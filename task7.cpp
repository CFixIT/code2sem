//
//  main.cpp
//  task7
//
//  Created by Nikita Kolmakov on 05.05.2018.
//  Copyright © 2018 Interesting Com. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#define SIZE 80
using namespace std;

ofstream file1("first.txt", ios::app);

class Books {
public:
    virtual void print() = 0;
    virtual void get() = 0;
};

class Name {
public:
    void name(char mas[SIZE]) {
        file1 << "Название книги: " << mas << "\t";
    }
};

class Type {
public:
    void type (char mas1[SIZE]) {
        file1 << "Тип книги: " << mas1 << "\t";
    }
};
class Print {
public:
    void print (char mas2[SIZE]) {
        file1 << "Частота выпуска: " << mas2 << "\t";
    }
};

class Pages {
public:
    void pages (int mas3[SIZE]) {
        file1 << "Кол-во страниц: " << *mas3 << "\t";
    }
};

class Edition {
public:
    void edition (int mas4[SIZE]) {
        file1 << "Тираж в шт.: " << *mas4 << "\t";
    }
};

class Year{
public:
    void year (int mas5[SIZE]) {
        file1 << "Год издания: " << *mas5 << endl << endl;
    }
};

class Run : public Year, public Edition, public Print, public Pages, public Type, public Name {
public:
};

class Search {
public:
    void print ()  {
        ifstream file1("first.txt", ios::in);
        vector<char> mas9;
        
        istream_iterator<char> begin(file1);
        istream_iterator<char> end;
        
        copy (begin, end, back_inserter(mas9));
        
        copy(mas9.begin(), mas9.end(), ostream_iterator<char>(cout));
        
        
    }
};

int main(int argc, const char * argv[]) {
    setlocale(0,"");
    int z = 1;
    for(;;) {
        if (z == 1) {
            char *mas = new char[SIZE];
            cout << "Введи название книги" << endl;
            gets(mas);
            Name a;
            a.name(mas);
            delete [] mas;
            
            char *mas1 = new char [SIZE];
            cout << "Введи тип книги" << endl;
            gets(mas1);
            Type b;
            b.type(mas1);
            delete [] mas1;
            
            
            char *mas2 = new char [SIZE];
            cout << "Частота выпуска" << endl;
            gets(mas2);
            Print d;
            d.print(mas2);
            delete [] mas2;
            
            int *mas3 = new int [SIZE];
            cout << "Введи кол-во страниц" << endl;
            cin >> mas3[0];
            Pages c;
            c.pages(mas3);
            delete [] mas3;
            
            int *mas4 = new int [SIZE];
            cout << "Введи тираж" << endl;
            cin >> mas4[0];
            Edition e;
            e.edition(mas4);
            delete [] mas4;
            
            int *mas5 = new int [SIZE];
            cout << "Введи год издания" << endl;
            cin >> mas5[0];
            Year f;
            f.year(mas5);
            delete [] mas5;
            
            cout << "Хотите добавить новую запись?" << " ";
            cin >> z;
            char * mas6 = new char[0];
            gets(mas6);
        }
        else {
            file1.close();
            break;
        }
    }
    Search k;
    k.print();
    return 0;
}
