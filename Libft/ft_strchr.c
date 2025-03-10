#include <stdio.h>
#include <stddef.h>
#include <string.h>

char *ft_strchr(const char *s, int c)
{
    while(*s)
    {
            if(*s == (char) c)
                return ((char *)s);
        s++;
    }
    if((char) c == '\0')
            return ((char *)s);
    return NULL;
}


void run_tests()
{
    // Test case 1: Basic test case with a character present
    char *test1 = "hello world";
    char *result1 = ft_strchr(test1, 'l');
    char *expected1 = strchr(test1, 'l');
    printf("Test 1 - 'l':\n");
    printf("Expected: %s, Got: %s\n\n", expected1, result1);

    // Test case 2: Character not present in the string
    char *test2 = "hello world";
    char *result2 = ft_strchr(test2, 'z');
    char *expected2 = strchr(test2, 'z');
    printf("Test 2 - 'z':\n");
    printf("Expected: %s, Got: %s\n\n", expected2, result2);

    // Test case 3: Searching for null terminator '\0'
    char *test3 = "hello world";
    char *result3 = ft_strchr(test3, '\0');
    char *expected3 = strchr(test3, '\0');
    printf("Test 3 - '\\0':\n");
    printf("Expected: %s, Got: %s\n\n", expected3, result3);

    // Test case 4: String with multiple occurrences of a character
    char *test4 = "hello world, hello again";
    char *result4 = ft_strchr(test4, 'l');
    char *expected4 = strchr(test4, 'l');
    printf("Test 4 - 'l':\n");
    printf("Expected: %s, Got: %s\n\n", expected4, result4);

    // Test case 5: Empty string
    char *test5 = "";
    char *result5 = ft_strchr(test5, 'l');
    char *expected5 = strchr(test5, 'l');
    printf("Test 5 - Empty string:\n");
    printf("Expected: %s, Got: %s\n\n", expected5, result5);

    // Test case 6: Character is at the beginning of the string
    char *test6 = "hello";
    char *result6 = ft_strchr(test6, 'h');
    char *expected6 = strchr(test6, 'h');
    printf("Test 6 - 'h' at the start:\n");
    printf("Expected: %s, Got: %s\n\n", expected6, result6);

    // Test case 7: Character is at the end of the string
    char *test7 = "hello";
    char *result7 = ft_strchr(test7, 'o');
    char *expected7 = strchr(test7, 'o');
    printf("Test 7 - 'o' at the end:\n");
    printf("Expected: %s, Got: %s\n\n", expected7, result7);
}

int main()
{
    run_tests();
    return 0;
}