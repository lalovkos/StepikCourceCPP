
#include "bar.h"

namespace BarNamespace
{
    ROOTS FindRoots(int a, int b, int c) {
        ROOTS answer;
        //��������� �������, � ������������� �������� ����� �����, 
        if ((b * b - 4 * a * c) >= 0) //���� ������������ ������ ��� ����� 0
        {
            double temp = sqrt(b * b - 4 * a * c);
            answer.root1 = (-1 * b + temp) / (2 * a);
            answer.root2 = (-1 * b - temp) / (2 * a);
            answer.Exist = true;
        }
        else
        {
            answer.root1 = 0;
            answer.root2 = 0;
            answer.Exist = false;
        }
        return answer;
    }

}