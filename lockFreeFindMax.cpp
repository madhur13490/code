#include<bits/stdc++.h>

// How do you find maximum of n integers
// in C++ when you don't have std::atomic::max?
// Here is a lock-free solution using CAS loop.

using namespace std;

atomic<int> maxVar(0);

void worker(int i)
{
        int temp;
        bool b = false;
        do {
                temp = maxVar;
                if (temp < i)
                        // See if I can swap my value.
                        b = maxVar.compare_exchange_weak(temp, i);
                else
                        // My val is anyway less, why should I go ahead? backout!
                        break;
        } while (!b);
}


int main()
{
        vector<std::thread> v;

        for (int i = 0; i < 10; ++i)
                v.push_back(std::thread(worker, i * 3));

        for (int i = 0; i < 10; ++i)
                v[i].join();

        cout << maxVar;
        return 0;
}

// Ouput should be 27
