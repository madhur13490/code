#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cassert>
using namespace std;

bool isPower2(unsigned long int n)
{
        assert(n>0);
        //cout << "true" << n << endl;
        if (!(n & (n - 1))) return true;
        return false;
}

unsigned long int closePower2(unsigned long int n)
{
        int p = log(n) / log(2);
        //cout << pow(2, p);
        return pow(2, p);
}

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        int t;
        bool turn = true;
        unsigned long int n;
        cin >> t;
        assert(isPower2(2));

        for (int i = 0; i < t; ++i) {
                turn = true;
                cin >> n;
                assert(n>0);
                while (n != 1) {
                        if (isPower2(n)) n = n / 2;
                        else {
                                n = n - closePower2(n);
                                //cout << "next" << n << endl;
                        }
                        turn = !turn;
                }

                if (turn) cout << "Richard\n";
                else cout << "Louise\n";
        }
        return 0;
}
