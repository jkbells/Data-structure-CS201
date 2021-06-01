#include<iostream>
#include<set>
using namespace std;


int main()
{
    // set<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(2);
    // s.insert(3);
    // int i;
    // for (auto i : s);
    // cout <<i<< " ";
    //    cout << "\n";
    // cout << s.size() << endl;
    // s.erase(2);
    // for (auto i : s) 
    //   cout << i << " ";
    // cout << "\n";

    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    int i;
    for (auto i : s);
    cout <<i<< " ";
       cout << "\n";
    cout << s.size() << endl;
    s.erase(s.find(3));
    for (auto i : s) 
      cout << i << " ";
    cout << "\n";


    return 0;
}