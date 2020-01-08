#ifndef PRIKAZ_DOGADJAJA
#define PRIKAZ_DOGADJAJA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int compare_dates1(const void* da, const void* db)
{
    DOGADJAJ* d1 = (DOGADJAJ*)da;
    DOGADJAJ* d2 = (DOGADJAJ*)db;
    if (d1->d.godina < d2->d.godina)
        return -1;

    else if (d1->d.godina > d2->d.godina)
        return 1;

    if (d1->d.godina == d2->d.godina)
    {
        if (d1->d.mjesec < d2->d.mjesec)
            return -1;
        else if (d1->d.mjesec > d2->d.mjesec)
            return 1;
        else if (d1->d.dan < d2->d.dan)
            return -1;
        else if (d1->d.dan > d2->d.dan)
            return 1;
        else
            return 0;
    }
}

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
int Sort_By_Name(const void* a, const void* b)
{
    DOGADJAJ* ia = (DOGADJAJ*)a;
    DOGADJAJ* ib = (DOGADJAJ*)b;
    return strcmp(ia->naziv, ib->naziv);

}

void pisi(DOGADJAJ* d)
{
    printf("%s\n%s\n%s\n%s\n%d.%d.%d.\n%02d:%02d\n",d->kategorija,d->naziv, d->opis, d->lokacija, d->d.dan, d->d.mjesec, d->d.godina, d->v.h, d->v.min);
    printf("\n");
}
void pretrazi_sortiraj(DOGADJAJ* d)
{
    DOGADJAJ p;
    int i = 0;
    int n = 10;
    int w;
    d = (DOGADJAJ*)malloc(n * sizeof(DOGADJAJ));
    char pom[1000];
    char c = 0;
    char grad[15];
    printf("Unesite grad za koji vas interesuju dogadjaji:\n");
    scanf(" %[^\n]s", grad);
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
        w=strstr(p.lokacija, grad);
            if(w)
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
        printf("\n[1]Kategorija\n[2]Danasnji dogadjaji\n[3]Protekli dogadjaji\n[4]Buduci dogadjaji\n[0]Izlaz\n");
        scanf("%d", &option);
        if (option == 1)
        {
            char category[50];
            printf("Unesite naziv kategorije:\n");
            scanf("%s", category);
            printf("\nDa li zelite sortirati podatke?\n");
            printf("[1]Da\n[2]Ne\n");
            int option2;
            scanf("%d", &option2);
            if (option2 == 1)
            {
                printf("[1]Sortiranje po nazivu\n[2]Sortiranje po datumu\n");
                int option3;
                scanf("%d", &option3);
                if (option3 == 1)
                    qsort(d, i, sizeof(DOGADJAJ), Sort_By_Name);
                else if(option3==2)
                    qsort(d, i, sizeof(DOGADJAJ),compare_dates1);

            }
            printf("Pregled dogadjaja:\n\n");
            for (int j = 0; j < i; j++)
                if (!strcmp((d + j)->kategorija, category))
                    pisi(d + j);

        }
        if (option == 2)
        {
            printf("\nDa li zelite sortirati podatke?\n");
            printf("[1]Da\n[2]Ne\n");
            int option2;
            scanf("%d", &option2);
            if (option2 == 1)
            {
                printf("[1]Sortiranje po nazivu\n[2]Sortiranje po datumu\n");
                int option3;
                scanf("%d", &option3);
                if (option3 == 1)
                    qsort(d, i, sizeof(DOGADJAJ), Sort_By_Name);
                else if (option3 == 2)
                    qsort(d, i, sizeof(DOGADJAJ), compare_dates1);

            }
            printf("Pregled dogadjaja:\n\n");
            for (int j = 0; j < i; j++)
            {
                if (compare_dates((d + j), x) == 0)
                    pisi(d + j);
            }
        }
        if (option == 3)
        {
            printf("\nDa li zelite sortirati podatke?\n");
            printf("[1]Da\n[2]Ne\n");
            int option2;
            scanf("%d", &option2);
            if (option2 == 1)
            {
                printf("\n[1]Sortiranje po nazivu\n[2]Sortiranje po datumu\n");
                int option3;
                scanf("%d", &option3);
                if (option3 == 1)
                    qsort(d, i, sizeof(DOGADJAJ), Sort_By_Name);
                else if (option3 == 2)
                    qsort(d, i, sizeof(DOGADJAJ), compare_dates1);

            }
            printf("Pregled dogadjaja:\n\n");
            for (int j = 0; j < i; j++)
            {
                if (compare_dates((d + j), x) == -1)
                    pisi(d + j);
            }
        }
        if (option == 4)
        {
            printf("\nDa li zelite sortirati podatke?\n");
            printf("[1]Da\n[2]Ne\n");
            int option2;
            scanf("%d", &option2);
            if (option2 == 1)
            {
                printf("[1]Sortiranje po nazivu\n[2]Sortiranje po datumu\n");
                int option3;
                scanf("%d", &option3);
                if (option3 == 1)
                    qsort(d, i, sizeof(DOGADJAJ), Sort_By_Name);
                else if (option3 == 2)
                    qsort(d, i, sizeof(DOGADJAJ), compare_dates1);

            }
            printf("Pregled dogadjaja:\n\n");
            for (int j = 0; j < i; j++)
            {
                if (compare_dates((d + j), x) == 1)
                    pisi(d + j);
            }
        }
    }
    while (option != 0);
    free(d);
    free(x);
}
#endif // PRIKAZ_DOGADJAJA
