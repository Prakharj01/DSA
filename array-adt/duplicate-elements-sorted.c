// missing elements in a sorted array
#include <stdio.h>
#include <stdlib.h>
struct array
{
    int arr[15];
    int size;
    int length;
};
void missinge(struct array arr1)
{
    int temp = 0;
    printf("Missing elements: ");
    for (int i = 0; i < arr1.length; i++)
    {
        if ((arr1.arr)[i] == (arr1.arr)[i + 1])
        {
            if (i != 0)
            {
                temp = arr1.arr[i - 1];

                if (temp == arr1.arr[i])
                {
                    continue;
                }
            }
            printf("%d\t", arr1.arr[i]);
        }
    }
}
void countinge(struct array arr1)
{
    int ele = 0;
    int count = 1;
    printf("\ncounting elements\n");
    for (int i = 0; i < arr1.length; i++)
    {
        if (arr1.arr[i] == arr1.arr[i - 1])
        {
            ele = arr1.arr[i];
            count += 1;
        }
        else
        {
            count = 1;
        }

        if (arr1.arr[i] == arr1.arr[i - 1] && arr1.arr[i] != arr1.arr[i + 1])
        {
            printf("%d\t %d\n", arr1.arr[i], count);
        }
    }
}
void hashing(struct array arr1)
{
    int max = arr1.arr[(arr1.length) - 1];
    int *p = (int *)calloc(max, sizeof(int));
    printf("using hashing\n");
    for (int i = 0; i < arr1.length; i++)
    {
        p[arr1.arr[i]]++;
    }

    for (int i = 0; i < max; i++)
    {
        if (p[i] > 1)
            printf("%d\t%d\n", i, p[i]);
    }
}
int main()
{
    struct array arr1 = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 15, 10};
    missinge(arr1);
    countinge(arr1);
    hashing(arr1);
    return 0;
}
