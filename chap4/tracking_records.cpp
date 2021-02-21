#include <stdlib.h>
#include <iostream>

struct list_node {
    int student_num;
    int grade;
    list_node *next;
};
typedef list_node *student_collection;

void add_record_tail(student_collection &sc, int num, int gr) {
    student_collection node = sc;
    while (node->next != NULL) node = node->next;
    list_node *new_node = new list_node;
    new_node->student_num = num; new_node->grade = gr; new_node->next = NULL;
    node->next = new_node;
}

void add_record_head(student_collection &sc, int num, int gr) {
    list_node *new_node = new list_node;
    new_node->student_num = num; new_node->grade = gr; new_node->next = NULL;
    new_node->next = sc;
    sc = new_node;
}

double average_grade(student_collection sc) {
    int count{0};
    double sum{0};
    list_node *loop_ptr = sc;
    while (loop_ptr != NULL) {
        sum += loop_ptr->grade;
        count++;
        loop_ptr = loop_ptr->next;
    }
    return sum/count;
}

void print_records(student_collection sc) {
    do {
        std::cout << sc->student_num << " ";
        sc = sc->next;
    } while (sc != NULL);
    std::cout << "\n";
}

int main() {
    student_collection sc;
    list_node *node1 = new list_node;
    node1->student_num = 1001; node1->grade = 78;
    list_node *node2 = new list_node;
    node2->student_num = 1002; node2->grade = 93;
    list_node *node3 = new list_node;
    node3->student_num = 1003; node3->grade = 85;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    sc = node1;
    node1 = node2 = node3 = NULL;

    print_records(sc);
    add_record_head(sc, 1004, 100);
    print_records(sc);
    std::cout << "Average Grade: " << average_grade(sc) << "\n";
}