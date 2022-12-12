#include<stdio.h>
#include<stdlib.h>
struct matrix{
    int *a;
    int n;
};

void set(struct matrix *m,int i,int j,int temp){
    m->a[(m->n)*(i-1)-(i-1)*(i-2)/2 + (j-1)]=temp;

}
void display(struct matrix *m){

for(int i=1;i<m->n;i++){
    for(int j=1;j<m->n;j++){
        if (j>=i){
            printf("%d\t",m->a[(m->n)*(i-1)-(i-1)*(i-2)/2 + (j-1)]);
        }
        else{
            printf("0\t");
        }
    }
    printf("\n");
}
}

void get(struct matrix *m,int i,int j){

}

int main()
{
    struct matrix m;
    int length,temp ;
    printf("Enter size of matrix: ");
    scanf("%d",&length);
    m.n=length;
    m.a=(int *)malloc(length*(length+1)/2*sizeof(int));
    for(int i=1;i<=length;i++){
        for(int j=1;j<=length;j++){
            if (j>=i){
                printf("Enter element[%d][%d]: ",i,j);
                scanf("%d",&temp);
                set(&m,i,j,temp);
            }
        }
    }
    display(&m);
    return 0;
}