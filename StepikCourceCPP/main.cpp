#include <iostream>

#include "bar.h"

using namespace std;

int main()
{
    
    char c = '\0';
    bool FirstEnter = true;
    while (std::cin.get(c)) {
        
        if ( (c != ' ') ) {
            std::cout << c;
            FirstEnter = true;
        }
        else if (FirstEnter) {
            std::cout << c;
            FirstEnter = false;
        }
    }

    return 0;
}