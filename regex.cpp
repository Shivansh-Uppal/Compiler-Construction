#include <iostream>
#include <string>

bool match(std::string str) {
    int state = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        switch (state) {
            case 0:
                if (c == '0') {
                    state = 0;
                } 
                else if (c == '1') {
                    state = 1;
                } 
                else {
                    return false;
                }
                break;
            case 1:
                if (c == '0') {
                    state = 2;
                } 
                else if (c == '1') {
                    state = 3;
                }
                else {
                    return false;
                }
                break;
            case 2:
                if(c=='\n'){
                    return true;
                }
                else {
                    return false;
                }
                break;
            case 3:
                if (c == '0') {
                    state = 2;
                } 
                else if (c == '1') {
                    state = 3;
                }
                else {
                    return false;
                }
                break;
    }
    }
        return true;
}


int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;
    if (match(str)) {
        std::cout << "String matches the pattern 0*1+(0|1)" << std::endl;
    } else {
        std::cout << "String does not match the pattern 0*1+(0|1)" << std::endl;
    }
    return 0;
}
