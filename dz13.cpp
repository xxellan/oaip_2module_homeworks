//задачи на классы (2 последние)
#include <iostream>
#include <locale>
#include <string>
using namespace std;
class Shape {
public:
    int a;
};
class Publication {
private:
    string title;
public:
    Publication() { title = " "; };
    Publication(string t) :title(t) {};
    void displayInfo() {
        cout << "Name of publication "<<title << endl;
    }
    void Gettitle(string t) {
        title = t;
    }
};
class Book: public Publication {
private:
    string name;
    string author;
    int year;
public:
    Book(string name, string author, int year) {
        this->name = name;
        this->author = author;
        this->year = year;
    }
    void displayinfo() {
        cout << "Name: " + name << endl;
        cout << "Author: " + author << endl;
        cout << "Year of publication: " << year << endl;
    }
};
class Rectangle: public Shape {
private:
    int b;
public:
    Rectangle(int a,int b) {
        this->b = b;
        this->a = a;
    }
    int calculateArea() {
        return a * b;
    }
    int calculatePerimeter() {
        return (a + b) * 2;
    }
    void displayinfo() {
        cout << "Length: " << a << ", " << "Width: " << b << ", " << "Square: " << a*b << ", " << "Perimeter: " << (a + b) *2<< endl;
    }
};

int main()
{
    Book k1("Crime and Punishment", "Dostoevsky", 1865);
    k1.Gettitle("Classic");
    k1.displayInfo();
    k1.displayinfo();
    Rectangle f1(23, 5);
    int s = f1.calculateArea();
    int p = f1.calculatePerimeter();
    f1.displayinfo();

}


