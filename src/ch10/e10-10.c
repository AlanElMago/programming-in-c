/* Exercise 10 from chapter 10.
 * Write a function called dictionary_sort that sorts a dictionary.
 */

#include <stdio.h>
#include <stdbool.h>

struct entry
{
    char word[15];
    char definition[50];
};

int compare_strings(const char s1[], const char s2[])
{
    int i = 0, answer;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        ++i;
    
    if (s1[i] < s2[i])
        answer = -1;            /* s1 < s2 */
    else if (s1[i] == s2[i])
        answer = 0;             /* s1 == s2 */
    else
        answer = 1;             /* s1 > s2 */
    
    return answer;
}

void dictionary_sort(int entries, struct entry d[entries])
{
    // Bubble sort

    int i;
    int j = entries - 1;
    bool sorted = false;
    struct entry aux;

    while(!sorted) { 
        sorted = true;

        for(int i = 0; i < j; i++) {
            if (compare_strings(d[i].word, d[i + 1].word) == 1) {
                aux = d[i];
                d[i] = d[i + 1];
                d[i + 1] = aux;
                sorted = false;
            }
        }
        j--;
    }
}

void print_dictionary(int entries, const struct entry d[entries])
{
    for (int i = 0; i < entries; i++)
        printf("%-15s %-40s\n", d[i].word, d[i].definition);
}

int main(void)
{
    struct entry dictionary[100] =
            {
              { "ahoy",     "a nautical call of greeting"       },
              { "aardvark", "a burrowing African mammal"        },
              { "aerie",    "a high nest"                       },
              { "ajar",     "partially opened"                  },
              { "addle",    "to become confused"                },
              { "affix",    "to append; attach"                 },
              { "abyss",    "a bottomless pit"                  },
              { "agar",     "a jelly made from seaweed"         },
              { "acumen",   "mentally sharp; keen"              },
              { "aigrette", "an ornamental cluster of feathers" },
            };

    char word[15];
    int  entries = 10;

    printf("Unsorted dictionary:\n");
    print_dictionary(entries, dictionary);

    dictionary_sort(entries, dictionary);

    printf("\nSorted dictionary:\n");
    print_dictionary(entries, dictionary);

    return 0;
}
