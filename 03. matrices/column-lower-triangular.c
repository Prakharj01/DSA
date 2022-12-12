#include<stdio.h>
#include<stdlib.h>
struct matrix{
    int *a;
    int n;
};
void set(struct matrix *m,int i,int j,int x){
    if(i>=j)
m->a[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
}
int get(struct matrix *m,int i,int j){
    
if(i>=j)
return m->a[m->n*(j-1)+(j-2)*(j-1)/2+i-j];
else
return 0;
}
void display(struct matrix *m){

for(int i=1;i<=m->n;i++){
    for(int j=1;j<=m->n;j++){
        if(i>=j){
        printf("%d\t",m->a[m->n*(j-1)+ (i-j) + (j-2)*(j-1)/2]);
        }
    else{  
        printf("0\t");
    }

}
printf("\n");
}
}
int main()
{
    
    struct matrix one;
    int length;
    printf("Enter dimension of lower triangular matrix ");
    scanf("%d",&length);
    one.n=length;
    one.a=(int *)malloc(one.n*(one.n+1)/2*sizeof(int));
    int temp;
    printf("Enter all elements: \n");

    for(int i=1;i<=length;i++){
        for(int j=1;j<=length;j++){
            if(i>=j){
            printf("Enter element %d,%d: ",i,j);
            scanf("%d",&temp);
            set(&one,i,j,temp);
            }
            }
    }


    display(&one);
        return 0;
}