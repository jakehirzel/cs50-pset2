#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{

    // Collect name in string; create int for length; declare array for initials
    string name = GetString();
    int length = strlen(name);
    char initials[length];
    
    // Initialize initials
    for (int i =0; i < length; i++)
    {
        initials[i] = 0;
    }
    
    // Iterate through name, add first letter and anything after a space to initials
    for (int i = 0, j = 0; i < length; i++)
    {
        if (i == 0)
        {
            initials[j] = name[i];
            j++;
        }
        else if (name[i] == ' ' && i + 1 < length)
        {
            initials[j] = name[i + 1];
            j++;
        }
    }
    
    // Check for lowercase initials and change to uppercase
    for (int i = 0; i < length; i++)
    {
        if (initials[i] >= 97 && initials[i] <= 122)
        {
            initials[i] = initials[i] - 32;
        }
    }
    
    // Print initials
    for (int i = 0; i < length; i++)
    {
        printf("%c", initials[i]);
    }
    printf("\n");
}

