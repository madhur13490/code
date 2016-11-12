#include<iostream>
#include<map>

// Class Dictionary :
//      This is designed to count the number of
//      occurences of the given data.
//      If the data is coming first time then counter
//      will internally initalize to 1.
//      Else, counter will be incremented.

using namespace std;
template<typename T>
class dictionary {
        public:
                // Insert "data"
                // Return current of copies of the data in dict.
                void printDict();
                int insert(T data);
        private:
                map<T, int> m;
};

template<typename T> int dictionary<T>::insert(T data)
{
        typename map<T, int>::iterator t = m.find(data);
        if (t == m.end()) {
                m[data] = 1;
        } else {
                m[data] += 1;
        }
        return m[data];
}

template<typename T> void dictionary<T>::printDict()
{
        for (auto& t : m) {
                cout << "\"" << t.first << "\" " << "= " << t.second << endl;
        }
}

// Driver
/*
#include"dict.h"

int main()
{
        dictionary<string> d;
        d.insert("madhur");
        d.insert("madhur");
        d.insert("madhur");

        d.printDict();
}*/

