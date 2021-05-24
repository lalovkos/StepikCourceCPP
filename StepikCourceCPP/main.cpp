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
    
    for (unsigned step = 0; step < shift; step++) {
        for (unsigned i = 0; i < size - 1; i++) {
            swap(a, i, i + 1);
        }
    }
    
}

unsigned strlen_my(const char* str) {
    unsigned len = 0;
    while (*str++) {
        ++len;
    }
    return len;
}

void deleteFirstChars(char* str, const int NFirstToDelete) {
    
    if (NFirstToDelete == 0) {
        return;
    }
 
    unsigned len = strlen_my(str);
    for (unsigned i = 0; i < len - NFirstToDelete; i++) {
        std::cout << str << std::endl;
        std::cout << strlen_my(str) - NFirstToDelete << std::endl;
        str[i] = str[i + NFirstToDelete];
        str[i + NFirstToDelete] = '\0';
    }
}

int strstr_my(const char* text, const char* pattern) {
    
    unsigned patternlength = strlen_my(pattern);
    if (!patternlength) {
        return 0;
    }
    
    unsigned foundlenght = 0;
    unsigned placecount = 0;

    while (*text != '\0') {
         
        for (int i = 0; i < patternlength; i++) {
            
            if (text[foundlenght] == pattern[i]) {
                foundlenght++;
                if (foundlenght == patternlength) {
                    return placecount;
                }
            }
            else {
                foundlenght = 0;
            }
        }
        *++text;
        placecount++;

    }
    
    return (int)-1;
}

int main() {
   
    
    char str1[15] = "";
    char str2[] = "ar";
    
    //deleteFirstChars(str1, 3);
    //deleteFirstChars(str2, 1);
    std::cout << strstr_my(str1, str2) << std::endl;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;


    return 0;
}