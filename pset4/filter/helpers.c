#include "helpers.h"
#include "math.h"
#include "limits.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grey = round((round(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)) / 3);
            image[i][j].rgbtRed = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtBlue = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //declare the array to hold the new rgb values.
            int sepia[3] =
            {
                round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue)),
                round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue)),
                round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue))
            };
            //Checks for overflow.
            for (int n = 0; n < 3; n++)
            {
                if (sepia[n] > UCHAR_MAX)
                {
                    sepia[n] = UCHAR_MAX;
                }
            }
            //Asigns values.
            image[i][j].rgbtRed = sepia[0];
            image[i][j].rgbtGreen = sepia[1];
            image[i][j].rgbtBlue = sepia[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    long ex[3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            ex[0] = image[i][j].rgbtBlue;
            ex[1] = image[i][j].rgbtGreen;

            ex[2] = image[i][j].rgbtRed;
            //Changes between the first and last element of the array
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            //Sets the value of the array
            image[i][width - j - 1].rgbtBlue = ex[0];
            image[i][width - j - 1].rgbtGreen = ex[1];
            image[i][width - j - 1].rgbtRed = ex[2];
        }
    }
    return;
}

// Blur image, I'm actually proud of this, might be a better solution but is clean IMO.
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    //Saves copy of the original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    //Rewrites the color of the image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double ex[3];
            ex[0] = 0;
            ex[1] = 0;
            ex[2] = 0;
            int counter = 0;
            int x = (i - 1);
            //So the idea next is to think a set of 3x3, and check if there is a pixel on that coordenate.
            //If there is, the program gets the RGB and increases the counter.
            for (int ii = 0; ii < 3; ii++)
            {
                int y = (j - 1);
                for (int jj = 0; jj < 3; jj++)
                {
                    if ((x > -1) && (x < height) && (y < width) && (y > -1))
                    {
                        //Adds rgb values for each pixel.
                        ex[0] += original[x][y].rgbtRed;
                        ex[1] += original[x][y].rgbtGreen;
                        ex[2] += original[x][y].rgbtBlue;
                        counter++;
                    }
                    y++;
                }
                x++;
            }
            //Sets image to temp variables.
            image[i][j].rgbtRed = round(ex[0] / counter);
            ex[0] = image[i][j].rgbtRed;
            image[i][j].rgbtGreen = round(ex[1] / counter);
            ex[1] = image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = round(ex[2] / counter);
            ex[2] = image[i][j].rgbtBlue;
        }
    }
    return;
}