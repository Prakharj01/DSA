#include<stdio.h>
#include<stdlib.h>
struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr){
    int i;
    printf("\nArray Elements are: ");
    for(int i=0;i<arr.length;i++){
        printf("%d  ", arr.A[i]);
    }
}
void append(int x,struct Array *arr){
    
    (arr)->A[arr->length]=x;
    (*arr).length++;
}

void insert(int index,int x,struct Array *arr){
    if(index>=0 && index<=arr->length){
        for(int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
    else{
        printf("Invalid index");
    }
}
void delete(int index,struct Array *arr){
     if(index>=0 && index<=arr->length){
     for(int i=index;i<arr->length-1;i++){
         arr->A[i]=arr->A[i+1];
     }
     arr->length--;
     }
}
int main()
{
   int x=7;
   struct Array arr={{2,3,4,5,6},10,5};
    
   display(arr);
   append(x,&arr);
   display(arr);
   insert(4,15, &arr);
   display(arr);
   delete(5, &arr);
   display(arr);
    return 0;
}