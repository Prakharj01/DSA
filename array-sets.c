#include<stdio.h>
#include<stdlib.h>
struct Array{
int arr[20];
int size;
int length;
};

struct Array *Merge(struct Array arr1, struct Array arr2){
    struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    for(int i=0;i<arr1.length;i++){
        
    }
    for(i=0;i<arr2.length;i++){
        for(j=0;j<arr3->length;j++){
        }
    }
    return arr3;
}
int main()
{
    struct Array arr1={{3,24,9,7,15,32,14},10,7};    struct Array arr2={{58,35,17,4,9,3,1},10,7};


    
    return 0;
}