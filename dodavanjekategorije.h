
#ifndef DODAVANJE_KATEGORIJE
#define DODAVANJE_KATEGORIJE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *fp;
int find_result = 0;
char temp[512],s[50];

void dodavanje_kategorije(char s[]);
int Search_in_File(char *fname, char *str);
int Search_in_File(char *fname, char *str)
{
    if((fp = fopen(fname, "r")) == NULL)
        return 0;
    while(fgets(temp, 512, fp) != NULL)
    {
        if((strstr(temp, str)) != NULL)
        {
            find_result++;
            return 1; //pronadjeno
        }
    }

    if(find_result == 0)
    {
        printf("\nDodajemo novu kategoriju ");
    }
    if(fp)
    {
        fclose(fp);
    }
    return(-1);
}
void dodavanje_kategorije(char s[])
{

            for(int i = 0; s[i]; i++)
            {
                s[i] = tolower(s[i]);
            }
            if((fp=(fopen("kategorije.txt","a")))!=0)
            {
                //printf("\nUspjesno otvorena datoteka\n");
                int p=0;
                p=Search_in_File("kategorije.txt", s);
                //printf("\n%d",p);
                if(p==1)
                {
                    printf("\nKategorija vec postoji!\n");
                    fclose(fp);

                }
                if(p==-1)
                {
                    fopen("kategorije.txt","a");
                    fprintf(fp, "%s\n", s);
                    printf("%s!\n", s);
                    fclose(fp);

                }
            }
        }

#endif
