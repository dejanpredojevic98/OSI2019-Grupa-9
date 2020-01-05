#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct datum
{
	int dan, mjesec, godina;
}DATUM;
typedef struct vrijeme
{
	int h, min;
} VRIJEME;
typedef struct dogadjaj
{
	char naziv[100], opis[1000], lokacija[50], kategorija[30];
	DATUM d;
	VRIJEME v;
} DOGADJAJ;
int cmp_string(const void* a, const void* b)
{
	return strcmp(*(char**)a, *(char**)b);
}
int split(DOGADJAJ *niz, int begin, int end) {
  int i = begin, j = end;
  DOGADJAJ pivot=niz[begin];
  while (i < j) {
    while (cmp_string(niz[i].lokacija,pivot.lokacija) && i<j) i++;
    while (cmp_string(niz[j].lokacija,pivot.lokacija)) j--;
    if (i < j) {
       DOGADJAJ pom = niz[i];
       niz[i] = niz[j];
       niz[j] = pom;
    }
  }
  niz[begin] = niz[j];
  niz[j] = pivot;
  return j;
}
void quick_sort(DOGADJAJ *niz,int begin, int end) {
  if (begin < end) {
    int pivot = split(niz, begin, end);
    quick_sort(niz, begin, pivot - 1);
    quick_sort(niz, pivot + 1, end);
  }
}
int split1(DOGADJAJ *niz, int begin, int end) {
  int i = begin, j = end;
  DOGADJAJ pivot=niz[begin];
  while (i < j) {
     while (cmp_string(niz[i].kategorija,pivot.kategorija) && i<j) i++;
    while (cmp_string(niz[j].kategorija,pivot.kategorija)) j--;
    if (i < j) {
       DOGADJAJ pom = niz[i];
       niz[i] = niz[j];
       niz[j] = pom;
    }
  }
  niz[begin] = niz[j];
  niz[j] = pivot;
  return j;
}
void quick_sort1(DOGADJAJ *niz,int begin, int end) {
  if (begin < end) {
    int pivot = split1(niz, begin, end);
    quick_sort(niz, begin, pivot - 1);
    quick_sort(niz, pivot + 1, end);
  }
}
void dodaj(DOGADJAJ *d, FILE* fp)
{
	printf("\nUnesite podatke o novom dogadjaju:\n");
	printf("   Kategorija: "); scanf(" %[^\n]s", d->kategorija);
	//dodaj_kategoriju();
	printf("   Naziv dogadjaja: "); scanf(" %[^\n]s", d->naziv);
	printf("   Opis: "); scanf(" %[^\n]s", d->opis);
	printf("   Lokacija: "); scanf(" %[^\n]s", d->lokacija);
	printf("   Datum: "); scanf("%d.%d.%d.", &d->d.dan, &d->d.mjesec, &d->d.godina);
	printf("   Vrijeme: "); scanf("%d.%d", &d->v.h, &d->v.min);
	if ((fp = fopen("dodaj_dogadjaj.txt", "a")) != EOF)
	{
		fprintf(fp, "\nKategorija: %s\n  Naziv dogadjaja: %s\n  Opis: %s\n  Lokacija: %s\n  Datum: %02d.%02d.%02d.\n  Vrijeme: %02d:%02dh\n",
			d->kategorija, d->naziv, d->opis, d->lokacija, d->d.dan, d->d.mjesec, d->d.godina, d->v.h, d->v.min);
		fclose(fp);
	}
}
void sortiranje2(DOGADJAJ *niz)
{
	int i = 0, j = i + 1;
	if ((niz[i].d.godina > niz[j].d.godina) ||
		(niz[i].d.godina == niz[j].d.godina &&
			niz[i].d.mjesec > niz[j].d.mjesec) ||
			(niz[i].d.godina == niz[j].d.godina &&
				niz[i].d.mjesec == niz[j].d.mjesec &&
				niz[i].d.dan > niz[j].d.dan))
	{
		DOGADJAJ pom = niz[i];
		niz[i] = niz[j];
		niz[j] = pom;
	}
}
int main()
{
	int n;
	DOGADJAJ *niz;
	FILE *fp;
	do
    {
        printf("Unesite broj dogadaja:\n");
        scanf("%d",&n);
    }
    while(n<1);
    niz=(DOGADJAJ*)malloc(n*sizeof(DOGADJAJ));
    int i;
    for(i=0;i<n;i++)
    {
        printf("Podaci o %d. dogadaju:\n",i+1);
        dodaj(niz+i,fp);
    }
    int m;
    do
   {
    printf("\nUnesite redni broj po kom kriterijumu zelite sortirati dogadaje:\n");
    printf("1.Sortiranje dogadaja po lokaciji:\n");
    printf("2.Sortiranje po kriterijumu:\n");
    printf("3.Sortiranje po datumu:\n");
    printf("0.Izlaz\n");
    scanf("%d",&m);
   }
   while(m<1);
   if(m==1)
   {
       printf("\nSortiranje po lokaciji:\n");
       quick_sort(niz,0,n);
   }
   if(m==2)
   {
       printf("\nSortiranje po kriterijumu:\n");
       quick_sort1(niz,0,n);
   }
   if(m==3)
   {
       printf("\nSoritranje po datumu:\n");
       sortiranje2(niz);
   }
    return 0;
}
