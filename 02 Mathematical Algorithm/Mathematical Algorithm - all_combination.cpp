#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int msk=1; msk<(1<<n); msk++){
        for(int i=0; i<n; i++){
            if(msk >> i & 1){
                cout << (i+1) << " ";
            }
        }
        cout << endl;
    }
}
