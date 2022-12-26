#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string ERROR_MESSAGES[] =
{
    "Everything is fine!",
    "Usage: ./substitution key",
    "Key must contain 26 characters.",
    "Key must contain only alphabetic characters.",
    "Key must contain each letter exactly once."
};

void exit_with_error(int error_code);
int check_key(string key, int key_length);

int main(int argc, string argv[])
{
    int error_code = 0;

    if (argc != 2)
    {
        error_code = 1;
        exit_with_error(error_code);
    }

    string key = argv[1];
    int key_length = strlen(key);

    error_code = check_key(key, key_length);
    if (error_code != 0)
    {
        exit_with_error(error_code);
    }

    string lowercase_key = key;
    for (int i = 0; i < key_length; i++)
    {
        lowercase_key[i] = tolower(lowercase_key[i]);
    }

    string plaintext = get_string("plaintext:  ");
    int text_length = strlen(plaintext);

    string ciphertext = (char *) malloc((text_length + 1) * sizeof(char));
    for (int i = 0; i < text_length; i++)
    {
        char plainchar = plaintext[i];
        char cipherchar;

        if (islower(plainchar))
        {
            int position = (int) plainchar - 97; // 97 - ASCII code for lowercase "A" char
            cipherchar = key[position];
        }
        else if (isupper(plainchar))
        {
            int position = (int) plainchar - 65; // 65 - ASCII code for uppercase "A" char
            cipherchar = toupper(key[position]);
        }
        else
        {
            cipherchar = plainchar;
        }

        ciphertext[i] = cipherchar;
    }

    printf("ciphertext: %s\n", ciphertext);
}

void exit_with_error(int error_code)
{
    printf("%s\n", ERROR_MESSAGES[error_code]);
    exit(1);
}

int check_key(string key, int key_length)
{
    if (key_length != 26)
    {
        return 2;
    }

    string duplicates = (char *) malloc((key_length + 1) * sizeof(char));

    for (int i = 0; i < key_length; i++)
    {
        char ch = key[i];
        if (!isalpha(ch))
        {
            return 3;
        }

        char lowercase_ch = tolower(ch);
        if (strchr(duplicates, lowercase_ch) != NULL)
        {
            return 4;
        }

        strncat(duplicates, &lowercase_ch, 1);
    }

    return 0;
}
