#include "set.h"

Set::Set(const Set &s) : len(s.len), arr(new double[s.len]) {
    for (int i = 0; i < len; i++) {
        arr[i] = s.arr[i];
    }
}

void Set::uni(const Set& s1, const Set& s2) {
    double *temp = new double[s1.len + s2.len];

    int i = 0, j = 0, k = 0;
    while (i < s1.len && j < s2.len) {
        if (s1.arr[i] < s2.arr[j]) {
            temp[k++] = s1.arr[i++];
        }
        else if (s1.arr[i] > s2.arr[j]) {
            temp[k++] = s2.arr[j++];
        }
        else {
            temp[k++] = s1.arr[i++];
            j++;
        }
    }
    while (i < s1.len) temp[k++] = s1.arr[i++];
    while (j < s2.len) temp[k++] = s2.arr[j++];

    delete [] arr;
    arr = temp;
    len = k;
}

void Set::intersection(const Set& s1, const Set& s2) {
    int max = s1.len < s2.len ? s1.len : s2.len;
    double *temp = new double[max];

    int i = 0, j = 0, k = 0;
    while (i < s1.len && j < s2.len) {
        if (s1.arr[i] < s2.arr[j]) i++;
        else if (s1.arr[i] > s2.arr[j]) j++;
        else {
            temp[k++] = s1.arr[i++];
            j++;
        }
    }

    delete [] arr;
    arr = temp;
    len = k;
}

void Set::diff(const Set& s1, const Set& s2) {
    double *temp = new double[s1.len];

    int i = 0, j = 0, k = 0;
    while (i < s1.len && j < s2.len) {
        if (s1.arr[i] < s2.arr[j]) {
            temp[k++] = s1.arr[i++];
        }
        else if (s1.arr[i] > s2.arr[j]) j++;
        else {i++; j++;}
    }
    while (i < s1.len) temp[k++] = s1.arr[i++];

    delete [] arr;
    arr = temp;
    len = k;
}

