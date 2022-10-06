#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"
#ifdef STRLEN
    #define FUNC() s21_strlen_test()
#endif
#ifdef STRCMP
    #define FUNC() s21_strcmp_test()
#endif
#ifdef STRCPY
    #define FUNC() s21_strcpy_test()
#endif
#ifdef STRCAT
    #define FUNC() s21_strcat_test()
#endif
#ifdef STRCHR
    #define FUNC() s21_strchr_test()
#endif
#ifdef STRSTR
    #define FUNC() s21_strstr_test()
#endif
#ifdef STRTOK
    #define FUNC() s21_strtok_test()
#endif

int s21_strlen_test();
int s21_strcmp_test();
int s21_strcpy_test();
int s21_strcat_test();
int s21_strchr_test();
int s21_strstr_test();
int s21_strtok_test();

int main() {
    FUNC();
    return 0;
}

int s21_strlen_test() {
    int result = 0;
    int test_result = 0;
    char *test_str1 = "";
    char *test_str2 = "yapolinkadinozavrik";
    char *test_str3 = "O";
    printf("%s\n", test_str1);
    result = s21_strlen(test_str1);
    printf("%s\n", test_str1);
    test_result = result;
    if (test_result == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s\n", test_str2);
    result = s21_strlen(test_str2);
    printf("%s\n", test_str2);
    test_result = result;
    if (test_result == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s\n", test_str3);
    result = s21_strlen(test_str3);
    printf("%s\n", test_str3);
    if (test_result == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return test_result;
}

int s21_strcmp_test() {
    int result = 0;
    int test_result = 0;
    char *test_str1 = "Hello world";
    char *test_str2 = "Hello world";
    char *test_str3 = "MAKSIMKA HOROSHIY";
    char *test_str4 = "MAKSIMKA HOROSHIY";
    char *test_str5 = "VITYA KYPIL MNE LIPTON";
    char *test_str6 = "VITYA KYPIL MNE LIPTON";
    printf("%s %s\n", test_str1, test_str2);
    result = s21_strcmp(test_str1, test_str2);
    printf("%s %s\n", test_str1, test_str2);
    test_result = result;
    if (test_result == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str3, test_str4);
    result = s21_strcmp(test_str3, test_str4);
    printf("%s %s\n", test_str3, test_str4);
    test_result = result;
    if (test_result == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str5, test_str6);
    result = s21_strcmp(test_str5, test_str6);
    printf("%s %s\n", test_str5, test_str6);
    test_result = result;
    if (test_result == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return test_result;
}
int s21_strcpy_test() {
    int result = 0;
    int test_result = 0;
    char *test_str1 = "IDEM KYSHAT S SANEY";
    char test_str2[100];
    char *test_str3 = "VITYA GIVAPNUL PROJECT HOCHENSYA PLAKAT";
    char test_str4[100];
    char *test_str5 = "AMOMUS MOMUS SUS";
    char test_str6[100];
    printf("%s %s\n", test_str2, test_str1);
    result = s21_strcpy(test_str2, test_str1);
    printf("%s %s\n", test_str2, test_str1);
    test_result = result;
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str4, test_str3);
    result = s21_strcpy(test_str4, test_str3);
    printf("%s %s\n", test_str4, test_str3);
    test_result = result;
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str6, test_str5);
    result = s21_strcpy(test_str6, test_str5);
    printf("%s %s\n", test_str6, test_str5);
    test_result = result;
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return test_result;
}
int s21_strcat_test() {
    int test_result = 0;
    char *test_str1 = "Polina ";
    char test_str2[100] = "ne tetya";
    char *test_str3 = "oleg";
    char test_str4[100] = " mashina";
    char *test_str5 = "kto ";
    char test_str6[100] = "ya";
    printf("%s %s\n", test_str2, test_str1);
    char *result = s21_strcat(test_str2, test_str1);
    printf("%s %s\n", test_str2, test_str1);
    if (result == 0) {
        test_result = 1;
    }
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str6, test_str5);
    result = s21_strcat(test_str6, test_str5);
    printf("%s %s\n", test_str6, test_str5);
    if (result == 0) {
        test_result = 1;
    }
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str4, test_str3);
    result = s21_strcat(test_str4, test_str3);
    printf("%s %s\n", test_str4, test_str3);
    if (result == 0) {
        test_result = 1;
    }
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return test_result;
}

int s21_strchr_test() {
    int test_result = 0;
    char *test_str1 = "Gachi remix";
    char *test_str2 = "Anton uehal v samaru";
    char *test_str3 = "Klava Koka";
    printf("%s\n", test_str1);
    char *result = s21_strchr(test_str1, 'G');
    printf("%s\n", test_str1);
    if (result == NULL) {
        test_result = 1;
    }
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s\n", test_str2);
    result = s21_strchr(test_str2, 'A');
    printf("%s\n", test_str2);
    if (result == NULL) {
        test_result = 1;
    }
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s\n", test_str3);
    result = s21_strchr(test_str3, 'K');
    printf("%s\n", test_str3);
    if (result == NULL) {
        test_result = 1;
    }
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return test_result;
}
int s21_strstr_test() {
    int result = 0;
    int test_result = 0;
    char *test_str1 = "Come on, lets go!";
    char *test_str2 = "lets go";
    char *test_str3 = "Domoy, Bista!";
    char *test_str4 = "Bista";
    char *test_str5 = "Maksim, cherni!";
    char *test_str6 = "cherni";
    printf("%s %s\n", test_str1, test_str2);
    result = s21_strstr(test_str1, test_str2);
    printf("%s %s\n", test_str1, test_str2);
    test_result = result;
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str3, test_str4);
    result = s21_strstr(test_str3, test_str4);
    printf("%s %s\n", test_str3, test_str4);
    test_result = result;
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%s %s\n", test_str5, test_str6);
    result = s21_strstr(test_str5, test_str6);
    printf("%s %s\n", test_str5, test_str6);
    test_result = result;
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return test_result;
}

int s21_strtok_test() {
    int test_result = 0;
    char test_str[] = "Hello, world!";
    char *result = s21_strtok(test_str, " ,!");
    if (result != NULL) {
        test_result = 1;
    }
    if (test_result != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    return test_result;
}
