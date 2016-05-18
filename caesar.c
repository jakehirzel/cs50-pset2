#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // Verify exactly two args
    if (argc < 2 || argc > 2)
    {
        printf("Hey! This program takes just one additional arg!\n");
        return 1;
    }

    // Make sure argv[1] is all numbers
    string test = argv[1];
    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
        if (isalpha(test[i]))
        {
            printf("Hey! Only non-negative ints as extra args!\n");
            return 1;
        }
    }
    
    // Make argv[1] into an int k
    int k = atoi(argv[1]);
    
    // Make sure k is non-negative
    if (k < 0)
    {
        printf("Hey! Only non-negative ints as extra args!\n");
        return 1;
    }
    
    // Prompt the user for string of plain text
    string ptext = GetString();

    // Output plaintext as cyphertext rotated by k postions
    for (int i = 0, j = strlen(ptext); i < j; i++)
    {
        // If capital letters
        if (ptext[i] > 64 && ptext[i] < 91)
        {
            printf("%c", (ptext[i] - 65 + k) % 26 + 65);
        }
        // Else if lowercase letters
        else if (ptext[i] > 96 && ptext[i] < 123)
        {
            printf("%c", (ptext[i] - 97 + k) % 26 + 97);
        }
        // Else everything else
        else
        {
            printf("%c", ptext[i]);
        }
    }
    printf("\n");
    
    // Exit and return 0;
    return 0;
}
