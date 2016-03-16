#include <stdio.h>
#include <cs50.h>

int main(void) {
    int minutes = 0;
    
    do 
    {
        printf("How many minutes was your shower?");
        minutes = GetInt();
    }
    while (minutes < 1);
    int bottles = minutes * 12;
    
    printf("minutes: %i \n", minutes);
    printf("bottles: %i \n", bottles);
    
    
}