//
//  main.cpp
//  task4.4
//
//  Created by Nikita Kolmakov on 16.05.2018.
//  Copyright © 2018 Interesting Com. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#define MAXSIZE 255

//если кол-во символов в строке = 10, то удалить символы A -> Z;
using namespace std;

class Line{
public:
    int k = 0;
    char *str;
    char *retstr;
    Line();
    ~Line();
    Line(char*);
    void set(char*);
    void run();
    void print();
    string print1();
};
Line::Line(){
    str=new char[MAXSIZE];
    str[0]='\0';
    retstr=new char[MAXSIZE];
    retstr[0]='\0';
};
Line::Line(char *s){
    str=new char[MAXSIZE];
    strcpy(str,s);
    retstr=new char[MAXSIZE];
    retstr[0]='\0';
};

void Line::run() {
    if((strlen(str) == 10))
    {
        int j = 0;
        for(unsigned int i = 0; i < strlen(str); i++) {
            if ((*(str + i) < 65) || (*(str + i) > 90)) {
                *(retstr + j++ ) = *(str + i);
                *(retstr + j) = '\0';
            }
        }
    }
    else
    {
        k = 1;
        cout << "Количество элементов не равняется 10" << endl;
    }
}

void Line::set(char* s) {
    strcpy(str, s);
}

void Line::print()
{
    if (strlen(str) != 10) {
        cout << str << endl;
    } else {
        cout << retstr << endl;
    }
}

string Line::print1() {
    return retstr;
}

Line::~Line()  {
    delete [] str;
   // cout << "... free space was delete" << endl;
}

class Pereg {
    char *str;
    int k;
public:
    Pereg(const char* s = "")
    {
        k = (int)strlen(s);
        str = new char [k + 1];
        strcpy(str,s);
    }
    Pereg& operator=(const Pereg& s)
    {
        if(k != s.k)
        {
            k = s.k;
            delete[] str;
            str = new char [k];
        }
        strcpy(str,s.str);
        return (*this);
    }
};
int main() {
    setlocale(0,"");
    ofstream file1("first.txt");
    ofstream file2("second.txt");
    char s[265];
    cout << "Enter string"<<endl;
    cin.getline(s,256);
   Line str(s);
   str.run();
    cout << "Вывод при косвенном вызове:" <<endl;
    str.print();
    
    Line *obj = new Line();
    obj -> set(s);
    obj -> run();
    cout << "Вывод при прямом вызове" << endl;
    obj -> print();
    
    file1 << s;
    file2 << obj -> print1();
    return 0;
}

