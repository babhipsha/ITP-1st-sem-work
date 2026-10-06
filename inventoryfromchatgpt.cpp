#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <limits>
#include <cctype>   // FIXED

using namespace std;

// ============================================================
// UTILITY FUNCTIONS
// ============================================================

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string getCurrentDateTime() {
    time_t now = time(nullptr);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

void printDivider(int width = 70, char ch = '=') {
    cout << string(width, ch) << "\n";
}

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

// ============================================================
// BASE CLASS
// ============================================================

class Item {
protected:
    int itemID;
    string name;
    double price;
    int quantity;
    string category;

public:
    Item(int id, const string& n, double p, int q)
        : itemID(id), name(n), price(p), quantity(q), category("General") {}

    virtual ~Item() {}

    virtual string getCategory() const = 0;
    virtual void displayInfo() const = 0;
    virtual string toCSV() const = 0;

    int getID() const { return itemID; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setPrice(double p) { price = p; }

    void addStock(int amt) {
        if (amt > 0) quantity += amt;
    }

    bool removeStock(int amt) {
        if (amt > 0 && quantity >= amt) {
            quantity -= amt;
            return true;
        }
        return false;
    }
};

// ============================================================
// DERIVED CLASSES
// ============================================================

class ElectronicsItem : public Item {
    int warranty;

public:
    ElectronicsItem(int id, const string& n, double p, int q, int w)
        : Item(id, n, p, q), warranty(w) {}

    string getCategory() const override { return "Electronics"; }

    void displayInfo() const override {
        cout << itemID << " " << name << " $" << price
             << " Qty:" << quantity << " Warranty:" << warranty << "\n";
    }

    string toCSV() const override {
        return to_string(itemID)+","+name+",Electronics,"+
               to_string(price)+","+to_string(quantity)+","+to_string(warranty);
    }
};

class GroceryItem : public Item {
    string expiry;

public:
    GroceryItem(int id, const string& n, double p, int q, string e)
        : Item(id, n, p, q), expiry(e) {}

    string getCategory() const override { return "Grocery"; }

    void displayInfo() const override {
        cout << itemID << " " << name << " $" << price
             << " Qty:" << quantity << " Exp:" << expiry << "\n";
    }

    string toCSV() const override {
        return to_string(itemID)+","+name+",Grocery,"+
               to_string(price)+","+to_string(quantity)+","+expiry;
    }
};

class ClothingItem : public Item {
    string size, colour;

public:
    ClothingItem(int id, const string& n, double p, int q,
                 string s, string c)
        : Item(id, n, p, q), size(s), colour(c) {}

    string getCategory() const override { return "Clothing"; }

    void displayInfo() const override {
        cout << itemID << " " << name << " $" << price
             << " Qty:" << quantity << " Size:" << size
             << " Color:" << colour << "\n";
    }

    string toCSV() const override {
        return to_string(itemID)+","+name+",Clothing,"+
               to_string(price)+","+to_string(quantity)+","+size+";"+colour;
    }
};

// ============================================================
// MANAGER
// ============================================================

class InventoryManager {
    vector<Item*> items;
    int nextID = 1;

public:
    ~InventoryManager() {
        for (auto i : items) delete i;
    }

    void addItem() {
        int type;
        cout << "1.Electronics 2.Grocery 3.Clothing: ";
        cin >> type;

        string name;
        double price;
        int qty;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name: ";
        getline(cin, name);

        cout << "Price: ";
        cin >> price;

        cout << "Qty: ";
        cin >> qty;

        Item* item = nullptr;

        if (type == 1) {
            int w;
            cout << "Warranty: ";
            cin >> w;
            item = new ElectronicsItem(nextID++, name, price, qty, w);
        }
        else if (type == 2) {
            string e;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Expiry: ";
            getline(cin, e);
            item = new GroceryItem(nextID++, name, price, qty, e);
        }
        else if (type == 3) {
            string s,c;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Size: ";
            getline(cin, s);
            cout << "Color: ";
            getline(cin, c);
            item = new ClothingItem(nextID++, name, price, qty, s, c);
        }

        if (item) items.push_back(item);
    }

    void viewItems() {
        for (auto i : items)
            i->displayInfo();
    }
};

// ============================================================
// MAIN
// ============================================================

int main() {
    InventoryManager m;
    int ch;

    do {
        cout << "\n1.Add 2.View 0.Exit: ";
        cin >> ch;

        if (ch == 1) m.addItem();
        else if (ch == 2) m.viewItems();

    } while (ch != 0);

    return 0;
}
