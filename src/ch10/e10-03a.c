/* Exercise 03a from chapter 10.
 * Modify Program 10.7 the countWords funtion to count the apostrophe as part
 * of a word. Also, extend the function to count a sequence of positive or
 * negative numbers, including any embedded commas and periods, as a single
 * word.
 */

#include <stdio.h>
#include <stdbool.h>

bool is_alphabetic(const char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'';
}

/* Function to count the number of words in a string */

bool is_number(const char c)
{
    return c >= '0' && c <= '9'
            || c == '+' || c == '-' || c == ',' || c == '.';
}

int count_words(const char string[])
{
    int  i, word_count = 0;
    bool looking_for_word = true;

    for (i = 0; string[i] != '\0'; ++i) {
        if ( is_alphabetic(string[i]) || is_number(string[i]) )
        {
            if (looking_for_word) {
                ++word_count;
                looking_for_word = false;
            }
        }
        else {
            looking_for_word = true;
        }
    }
    
    return word_count;
}

int main(void)
{
    const char text1[] = "My lucky numbers are 3 and 5.";
    const char text2[] = "It's small loan of 1,000,000.00 dollars.";
    const char text3[] = "The dolphin is -10 meters from sea level.";
    int count_words(const char string[]);

    printf("%s - words = %i\n", text1, count_words(text1));
    printf("%s - words = %i\n", text2, count_words(text2));
    printf("%s - words = %i\n", text3, count_words(text3));

    return 0;
}
