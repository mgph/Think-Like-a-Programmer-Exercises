#include <iostream>
#include <string>
using std::cout;
using std::string;

struct Student {
    int grade;
    int studentID;
    string name;
};

int compare_grades(const void* fA, const void* fB) {
    Student* a = (Student*)fA;
    Student* b = (Student*)fB;
    return b->grade - a->grade;
}

int compare_IDs(const void* fA, const void* fB) {
    Student* a = (Student*)fA;
    Student* b = (Student*)fB;
    return b->studentID - a->studentID;
}

int main() {
    const int ARRAY_SIZE = 10;
    Student studentArray[ARRAY_SIZE] {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    int highest_index = 0;
    for (int i{0}; i<ARRAY_SIZE; i++) {
        if (studentArray[i].grade > studentArray[highest_index].grade)
            highest_index = i; 
    }
    cout << "Highest grade: " << studentArray[highest_index].grade << "\n";
    
    qsort(studentArray, ARRAY_SIZE, sizeof(Student), compare_grades);
    for (auto i : studentArray) {
        cout << i.grade << " " << i.studentID << " " << i.name << "\n";
    }

    qsort(studentArray, ARRAY_SIZE, sizeof(Student), compare_IDs);
    for (auto i : studentArray) {
        cout << i.grade << " " << i.studentID << " " << i.name << "\n";
    }
}

