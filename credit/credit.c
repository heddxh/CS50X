#include <cs50.h>
#include <stdio.h>

long get_numbers(void);


int main(void)
{
  long numbers = get_numbers();

  
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