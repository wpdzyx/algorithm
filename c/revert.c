#include <stdio.h>
#include <limits.h>

int func(int si_a, int si_b)
{
    int result;
    if (si_a > 0)
    { /* si_a is positive */
        if (si_b > 0)
        { /* si_a and si_b are positive */
            if (si_a > (INT_MAX / si_b))
            {
                /* Handle error */
                return 0;
            }
        }
        else
        { /* si_a positive, si_b nonpositive */
            if (si_b < (INT_MIN / si_a))
            {
                /* Handle error */
                return 0;
            }
        } /* si_a positive, si_b nonpositive */
    }
    else
    { /* si_a is nonpositive */
        if (si_b > 0)
        { /* si_a is nonpositive, si_b is positive */
            if (si_a < (INT_MIN / si_b))
            {
                /* Handle error */
                return 0;
            }
        }
        else
        { /* si_a and si_b are nonpositive */
            if ((si_a != 0) && (si_b < (INT_MAX / si_a)))
            {
                /* Handle error */
                return 0;
            }
        } /* End if si_a and si_b are nonpositive */
    }     /* End if si_a is nonpositive */

    result = si_a * si_b;
    return result;
}

int reverse(int x)
{
    int rev = 0;
    int flag = 0;
    int prev_rev = 0;
    int digital = 0;

    if ((x < 0)&&(x>INT_MIN))
    {
        x = -x;
        flag = 1;
    }
    
    if(x==INT_MIN)
    {
        return 0;
    }
    

    while (x / 10 != 0 || x % 10 != 0)
    {
        digital = x % 10;
        prev_rev = func(rev, 10) + digital;
        if ((prev_rev - digital) / 10 != rev)
        {
            return 0;
        }
        rev = prev_rev;
        x = x / 10;
    }

    if (flag == 1)
    {
        rev = -rev;
    }

    printf("rev is :%d\n", rev);
    return rev;
}

int main()
{
    int x = 1534236469; //964632435;

    reverse(x);
}