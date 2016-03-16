#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, char* argv[])
{
    string name = GetString();
     
    if (name != NULL)
    {  
        // capitalise name
        for(int i = 0, n = strlen(name); i < n; i++) 
        {
            name[i] = toupper(name[i]);          
        }
        // obtain first initial
        printf("%c", name[0]); 
         
        // loop through name
        for(int i = 0, y = 0, n = strlen(name); i < n; i++) 
        {
             
            // find spaces and locate initial
            if (name[i] == ' ' && y == 0) 
            {
                // go to next char for initial
                i++;
                printf("%c", name[i]);
                y++;
               
            }
            // find initial of 3rd name
            else if (name[i] == ' ' && y == 1) 
            {
                i++;
                printf("%c", name[i]);
            }
        }
        printf("\n"); 
    }
 
 
}