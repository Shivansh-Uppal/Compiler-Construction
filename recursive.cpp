#include <stdio.h>
#include <string.h>
#include<iostream>
#include<cstdio>

using namespace std;
 
#define SUCCESS 1
#define FAILED 0
 
int E(), Edash(), T(), Tdash(), F();
 
const char *cursor;
char a[64];
 
int main()
{
    puts("Enter the string: i+(i+i)*i");
    sscanf("i+(i+i)*i", "%s", a);
    cursor = a;
    puts("");
    puts("Input            Action");
    puts("--------------------------------");
 
    if (E() && *cursor == '\0') {
        puts("--------------------------------");
        puts("string is successfully parsed");
        return 0;
    } else {
        puts("--------------------------------");
        puts("Error in parsing string");
        return 1;
    }
}
 
int E()
{
    //printf("%-16s E  ->  T E'\n", cursor); write in cpp with %-16s
    cout <<cursor << "    E  ->  T E'" << endl;
    if (T()) {
        if (Edash())
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}
 
int Edash()
{
    if (*cursor == '+') {
        cout<<cursor<<"    E' ->  + T E'"<<endl;
        cursor++;
        if (T()) {
            if (Edash())
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        //printf("  E' ->  $\n", cursor);
        cout<<cursor<<"    E' ->  $"<<endl;
        return SUCCESS;
    }
}
 
int T()
{
    cout<<cursor<<"    T  ->  F T'"<<endl;
    if (F()) {
        if (Tdash())
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}
 
int Tdash()
{
    if (*cursor == '*') {
        cout<<cursor<<"    T' ->  * F T'"<<endl;
        cursor++;
        if (F()) {
            if (Tdash())
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        cout<<cursor<<"    T' ->  $"<<endl;
        return SUCCESS;
    }
}
 
int F()
{
    if (*cursor == '(') {
        cout<<cursor<<"    F  ->  ( E )"<<endl;
        cursor++;
        if (E()) {
            if (*cursor == ')') {
                cursor++;
                return SUCCESS;
            } else
                return FAILED;
        } else
            return FAILED;
    } else if (*cursor == 'i') {
        cursor++;
        cout<<cursor<<"    F  ->  i"<<endl;
        return SUCCESS;
    } else
        return FAILED;
}