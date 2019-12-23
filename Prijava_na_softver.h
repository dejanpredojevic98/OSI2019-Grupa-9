#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char user_name[15];
    char password[11];
}USER_INFO;
char* insert_password()
{
	char* password;
    password = (char*)calloc(15,sizeof(char));
	int p = 0;
    do {
        password[p] = _getch();
        if (password[p] != '\r') {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');
    if (p != 15)
        password = (char*)realloc(password, p * sizeof(char));
    password[p - 1] = '\0';
    return password;
}
void check_info(const char* file_name,char* user_name, char* password)
{
    FILE* fp;
    USER_INFO user;
    int p = 0, x=0;
    if(fp=fopen(file_name,"r"))
    {

        while (fscanf(fp, "%s %s\n", user.user_name, user.password) == 2)
        {
            x++;
            if (x == 1)
                continue;
            if (((strcmp(user.user_name, user_name) == 0) && strcmp(user.password, password) == 0))
            {
                printf("\npodaci su tacni\n");
                p++;
                break;
            }
            else
                continue;
        }
        
    }
    else
        printf("Greska prilikom otvaranja datoteke.");
    if (p == 0)
        printf("\nnetacni podaci\n");
}