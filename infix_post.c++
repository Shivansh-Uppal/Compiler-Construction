#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>

using namespace std;

float postfixINfloat(char *postfix){
    int i=0;
    //num is the number to be pushed into the stack
    float num=0;
    //num1 and num2 are the numbers to be popped from the stack
    float num1=0;
    float num2=0;
    //result is the result of the operation
    float result=0;

    //len is the length of the postfix expression
    int len=strlen(postfix);

    //s is the stack to store the numbers
    stack<float> s;

    //while the end of the postfix expression is not reached
    while(i<len){
        //if the character is a comma
        if(postfix[i]==','){
            i++;
            continue;
        }
        //if the character is a digit
        if(isdigit(postfix[i])){
            num=0;
            while(isdigit(postfix[i])){
                num=num*10+(postfix[i]-'0');
                i++;
            }
            s.push(num);
        }
        //else the character is an operator
        else{
            num1=s.top();
            s.pop();
            num2=s.top();
            s.pop();

            //perform the operation
            switch(postfix[i]){
                case '+':
                    result=num1+num2;
                    break;
                case '-':
                    result=num2-num1;
                    break;
                case '*':
                    result=num1*num2;
                    break;
                case '/':
                    result=num2/num1;
                    break;
            }
            s.push(result);
            i++;
        }
    }
    return s.top();
}

int main()
{
char input[100];
cout << "Enter an infix expression: ";
cin >> input;

stack<char> s; //stack to store operators

string output = ""; //string to store the postfix expression

for(int i = 0; i < strlen(input); i++)
{
    if(isdigit(input[i])) //if the character is a digit
    {
        output += input[i]; //add the digit to the output string

        //if the next character is a digit or the character is the last character
        if(i + 1 == strlen(input) || !isdigit(input[i + 1]))
        {
            output += ","; //add a comma to the output string
        }
    }
    else //if the character is not a digit
    {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') //if the character is an operator
        {
            //while the stack is not empty and the operator on the top of the stack has higher or equal precedence to the current operator
            while(!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                //add the operator on the top of the stack to the output string
                output += s.top();
                s.pop(); //remove the operator from the stack
            }

            //push the current operator onto the stack
            s.push(input[i]);
        }
        else if(input[i] == '(') //if the character is a left parenthesis
        {
            s.push(input[i]); //push the parenthesis onto the stack
        }
        else if(input[i] == ')') //if the character is a right parenthesis
        {
            //while the operator on the top of the stack is not a left parenthesis
            while(s.top() != '(')
            {
                //add the operator on the top of the stack to the output string
                output += s.top();
                s.pop(); //remove the operator from the stack
            }

            s.pop(); //remove the left parenthesis from the stack
        }
    }
}

//while the stack is not empty
while(!s.empty())
{
    //add the operator on the top of the stack to the output string
    output += s.top();
    s.pop(); //remove the operator from the stack
}

cout<<"Postfix expression: ";
cout << output << endl; //print the postfix expression

cout<<"Result: ";
cout<<postfixINfloat((char*)output.c_str())<<endl;
return 0;
}