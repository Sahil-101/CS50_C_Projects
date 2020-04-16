#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//still some bugs are there

int main(int argc, char *argv[])
{
    //buffer array of byte
    __uint8_t array[512];

    //command line argument check
    if(argc<2)
    {
        printf("Enter the file name via command line\n");
        return 1;
        
    }

    //file to be read data
    FILE *f = fopen("card.raw" ,"r");

    //check and imagcount int declaration
    //check for running while condition
    int check,imgcount=0;

    //image file pointer to be written in new files
    FILE *img;

    //assignment of check
    //fread returns number of elements read if operated successfully otherwise returns 0
    check=fread(array,1,512,f);

    //i for index usage and flag for else conditions
    int flag=0;

    //image name buffer
    char filename[7];

    while (check==512)
    {       
            //checking of jpeg format conditions
            if((array[0]==0xff)&&(array[1]==0xd8)&&(array[2]==0xff)&&((array[3] & 0xf0)==0xe0))
            {
                                           
                            //printing name in image name buffer
                            sprintf(filename,"%03i.jpg", imgcount);

                            //image file pointer along with name if already one was opened close the previous one
                            if(flag==1)
                            {
                                fclose(img);
                                img=fopen(filename,"w");
                            }
                            else
                            {
                                img=fopen(filename,"w");
                            }
                             //writing new file
                            fwrite(array,1,512,img);
                            flag=1;
                            imgcount++;  
                       
                    
            
            }
            
            //if no new jpeg header continue to write
            else if(flag==1)
            {
                fwrite(array,1,512,img);
            }


        //reassignment of check condition
        check=fread(array,1,512,f);
        
        
    }

    return 0;

}