
#include<bits/stdc++.h>

using namespace std;

template<typename T>
void print(T& m) {
	for (auto i : m) {
		cout << i.first << " " << i.second << endl;
	}
}


template<typename T>
T myMapIntersect(T& left, T& right)
{
	T result;
        for (auto i : left) { 
		//cout << i.second;
		auto t = right.find(i.first);
		if (t != right.end()) {
			// found the element
			result[i.first] = abs(i.second - t->second);
		} else {
			// Not found
			result[i.first] = i.second;
		}
	}

	for (auto i : right) {
		auto t = left.find(i.first);
		if (t == left.end()) 
			result[i.first] = i.second;
	}

	cout << "result \n";
	print<T>(result);

	return result;
}

int minDeletions(string& s1, string &s2)
{
	map<char, int> m1, m2;
	int sum = 0;
	for (auto i : s1) {
		// Not found case and found
		auto t = m1.find(i);
		t == m1.end() ? m1[i] = 1 : m1[i] = t->second + 1;
	}
	for (auto i : s2) {
		// Not found case and found
		auto t = m2.find(i);
		t == m2.end() ? m2[i] = 1 : m2[i] = t->second + 1;
	
	} 

	cout << "m1\n";
	print<map<char, int> >(m1);

	cout << "m2\n";
	print<map<char, int> >(m2);
	auto result = myMapIntersect<map<char, int > > (m1, m2);
	
	for (auto i : result) {
		sum += i.second;
	}
	return sum;
}


int main()
{

	string s1, s2;
	cin >> s1 >> s2;

	 //myMapIntersect< map<string,int> >(m, m);
	cout << "min dele" << minDeletions(s1, s2);
	
	
	return 0;
}
