#include <cs50.h>
#include <stdio.h>

long get_numbers(void);
int multiply_sum(long numbers);
int remain_sum(long numbers);


int main(void)
{
    // user input
    long numbers = get_numbers();

    // calculate
    int sum1 = multiply_sum(numbers);
    int sum2 = remain_sum(numbers);

    // plus
    int result = sum1 + sum2

    // judge
    if(result % 10 = 0)
    {
        if
    }

}

long get_numbers(void)
{
    long numbers;
    do
    {
        numbers = get_long("Number: ");
    }
    while(numbers < 0);
    return numbers;
}

int multiply_sum(long numbers)
{
    int sum;
    int digit;
    while(numbers >= 10)
    {
        numbers = numbers / 10;
        digit = numbers % 10;
        numbers = numbers / 10;
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

int remain_sum(long numbers)
{
    int digit;
    int sum;
    while(numbers >= 0)
    {
        digit = numbers % 10;
        numbers = numbers / 100;
        sum = sum + digit
    }
    return sum;
}