#include <string.h>

char *ctos(char s[2], const char c) {
    s[0] = c;         // Assign the input character to the first element of the array
    s[1] = '\0';      // Null-terminate the string
    return s;         // Return a pointer to the string
}