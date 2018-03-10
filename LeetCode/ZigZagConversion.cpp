#include "ComonDef.h"

NAMESPACE_ANONYMOUS_BEGIN()
/*
0                  14                     28
1               13 15                  27
2             12   16              26
3          11      17           25
4        10        18        24
5      9           19     23
6   8              20  22
7                  21

��iΪ�к�,jΪ���еĵڼ�������,�ж���ÿһ�е��ַ���ԭ�ַ����е�λ��,��
gap = (row - 1) * 2; //14
f(i,j) = i + j * gap;			(i==0 ���� i == row -1)
       = i + (j+1)/2 * gap		(i>0 �� i < row -1��jΪż��)
	   = (j+1)/2 * gap -i		(i>0 �� i < row -1��jΪ����)
*/
class Solution {
public:
	void fillFirstAndLast(string const &src, string&dest, int &newIndex, int const base, int const gap) {
		int index = base;
		int const size = src.size();
		while (index < size) {
			dest[newIndex++] = src[index];
			index += gap;
		}
	}
	string convert(string s, int numRows) {
		int const size = s.size();
		if (numRows == 1 || size <= numRows) {
			return s;
		}
		string ret(size, ' ');
		int newIndex = 0;
		int const gap = (numRows - 1) * 2;
		fillFirstAndLast(s, ret, newIndex, 0, gap);
		int lastIndex = numRows - 1;
		for (int i = 1; i < lastIndex; i++) {
			int index = i;
			bool odd = true;
			int base = lastIndex * 2;
			while (index < size) {
				ret[newIndex++] = s[index];
				if (odd) {
					index = base - i;
				} else {
					index = base + i;
					base += gap;
				}
				odd = !odd;
			}
		}
		fillFirstAndLast(s, ret, newIndex, lastIndex, gap);
		return ret;
	}
};

NAMESPACE_ANONYMOUS_END()

void testZigZagConversion(){
	Solution sln;
	cout << sln.convert("PAYPALISHIRING",9) << endl;
}