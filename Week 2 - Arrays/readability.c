#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

//calling functions
int space(string text, int len);
int letter(string text, int letters);
int sentence(string text, int len);

int main(void)
{
    //gets input from user
    string text = get_string("Text: ");
    int len = strlen(text);
    int words = space(text, len) + 1;
    int letters = letter(text, len);
    int sentences = sentence(text, len);
    //printf("Letters: %i\n", letters);
    //printf("Words: %i\n", words);
    //printf("Sentences: %i\n", sentences);

    if(words <= 100)
    {
        //You need to use more siginificant digits!
        float l = letters*100.00/words;
        float s = sentences*100.00/words;
        float index = 0.0588 * l - 0.296 * s - 15.8;
        //If Grade is less than 1
        if(index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if(index > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            int b = round(index);
            printf("Grade %i\n", b);
        }

    }
    //Not completed, because I am assuming the words are less than 100.
    if(words >= 100)
    {
        //Do this
    }
}




//Find letters by iterating over the text and adding to a counter if it is part of the alphabet
int letter(string text, int len)
{
    int count = 0;
    for (int c = 0; c < len; c++)
    {
        if(isalpha(text[c]))
        {
            count++;
        }
    }
    return count;
}

//Find sentences using the same method as above.
int sentence(string text, int len)
{
    int count = 0;
    for (int c = 0; c < len; c++)
    {
        if(text[c] == '!' || text[c] == '.' || text[c] == '?')
        {
            count++;
        }
    }
    return count;
}

//Find whitespace similar to above, however with whitespace.
int space(string text, int len)
{
    int count = 0;
    for (int c = 0; c < len; c++)
    {
        if(isspace(text[c]))
        {
            count++;
        }
    }
    return count;
}