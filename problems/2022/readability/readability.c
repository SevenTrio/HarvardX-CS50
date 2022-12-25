#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int text_length = strlen(text);

    int letters_count = 0;
    int words_count = 0;
    int sentences_count = 0;

    for (int i = 0; i < text_length; i++)
    {
        char current_char = text[i];

        if (islower(current_char) || isupper(current_char))
        {
            letters_count++;
        }
        else if (current_char == ' ')
        {
            words_count++;
        }
        else if (current_char == '.' || current_char == '!' || current_char == '?')
        {
            sentences_count++;
        }
    }

    // Count last word in the text
    words_count++;

    // L is the average number of letters per 100 words in the text
    float L = (float) letters_count / words_count * 100;

    // S is the average number of sentences per 100 words in the text
    float S = (float) sentences_count / words_count * 100;

    // The Coleman-Liau index formula: index = 0.0588 * L - 0.296 * S - 15.8
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
