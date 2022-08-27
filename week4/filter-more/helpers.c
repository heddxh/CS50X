#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            BYTE B = image[h][w].rgbtBlue;
            BYTE G = image[h][w].rgbtGreen;
            BYTE R = image[h][w].rgbtRed;
            BYTE average = round((B + G + R) / 3.0);
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < (width / 2); w++)
        {
            RGBTRIPLE tmp;
            tmp = image[h][w];
            image[h][w] = image[h][width - w + 1];
            image[h][width - w + 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    int cnt = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    if (h + row < 0 || h + row > height - 1)
                    {
                        continue; // Go out of this loop
                    }
                    if (w + col < 0 || w + col > width - 1)
                    {
                        continue;
                    }

                    cnt++;
                    
                }

            }
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}