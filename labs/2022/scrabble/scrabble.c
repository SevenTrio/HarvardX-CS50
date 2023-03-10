#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int get_letter_point(char letter);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int length = strlen(word);
    int score = 0;

    for (int i = 0; i < length; i++)
    {
        char letter = word[i];
        int point = get_letter_point(letter);
        score += point;
    }

    return score;
}

int get_letter_point(char letter)
{
    int position;

    if (isupper(letter))
    {
        position = (int) letter - 65; // 65 - ASCII code for uppercase "A" char
    }
    else if (islower(letter))
    {
        position = (int) letter - 97;  //97 - ASCII code for lowercase "A" char
    }
    else
    {
        return 0;
    }

    return POINTS[position];
}
