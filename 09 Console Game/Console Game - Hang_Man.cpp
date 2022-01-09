#include <bits/stdc++.h>
using namespace std;
vector<string> words(1000); int chance;
void import(){
    ifstream english_words; string line;
    english_words.open("words.txt");
    for(int i=0; i<1000; i++){getline(english_words, line); words[i] = line;}
    english_words.close();
}
void print(){
    if(chance == 6) cout << " O \n\\|/\n | \n/ \\" << endl;
    if(chance == 5) cout << " O \n\\|/\n | \n \\" << endl;
    if(chance == 4) cout << " O \n\\|/\n | " << endl;
    if(chance == 3) cout << " O \n\\|/" << endl;
    if(chance == 2) cout << " O \n |/" << endl;
    if(chance == 1) cout << " O \n |" << endl;
    if(chance == 0) cout << " O \nYOU LOSE!" << endl;
}
int main() {
    import();
    srand(time(NULL));
    while(true){
        chance = 6; string word = words[rand()%1000], again; char guess;
        while(word.size()>6) word = words[rand()%1000];
        cout << "Welcome the Hang Man Game!" << endl; print();
        bool ans[word.size()], flag, win; memset(ans, false, sizeof(ans));
        cout << "Guess the word: ";
        for(int i=0; i<word.size(); i++) cout << "_ "; cout << endl;
        cout << word << " <- answer for debug!" << endl;
        while(chance>0){
            cin >> guess; flag = false; win = true;
            for(int i=0; i<word.size(); i++){
                if(word[i]==guess){flag = true;ans[i] = true; cout << guess << " ";}
                else if(ans[i]){cout << word[i] << " ";}
                else{cout << "_ "; win = false;}
            }
            cout << endl;
            if(win){cout << "NICE YOU WIN!" << endl; break;}
            if(!flag){chance--; cout << "No " << guess << " in the word!" << endl;}
            print();
        }
        cout << "PLAY AGAIN? (Y/N)" << endl; cin >> again;
        if(again == "N") break;
    }
    cout << "SEE YOU NEXT TIME!" << endl;
    return 0;
}
