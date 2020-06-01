#include <cs50.h>
#include <stdio.h>

long get_positive_long(string prompt);
int process(char x);
//Gets an imput and determinates if it correspond to a valid card number.
int main(void)
{
    long imput = (get_positive_long("Card number: \n"));
    char cardNumber[15];
    //convertir a char desde long.
    sprintf(cardNumber, "%li\n", imput);
    printf("tarjetah: %li\n lenght : %s\n", imput, cardNumber);
}

//Gets a positive long number.
long get_positive_long(string prompt)
{
    long x = 0;
    while(x <= 100000000 || x >= 10000000000000000)
    {
        x = get_long("%s", prompt);
    }
    return x;
}
//Gets the subting from the card number
int process(char x)
{
    char = y[10]={0};
    int = l;




}
