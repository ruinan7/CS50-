/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

#include "helpers.h"

int middle(int b, int e);
int recursion(int b, int m, int e, int va[], int v);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
//implementing binary search
int begin = 0;
int mid;
int end = n - 1;


        while (n > 0)
        {
            
            mid = values[middle(begin, end)]; 

            if (mid == value || values[end] == value)
            {
                printf("Found needle in haystack!\n");
                exit(0);                
            }
            else if (recursion(begin, middle(begin, end), end, values, value) == true)
            {
                printf("Found needle in haystack!\n");
                exit(0);
            }
            else 
            {
                printf("Didn't find needle in haystack.\n");
                exit(1);
            }
        }
        return false;

    
}

/**
 * Sorts array of n values.
 */
//Bubble Sort
void sort(int values[], int n)
{
int left;
int right;
int holder;
int counter = n;
    do
    {
        for (left = 0; left <= (n - 2); left++)
        {
            right = left + 1;
            if (values[left] > values[right])
            {
               holder = values[right];
               values[right] = values[left];
               values[left] = holder;
            }
        }
        counter = counter - 1;
    }
    while (counter >= 0);
    //printf("%i %i %i %i\n", values[0], values[1], values[2], values[3]);

}








int middle(int b, int e)
{

    if ( e % 2 == 0)
    {
        //printf("b is %i\n", b);
        //printf("e is %i\n", e);
        return (b + e) / 2;
    }
    else
    {
        return (b + e - 1) / 2;
    }    
}

int recursion(int b, int m, int e, int va[], int v)
{
    if (v < va[m])
    {

        e = m - 1;
        m = va[middle(b, e)];
        if (m == v)
        {
            return true;
        }
        else if (b > m || m > e)
        {
            return false;
        }
        else
        {
            return recursion(b, m, e, va, v);
        }
        
    }
    else if (v > va[m])
    {

        b = m + 1;
        m = middle (b, e);

        if (va[m] == v)
        {
            return true;
        }
        else if (b > m || m > e)
        {
            return false;            
        }
        else 
        {
            return recursion(b, m, e, va, v);
        }
    }
    else
    {
        return true;
    }    
}