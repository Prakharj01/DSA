#include<stdio.h>
#include<stdlib.h>


void Insert(int a[],int n){
int num=a[n];
int i=n;
int temp=a[n];
while(temp>a[i/2] && i>1){
a[i]=a[i/2];
i=i/2;
}
a[i]=temp;
}
void display(int a[],int n){
    int i=0;
    for(i=0;i<=n;i++){
        printf("%d\t",a[i]);
       
    }
    printf("\n");
}

int delete(int a[],int n){

    int x=a[n];
    int val=a[1];
    a[1]=a[n];
int temp;
    int i=1;
    int j=2*i;
    while(j<n-1){
        if (a[j+1]>a[j]){
        j=j+1;
        }
        if (a[i]<a[j]){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i=j;
        j=2*i;
        }
        else{
            break;
        }
    }
a[n]=val;
return val;

}
int main()
{
    int a[]= {0,10,20,30,25,5,40,35};
    //40,25,35,10,5,20,30
    int n=7;

    for(int i=1;i<8;i++){
    Insert(a,i);
    display(a,i);
    }

for (int i=7;i>0;i--){
    printf("Deleted value is %d\n ",delete(a,i));
}
    display(a,7);
    return 0;
}