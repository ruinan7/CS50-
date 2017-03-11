# include <cs50.h>
# include <stdio.h>

int main (void)
{
    printf("How old are you? ");
    int i = get_int();
    printf("You are %i\n", i);
}