// Google code jam 2016 problem A 


#include<cmath>
#include<set>
#include<iostream>
std::set<int> s;
void bookkeep(long int n)
{


        while(n!=0){
                s.insert(n%10);
                n= n/10;
        }
}

using namespace std;
int main()
{
        int t,n,j,t1;
        cin >>t;
        for (int i=0; i<t; ++i)
        {
        cin >> n;

        int temp = log10(n);
        if(n > 1 && pow(10,temp) == n) {
                cout << "case #" << i+1 << ": " << 9*n <<endl;
                continue;
        }

        if(!n) { cout << "case #" << i+1 << ": " << "INSOMNIA\n"; continue;}

        j=1;
                while(s.size() != 10) {
                        t1 = n*j;
                        bookkeep(t1);

                        ++j;
                        //cout << "en";
                }
                cout << "case #" << i+1 << ": " << t1 << endl;
                s.clear();
        }
        return 0;
}
