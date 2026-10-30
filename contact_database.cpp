// Contact Database
// Stores, finds, and removes simple contacts using an STL vector.
// Refurbished from a learning exercise; maintain the original learning objective.

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Contact record containing a name and telephone number.
class Contact {
protected:

    string name;
    string phone_number;

public:

    Contact() { name = " "; phone_number = " "; }
    Contact(const Contact&) = default;
    Contact(string name, string phone_number) { SetName(name); SetNumber(phone_number); }

    string GetName() const { return name; }
    string GetNumber() const { return phone_number; }

    void SetName(string name) { this->name = name; }
    void SetNumber(string phone_number) { this->phone_number = phone_number; }

    void Print() {
        cout << "\n ~~> Name : " << name << "\n ~~> Phone number : " << phone_number << endl;
    }

    Contact& operator= (const Contact& contOne) noexcept {
        this->name = contOne.name;
        this->phone_number = contOne.phone_number;
        return *this;
    }
};

class Database {
private:
    vector<Contact> contacts;

public:
    Database() = default;

    void AddContact(Contact& obj) {
        contacts.push_back(obj);
    }

    void DeleteByName(const string& name) {
        // erase-remove ensures matching names are removed even on repeated calls.
        contacts.erase(
            remove_if(contacts.begin(), contacts.end(),
                [&](const Contact& contact) { return contact.GetName() == name; }),
            contacts.end());
    }

    void Print() {
        for (const Contact& i : contacts) {
            cout << i.GetName() << " " << i.GetNumber() << endl;
        }
    }

    void SearchByName(string name) {
        for (const Contact& i : contacts) {
            if (i.GetName() == name) {
                cout << i.GetNumber() << endl;
            }
        }
    }
};

int main() {
    Contact c("sa", "055");
    Contact c1("rx", "740");
    Contact c2("an", "4005");

    Database data;
    data.AddContact(c);
    data.AddContact(c1);
    data.AddContact(c2);

    data.Print();
    data.SearchByName("sa");
}
