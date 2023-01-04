#include<stdio.h>
    int A[10]={-3,-5,82,-25,21,3,9,-4,-7,47};

    void swap(int i,int j){
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
int main()
{
    int temp;
    int length=10;
    int i=0;
    int j=length-1;

        for(i=0;i<length;i++){
            printf("%d\t",A[i]);
        }
        i=0;
        while(j>i){
           while(A[i]<0){
               //printf("\n%d\t",A[i]);
               i++;
           }
        
            while(A[j]>=0){
                j--;
            }
            if(i<j){
                   swap(i,j);
                    
                }
            }
        
    printf("\n");
        for(i=0;i<length;i++){
            printf("%d\t",A[i]);
        }
    return 0;
}