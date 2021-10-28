#include<stdio.h>
#include<stdlib.h>
void swap(int *ptr1,int *ptr);
struct Array{
    int a[10];
    int size;
    int length;
};
void display(struct Array arr){
    int i;
    printf("\nArray Elements are: ");
    for(int i=0;i<arr.length;i++){
        printf("%d  ", arr.a[i]);
    }
}
int LinearSearch(struct Array *arr, int num){
    for(int i=0;i<arr->length;i++ ){
        if(num==arr->a[i]){
            swap(&arr->a[i], &arr->a[i-1]);
            return i;
        }
    }
        return -1;
}
void swap(int *ptr1,int *ptr){
    int temp;
    temp=*ptr1;
    *ptr1=*ptr;
    *ptr=temp;
}

int main()
{
   int x=7;
   struct Array arr={{2,3,4,5,6},10,5};
      display(arr);
    printf("\nThe number is at index: %d",LinearSearch(&arr,5));
      display(arr);
    return 0;
}