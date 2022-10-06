#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void butt1(char *printer, FILE *f);
void butt2(FILE *f);
void butt3();
void ceaser(int key, FILE *after);

int main() {
    char mycor;
    FILE *f = NULL;
    int button = 0, flag = 0;
    char *path = malloc(100);
    char *printer = malloc(100);
    while (flag != 1) {
        rewind(stdin);
        scanf("%d", &button);
        switch (button) {
        case 1:
            scanf("%s", path);
            f = fopen(path, "r");
            butt1(printer, f);
            break;
        case 2:
            if (f != NULL) {
                f = fopen(path, "a+");
                rewind(stdin);
                butt2(f);
                butt1(printer, f);
                fclose(f);
            } else {
                rewind(stdin);
                scanf("%c", &mycor);
                printf("n/a\n");
            }
            break;
        case 3:
            rewind(stdin);
            butt3();
            break;
        case -1:
            flag = 1;
            break;
        default:
            printf("n/a\n");
            break;
        }
    }
    free(path);
    free(printer);
    return 0;
}
void butt1(char *printer, FILE *f) {
    if (f == NULL) {
        printf("n/a\n");
    } else {
        fseek(f, 0, SEEK_END);
        if (ftell(f) == 0) {
            printf("n/a\n");
        } else {
            fseek(f, 0, SEEK_SET);
            while (fgets(printer, 100, f) != NULL) {
                printf("%s\n", printer);
            }
        }
    }
}
void butt2(FILE *f) {
    char str;
    if (ftell(f) == 0) {
        while (scanf("%c", &str) && str != '\n') {
            fprintf(f, "%c", str);
        }
    } else {
        fprintf(f, "\n");
        while (scanf("%c", &str) && str != '\n') {
            fprintf(f, "%c", str);
        }
    }
}
void butt3() {
    DIR* direcory;
    FILE *after, *heder;
    struct dirent* entry;
    char* path;
    int key;
    path = calloc(100, sizeof(char));
    scanf("%s", path);
    scanf("%d", &key);
    char megapath[500];
    if ((direcory = opendir(path)) != NULL) {
        while ((entry = readdir(direcory)) != NULL) {
            if (entry->d_name[strlen(entry->d_name) - 1] == 'c' &&
            entry->d_name[strlen(entry->d_name) - 2] == '.') {
                strcpy(megapath, path);
                strcat(megapath, entry->d_name);
                after = fopen(megapath, "r+");
                ceaser(key, after);
                fclose(after);
                }
            if (entry->d_name[strlen(entry->d_name) - 1] == 'h' &&
            entry->d_name[strlen(entry->d_name) - 2] == '.') {
                strcpy(megapath, path);
                strcat(megapath, entry->d_name);
                heder = fopen(megapath, "w");
                fclose(heder);
                }
        }
        closedir(direcory);
        free(path);
}
}
void ceaser(int key, FILE *after) {
    printf("ceaser\n");
    char ch;
    while (fscanf(after, "%1c", &ch) != EOF) {
        ch = ch + key;
        fseek(after, -1, SEEK_CUR);
        fprintf(after, "%c", ch);
    }
}
