# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

// argc = argument count; it's an int.
// argv[] is an array, which is a type of string in C.

int main (int argc, string argv[])
{
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            printf("%c", argv[i][j]);
        }
        printf("\n");
    }
}