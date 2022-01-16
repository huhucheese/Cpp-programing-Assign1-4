#ifndef ASSIGN2_STUDENT_H
#define ASSIGN2_STUDENT_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory>
#include <vector>

const int SUBJECT_NO = 3;

struct StudentInfo {
    std::string name;
    int scores[SUBJECT_NO];
    int sum;
    double average;

};

std::unique_ptr<StudentInfo> make_student();
void print(const StudentInfo& si);
void print_all(const std::vector<std::unique_ptr<StudentInfo>>& vec);

#endif //ASSIGN2_STUDENT_H
