#include<stdio.h>
#include<stdlib.h>

struct element{
    int i;
    int j;
    int x;
};
struct sparse{
    int m;
    int n;
    int num;
    struct element *e;
};

void create(struct sparse *s){
    int temp,count=0;
    printf("Enter dimensions of the matrix: ");
    scanf("%d\n%d", &s->m, &s->n);
    printf("Enter number of non zero elements: ");
    scanf("%d", &s->num);
    s->e=(void *)malloc(s->num*sizeof(struct element));

    for(int i=0;i<s->num;i++){
        printf("Enter x: ");
        scanf("%d",&(s->e[i].i));
        printf("Enter y: ");
        scanf("%d",&(s->e[i].j));
        printf("Enter num: ");
        scanf("%d", &(s->e[i].x));
    }
}

void display(struct sparse *s){
    printf("The dimension of matrix is %dx%d : \n",s->m,s->n);
    int count=0;
    int k=0;
    for(int i=1;i<=s->m;i++){
        for(int j=1;j<=s->n;j++){
            if (i==s->e[k].i && j==s->e[k].j){
                printf("%d\t",s->e[k].x);
                k++;
            }
            else{
                printf("0\t");
            }
            
        }
        printf("\n");
    }
    }

    void addition(struct sparse *s1, struct sparse *s2,struct sparse *sum ){
        if (s1->m!=s2->m || s1->n!=s2->n){
            printf("Dimenstions not equal. Cant add");


        }
        else{
        
        int max= s1->num + s2->num;
        sum->m=s1->m;
        sum->n=s1->n;
        sum->e=(void *)malloc(max*sizeof(struct element));
     
        int posone=0;
        int postwo=0;
        int count=0;
        
        while(posone<s1->num && postwo<s2->num){
            if(s1->e[posone].i <s2->e[postwo].i){
               sum->e[count++]=s1->e[posone];
                 
                posone++;
            }
            if(s1->e[posone].i> s2->e[postwo].i){
              sum->e[count++]=s2->e[postwo];
                postwo++;
            }
            if(s1->e[posone].i ==s2->e[postwo].i){
                if(s1->e[posone].j ==s2->e[postwo].j){
                sum->e[count].i=s1->e[postwo].i;
                sum->e[count].j=s1->e[postwo].j;
                sum->e[count].x=s1->e[postwo].x+s2->e[posone].x;
                count++;
                }
                else{
                     if(s1->e[posone].j <s2->e[postwo].j){
                sum->e[count++]=s1->e[posone];
                sum->e[count++]=s2->e[postwo];
            }
            if(s1->e[posone].j> s2->e[postwo].j){
                sum->e[count++]=s2->e[postwo];
                sum->e[count++]=s1->e[posone];
            }
                }
                postwo++;
                posone++;
            }
            
        }
        sum->num=count;
        
        
        }
       
    }
int main()
{
    struct sparse s1,s2,res;
    struct sparse *sum;
    create (&s1);
    display(&s1);

    create (&s2);
    display(&s2);

    addition(&s1,&s2,&res);
    display(&res);

    return 0;
}