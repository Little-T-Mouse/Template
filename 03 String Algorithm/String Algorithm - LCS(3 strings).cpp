#include<bits/stdc++.h>
using namespace std;

string X = "Little_Mouse";
string Y = "Little_Bad_English_Mouse";
string Z = "Mouse_Little";
int dp[100][100][100];
int LCS(int i, int j,int k){
    if(i==-1||j==-1||k==-1) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(X[i]==Y[j] && Y[j]==Z[k])
        return dp[i][j][k] = 1+LCS(i-1,j-1,k-1);
    else
        return dp[i][j][k] = max(max(LCS(i-1,j,k), LCS(i,j-1,k)),LCS(i,j,k-1));
}

int main(){
    memset(dp, -1,sizeof(dp));
    cout << "Length of LCS is " << LCS(X.length()-1,Y.length()-1,Z.length()-1);
}
