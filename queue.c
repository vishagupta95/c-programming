#include <stdio.h>

int array[5];
int start = 0;
int end = 0;

void queue_add(int x)
{
    if ((end + 1) % 5 == start)
    {
        printf("queue is full \n");
        return;
    }

    array[end] = x;
    end = (end + 1) % 5;
}

int queue_remove()
{
    if (start == end)
    {
        printf("queue is empty \n");
        return;
    }

    printf(" remove array end %d \n", array[start]);
    array[start] = -1;
    start = (start + 1) % 5;
}

int main()
{
    queue_add(1);
    queue_add(200);
    queue_add(3);
    queue_add(4);
    queue_remove();
    queue_add(5);
    queue_remove();
}
