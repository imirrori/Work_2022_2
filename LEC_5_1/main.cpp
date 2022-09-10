// Дана строка символов. Определить, является ли она правильным скобочным выражением.
// () - да
// (()) - да
// )( - нет

#include <stdio.h>

int main()
{
    const char* str_1 = "()";
    int count = 0;

    while(*str_1) {
        if (*str_1 == '(') {
            ++count;
        } else if (*str_1 == ')') {
            --count;
            if (count < 0) {
                printf("false\n");
                return 0;
            }
        }
        ++str_1;
    }

    printf("%s\n", count == 0 ? "true" : "false");

    return 0;
}
