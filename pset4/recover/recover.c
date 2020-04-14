#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int array[5000];

    /*if(argc<2)
    {
        printf("Enter the file name via command line\n");
        
    }
    */



    FILE *f = fopen("card.raw" ,"r");

    fread(array,sizeof(int),512,f);

    int count=0;    

    for(int i=0; i<5000; i++)
    {
           if (array[i]!=0)
           {
               printf("yoss %d\n",(array[i]));
           }
     
    }

    return 0;

}
