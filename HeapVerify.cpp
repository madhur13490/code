
// Hacky way to include all files!
// Ideally you should include only the reqiuired files
// to avoid compile-time hammer and achieve portability.
#include<bits/stdc++.h>

using namespace std;

// The class MaxheapVerify accepts vector as input
// and verifies if it honors max heap property.

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

// Simple driver routine.
int main()
{

	vector<int> v = {2, 1};

	MaxHeapVerify m(v);

	cout << m.verify();
	
	return 0;
}
