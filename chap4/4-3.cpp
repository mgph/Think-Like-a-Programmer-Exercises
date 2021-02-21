#include <iostream>

typedef char *array_string;

int length(array_string s) {
    int len{0};
    while (s[len] != 0) len++;
    return len;
}

int findString(array_string s, array_string t, int start) {
    if (s[start] == t[0] && (start+length(t)<=length(s)) ) {
        int j{0};
        while (t[j] == s[start+j] && t[j] != 0) {
            j++;
        }
        if (j == length(t))
            return start;
    }
    return -1;
}

array_string subString(array_string str, int start, int len) {
    array_string new_str = new char[len+1];
    for (int i=0; i<len; i++) new_str[i] = str[start+i];
    new_str[len] = 0;
    return new_str;
}

void replaceString(array_string &source, array_string target, array_string replaceText) {
    int replaceText_length = length(replaceText);
    
    for (int i=0; i<length(source); i++) {
        int index = findString(source, target, i);
        if (index != -1) {
            array_string cut_string = subString(source, index+length(target), length(source));
            array_string new_string = new char[replaceText_length+length(cut_string)];

            for (int source_i=0; source_i<index; source_i++) new_string[source_i] = source[source_i];
            for (int j=0; j<replaceText_length; j++) new_string[j+index] = replaceText[j];
            for (int k=0; k<length(cut_string); k++) new_string[k+replaceText_length+index] = cut_string[k];
            new_string[index+replaceText_length+length(cut_string)] = 0;

            source = new_string;
        }
    }
}

void replaceString_tester() {
    array_string source = new char[9];
    source[0] = 'a'; source[1] = 'b'; source[2] = 'c'; source[3] = 'd'; 
    source[4] = 'a'; source[5] = 'b'; source[6] = 'e'; source[7] = 'e'; source[8] = 0; 

    array_string target = new char[3];
    target[0] = 'a'; target[1] = 'b'; target[2] = 0;

    array_string replaceText = new char[4];
    replaceText[0] = 'x'; replaceText[1] = 'y'; replaceText[2] = 'z'; replaceText[3] = 0;

    std::cout << source << "\n" << target << "\n" << replaceText << "\n";
    replaceString(source, target, replaceText);
    std::cout << source << "\n";
}

int main() {
    replaceString_tester();
}