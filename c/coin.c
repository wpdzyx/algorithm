/**
 * You have a total of n coins that you want to form in a staircase shape, 
 * where every k-th row must have exactly k coins.
 * Given n, find the total number of full staircase rows that can be formed.
 * cn is a non-negative integer and fits within the range of a 32-bit signed integer.
*/

#include <stdio.h>

int sum(int n){

    /*
    1+2+3+.....+k<n
    1+2+3+.....+k+(k+1)>n
    return k
    */
   if(n==1)
   {
       return 1;
   }

   return n+sum(n-1);
}

int arrangeCoins(int n)
{
    int i=0;
    int ret=0;
    for (i = 1; i <= n; i++)
    {
        if((sum(i)<=n)&&(sum(i+1)>n))
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    int ret=0;
    ret=arrangeCoins(1804289383);

    printf("val is:%d\n",ret);
}
