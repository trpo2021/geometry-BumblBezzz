#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void chek_circle(char* string)
{
    char cir[] = "circle";
    if (memcmp(string, cir, 6) != 0) {
        printf("Error: expected circle\n");
        exit(0);
    }
    char cir_2[] = "circle(";
    if (memcmp(string, cir_2, 7) != 0) {
        printf("Error: expected (\n");
        exit(0);
    }
}
void chek_digit(char* str, char* mcoord, char* mrad)
{
    int i = 0;
    char copystr[100] = "";
    int count = 0;
    strncpy(copystr, str, 100);
    char del[] = "(,)";
    char* object1 = strtok(str, del);
    while (object1 != NULL) {
        object1 = strtok(NULL, del);
        count++;
    }
    if ((count - 1) == 2) {
        printf("Error: expected ,\n");
        exit(0);
    }
    if ((count - 1) != 3) {
        printf("Error\n");
        exit(0);
    }
    char* object2 = strtok(copystr, "(");
    object2 = strtok(NULL, ",");
    strncpy(mcoord, object2, 50);
    object2 = strtok(NULL, ")");
    strncpy(mrad, object2, 50);
    if (strchr(mcoord, ' ') == NULL) {
        printf("Error: expected coordinatehh\n");
        exit(0);
    }
    for (i = 0; i < strlen(mcoord); i++) {
        if ((isdigit(mcoord[i]) == 0) && (mcoord[i] != ' ')
            && (mcoord[i] != '.') && (mcoord[i] != '-')) {
            printf("Error: expected coordinate\n");
            exit(0);
        }
    }
    for (i = 0; i < strlen(mrad); i++) {
        if ((isdigit(mrad[i]) == 0) && (mrad[i] != '.') && (mrad[i] != ' ')
            && (mrad[i] != '-')) {
            printf("Error: expected digit\n");
            exit(0);
        }
    }
    // puts(mcoord);
    // puts(mrad);
}
int main()
{
    char mcoord[50] = "";
    char mrad[50] = "";
    int i;
    char instr[100] = "";
    fgets(instr, 100, stdin);
    char out[100] = "";
    strncpy(out, instr, 100);
    for (i = 0; i < strlen(instr); i++) {
        instr[i] = tolower(instr[i]);
    }
    chek_circle(instr);
    chek_digit(instr, mcoord, mrad);
    puts(out);
    return 0;
}
