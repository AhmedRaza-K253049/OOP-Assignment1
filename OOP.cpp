#include <iostream>
#include <string>
using namespace std;

/* ================= ENGINE ================= */
class Engine {
private:
    string type;
    int horsepower;
    float capacity;
    string fuelType;
    bool turbo;

public:
    Engine() : type("Petrol"), horsepower(100), capacity(1.3), fuelType("Petrol"), turbo(false) {}
    Engine(string t, int hp, float c, string f, bool tb)
        : type(t), horsepower(hp), capacity(c), fuelType(f), turbo(tb) {}
    Engine(const Engine& e)
        : type(e.type), horsepower(e.horsepower), capacity(e.capacity),
          fuelType(e.fuelType), turbo(e.turbo) {}

    void start() { cout << "Engine started\n"; }
    void stop() { cout << "Engine stopped\n"; }
    void display() const {
        cout << "Engine: " << type << " " << horsepower << "HP "
             << capacity << "L " << fuelType
             << (turbo ? " Turbo\n" : "\n");
    }
    void service() { cout << "Engine serviced\n"; }
};

/* ================= TRANSMISSION ================= */
class Transmission {
private:
    string type;
    int gears;
    bool automatic;
    string driveType;
    bool paddleShift;

public:
    Transmission() : type("Manual"), gears(5), automatic(false), driveType("FWD"), paddleShift(false) {}
    Transmission(string t, int g, bool a, string d, bool p)
        : type(t), gears(g), automatic(a), driveType(d), paddleShift(p) {}
    Transmission(const Transmission& t)
        : type(t.type), gears(t.gears), automatic(t.automatic),
          driveType(t.driveType), paddleShift(t.paddleShift) {}

    void shiftGear(int g) { cout << "Shifted to gear " << g << endl; }
    void display() const { cout << "Transmission: " << type << " " << gears << " gears\n"; }
    void toggleMode() { automatic = !automatic; }
    void service() { cout << "Transmission serviced\n"; }
};

/* ================= VEHICLE (COMPOSITION) ================= */
class Vehicle {
private:
    const int vehicleID;
    string brand;
    string model;
    int year;
    double mileage;
    Engine engine;
    Transmission transmission;

public:
    Vehicle(int id, string b, string m, int y, double mil,
            Engine e, Transmission t)
        : vehicleID(id), brand(b), model(m), year(y),
          mileage(mil), engine(e), transmission(t) {}

    Vehicle(const Vehicle& v)
        : vehicleID(v.vehicleID), brand(v.brand), model(v.model),
          year(v.year), mileage(v.mileage),
          engine(v.engine), transmission(v.transmission) {}

    void displaySpecs() const {
        cout << brand << " " << model << " (" << year << ")\n";
        cout << "Mileage: " << mileage << " km\n";
        engine.display();
        transmission.display();
    }

    void updateMileage(double m) { mileage = m; }
    void compareYear(const Vehicle& v) {
        cout << (year > v.year ? "Newer vehicle\n" : "Older vehicle\n");
    }
    string getBrand() const { return brand; }
    int getYear() const { return year; }
};

/* ================= LISTING (COMPOSITION) ================= */
class Listing {
private:
    const int listingID;
    Vehicle vehicle;
    double price;
    string city;
    bool approved;
    static int totalListings;

public:
    Listing(int id, Vehicle v, double p, string c)
        : listingID(id), vehicle(v), price(p), city(c), approved(false) {
        totalListings++;
    }

    Listing(const Listing& l)
        : listingID(l.listingID), vehicle(l.vehicle),
          price(l.price), city(l.city), approved(l.approved) {}

    void approve() { approved = true; }
    void deactivate() { approved = false; }
    void updatePrice(double p) { price = p; }

    void display() const {
        cout << "\nListing ID: " << listingID << endl;
        vehicle.displaySpecs();
        cout << "Price: " << price << " | City: " << city
             << " | Status: " << (approved ? "Approved\n" : "Pending\n");
    }

    string getBrand() const { return vehicle.getBrand(); }
    int getYear() const { return vehicle.getYear(); }
    double getPrice() const { return price; }
};
int Listing::totalListings = 0;

/* ================= USER ================= */
class User {
protected:
    const int userID;
    string name;
    string email;
    string password;
    string phone;
    static int totalUsers;

public:
    User(int id, string n, string e, string p, string ph)
        : userID(id), name(n), email(e), password(p), phone(ph) {
        totalUsers++;
    }

    User(const User& u)
        : userID(u.userID), name(u.name),
          email(u.email), password(u.password), phone(u.phone) {}

    virtual void login() { cout << name << " logged in\n"; }
    virtual void logout() { cout << name << " logged out\n"; }
    virtual void displayProfile() const {
        cout << "User: " << name << " | Email: " << email << endl;
    }
    virtual void updatePhone(string ph) { phone = ph; }
};
int User::totalUsers = 0;

/* ================= MESSAGE ================= */
class Message {
private:
    const int messageID;
    User* sender;
    User* receiver;
    string text;
    bool seen;
    string timestamp;

public:
    Message(int id, User* s, User* r, string t)
        : messageID(id), sender(s), receiver(r),
          text(t), seen(false), timestamp("Now") {}

    void send() { cout << "Message sent: " << text << endl; }
    void markSeen() { seen = true; }
    void display() const {
        cout << "Message: " << text
             << " | Status: " << (seen ? "Seen\n" : "Unseen\n");
    }
    void deleteMessage() { text = ""; }
};

/* ================= BUYER (AGGREGATION) ================= */
class Buyer : public User {
private:
    Listing* favorites[10];
    int favCount;
    double budget;
    string preferredBrand;
    bool verified;

public:
    Buyer(int id, string n, string e, string p, string ph,
          double b, string pb)
        : User(id, n, e, p, ph),
          favCount(0), budget(b),
          preferredBrand(pb), verified(false) {}

    void addToFavorites(Listing* l) {
        if (favCount < 10) favorites[favCount++] = l;
    }

    void viewFavorites() const {
        for (int i = 0; i < favCount; i++)
            favorites[i]->display();
    }

    void sendMessage(User* seller, string msgText) {
        Message msg(1, this, seller, msgText);
        msg.send();
    }

    void verify() { verified = true; }
};

/* ================= SELLER ================= */
class Seller : public User {
private:
    Listing* listings[10];
    int listingCount;
    float rating;
    int totalSales;
    bool verified;

public:
    Seller(int id, string n, string e, string p, string ph)
        : User(id, n, e, p, ph),
          listingCount(0), rating(5.0),
          totalSales(0), verified(false) {}

    void addListing(Listing* l) {
        if (listingCount < 10) listings[listingCount++] = l;
    }

    void removeListing(int index) {
        if (index < listingCount)
            listings[index]->deactivate();
    }

    void respondMessage(string msg) {
        cout << "Seller reply: " << msg << endl;
    }

    void verify() { verified = true; }
};

/* ================= ADMIN ================= */
class Admin : public User {
private:
    string role;
    int approvals;
    int removals;
    bool superAdmin;
    const string adminCode;

public:
    Admin(int id, string n, string e, string p, string ph,
          string code)
        : User(id, n, e, p, ph),
          role("Moderator"), approvals(0),
          removals(0), superAdmin(false),
          adminCode(code) {}

    void approveListing(Listing& l) {
        l.approve();
        approvals++;
    }

    void removeListing(Listing& l) {
        l.deactivate();
        removals++;
    }

    void viewStats() const {
        cout << "Approvals: " << approvals
             << " | Removals: " << removals << endl;
    }

    void promote() { superAdmin = true; }
};

/* ================= MARKETPLACE ================= */
class Marketplace {
private:
    const string platformName;
    Listing* listings[50];
    int listingCount;
    const float MAX_PRICE_LIMIT = 100000000;

public:
    Marketplace(string name)
        : platformName(name), listingCount(0) {}

    void addListing(Listing* l) {
        if (listingCount < 50)
            listings[listingCount++] = l;
    }

    void search(string brand, int year, double maxPrice) {
        cout << "\nSearch Results:\n";
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]->getBrand() == brand &&
                listings[i]->getYear() >= year &&
                listings[i]->getPrice() <= maxPrice)
                listings[i]->display();
        }
    }

    void showAll() {
        for (int i = 0; i < listingCount; i++)
            listings[i]->display();
    }

    void displayPlatform() const {
        cout << "Welcome to " << platformName << endl;
    }
};

/* ================= MAIN ================= */
int main() {

    Marketplace market("PakWheels Clone");

    Engine e1("Petrol", 130, 1.6, "Petrol", false);
    Transmission t1("Automatic", 6, true, "FWD", false);

    Vehicle v1(1, "Toyota", "Corolla", 2020, 45000, e1, t1);
    Listing l1(101, v1, 4500000, "Karachi");

    Seller seller(1, "Ali", "ali@mail.com", "123", "0300");
    Buyer buyer(2, "Ahmed", "ahmed@mail.com", "123", "0311", 5000000, "Toyota");
    Admin admin(3, "Admin", "admin@mail.com", "admin", "0000", "ADM001");

    market.addListing(&l1);
    seller.addListing(&l1);

    admin.approveListing(l1);

    market.displayPlatform();
    market.showAll();

    market.search("Toyota", 2018, 5000000);

    buyer.addToFavorites(&l1);
    buyer.viewFavorites();

    buyer.sendMessage(&seller, "Is the car available?");
    seller.respondMessage("Yes, it is available.");

    admin.viewStats();

    return 0;
}