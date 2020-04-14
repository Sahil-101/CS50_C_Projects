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
            {
                image[i][j].rgbtBlue= average(9,image2[i-1][j-1].rgbtBlue,  image2[i-1][j].rgbtBlue,image2[i-1][j+1].rgbtBlue,image2[i][j-1].rgbtBlue,image2[i][j].rgbtBlue,
                 image2[i][j+1].rgbtBlue , image2[i+1][j-1].rgbtBlue ,  image2[i+1][j].rgbtBlue, image2[i+1][j+1].rgbtBlue);

                image[i][j].rgbtGreen= average(9 ,image2[i-1][j-1].rgbtGreen ,image2[i-1][j].rgbtGreen ,image2[i-1][j+1].rgbtGreen, image2[i][j-1].rgbtGreen ,
                                 image2[i][j].rgbtGreen ,image2[i][j+1].rgbtGreen , image2[i+1][j-1].rgbtGreen , image2[i+1][j].rgbtGreen , image2[i+1][j+1].rgbtGreen);

                image[i][j].rgbtRed= average(9, image2[i-1][j-1].rgbtRed ,image2[i-1][j].rgbtRed , image2[i-1][j+1].rgbtRed , image2[i][j-1].rgbtRed ,
                                 image2[i][j].rgbtRed , image2[i][j+1].rgbtRed , image2[i+1][j-1].rgbtRed ,image2[i+1][j].rgbtRed , image2[i+1][j+1].rgbtRed);
            
            }
            
        }
    }


    
    for(int i=0; i<height; i+=height)
    {
        for(int j=0; j<width; j++)
        {
            startRow= ((i - 1)<0) ? i : i - 1;
            endRow =  (i + 1 >= height) ? i : i + 1;
            startColumn = (j - 1 < 0) ? j : j - 1;
            endColumn = (j + 1 >= width) ? j : j + 1;

            loopavg(i , j , startRow ,endRow , startColumn ,endColumn , height , width ,image2,image);
        }
    }



    for(int i=1; i<height-1; i++)
    {
        for(int j=0; j<width; j=+width)
        {
            startRow= (i - 1 < 0) ? i : i - 1;
            endRow = (i + 1 >= height) ? i : i + 1;
            startColumn = (j - 1 < 0) ? j : j - 1;
            endColumn = (j + 1 >= width) ? j : j + 1;

            loopavg(i , j , startRow ,endRow , startColumn ,endColumn , height , width ,image2, image);
        
        }
    }

    
}
