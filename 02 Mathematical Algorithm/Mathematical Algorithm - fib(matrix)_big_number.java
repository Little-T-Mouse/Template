#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
typedef long long ll;
const ll mod = ll(1e9 + 7);
const ll pisano = 2000000016LL;
class matrixs{public: ll matrix[2][2];};
matrixs mul(matrixs x_matrix, matrixs y_matrix){
    matrixs product_matrix; for(int i=0; i<2; i++){for(int j=0; j<2; j++){product_matrix.matrix[i][j]=0;}}
    for(int i=0; i<2; i++){for(int j=0; j<2; j++){for(int k=0; k<2; k++){product_matrix.matrix[i][j]+=x_matrix.matrix[i][k]*y_matrix.matrix[k][j];}product_matrix.matrix[i][j]%=mod;}}
    return product_matrix;
}
matrixs expo(matrixs base_matrix, ll pow){
    matrixs exp_matrix;
    for(int i=0; i<2; i++){for(ll j=0; j<2; j++){exp_matrix.matrix[i][j]=(i==j);}} for(ll i=0; (1LL<<i)<=pow; i++){if((1LL<<i)&pow)exp_matrix=mul(exp_matrix,base_matrix); base_matrix=mul(base_matrix,base_matrix);}
    return exp_matrix;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string N; cin >> N; reverse(all(N)); ll total = 0, digit = 1; matrixs base_matrix, exp_matrix;
    for(char ch: N){total=(total+(ch-'0')*digit)%pisano; digit=digit*10%pisano;}
    if(total==0){cout<<0<<endl;return 0;} if(total==1){cout<<1<<endl; return 0;} total--; if(total<0){total+=pisano;}
    base_matrix.matrix[0][0]=1;base_matrix.matrix[0][1]=1;base_matrix.matrix[1][0]=1;base_matrix.matrix[1][1]=0; // {{1, 1}, {1, 0}}
    exp_matrix = expo(base_matrix, total);
    cout << exp_matrix.matrix[0][0]%mod << endl;
    return 0;
}
