for(int i=0; i<=height; i+=height)
    {
       if (i==0)
       {
           lim=i+1;
       }
       else
       {
           lim=i-1;
       }
        for(int j=0; j<width; j++)
        {
            if(j==0)
            {
                image[i][j].rgbtBlue=  average(4,image2[i][j].rgbtBlue ,image2[i][j+1].rgbtBlue ,image2[lim][j].rgbtBlue , image2[lim][j+1].rgbtBlue);

                image[i][j].rgbtRed=  average(4, image2[i][j].rgbtRed , image2[i][j+1].rgbtRed ,image2[lim][j].rgbtRed ,  image2[lim][j+1].rgbtRed);

                image[i][j].rgbtGreen=  average(4,image2[i][j].rgbtGreen , image2[i][j+1].rgbtGreen , image2[lim][j].rgbtGreen , image2[lim][j+1].rgbtGreen);
            }
            else if(j==width)
            {
                image[i][j].rgbtBlue=  average(4,image2[i][j].rgbtBlue ,image2[i+1][j].rgbtBlue ,image2[i][j-1].rgbtBlue , image2[lim][j+1].rgbtBlue);

                image[i][j].rgbtRed=  average(4, image2[i][j].rgbtRed , image2[i][j+1].rgbtRed ,image2[lim][j].rgbtRed ,  image2[lim][j+1].rgbtRed);

                image[i][j].rgbtGreen=  average(4,image2[i][j].rgbtGreen , image2[i][j+1].rgbtGreen , image2[lim][j].rgbtGreen , image2[lim][j+1].rgbtGreen);
            }
            else          
            {
                image[i][j].rgbtBlue=  average(6,image2[i][j-1].rgbtBlue , image2[i][j].rgbtBlue , image2[i][j+1].rgbtBlue , image2[lim][j-1].rgbtBlue,  image2[lim][j].rgbtBlue ,  image2[lim][j+1].rgbtBlue);

                image[i][j].rgbtRed=  average(6,image2[i][j-1].rgbtRed , image2[i][j].rgbtRed ,  image2[i][j+1].rgbtRed ,  image2[lim][j-1].rgbtRed ,  image2[lim][j].rgbtRed,  image2[lim][j+1].rgbtRed);

                image[i][j].rgbtGreen= average(6,image2[i][j-1].rgbtGreen , image2[i][j].rgbtGreen , image2[i][j+1].rgbtGreen ,  image2[lim][j-1].rgbtGreen ,  image2[lim][j].rgbtGreen ,  image2[lim][j+1].rgbtGreen);        
            }
        } 
       
    }
    
    for(int j=1; j<=width+1; j+=width)
    {
       if (j==0)
       {
           lim=j+1;
       }
       else
       {
           lim=j-1;
       }
        for(int i=1; i<height-1; i++)
        {
                image[i][j].rgbtBlue=  average(6,image2[i][lim].rgbtBlue ,image2[i][j].rgbtBlue ,  image2[i+1][j].rgbtBlue ,  image2[i+1][lim].rgbtBlue ,  image2[i-1][j].rgbtBlue ,  image2[i-1][j+1].rgbtBlue);

                image[i][j].rgbtRed=  average(6,image2[i][lim].rgbtRed , image2[i][j].rgbtRed,  image2[i+1][j].rgbtRed , image2[i+1][lim].rgbtRed ,  image2[i-1][j].rgbtRed , image2[i-1][j+1].rgbtRed);

                image[i][j].rgbtGreen=  average(6,image2[i][lim].rgbtGreen , image2[i][j].rgbtGreen ,  image2[i+1][j].rgbtGreen , image2[i+1][lim].rgbtGreen ,  image2[i-1][j].rgbtGreen , image2[i-1][j+1].rgbtGreen);

        } 
       
    }
    

