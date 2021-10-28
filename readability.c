// Implement a program that computes the approximate grade level needed to comprehend some text

#import <stdio.h>
#import <ctype.h>
#import <math.h>
#import <cs50.h>

int count_l(string letters); //identifying user created functions in the program
int count_w(string letters);
int count_s(string letters);
double index(int letters, int words, int sent);
string gradeLevel(double index);

int main(void) //the main program
{
    string text = get_string("Text: ");

    int charCount = count_l(text);
    int wordCount = count_w(text);
    int sentCount = count_s(text);
    printf("%d letter(s)\n%d word(s)\n%d sentence(s)\n", charCount, wordCount, sentCount);

    double i = round(index(charCount, wordCount, sentCount));

    string grade = gradeLevel(i);
    printf("%s\n", grade);
}

int count_l(string letters) //counts the letters of the input string
{
    int allCount = 0;
    int spCount = 0;
    for (int i = 0; letters[i]; i++)
    {
        if (ispunct(letters[i]) || isspace(letters[i]))
        {
            spCount++;
        }
        allCount++;
    }
    int charCount = allCount - spCount;
    return charCount;
}

int count_w(string words) //counts the words
{
    int wordCount = 1;
    for (int i = 0; words[i] != '\0'; i++)
    {
        if (isblank(words[i]) || words[i] == '\n')
        {
            wordCount++;
        }
    }
    return wordCount;
}

int count_s(string sentence) //counts the senetences
{
    int sentCount = 0;
    for (int i = 0; sentence[i]; i++)
    {
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentCount++;
        }
    }
    return sentCount;
}

double index(int letters, int words, int sent) //the coleman-liau index equation
{
    double L = ((double) letters / words) * 100;
    double S = ((double) sent / words) * 100;

    double i = (0.0588 * L) - (0.296 * S) - 15.8;

    return i;
}

string gradeLevel(double index) //if-else statement to determine the grade level from the coleman-liau index
{
    string statement = "";
    if (index < 0)
    {
        statement = "Before Grade 1";
    }
    else
    {
        if (index == 1)
        {
            statement = "Grade 1";
        }
        else if (index == 2)
        {
            statement = "Grade 2";
        }
        else if (index == 3)
        {
            statement = "Grade 3";
        }
        else if (index == 4)
        {
            statement = "Grade 4";
        }
        else if (index == 5)
        {
            statement = "Grade 5";
        }
        else if (index == 6)
        {
            statement = "Grade 6";
        }
        else if (index == 7)
        {
            statement = "Grade 7";
        }
        else if (index == 8)
        {
            statement = "Grade 8";
        }
        else if (index == 9)
        {
            statement = "Grade 9";
        }
        else if (index == 10)
        {
            statement = "Grade 10";
        }
        else if (index == 11)
        {
            statement = "Grade 11";
        }
        else if (index == 12)
        {
            statement = "Grade 12";
        }
        else if (index == 13)
        {
            statement = "Grade 13";
        }
        else if (index == 14)
        {
            statement = "Grade 14";
        }
        else if (index == 15)
        {
            statement = "Grade 15";
        }
        else if (index == 16)
        {
            statement = "Grade 16";
        }
        else if (index > 16)
        {
            statement = "Grade 16+";
        }
    }
    return statement;
}