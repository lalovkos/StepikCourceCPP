#include <iostream>
#include "bar.h"
#include "algorithm"

int power(int x, unsigned p) {
    int answer;
    if (p == 0) {
        return 1;
    }
    else {
        answer = x;
        for (int i = 0; i < p; i++) {
            answer = answer * x;
        }
    }

    return answer;
}

int main() 
{
	std::cout << "Hello world!" << std::endl;
	auto i = 3u;
	std::cout << -3 / i * 3 << std::endl;

	unsigned int b = 12314U;
	unsigned long c = 23122UL;
	double d = 3.14;
	float e = 12.41F;
	double f = 3.0E9;
	foo(10);
	return 0;
}