#include <iostream>
#include "MathFunc.h"

using namespace std;

int MathFunc::getMax(int n1, int n2) {
    if(n1 >= n2) return n1;
    return n2;
}

int MathFunc::getMax(int *arr, int len) {
    int result = 0;
    for(int i=0; i<len; i++) {
        if(arr[i] >= result) result = arr[i];
    }
    return result;
}

int MathFunc::getMin(int n1, int n2) {
    if(n1 <= n2) return n1;
    return n2;
}

int MathFunc::getMin(int *arr, int len) {
    int result = 99999;
    for(int i=0; i<len; i++) {
        if(arr[i] <= result) result = arr[i];
    }
    return result;
}
