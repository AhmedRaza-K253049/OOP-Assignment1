#include <iostream>
#include <string>
using namespace std;

class Message{
    private:
        string Sender;
        string Reciever;
        string Data;
        static int MessageID;
        bool Seen;
    public:
        Message(string s, string r, string d){
            Sender = s;
            Reciever = r;
            Data = d;
            Seen = false;
            MessageID++;
        }
        void sendMessage(){
            cout<< "Message '"<< Data<< "' to "<< Reciever;
        }
        void Seen(){Seen = true;}
};

class Transmission{
    private:
        int Gear;
        string Type;
        bool automatic;
        bool paddleShift;
        string PowerType;
    public:
        Transmission(){};
        Transmission(int G, string T, bool A, bool P, string PW): Gear(G), Type(T), automatic(A), paddleShift(P), PowerType(PW){}
        void Display(){
            cout<< "Transmission Type: "<< Type<< endl;
            cout<< "Gears: "<< Gear<< endl;
            cout<< "Automatic: "<< (automatic ? "Yes" : "No")<< endl;
            cout<< "Paddle Shift: "<< (paddleShift ? "Yes" : "No")<< endl;
            cout<< "Power: "<< PowerType<< endl;
        }

        int getGear(){return Gear;}
        string getType(){return Type;}
        bool getAutomatic(){return automatic;}
        bool getPaddleShift(){return paddleShift;}
        string getPowerType(){return PowerType;}

        void service(){
            cout<< "Transmission Serviced"<< endl;
        }
        void toggleMode(){
            automatic = !automatic;
            Type = automatic ? "Automatic" : "Manual";
        }
        void gearChange(int G){
            if(G > 0 && G <= Gear){
                cout<< "Shifted to gear "<< G<< endl;
            }else{
                cout<< "Invalid gear"<< endl;
            }
        }
        void paddleShift(int G){
            if(paddleShift){
                gearChange(G);
            }else{
                cout<< "Paddle shift not available"<< endl;
            }
        }
};

class Engine{
    private:
        int CC;
        string FuelType;
        int Cylinder;
        int Turbo;
    public:
        Engine(){};
        Engine(int CCIn, string FuelIn, int CylinderIn, int TurboIn){
            CC = CCIn;
            FuelType = FuelIn;
            Cylinder = CylinderIn;
            Turbo = TurboIn;
        }
        void Display(){
            cout<< "Engine CC: "<< CC<< endl;
            cout<< "Fuel Type: "<< FuelType<< endl;
            cout<< "Cylinder: "<< Cylinder<< endl;
            cout<< "Turbo: "<< (Turbo ? "Yes" : "No")<< endl;
        }
        int getCC(){return CC;}
        string getFuelType(){return FuelType;}
        int getCylinder(){return Cylinder;}
        int getTurbo(){return Turbo;}
        void service(){
            cout<< "Engine Serviced"<< endl;
        }
};
class Car{
private:
    static int CarCount;
    int Id;
    string Company;
    string Name;
    Engine engine;
    int Mileage;
    Transmission transmission;
    int Price;
    int RegisterationYear;
public:
    Car(){};
    Car(string CIn, string NIn, int MIn, int PIn, int RIn, int CC, string FIn, int CylinderIn, int TurboIn, int G, string T, bool A, bool P, string PW): engine(CC, FIn, CylinderIn, TurboIn), transmission(G, T, A, P, PW), Id(CarCount++){
        Company = CIn;
        Name = NIn;
        Mileage = MIn;
        Price = PIn;
        RegisterationYear = RIn;
    }
    string returnCompany(){return Company;}
    string returnName(){return Name;}
    int returnMileage(){return Mileage;}
    int returnRegisterationYear(){return RegisterationYear;}
    int returnPrice(){return Price;}
    int returnID(){return Id;}
    
    void setCompany(string input){Company = input;}
    void setName(string input){Name = input;}
    void setMileage(int input){Mileage = input;}
    void setRegisterationYear(int input){RegisterationYear = input;}
    void setPrice(int input){Price = input;}

    void Display(){
        cout<< "Car ID: "<< Id<< endl;
        cout<< "Company: "<< Company<< endl;
        cout<< "Name: "<< Name<<endl;
        cout<< "Mileage: "<< Mileage<< endl;
        cout<< "Registered In Year: "<< RegisterationYear<< endl;
        cout<< "Price: "<< Price<< endl;
        engine.Display();
        transmission.Display();
    }
};

class CarList
{
    private:
        static int ListID;
        Car Cars[50];
};

class Browser{
    private:
        static int UserCount;
        const int UserID;
        string Name;
        string Number;
        string Email;
    public:
        Browser(string n, string no, string e): Name(n), Number(no), Email(e), UserID(UserCount++){}
        void displayInfo(){
            cout<< "UserID: "<< UserID<< endl;
            cout<< "Name: "<< Name<< endl;
            cout<< "Number: "<< Number<< endl;
            cout<< "Email : "<< Email<< endl;
        }
    
};

class Seller{
    private:
        static int UserCount;
        const int UserID;
        string Name;
        const int Number;
        const string Email;
        Car Selling[5];
        int SellingCount;
    public:

        Seller(string NameIn, string EmailIn, string PasswordIn, int NumberIn): Email(EmailIn), Number(NumberIn), UserID(UserCount++){
            Name = NameIn;
            SellingCount = 0;
        }
        void addCar(Car *&ApprovalList,int *ApprovalListIndex, int *size,string CIn, string NIn, int MIn, int PIn, int RIn, int CC, string FIn, int CylinderIn, int TurboIn, int G, string T, bool A, bool P, string PW){
            if(*ApprovalListIndex >= *size){
                Car *temp = new Car[*size * 2];
                for(int i = 0; i < *size; i++){
                    temp[i] = ApprovalList[i]; 
                }
                delete[] ApprovalList;
                ApprovalList = temp;
                ApprovalList[*ApprovalListIndex] = Car(CIn, NIn, MIn, PIn, RIn, CC, FIn, CylinderIn, TurboIn, G, T, A, P, PW);
                (*ApprovalListIndex)++;
            }
        }
        void removeCar(Car *&ApprovalList,int *ApprovalListIndex, int size, int IdIn){
            for(int i = 0; i < SellingCount; i++){
                if(Selling[i].returnID() == IdIn){
                    for(int j = i; j < SellingCount; j++){
                        Selling[j] = Selling[j + 1];
                    }
                SellingCount--;
                }
            }
            for(int i = 0; i < *ApprovalListIndex; i++){
                if(ApprovalList[i].returnID() == IdIn){
                    for(int j = i; j < *ApprovalListIndex; j++){
                        ApprovalList[j] = ApprovalList[j + 1];
                    }
                *ApprovalListIndex--;
                }
            }
        }
};
class Buyer{
   private:
        static int UserCount;
        const int UserID;
        string Name;
        const string Email;
        const int Number;
        Car **Favourite;
        int FavouriteMax;
        int FavouriteCount;
    public:
        Buyer(string NameIn, string EmailIn, string PasswordIn, int NumberIn): Email(EmailIn), Number(NumberIn), UserID(UserCount++){
            Name = NameIn;
            FavouriteCount = 0;
            FavouriteMax = 5;
            Favourite = new Car*[5];
        }
        void addFavourite(Car *obj){
            if(FavouriteCount < FavouriteMax){
                Favourite[FavouriteCount] = obj;
                FavouriteCount++;
            }else{
                Car **temp;
                temp = new Car*[FavouriteMax * 2];
                for(int i = 0; i < FavouriteMax; i++){
                    temp[i] = Favourite[i];
                }
                temp[FavouriteCount] = obj;
                delete[] Favourite;
                Favourite = temp;
                FavouriteCount++;
                FavouriteMax *= 2;
            }
        }
        void removeFavourite(int IdIn){
            for(int i = 0; i < FavouriteCount; i++){
                if(Favourite[i]->returnID() == IdIn){
                    for(int j = i; j < FavouriteCount; j++){
                        Favourite[j] = Favourite[j + 1];
                    }
                FavouriteCount--;
                }
            }
        }
};
class Admin{
    private:
        string Name;
        string Email;
        string Role;
        int Approved;
        int Rejected;
    public:
        Admin(string N, string E, string R, int A, int RJ){
            Name = N;
            Email = E;
            Role = R;
            Approved = A;
            Rejected = RJ;
        }
        void Displa(){
            cout<< "Name: "<< Name<< endl;
            cout<< "Email: "<< Email<< endl;
            cout<< "Role: "<< Role<< endl;
            cout<< "Approved Cars: "<< Approved<< endl;
            cout<< "Rejected Cars: "<< Rejected<< endl;
        }
        void approveCar(Car *ApprovalList, int *ApprovalListIndex, Car *&Database, int *DatabaseIndex, int *DatabaseSize){
            int temp;
            for(int i = 0; i < *ApprovalListIndex; i++){
                ApprovalList[i].Display();
            }
            cout<< "What Car Do You Want To Approve: "; cin>> temp;
            if(*DatabaseIndex > *DatabaseSize){
                Car *tempDatabase = new Car[*DatabaseSize * 2];
                for(int i = 0; i < *DatabaseIndex; i++){
                    tempDatabase[i] = Database[i];
                }
                delete[] Database;
                Database = tempDatabase;
                (*DatabaseSize) *= 2;
            }
            for(int i = 0; i < *DatabaseIndex; i++){
                if(i == temp){
                    Database[*DatabaseIndex] = ApprovalList[i];
                    for(int j = i; j < *ApprovalListIndex; j++){
                        ApprovalList[j] = ApprovalList[j + 1];
                    }
                    (*DatabaseIndex)++;
                    (*ApprovalListIndex)--;
                }
            }
            Approved++;
        }
        void rejectCar(Car *ApprovalList, int *ApprovalListIndex, int ApprovalListSize){
            int temp;
            for(int i = 0; i < *ApprovalListIndex; i++){
                ApprovalList[i].Display();
            }
            cout<< "What Car Do You Want To Reject: "; cin>> temp;
            for(int i = temp; i < ApprovalListSize - 1; i++){
                ApprovalList[i + 1] = ApprovalList[i];
            }
            (*ApprovalListIndex)--;
            Rejected++;
        }
};