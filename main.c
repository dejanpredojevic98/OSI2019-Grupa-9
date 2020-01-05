#include <stdio.h>
#include <stdlib.h>
#include <string.h.>
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

void azuriraj (DOGADJAJ *d)
{
    char pom[1000], naziv[1000]; int k, br=0;
    char c=0; char opis[1000], lokacija[100]; DATUM dat; VRIJEME vrijeme;
    FILE *fp1=fopen("dodaj_dogadjaj.txt", "r");
    FILE *fp2=fopen("azurirani.txt", "w");
    printf("\nUnesite naziv dogadjaja koji zelite da azurirate: "); scanf(" %[^\n]s", naziv);
    fgets(pom, 100, fp1); int broj1, broj2, broj3, broj4;
    while(fgets(pom,100,fp1)!=NULL)
    {
        fscanf(fp1, "%s", d->kategorija);
        fscanf(fp1,"%c",&c);
        fscanf(fp1," %[^\n]s",d->naziv);
        fscanf(fp1,"%c",&c);
        fscanf(fp1, " %[^\n]s", d->opis);
        fscanf(fp1,"%c",&c);
        fscanf(fp1," %[^\n]s", d->lokacija);
        fscanf(fp1,"%c",&c);
        fscanf(fp1,"%d.%d.%d.", &d->d.dan, &d->d.mjesec, &d->d.godina);
        fscanf(fp1,"%c",&c);
        fscanf(fp1,"%d:%dh", &d->v.h, &d->v.min);
        fgetc(fp1);
        k=strcmp(naziv, d->naziv);
        //printf("ucitano\n");

        if(k!=0)
        {
            fprintf(fp2,"\n\n%s\n%s\n%s\n%s\n%02d.%02d.%02d.\n%02d:%02dh",
                d->kategorija,d->naziv, d->opis, d->lokacija, d->d.dan, d->d.mjesec, d->d.godina, d->v.h, d->v.min);
                //printf("ispisano\n");
        }
        else if(k==0)
        {
            //printf("azuriranje\n");
             br++;
            fprintf(fp2,"\n\n%s\n%s\n", d->kategorija, d->naziv);
            printf("\nDa li zelite da promijenite opis?\n1 - DA\n2 - NE\nIzbor: "); scanf("%d", &broj1);
            if(broj1==1)
            {
                printf("\nNovi opis: "); scanf(" %[^\n]s", opis);
                fprintf(fp2,"%s\n", opis);
            }
            if(broj1==2)
                fprintf(fp2,"%s\n", d->opis);
            printf("\nDa li zelite da promijenite lokaciju?\n1 - DA\n2 - NE\nIzbor: "); scanf("%d",&broj2);
            if(broj2==1)
            {
                printf("\nNova lokacija: "); scanf(" %[^\n]s", lokacija);
                fprintf(fp2,"%s\n", lokacija);
            }
            if(broj2==2)
                fprintf(fp2,"%s\n", d->lokacija);
            printf("\nDa li zelite da promijenite datum?\n1 - DA\n2 - NE\nIzbor: "); scanf("%d",&broj3);
            if(broj3==1)
            {
                printf("\nNovi datum: "); scanf("%d.%d.%d.", &dat.dan, &dat.mjesec, &dat.godina);
                fprintf(fp2,"%02d.%02d.%d.\n", dat.dan, dat.mjesec, dat.godina);
            }
            if(broj3==2)
                fprintf(fp2,"%d.%d.%d.\n", d->d.dan, d->d.mjesec, d->d.godina);
            printf("\nDa li zelite da promijenite vrijeme?\n1 - DA\n2 - NE\nIzbor: "); scanf("%d",&broj4);
            if(broj4==1)
            {
                printf("\nNovo vrijeme: "); scanf("%d:%d", &vrijeme.h, &vrijeme.min);
                fprintf(fp2,"%02d:%02dh\n", vrijeme.h, vrijeme.min);
            }
            if(broj4==2)
                fprintf(fp2,"%02d:%02dh\n", d->v.h, d->v.min);
        }
    }
    if(br==0)
        printf("Ne postoji dogadjaj!\n");
    fclose(fp2);
    fclose(fp1);

}
int main()
{
    DOGADJAJ d;
    azuriraj(&d);
    return 0;
}
