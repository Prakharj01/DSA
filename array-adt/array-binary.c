#include<stdio.h>
struct Array{
int array[20];
int size;
int length;
};
void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d\t",arr.array[i]);
    }
}
void merge(struct Array arr1,struct Array arr2,struct Array *arr3){
    
    int i=0,j=0,k=0;
    int m=arr1.length;
    int n=arr2.length;
    arr3->length=m+n;
    while(i<arr1.length && j<arr2.length){
        if(arr1.array[i]>= arr2.array[j] && j<n){
        arr3->array[k]=arr2.array[j];
        j++;
        k++;
        }
        else if(arr1.array[i]< arr2.array[j]){
        arr3->array[k]=arr2.array[i];
        i++;
        k++;
        }
        if(i==m){

        }
   }



}
int main()
{
    typedef struct Array arrae;
    arrae arr1={{2,6,10,15,25},10,5};
    arrae arr2={{3,4,7,18,20},10,5};
    arrae arr4;
    arrae *arr3;
    arr3=&arr4;
    merge(arr1,arr2, arr3);
    display(arr4);
    return 0;
}