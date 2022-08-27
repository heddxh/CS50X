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
    image[0][0] = round((image[0][1] + image[1][0] + image[1][1]) / 3.0);
    for (int w = 1; w < width; w++)
    {
        image[0][w] = round((image[0][w] + image[0][w - 1] + image[0][w + 1] + image[1][w] + image[1][w - 1] + image[1][w + 1]) / 6.0);
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < (width / 2); w++)
        {

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
