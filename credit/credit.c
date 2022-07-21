#include <cs50.h>
#include <stdio.h>

long get_numbers(void);


int main(void)
{
    // user input
    long numbers = get_numbers();

    // auth


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
    while(numbers >= 10)
    {
        numbers = numbers / 10;
        sum = sum + numbers % 10 *2;
        return sum;
    }
}