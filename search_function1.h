#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
} DOGADJAJ;
int compare_dates(const void* da,const void* db)
{
    DOGADJAJ* d1 = (DOGADJAJ*)da;
    DATUM* d2 = (DATUM*)db;
    if (d1->d.godina < d2->godina)
        return -1;

    else if (d1->d.godina > d2->godina)
        return 1;

    if (d1->d.godina == d2->godina)
    {
        if (d1->d.mjesec < d2->mjesec)
            return -1;
        else if (d1->d.mjesec > d2->mjesec)
            return 1;
        else if (d1->d.dan < d2->dan)
            return -1;
        else if (d1->d.dan > d2->dan)
            return 1;
        else
            return 0;
    }
}

void pisi(DOGADJAJ* d)
{
    printf("%s\n%s\n%s\n%s\n%d.%d.%d.\n%d:%d\n",d->kategorija,d->naziv, d->opis, d->lokacija, d->d.dan, d->d.mjesec, d->d.godina, d->v.h, d->v.min);
    printf("\n");
}
void pretrazi(DOGADJAJ* d)
{
    DOGADJAJ p;
    int i = 0;
    int n = 10;
    d = (DOGADJAJ*)malloc(n * sizeof(DOGADJAJ));
    char pom[1000];
    char c = 0;
    FILE* fp = fopen("dodaj_dogadjaj.txt", "r");
    while (fgets(pom, 100, fp) != NULL)
    {
        fscanf(fp, "%s", p.kategorija);
        fscanf(fp, "%c", &c);
        fscanf(fp, " %[^\n]s", p.naziv);
        fscanf(fp, "%c", &c);
        fscanf(fp, " %[^\n]s", p.opis);
        fscanf(fp, "%c", &c);
        fscanf(fp, " %[^\n]s", p.lokacija);
        fscanf(fp, "%c", &c);
        fscanf(fp, "%d.%d.%d.", &p.d.dan, &p.d.mjesec, &p.d.godina);
        fscanf(fp, "%c", &c);
        fscanf(fp, "%d:%dh", &p.v.h, &p.v.min);
        fgets(pom, 100, fp);
        if (i == n)
            d = (DOGADJAJ*)realloc(d, (n *= 2) * sizeof(DOGADJAJ));
        d[i++] = p;

    }
    fclose(fp);
    DATUM* x;
    x = (DATUM*)malloc(sizeof(DATUM));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    x->godina = tm.tm_year + 1900;
    x->mjesec = tm.tm_mon + 1;
    x->dan = tm.tm_mday;
    int option;
    do
    {
        printf("[1]Kategorija\n[2]Danasnji dogadjaji\n[3]Protekli dogadjaji\n[4]Buduci dogadjaji\n[0]Izlaz\n");
        scanf("%d", &option);
        if (option == 1)
        {
            char category[50];
            scanf("%s", category);
            for (int j = 0; j < i; j++)
                if (!strcmp((d + j)->kategorija, category)) // pregled po kategoriji
                    pisi(d + j);

        }
        if (option == 2)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare_dates((d + j), x) == 0) // danasnji dogadjaji
                    pisi(d + j);
            }
        }
        if (option == 3)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare_dates((d + j), x) == -1) // protekli dogadjaji
                    pisi(d + j);
            }
        }
        if (option == 4)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare_dates((d + j), x) == 1) // buduci dogadjaji
                    pisi(d + j);
            }
        }
    } while (option != 0);
}