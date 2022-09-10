// Дана строка символов. Удалить из нее все слова нечетной длины.
// Слова отделяются друг от друга одним пробелом.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[255];

    printf("Please enter string: ");
    gets(str);

    char word[255];
    int len = 0;
    while(sscanf(str + len, "%s", word) == 1) {
        const int wordLen = strlen(word);
        len += wordLen + 1;
        if ((wordLen % 2) == 1) {
            printf("%s\n", word);
        }
    }

    return 0;
}
