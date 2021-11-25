#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
typedef vector<int> vi;

vi same_opration(vi A, vi B){
    while(A.size() < B.size()) A.push_back(0); while(B.size() < A.size()) B.push_back(0); vi ans(A.size()+5); fill(all(ans),0);
    for(int i=0; i<A.size(); i++){ans[i] = A[i]+B[i];} // Adding without carry
    for(int i=0; i<ans.size(); i++){int carry=ans[i]/10; if(ans.size()>i+1){ans[i]%=10; ans[i+1]+=carry;}}
    while(!ans.empty()&&ans.back() == 0)ans.pop_back(); if(ans.empty())ans.push_back(0);
    return ans;
}
vi dif_opration(vi A, vi B){
    while(A.size() < B.size()) A.push_back(0); while(B.size() < A.size()) B.push_back(0); vi ans(A.size()+5); fill(all(ans),0);
    for(int i=0; i<A.size(); i++){ans[i]+=A[i]-B[i]; if(ans[i]<0){ans[i]+=10;ans[i+1]--;}}
    for(int i=0; i<ans.size(); i++){int carry=ans[i]/10; if(ans.size()>i+1){ans[i]%=10; ans[i+1]+=carry;}}
    while(!ans.empty()&&ans.back() == 0)ans.pop_back(); if(ans.empty())ans.push_back(0);
    return ans;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N; string n1, n2; bool p1, p2; // n: number. p: positive.
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> n1 >> n2;
        vi A, B; p1 = (n1[0]=='-'); p2 = (n2[0]=='-');
        for(int j=0; j<n1.size(); j++){if(n1[j]!='-')A.pb(n1[j]-'0');}
        for(int j=0; j<n2.size(); j++){if(n2[j]!='-')B.pb(n2[j]-'0');}
        reverse(all(A)); reverse(all(B));
        while(!A.empty()&&A.back()==0)A.pop_back(); while(!B.empty()&&B.back()==0)B.pop_back(); // WHY!!! WHY NO POP FRONT!!!
        reverse(all(A)); reverse(all(B));
        if(A.empty())A.push_back(0); if(B.empty())B.push_back(0);
        if(B.size()>A.size()||(B.size()==A.size()&&B>A)){swap(A,B);swap(p1,p2);} // ABS(A) > ABS(B)
        reverse(all(A)); reverse(all(B));
        if(!p1&&!p2){ // both positive
            vi ans = same_opration(A, B); reverse(all(ans)); for(int i=0; i<ans.size(); i++) cout << ans[i]; cout << "\n";
        }
        else if(p1&&!p2){ // number 1 is negative
            vi ans = dif_opration(A, B); reverse(all(ans)); if(ans[0]!=0)cout<<'-'; for(int i=0; i<ans.size(); i++) cout << ans[i]; cout << "\n";
        }
        else if(!p1&&p2){ // number 2 is negative
            vi ans = dif_opration(A, B); reverse(all(ans)); for(int i=0; i<ans.size(); i++) cout << ans[i]; cout << "\n";
        }
        else if(p1&&p2){ // both negative
            vi ans = same_opration(A, B); reverse(all(ans)); if(ans[0]!=0)cout<<'-'; for(int i=0; i<ans.size(); i++) cout << ans[i]; cout << "\n";
        }
    }
    return 0;
}
