#include<stdio.h>
#include<stdlib.h>
struct array{
    int arr[15];
    int length;
    int size;
    
};

void sume(struct array a,int num){

    int n=a.length;
    int max;
    int temp;
    int *p=(int *)calloc(max+1,sizeof(int));
    for(int i=0;i<n;i++){
        temp=num-a.arr[i];
        if(p[temp]>0 && temp>0){
            printf("%d + %d = %d \n",a.arr[i],temp,num);
        }
        p[a.arr[i]]++;
    }
}

void sorted(struct array a,int num){
int i=0,j=a.length-1;
printf("\n Sorted Array \n");
while(j>i){
    if(a.arr[i] + a.arr[j]==num){
        printf("%d + %d = %d \n",a.arr[i],a.arr[j],num);
    i++;
    }
    if(a.arr[i] + a.arr[j] >num){
        j--;
    }
    if(a.arr[i] + a.arr[j] <num){
        i++;
    }
}
}
int main()
{
    struct array a={{6,3,8,10,16,7,5,2,4,9},10,15};
    sume(a,10);

    struct array b={{1,3,4,5,6,8,9,12,15,19},10,15};
    sorted(a,10);
    return 0;
}