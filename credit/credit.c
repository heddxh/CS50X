#include <cs50.h>
#include <stdio.h>

long get_number(void);
int multiply_sum(long number);
int remain_sum(long number);


int main(void)
{
    // user input
    long number = get_number();

    // calculate
    int sum1 = multiply_sum(number);
    int sum2 = remain_sum(number);

    // plus
    int result = sum1 + sum2;

    // mount length & detect start
    int length = 0;
    int start1;
    int start2;
    while(number > 0)
    {
        length++;
        number = number / 10;
        if(number < 100 && number >= 10)
        {
            start2 = number;
        }
        if (number < 10 && number > 0)
        {
            start1 = number;
        }
    }

    // judge
    if (result % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (length == 15)
    {
        if (start2 == 34 || start2 == 37)
        {
            printf("AMEX\n");
        }
        else
        {
           printf("INVALID\n");
        }
    }
    else if (start1 == 4)
    {
        if (length == 13 || length == 16)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (start2 == 51 || start2 == 52 || start2 == 53 || start2 == 54 || start2 == 55)
    {
        if (length == 16)
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_number(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while(number < 0);
    return number;
}

int multiply_sum(long number)
{
    int sum = 0;
    int digit = 0;
    while(number >= 10)
    {
        number = number / 10;
        digit = number % 10;
        number = number / 10;
        if (digit * 2 > 9)
        {
            sum = sum + digit * 2 / 10 + digit * 2 % 10;
        }
        else
        {
            sum = sum + digit * 2;
        }
    }
    return sum;
}

int remain_sum(long number)
{
    int digit = 0;
    int sum = 0;
    while(number > 0)
    {
        digit = number % 10;
        number = number / 100;
        sum = sum + digit;
    }
    return sum;
}