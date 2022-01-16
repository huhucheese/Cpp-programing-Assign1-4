#include "Student.h"
#include <iostream>

using namespace std;

unique_ptr<StudentInfo> make_student(){
    unique_ptr<StudentInfo> st(new StudentInfo);
    int sum = 0;
    double average;

    cin >> st -> name;

    for(int i = 0; i < 3; i++){
        cin >> st -> scores[i];
        sum += st -> scores[i];
    }

    average = sum / 3.0;
    st -> sum = sum;
    st -> average = average;

    return st;
}

void print(const StudentInfo& si) {
    cout << si.name << "\t";
    for(auto it : si.scores){
        cout << it << "\t";
    }
    cout << si.sum << "\t" << si.average <<endl;
}

void print_all(const vector<unique_ptr<StudentInfo>>& vec) {
    for(auto& item : vec){
        print(*item);
    }
}
