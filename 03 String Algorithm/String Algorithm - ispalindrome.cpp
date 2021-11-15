bool ispalindrome(string S){
    if(S.length() < 2) return true;
    if(S[0]!=S[S.length()-1]) return false;
    return isPalindrome(S.substr(1, S.length()-2));
}
