// Computer Store Management
// Models computer inventory, input/output operators, and object copying.
// Refurbished from a learning exercise; maintain the original learning objective.

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
using namespace std;

class Computer {
    static int id;
    int objectId;
    string model, vendor, videocard, monitor;
    double cpu_hz;
    int core, ram, disk_size;
    bool isSSD;
public:
    Computer() : objectId(id++) {
        SetModel("N6OLO15"); SetVendor("GameMax");
        SetVideoCard("NVIDIA GeForce RTX 3060"); SetMonitor("ASUS VQ259QM");
        SetCpuHz(3.80); SetCore(8); SetRam(32); SetDiskSize(2); SetSSD(true);
    }
    Computer(string model, string vendor, string videocard, string monitor,
             double cpu_hz, int core, int ram, int disk_size, bool isSSD) : Computer() {
        SetModel(model); SetVendor(vendor); SetVideoCard(videocard);
        SetMonitor(monitor); SetCpuHz(cpu_hz); SetCore(core);
        SetRam(ram); SetDiskSize(disk_size); SetSSD(isSSD);
    }
    Computer(const Computer& other) : objectId(id++) {
        SetModel(other.model); SetVendor(other.vendor); SetVideoCard(other.videocard);
        SetMonitor(other.monitor); SetCpuHz(other.cpu_hz); SetCore(other.core);
        SetRam(other.ram); SetDiskSize(other.disk_size); SetSSD(other.isSSD);
    }
    Computer& operator=(const Computer& other) {
        if (this != &other) {
            SetModel(other.model); SetVendor(other.vendor); SetVideoCard(other.videocard);
            SetMonitor(other.monitor); SetCpuHz(other.cpu_hz); SetCore(other.core);
            SetRam(other.ram); SetDiskSize(other.disk_size); SetSSD(other.isSSD);
        }
        return *this;
    }
    int GetObjectId() const { return objectId; }
    string GetModel() const { return model; }
    string GetVendor() const { return vendor; }
    string GetVideoCard() const { return videocard; }
    string GetMonitor() const { return monitor; }
    double GetCpuHz() const { return cpu_hz; }
    int GetCore() const { return core; }
    int GetRam() const { return ram; }
    int GetDiskSize() const { return disk_size; }
    bool GetSSD() const { return isSSD; }

    void SetModel(string value) { model = value; }
    void SetVendor(string value) { vendor = value; }
    void SetVideoCard(string value) { videocard = value; }
    void SetMonitor(string value) { monitor = value; }
    void SetCpuHz(double value) { cpu_hz = value; }
    void SetCore(int value) { core = value; }
    void SetRam(int value) { ram = value; }
    void SetDiskSize(int value) { disk_size = value; }
    void SetSSD(bool value) { isSSD = value; }

    friend ostream& operator<<(ostream& out, const Computer& obj) {
        out << "==========Computers==========" << endl
            << "objectId  : " << obj.objectId << endl
            << "model     : " << obj.model << endl
            << "vendor    : " << obj.vendor << endl
            << "videocard : " << obj.videocard << endl
            << "monitor   : " << obj.monitor << endl
            << "cpu_hz    : " << obj.cpu_hz << endl
            << "core      : " << obj.core << endl
            << "ram       : " << obj.ram << endl
            << "isSSD     : " << boolalpha << obj.isSSD << noboolalpha << endl << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Computer& obj) {
        string model, vendor, videocard, monitor;
        int num;
        bool SSD;
        double cpu;
        cout << "Model : "; getline(in, model); obj.SetModel(model);
        cout << "Vendor : "; getline(in, vendor); obj.SetVendor(vendor);
        cout << "Videocard : "; getline(in, videocard); obj.SetVideoCard(videocard);
        cout << "Monitor : "; getline(in, monitor); obj.SetMonitor(monitor);
        cout << "Cpu_hz : "; in >> cpu; obj.SetCpuHz(cpu);
        cout << "Core : "; in >> num; obj.SetCore(num);
        cout << "Ram : "; in >> num; obj.SetRam(num);
        cout << "SSD : "; in >> SSD; obj.SetSSD(SSD);
        return in;
    }
};
int Computer::id = 1;

// Own computers using smart pointers so deleting a record is memory-safe.
class ComputerStore {
    string store_name, store_address;
    vector<unique_ptr<Computer>> computers;
public:
    ComputerStore(string name, string address)
        : store_name(std::move(name)), store_address(std::move(address)) {}
    const string& GetAddress() const { return store_address; }
    const string& GetName() const { return store_name; }
    void SetName(const string& name) { store_name = name; }
    void SetAddress(const string& address) { store_address = address; }
    void addComputer(const Computer& computer) {
        computers.push_back(make_unique<Computer>(computer));
    }
    void DeleteComputer(int id) {
        computers.erase(remove_if(computers.begin(), computers.end(),
            [id](const unique_ptr<Computer>& computer) {
                return computer->GetObjectId() == id;
            }), computers.end());
    }
    friend ostream& operator<<(ostream& out, const ComputerStore& store) {
        out << store.store_name << '\n' << store.store_address << '\n';
        for (const auto& computer : store.computers) out << *computer << '\n';
        return out;
    }
};

int main() {
    ComputerStore t("Demo Computer Store", "Sample City");
    t.addComputer(Computer("F15", "TUF", "Rtx 3060", "Asus", 3.2, 12, 32, 2, true));
    cout << t;
    return 0;
}
