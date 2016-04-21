#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t, n, food, pokemon;
    int i, j, ct;
    cin >> t;
    for (i = 0; i < t; i++) {
        vector<int> v;
        cin >>n;
        ct = 0;
        for (j = 0; j < n; j++) {
            cin >> food >> pokemon;
            v.push_back(food);
            vector<int>::iterator it = std::find(v.begin(), v.end(), pokemon);
            if (it != v.end()) {
                // Erase from vector
                v.erase(it);
            } else {
                ct ++;
            }
        }
        cout << ct << endl;
        v.clear();
    }

    return 0;
}
            
