# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

// argc = argument count; it's an int.
// argv[] is an array, which is a type of string in C.

int main (int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}