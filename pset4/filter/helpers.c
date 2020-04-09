#include "helpers.h"

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

    if(width%2==0)
    {

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
    }
    else
    {


        for(int i=0; i<height; i++)
        {
            for(int j=0; j<(width/2); j++)
            {
                pointer1=&image[i][j];
                pointer2=&image[i][width-1-j];
                *pointer3=*pointer1;
                *pointer1=*pointer2;
                *pointer2=*pointer3;
            }
        }


    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
