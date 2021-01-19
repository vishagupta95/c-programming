#include <stdio.h>
#include <string.h>

 int main(){ 
     int rc =0;    
     char command[100] = {0};
      memset(command,'\0',100);
       rc = snprintf(command, 100, "rm -rf /bootflash/curr-ks.img ");
      if (rc < 0 || rc > 100) {
          printf("test_nh larger than the command buffer size, please increase it\n");
      } else {
       printf("vishal command %s",command);  
       rc = system(command);
     }
 }    

