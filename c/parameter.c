#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int swap(int a,int b)
{
    int temp=0;

    temp=a;
    a=b;
    b=temp;
}

int swapAB(int* a,int* b)
{
    int* temp=NULL;
    temp=malloc(sizeof(int));

    *temp=*a;
    *a=*b;
    *b=*temp;

    free(temp);
    temp=NULL;
}

int main()
{
    int a=10;
    int b=12;
    int result=0;

    result=max(a,b);
    printf("max value:%d\n",result);

    result=swap(a,b);
    printf("a:%d,b:%d\n",a,b);

    result=swapAB(&a,&b);
    printf("a:%d,b:%d\n",a,b);
}
