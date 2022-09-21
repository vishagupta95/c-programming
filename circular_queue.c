int array[5];
int end= 0;
int start= 0;

#include <stdio.h>

void enque(int x)
{
  if ((end+1)%5  == start) {
      //printf("queue is full \n");	  
      return;
  }
 array[end]=x;
 printf("enque :added at pos %d val %d RARE %d \n",end,x,start); 
 end =(end+1)%5; 
}	

void deque()
{
  if ((start)%5 == end) {
      printf("quuee is empty \n");	  
      return;
  }
 array[start]=-1;  
 printf("deque :at pos %d val %d START %d\n",start,-1,start); 
 start =(start+1)%5; 
}

void print_queue()
{
  int m=0;	
 printf("head :%d tail %d \n",start,end);	 
 for (m= 0;m < 5;m++) 
 printf("pos :%d val %d \n",m, array[m]);	 

}	

int main()
{
 int m;
 for (m= 0;m < 5;m++) 
 array[m] = -1;
 print_queue();
 for (m= 0;m < 15;m++) 
 enque(20);
 print_queue();
 deque();
 print_queue();
 enque(25);
 print_queue();
 enque(25);
 print_queue();
 deque();
 deque();
 deque();
 deque();
 deque();
 print_queue();
 enque(25);
 print_queue();
 for (m= 0;m < 15;m++) 
 enque(20);
 print_queue();
}	


