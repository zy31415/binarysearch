//
// Created by Yang Zhang on 2021-06-17.
//

#include <stdio.h>
#include <stdlib.h>
#include "../seq_search.h"

struct entry {
    long index, value;
};


long count_items(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    return ftell(fp) / (long) sizeof (struct entry);
}

long get_item(FILE *fp, long n) {
    long entry_size = (long) sizeof (struct entry);
    struct entry row;
    fseek(fp, entry_size * n, SEEK_SET);
    fread(&row, entry_size, 1, fp);
    return row.value;
}


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

    long N = count_items(fid);

    printf("Total items: %ld\n", N);

    // binary search:
    long s = 0, t = N-1;

    if (target < get_item(fid, s)) {
        printf("Not found.");
        return 0;
    }

    if (target > get_item(fid, t)) {
        printf("Not found.");
        return 0;
    }

    while( s <= t) {
        long m = (s + t)/2;

        long v = get_item(fid, m);

        if (v == target) {
            printf("Found target - index: %ld\n", m);
            return 0;
        }

        if ( v < target) {
            s = m + 1;
        } else {
            t = m - 1;
        }
    }

    fclose(fid);

    printf("Target *NOT* found.");

    return 0;
}