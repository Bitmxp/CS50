#include <stdio.h>
#include <cs50.h>
//Math Header for Exponents
#include <math.h>


int main(void)
{
    //DECLARING VARIABLES AND COPYING THE CREDIT NUMBER FOR DIFFERENT PURPOUSES
    long int c = 0;
    //COPYING HERE
    c = get_long("Number: ");
    long int cc = c;
    long int ccc = cc;
    //Pre-Declaring Variables
    int score1 = 0;
    int score2 = 0;
    int temp1 = 0;
    int temp2 = 0;
    int counter = 0;
    int cd;
    //Counting Variables
    for (cd = 0; ccc > 0; cd++)
    {
        ccc /= 10;
    }
    //Starting the Validation Prompt
    for (counter = 0; counter <= cd; counter++)
    {
        //For Even numbered Digits
        if (counter % 2 == 0)
        {
            //TODO: Make Counter Algorithm for other few digits
            score2 += cc % 10;
            cc /= 10;
        }
        //This is for the ODD numbered digits
        else
        {
            //Temporary Value holder!
            temp1 = cc % 10;
            temp1 = cc % 10 * 2;
            while (temp1)
            {
                score1 += temp1 % 10;
                temp1 /= 10;
            }
            cc /= 10;
        }
    }
    //Adds the two scores for final result of the validation algorithm
    temp2 = score1 + score2;
    if (temp2 % 10 == 0)
    {
        //CHECK THE TYPE AND LENGTH OF CARD
        if (cd == 16)
        {
            //Get the last X digits by dividing by 10^X
            if (c / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else if (c / 100000000000000 >= 51 && c / 100000000000000 <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (cd == 15)
        {
            if (c / 10000000000000 == 34 || c / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (cd == 13)
        {
            if (c / pow(10, 15) == 4)
            {
                printf("VISA\n");
            } 
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }   
    }
    else
    {
        printf("INVALID\n");
    }
}
