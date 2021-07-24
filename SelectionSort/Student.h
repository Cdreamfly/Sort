//
// Created by cheng on 2021/7/24.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {

    string name;
    int score;

    bool operator<(const Student &student) {
        return score != student.score ? score > student.score : name < student.name;
    }

    friend ostream &operator<<(ostream &os, Student &student) {
        os << student.name << " " << student.score << endl;
        return os;
    }

};

#endif //SELECTIONSORT_STUDENT_H
