/* Exercise 12 from chapter 10.
 * Write a function called str_to_float that converts a character string into
 * a floating-point value. Have the function accept an optional leading minus
 * sign.
 */

#include <stdio.h>
#include <stdbool.h>

float str_to_float(const char string[])
{
    float result = 0.0f;
    float float_value = 0.0f;
    bool is_negative = false;
    int point_pos = -1;
    int exponent = 0;
    int i = 0;

    if (string[i] == '-') {
        is_negative = true;
        i++;
    }

    for (; (string[i] >= '0' && string[i] <= '9') || string[i] == '.'; i++) {

        if (string[i] == '.') {
            point_pos = i;
            continue;
        }

        float_value = string[i] - '0';
        result = result * 10 + float_value;
    }

    if (point_pos != -1) {
        exponent = i - point_pos - 1;
        
        for (int j = 1; j <= exponent; j++)
            result *= 0.1f;
    }

    if (is_negative)
        return -result;

    return result;
}

int main(void)
{
    printf("%f\n", str_to_float("1.1"));
    printf("%f\n", str_to_float("395.59") + 25.1f);
    printf("%f\n", str_to_float("-867.6921"));
    printf("%f\n", str_to_float("-222.2222") + 111.1111f);

    return 0;
}
