# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>


int main (void)
{
    // get user's name 
    string s = get_string();
    
    // if the first char is not a space, then print the capitalized version of first char
    if(s[0] != ' ')
    {
        printf("%c", toupper(s[0])); 
    }
    
    //starting from the 2nd char, print the capitalized version of this char if the previous char is a space AND current char is not a space
    for (int i = 1, n = strlen(s); i < n; i++)
    {
        if(s[i-1] == ' ' && s[i] != ' ')
        {
        printf("%c", toupper(s[i])); 
        }
    }
    printf("\n");
}
