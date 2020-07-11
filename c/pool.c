#include<stdio.h>
#include<stdlib.h>

int maxArea(int* height, int heightSize)
{
    int i=0,j=0;
    int tmp=0;
    int area=0;

    for(i=0;i<heightSize;i++)
    {
        for(j=i+1;j<heightSize;j++)
        {
            tmp=(j-i)*(height[j]<height[i]?height[j]:height[i]);
            if(tmp>area)
            {
                area=tmp;
            }
        }
    }

    return area;
}

int main()
{
    int array[]={1,8,6,2,5,4,8,3,7};
    int output=0;

    printf("area is:%d\n",maxArea(array,sizeof(array)/sizeof(int)));
}