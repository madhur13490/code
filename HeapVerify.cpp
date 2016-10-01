
#include<bits/stdc++.h>

using namespace std;

class MaxHeapVerify {
	private:
		vector<int> internalVect; 

		int getParent(int i) {
			return floor(i/2);
		}

		int getLeftChildIndex(int i) {
			return 2 * i + 1;
		}

		int getRightChildIndex(int i) {
			return 2 * i + 2;
		}

		bool isLeftWithinBound(int i) {
			return getLeftChildIndex(i) < internalVect.size();
		}

		bool isRightWithinBound(int i) {
			return getLeftChildIndex(i) < internalVect.size();
		}

		
	public:
		explicit MaxHeapVerify(vector<int>& v) : internalVect(v) {}
		
		bool verify(int i = 0) {
			bool temp = true, isLeftOk = true, isRightOk = true, isLocalOk = true;

			if (i >= internalVect.size() - 1)
				assert("Error");

			if (isLeftWithinBound(i)) 
				isLeftOk = verify(getLeftChildIndex(i));

			if (isRightWithinBound(i))
				isRightOk = verify(getRightChildIndex(i));

			if (isLeftWithinBound(i)) 
				temp = internalVect[i] > internalVect[getLeftChildIndex(i)];

			if (isRightWithinBound(i))
				isLocalOk = temp & (internalVect[i] > internalVect[getRightChildIndex(i)]);

			return isLeftOk && isRightOk && isLocalOk;

		}
};

int main()
{

	vector<int> v = {2, 1};

	MaxHeapVerify m(v);

	cout << m.verify();
	
	return 0;
}
