#include <iostream>
#include <string.h>
#include <fstream>
#include<sstream>
#include<cstring>
using namespace std;

// Returns 'true' if the string is a VALID IDENTIFIER.
bool isIdentifier(char* str){
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || 
   str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '!' || str[0] == '@' || 
   str[0] == '#' || str[0] == '$' || str[0] == '%' || str[0] == '^' || str[0] == '&' || str[0] == '*' || 
   str[0] == '(' || str[0] == ')' || str[0] == '-' || str[0] == '+' || str[0] == '=' || str[0] == '{' || 
   str[0] == '}' || str[0] == '[' || str[0] == ']' || str[0] == '|' || str[0] == ';' || str[0] == ':' || 
   str[0] == '"' || str[0] == '\'' || str[0] == '<' || str[0] == '>' || str[0] == ',' || str[0] == '.' || 
   str[0] == '?' || str[0] == '/' || str[0] == '`' || str[0] == '~' || str[0] == ' ' || str[0] == '\t' || 
   str[0] == '\n' || str[0] == '\r' || str[0] == '\v' || str[0] == '\f' || str[0] == '\b' || str[0] == '\a' || 
   str[0] == '\0')
    return (false);
   return (true);
}

// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str){
   if (!strcmp(str, "asm") || !strcmp(str, "case") || !strcmp(str, "const") || !strcmp(str, "continue") 
   || !strcmp(str, "default") || !strcmp(str, "do") || !strcmp(str, "else") || !strcmp(str, "enum")
    || !strcmp(str, "extern") || !strcmp(str, "for") || !strcmp(str, "goto") || !strcmp(str, "if")
    || !strcmp(str, "register") || !strcmp(str, "return") || !strcmp(str, "sizeof") || !strcmp(str, "static")
    || !strcmp(str, "struct") || !strcmp(str, "switch") || !strcmp(str, "typedef") || !strcmp(str, "union")
    || !strcmp(str, "volatile") || !strcmp(str, "while") || !strcmp(str, "auto") || !strcmp(str, "break")
    || !strcmp(str, "char") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "int")
    || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "signed") || !strcmp(str, "unsigned")
    || !strcmp(str, "void") || !strcmp(str, "bool") || !strcmp(str, "catch") || !strcmp(str, "class")
    || !strcmp(str, "const_cast") || !strcmp(str, "delete") || !strcmp(str, "dynamic_cast") 
    || !strcmp(str, "explicit") || !strcmp(str, "false") || !strcmp(str, "friend") || !strcmp(str, "inline")
    || !strcmp(str, "mutable") || !strcmp(str, "namespace") || !strcmp(str, "new") || !strcmp(str, "operator")
    || !strcmp(str, "private") || !strcmp(str, "protected") || !strcmp(str, "public") || !strcmp(str, "reinterpret_cast")
    || !strcmp(str, "static_cast") || !strcmp(str, "template") || !strcmp(str, "this") || !strcmp(str, "throw")
    || !strcmp(str, "true") || !strcmp(str, "try") || !strcmp(str, "typeid") || !strcmp(str, "typename")
    || !strcmp(str, "using") || !strcmp(str, "virtual") || !strcmp(str, "wchar_t") || !strcmp(str, "and")
    || !strcmp(str, "and_eq") || !strcmp(str, "bitand") || !strcmp(str, "bitor") || !strcmp(str, "compl")
    || !strcmp(str, "not") || !strcmp(str, "not_eq") || !strcmp(str, "or") || !strcmp(str, "or_eq")
    || !strcmp(str, "xor") || !strcmp(str, "xor_eq") || !strcmp(str, "alignas") || !strcmp(str, "alignof")
    || !strcmp(str, "char16_t") || !strcmp(str, "char32_t") || !strcmp(str, "constexpr") || !strcmp(str, "decltype")
    || !strcmp(str, "noexcept") || !strcmp(str, "nullptr") || !strcmp(str, "static_assert") || !strcmp(str, "thread_local")
    || !strcmp(str, "export") || !strcmp(str,"main") || !strcmp(str,"cin") || !strcmp(str,"cout") || 
    !strcmp(str,"endl"))
   return (true);
   return (false);
}

// Returns 'true' if the string is operator.
bool isValidOperator(char ch){
   if (ch == '+' || ch == '-' || ch == '*' ||
   ch == '/'  || ch == '='|| ch == '!' || ch == '&' 
   || ch == '|'|| ch == '%'|| ch == '^' || ch == '~' 
   || ch == '?'|| ch == ':')
   return (true);
   return (false);
}

// Returns 'true' if the string is a Punctiator.
bool isPunctuator(char ch){
   if (ch==',' || ch==';' || ch==':' || ch=='.' 
   || ch == '[' || ch == ']' || ch == '{' || ch == '}'|| ch == '(' || 
   ch == ')'|| ch == '<' || ch == '>' || ch == ',' || ch == ';')
   return (true);
   return (false);
}

//returns 'true' if the string is to be ignored
bool isIgnore(char* str){
    if(!strcmp(str, " ") || !strcmp(str, "#include") || 
    !strcmp(str, "#define") || !strcmp(str, "#ifndef")
    || !strcmp(str, "#endif") || !strcmp(str, "#ifdef")
    || !strcmp(str, "#undef") || !strcmp(str, "//") ||
    !strcmp(str, "/*") || !strcmp(str, "*/"))
    return (true);
    return (false);
}


int main(){
    int flag0=0,flag1=0,flag2=0,flag3=0;
    char str[1000] =" #include<iostream> int main ( ) { int a = 10 ; int b = 20 ; int c = a + b ; cout << c ; return 0 ; } ";
    char* token = strtok(&str[0], " ");

        while(token != NULL){
            if(isIgnore(token)){
                token = strtok(NULL, " ");
                continue;
            }
            else{
                if(isKeyword(token)){
                    flag0++;
                }
                else if(isIdentifier(token)){
                    flag1++;
                }
                else if(isValidOperator(token[0])){
                    flag2++;
                }
                else if(isPunctuator(token[0])){
                    flag3++;
                }
                token = strtok(NULL, " ");
            }
    }
    cout << "Keywords: " << flag0 << endl;
    cout << "Identifiers: " << flag1 << endl;
    cout << "Operators: " << flag2 << endl;
    cout << "Punctuators: " << flag3 << endl;
return 0;
}
    

