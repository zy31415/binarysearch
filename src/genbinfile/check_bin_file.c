//
// Created by Yang Zhang on 2021-06-18.
//

#include <stdio.h>

struct entry {
    long index, value;
};

int main(const int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Number of arguments has to be 1.");
        return -1;
    }

    const char *fn = argv[1];
    FILE *fid;

    if ((fid = fopen(fn,"rb")) == NULL) {
        fprintf(stderr, "Cannot open file: %s", fn);
        return -1;
    }

    struct entry pre, cur;

    if ((fread(&pre, sizeof (struct entry), 1, fid) != 1)) {
        fprintf(stderr, "Reading error. empty file?\n");
    }

    int nitems = 0;

    while(fread(&cur, sizeof(struct entry), 1, fid) == 1) {
        if (cur.index != pre.index + 1) {
            printf("Row %ld: messed up order.\n", cur.index);
        }
        if (cur.value < pre.value) {
            printf("Row %ld: Wrong value order!\n", cur.index);
        }
        // copy
        pre = cur;
        nitems ++;
    }

    printf("I have checked %d items.\n", nitems);

    return 0;
}