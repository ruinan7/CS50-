# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>


int main (int argc, string argv[])
{
    // produce a error message if you don't have a key or have more than one key.
    if (argc != 2)
    {
        printf("Error! Your key must a non-negative integer~\n");
        return 1;
    }
    else
    {
        //store key in an int
        string kstring = argv[1];
        int k = atoi(kstring);

        //promot user to enter plaintext
        printf("plaintext: ");
        string plaintext = get_string();
        
        //convert plaintext into ciphertext using user's key
        char ciphertext[strlen(plaintext)];
        printf("ciphertext: ");
        
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // capital letters
            if (plaintext[i] >= 65 && plaintext[i] <= 90)
            {
            ciphertext[i] = (plaintext[i] - 64 + k) % 26 + 64;
            printf("%c", ciphertext[i]);
            }
            
            // lowercase letters
            if (plaintext[i] >= 97 && plaintext[i] <= 122)
            {
            ciphertext[i] = (plaintext[i] - 96 + k) % 26 + 96;
            printf("%c", ciphertext[i]);
            }
            
            // space
            if (plaintext[i] == ' ')
            {
            printf(" ");
            }
            
            //comma
            if (plaintext[i] == 44)
            {
            printf(",");
            }
            
            //exclamation point
            if (plaintext[i] == 33)
            {
            printf("!");
            }
            
            //period
            if (plaintext[i] == 46)
            {
            printf(".");
            }

        }
        printf("\n");
        return 0;
    }
}