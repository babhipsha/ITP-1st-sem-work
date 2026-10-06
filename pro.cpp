#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

class Item {
protected:
    std::string name;
    int quantity;
    double price;

public:
    Item(std::string n, int q, double p) : name(n), quantity(q), price(p) {}
    virtual void display() = 0;
    virtual std::string getName() { return name; }
    virtual int getQuantity() { return quantity; }
    virtual double getPrice() { return price; }
    virtual void updateQuantity(int q) { quantity += q; }
};

class Product : public Item {
public:
    Product(std::string n, int q, double p) : Item(n, q, p) {}
    void display() override {
        std::cout << std::setw(20) << name << std::setw(10) << quantity << std::setw(10) << price << std::endl;
    }
};

class Inventory {
private:
    std::vector<Item*> items;

public:
    void addItem(Item* item) {
        items.push_back(item);
    }

    void updateStock(std::string name, int quantity) {
        for (auto& item : items) {
            if (item>getName() == name) {
                item->updateQuantity(quantity);
                return;
            }
        }
        std::cout << "Item not found!" << std::endl;
    }

    void removeItem(std::string name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getName() /*
 * ============================================================
 *  PHARMACY INVENTORY MANAGEMENT SYSTEM
 *  Designed for: Nepali Pharmacy Businesses
 *  Language: C++ (OOP with File Handling)
 *  Author: [Your Name]
 *  Date: 2025
 *
 *  OOP Concepts Used:
 *    - Classes & Objects
 *    - Inheritance (Medicine -> PrescriptionMedicine, OTCMedicine)
 *    - Polymorphism (virtual functions)
 *    - Encapsulation (private data + public getters/setters)
 *    - File Handling (fstream for data persistence)
 * ============================================================
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <limits>

using namespace std;

// ============================================================
//  UTILITY FUNCTIONS
// ============================================================

// Get current date as a formatted string (YYYY-MM-DD)
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ostringstream oss;
    oss << (1900 + ltm->tm_year) << "-"
        << setw(2) << setfill('0') << (1 + ltm->tm_mon) << "-"
        << setw(2) << setfill('0') << ltm->tm_mday;
    return oss.str();
}

// Print a horizontal divider line
void printLine(char ch = '-', int width = 75) {
    cout << string(width, ch) << endl;
}

// Clear input buffer to avoid junk reads
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ============================================================
//  BASE CLASS: Medicine
//  Encapsulates all common attributes of a medicine item
// ============================================================
class Medicine {
protected:
    int     id;           // Unique item ID
    string  name;         // Medicine name (Nepali brand or generic)
    string  category;     // e.g., Antibiotic, Painkiller, Vitamin
    string  manufacturer; // e.g., Bioequivalence Lab Pvt. Ltd.
    double  price;        // Price in NPR (Nepali Rupees)
    int     quantity;     // Units currently in stock
    string  expiryDate;   // Format: YYYY-MM-DD
    string  batchNo;      // Batch number for traceability

public:
    // ----- Constructors -----

    // Default constructor
    Medicine()
        : id(0), name(""), category(""), manufacturer(""),
          price(0.0), quantity(0), expiryDate(""), batchNo("") {}

    // Parameterized constructor
    Medicine(int id, string name, string category, string manufacturer,
             double price, int quantity, string expiryDate, string batchNo)
        : id(id), name(name), category(category), manufacturer(manufacturer),
          price(price), quantity(quantity), expiryDate(expiryDate), batchNo(batchNo) {}

    // Virtual destructor (good OOP practice for inheritance)
    virtual ~Medicine() {}

    // ----- Getters (Encapsulation) -----
    int     getId()           const { return id; }
    string  getName()         const { return name; }
    string  getCategory()     const { return category; }
    string  getManufacturer() const { return manufacturer; }
    double  getPrice()        const { return price; }
    int     getQuantity()     const { return quantity; }
    string  getExpiryDate()   const { return expiryDate; }
    string  getBatchNo()      const { return batchNo; }

    // ----- Setters -----
    void setName(string n)         { name = n; }
    void setCategory(string c)     { category = c; }
    void setManufacturer(string m) { manufacturer = m; }
    void setPrice(double p)        { price = p; }
    void setQuantity(int q)        { quantity = q; }
    void setExpiryDate(string e)   { expiryDate = e; }
    void setBatchNo(string b)      { batchNo = b; }

    // ----- Virtual functions (Polymorphism) -----

    // Returns medicine type — overridden by subclasses
    virtual string getType() const { return "General"; }

    // Display a single row in the inventory table
    virtual void displayRow() const {
        cout << left
             << setw(5)  << id
             << setw(22) << name.substr(0, 20)
             << setw(16) << category.substr(0, 14)
             << setw(10) << getType()
             << setw(10) << quantity
             << setw(10) << fixed << setprecision(2) << price
             << setw(12) << expiryDate
             << endl;
    }

    // Serialize to CSV string for file storage
    virtual string toCSV() const {
        return to_string(id) + "," + name + "," + category + "," +
               manufacturer + "," + to_string(price) + "," +
               to_string(quantity) + "," + expiryDate + "," +
               batchNo + "," + getType();
    }
};

// ============================================================
//  DERIVED CLASS 1: PrescriptionMedicine
//  Medicines that require a doctor's prescription (e.g., antibiotics)
//  Demonstrates INHERITANCE and POLYMORPHISM
// ============================================================
class PrescriptionMedicine : public Medicine {
private:
    string prescribingDoctor; // Name of authorized prescriber type
    string schedule;          // Schedule (e.g., Schedule H, H1 under Nepal Drug Act)

public:
    PrescriptionMedicine() : Medicine(), prescribingDoctor(""), schedule("") {}

    PrescriptionMedicine(int id, string name, string category,
                         string manufacturer, double price, int quantity,
                         string expiryDate, string batchNo,
                         string prescribingDoctor, string schedule)
        : Medicine(id, name, category, manufacturer, price, quantity,
                   expiryDate, batchNo),
          prescribingDoctor(prescribingDoctor), schedule(schedule) {}

    string getPrescribingDoctor() const { return prescribingDoctor; }
    string getSchedule()          const { return schedule; }

    // Override: return type label
    string getType() const override { return "Rx"; }

    // Override: serialize with extra fields
    string toCSV() const override {
        return Medicine::toCSV() + "," + prescribingDoctor + "," + schedule;
    }
};

// ============================================================
//  DERIVED CLASS 2: OTCMedicine
//  Over-the-counter medicines (no prescription needed)
//  Demonstrates INHERITANCE and POLYMORPHISM
// ============================================================
class OTCMedicine : public Medicine {
private:
    string usage; // Short usage description (e.g., "Fever & Headache")

public:
    OTCMedicine() : Medicine(), usage("") {}

    OTCMedicine(int id, string name, string category,
                string manufacturer, double price, int quantity,
                string expiryDate, string batchNo, string usage)
        : Medicine(id, name, category, manufacturer, price, quantity,
                   expiryDate, batchNo),
          usage(usage) {}

    string getUsage() const { return usage; }

    // Override: return type label
    string getType() const override { return "OTC"; }

    // Override: serialize with extra field
    string toCSV() const override {
        return Medicine::toCSV() + "," + usage;
    }
};

// ============================================================
//  STRUCT: Transaction
//  Represents a single sale or purchase record
// ============================================================
struct Transaction {
    string date;
    string type;        // "SALE" or "PURCHASE"
    int    medicineId;
    string medicineName;
    int    quantity;
    double pricePerUnit;
    double totalAmount;

    // Serialize to CSV for file storage
    string toCSV() const {
        return date + "," + type + "," + to_string(medicineId) + "," +
               medicineName + "," + to_string(quantity) + "," +
               to_string(pricePerUnit) + "," + to_string(totalAmount);
    }
};

// ============================================================
//  CLASS: PharmacyInventory
//  Core system class — manages medicines, transactions, and files
// ============================================================
class PharmacyInventory {
private:
    vector<Medicine*>   inventory;    // Polymorphic collection of medicines
    vector<Transaction> transactions; // All sales & purchases

    const string INVENTORY_FILE   = "inventory.csv";
    const string TRANSACTION_FILE = "transactions.csv";

    int nextId; // Auto-increment ID counter

    // ---- Internal helpers ----

    // Find a medicine by ID; returns nullptr if not found
    Medicine* findById(int id) {
        for (auto* m : inventory)
            if (m->getId() == id) return m;
        return nullptr;
    }

    // Parse a line of CSV into tokens
    vector<string> parseCSV(const string& line) {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
            tokens.push_back(token);
        return tokens;
    }

public:
    // Constructor: load data from files on startup
    PharmacyInventory() : nextId(1) {
        loadInventory();
        loadTransactions();
    }

    // Destructor: save data and free heap memory
    ~PharmacyInventory() {
        saveInventory();
        saveTransactions();
        for (auto* m : inventory) delete m;
    }

    // ============================================================
    //  FILE HANDLING: Load inventory from CSV
    // ============================================================
    void loadInventory() {
        ifstream file(INVENTORY_FILE);
        if (!file.is_open()) return; // No file yet — fresh start

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = parseCSV(line);
            if (t.size() < 9) continue;

            int    id       = stoi(t[0]);
            string name     = t[1];
            string category = t[2];
            string mfr      = t[3];
            double price    = stod(t[4]);
            int    qty      = stoi(t[5]);
            string expiry   = t[6];
            string batch    = t[7];
            string type     = t[8];

            Medicine* med = nullptr;

            if (type == "Rx" && t.size() >= 11) {
                med = new PrescriptionMedicine(id, name, category, mfr,
                          price, qty, expiry, batch, t[9], t[10]);
            } else if (type == "OTC" && t.size() >= 10) {
                med = new OTCMedicine(id, name, category, mfr,
                          price, qty, expiry, batch, t[9]);
            } else {
                med = new Medicine(id, name, category, mfr,
                          price, qty, expiry, batch);
            }

            inventory.push_back(med);
            if (id >= nextId) nextId = id + 1;
        }
        file.close();
    }

    // ============================================================
    //  FILE HANDLING: Save inventory to CSV
    // ============================================================
    void saveInventory() {
        ofstream file(INVENTORY_FILE);
        for (auto* m : inventory)
            file << m->toCSV() << "\n";
        file.close();
    }

    // ============================================================
    //  FILE HANDLING: Load transactions from CSV
    // ============================================================
    void loadTransactions() {
        ifstream file(TRANSACTION_FILE);
        if (!file.is_open()) return;

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = parseCSV(line);
            if (t.size() < 7) continue;

            Transaction tx;
            tx.date         = t[0];
            tx.type         = t[1];
            tx.medicineId   = stoi(t[2]);
            tx.medicineName = t[3];
            tx.quantity     = stoi(t[4]);
            tx.pricePerUnit = stod(t[5]);
            tx.totalAmount  = stod(t[6]);
            transactions.push_back(tx);
        }
        file.close();
    }

    // ============================================================
    //  FILE HANDLING: Save transactions to CSV
    // ============================================================
    void saveTransactions() {
        ofstream file(TRANSACTION_FILE);
        for (auto& tx : transactions)
            file << tx.toCSV() << "\n";
        file.close();
    }

    // ============================================================
    //  FEATURE 1: Add New Medicine
    // ============================================================
    void addMedicine() {
        cout << "\n--- Add New Medicine ---\n";
        cout << "Type: 1) Prescription (Rx)  2) OTC  3) General\nChoice: ";
        int typeChoice;
        cin >> typeChoice;
        clearInputBuffer();

        string name, category, mfr, expiry, batch;
        double price;
        int qty;

        cout << "Medicine Name       : "; getline(cin, name);
        cout << "Category            : "; getline(cin, category);
        cout << "Manufacturer        : "; getline(cin, mfr);
        cout << "Price (NPR)         : "; cin >> price; clearInputBuffer();
        cout << "Quantity in Stock   : "; cin >> qty;   clearInputBuffer();
        cout << "Expiry Date (YYYY-MM-DD): "; getline(cin, expiry);
        cout << "Batch Number        : "; getline(cin, batch);

        Medicine* med = nullptr;

        if (typeChoice == 1) {
            string doctor, schedule;
            cout << "Prescribing Doctor Type : "; getline(cin, doctor);
            cout << "Schedule (e.g. H/H1/X)  : "; getline(cin, schedule);
            med = new PrescriptionMedicine(nextId, name, category, mfr,
                      price, qty, expiry, batch, doctor, schedule);
        } else if (typeChoice == 2) {
            string usage;
            cout << "Usage/Indication : "; getline(cin, usage);
            med = new OTCMedicine(nextId, name, category, mfr,
                      price, qty, expiry, batch, usage);
        } else {
            med = new Medicine(nextId, name, category, mfr,
                      price, qty, expiry, batch);
        }

        inventory.push_back(med);
        cout << "\n[OK] Medicine added with ID: " << nextId << endl;
        nextId++;
        saveInventory();
    }

    // ============================================================
    //  FEATURE 2: View Inventory (tabular display — polymorphism)
    // ============================================================
    void viewInventory() {
        if (inventory.empty()) {
            cout << "\n[INFO] No medicines in inventory.\n";
            return;
        }

        printLine('=');
        cout << "                  PHARMACY INVENTORY  |  Date: " << getCurrentDate() << endl;
        printLine('=');
        cout << left
             << setw(5)  << "ID"
             << setw(22) << "Name"
             << setw(16) << "Category"
             << setw(10) << "Type"
             << setw(10) << "Qty"
             << setw(10) << "Price(NPR)"
             << setw(12) << "Expiry"
             << endl;
        printLine();

        // Polymorphic call — each subclass displays its row
        for (auto* m : inventory)
            m->displayRow();

        printLine();
        cout << "Total Items: " << inventory.size() << endl;
    }

    // ============================================================
    //  FEATURE 3: Update Stock
    // ============================================================
    void updateStock() {
        cout << "\n--- Update Stock ---\n";
        cout << "Enter Medicine ID: ";
        int id; cin >> id; clearInputBuffer();

        Medicine* med = findById(id);
        if (!med) { cout << "[ERROR] Medicine not found.\n"; return; }

        cout << "Current Stock of \"" << med->getName() << "\": " << med->getQuantity() << endl;
        cout << "1) Add Stock (Purchase)\n2) Reduce Stock (Manual Adjustment)\nChoice: ";
        int choice; cin >> choice; clearInputBuffer();

        cout << "Enter Quantity: ";
        int qty; cin >> qty; clearInputBuffer();

        if (choice == 1) {
            med->setQuantity(med->getQuantity() + qty);

            // Record purchase transaction
            Transaction tx;
            tx.date         = getCurrentDate();
            tx.type         = "PURCHASE";
            tx.medicineId   = id;
            tx.medicineName = med->getName();
            tx.quantity     = qty;
            tx.pricePerUnit = med->getPrice();
            tx.totalAmount  = qty * med->getPrice();
            transactions.push_back(tx);

            cout << "[OK] Stock updated. New quantity: " << med->getQuantity() << endl;
        } else {
            if (qty > med->getQuantity()) {
                cout << "[ERROR] Insufficient stock.\n";
                return;
            }
            med->setQuantity(med->getQuantity() - qty);
            cout << "[OK] Stock adjusted. New quantity: " << med->getQuantity() << endl;
        }
        saveInventory();
        saveTransactions();
    }

    // ============================================================
    //  FEATURE 4: Record a Sale
    // ============================================================
    void recordSale() {
        cout << "\n--- Record Sale ---\n";
        cout << "Enter Medicine ID: ";
        int id; cin >> id; clearInputBuffer();

        Medicine* med = findById(id);
        if (!med) { cout << "[ERROR] Medicine not found.\n"; return; }

        cout << "Medicine : " << med->getName() << " | Stock: " << med->getQuantity()
             << " | Price: NPR " << fixed << setprecision(2) << med->getPrice() << endl;

        cout << "Quantity to Sell: ";
        int qty; cin >> qty; clearInputBuffer();

        if (qty > med->getQuantity()) {
            cout << "[ERROR] Not enough stock. Available: " << med->getQuantity() << endl;
            return;
        }

        double total = qty * med->getPrice();
        med->setQuantity(med->getQuantity() - qty);

        // Record sale transaction
        Transaction tx;
        tx.date         = getCurrentDate();
        tx.type         = "SALE";
        tx.medicineId   = id;
        tx.medicineName = med->getName();
        tx.quantity     = qty;
        tx.pricePerUnit = med->getPrice();
        tx.totalAmount  = total;
        transactions.push_back(tx);

        cout << fixed << setprecision(2);
        cout << "\n--- RECEIPT ---\n";
        cout << "Medicine : " << med->getName() << endl;
        cout << "Quantity : " << qty << endl;
        cout << "Rate     : NPR " << med->getPrice() << endl;
        cout << "TOTAL    : NPR " << total << endl;

        saveInventory();
        saveTransactions();
    }

    // ============================================================
    //  FEATURE 5: Remove a Medicine
    // ============================================================
    void removeMedicine() {
        cout << "\n--- Remove Medicine ---\n";
        cout << "Enter Medicine ID to remove: ";
        int id; cin >> id; clearInputBuffer();

        auto it = find_if(inventory.begin(), inventory.end(),
                          [id](Medicine* m) { return m->getId() == id; });

        if (it == inventory.end()) {
            cout << "[ERROR] Medicine not found.\n";
            return;
        }

        cout << "Remove \"" << (*it)->getName() << "\"? (y/n): ";
        char confirm; cin >> confirm; clearInputBuffer();

        if (confirm == 'y' || confirm == 'Y') {
            delete *it;
            inventory.erase(it);
            cout << "[OK] Medicine removed.\n";
            saveInventory();
        } else {
            cout << "[Cancelled]\n";
        }
    }

    // ============================================================
    //  FEATURE 6: Search Medicine by Name
    // ============================================================
    void searchMedicine() {
        cout << "\n--- Search Medicine ---\n";
        cout << "Enter name keyword: ";
        string keyword; getline(cin, keyword);

        // Convert keyword to lowercase for case-insensitive search
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

        bool found = false;
        printLine();
        cout << left
             << setw(5)  << "ID"
             << setw(22) << "Name"
             << setw(16) << "Category"
             << setw(10) << "Type"
             << setw(10) << "Qty"
             << setw(10) << "Price"
             << setw(12) << "Expiry"
             << endl;
        printLine();

        for (auto* m : inventory) {
            string nameLower = m->getName();
            transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
            if (nameLower.find(keyword) != string::npos) {
                m->displayRow(); // Polymorphic display
                found = true;
            }
        }

        if (!found) cout << "[INFO] No medicines matched \"" << keyword << "\".\n";
        printLine();
    }

    // ============================================================
    //  FEATURE 7: Low Stock Alert
    // ============================================================
    void lowStockAlert() {
        cout << "\n--- Low Stock Alert (Qty <= 10) ---\n";
        printLine();
        bool any = false;
        for (auto* m : inventory) {
            if (m->getQuantity() <= 10) {
                cout << "  [LOW] ID:" << m->getId()
                     << " | " << m->getName()
                     << " | Qty: " << m->getQuantity()
                     << " | Category: " << m->getCategory()
                     << endl;
                any = true;
            }
        }
        if (!any) cout << "  All items are sufficiently stocked.\n";
        printLine();
    }

    // ============================================================
    //  FEATURE 8: Generate Sales/Purchase Report
    // ============================================================
    void generateReport() {
        cout << "\n--- Reports ---\n";
        cout << "1) All Transactions\n2) Sales Only\n3) Purchases Only\nChoice: ";
        int choice; cin >> choice; clearInputBuffer();

        string filterType = "";
        if (choice == 2) filterType = "SALE";
        if (choice == 3) filterType = "PURCHASE";

        printLine('=');
        cout << "        TRANSACTION REPORT  |  Generated: " << getCurrentDate() << endl;
        printLine('=');
        cout << left
             << setw(12) << "Date"
             << setw(10) << "Type"
             << setw(5)  << "ID"
             << setw(22) << "Medicine"
             << setw(8)  << "Qty"
             << setw(14) << "Price/Unit"
             << setw(14) << "Total (NPR)"
             << endl;
        printLine();

        double grandTotal = 0.0;
        int count = 0;

        for (auto& tx : transactions) {
            if (!filterType.empty() && tx.type != filterType) continue;
            cout << left
                 << setw(12) << tx.date
                 << setw(10) << tx.type
                 << setw(5)  << tx.medicineId
                 << setw(22) << tx.medicineName.substr(0, 20)
                 << setw(8)  << tx.quantity
                 << setw(14) << fixed << setprecision(2) << tx.pricePerUnit
                 << setw(14) << tx.totalAmount
                 << endl;
            grandTotal += tx.totalAmount;
            count++;
        }

        printLine();
        cout << "Transactions: " << count
             << " | GRAND TOTAL: NPR " << fixed << setprecision(2) << grandTotal << endl;
        printLine('=');
    }

    // ============================================================
    //  FEATURE 9: Expiry Check
    // ============================================================
    void checkExpiry() {
        string today = getCurrentDate();
        cout << "\n--- Expiry Status ---\n";
        printLine();
        bool any = false;
        for (auto* m : inventory) {
            if (m->getExpiryDate() <= today) {
                cout << "  [EXPIRED/DUE] ID:" << m->getId()
                     << " | " << m->getName()
                     << " | Expiry: " << m->getExpiryDate()
                     << " | Batch: " << m->getBatchNo()
                     << endl;
                any = true;
            }
        }
        if (!any) cout << "  No expired or due-to-expire medicines found.\n";
        printLine();
    }
};

// ============================================================
//  MAIN: Menu-Driven Console Interface
// ============================================================
int main() {
    PharmacyInventory pharmacy;

    cout << "\n";
    printLine('*', 75);
    cout << "*        WELCOME TO NEPAL PHARMACY INVENTORY MANAGEMENT SYSTEM          *\n";
    cout << "*                  Powered by C++ OOP  |  NPR Currency                  *\n";
    printLine('*', 75);

    int choice;
    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << " 1. View Inventory\n";
        cout << " 2. Add New Medicine\n";
        cout << " 3. Update Stock (Purchase)\n";
        cout << " 4. Record Sale\n";
        cout << " 5. Remove Medicine\n";
        cout << " 6. Search Medicine\n";
        cout << " 7. Low Stock Alert\n";
        cout << " 8. Sales / Purchase Report\n";
        cout << " 9. Expiry Date Check\n";
        cout << " 0. Exit\n";
        cout << "================================\n";
        cout << "Enter choice: ";
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1: pharmacy.viewInventory();  break;
            case 2: pharmacy.addMedicine();    break;
            case 3: pharmacy.updateStock();    break;
            case 4: pharmacy.recordSale();     break;
            case 5: pharmacy.removeMedicine(); break;
            case 6: pharmacy.searchMedicine(); break;
            case 7: pharmacy.lowStockAlert();  break;
            case 8: pharmacy.generateReport(); break;
            case 9: pharmacy.checkExpiry();    break;
            case 0:
                cout << "\nData saved. Thank you for using Nepal Pharmacy IMS. Bye!\n";
                break;
            default:
                cout << "[ERROR] Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}== name) {
                delete *it;
                items.erase(it);
                return;
            }
        }
        std::cout << "Item not found!" << std::endl;
    }

    void viewInventory() {
        std::cout << std::setw(20) << "Name" << std::setw(10) << "Quantity" << std::setw(10) << "Price" << std::endl;
        for (auto& item : items) {
            item->display();
        }
    }

    void saveToFile() {
        std::ofstream file("inventory.txt");
        for (auto& item : items) {
            file << item->getName() << " " << item->getQuantity() << " " << item->getPrice() << std::endl;
        }
        file.close();
    }

    void loadFromFile() {
        std::ifstream file("inventory.txt");
        std::string name;
        int quantity;
        double price;
        while (file >> name >> quantity >> price) {
            addItem(new Product(name, quantity, price));
        }
        file.close();
    }
};

int main() {
    Inventory inventory;
    inventory.loadFromFile();

    int choice;
    do {
        std::cout << "1. Add Item\n2. Update Stock\n3. Remove Item\n4. View Inventory\n5. Save & Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int quantity;
            double price;
            std::cout << "Enter item name, quantity, and price: ";
            std::cin >> name >> quantity >> price;
            inventory.addItem(new Product(name, quantity, price));
        } else if (choice == 2) {
            std::string name;
            int quantity;
            std::cout << "Enter item name and quantity to update: ";
            std::cin >> name >> quantity;
            inventory.updateStock(name, quantity);
        } else if (choice == 3) {
            std::string name;
            std::cout << "Enter item name to remove: ";
            std::cin >> name;
            inventory.removeItem(name);
        } else if (choice == 4) {
            inventory.viewInventory();
        }
    } while (choice != 5);

    inventory.saveToFile();
    return 0;
}
