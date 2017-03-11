# include <cs50.h>
# include <stdio.h>

// argc = argument count; it's an int.
// argv[] is an array, which is a type of string in C.

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;  //exit code, can be anything but 0. It's an error code for internal reference.
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}