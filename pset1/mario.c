#import <stdio.h>
#import <cs50.h>

int main (void) {
    
    
    int height;
    
    do 
    {
        printf("Height: ");
        height = GetInt();
    } while(height < 0 || height > 23);
    
    int space = height - 1;
    int row = 0;
    int step = row + 2;
    
    for(row = 0; row < height; row++) 
    {
        for(int x = space; x > 0; x--) 
        {
            printf(" ");
        }
        
        for(int x = 0; x < step; x++)
        {
            printf("#");
        }
        printf("\n");
        space--;
        step++;
        
    }
}
