// Bank and Debtor Management
// Demonstrates debtor records and filtering by debt or overdue payments.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Debtor {
    int objectId;
    string name, surname, workAdress, phoneNumber, liveAdress;
    double salary;
    bool hasLatePayment;
    int debt;
    static int Id;
public:
    Debtor() : objectId(Id++), name(""), surname(""), workAdress(""), phoneNumber(""),
        liveAdress(""), salary(0), hasLatePayment(true), debt(0) {}
    Debtor(string name, string surname, string workplace, double salary, string phone,
           bool late, string address, int debt) : Debtor() {
        SetName(name); SetSurname(surname); SetWorkAdress(workplace); SetSalary(salary);
        SetPhoneNumber(phone); SetHasLatePayment(late); SetLiveAdress(address); SetDebt(debt);
    }
    Debtor(const Debtor& other) : objectId(Id++), name(other.name), surname(other.surname),
        workAdress(other.workAdress), phoneNumber(other.phoneNumber),
        liveAdress(other.liveAdress), salary(other.salary),
        hasLatePayment(other.hasLatePayment), debt(other.debt) {}

    int GetObjectId() { return objectId; }
    string GetName() { return name; }
    string GetSurname() { return surname; }
    string GetWorkAdress() { return workAdress; }
    double GetSalary() { return salary; }
    string GetPhoneNumber() { return phoneNumber; }
    bool GetHasLatePayment() { return hasLatePayment; }
    string GetLiveAdress() { return liveAdress; }
    int GetDebt() { return debt; }

    void SetObjectId(int value) { objectId = value; }
    void SetName(string value) { name = value; }
    void SetSurname(string value) { surname = value; }
    void SetWorkAdress(string value) { workAdress = value; }
    void SetSalary(double value) { salary = value; }
    void SetPhoneNumber(string value) { phoneNumber = value; }
    void SetHasLatePayment(bool value) { hasLatePayment = value; }
    void SetLiveAdress(string value) { liveAdress = value; }
    void SetDebt(int value) { debt = value; }

    void showDebtors() {
        cout << "Id : " << objectId << "\nName : " << name << "\nSurname : " << surname
             << "\nSalary : " << salary << "\nPhone Number : " << phoneNumber
             << "\nWork Address : " << workAdress << "\nHome Address : " << liveAdress
             << "\nDebt : " << debt << endl;
    }
};
int Debtor::Id = 1;

class Bank {
    string name;
    vector<Debtor> debtors{
        Debtor("Sample", "Customer", "Example Workplace", 7000, "000 *** ** **",
               true, "Example Address", 260)
    };
public:
    Bank() : name(" ") {}
    void showAllDebtors() {
        cout << "All Debtors : " << endl << endl;
        for (auto& debtor : debtors) { debtor.showDebtors(); cout << endl; }
    }
    void showDebtorThousandDebt() {
        cout << "Debtors owing more than 1,000: " << endl << endl;
        for (auto& debtor : debtors)
            if (debtor.GetDebt() > 1000) { debtor.showDebtors(); cout << endl; }
    }
    void showLateDebtors() {
        cout << "Has Late Debtors : " << endl << endl;
        for (auto& debtor : debtors)
            if (debtor.GetHasLatePayment()) { debtor.showDebtors(); cout << endl; }
    }
};
int main() {
    Bank bank;
    bank.showAllDebtors();
    bank.showDebtorThousandDebt();
    bank.showLateDebtors();
}
