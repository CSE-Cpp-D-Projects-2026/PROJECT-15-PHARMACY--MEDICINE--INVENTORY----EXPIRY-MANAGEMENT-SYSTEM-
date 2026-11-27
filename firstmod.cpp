

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
using namespace std;

struct Batch {
    int batchId;int medicineId;int supplierId;int quantity;
    string receivedDate; string expiryDate;
};

struct AuditEntry {
    string action;string date;
    int batchno;
    int quantityChange;
};

template <typename T>
T findId(const vector<T>& records, int id) {
    for (size_t i = 0; i < records.size(); ++i)
        if (records[i].getId() == id) return records[i];
    throw runtime_error("Record not found.");
}

template <typename T>
void printValue(const T& value) {
    cout << value << '\n';
}

template <typename T>
class DisplayBox {
public:
    void show(const T& value) { cout << value << '\n'; }
};

template <>
class DisplayBox<double> {
public:
    void show(const double& value) {
        cout << fixed << setprecision(2) << value << '\n';
    }
};

class Medicine {
private:
    int id;
    string name, category, unit;
    double price;
    int reorderLevel;
    static int count;

public:
    Medicine() : id(0), name(""), category(""), unit(""), price(0), reorderLevel(0) { ++count; }
    Medicine(int i, string n, string c, string u, double p, int r)
        : id(i), name(n), category(c), unit(u), price(p), reorderLevel(r) { ++count; }
    Medicine(const Medicine& m)
        : id(m.id), name(m.name), category(m.category), unit(m.unit),
          price(m.price), reorderLevel(m.reorderLevel) { ++count; }
    ~Medicine() { --count; }


int getId() const { return id; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    string getUnit() const { return unit; }
    double getPrice() const { return price; }
    int getReorderLevel() const { return reorderLevel; }

    void setName(string n) { this->name = n; }
    void setCategory(string c) { category = c; }
    void setUnit(string u) { unit = u; }
    void setPrice(double p) { price = p; }
    void setReorderLevel(int r) { reorderLevel = r; }

    inline bool isValidPrice() const { return price > 0; }

    void display() const {
        cout << "ID: " << id << " | " << name << " | " << category
             << " | Unit: " << unit << " | Price: Rs." << fixed << setprecision(2)
             << price << " | Reorder at: " << reorderLevel << '\n';
    }

    static int getCount() { return count; }

    friend bool operator<(const Medicine& a, const Medicine& b) {
        return a.name < b.name;
    }
}