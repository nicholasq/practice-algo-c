#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeStringsAlternatively(const char *one, const char *two) {
    if (one == NULL || two == NULL) {
        printf("Input strings must not be NULL\n");
        exit(1);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    char *result = (char *) malloc(strlen(one) + strlen(two) + 1);

    if (result == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    while (one[i] != '\0' || two[j] != '\0') {
        if (one[i] != '\0') {
            result[k++] = one[i++];
        }
        if (two[j] != '\0') {
            result[k++] = two[j++];
        }
    }
    result[k] = '\0';
    return result;
}

void test_mergeStringsAlternatively() {
    printf("mergeStringsAlternatively() tests:\n");

    typedef struct testcase {
        char *one;
        char *two;
        char *expected;
    } testcase;

    const testcase testcases[] = {
        {"abc", "def", "adbecf"},
        {"abcd", "ef", "aebfcd"},
        {"ab", "cdef", "acbdef"}
    };


    const int length = sizeof(testcases) / sizeof(testcase);

    for (int i = 0; i < length; ++i) {
        const testcase current = testcases[i];
        char *result = mergeStringsAlternatively(current.one, current.two);
        if (strcmp(result, current.expected) != 0) {
            printf("mergeStringsAlternatively() failed. Expected %s, got %s\n", current.expected, result);
        } else {
            printf("Passed!\n");
        }
        free(result);
    }
}
