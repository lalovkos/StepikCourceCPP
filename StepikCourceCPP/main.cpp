#include <iostream>
#include "bar.h"
#include "algorithm"

int power(int x, unsigned p) {
    int answer = 1;
    
    if (p) {
        answer = x;
        answer = (p & 1) ? x * power(x, p & ~1) : power(x * x, p >> 1);
    }

    return answer;
}

int main() {
    int x = 1;
    unsigned p = 10;
    std::cin >> x >> p;
    std::cout << power(x, p) << std::endl;
	return 0;
}