/*

file descriptor is a integer used to index into a table of files that a process has open.
socket is a special file used for inter-process communication

IO Multiplexing
simple solution is to create a thread (or process) for each client , block on read 
until a request is sent and write a response. This is working ok with a
small number of clients but if we want to scale it to hundreds of clients, creating a 
thread for each client is a bad idea

The solution is to use a kernel mechanism for polling over a set of file descriptors. 

There are 3 options you can use in Linux: select, poll,epoll

Select (), poll (), epoll () three sets of I / O multiplexing system calls can listen
to multiple file descriptors at the same time. They will wait for the timeout 
specified by the  timeout parameter until an event occurs on one or more 
file descriptors. 

All the above methods serve the same idea, create a set of file descriptors , tell the
kernel what would you like to do with each file descriptor (read, write, ..) and use 
one thread to block on one function call until at least one file descriptor requested 
operation available


1)select () system call
select does not bind the file descriptor and event.   The select system call 
monitors three sets of file descriptors

1.  readfds,
2.  writefds and 
3.  exceptfds. 

2)poll () system call

Poll is somewhat smarter. It bind both file descriptors and events Using  pollfd 
structure

3, epoll () system call
epoll is a Linux kernel system call for a scalable I/O to achieve better performance in more 
demanding applications, where the number of watched file descriptors is large (unlike the
 older system  calls, which operate in O(n) time, epoll operates in O(1) 
1.  epoll instance are in kernel

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
 
#define MAXBUF 256
 
void child_process(void)
{
  sleep(2);
  char msg[MAXBUF];
  struct sockaddr_in addr = {0};
  int n, sockfd,num=1;
  srandom(getpid());
  /* Create socket and connect to server */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(2000);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
 
  printf("child {%d} connected \n", getpid());
  while(1){
        int sl = (random() % 10 ) +  1;
        num++;
        sleep(sl);
    sprintf (msg, "Test message %d from client %d", num, getpid());
    n = write(sockfd, msg, strlen(msg));    /* Send message */
  }
 
}
 
int main()
{
  char buffer[MAXBUF];
  int fds[5];
  struct sockaddr_in addr;
  struct sockaddr_in client;
  int addrlen, n,i,max=0;;
  int sockfd, commfd;
  fd_set rset;
  for(i=0;i<5;i++)
  {
    if(fork() == 0)
    {
        child_process();
        exit(0);
    }
  }
 
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&addr, 0, sizeof (addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(2000);
  addr.sin_addr.s_addr = INADDR_ANY;
  bind(sockfd,(struct sockaddr*)&addr ,sizeof(addr));
  listen (sockfd, 5); 
 
  for (i=0;i<5;i++) 
  {
    memset(&client, 0, sizeof (client));
    addrlen = sizeof(client);
    fds[i] = accept(sockfd,(struct sockaddr*)&client, &addrlen);
    if(fds[i] > max)
        max = fds[i];
  }
  
  while(1){
    FD_ZERO(&rset);
    for (i = 0; i< 5; i++ ) {
        FD_SET(fds[i],&rset);
    }
 
    puts("round again");
    select(max+1, &rset, NULL, NULL, NULL);
 
    for(i=0;i<5;i++) {
        if (FD_ISSET(fds[i], &rset)){
            memset(buffer,0,MAXBUF);
            read(fds[i], buffer, MAXBUF);
            puts(buffer);
        }
    }   
  }
  return 0;
}

/*

We start with creating 5 child processes , each process connect to the server and send messages to the server. 
The server process uses accept(2) to create a different file descriptor for each client. The first parameter ini
 select(2) should be the highest-numbered file descriptor in any of the three sets, plus 1 so we check the max fd num

The main infinite loop creates a set of all file descriptors, call select and on return check which file descriptor 
is ready for read. For simplicity I didn add error checking

On return , select changes the set to contains only the file descriptors that is ready so we need to build the 
set again every iteration.

The reason we need to tell select what is the highest-numbered file descriptor is the inner implementation of fd_set. i
Each fd is declared by a bit so fd_set is an array of 32 integers (32 *32bit = 1024 bits). The function check any bit toi
 see if its set until it reach the maximum. This means that if we have 5 file descriptors but the highest number is 900 , i
the function will check any bit from 0 to 900 to find the 
file descriptors to watch. There is a posix alternative to select – pselect which add a signal mask while waiting 
*/


/// POLL
/*
Unlike select(), with its inefficient three bitmask-based sets of file descriptors, poll( ) employs a single array of nfds pollfd structures. the prototype is simpler:

int poll (struct pollfd *fds, unsigned int nfds, int timeout);
1
int poll (struct pollfd *fds, unsigned int nfds, int timeout);
The structure pollfd has a different fields for the events and the returning events so we don’t need to build it each time:

struct pollfd {
      int fd;
      short events; 
      short revents;
};
For each file descriptor build an object of type pollfd and fill the required events. after poll returns check the revents field


*/

poll()
{

// To change the above example to use poll:
for (i=0;i<5;i++) 
  {
    memset(&client, 0, sizeof (client));
    addrlen = sizeof(client);
    pollfds[i].fd = accept(sockfd,(struct sockaddr*)&client, &addrlen);
    pollfds[i].events = POLLIN;
  }
  sleep(1);
  while(1){
    puts("round again");
    poll(pollfds, 5, 50000);
 
    for(i=0;i<5;i++) {
        if (pollfds[i].revents & POLLIN){
            pollfds[i].revents = 0;
            memset(buffer,0,MAXBUF);
            read(pollfds[i].fd, buffer, MAXBUF);
            puts(buffer);
        }
    }
  }

/*

Poll vs Select
poll( ) does not require that the user calculate the value of the highest- numbered file descriptor +1
poll( ) is more efficient for large-valued file descriptors. Imagine watching a single file descriptor with the value 900 via select()—the kernel would have to check each bit of each passed-in set, up to the 900th bit.
select( )’s file descriptor sets are statically sized.
With select( ), the file descriptor sets are reconstructed on return, so each subsequent call must reinitialize them. The poll( ) system call separates the input (events field) from the output (revents field), allowing the array to be reused without change.
The timeout parameter to select( ) is undefined on return. Portable code needs to reinitialize it. This is not an issue with pselect( )
select( ) is more portable, as some Unix systems do not support poll( )

*/


poll* System Calls
While working with select and poll we manage everything on user space and we send the sets on each call to wait. To add another socket we need to add it to the set and call select/poll again.

Epoll* system calls help us to create and manage the context in the kernel. We divide the task to 3 steps:

create a context in the kernel using epoll_create
add and remove file descriptors to/from the context using epoll_ctl
wait for events in the context using epoll_wait
Lets change the above example to use epoll:

  struct epoll_event events[5];
  int epfd = epoll_create(10);
  ...
  ...
  for (i=0;i<5;i++) 
  {
    static struct epoll_event ev;
    memset(&client, 0, sizeof (client));
    addrlen = sizeof(client);
    ev.data.fd = accept(sockfd,(struct sockaddr*)&client, &addrlen);
    ev.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, ev.data.fd, &ev); 
  }
  
  while(1){
    puts("round again");
    nfds = epoll_wait(epfd, events, 5, 10000);
    
    for(i=0;i<nfds;i++) {
            memset(buffer,0,MAXBUF);
            read(events[i].data.fd, buffer, MAXBUF);
            puts(buffer);
    }
  }


Epoll vs Select/Poll
We can add and remove file descriptor while waiting
epoll_wait returns only the objects with ready file descriptors
epoll has better performance – O(1) instead of O(n)
epoll can behave as level triggered or edge triggered (see man page)
epoll is Linux specific so non portable
  struct epoll_event events[5];
  int epfd = epoll_create(10);
  ...
  ...
  for (i=0;i<5;i++) 
  {
    static struct epoll_event ev;
    memset(&client, 0, sizeof (client));
    addrlen = sizeof(client);
    ev.data.fd = accept(sockfd,(struct sockaddr*)&client, &addrlen);
    ev.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, ev.data.fd, &ev); 
  }
  
  while(1){
    puts("round again");
    nfds = epoll_wait(epfd, events, 5, 10000);
    
    for(i=0;i<nfds;i++) {
            memset(buffer,0,MAXBUF);
            read(events[i].data.fd, buffer, MAXBUF);
            puts(buffer);
    }
  }



