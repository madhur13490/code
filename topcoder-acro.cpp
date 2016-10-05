// Print acronym

#include<bits/stdc++.h>

using namespace std;

int main()
{
        string s;

        std::getline(cin, s);

        cout << s[0];

        for (std::string::iterator it = s.begin() + 1; it != s.end(); ++it) {
                if (*it == ' ' && (it + 1) != s.end()) {
                        cout << *(it + 1);
                } else {
                        continue;
                }
        }


        return 0;
}
