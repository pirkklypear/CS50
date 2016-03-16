#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    float change;
    int remaining;
    
    do
    {
        printf("Oh Hai! How much change is owed? ");
        change = GetFloat();
        remaining = round(change * 100);
    } while (change < 0);
    

    
    int coins = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    
    while(remaining > 0) {
        if (remaining >= 25) 
        {
            coins = remaining / quarter;
            remaining = remaining % quarter;
        }
        if (remaining >= dime && remaining < quarter) 
        {
            coins = coins + (remaining / dime);
            remaining = remaining % dime;
        }
        if (remaining >= nickel && remaining < dime) 
        {
            coins = coins + (remaining / nickel);
            remaining = remaining % nickel;
        }
        if (remaining >= penny && remaining < nickel) 
        {
            coins = coins + (remaining / penny);
            remaining = remaining % penny;
        }
    }
    
    printf("%i", coins);
    printf("\n");
    
}