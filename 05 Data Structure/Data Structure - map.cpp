#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp1; // unordered map
map<string, int> mp2;   //sorted
int main(){
    mp1["hello"] = 5;
    mp1["c++"] = 10;
    for(pair<string, int> x : mp1)
        cout << "( " << x.first << " " << x.second << "), ";
    cout << endl;
    //check if map contains a key or not
    if(mp1.count("hello")) { // count the num of hello in the map
        cout << "yes\n";
    }
    if(mp1.find("hello") != mp1.end()) {  //find the key's iterator
        cout << "yes\n";
    }
    for(pair<string, int> x : mp1)
        cout << "( " << x.first << " " << x.second << "), ";
    cout << endl;
}
