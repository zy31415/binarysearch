//
// Created by Yang Zhang on 2021-06-17.
//

#include <stdio.h>
#include <stdlib.h>
#include "../seq_search.h"

struct entry {
    long index, value;
};

int main(const int argc, const char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Take 2 arguments!");
        return -1;
    }

    const char *filename = argv[1];
    char *eptr;
    long target = strtol(argv[2], &eptr,10);

    printf("Target: %ld\n", target);

    FILE *fid;

    if ((fid = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return -1;
    }

    struct entry row;

    long found_index = -1;

    long item_searched = 0;
    while(fread(&row, sizeof(struct entry), 1, fid) == 1) {
        item_searched ++;

        if (target < row.value ) {
            break;
        }

        if (target == row.value) {
            found_index = row.index;
            break;
        }


    }
    fclose(fid);

    if (found_index >= 0) {
        printf("Find target - index: %ld. Items searched: %ld\n", found_index, item_searched);
    } else {
        printf("Target *NOT* found. Items searched: %ld\n", item_searched);
    }

    return 0;
}