#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

size_t s21_strlen(const char *str)  {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
int s21_strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
int s21_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return 0;
}
char *s21_strcat(char *dest, const char *src) {
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
char *s21_strchr(const char *str, int ch) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            return (char *) &str[i];
        }
        i++;
    }
    return NULL;
}
int s21_strstr(const char *str1, const char *str2) {
    int i = 0, k = 0, j = 0;
    while (str1[i] != '\0') {
        if (str1[i] == str2[j]) {
            k = i;
            while (str1[k] != '\0' && str2[j] != '\0') {
                if (str1[k] != str2[j]) {
                    break;
                }
                k++;
                j++;
            }
            if (str2[j] == '\0') {
                return i;
            }
        }
        i++;
    }
    return -1;
}
char *s21_strtok(char *str, const char *delim) {
    static char *last_str = NULL;
    if (str == NULL) {
        str = last_str;
    }
    if (str == NULL) {
        return NULL;
    }
    int i = 0, j = 0, k = 0, is_delim = 0;
    while (str[i] != '\0') {
        is_delim = 0;
        j = 0;
        while (delim[j] != '\0') {
            if (str[i] == delim[j]) {
                is_delim = 1;
                break;
            }
            j++;
        }
        if (!is_delim) {
            break;
        }
        i++;
    }
    if (str[i] == '\0') {
        last_str = NULL;
        return NULL;
    }
    last_str = str + i;
    while (last_str[k] != '\0') {
        is_delim = 0;
        j = 0;
        while (delim[j] != '\0') {
            if (last_str[k] == delim[j]) {
                is_delim = 1;
                break;
            }
            j++;
        }
        if (is_delim) {
            break;
        }
        k++;
    }
    if (last_str[k] == '\0') {
        last_str = NULL;
    } else {
        last_str[k] = '\0';
        last_str = last_str + k + 1;
    }
    return str + i;
}
