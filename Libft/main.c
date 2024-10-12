// main.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "libft.h"

#define NUM_TESTS 1000

char generate_random_char() {
    return (char)(rand() % 128);
}

void compare_and_print(const char* func_name, bool gnu_result, bool custom_result, char test_char) {
    if (gnu_result == custom_result) {
        printf("%s: PASS for '%c' (ASCII %d)\n", func_name, test_char, test_char);
    } else {
        printf("%s: FAIL for '%c' (ASCII %d) - GNU: %d, Custom: %d\n",
               func_name, test_char, test_char, gnu_result, custom_result);
    }
}

int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < NUM_TESTS; i++) {
        char test_char = generate_random_char();
        compare_and_print("isalpha", isalpha(test_char), ft_isalpha(test_char), test_char);
        compare_and_print("isdigit", isdigit(test_char), ft_isdigit(test_char), test_char);
        compare_and_print("isalnum", isalnum(test_char), ft_isalnum(test_char), test_char);
        compare_and_print("isascii", isascii(test_char), ft_isascii(test_char), test_char);
        compare_and_print("isprint", isprint(test_char), ft_isprint(test_char), test_char);

        printf("\n");  // Add a newline for readability between test sets
    }

    return 0;
}

