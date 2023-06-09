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
    RGBTRIPLE tmp[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int cnt = 0;
            int sumb = 0;
            int sumg = 0;
            int sumr = 0;
            for (int row = -1; row <= 1; row++)
            {
                if (h + row < 0 || h + row > height - 1)
                {
                    continue; // Go out of this loop
                }
                for (int col = -1; col <= 1; col++)
                {
                    if (w + col < 0 || w + col > width - 1)
                    {
                        continue;
                    }

                    cnt++;
                    sumb += image[h + row][w + col].rgbtBlue;
                    sumg += image[h + row][w + col].rgbtGreen;
                    sumr += image[h + row][w + col].rgbtRed;
                }

            }
            tmp[h][w].rgbtBlue = sumb / cnt;
            tmp[h][w].rgbtGreen = sumg / cnt;
            tmp[h][w].rgbtRed = sumr / cnt;
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = tmp[h][w];
        }
    }
    return;
}

// Detect edges
// NOT COMPLETED!!!!!!
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE gx = 0;
            RGBTRIPLE gy = 0;

            for (int row = -1; row <= 1; row++)
            {
                if (h + row < 0 || h + row > height - 1)
                {
                    continue;
                }
                for (int col = -1; col <= 1; col++)
                {
                    if (w + col < 0 || w + col > width - 1)
                    {
                        continue;
                    }
                }
                if (col != 0)
                {
                    if (row != 0)
                    {
                        gx = gx + BGRcompute(image[h][w], '*', 1);
                        gx = BGRcompute(image[h][w], '+', )
                        gy += row * 1;
                    }
                    else
                    {
                        gx += col * 2;
                    }
                }
                else
                {
                    gy += row * 2;
                }
            }

            tmp [h][w] =
        }
    }
    return;
}
