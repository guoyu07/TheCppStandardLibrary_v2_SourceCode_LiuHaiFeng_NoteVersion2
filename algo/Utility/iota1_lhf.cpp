// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
using namespace std;

int main()
{
    array<int, 10> coll;
    // Assigns to every element in the range [first,last)
    // successive values of val, as if incremented with ++val
    // after each element is written.
    // C++11�㷨���㷨��������iota��������������������У�
    // ����������Ҫһ���������飬��������е�Ԫ�ض�����
    // ĳһ����ֵ�Ļ���֮�ϵ����ģ���ô��iota���Ժܷ���
    // ���������������
    iota(coll.begin(), coll.end(), 42);

    PRINT_ELEMENTS(coll, "coll: ");
}
