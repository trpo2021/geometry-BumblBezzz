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

int main()
{
    int i;
    char instr[200] = "";
    fgets(instr, 200, stdin);
    for (i = 0; i < 200; i++) {
        instr[i] = tolower(instr[i]);
    }
    chek_circle(instr);
    puts(instr);
    return 0;
}
