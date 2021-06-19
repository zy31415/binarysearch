//
// Created by Yang Zhang on 2021-06-15.
//

#include <string.h>

int binary_search(const int* arr, int N, int target) {

    int s = 0;
    int t = N -1;

    if (target < arr[s])
        return -1;

    if (target > arr[t])
        return -1;

    while (s <= t) {
        int m = ( s + t ) /2;

        if (target == arr[m])
            return m;

        if (target < arr[m]) {
            t = m -1;
        } else {
            s = m +1;
        }
    }

    return -1;

}

int binary_search_str(const char** arr, int N, const char * target) {
    int s = 0;
    int t = N-1;

    if (strcmp(target, arr[s]) < 0)
        return -1;

    if (strcmp(target, arr[t]) > 0)
        return -1;

    while (s <= t) {
        int m = ( s + t ) / 2;

        if (strcmp(target, arr[m]) == 0)
            return m;

        if (strcmp(target, arr[m]) < 0 ) {
            t = m -1;
        } else {
            s = m +1;
        }
    }

    return -1;
}