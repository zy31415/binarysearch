//
// Created by Yang Zhang on 2021-06-12.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PageSize 1024


void print_page(char page[PageSize]) {
    for(int i=0; i < PageSize && page[i] != EOF; i++) {
        printf("%c", page[i]);
    }
}

long read_page(FILE *fid, char page[PageSize]) {
    memset(page, EOF, PageSize);

    // Read a page:
    fread(page, 1, PageSize, fid);

    return ftell(fid);
}

bool bs(FILE *fid) {
    char page[PageSize];

    long pos = read_page(fid, page);

    print_page(page);

    printf("Pos: %ld", pos);

    return true;
}




int main() {

    FILE *fp;

    if ((fp = fopen("source.txt", "rt")) == NULL) {
        printf("Error! File cannot be opened.");
        exit(1);
    };

    bs(fp);

    if (feof(fp))
        printf("End of File!");

    fclose(fp);

    return 0;
}

