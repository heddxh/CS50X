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
    printf("%i\n", sum1);
    int sum2 = remain_sum(number);
    printf("%i\n", sum2);

    // plus
    int result = sum1 + sum2;
    printf("%i\n", result);

    // mount length
    int length = 0;
    while(number > 0)
    {
        length++;
        number = number / 10;
    }
    printf("%i\n", length);

    // judge
    int start = number / (10 ^ (length - 1));
    printf("%i\n", start);
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
    while(number >= 0)
    {
        digit = number % 10;
        number = number / 100;
        sum = sum + digit;
    }
    return sum;
}