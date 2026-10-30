// String and Integer Collection Exercises
// Implements string operations and integer collection practice.
// Refurbished from a learning exercise; maintain the original learning objective.

#include <iostream>
#include <list>
#include <string>
using namespace std;

// String exercise: first/last character, append, reverse-search, search, clear.
// Integer collection exercise: insert at front/back, copy and print.

#pragma region MyString
class MyString {
    string text_;

public:
    MyString() = default;
    MyString(string name) {
        text_ = name;
    }

    char firstCharacter() const {
        return text_.empty() ? '\0' : text_.front();
    }

    char lastCharacter() const {
        return text_.empty() ? '\0' : text_.back();
    }

    string append(const char* text) {
        return text_.append(text);
    }

    int rfind(const char text) {
        return text_.rfind(text);
    }

    int find(const char text) {
        return text_.find(text);
    }

    string clear() {
        text_.clear();
        return text_;
    }
};
#pragma endregion

#pragma region IntArray
class IntArray {
    list<int> Array;
public:
    IntArray() = default;

    void addToBeginning(int number) {
        Array.push_front(number);
    }

    void addToEnd(int number) {
        Array.push_back(number);
    }

    void copyFrom(const list<int>& values) {
        Array = values;
    }

    void print() {
        for (auto i : Array) {
            cout << i << " ";
        }
    }

    void print(list<int> array) {
        for (auto i : array) {
            cout << i << " ";
        }
    }
};
#pragma endregion

int main() {
#pragma region MyString class
    //MyString textOne("Hakuna");
    //cout << textOne.firstCharacter() << endl;
    //cout << textOne.lastCharacter() << endl;
    //const char* text = " Matata";
    //cout << textOne.append(text) << endl;
    //cout << textOne.rfind('a') << endl;
    //cout << textOne.find('a') << endl;
    //cout << textOne.clear() << endl;
#pragma endregion

#pragma region IntArray
    //IntArray listOne;
    //listOne.addToBeginning(10);
    //listOne.addToEnd(12);
    //list<int> listTwo;
    //listOne.copyFrom(listTwo);
    //listOne.print();
#pragma endregion
}
