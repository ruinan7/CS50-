#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Minutes: ");
    int shower = get_int();
    printf("Bottles: %i\n", shower * 192 / 16);
}