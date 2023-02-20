#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main(){
  string regex="";
  cout<<"Enter the regex: ";
  cin>>regex;

  int len = regex.length();

  cout<<"CFG: "<<endl;
  for(int i=0;i<len;i++){
    if(regex[i]=='*'){
      cout<<"S-> "<<regex[i-1]<<"S | epsilon"<<endl;
    }
    if(regex[i]=='|'){
      cout<<"S-> "<<regex[i-1]<<" | "<<regex[i+1]<<endl;
    }
    if(regex[i]=='+' && regex[i+1]!='*'){
      cout<<"S-> "<<regex[i-1]<<"S | "<<regex[i-1]<<endl;
    }
    if(regex[i]=='.'){
      cout<<"S-> "<<regex[i-1]<<regex[i+1]<<endl;
    }
  } 
  return 0;
}