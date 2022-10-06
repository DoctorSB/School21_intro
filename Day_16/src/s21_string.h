#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
int s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int ch);
int s21_strstr(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);

#endif  //  SRC_S21_STRING_H_
