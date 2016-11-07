// Google codejam 2016 problem B

#include<iostream>
#include<string>

using namespace std;

int main()
{
        int t,ct;
        cin >>t;
        string s;
        for (int i = 0; i < t ; ++i) {
                ct=0;
                cin >> s;
                for (int j = s.length() -1; j >= 0; --j) {
                        if (s[j] == '-') {
                                ct++;
                                for (int k = 0; k <= j; ++k) {
                                        s[k] == '+' ? s[k] = '-' : s[k]='+';
                                }
                        }
                }
                cout << "case #" << i+1 << ": " <<ct << endl;
        }
        return 0;
}
