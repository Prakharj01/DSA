#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int array[10];
    int length;
    int size;
};

struct Array *unione(struct Array *arrp[]){
int i,j=0;
int res=0;
struct Array *arr4=(struct Array *)malloc(sizeof(struct Array));
for(i=0;i<arrp[0]->length;i++){
    arr4->array[i]=arrp[0]->array[i];
}
arr4->length=arrp[0]->length;
j=arrp[0]->length;
i=0;

for( i=0;i<arrp[1]->length;i++){
    for(int k=0;k<j;k++){
        if(arrp[1]->array[i]==arr4->array[k]){
            res=1;
            break;
        }
    }
    if(res==0){
        arr4->array[j]=arrp[1]->array[i];
        j++;
    }
    res=0;
}
arr4->length=j;
return arr4;
}
struct Array *distincte(struct Array *arrp[])
{
    printf("Array of distinct elements\n");
    int k = 0, temp = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (int v = 0; v < 2; v++)
    {
        for (int i = 0; i < arrp[v]->length; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (arrp[v]->array[i] == arr3->array[j])
                {
                    temp = 1;
                }
            }
            if (temp == 0)
            {
                arr3->array[k] = arrp[v]->array[i];
                k++;
                arr3->length = k;
            }
            temp = 0;
        }
    }
    return arr3;
}
void display(struct Array a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d\t", a.array[i]);
    }
}

struct Array *intere(struct Array *arrp[]){
struct Array *arr5=(struct array *)malloc(sizeof(struct Array));

int j=0;
for(int i=0;i<arrp[0]->length;i++){
    for(int j=0;j<arrp[1]->length;i++){
        if (arrp[0]->array[i]==arrp[1]->array[j]){
            arr5->array[j]=arrp[0]->array[i];
            j++;
            break;
        }
    }
}
return arr5;
}
int main()
{
    struct Array arr1 = {{3, 5, 10, 4, 5}, 5, 10};
    struct Array arr2 = {{12, 4, 7, 2, 5}, 5, 10};
    struct Array *arr3, *arr4, *arr5;
    struct Array *arrp[2] = {&arr1, &arr2};
    arr3 = distincte(arrp);
    display(*arr3);
    
    printf("\nUNION IN SETS\n");
    arr4=unione(arrp);
    display(*arr4);

printf("\n Intersection in set");
      arr5=intersect(arrp);
      display(*arr5);
      return 0;

    printf("");
}

/*
If both the array are in ascending order. we can modify the merging of array with checking for duplicates.
*/