#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//Given a 32-bit signed integer, reverse digits of an integer.
//#pragma pack(8)
struct node
{
    int val;
    struct node *next;
};
//#pragma pack()

struct node *int2Link(int x);
int linkDepth(struct node *pNode);

int reverse(int x)
{
    struct node *plink = NULL;
    int i = 0;
    int num = 0;
    int flag = 0;
    int depth = 0;

    //overflow check
    struct node* pmax=NULL;
    int pmax_depth=0;

    if (x < 0)
    {
        x = -x;
        flag = 1;
    }

    plink = int2Link(x);
    depth = linkDepth(plink);

    pmax=int2Link(INT_MAX);
    pmax_depth=linkDepth(pmax);
    
    for (i = 1; i <= depth; i++)
    {
        if(depth==10)
        {
            plink->val>pmax->val;
            printf("over flow\n");
            return 0;
        };

        printf("x=%d\n", plink->val);
        num += ((plink->val) * ((int)pow(10, depth - i)));
        plink = plink->next;
    }

    printf("num=%d\n", num);
    if (flag == 1)
    {
        num = -num;
    }

    if((num<0)&&(flag==0))
    {
        printf("over flow,return 0\n");
        return 0;
    }

    return num;
}

struct node *int2Link(int x)
{
    int i = 0;
    int n = 0;

    struct node *pNode = NULL;
    struct node *pLink = NULL;

    pLink = (struct node *)malloc(sizeof(struct node));
    //must init the member when malloc a structure memory
    pLink->val = 0;
    pLink->next = NULL;

    pNode = pLink;

    for (; (x / 10) || (x % 10);)
    {
        pNode->val = x % 10;
        printf("[%d]", pNode->val);
        printf("pNode->val:%d\n", pNode->val);

        if (x /= 10)
        {
            pNode->next = (struct node *)malloc(sizeof(struct node));
            pNode = pNode->next;
        }
        else
        {
            pNode->next = NULL;
        }
    }

    return pLink;
}

int linkDepth(struct node *pNode)
{
    //struct node* pn=NULL;
    //pn=pNode;

    int i = 1;
    while ((pNode->next) != NULL)
    {
        i++;
        pNode = pNode->next;
    }

    printf("link depth is:%d\n", i);
    return i;
}

int main()
{
    //int num = 1534236462;
    int num = -2147483412;

    printf("max int 32:%d\n", (int)pow(2, 31) - 1);
    printf("max int 32:%d\n", -(int)pow(2, 31));

    //int2Link(num);
    reverse(num);
}
