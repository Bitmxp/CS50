#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//string error(int argc, string argv, int len);

int main(int argc, string argv[])
{
    int search(char query);
    int duplicate(string input, int inputlen);
    // ------------- ERROR HANDLING -------------
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string text = argv[1];
    int len = strlen(text);

    for (int x = 0; x < len; x++)
    {
        if isalpha(text[x])
        {
            continue;
        }
        else
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
    }
    if (len != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    //------------- MAIN SEGMENT -------------
    if (duplicate(text, len))
    {
        printf("No duplicates in key!\n");
        return 1;
    }
    string input = get_string("plaintext: ");
    int inputlen = strlen(input);
    //Convert Key to Uppercase
    //string key = "";
    //for (int t = 0; t < 26; t++)
    //{
    //key = key + toupper(text[t]);
    //}

    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int uni[26];
    len = strlen(input);
    //cipher = ""
    for (int x = 0; x < 26; x++)
    {
        int diff = abc[x] - toupper(text[x]);
        uni[x] = diff;
        //printf("%i\n", diff);
    }
    int ind = 0;
    char out;
    printf("ciphertext: ");
    for (int y = 0; y < len; y++)
    {
        if (isalpha(input[y]))
        {
            ind = search(input[y]);
            out = input[y] - uni[ind];
            printf("%c", out);
        }
        else
        {
            printf("%c", input[y]);
        }

    }
    printf("\n");
    //printf("ciphertext: %s", out);
    //for(int l = 0; l < len; l++)
    //{
    //    cipher = cipher + len
    //}

}

int search(char query)
{
    query = tolower(query);
    char alpha[26];
    string abc = "abcdefghijklmnopqrstuvwxyz";
    int n;
    for (n = 0; n < 26; n++)
    {
        if (query == abc[n])
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return n;
}

int duplicate(string input, int inputlen)
{
    int i, j;
    for (i = 0; i < inputlen - 1; i++)
    {
        for (j = i + 1; j < inputlen - 1; j++)
        {
            if (input[j] == input[i])
            {
                return 1;
            }
        }
    }
    return 0;
}
/*string error(int argc, string argv, int len)
{
    string error = "0";
    if (argc != 2)
    {
        error = "Usage: ./substitution key\n";
        return error;
    }
    else if (len != 26)
    {
        error = "Key must contain 26 characters\n";
        return error;
    }
    for (int x = 0; x < len; x++)
    {
        if isalpha(argv[x])
        {
            continue;
        }
        else
        {
            error = "Key must only contain alphabetic characters\n";
            return error;
        }
    }
    return "";
}*/