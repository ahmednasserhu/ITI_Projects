#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);
void swap_without_temp(int* x, int* y);
void swap_without_temp2(int* x, int* y);

int main()
{
    int x=5,y=7;
    swap_without_temp2(&x,&y);
    printf("after swapping: x = %d, y = %d",x,y);
}


void swap1(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_without_temp(int* x, int* y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void swap_without_temp2(int* x, int* y){
    *x = *x * *y;
    *y = *x / *y;
    *x = *x / *y;
}
