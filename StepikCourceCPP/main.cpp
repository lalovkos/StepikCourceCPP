#include <iostream>
#include <functional>
#include <array>

#include "TCPProject.h"
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

void rotate(int a[], unsigned size, unsigned shift) {
    
    for (unsigned step = 0; step < shift; step++) {
        for (unsigned i = 0; i < size - 1; i++) {
            swap(a, i, i + 1);
        }
    }
    
}

char* resize_my(const char* str, unsigned size, unsigned new_size) {

    char* new_str = new char[new_size];
    unsigned min_size = (size < new_size) ? size : new_size;

    for (int i = 0; i < min_size; i++) {
        new_str[i] = str[i];
    }

    delete[] str;

    return new_str;
}

struct TestStruct{
    int a;
    int b;
    double c;
};

void foo(TestStruct &ts, const std::function<int (int x)>func ) {
    ts.a = func(10);
}

void foo(const int& a) {
    int b = 10;
    b = a;
    b = 120;
    std::cout << b << "-s" << std::endl;
}

int main() {

    TCPProject::TCPServer server = TCPProject::TCPServer();
    int i = server.port();
    server.Start();
    return 0;
}