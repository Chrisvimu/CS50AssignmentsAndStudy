#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(string prompt);
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;
int lookChange(int x);
int greedy(int n, int x);
int m = 0;

//Calculates the minumun ammount of coins to give to the client acording to change.
int main(void)
{
    //Formatś it to int.
    int change = round((100 * (get_positive_float("Change owed?\n"))));
    lookChange(change);
    printf("\n Coins: %i\n", m);
}
//Possitive float verification
float get_positive_float(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);

    }
    while (n < 0);
    return n;
}
//Checks the change and chooses to what operation to make.
int lookChange(int x)
{
    int n;
    while (x > 0)
    {
        if (x >= quarter)
        {
            x = greedy(1, x);

        }
        else if (x >= dime)
        {
            x = greedy(2, x);

        }
        else if (x >= nickel)
        {
            x = greedy(3, x);

        }
        else if (x >= penny)
        {
            x = greedy(4, x);

        }
        else
        {
            return x;
        }
    }
    return x;
}
//Makes operation acording to the coin using a switch idk
int greedy(int n, int x)
{
    int i = 0;
    switch (n)
    {
        case 1:
            i = (x / quarter);
            m = (m + i);
            x = (x - (i * quarter));
            printf("Quarters: %i", i);
            break;

        case 2:
            i = (x / dime);
            m = (m + i);
            x = (x - (i * dime));
            printf("Dime: %i", i);
            break;

        case 3:
            i = (x / nickel);
            m = (m + i);
            x = (x - (i * nickel));
            printf("Nickel: %i", i);
            break;
        case 4:
            i = (x / penny);
            m = (m + i);
            x = (x - (i * penny));
            printf("Penny: %i", i);
            break;
    }
    return x;
    printf("\n");
}
