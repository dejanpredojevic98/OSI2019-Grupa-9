#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int static br=0;
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
DOGADJAJ* citaj(){
    int n = 5;
    int i = 0;

    DOGADJAJ* niz = (DOGADJAJ*)calloc(n,sizeof(DOGADJAJ));
    DOGADJAJ tmp;

    FILE* file = fopen("dodaj_dogadjaj.txt", "r");
    if(file == NULL)
    {
        printf("Datoteka se nije otvorila");
        return NULL;
    }

    while(fscanf(file,"%s\n%[^\0]s%[^\0]s%[^\0]s%d.%d.%d.%d:%d", tmp.kategorija,tmp.naziv,tmp.opis,tmp.lokacija,&tmp.d.dan,&tmp.d.mjesec,&tmp.d.godina,&tmp.v.h,&tmp.v.min) != -1){
        if(i == n){
            niz = (DOGADJAJ*)realloc(niz,(n*=2)*sizeof(DOGADJAJ));
        }
        niz[i++]=tmp;
        br++;
         printf("%s\n%s %s %s\n %d.%d.%d.\n %d:%dh\n", tmp.kategorija,tmp.naziv,tmp.opis,tmp.lokacija,tmp.d.dan,tmp.d.mjesec,tmp.d.godina,tmp.v.h,tmp.v.min);
    }
    fclose(file);
    return niz;

}
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
void quick_sort1(DOGADJAJ *niz,int begin, int end)
 {
  if (begin < end) {
    int pivot = split1(niz, begin, end);
    quick_sort(niz, begin, pivot - 1);
    quick_sort(niz, pivot + 1, end);
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
  DOGADJAJ *niz=citaj();
  int redni_broj;
  do
   {
    printf("\nUnesite redni broj po kom kriterijumu zelite sortirati dogadaje:\n");
    printf("1.Sortiranje dogadaja po lokaciji:\n");
    printf("2.Sortiranje po kriterijumu:\n");
    printf("3.Sortiranje po datumu:\n");
    printf("0.Izlaz\n");
    scanf("%d",&redni_broj);
   }
   while(redni_broj<1);
   niz=citaj();
  if(redni_broj==1)
  {
     quick_sort(niz,0,br);
  }
  else if(redni_broj==2)
  {
      quick_sort1(niz,0,br);
  }
  else if(redni_broj==3)
  {
      sortiranje2(niz);
  }
  return 0;
}
