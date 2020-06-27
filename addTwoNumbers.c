#include <stdio.h>
#include <stdlib.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int linkDepth(struct ListNode* ln)
{
    if(ln==NULL)
    {
        return 0;
    }

    int depth=0;
    struct ListNode* pln;
    pln=ln;

    while (pln->next!=NULL)
    {
        depth++;
        pln=pln->next;
    }
    
    printf("list depth is:%d\n",depth+1);

    return depth+1;
}

struct ListNode* initList(struct ListNode* pl,int depth)
{
    struct ListNode* plt;
    int i=0;

    plt=pl;

    for(i=0;i<depth;i++)
    {
        plt->val=0;
        if(i==(depth-1))
        {
            plt->next=NULL;
        }
        else
        {
            plt->next=plt+1;
            plt++;
        }

        //printf("init list :%d\n",plt->val);
    }

    return pl;
}

struct ListNode* array2List(int array[],int arrayLen)
{
    int i=0;
    struct ListNode *ln,*tmp;
    ln = (struct ListNode*)malloc(sizeof(struct ListNode)*arrayLen);
    tmp=ln;

    //printf("array length is :%d\n",arrayLen);

    for(i=0;i<arrayLen;i++)
    {
        tmp->val=*(array+i);
        //printf("arrry2list node:%d\n",tmp->val);

        if(i<arrayLen-1)
        {
            tmp->next=tmp+1;
            tmp++;
        }
        else
        {
            tmp->next=NULL;
        } 
    }

    return ln;
}

int* list2Array(struct ListNode* list)
{
    int depth=0;
    int i=0;
    struct ListNode* ltp;
    int* array;

    ltp=list;
    depth=linkDepth(ltp);
    array=malloc(sizeof(int)*depth);

    for(i=0;i<depth;i++)
    {
        array[i]=ltp->val;
        //why ltp++ is wrong ? what is the different between lpt=ltp->next and ltp++;
        //ltp++;
        ltp=ltp->next;

        printf("array element is:%d\n",array[i]);
    }

    return array;

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1, *p2,*p3;
    
    int val_1=0;
    int val_2=0;
    int depth=0;
    int carry=0;
    int sum=0;
    int i=0;

    struct ListNode* tmp;
    struct ListNode* carryNode;

    p1=l1;
    p2=l2;
    depth=(linkDepth(l1)>linkDepth(l2)?linkDepth(l1):linkDepth(l2));

    p3=(struct ListNode*)malloc(sizeof(struct ListNode)*depth);
    p3=initList(p3,depth);
    tmp=p3;


    //while(p1 !=NULL || p2 !=NULL)
    for(i=0;i<depth;i++)
    {
        val_1= (p1!=NULL?p1->val:0);
        val_2= (p2!=NULL?p2->val:0);

        sum=val_1+val_2+carry;
        carry=sum/10;
        tmp->val=sum%10;

        if(i==(depth-1)&&((sum>10)||sum==10))
        {
            carryNode=(struct ListNode*)malloc(sizeof(struct ListNode));
            carryNode->val=1;
            tmp->next=carryNode;
            carryNode->next=NULL;
        }
        else if((p1!=NULL)&&(p2!=NULL))
        {
            p1=p1->next;
            p2=p2->next;
            tmp=tmp->next;
        }
        else if((p1==NULL)&&(p2!=NULL))
        {
            p2=p2->next;
            tmp=tmp->next;
        }
        else if((p1!=NULL)&&(p2==NULL))
        {
            p1=p1->next;
            tmp=tmp->next;
        }
        else
        {
            printf("error happend!\n");
        }
        
        
    }
    list2Array(p3);

    return p3;
}


int main()
{
    //int list_1[]={7,4,8};
    //int list_2[]={5,6,4}; 
    int list_1[]={5,6};
    int list_2[]={5};

    struct ListNode* ln_1;
    struct ListNode* ln_2;
    struct ListNode* ln_3;

    ln_1=array2List(list_1,sizeof(list_1)/sizeof(list_1[0]));
    ln_2=array2List(list_2,sizeof(list_2)/sizeof(list_2[0]));

    ln_3=addTwoNumbers(ln_1,ln_2);
    list2Array(ln_3);
}
