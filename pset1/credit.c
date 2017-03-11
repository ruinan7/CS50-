#include <stdio.h>
#include <cs50.h>

void checksum(long long n);
int countdigits(long long x);

        
int main(void)
{
    printf("Number: ");
    long long cardnumber = get_long_long();
    checksum(cardnumber);
    countdigits(cardnumber);

}

void checksum(long long n)
{
    long long sum = 0;
    long long sum2 = 0;
    long long num = n / 10;
    long long num2 = n;
    
    for (int i = 1; i < 9; i = i + 1)
    {
        sum = sum + (num % 10 % 10 * 2)/10 + (num % 10 % 10 * 2) % 10;
        num = num / 100;
    }
    for (int i = 1; i < 9; i = i + 1)
    {
        sum2 = sum2 + num2 % 10 % 10;
        num2 = num2 / 100;
    }
    
    //printf("Sum is %lld\n", sum);
    //printf("Sum2 is %lld\n", sum2);
    long long total = sum + sum2;
    //printf("total is %lld\n", total);
    if (total % 10 == 0)
    {
        if ((n /10000000000000 % 37 == 0 || n /10000000000000 % 34 == 0)&& countdigits(n) == 15)
        {
            printf("AMEX\n");
        }
        else if ((n /100000000000000 % 51 == 0 || n /100000000000000 % 52 == 0 || n /100000000000000 % 53 == 0 || n /100000000000000 % 54 == 0 || n /100000000000000 % 55 == 0)&& countdigits(n) == 16)
        {
            printf("MASTERCARD\n");    
        }
        else if ((n /1000000000000000 % 4 == 0 && countdigits(n) == 16) || (n /1000000000000 % 4 == 0 && countdigits(n) == 13))
        {
            printf("VISA\n");                
        }
        else 
        {
        printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
    
}


int countdigits(long long x)
{
    int count = 0;

    while(x != 0)
    {
        // n = n/10
        x /= 10;
        ++count;
    }
    return count;
    //printf("Number of digits: %d", count);
}