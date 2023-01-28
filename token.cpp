#include <iostream>
#include <fstream>
#include<sstream>
#include <map>

using namespace std;

map<string, int> tokens;

int main() {
    string filename;
    int token_count = 0;

    cout << "Enter file name: ";
    getline(cin, filename);

    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            string token = "";
            for (int i = 0; i < line.length(); i++) {
                if (isalnum(line[i]) || line[i] == '_') {
                    token += line[i];
                } else {
                    if (token != "") {
                        if(tokens.find("#") != tokens.end()){
                            continue;
                        }
                        if (tokens.find(token) != tokens.end()) {
                            tokens[token]++;
                        } else {
                            tokens[token] = 1;
                        }
                        token = "";
                    }
                }
            }
        }
        file.close();
        for (auto const &x : tokens) {
            cout << x.first << ": " << x.second << endl;
        }
    } else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}