#include<iostream>
#include<string>

using namespace std;

// With the following code I collapse
// all subsequent spaces into one.
// It handles all spaces begging and at the end
// Need to compile with -std=c++11
// due to the use of push_back()

int main()
{
        string s;
        s = "    This   is a                  iio         ";
        int j = 0;
        string k;
        char t;

        for (int i = 0; i < s.length();) {
                if (s[i] == ' ') {
                        t = s[i];
                        i++;
                        while (t == s[i]) i++;
                        // we don't want space at the beginning
                        if (!k.empty())
                                k.push_back(' ');
                } else {
                        k.push_back(s[i++]);
                }
        }
        // We don't want space at the end.
        if (k[k.length() - 1] == ' ')
                k.pop_back();

        cout << k;
        return 0;
}
