#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int testKey(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z')))
        {
            return 1;
        }
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (testKey(argv[1]))
    {
        printf("Key characters must be unique.\n");
        return 1;
    }


    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext) + 1];
    strcpy(ciphertext, plaintext);


    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if(islower(plaintext[i]))
            {
                ciphertext[i] = tolower(argv[1][plaintext[i] - 'a']);
            }
            else
            {
                ciphertext[i] = toupper(argv[1][plaintext[i] - 'A']);
            }
        }
        else 
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[strlen(plaintext)] = '\0';
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
