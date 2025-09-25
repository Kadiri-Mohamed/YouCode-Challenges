#include <stdio.h>
int main(void)
{
    char num[8];
    char valid_num[8];

    printf("donner le numero de telephone: ");

    scanf(" %[^\n]", num);

    for (int i = 0; num[i] != '\0'; i++)
    {
        if (num[i] == 'A' || num[i] == 'B' || num[i] == 'C')
        {
            valid_num[i] = '2';
        }
        else if (num[i] == 'D' || num[i] == 'E' || num[i] == 'F')
        {
            valid_num[i] = '3';
        }
        else if (num[i] == 'G' || num[i] == 'H' || num[i] == 'I')
        {
            valid_num[i] = '4';
        }
        else if (num[i] == 'J' || num[i] == 'K' || num[i] == 'L')
        {
            valid_num[i] = '5';
        }
        else if (num[i] == 'M' || num[i] == 'N' || num[i] == 'O')
        {
            valid_num[i] = '6';
        }
        else if (num[i] == 'P' || num[i] == 'R' || num[i] == 'S')
        {
            valid_num[i] = '7';
        }
        else if (num[i] == 'T' || num[i] == 'U' || num[i] == 'V')
        {
            valid_num[i] = '8';
        }
        else if (num[i] == 'W' || num[i] == 'X' || num[i] == 'Y')
        {
            valid_num[i] = '9';
        }else{
            valid_num[i] = num[i];
        }
    }
    printf("%s", valid_num);

    return 0;
}