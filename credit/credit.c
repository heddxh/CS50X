#include <cs50.h>
#include <stdio.h>

long get_numbers(void);


int main(void)
{
    // user input
    long numbers = get_numbers();

    // calculate
    int sum = multiply_sum(numbers);

    // plus remain digits


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
    while(numbers >= 10)
    {
        digit = numbers % 10;
        numbers = numbers / 100;
    }
}