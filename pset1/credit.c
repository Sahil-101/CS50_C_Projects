#include<stdio.h>
#include<cs50.h>

int main()
{
int n;
long index=0,credit,sum,i=0,temp=0,sum2=0,sum3=0,credit2=0,first2=0,credit3;
int visalength=0,printcheck=0;
credit = get_long("Number :");
credit2=credit;
credit3=credit;

while(true)
{
    if(credit3<100)
    {
        break;
    }
    visalength++;
    credit3/=10;

}
first2=credit3;


while(credit!=0)
{
    if(i%2==0)
    {
        sum3+=(credit%10);
    }
    else
    {
        temp=(2*(credit%10));
        while(temp!=0)
        {
            sum2+=(temp%10);
            temp=temp/10;
        }
    }
    credit=credit/10;
    i+=1;
}
while(credit2>10)
{
    index=credit2/10;
    credit2=credit2/10;
}
//printf("index=%ld,sum3+sum2=%ld\n", index,sum3+sum2);
//printf("first2 is %ld", first2);
if((sum2+sum3)%10==0)
{
    if(index==5)
    {
        if((first2>50)&&(first2<56))
        {
            printf("MASTERCARD\n");
            printcheck++;
        }

    }
    else if((first2==34)||(first2==37))
    {
        {
            printf("AMEX\n");
            printcheck++;
        }

    }
    else
    {
        if((index==4) && (visalength>10))
        {
            printf("VISA\n");
            printcheck++;
        }

    }
}
if(printcheck==0)
{
    printf("INVALID\n");
}
return 0;
}
