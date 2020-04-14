#include "helpers.h"
#include<stdarg.h>
#include<math.h>
#include<stdio.h>

int startRow, endRow, startColumn, endColumn;


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE *pointer;
    BYTE avg;
    BYTE r,g,b;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            pointer = &image[i][j];
            b = (*pointer).rgbtBlue;
            g = (*pointer).rgbtGreen;
            r = (*pointer).rgbtRed;

            if((b+r+g)%3==2)
            {
                avg=((b+r+g)/3)+1;
            }
            else
            {
                avg=(b+r+g)/3;
            }


            (*pointer).rgbtBlue=avg;
            (*pointer).rgbtGreen=avg;
            (*pointer).rgbtRed=avg;

        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE *pointer1;
    RGBTRIPLE *pointer2;
    RGBTRIPLE *pointer3;

    RGBTRIPLE temp;

    pointer3=&temp;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width/2; j++)
        {
            pointer1=&image[i][j];
            pointer2=&image[i][width-1-j];
            *pointer3=*pointer1;
            *pointer1=*pointer2;
            *pointer2=*pointer3;
        }
    }
  
    return;
}

int average(int arg_count, ...)
{
    float avg;
    int sum = 0;
    va_list list;
    va_start(list, arg_count);
    for (int i = 0; i < arg_count; i++)
    {
        sum += va_arg(list, int);
    }

    avg = (sum / (float)arg_count);
    if (avg - (int)avg >= 0.5)
    {
        return avg = (int)avg + 1;
    }
    else
    {

        return avg = (int)avg;
    }
}

void loopavg(int a1,int a2 ,int startrow , int endrow ,int startcol , int endcol,int height ,int width,RGBTRIPLE image2[height][width],RGBTRIPLE image[height][width])
{
    int avg,blue=0,red=0,green=0,count=0;
    RGBTRIPLE * pointermain;
    pointermain=&image[a1][a2]; 
    for(int i=startrow; i<endrow; i++)
    {
        for(int j=startcol; j<endcol; j++)
        {
            red+=pointermain->rgbtRed;
            blue+=pointermain->rgbtBlue;
            green+=pointermain->rgbtGreen;
            count++;
        }
    }
    pointermain->rgbtRed=round( (double) red/(count));
    pointermain->rgbtGreen=round( (double) green/(count));
    pointermain->rgbtBlue=round( (double) blue/(count));
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];

    int max,min;

    //copying image as image2
    for(int i=0; i<height; i++)
    {
        for(int j=0;j<width; j++)
        {
            image2[i][j]=image[i][j];
        }
    }

    for(int i=1; i<height-1; i++)
    {
        for(int j=1; j<width-1; j++)
        {
                image[i][j].rgbtBlue= average(9,image2[i-1][j-1].rgbtBlue,  image2[i-1][j].rgbtBlue,image2[i-1][j+1].rgbtBlue,image2[i][j-1].rgbtBlue,image2[i][j].rgbtBlue,
                                image2[i][j+1].rgbtBlue , image2[i+1][j-1].rgbtBlue ,  image2[i+1][j].rgbtBlue, image2[i+1][j+1].rgbtBlue);

                image[i][j].rgbtGreen= average(9 ,image2[i-1][j-1].rgbtGreen ,image2[i-1][j].rgbtGreen ,image2[i-1][j+1].rgbtGreen, image2[i][j-1].rgbtGreen ,
                                 image2[i][j].rgbtGreen ,image2[i][j+1].rgbtGreen , image2[i+1][j-1].rgbtGreen , image2[i+1][j].rgbtGreen , image2[i+1][j+1].rgbtGreen);

                image[i][j].rgbtRed= average(9, image2[i-1][j-1].rgbtRed ,image2[i-1][j].rgbtRed , image2[i-1][j+1].rgbtRed , image2[i][j-1].rgbtRed ,
                                 image2[i][j].rgbtRed , image2[i][j+1].rgbtRed , image2[i+1][j-1].rgbtRed ,image2[i+1][j].rgbtRed , image2[i+1][j+1].rgbtRed);
        }
    }

    for(int i=0; i<height; i+=height-1)
    {
        for(int j=0; j<width; j++)
        {   
            //top left corner
            if((i==0)&&(j==0))
            {
                image[i][j].rgbtBlue= average(4,image2[i][j].rgbtBlue,image2[i][j+1].rgbtBlue , image2[i+1][j].rgbtBlue, image2[i+1][j+1].rgbtBlue);

                image[i][j].rgbtRed= average(4,image2[i][j].rgbtRed,image2[i][j+1].rgbtRed , image2[i+1][j].rgbtRed, image2[i+1][j+1].rgbtRed);

                image[i][j].rgbtGreen= average(4,image2[i][j].rgbtGreen,image2[i][j+1].rgbtGreen , image2[i+1][j].rgbtGreen, image2[i+1][j+1].rgbtGreen);
                
            }
            //top right corner
            else if((i==0)&&(j==width-1))
            {
                image[i][j].rgbtBlue= average(4,image2[i][j].rgbtBlue,image2[i][j-1].rgbtBlue , image2[i+1][j].rgbtBlue, image2[i+1][j-1].rgbtBlue);

                image[i][j].rgbtRed= average(4,image2[i][j].rgbtRed,image2[i][j-1].rgbtRed , image2[i+1][j].rgbtRed, image2[i+1][j-1].rgbtRed);

                image[i][j].rgbtGreen= average(4,image2[i][j].rgbtGreen,image2[i][j-1].rgbtGreen , image2[i+1][j].rgbtGreen, image2[i+1][j-1].rgbtGreen);
            }
            //bottom left corner
            else if((i==height-1)&&(j==0))
            {
                image[i][j].rgbtBlue= average(4,image2[i][j].rgbtBlue,image2[i][j+1].rgbtBlue , image2[i-1][j].rgbtBlue, image2[i-1][j+1].rgbtBlue);

                image[i][j].rgbtRed= average(4,image2[i][j].rgbtRed,image2[i][j+1].rgbtRed , image2[i-1][j].rgbtRed, image2[i-1][j+1].rgbtRed);

                image[i][j].rgbtGreen= average(4,image2[i][j].rgbtGreen,image2[i][j+1].rgbtGreen , image2[i-1][j].rgbtGreen, image2[i-1][j+1].rgbtGreen);                   
                
            }
            //bottom right corner
            else if((i==height-1)&&(j==width-1))
            {
                image[i][j].rgbtBlue= average(4,image2[i][j].rgbtBlue,image2[i][j-1].rgbtBlue , image2[i-1][j].rgbtBlue, image2[i-1][j-1].rgbtBlue);

                image[i][j].rgbtRed= average(4,image2[i][j].rgbtRed,image2[i][j-1].rgbtRed , image2[i-1][j].rgbtRed, image2[i-1][j-1].rgbtRed);

                image[i][j].rgbtGreen= average(4,image2[i][j].rgbtGreen,image2[i][j-1].rgbtGreen , image2[i-1][j].rgbtGreen, image2[i-1][j-1].rgbtGreen);                   
                
            }

            //top edges
            else if((i==0)&&((j!=0)&&(j!=width-1)))
            {
                image[i][j].rgbtBlue= average(6,image2[i][j-1].rgbtBlue,image2[i][j].rgbtBlue,image2[i][j+1].rgbtBlue , image2[i+1][j-1].rgbtBlue ,  image2[i+1][j].rgbtBlue, image2[i+1][j+1].rgbtBlue);

                image[i][j].rgbtGreen= average(6 ,image2[i][j-1].rgbtGreen ,image2[i][j].rgbtGreen ,image2[i][j+1].rgbtGreen , image2[i+1][j-1].rgbtGreen , image2[i+1][j].rgbtGreen , image2[i+1][j+1].rgbtGreen);

                image[i][j].rgbtRed= average(6,image2[i][j-1].rgbtRed ,image2[i][j].rgbtRed , image2[i][j+1].rgbtRed , image2[i+1][j-1].rgbtRed ,image2[i+1][j].rgbtRed , image2[i+1][j+1].rgbtRed);
           
            }

            //bottom edges
            else if((i==height-1)&&((j!=0)&&(j!=width-1)))
            {
                image[i][j].rgbtBlue= average(6,image2[i-1][j-1].rgbtBlue,  image2[i-1][j].rgbtBlue,image2[i-1][j+1].rgbtBlue,image2[i][j-1].rgbtBlue,image2[i][j].rgbtBlue,
                                image2[i][j+1].rgbtBlue);

                image[i][j].rgbtGreen= average(6 ,image2[i-1][j-1].rgbtGreen ,image2[i-1][j].rgbtGreen ,image2[i-1][j+1].rgbtGreen, image2[i][j-1].rgbtGreen ,
                                 image2[i][j].rgbtGreen ,image2[i][j+1].rgbtGreen);

                image[i][j].rgbtRed= average(6, image2[i-1][j-1].rgbtRed ,image2[i-1][j].rgbtRed , image2[i-1][j+1].rgbtRed , image2[i][j-1].rgbtRed ,
                                 image2[i][j].rgbtRed , image2[i][j+1].rgbtRed);
                    }
            

        }
    }

    for(int i=1; i<height-1; i++)
    {
        for(int j=0; j<width; j+=width-1)
        {
            //for left edges
            if(j==0)
            {
                image[i][j].rgbtBlue= average(6,image2[i-1][j+1].rgbtBlue,  image2[i-1][j].rgbtBlue,image2[i+1][j+1].rgbtBlue,image2[i+1][j].rgbtBlue,image2[i][j].rgbtBlue,
                                image2[i][j+1].rgbtBlue);

                image[i][j].rgbtRed= average(6,image2[i-1][j+1].rgbtRed,  image2[i-1][j].rgbtRed,image2[i+1][j+1].rgbtRed,image2[i+1][j].rgbtRed,image2[i][j].rgbtRed,
                                image2[i][j+1].rgbtRed);

                image[i][j].rgbtGreen= average(6,image2[i-1][j+1].rgbtGreen,  image2[i-1][j].rgbtGreen,image2[i+1][j+1].rgbtGreen,image2[i+1][j].rgbtGreen,image2[i][j].rgbtGreen,
                                image2[i][j+1].rgbtGreen);
            }

            else if(j==width-1)
            {
                //for right edge
                image[i][j].rgbtBlue= average(6,image2[i-1][j-1].rgbtBlue,  image2[i-1][j].rgbtBlue,image2[i+1][j-1].rgbtBlue,image2[i+1][j].rgbtBlue,image2[i][j].rgbtBlue,
                                image2[i][j-1].rgbtBlue);

                image[i][j].rgbtRed= average(6,image2[i-1][j-1].rgbtRed,  image2[i-1][j].rgbtRed,image2[i+1][j-1].rgbtRed,image2[i+1][j].rgbtRed,image2[i][j].rgbtRed,
                                image2[i][j-1].rgbtRed);

                image[i][j].rgbtGreen= average(6,image2[i-1][j-1].rgbtGreen,  image2[i-1][j].rgbtGreen,image2[i+1][j-1].rgbtGreen,image2[i+1][j].rgbtGreen,image2[i][j].rgbtGreen,
                                image2[i][j-1].rgbtGreen);
            
            }

        }
            
    }
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

//top rigth corner
//bottom left corner
//bottom right corner