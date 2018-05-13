#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#define SIZE 80
using namespace std;

ofstream file1("first.txt", ios::app);

class Books {
public:
    virtual void print() = 0;
};

class Name {
public:
    void name (char mas[SIZE]) {
        file1 << "Volume Name: " << mas << "\t";
    }
    void name1 () {
        cout << "Класс имя"<< endl;
    }
};

class Type {
public:
    void type (char mas1[SIZE]) {
        file1 << "Book type: " << mas1 << "\t";
    }
    void type1 () {
        cout << "Класс тип"<< endl;
    }
};
class Print {
public:
    void print (char mas2[SIZE]) {
        file1 << "Release frequency: " << mas2 << "\t";
    }
    void print1 () {
        cout << "Класс частота выпуска"<< endl;
    }
};

class Pages {
public:
    void pages (int mas3[SIZE]) {
        file1 << "Number of pages: " << *mas3 << "\t";
    }
    void pages1 () {
        cout << "Класс кол-во страниц"<< endl;
    }
};

class Edition {
public:
    void edition (int mas4[SIZE]) {
        file1 << "Edition: " << *mas4 << "\t";
    }
    void edition1 () {
        cout << "Класс тираж"<< endl;
    }
};

class Year {
public:
    void year (int mas5[SIZE]) {
        file1 << "The year of publishing: " << *mas5 << ";" << endl << endl;
    }
    void year1() {
        cout << "Класс год выпуска" << endl;
    }
};

class Run : public Name, public Year, public Edition, public Print, public Pages, public Type {
public:
    void run() {
        for (;;) {
            try {
                int k = 0;
                cout << "Вы хотите отчистить файл?" << endl;
                cin >> k;
                if ((k >= 2) || (k < 0)) {
                    throw k;
                }
                if (k == 1) {
                    ofstream file1;
                    file1.open("first.txt", ofstream::out | ofstream::trunc);
                    cout << "Файл был отчищен." << endl;
                    file1.close();
                    break;
                } else {
                    cout << "Файл не был отчищен." << endl;
                    file1.close();
                    break;
                }
            } catch (int) {
                cout << "Введите число 0 или 1 " << endl;
            }
        }
    }
};

class Search {
public:
    void search (char mas[SIZE])  {
        ifstream file1("first.txt", ios::in);
        vector<char> mas9;
        vector<char> mas10(SIZE);
        vector<char>::iterator sb;
        
        istream_iterator<char> begin(file1);
        istream_iterator<char> end;
        copy (begin, end, back_inserter(mas9));
        
        
        if  (sb == mas9.end()) {
            cout << "Такая книга есть в списке" << endl;
        } else {
            cout << "данных нет" << endl;
        }
    }
};

class Prints: public Books {
public:
    void print ()  {
        ifstream file1("first.txt", ios::in);
        
        vector<char> mas9;
        vector<char> mas10(SIZE);
        
        istream_iterator<char> begin(file1);
        istream_iterator<char> end;
        
        copy (begin, end, back_inserter(mas9));
        
        cout << "Содержимое файла" << endl;
        for (int i = 1; i < mas9.size(); i++) {
            if (mas9[i] == ';') {
                mas9[i] = 0x0A;
            }
        }
        copy(mas9.begin(), mas9.end(), ostream_iterator<char>(cout, ""));
        file1.close();
    }
};


int main(int argc, const char * argv[]) {
    setlocale(0,"");
    cout << "Вводите данные на латинице" << endl;
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
            
            for (;;) {
                try {
                    cout << "Хотите добавить новую запись?" << " ";
                    cin >> z;
                    if ((z < 0) || (z > 1)) throw z;
                    break;
                } catch (int) {
                    cout << "Введите либо 0 либо 1" << endl;
                }
            }
            char * mas6 = new char[0];
            gets(mas6);
        }
        else {
            file1.close();
            break;
        }
    }
    
    Search k;
    char *mas10 = new char [SIZE];
    gets(mas10);
    k.search(mas10);
    
    Prints p;
    p.print();
    
    Run r;
    r.run();
    
    r.name1();
    r.type1();
    r.print1();
    r.pages1();
    r.edition1();
    r.year1();
    return 0;
}

/*
 
 Volume[__] = { 1, 2, 3, 4, 5}
 Volume[i] = 4
 
 Volume[__] = { 1, 2, 3, \0 ,5}
 
 */

