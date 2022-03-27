void enque(int x)
{
  if ((end+1)%5  == start) {
      //printf("queue is full \n");   
      return;
  }
 array[end]=x;
 end =(end+1)%5; 
}   
    
void deque() 
{
  if ((start)%5 == end) {
      printf("quuee is empty \n");    
      return;
  } 
 array[start]=-1;  
 start =(start+1)%5;
