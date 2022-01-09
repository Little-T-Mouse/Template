bool isAllUpper(string S){
    for(char ch: S){
        if(!isupper(ch)) return false;
    }
    return true;
}
