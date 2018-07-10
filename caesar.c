// accept a key as an argument and encrypt a plaintext input,
// then output cyphertext

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // assign key from arguments passed at command line
    int key;
    if (argc == 2)
    {
        key = (int) atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar k)\n");
        return 1;
    }

    // reduce key to value between 0 and 26
    key = key % 26;

    // get plaintext from user
    string plaintext = get_string("plaintext: ");

    // declare cyphertext as plaintext for string length
    string cyphertext = plaintext;

    // loop through plaintext by letter
    for (int x = 0, n = strlen(plaintext); x < n; x++)
    {
        // declare letDex to hold ascii value of letter
        int letDex = (int) plaintext[x];

        // declare cryptDex to store num value of shifted letter
        int cryptDex;

        // if lowercase letter, adjust from 'a'
        if (plaintext[x] >= 'a' && plaintext[x] <= 'z') {
            cryptDex = (((letDex + key) - (int) 'a') % 26) + (int) 'a';
        }
        // if uppercase letter, adjust from 'A'
        else if (plaintext[x] >= 'A' && plaintext[x] <= 'Z')
        {
            cryptDex = (((letDex + key) - (int) 'A') % 26) + (int) 'A';
        }
        else
        {
            cryptDex = (int) letDex;
        }
        // add encrypted letter to cyphertext
        cyphertext[x] = (char) cryptDex;
    }

    printf("cyphertext: %s\n", cyphertext);

    return 0;
}
