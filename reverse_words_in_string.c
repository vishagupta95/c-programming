#include <stdio.h>

void reverseString(char* start, char* end){
   while (start < end){
      char temp = *start;
      *start = *end;
      *end = temp;
      ++start;
      --end;
   }   
}

char* word_start_index(char* p)
{
    while((*p != '\0') && (*p == ' ')){
        ++p;    
    }

    if(*p == '\0')
        return NULL;
    else
        return p;
}

char* word_end_index(char* p)
{
    while((*p != '\0') && (*p != ' ')){
        ++p;
    }

    return p-1;
} 

int main(){
    char arr[] = "vishal is a good programmer";
    char* test = arr;

    while (test != '\0'){
        char* curWordStart = word_start_index(test);
        if (curWordStart == NULL)
            break;
        char* curWordEnd = word_end_index(curWordStart);
        reverseString(curWordStart, curWordEnd); 
        test = curWordEnd + 1;
    }
    printf("%s \n", arr);
    return(0);
}
