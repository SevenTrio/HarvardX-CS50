#include <cs50.h>
#include <stdio.h>
#include <math.h>

int getDigit(long number, int position);
int getChecksum(long card_number, int length);
int isValidCreditCard(long card_number, int length);

int main(void)
{
    long card_number = get_long("Number: ");
    int length = card_number < 10 ? 1 : ceil(log10(card_number));

    int firstNumber = card_number / pow(10, length - 1);
    int firstTwoNumbers = card_number / pow(10, length - 2);

    int isValid = isValidCreditCard(card_number, length);
    if (!isValid)
    {
        printf("INVALID\n");
        return 0;
    }

    if (firstNumber == 4)
    {
        printf("VISA\n");
    }
    else if (firstTwoNumbers == 34 || firstTwoNumbers == 37)
    {
        printf("AMEX\n");
    }
    else if (firstTwoNumbers >= 51 && firstTwoNumbers <= 55)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int getDigit(long number, int position)
{
    long divider = pow(10, position);
    long remainder = number % divider;
    int digit = remainder / pow(10, position - 1);

    return digit;
}

int getChecksum(long card_number, int length)
{
    int multipliedSum = 0;
    for (int i = 2; i <= length; i = i + 2)
    {
        printf("i: %i\n", i);
        int digit = getDigit(card_number, i);
        int multipliedDigit = digit * 2;
        if (multipliedDigit > 9)
        {
            multipliedSum += getDigit(multipliedDigit, 1);
            multipliedSum += getDigit(multipliedDigit, 2);
        }
        else
        {
            multipliedSum += multipliedDigit;
        }
    }

    int regularSum = 0;
    for (int i = 1; i <= length; i = i + 2)
    {
        int digit = getDigit(card_number, i);
        regularSum += digit;
    }

    return multipliedSum + regularSum;
}

int isValidCreditCard(long card_number, int length)
{
    if (length < 13 || length > 16)
    {
        return 0;
    }

    int checksum = getChecksum(card_number, length);

    return checksum % 10 == 0;
}
