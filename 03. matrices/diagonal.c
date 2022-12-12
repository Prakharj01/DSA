#include<stdio.h>
struct matrix{
    int a[10];
    int n;
};

void set(struct matrix *m,int i,int j,int x){
    if(i==j){
        m->a[i-1]=x;
    }

}
int get(struct matrix *m,int i,int j){
    if(i==j){
        return m->a[i-1];
    }
    else{
        return 0;
    }

}
void display(struct matrix *m){

for(int i=0;i<m->n;i++){
    for(int j=0;j<m->n;j++){
        if(i==j){
        printf("%d\t",m->a[i]);
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
    printf("Enter length of diagonal matrix: ");
    scanf("%d",&length);
    one.n=length;
    int temp=2;
    printf("Length: %d \n",length);
    for(int i=1;i<=length;i++){
        printf("Enter element %d: ",i);
        scanf("%d",&temp);
        set(&one,i,i,temp);
    }
    display(&one);
    return 0;
}