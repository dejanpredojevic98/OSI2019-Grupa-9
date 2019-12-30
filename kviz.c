#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ime_grada[10], s[100];
    int i, odg_a,odg_b,odg_c,odg_d,odg_e,odg_f,odg_g,odg_h,odg_i,odg_j;
    int broj_bodova=0;

    printf("Unesite ime grada za koji zelite igrati kviz:\n");
    gets(ime_grada);
    strcat(ime_grada, ".txt");
    if ((fp=fopen (ime_grada, "r"))!=NULL)
    {
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }

        printf("\nUnesite odgovor na pitanje broj 1: ");
        scanf("%d", &odg_a);
        if (odg_a==2)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");

        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 2: ");
        scanf("%d", &odg_b);
        if (odg_b==3)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 3: ");
        scanf("%d", &odg_c);
        if (odg_c==2)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 4: ");
        scanf("%d", &odg_d);
        if (odg_d==1)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 5: ");
        scanf("%d", &odg_e);
        if (odg_e==1)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 6: ");
        scanf("%d", &odg_f);
        if (odg_f==3)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 7: ");
        scanf("%d", &odg_g);
        if (odg_g==2)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 8: ");
        scanf("%d", &odg_h);
        if (odg_h==3)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 9: ");
        scanf("%d", &odg_i);
        if (odg_i==1)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");
        for (int a=0; a<5; a++)
        {
            fgets(s, 100, fp);
            printf("%s", s);
        }
        printf("\nUnesite odgovor na pitanje broj 10: ");
        scanf("%d", &odg_j);
        if (odg_j==2)
        {
            printf("Tacan odgovor!\n\n");
            broj_bodova++;
        }
        else
            printf("Netacan odgovor\n\n");

        printf("\nBroj osvojenih bodova iznosi %d", broj_bodova);
        fclose(fp);
    }
    else
        printf("Ne postoji kviz za taj grad");
    return 0;
}
//2 3 2 1 1 3 2 3 1 2
