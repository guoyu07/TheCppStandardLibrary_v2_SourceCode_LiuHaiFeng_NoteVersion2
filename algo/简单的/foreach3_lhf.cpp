// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
using namespace std;

class MeanValue {
private:
	long num;	// Ԫ�صĸ���
	long sum;	// ����Ԫ��ֵ�ĺ�
public:
	MeanValue() : num(0), sum(0) {
		cout << "MeanValue() constructor" << endl;
	}

	MeanValue(int num) : sum(0) {
		this->num = num;
		cout << "MeanValue(int num) constructor" << endl;
	}

	void operator() (int elem) {
		++num;
		sum += elem;
	}

	operator double() {
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll, 1, 8);
	PRINT_ELEMENTS(coll);

	MeanValue mvalue;
	MeanValue mvalue2(2);
	// for_eachִ�н�����᷵��һ��"MeanValue"���ʵ��
	// ���ʵ������״̬��, �����������for_each()��������
	// ��״̬

#if 1

	mvalue = for_each(coll.begin(), coll.end(), mvalue);
	mvalue2 = for_each(coll.begin(), coll.end(), mvalue2);
#else
	// mvalue = for_each(coll.begin(), coll.end(), MeanValue()); �ȼ������´���:
	// MeanValue tmp;
	// mvalue = for_each(coll.begin(), coll.end(), tmp);

	mvalue = for_each(coll.begin(), coll.end(), MeanValue());
	mvalue2 = for_each(coll.begin(), coll.end(), MeanValue(2));
#endif

	// mvalue��һ����ʵ��, ��������������"operator double()",
	// ����mvalueִ�е�double��ת��ʱ, ���ص�"operator double()"
	// �ķ���������(����ƽ��ֵ)
	double mv = mvalue;
	cout << "mean value: " << mv << endl;

	double mv2 = mvalue2;
	cout << "mean value2: " << mv2 << endl;
}