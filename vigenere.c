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

    // Make sure argv[1] is all letters
    string test = argv[1];
    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
        if (isdigit(test[i]) || ispunct(test[i]))
        {
            printf("Hey! Only use letters in the extra arg!\n");
            return 1;
        }
    }

    // Make argv[1] into a string called key; get key length; make keynum array for numerical key
    string key = argv[1];
    int keylen = strlen(key);
    int keynum[keylen];

    // Make each letter of key (regardless of case) into an int and assign to zero indexed keynum array
    for (int i = 0; i < keylen; i++)
    {
        // If capital letters
        if (key[i] > 64 && key[i] < 91)
        {
            keynum[i] = (int)key[i] - 65;
        }
        // Else if lowercase letters
        else if (key[i] > 96 && key[i] < 123)
        {
            keynum[i] = (int)key[i] - 97;
        }
    }

    // Prompt the user for string of plain text to encrypt
    string ptext = GetString();

    // Output plaintext as cyphertext with each letter rotated by sequential keynum[i] postions
    
    // Loop through letters of ptext
    for (int i = 0, j = strlen(ptext), k = 0; i < j; i++)
    {
        // Do Caesar's cypher on each letter rotated by keynum[i]
        // If capital letters; increment k
        if (ptext[i] > 64 && ptext[i] < 91)
        {
            printf("%c", (ptext[i] - 65 + keynum[k % keylen]) % 26 + 65);
            k++;
        }
        // Else if lowercase letters; increment k
        else if (ptext[i] > 96 && ptext[i] < 123)
        {
            printf("%c", (ptext[i] - 97 + keynum[k % keylen]) % 26 + 97);
            k++;
        }
        // Else everything else; do not increment k
        else
        {
            printf("%c", ptext[i]);
        }
    }
    
    printf("\n");
    
    // Exit and return 0;
    return 0;
}
