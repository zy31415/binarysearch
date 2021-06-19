//
// Created by Yang Zhang on 2021-06-17.
//

#include <stdio.h>
#include <stdlib.h>

struct entry {
    long index, value;
};

int random_step() {
    return rand() % 5 + 1;
}

int main() {
    FILE * fid = fopen("data.bin", "wb");

    long n = 125000000L;

    long pre = 0;

    for (long i = 0; i<n; i++) {
        struct entry r;
        r.index = i;
        r.value = pre + random_step();
        pre = r.value;
        fwrite(&r, sizeof(struct entry), 1, fid);
    }

    printf("The final value: %ld", pre);

    fclose(fid);

    return 0;
}