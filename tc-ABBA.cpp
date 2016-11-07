/* 
TopCoder : Problem Statement: 
One day, Jamie noticed that many English words only use the letters A and B. 
Examples of such words include "AB" (short for abdominal), "BAA" (the noise a sheep makes), 
"AA" (a type of lava), and "ABBA" (a Swedish pop sensation).

Inspired by this observation, Jamie created a simple game. 
You are given two s: initial and target. The goal of the game is to find a 
sequence of valid moves that will change initial into target. There are two types of valid moves:

Add the letter A to the end of the string.
Reverse the string and then add the letter B to the end of the string.
Return "Possible" (quotes for clarity) if there is a sequence of valid moves that 
will change initial into target. Otherwise, return "Impossible". 
*/

#include<bits/stdc++.h>

using namespace std;


bool canObtain1(string source, string target, int sa, int sb, int ta, int tb)
{
        bool left = false, right = false;
        if (source == target) {
                return true;
        } else {
                if (sa < ta) {
                        left = canObtain1(source + 'A', target, sa+1, sb, ta, tb);
                }
                if (sb < tb) {
                        reverse(source.begin(), source.end());
                        right = canObtain1(source+'B', target, sa, sb+1, ta, tb);
                }
                return left || right;
        }

}

class ABBA {
        public:
                string canObtain(string source, string target) {
                        int sa = 0, sb = 0, ta = 0, tb = 0;
                        for (char c : source) {
                                c == 'A' ? sa++ : sb++;
                        }
                        for (char c : target) {
                                c == 'A' ? ta++ : tb++;
                        }

                        return canObtain1(source, target, sa, sb, ta, tb) ? "Possible" : "Impossible";
                 }
};

int main()
{
        string source, target;
        cin >> source;
        cin >> target;

        ABBA obj;
        cout << obj.canObtain(source, target);
        return 0;
}
