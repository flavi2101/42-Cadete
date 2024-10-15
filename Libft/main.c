#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "libft.h"

#define NUM_TESTS 1000

// Helper function to generate random characters
char generate_random_char() {
    return (char)(rand() % 128);
}

// Helper function to generate random strings of a given length
void generate_random_string(char* buffer, size_t length) {
    for (size_t i = 0; i < length - 1; i++) {
        buffer[i] = generate_random_char();
    }
    buffer[length - 1] = '\0';
}

// Function to compare and print results for boolean functions
void compare_and_print_bool(const char* func_name, bool gnu_result, bool custom_result, char test_char) {
    if (gnu_result == custom_result) {
        printf("%s: PASS for '%c' (ASCII %d)\n", func_name, test_char, test_char);
    } else {
        printf("%s: FAIL for '%c' (ASCII %d) - GNU: %d, Custom: %d\n",
               func_name, test_char, test_char, gnu_result, custom_result);
    }
}

// Function to compare and print results for string functions
void compare_and_print_str(const char* func_name, const char* gnu_result, const char* custom_result, const char* test_str) {
    if (gnu_result == custom_result || (gnu_result && custom_result && strcmp(gnu_result, custom_result) == 0)) {
        printf("%s: PASS for \"%s\"\n", func_name, test_str);
    } else {
        printf("%s: FAIL for \"%s\" - GNU: %p, Custom: %p\n", func_name, test_str, gnu_result, custom_result);
    }
}

// Main test function
int main() {
    srand((unsigned int)time(NULL));

    char buffer[100];

    for (int i = 0; i < NUM_TESTS; i++) {
        char test_char = generate_random_char();
        generate_random_string(buffer, sizeof(buffer));

        // Testing character classification functions
        compare_and_print_bool("isalpha", isalpha(test_char), ft_isalpha(test_char), test_char);
        compare_and_print_bool("isdigit", isdigit(test_char), ft_isdigit(test_char), test_char);
        compare_and_print_bool("isalnum", isalnum(test_char), ft_isalnum(test_char), test_char);
        compare_and_print_bool("isascii", isascii(test_char), ft_isascii(test_char), test_char);
        compare_and_print_bool("isprint", isprint(test_char), ft_isprint(test_char), test_char);
        compare_and_print_bool("toupper", toupper(test_char) == ft_toupper(test_char), true, test_char);
        compare_and_print_bool("tolower", tolower(test_char) == ft_tolower(test_char), true, test_char);

        // Testing string functions
        size_t gnu_strlen = strlen(buffer);
        size_t custom_strlen = ft_strlen(buffer);
        printf("strlen: %s for \"%s\" (GNU: %zu, Custom: %zu)\n", (gnu_strlen == custom_strlen ? "PASS" : "FAIL"), buffer, gnu_strlen, custom_strlen);

        char random_search_char = generate_random_char();
        compare_and_print_str("strchr", strchr(buffer, random_search_char), ft_strchr(buffer, random_search_char), buffer);
        compare_and_print_str("strrchr", strrchr(buffer, random_search_char), ft_strrchr(buffer, random_search_char), buffer);

        char test_str1[] = "casa de brinquedo";
        char test_str2[] = "casa";
        size_t n = (size_t)(rand() % (strlen(test_str1) + 1));
        int gnu_strncmp = strncmp(test_str1, test_str2, n);
        int custom_strncmp = ft_strncmp(test_str1, test_str2, n);
        printf("strncmp: %s for \"%s\" vs \"%s\" (n = %zu) - GNU: %d, Custom: %d\n", (gnu_strncmp == custom_strncmp ? "PASS" : "FAIL"), test_str1, test_str2, n, gnu_strncmp, custom_strncmp);
        
        printf("\n");  // Add a newline for readability between test sets
    }

    return 0;
}
