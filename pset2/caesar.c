#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    if(argc != 2) 
    {
        printf("%i \n", argc);
        printf("Invalid arguments.\n");
        return 1;
        
    } 
    else 
    {
        int k = atoi(argv[1]); //convert key from string to int
        string name = GetString();
        
        for(int letter = 0; letter < strlen(name); letter++) 
        {
            if(isalpha(name[letter])) 
            {
                if(islower(name[letter])) 
                {
                    name[letter] = (name[letter] - 97 + k) % 26 + 97;
                }
                if(isupper(name[letter]))
                {
                    name[letter] = (name[letter] - 65 + k) % 26 + 65;
                }
            }
        }
        printf("%s", name);
        printf("\n");
        return 0;
    }
    
}

