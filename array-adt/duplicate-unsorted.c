#include<stdio.h>
#include<stdlib.h>
struct array {
    int arr[15];
    int length;
    int size;
};

void duplicate(struct array a){
int n=a.length;
int count=1;
printf("Elements       Count\n");
for(int i=0;i<n;i++){
        if(a.arr[i]!=-1){
    for(int j=i+1;j<n;j++){
        if (a.arr[i]==a.arr[j] && a.arr[i]!=-1){
        a.arr[j]=-1;
            count++;
        }
    }
    printf("%d\t\t%d\n",a.arr[i],count);
}
count=1;
}
}

void hashtable(struct array a){
    int n=a.length;
    int max=-1;
    printf("\nUsing hash table\n");
    for(int i=0;i<n;i++){
        if(max<a.arr[i]){
            max=a.arr[i];
        }
    }
int *p=(int *)calloc(max+1,sizeof(int));
for(int i=0;i<n;i++){
    p[a.arr[i]]++;
}
for(int i=0;i<=max;i++){
    if(p[i]>1){
        printf("%d\t\t%d\n",i,p[i]);
    }
}
    

}
int main()
{
    struct array a={{8,3,6,4,6,5,6,8,2,7},10,15};

    duplicate(a);
    hashtable(a);
    return 0;
}