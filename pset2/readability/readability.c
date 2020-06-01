//imports
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Variables
int txt_sentences;
int txt_words = 1;
int txt_letters;
//functions
float text_processing(string x);
void process_text(string x, int l);
float index_calculator();
void grade_it(float x);

//Takes a text input and grades it acording to the Coleman-Liau index.
int main(void)
{
    string text = get_string("Text: \n"); //The string can cast a char using string_name[]
    float index = text_processing(text);
    grade_it(index);
    return 0;
}
//Process the text and returns the dificulty.
float text_processing(string x)
{
    int txt_lenght = strlen(x);
    process_text(x, txt_lenght); //process the text as an array for the diferent criteria of the index.
    float index = index_calculator(); //Process the grade.
    return index;
}
//Registers letters, sencences and words.
void process_text(string x, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (x[i] == '.' || x[i] == '!' || x[i] == '?') //counts sentences in the test.
        {
            txt_sentences++;
        }
        else if (isspace(x[i])) //countes words in the text.
        {
            txt_words++;
        }
        else if (isalpha(x[i])) //counts letters in the text.
        {
            txt_letters++;
        }
    }
}
//Calculate index.
float index_calculator()
{
    float index = (0.0588 * (100 * (float) txt_letters / (float) txt_words) - 0.296 * (100 * (float) txt_sentences /
                   (float) txt_words) - 15.8);
    return index;
}
//Prints its grade acording to the requisite
void grade_it(float x)
{
    if (x < 16 && x >= 0)
    {
        printf("Grade %i\n", (int) round(x));
    }
    else if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}