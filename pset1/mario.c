#include <stdio.h>
#include <cs50.h>

void printdash(int n);
void printspace(int n);
void printnewline(void);
        
int main(void)
{
    
    printf("Height: ");
    int height = get_int();
    
    if  (height < 0 || height > 23)
    {
        printf("Retry: ");
        height = get_int();
    }
    else if (height == 0)
    {
        printf("");
    }
    else
    {
        int spacecounter = height - 1;
        int dashcounter = 1;
        for (int row = 0; row < height; row++)
        {
            printspace(spacecounter);
            printdash(dashcounter);
            printspace(2);
            printdash(dashcounter);
            printnewline();
            spacecounter--;
            dashcounter++;
        }
        
    }
    
}




void printdash(int n)
{
    for (int i=0; i<n; i++)
    {
        printf("#");       
    }
}

void printspace(int n)
{
    for (int i=0; i<n; i++)
    {
        printf(" ");       
    }
}

void printnewline(void)
{
        printf("\n");       
}