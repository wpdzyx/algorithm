#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Given a 32-bit signed integer, reverse digits of an integer.
struct node
{
    int val;
    struct node *next;    
};

struct node* int2Link(int x);
int linkDepth(struct node *pNode);

int reverse(int x)
{
    struct node *plink=NULL;
    int i=0;
    int num=0;
    int flag=0;
    int depth=0;

    
    if(x<0)
    {
        x=-x;
        flag=1;
    }
    
    plink=int2Link(x);
    depth=linkDepth(plink);
    
    for (i = 1; i <= depth; i++)
    {
 
        printf("x=%d\n",plink->val);
        num+=((plink->val)*(pow(10,depth-i)));
        plink=plink->next;
    }

    printf("num=%d\n",num);
    if(flag==1)
    {
        num=-num;
    }
    return num;

}

struct node* int2Link(int x)
{
    int i=0;
    int n=0;

    struct node* pNode=NULL;
    struct node* pLink=NULL;

    pLink=(struct node*)malloc(sizeof(struct node));
    pNode=pLink;

    for(;(x/10)||(x%10);)
    {
        pNode->val=x%10;
        printf("[%d]",pNode->val);
        printf("pNode->val:%d\n",pNode->val);
        
        if(x/=10)
        {
            pNode->next=malloc(sizeof(struct node));
            pNode=pNode->next;
        }
        else
        {
            pNode->next=NULL;
        } 
    }

    return pLink;
}


int linkDepth(struct node* pNode)
{
    struct node* pn=NULL;
    pn=pNode;

    int i=1;
    while (pn->next != NULL)
    {
        i++;
        pn=pn->next;
    }
    
    printf("link depth is:%d\n",i);
    return i;
}

int main()
{
    int num=123;

    //int2Link(num);
    reverse(num);
}
