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
    ostatok = (a > b)?(a % b):(b % a);
    if (ostatok == 0) {
        return (a > b)?b:a;
    }
    else {
        return (a > b)?gcd(ostatok, b):gcd(a, ostatok);
    }

}

int main() {
    int x = 10;
    int y = 20;

    int i = 10;

    x = ((i = x*i) * (i));
    

    return x;
}