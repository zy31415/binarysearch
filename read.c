#include <stdio.h>

int main () {
    FILE *fp;

    fp = fopen("source.txt", "rt");

    char c[255];

    fread(c, 1,255,fp);

    printf("Read: %s.\n", c);

    return 0;
}