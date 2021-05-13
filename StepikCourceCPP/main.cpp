#include <iostream>

#include "bar.h"

using namespace std;

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    BarNamespace::ROOTS roots = BarNamespace::FindRoots(a, b, c);

    if (roots.Exist) {
        std::cout << roots.root1 << " " << roots.root2 << std::endl;
    }
    else {
        std::cout << "No real roots" << std::endl;
    }

    return 0;
}