#include <stdio.h>

int is_zhishu(int number)
// 1 表示不是质数
{
    int half_number = number / 2;
    for(int i = 2, i < half_number, i++)
    {
        result1 = number / i;
        result2 = number / ((float)i);
        if(result1 == result2)
        {
            return 1;
        }
    }
}