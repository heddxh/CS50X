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
    int result = sum1 + sum2

    // mount length
    int length = 0;
    while(number > 0)
    {
        length++;
        number = number / 10
    }

    // judge
    if(result % 10 = 0)
    {
        if
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
        return sum;
    }
}

int remain_sum(long number)
{
    int digit;
    int sum;
    while(number >= 0)
    {
        digit = number % 10;
        number = number / 100;
        sum = sum + digit
    }
    return sum;
}