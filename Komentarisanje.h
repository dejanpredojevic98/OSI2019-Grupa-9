#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct vrijeme
{
    int h, min;
} VRIJEME;
typedef struct datum
{
    int dan, mjesec, godina;
} DATUM;
typedef struct dogadjaj
{
    char naziv[100], opis[1000], lokacija[50], kategorija[30];
    DATUM d;
    VRIJEME v;
    char komentar[100];
} DOGADJAJ;
typedef struct node {
    DOGADJAJ d;
    struct node* next;
}NODE;
void write_in_file(char* name1, char* str2)
{
    FILE* dat;
    if (dat = fopen(name1, "a"))
    {
        fprintf(dat,"%s\n", str2);
        fclose(dat);
    }
}

void insert_comment(char* str1)
{
    char str2[50] = { 0 };
    scanf("%[^\n]%*c", str2);
    strcat(str1, "comments.txt");
    write_in_file(str1, str2);
}

