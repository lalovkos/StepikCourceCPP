#include <iostream>
#include "bar.h"
#include "algorithm"

int power(int x, unsigned p) {
    int answer = 1;
    
    if (p) {
        answer = x;
        for (int i = 0; i < p-1; i++) {
            answer = answer * x;
        }
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