// Student Priority Queue
// Uses a generic queue that removes the student with the highest average score.
// Refurbished from a learning exercise; maintain the original learning objective.

#include <iostream>
#include <cassert>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    string surname;
    double average;
public:
    Student() : name(""), surname(""), average(0) {}
    Student(string name, string surname, double average)
        : name(name), surname(surname), average(average) {}

    string GetName() { return name; }
    string GetSurName() { return surname; }
    double GetAvg() { return average; }
    void SetName(const string name) { this->name = name; }
    void SetSurName(const string surname) { this->surname = surname; }
    void SetAvg(const double average) { this->average = average; }

    bool operator>(const Student& obj) const { return average > obj.average; }
    friend ostream& operator<<(ostream& out, const Student& obj) {
        out << " Name : " << obj.name << endl
            << " Surname : " << obj.surname << endl
            << " Average : " << obj.average << endl;
        return out;
    }
};

// Small educational priority queue: O(n) search, O(n) removal.
// std::vector safely manages element lifetime and copy semantics.
template <class T>
class PriorityQueue {
    std::vector<T> items;
    std::size_t capacity;

    std::size_t GetMaxIndex() const {
        std::size_t maxIndex = 0;
        for (std::size_t i = 1; i < items.size(); ++i) {
            if (items[i] > items[maxIndex]) maxIndex = i;
        }
        return maxIndex;
    }
public:
    explicit PriorityQueue(std::size_t size) : capacity(size) { items.reserve(size); }
    bool IsFull() const { return items.size() >= capacity; }
    bool IsEmpty() const { return items.empty(); }
    void Push(const T& value) { assert(!IsFull()); items.push_back(value); }
    void Pop() { assert(!IsEmpty()); items.erase(items.begin() + GetMaxIndex()); }
    void Print() const {
        for (const T& item : items) std::cout << item << '\n';
    }
};

int main() {
    PriorityQueue<Student> queue(4);
    queue.Push(Student("Student", "One", 71));
    queue.Push(Student("Student", "Two", 61));
    queue.Push(Student("Student", "Three", 81));
    queue.Push(Student("Student", "Four", 91));
    queue.Print();

    cout << "\n ~~~~~~~~~~~~ Next ~~~~~~~~~~~~ \n\n";
    queue.Pop();
    queue.Print();
    cout << "\n ~~~~~~~~~~~~ Next ~~~~~~~~~~~~ \n\n";
    queue.Pop();
    queue.Print();
    cout << "\n ~~~~~~~~~~~~ Next ~~~~~~~~~~~~ \n\n";
    queue.Pop();
    queue.Print();
}
