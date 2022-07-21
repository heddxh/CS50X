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

int multiply_result(long numbers)
{
    while(???)
    {
        numbers = numbers / 10
        
    }
}