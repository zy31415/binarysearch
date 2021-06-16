//
// Created by Yang Zhang on 2021-06-15.
//

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