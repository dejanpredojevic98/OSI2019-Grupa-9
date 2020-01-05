#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void brisi (DOGADJAJ *d);

int main()
{
    DOGADJAJ d;
    brisi(&d);

    return 0;
}
void brisi (DOGADJAJ *d)
{
    char pom[1000];
    char c=0;
    FILE *fp=fopen("dodaj_dogadjaj.txt", "r");
    FILE *fp1=fopen("nova.txt", "w");
    printf("Unesi naziv dogadjaja koji brisemo?");
    char string[100];
    scanf("%[^\n]s", string);
    fgets(pom, 100, fp);
    while(fgets(pom,100,fp)!=NULL)
    {

        fscanf(fp, "%s", d->kategorija);
        fscanf(fp,"%c",&c);
        fscanf(fp," %[^\n]s",d->naziv);
        fscanf(fp,"%c",&c);
        fscanf(fp, " %[^\n]s", d->opis);
        fscanf(fp,"%c",&c);
        fscanf(fp," %[^\n]s", d->lokacija);
        fscanf(fp,"%c",&c);
        fscanf(fp,"%d.%d.%d.", &d->d.dan, &d->d.mjesec, &d->d.godina);
        fscanf(fp,"%c",&c);
        fscanf(fp,"%d:%dh", &d->v.h, &d->v.min);fgetc(fp);
        int k=strcmp(string, d->naziv);
        printf("\nPoredimo %s i %s, dobijamo %d\n", string, d->naziv, k);


    if(k!=0)
        fprintf(fp1,"\n\n%s\n%s\n%s\n%s\n%02d.%02d.%02d.\n%02d:%02dh",
                d->kategorija,d->naziv, d->opis, d->lokacija, d->d.dan, d->d.mjesec, d->d.godina, d->v.h, d->v.min);

    printf("%s\n%s\n%s\n%s\n%d.%d.%d.\n%d:%d\n\n",d->kategorija, d->naziv,d->opis, d->lokacija, d->d.dan, d->d.mjesec, d->d.godina, d->v.h, d->v.min);
    }
    fclose(fp1);
    fclose(fp);
    remove("dodaj_dogadjaj.txt");
    rename("nova.txt", "dodaj_dogadjaj.txt");
}
