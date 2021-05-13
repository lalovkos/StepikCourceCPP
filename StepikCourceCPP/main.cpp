#include <iostream>

using namespace std;

int main()
{
    int p;
    std::cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << x + y << std::endl;
    }

    return 0;
}