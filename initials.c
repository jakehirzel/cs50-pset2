#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{

    // Collect name in string; create int for length
    string name = GetString();
    int length = strlen(name);

    // Make name uppercase
    for (int i = 0; i < length; i++)
    {
        if (name[i] >= 97 && name[i] <= 122)
        {
            name[i] = name[i] - 32;
        }
    }
    
    // Print initials from name
    for (int i=0; i < length; i++)
    {
        if (i == 0)
        {
            printf("%c", name[i]);
        }
        else if (name[i] == ' ' && i + 1 < length)
        {
            printf("%c",name[i + 1]);
        }
    }
    printf("\n");
}

