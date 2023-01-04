#include<stdio.h>
#include<stdlib.h>
struct arr {
int array[11];
int size;
int length;
};
int singlee(struct arr a){
int i=0;
int k=a.array[0]-i;
while(a.array[i]-i==k){
i++;
}
return i+k;
}

int multiplee(struct arr a){
int i=0,count=0;
int k=a.array[0]-i;
    printf("Missing element is : ");
for(;i<a.length;i++){
if(a.array[i]-i!=k){
    while(k<a.array[i]-i){
    printf("%d \t",i+k);
    k++;
count++;
}
}
}
return count;
}

void fasterm(struct arr a,int max){
int *hash;
hash=(int *)calloc(max,sizeof(int));
for(int i=0;i<a.length;i++){
hash[a.array[i]]++;
}
printf("\n Hashing-> Missing elements: ");
for(int i=0;i<max;i++){
    if (hash[i]==0){
        printf("%d  ",i);
    }
}
free(hash);
}
int main()
{
    
    struct arr a={{6,7,8,9,10,11,12,14,15,16,17},11,11};
    struct arr a2={{6,7,8,9,11,12,15,16,17},11,9};
    
    struct arr a3={{3,7,4,9,12,6,1,11,2,10},11,10};
    int max=12;
   int num=singlee(a);
    printf("Single Missing number is: %d\n",num);
    int count=multiplee(a2);
    printf("\nNo of Missing number is: %d ",count);

    fasterm(a3,max);
    return 0;
}

/*for multiple elements, the time complexity is order (n) but for hashing though we require a lot of space the time complexity if o(n) since we are scanning it only once;

using the hash, the time complexity of the hash is order(n) again since only once we are scanning through the entire array
*/