#ifndef BRISANJE_KATEGORIJE
#define BRISANJE_KATEGORIJE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void brisi_kategoriju()
{
    DOGADJAJ d;
    char pom[100], str_kat[100], c=0;
    int k,j,br1=0,br2=0;
    FILE *fp=fopen("dodaj_dogadjaj.txt", "r");
    FILE *fp1=fopen("nova.txt", "w");
    FILE *fp2=fopen("kategorije.txt", "r");
    FILE *fp3=fopen("nova_kategorija.txt", "w");

    printf("Unesite koju kategoriju zelite obrisati: ");
    scanf(" %[^\n]s", str_kat);

    while(fscanf(fp2, "%s\n", d.kategorija)==1)
    {
        j=strcmp(str_kat, d.kategorija);
        if(j==0)
        {
        printf("\nObrisana kategorija: %s\n", d.kategorija);
        br1++;
        }


        if(j!=0)
            fprintf(fp3,"%s\n",d.kategorija);
    }

    while(fgets(pom,100,fp)!=NULL)
    {
        fscanf(fp, "%s", d.kategorija);
        fscanf(fp,"%c",&c);
        fscanf(fp," %[^\n]s",d.naziv);
        fscanf(fp,"%c",&c);
        fscanf(fp, " %[^\n]s", d.opis);
        fscanf(fp,"%c",&c);
        fscanf(fp," %[^\n]s", d.lokacija);
        fscanf(fp,"%c",&c);
        fscanf(fp,"%d.%d.%d.", &d.d.dan, &d.d.mjesec, &d.d.godina);
        fscanf(fp,"%c",&c);
        fscanf(fp,"%d:%dh", &d.v.h, &d.v.min);
        fgetc(fp);
        k=strcmp(str_kat, d.kategorija);
        if(k==0)
        {printf("\nObrisan dogadjaj: %s\n", d.naziv);
        br2++;}


        if(k!=0)
            fprintf(fp1,"\n%s\n%s\n%s\n%s\n%02d.%02d.%02d.\n%02d:%02dh\n",
                    d.kategorija,d.naziv, d.opis, d.lokacija, d.d.dan, d.d.mjesec, d.d.godina, d.v.h, d.v.min);
    }
    if (br1==0) printf("\nNe postoje podaci o toj kategoriji!\n");
    if (br2==0) printf("\nNe postoje dogadjaji sa tom kategorijom!\n");
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    remove("dodaj_dogadjaj.txt");
    rename("nova.txt", "dodaj_dogadjaj.txt");
    remove("kategorije.txt");
    rename("nova_kategorija.txt", "kategorije.txt");
}
#endif // BRISANJE_KATEGORIJE


