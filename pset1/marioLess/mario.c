#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
void draw_it(int x);
void space_it(int x);

//main program, ask for height
int main(void)
{
    int height = get_positive_int("How high you want Mario to jump?");
    draw_it(height);
}

//Ask for a valid int above 0 and velow 9
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}

//Draws # n times for acording to the floor number
void draw_it(int x)
{

    for (int i = 0; i <= x; i++)
    {
        int h = (x - i);

        //Only when the number is above 0
        if (i > 0)
        {
            space_it(h);
        }
        for (int j = 0; j < i; j++)
        {

            printf("#");
        }

        //Only when the number is above 0
        if (i > 0)
        {
            printf("\n");
        }
    }
}


//Print spaces n times
void space_it(int x)
{
    for (int s = 0; s < x; s++)
    {
        printf(" ");
    }
}