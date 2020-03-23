#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //making sure the program knows the integer exists
    int h = 0;
    do
    {
        h = get_int("Height: ");
        if (h > 8)
        {
            //So that the program will reject it and start over
            h = -1;
        }
        for (int counter = 1; counter <= h; counter++)
        {
            for (int c = 1; c <= h - counter; c++)
            {
                //Adds the amount of spaces
                printf(" ");
            }
            for (int x = 1; x <= counter; x++)
            {
                //addss the hashes
                printf("#");
            }
            printf("  ");
            //Adds spaces AGAIN
            for (int x = 1; x <= counter; x++)
            {
                printf("#");
            }
            printf("\n");
        }
    } 
    //will continue the loop
    while (h <= 0);
}
