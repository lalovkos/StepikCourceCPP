#include <iostream>

#include "bar.h"


int log(int k) {
    int p = -1;
    do {
        k >>= 1;
        p++;
    } while (k);
    return p;
}

unsigned gcd(unsigned a, unsigned b) {

    unsigned ostatok;
    ostatok = (a > b) ? (a % b) : (b % a);
    if (ostatok == 0) {
        return (a > b) ? b : a;
    }
    else {
        return (a > b) ? gcd(ostatok, b) : gcd(a, ostatok);
    }

}

void WriteInConsoleFromLast() {
    
    int new_c;
    std::cin >> new_c;
    if (new_c != 0) {
        WriteInConsoleFromLast();
        std::cout << new_c << ' ';
    }
   
}

void swap(int a[], int pos1, int pos2) {
    
    a[pos1] = a[pos1] + a[pos2];
    a[pos2] = a[pos1] - a[pos2];
    a[pos1] = a[pos1] - a[pos2];

}

void rotate(int a[], unsigned size, int shift) {
    
    for (int step = 0; step < shift; step++) {
        for (int i = 0; i < size - 1; i++) {
            swap(a, i, i + 1);
        }
    }
    
}

int main() {

    int a[] = {1,2,3,4,5,6,7,8,9};
    rotate(a,9,4);
    for (int i = 0; i < 9; i++) {

        std::cout << a[i];
    
    }

    return 0;
}