/*
* N beers; 
* 2xbootle --> 1 beer
* 4xcovers --> 1 beer
* How many beers will buy ? 
*/

#include <stdio.h>

int buy(int beers,int bootles,int covers)
{
    /*5 beers = 5 bootles + 5 covers*/
    /*[5,0,0] 
     *[3,1,1]
     *[3,0,0]
     *[1,1,3]
     *[2,0,0]
     *[1,0,2]
    */
    int changes=0;

    bootles+=beers;
    covers+=beers;

    changes+=bootles/2;
    changes+=covers/4;

    bootles%=2;
    covers%=4;
    beers=changes;

    printf("beers:%d,bootle:%d,cover:%d\n",beers,bootles,covers);

    if((changes+bootles<2)&&(changes+covers<4))
    {
        return beers;
    } 

    return beers+buy(beers,bootles,covers);

}

int main()
{
    int total=0;
    int beers=35;
    total=buy(beers,0,0);

    printf("total beers are:%d\n",total+beers);
}