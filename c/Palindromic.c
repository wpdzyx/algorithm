/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

/*
pseudo code:
window: [bab]ad = 3
        b[aba]d = 3
        ba[bad] = 0

window: [cbbd] = 0
        c[bb]d = 2
        cb[bd] = 0
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char val;
    struct Node *next;
} node;

int prtlink(node *link);

#if 0
int longestPalindrome(char *s)
{
    char* pStr=NULL;
    pStr=s;
    int i=0,j=0;
    int len=0;
    int count=1;

    for(i=0;pStr[i]!='\0';i++)
    {
        for(j=i+1;pStr[j]!='\0';j++)
        {
            if(pStr[i]!=pStr[j])
            {
                count++;
            }
            else
            {
                if(count>len)
                {
                    len=count+1;
                }
                break;
            } 
        } 
        
        count=1;
    }
    return len;
}
#endif

node *str2link(char *s)
{
    char *pStr = NULL;
    pStr = s;

    /*sub string point, subStr point to the link start position, and sub Temp move forward*/
    node *subTemp = NULL;
    node *subStr = NULL;
    subStr = (node *)malloc(sizeof(node));
    subTemp = subStr;

    while (*pStr != '\0')
    {
        subTemp->val = *pStr;
        subTemp->next = malloc(sizeof(node));
        subTemp = subTemp->next;
        pStr++;
    }
    subTemp = NULL;

    prtlink(subStr);
    return subStr;
}

int prtlink(node *link)
{
    node *pLink;
    pLink = link;

    while (pLink->next != NULL)
    {
        printf("val:%c\n", pLink->val);
        pLink = pLink->next;
    }
    return 1;
}


#if 0
char *longestPalindrome(char *s)
{
    /*pStr for operate the string,but not move the origin string pointer*/
    char *pStr = NULL;

    pStr = s;
    int i = 0, j = 0;
    int len = 0;
    int count = 1;
    int idx[2] = {0};

    for (i = 0; pStr[i] != '\0'; i++)
    {
        //reset count to 1 when find a palindromic string, start to find next longest 
        count = 1;

        //if there is only one char, return it
        if(pStr[1]=='\0')
        {
            idx[0]=idx[1]=0;
            break;
        }

        for (j =(i+1); pStr[j] != '\0'; j++)
        {
            //if the side by side char are same, like s='aaaa', or s='bccccd'
            if(pStr[i]==pStr[j])
            {
                count++;
                if (count > len)
                {
                    len = count ;
                    idx[0] = i;
                    idx[1] = j;
                }
                continue;
            }

            /*check if the value is same*/
            if (pStr[i] != pStr[j])
            {
                count++;
            }
            else
            {
                {
                    if (count > len)
                    {
                        len = count;
                        idx[0] = i;
                        idx[1] = j;
                    }
                    /*start to check next loop of pStr*/
                    break;
                }
            }
        }

    }

    char *palindromic = (char *)malloc(sizeof(char) * 1000);
    memset(palindromic, 0x0, sizeof(char) * 1000);

    //get palindromic sub string from string s
    for (i = idx[0], j = 0; i <= (idx[1]); i++, j++)
    {
        palindromic[j] = s[i];
        printf("%s ", palindromic);
    }

    printf("\n");
    /*
    no palindromic sub string , the sub string same with original, like : abcda
    so we return the string first alphabet.
    */
    if(strcmp(palindromic,s)==0)
    {
        char* strSame="";
        strSame[0]=palindromic[0];
        //printf("compare string:%d，%s\n",strcmp(palindromic,s),strSame);
        return strSame;
    }

    return palindromic;
}
#endif 

char* longestPalindrome(char *s)
{
    /*pStr for operate the string,but not move the origin string pointer*/
    char *pStr = NULL;

    int i=0,j=0;
    int count=0,len=0;

    
    while(EQ(pStr[i],pStr[len-i]))
    {
        if(i<len/2)
        {
            i+=1;
        }
        else
        {
            return pStr
        }
        
    }
}

int main()
{
    //char* s="ababd";
    //char* s="abbd";
    //char *s = "bccc";
    char* s="abcda";
    //char* s="a";
    int count = 0;

    //count=longestPalindrome(s);
    //printf("longest string is:%d\n",count);
    //str2link(s);
    longestPalindrome(s);
}