#ifndef BRISANJEKATEGORIJE
#define BRISANJEKATEGORIJE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void brisi_kategoriju( char* kategorija)
{
    FILE*fp1;
    FILE*fp2;
    char pom[100]= {0};
    int p=0;
    if((fp1=fopen("kategorije.txt", "r")))
    {
        if( feof(fp1) )
        {
            printf("\nNema nijedne kategorije!!!");
            return;
        }
        if((fp2=fopen("nova.txt", "w")))
        {
            //  printf("\nUspjesno otvorena nova datoteka\n");
            //while(fscanf(fp1, "%[^\n]%*c", pom) != EOF)
            while(fgets(pom, 100, fp1))
            {
                if(pom[strlen(pom)-1] == '\n')
                    pom[strlen(pom)-1]=0;
                else
                    pom[strlen(pom)]=0;
             //   printf("\nPoredimo rijeci %s", pom);
                // printf(" i %s", kategorija);
                p=strcmp(kategorija, pom);
                if(p!=0)
                {
                    // printf("\nPisemo u novu datoteku %s\n", pom);
                    // fprintf(fp2, "%[^\n]%*c", pom);
                    fputs(pom,fp2);
                    fprintf(fp2, "%c",'\n');

                }
                else
                    printf("\nBrisemo kategoriju %s\n", pom);
            }
        }
        else
        {
            printf("Neuspjesno otvoranje kategorija!!!");
            return;
        }
        fclose(fp2);
    }
    else
    {
        printf("Neuspjenso otvorene kategorije");
        return;
    }
    fclose(fp1);
    remove ("kategorije.txt");
    rename("nova.txt", "kategorije.txt");
}
#endif
