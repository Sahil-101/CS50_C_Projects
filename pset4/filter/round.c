#include<math.h>

int Round(double a)
{
    if(a- floor(a) >0.5)
    {
        return (int) a+1;
    }
    else
    {
        return (int) a;
    }
    
}
