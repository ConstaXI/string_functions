#include <stdio.h>

unsigned int strlen(const char *str);

char *strcat(char *s1, const char *s2);

int strcmp(const char *str0, const char *str1);

int strend(char *s, const char *t);

unsigned int strlen(const char *str) {
    const char *char_ptr;

    for (char_ptr = str; char_ptr != 0; ++char_ptr) {
        if (*char_ptr == '\0') {
            return (char_ptr - str);
        }
    }

    return 0;
}

char *strcat(char *s1, const char *s2) {
    // Faz com que a s1 aponte pro final dela mesma -1, para evitar o \n
    // Em seguida, copia a string s2 até ela chegar no \n
    // Em seguida, faz com que s1 e s2 incrementem, para apontar para as próximas posições
    for (s1 = (char *) s1 + strlen(s1); *s2 != '\0'; ++s1, ++s2) {
        *s1 = *s2;
    }

    // Indica o final da string
    *s1 = '\0';

    // Faz a string s1 apontar para o início dela novamente.
    s1 = s1 - strlen(s1) - strlen(s2);

    return s1;
}

int strcmp(const char *str0, const char *str1) {
    const char *ptr0, *ptr1;

    for(ptr0 = str0, ptr1 = str1; (*ptr0 || *ptr1) != '\0'; ++ptr0, ++ptr1) {
        if(*ptr0 == '\0' && *ptr1 != '\0' && *ptr0 != *ptr1) {
            return -1;
        } else if(*ptr0 != '\0' && *ptr1 == '\0' && *ptr0 != *ptr1) {
            return 1;
        }
    }

    return 0;
}

int strend(char *s, const char *t) {
    for(s = s + strlen(t) - 1; *s != '\0'; ++s, ++t) {
        if(*s != *t) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char arr_0[100];
    char arr_1[100];

    fgets(arr_0, 100, stdin);
    fflush(stdin);
    fgets(arr_1, 100, stdin);

    printf("size of arr_0: %d\n", strlen(arr_0));
    printf("size of arr_1: %d\n", strlen(arr_1));

    printf("Strings are different? %d\n", strcmp(arr_0, arr_1));

    printf("arr_1 is in the final of arr_0? %d\n", strend(arr_0, arr_1));

    strcat(arr_0, arr_1);

    puts(arr_0);

    return 0;
}