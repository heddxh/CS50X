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
    int start;
    while(number > 0)
    {
        length++;
        number = number / 10;
        if (number < 10 && number > 0)
        {
            start = number;
        }
    }

    // printf("%i\n", length);
    // printf("%i\n", start);
    // printf("%i\n", sum1);
     printf("%i\n", sum2);
    //printf("%i\n", result);

    // judge
    if(result % 10 == 0)
    {
        if(length == 15)
        {
            printf("AMEX\n");
        }
        else if (start == 4)
        {
            printf("VISA\n");
        }
        else
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
    int sum;
    int digit;
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
    int digit;
    int sum;
    while(number > 0)
    {
        digit = number % 10;
        number = number / 100;
        printf("%i\n", digit);
        sum = sum + digit;
    }
    return sum;
}