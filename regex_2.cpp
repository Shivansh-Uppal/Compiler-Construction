//finite machine for regular expression: a+b*(c|d)+a*c+

#include <iostream>
#include <string>

using namespace std;

bool reg(string str){
        int state=0;
        for(int i=0;i<str.size();i++){
                char c=str[i];
                switch(state){
                    case 0:
                        if(c=='a'){
                            state=1;
                        }
                        else if(c=='c'){
                            state=2;
                        }
                        else{
                            return false;
                        }
                        break;
                    case 1:
                        if(c=='a'){
                            state=1;
                        }
                        else if(c=='b'){
                            state=3;
                        }
                        else if(c=='c'){
                            state=4;
                        }
                        else if(c=='d'){
                            state=5;
                        }
                        else{
                            return false;
                        }
                        break;
                    case 2:
                        if(c=='c'){
                            state=2;
                        }
                        else if(c=='\n'){
                            return true;
                        }
                        else{
                            return false;
                        }
                        break;
                    case 3:
                        if(c=='b'){
                            state=3;
                        }
                        else if(c=='c'){
                            state=5;
                        }
                        else if(c=='d'){
                            state=5;
                        }
                        else{
                            return false;
                        }
                        break;
                    case 4:
                        if(c=='c'){
                            state=2;
                        }
                        else{
                            return false;
                        }
                        break;
                    case 5:
                        if(c=='\n'){
                            return true;
                        }
                        else{
                            return false;
                        }
                        break;       
        }
    }
    return true;
}


int main()
{
        string str;
        cout<<"Enter a string: ";
        getline(cin,str);
        if(reg(str)){
            cout<<"String matches the pattern a+b*(c|d)|a*c+"<<endl;
        }
        else{
            cout<<"String does not match the pattern a+b*(c|d)|a*c+"<<endl;
        }
        return 0;
}