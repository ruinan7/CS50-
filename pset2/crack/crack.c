#define _XOPEN_SOURCE
#include <unistd.h>
# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int cryptpw(string pwletter, string salt, string realhash);

int main (int argc, string argv[])
{
    // produce a hint if you don't have a hash or have more than one hash.
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    else
    {
        string realhash = argv[1];
        //get salt from user's hash
        char salt[3];
        sprintf(salt, "%c%c", argv[1][0], argv[1][1]);
        //printf("salt is %s\n", salt);

        // Generate a one digit key
        char pw[20];
        
        //one digit A-Z
        for (char pw1A = 'A'; pw1A <= 'Z'; pw1A++)
        {

            sprintf(pw, "%c%c", pw1A, '\0');
            //printf("%s\n",pw);
            
            int decision = cryptpw(pw, salt, realhash);
            if (decision == 0)
            {
                printf("%s", pw);
                exit(0);
            }
        }
            
        //one digit a-z
        for (char pw1a = 'a'; pw1a <= 'z'; pw1a++)
        {

            sprintf(pw, "%c%c", pw1a, '\0');
            //printf("%s\n",pw);
            
            int decision = cryptpw(pw, salt, realhash);
            if (decision == 0)
            {
                printf("%s", pw);
                exit(0);
            }
        }

        //two digit A-Z
        for (char pw2A = 'A'; pw2A <= 'Z'; pw2A++)
        {
            for(char pw22A = 'A'; pw22A <= 'Z'; pw22A++)
            {
                sprintf(pw, "%c%c%c", pw2A, pw22A, '\0');
                //printf("%s\n",pw);
                
                int decision = cryptpw(pw, salt, realhash);
                if (decision == 0)
                {
                    printf("%s", pw);
                    exit(0);
                }
            }
        }
        
        //two digit a-z
        for (char pw2a = 'a'; pw2a <= 'z'; pw2a++)
        {
            for(char pw22a = 'a'; pw22a <= 'z'; pw22a++)
            {
                sprintf(pw, "%c%c%c", pw2a, pw22a, '\0');
                //printf("%s\n",pw);
                
                int decision = cryptpw(pw, salt, realhash);
                if (decision == 0)
                {
                    printf("%s", pw);
                    exit(0);
                }
            }
        }        

        //three digit A-Z
        for (char pw3A = 'A'; pw3A <= 'Z'; pw3A++)
        {
            for (char pw33A = 'A'; pw33A <= 'Z'; pw33A++)
            {
                for (char pw333A = 'A'; pw333A <= 'Z'; pw333A++)
                    {
                
                        sprintf(pw, "%c%c%c%c", pw3A, pw33A, pw333A, '\0');
                        //printf("%s\n",pw);
                        
                        int decision = cryptpw(pw, salt, realhash);
                        if (decision == 0)
                        {
                            printf("%s", pw);
                            exit(0);
                        }
                    }
            }
        }         
        
         //three digit a-z
        for (char pw3a = 'a'; pw3a <= 'z'; pw3a++)
        {
            for (char pw33a = 'a'; pw33a <= 'z'; pw33a++)
            {
                for (char pw333a = 'a'; pw333a <= 'z'; pw333a++)
                    {
                
                        sprintf(pw, "%c%c%c%c", pw3a, pw33a, pw333a, '\0');
                        //printf("%s\n",pw);
                        
                        int decision = cryptpw(pw, salt, realhash);
                        if (decision == 0)
                        {
                            printf("%s", pw);
                            exit(0);
                        }
                    }
            }
        }      
        
        //four digit A-Z
        for (char pw4A = 'A'; pw4A <= 'Z'; pw4A++)
        {
            for (char pw44A = 'A'; pw44A <= 'Z'; pw44A++)
            {
                for (char pw444A = 'A'; pw444A <= 'Z'; pw444A++)
                    {
                        for (char pw4444A = 'A'; pw4444A <= 'Z'; pw4444A++)
                        {
                            sprintf(pw, "%c%c%c%c%c", pw4A, pw44A, pw444A, pw4444A, '\0');
                            //printf("%s\n",pw);
                            
                            int decision = cryptpw(pw, salt, realhash);
                            if (decision == 0)
                            {
                                printf("%s", pw);
                                exit(0);
                            }
                        }
                    }
            }
        }        

        //four digit a-z
        for (char pw4a = 'a'; pw4a <= 'z'; pw4a++)
        {
            for (char pw44a = 'a'; pw44a <= 'z'; pw44a++)
            {
                for (char pw444a = 'a'; pw444a <= 'z'; pw444a++)
                    {
                        for (char pw4444a = 'a'; pw4444a <= 'z'; pw4444a++)
                        {
                            sprintf(pw, "%c%c%c%c%c", pw4a, pw44a, pw444a, pw4444a, '\0');
                            //printf("%s\n",pw);
                            
                            int decision = cryptpw(pw, salt, realhash);
                            if (decision == 0)
                            {
                                printf("%s", pw);
                                exit(0);
                            }
                        }
                    }
            }
        }        


        
            
        return 0;

    }
    
}


int cryptpw(string pwletter, string salt, string realhash)
{
    //use key to crate our hash
    string hash = crypt(pwletter, salt);
    //printf("%s\n", hash);

    //compare our hash to real hash
    if (strcmp(hash, realhash) == 0)
    {
        //printf("correct!\n");
        return 0;
    }
    else
    {
        //printf("wrong\n");
        return 1;
    }       
}