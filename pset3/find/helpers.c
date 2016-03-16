/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n) // binary search = needle, stack, size
{
    int min = 0;
    int max = n;
    int midpoint = max / 2;

    if(max < min || n == 0) 
    {
        return false;
    }
    
    while (min <= max) 
    {
        if (values[midpoint] == value)
        {
            return true;
            break;
        }
        else if (values[midpoint] > value)
        {
            max = midpoint - 1;
            midpoint = ((max - min) / 2) + min;
        }
        else if (values[midpoint] < value)
        {
            min = midpoint + 1;
            midpoint = ((max - min) / 2) + min;
        }
    }
    return false;
    

        
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    for(int m = 0; m < n; m++)
    {
        for (int i = 0, j = 1; i < n; i++, j++)
        {
            int x = values[i];
            int y = values[j];
            if (x > y) 
            {
                values[i] = y;
                values[j] = x;
            }
        }
    }

    return;
}
