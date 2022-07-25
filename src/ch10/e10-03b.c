/* Exercise 03b from chapter 10.
 * Modify Program 10.8 the countWords funtion to count the apostrophe as part
 * of a word. Also, extend the function to count a sequence of positive or
 * negative numbers, including any embedded commas and periods, as a single
 * word.
 */

#include <stdio.h>
#include <stdbool.h>

bool is_alphabetic(const char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c >= '\'';
}

// Function to read a line of text from the terminal

bool is_number(const char c)
{
    return c >= '0' && c <= '9'
            || c == '+' || c == '-' || c == ',' || c == '.';
}

void read_line(char buffer[])
{
    char character;
    int  i = 0;

    do
    {
        character = getchar();
        buffer[i] = character;
        ++i;
    } while (character != '\n');

    buffer[i - 1] = '\0';
}

/* Function to count the number of words in a string */

int count_words(const char string[])
{
    int  i, word_count = 0;
    bool looking_for_word = true, is_alphabetic(const char c);

    for (i = 0; string[i] != '\0'; ++i)
        if ( is_alphabetic(string[i]) || is_number(string[i]) )
        {
            if ( looking_for_word )
            {
                ++word_count;
                looking_for_word = false;
            }
        }
        else
            looking_for_word = true;
    
    return word_count;
}

int main(void)
{
    char text[81];
    int  total_words = 0;
    int  count_words(const char string[]);
    void read_line(char buffer[]);
    bool end_of_text = false;

    printf("Type in your text.\n");
    printf("When you are done, press 'RETURN'.\n\n");

    while (!end_of_text)
    {
        read_line(text);

        if (text[0] == '\0')
            end_of_text = true;
        else
            total_words += count_words(text);
    }

    printf("\nThere are %i words in the above text.\n", total_words);

    return 0;
}
