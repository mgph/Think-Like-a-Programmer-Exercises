#include <iostream>
using std::cout;

typedef char * array_string;

char character_at(array_string s, int position) {
    return s[position];
}

int length(array_string s) {
    int length{0};
    while (s[length] != 0) length++;
    return length;
}

void append(array_string &s, char c) {
    int old_length = length(s);
    array_string new_string = new char[old_length+2];
    
    for (int i=0; i<old_length; i++) new_string[i] = s[i];

    new_string[old_length] = c;
    new_string[old_length+1] = 0;
    delete[] s;
    s = new_string;
}

void append_tester() {
    array_string a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    append(a, '!');
    cout << a << "\n";

    array_string b = new char[1];
    b[0] = 0;
    append(b, '!');
    cout << b << "\n";
}

void concatenate(array_string &a, array_string b) {
    int a_length = length(a);
    int b_length = length(b);
    int a_b_length = a_length + b_length;

    array_string new_string = new char[a_b_length+1];
    for (int i=0; i<a_length; i++) new_string[i] = a[i];
    for (int i=0; i<b_length; i++) new_string[a_length+i] = b[i];
    new_string[a_b_length] = 0;

    delete[] a;
    a = new_string;
}

void concatenate_tester() {
    array_string a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    array_string b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    concatenate(a,b);
    cout << a << "\n";
    array_string c = new char[1];
    c[0] = 0;
    concatenate(c,b);
    cout << c << "\n" << b << "\n";
    cout << (void *)c << "\n" << (void *)b << "\n";
}

int main() {
    append_tester();
    concatenate_tester();
}