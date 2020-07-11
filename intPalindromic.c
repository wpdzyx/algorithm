#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false -1
#define EQ(a,b) (a==b)

typedef struct _node
{
    int val;
    struct _node* next;
    struct _node* prev;
}node;

bool isPalindrome(int x);
node* int2link(int x);
int linkDepth(node* nd);

bool isPalindrome(int x){
    node* pStart=NULL;
    node* pEnd=NULL;

    int i=0;
    int len=0;

    if(x<0)
    {
        printf("negative number\n");
        return false;
    }

    pStart=int2link(x);
    pEnd=pStart;

    len=linkDepth(pStart);

    //while(pEnd!=NULL)
    for(i=0;i<len-1;i++)
    {
        pEnd=pEnd->next;
    }

    for(i=0;i<len/2;i++)
    {
        printf("start val:%d, end val:%d\n",pStart->val,pEnd->val);
        if(EQ(pStart->val,pEnd->val))
        {
            pStart=pStart->next;
            pEnd=pEnd->prev;
        }
        else
        {
            printf("No panlindromic number\n");
            return -1;
        }
        
    }

    printf("loop finished, panlindrom number\n");
    return 1;
}

int linkDepth(node* nd)
{
    int count=0;

    if(EQ(nd,NULL))
    {
        return -1;
    }

    //pn=nd;

    while (nd->next!=NULL)
    {
        nd=nd->next;
        count++;
    }

    printf("depth is:%d,pn addr:0x%x\n",count,nd); 
    return count;
}

node* int2link(int x)
{
    node* pn=NULL;
    node* pr=NULL;
    node* tmp=NULL;

    pn=(node*)malloc(sizeof(node));
    pn->prev=NULL;
    pn->val=0xffff;

    pr=pn;

    while((x%10!=0)||(x/10!=0))
    {
        pn->val=x%10;
        printf("node val:%d\n",pn->val);
        pn->next=(node*)malloc(sizeof(node));
        tmp=pn;
        pn=pn->next;
        pn->prev=tmp;
        x/=10;
    }

    pn->next=NULL;
    return pr;
}

int main()
{
    int x=123321;
    int y=12345;
    int z=100;
    int a=-121;
    int b=0;

    isPalindrome(a);
    //isPalindrome(b);
    //isPalindrome(x);
    //isPalindrome(y);
}