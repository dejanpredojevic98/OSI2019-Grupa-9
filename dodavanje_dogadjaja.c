#include <stdio.h>
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
} DOGADJAJ;

void dodaj (DOGADJAJ *d, FILE *fp)
{
    printf("\nUnesite podatke o novom dogadjaju:\n");
    printf("   Kategorija: "); scanf(" %[^\n]s",d->kategorija);
    //dodaj_kategoriju();
    printf("   Naziv dogadjaja: "); scanf(" %[^\n]s", d->naziv);
    printf("   Opis: "); scanf(" %[^\n]s", d->opis);
    printf("   Lokacija: "); scanf(" %[^\n]s", d->lokacija);
    printf("   Datum: "); scanf("%d.%d.%d.", &d->d.dan, &d->d.mjesec, &d->d.godina);
    printf("   Vrijeme: "); scanf("%d.%d", &d->v.h, &d->v.min);
    if((fp=fopen("dodaj_dogadjaj.txt", "a"))!=EOF)
    {
        fprintf(fp,"\nKategorija: %s\n  Naziv dogadjaja: %s\n  Opis: %s\n  Lokacija: %s\n  Datum: %02d.%02d.%02d.\n  Vrijeme: %02d:%02dh\n",
                d->kategorija, d->naziv, d->opis, d->lokacija, d->d.dan, d->d.mjesec, d->d.godina, d->v.h, d->v.min);
        fclose(fp);
    }
}
int main()
{

    DOGADJAJ d;
    FILE *fp;
    dodaj (&d, fp);
    return 0;
}
