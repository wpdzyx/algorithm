/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <stdio.h>

typedef enum
{
    I=1,
    V=5,
    X=10,
    L=50,
    C=100,
    D=500,
    M=1000,
}romangroup;

int romanToInt(char * s)
{
    /*
    step 1 : get the seprated char;
    step 2 : check if the char next is greater than him;
    step 3 : add all of the number;
    */
   /*
   if((s[0]=='I')&&(s[1]=='V'))
   {
       return 4;
   }
   else if((s[0]=='I')&&(s[1]=='X'))
   {
       return 9;
   }
   else if((s[0]=='X')&&(s[1]=='L'))
   {
       return 40;
   }
   else if ((s[0]=='X')&&(s[1]=='C'))
   {
       return 90;
   }
   else if((s[0]=='C')&&(s[1]=='D'))
   {
       return 400;
   }
   else if((s[0]=='C')&&(s[1]=='M'))
   {
       return 900;
   }
   */

   int i=0;
   int num=0;
   for(i=0;s[i]!='\0';)
   {
        if((s[i]!='\0')&&(s[i+1]!='\0'))
        {
            if((s[i]=='I')&&(s[i+1]=='V'))
            {
                num+=4;
                i+=2;
                continue;
            }
            else if((s[i]=='I')&&(s[i+1]=='X'))
            {
                num+=9;
                i+=2;                
                continue;
            }
            else if((s[i]=='X')&&(s[i+1]=='L'))
            {
                num+=40;
                i+=2;
                continue;
            }
            else if ((s[i]=='X')&&(s[i+1]=='C'))
            {
                num+=90;
                i+=2;
                continue;
            }
            else if((s[i]=='C')&&(s[i+1]=='D'))
            {
                num+=400;
                i+=2;
                continue;
            }
            else if((s[i]=='C')&&(s[i+1]=='M'))
            {
                num+=900;
                i+=2;
                continue;
            }
        }


        if(s[i]=='M')
        {
            num+=1000;
        }
        else if (s[i]=='D')
        {
            num+=500;
        }
        else if (s[i]=='C')
        {
            num+=100;
        }
        else if(s[i]=='L')
        {
            num+=50;
        }
        else if(s[i]=='X')
        {
            num+=10;
        }
        else if(s[i]=='V')
        {
            num+=5;
        }
        else if (s[i]=='I')
        {
            num+=1;
        }

        i++;              
    }

   return num;

}

int main()
{
    //char* s="MCMXCIV";
    char* s="M";
    int num=0;

    num=romanToInt(s);
    printf("num is:%d\n",num);
}