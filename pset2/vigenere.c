#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    do 
    {
        printf("What message do you want to encrypt? \n");
    } while (argc != 2);

    for(int y = 0, keyphrase = strlen(argv[1]); y < keyphrase; y++)
    {
        if (isdigit(argv[1][y]))
        {
        printf("No digit \n");
        return 1;
            }
        }
        string k = argv[1];
        int klength = strlen(k);
        string p = "";
        p = GetString();
        
        
        
        for (int x = 0; x < klength; x++)
        {
            if (isupper(k[x])) 
            {
                k[x] = k[x] - 65;
            } else if(islower(k[x]))
            {
                k[x] = k[x] - 97;
            }
        }
        
        
        for(int i = 0, j = 0; i < strlen(p); i++)
        {
            if (isalpha(p[i]))
            {
                if (islower(p[i])) 
                {
                    p[i] = ((p[i] - 97) + k[j]) % 26 + 97;
                    // name[letter] = (name[letter] - 97 + k) % 26 + 97;
                    // copy and adapt cipher from working
                } 
                else if (isupper(p[i])) 
                {
                    p[i] = ((p[i] - 65) + k[j]) % 26 + 65;
                }
                j++;
                
                if (j == klength)
                {
                    j = 0;
                }
            }
        }
        printf("%s", p);
        printf("\n");
        return 0;
    
}

