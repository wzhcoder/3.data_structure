#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "math.h"  
#include "time.h"


// int num[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };

int num[] = {3, 5, 1, 6, 2, 4};
void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1  = *p2;
    *p2  = temp;
}


void bubble_sort(int num[], int length)
{
    int i = 0, j = 0;
    int temp;
    for(i = 0; i < (length - 1); i++)
        for(j = 0; j < (length - 1 -i); j++){
            if(num[j] > num[j+1]){
                // temp = num[j];
                // num[j] = num[j+1];
                // num[j+1] = temp;
                swap(&num[j], &num[j+1]);
            }
        }

}


void select_sort(int num[], int len)
{
    int i, j, min;
    for(i = 0; i < len - 1 ; i++){
        min = i;
        for(j = i + 1; j < len; j++){
            if(num[j] < num[min]){
                swap(&num[j], &num[min]);
            }
        }
    }
}


void insertion_sort(int arr[], int len){
    int i,j,temp;
    for (i=1;i<len;i++){
            temp = arr[i];
            for (j=i;j>0 && arr[j-1]>temp;j--)
                    arr[j] = arr[j-1];
            arr[j] = temp;
    }
}

int main()
{
    int i = 0;
    int length = sizeof(num)/sizeof(int);
    // printf("%d\r\n", length);
    // bubble_sort(num, length);
    // select_sort(num, length);
    insertion_sort(num, length);
    for(i = 0; i < length; i++){
        printf("%d\t", num[i]);

    }

}