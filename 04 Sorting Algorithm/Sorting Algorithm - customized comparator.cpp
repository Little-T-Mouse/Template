#include <bits/stdc++.h>
using namespace std;
class Student {
public:
    string name;
    int grade, age;
    double score;
    Student(){};
    Student(string name, int grade, int age, double score){
        this->name = name;  this->grade = grade; this->age = age; this->score = score;
    }
};
bool agecmp(Student a, Student b){// return true (a before b), false (a after b)
    if(a.age < b.age) return true;
    // if(a.age == b.age) return(a.grade < b.grade); // Additional sort
    return false;
}
int main(){
    int n; vector<Student> vec;
    cin >> n;
    for(int i=0; i<n; i++){
        string name; int grade, age; double score;
        cin >> name >> grade >> age >> score;
        vec.push_back(Student(name, grade, age, score));
    }
    sort(vec.begin(), vec.end(), agecmp);
    for(Student x : vec) {
        cout << "name:" << x.name << " grade: " << x.grade << " age:" << x.age << " score:" << x.score << endl;
    }
}
/*
3
Alice 10 15 96.5
Bob 10 14 93.8
Calvin 9 14 97.5
*/
