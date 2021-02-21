#include <iostream>

typedef char *array_string;

int length(array_string s) {
    int len{0};
    while (s[len] != 0) len++;
    return len;
}

array_string substring(array_string str, int start, int len) {
    array_string new_str = new char[len+1];
    for (int i=0; i<len; i++) new_str[i] = str[start-1+i];
    new_str[len] = 0;
    return new_str;
}

int main() {
    array_string original = new char[8];
    original[0] = 'a'; original[1] = 'b'; original[2] = 'c';
    original[3] = 'd'; original[4] = 'e'; original[5] = 'f';
    original[6] = 'g'; original[7] = 0;
    std::cout << original << "\n";
    array_string sub_string = substring(original, 3, 4);
    std::cout << original << "\n" << sub_string << "\n";
}