
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Declaration of functions
int key_processing(string x, int key);

//Encrypt or decrypt code based on args, must be 2.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int i, o; //Lenght of the second arg or "key"
        //loop for the lenght of the second arg
        for (i = 0, o = strlen(argv[1]); i < o; i++)
        {
            if (!isdigit(argv[1][i])) //checks if it's a digit to continue, for handling of non-numerics.
            {
                printf("Error. 'Second argument incorrect'\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);
        string text = get_string("plaintext: \n"); //The string can cast a char using string_name[]
        key_processing(text, key);
        return 0;
    }
    else
    {
        printf("Error: 'incorrect command line format'\n");
        return 1;
    }
}

//takes the user input and check what is the ANCII code for the character,  and aplies the key.
int key_processing(string x, int key)
{
    int text_Lenght = strlen(x);
    string cipher = x;

    for (int i  = 0; i < text_Lenght; i++)
    {
        //For uppercase
        if (cipher[i] >= 65 && cipher[i] <= 90)
        {
            cipher[i] = (cipher[i] - 65 + key) % 26 + 65;
        }
        //For lowecase
        if (cipher[i] >= 97 && cipher[i] <= 122)
        {
            cipher[i] = (cipher[i] - 97 + key) % 26 + 97;
        }
        //Other characters left untouched
        else
        {
            cipher[i] = x[i];
        }
    }

    printf("ciphertext: %s\n", cipher);
    return 0;
}
