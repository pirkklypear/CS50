/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512

int main(int argc, char* argv[])
{
    //init variables
    
    int counter = 0;
    typedef uint8_t BYTE;
    BYTE buffer[BLOCKSIZE];
    bool imgFound = true;
    //char* infile = "card.raw";
    
    //open the memory card and read
    
    FILE* inptr = fopen("card.raw", "r");
    FILE* img = NULL;
    
    // Check that file opened
    if (inptr == NULL)
    {
        return 2;
    }
    
    // Read BLOCKSIZEbyte block from loaded file
    
    
    // Run until end of file card.raw
    while (imgFound)
    {
        for (int i = 0; i < BLOCKSIZE; i++)
        {
            if (feof(inptr))
            {
                fclose(inptr);
                
                if(img != NULL)
                {
                    fclose(img);
                }
                
                imgFound = false;
                return 0;
            }
            
            fread(&buffer[i], sizeof(BYTE), 1, inptr);
        }
        // Check for 1101 sequence of jpeg   
        if  (buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff)
        {
            if (img != NULL) 
            {
                fclose(img);
            }
            
            // Create file name from file discovery counter
            char title[50];
            sprintf(title, "%.3i.jpg", counter);
            counter++;
                
            // Use file name to create file and write
            img = fopen(title, "w");
            fwrite(&buffer[0], BLOCKSIZE * sizeof(BYTE), 1, img);
        }
        else if (img != NULL) 
        {
            fwrite(&buffer[0], BLOCKSIZE * sizeof(BYTE), 1, img);
        }
    } 
}

