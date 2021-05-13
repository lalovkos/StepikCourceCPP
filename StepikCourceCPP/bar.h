#ifndef BAR_EXT
#define BAR_EXT
namespace BarNamespace
{
    struct ROOTS {
        double root1, root2;
        bool Exist;
    };

    ROOTS FindRoots(int a, int b, int c);

}
#endif 