// Vehicle Inheritance and Polymorphism
// Demonstrates an engine, three vehicle subclasses, and stack-based storage.
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Engine {
public:
    string engineNo, company;
    double volume;
    Engine() = default;
    Engine(string no, string maker, double vol) : engineNo(no), company(maker), volume(vol) {}
    void Show() { cout << "Company  : " << company << "\nEngineNo : " << engineNo << "\nVolume   : " << volume << endl; }
};
class Vehicle {
public:
    static int staticId;
    int id;
    string model, vendor;
    Engine engine;
    Vehicle(string vendor, string model, Engine engine) : id(staticId++), model(model), vendor(vendor), engine(engine) {}
    virtual void Show() {
        cout << "Id     : " << id << "\nVendor : " << vendor << "\nModel  : " << model << endl;
        engine.Show();
    }
    virtual ~Vehicle() = default;
};
int Vehicle::staticId = 1;
class Car : public Vehicle {
public:
    bool hasSpoiler;
    Car(string vendor, string model, Engine engine, bool spoiler) : Vehicle(vendor, model, engine), hasSpoiler(spoiler) {}
    void Show() override {
        cout << "********* Car *********" << endl; Vehicle::Show();
        cout << "Spoiler : " << (hasSpoiler ? "yes" : "no") << endl;
    }
};
class Ship : public Vehicle {
public:
    bool hasSail;
    Ship(string vendor, string model, Engine engine, bool sail) : Vehicle(vendor, model, engine), hasSail(sail) {}
    void Show() override {
        cout << "********* Ship *********" << endl; Vehicle::Show();
        cout << "Sail : " << (hasSail ? "yes" : "no") << endl;
    }
};
class Airplane : public Vehicle {
public:
    int engineCount, passengerCapacity;
    Airplane(string vendor, string model, Engine engine, int engines, int capacity)
        : Vehicle(vendor, model, engine), engineCount(engines), passengerCapacity(capacity) {}
    void Show() override {
        cout << "********* Airplane *********" << endl; Vehicle::Show();
        cout << "Engine Count : " << engineCount << "\nPassenger Capacity : " << passengerCapacity << endl;
    }
};
class VehicleDepot {
public:
    stack<Car> cars;
    stack<Ship> ships;
    stack<Airplane> airplanes;
    void AddCar(Car& car) { cars.push(car); }
    void AddShip(Ship& ship) { ships.push(ship); }
    void AddAirplane(Airplane& airplane) { airplanes.push(airplane); }
    // Showing all vehicles intentionally empties the stacks.
    void ShowAllVehicles() {
        while (!cars.empty()) { cars.top().Show(); cars.pop(); }
        while (!ships.empty()) { ships.top().Show(); ships.pop(); }
        while (!airplanes.empty()) { airplanes.top().Show(); airplanes.pop(); }
    }
};
int main() {
    VehicleDepot depot;
    Car carOne("bmw", "x6", Engine("bmw123", "bmw", 3.1), true);
    Ship shipOne("Cruise", "42394", Engine("Cruise", "234cr", 3.3), true);
    Airplane planeOne("Boing", "737", Engine("Boing", "141", 100), 4, 360);
    depot.AddCar(carOne); depot.AddShip(shipOne); depot.AddAirplane(planeOne);
    depot.ShowAllVehicles();
}
