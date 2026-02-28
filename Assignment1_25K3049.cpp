#include <iostream>
#include <string>
using namespace std;

class Message;
class Transmission;
class Engine;
class Car;
class CarList;
class Seller;
class Buyer;
class Admin;

class Transmission{
    private:
        int Gear;
        string Type;
        bool Automatic;
        bool PaddleShift;
        string PowerType;
    public:
        Transmission(){};
        Transmission(int GearIn, string TypeIn, int AutomaticIn, int PaddleShiftIn, string PowerTypeIn): Gear(GearIn), Type(TypeIn), Automatic(AutomaticIn), PaddleShift(PaddleShiftIn), PowerType(PowerTypeIn){}
        void Display(){
            cout<< "Transmission Type: "<< Type<< endl;
            cout<< "Gears: "<< Gear<< endl;
            cout<< "Automatic: "<< (Automatic ? "Yes" : "No")<< endl;
            cout<< "Paddle Shift: "<< (PaddleShift ? "Yes" : "No")<< endl;
            cout<< "Power: "<< PowerType<< endl;
        }

        int getGear(){return Gear;}
        string getType(){return Type;}
        bool getAutomatic(){return Automatic;}
        bool getPaddleShift(){return PaddleShift;}
        string getPowerType(){return PowerType;}

        void setPedalPositive(){PaddleShift = true;}
        void setPedalNegative(){PaddleShift = false;}
        void setManual(){Type = "Manual";}
        void setAutomatic(){Type = "Automatic";}
        void service(){
            cout<< "Transmission Serviced"<< endl;
        }
        void toggleMode(){
            Automatic = !Automatic;
            Type = Automatic ? "Automatic" : "Manual";
        }
        void gearChange(int G){
            if(G > 0 && G <= Gear){
                cout<< "Shifted to gear "<< G<< endl;
            }else{
                cout<< "Invalid gear"<< endl;
            }
        }
        void changePaddleShift(int G){
            if(PaddleShift){
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
        bool Turbo;
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
    Car(string CompanyNameIn, string NameIn, string TypeIn, int MileageIn, int PriceIn, int RegistrationIn, int CCIn, string FuelIn, int CylinderIn, int TurboIn, int GearIn, int AutomaticIn, int PaddleShiftIn, string PowerTypeIn)
    :engine(CCIn, FuelIn, CylinderIn, TurboIn), transmission(GearIn, TypeIn, AutomaticIn, PaddleShiftIn, PowerTypeIn){
        Company = CompanyNameIn;
        Name = NameIn;
        Mileage = MileageIn;
        Price = PriceIn;
        RegisterationYear = RegistrationIn;
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

class Browser{
    private:
        const int UserID;
        string Name;
        string Number;
        string Email;
    public:
        static int UserCount;
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
        int UserID;
        string Name;
        int Number;
        string Email;
    public:
        Seller(){}
        Seller(string NameIn, string EmailIn, int NumberIn){
            UserID = Browser:: UserCount++;
            Email = EmailIn;
            Number = NumberIn;
            Name = NameIn;
        }
        void Display(){
            cout<< "UserID: "<< UserID<< endl;
            cout<< "Name: "<< Name<< endl;
            cout<< "Number: "<< Number<< endl;
            cout<< "Email : "<< Email<< endl;
        }
};

class Buyer{
   private:
        int UserID;
        string Name;
        string Email;
        int Number;
        Car **Favourite;
        int FavouriteMax;
        int FavouriteCount;
    public:
        Buyer(){}
        Buyer(string NameIn, string EmailIn, string PasswordIn, int NumberIn){
            Number = NumberIn;  
            UserID = Browser:: UserCount++;
            Email = EmailIn;
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
        int UserID;
        int Approved;
        int Rejected;
    public:
        Admin(){}
        Admin(string NameIn, string EmailIn){
            UserID = Browser:: UserCount++;
            Name = NameIn;
            Email = EmailIn;
            Approved = 0;
            Rejected = 0;
        }
        void Display(){
            cout<< "Name: "<< Name<< endl;
            cout<< "Email: "<< Email<< endl;
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

class CarList{
    private:
        int ListID;
        static int ListCount;
        Car thisCar;
        Seller thisSeller;
    public:
        CarList(){}
        CarList(string CompanyNameIn, string NameIn, int MileageIn, int PriceIn, int RegistrationYearIn, int CC, string FuelIn, int CylinderIn, int TurboIn, int GearIn, int AutomaticIn, int PaddleShiftIn, string PowerTypeIn, string SellerNameIn, string EmailIn, int NumberIn)
        :thisCar(CompanyNameIn, NameIn, MileageIn, PriceIn, RegistrationYearIn, CC, FuelIn, CylinderIn, TurboIn, GearIn, AutomaticIn, PaddleShiftIn, PowerTypeIn), thisSeller(SellerNameIn, EmailIn, NumberIn), ListID(ListCount++){}
        
        int getListID(){return ListID;}
        static int getList(){return ListCount;}
        Car getCar(){return thisCar;}
        Seller getSeller(){return thisSeller;}
        void display(){
            cout<< "List ID: "<< ListID<< endl;
            thisCar.Display();
            thisSeller.Display();
        }
};
int CarList:: ListCount = 0;
int Message:: MessageID = 0;
int Browser:: UserCount = 0;

void addCar(Car *&ApprovalList,int *ApprovalListIndex, int *size){
    string CompanyNameIn, NameIn, FuelIn, NameIn, PowerTypeIn, EmailIn, TypeIn;
    int MileageIn, PriceIn, RegistrationYearIn, CC, NumberIn, CylinderIn, TurboIn, GearIn, PaddleShiftIn, AutomaticIn;
    cout<< "Enter Car Company: "; cin>> CompanyNameIn;
    cout<< "Enter Car Name: "; cin>> NameIn;
    cout<< "Enter Car Mileage: "; cin>> MileageIn;
    cout<< "Enter Car Price: "; cin>> PriceIn;
    cout<< "Enter Car Registration Year: "; cin>> RegistrationYearIn;
    cout<< "Enter Car CC: "; cin>> CC;
    cout<< "Enter Car Fuel Type (Petrol Diesel etc): "; cin>> FuelIn;
    cout<< "How many Cylinder does the car have: "; cin>> CylinderIn;
    cout<< "Does the car have turbo ? Enter 1 if yes "; cin>> TurboIn;
    cout<< "Enter number of gears the Car has: "; cin>> GearIn;
    cout<< "Is the Car Manual or Automatic ? Enter 1 if yes "; cin>> AutomaticIn;
    cout<< "Does it have Pedal Shifters ? : "; cin>> PaddleShiftIn;
    cout<< "What Power Type is the Car (PWD / FWD / AWD): "; cin>> PowerTypeIn;
    (AutomaticIn) ? (TypeIn = "Manual") : (TypeIn = "Automatic"); 
    if(*ApprovalListIndex >= *size){
        Car *temp = new Car[*size * 2];
        for(int i = 0; i < *size; i++){
            temp[i] = ApprovalList[i]; 
        }
        delete[] ApprovalList;
        ApprovalList = temp;
        ApprovalList[*ApprovalListIndex] = Car(CompanyNameIn, NameIn, TypeIn, MileageIn, PriceIn, RegistrationYearIn, CC, FuelIn, CylinderIn, TurboIn, GearIn, AutomaticIn, PaddleShiftIn, PowerTypeIn);
        (*ApprovalListIndex)++;
        (*size) *= 2;
    }else{
        ApprovalList[*ApprovalListIndex] = Car(CompanyNameIn, NameIn, TypeIn, MileageIn, PriceIn, RegistrationYearIn, CC, FuelIn, CylinderIn, TurboIn, GearIn, AutomaticIn, PaddleShiftIn, PowerTypeIn);
        (*ApprovalListIndex)++;
    }
}
void removeCar(Car *&ApprovalList,int *ApprovalListIndex, int size, int IdIn){
    for(int i = 0; i < *ApprovalListIndex; i++){
        if(ApprovalList[i].returnID() == IdIn){
            for(int j = i; j < *ApprovalListIndex - 1; j++){
                ApprovalList[j] = ApprovalList[j + 1];
            }
            (*ApprovalListIndex)--;;
        }
    }
}

int main(){
    CarList *Database = new CarList[50];
    CarList *ApprovalList = new CarList[10];
    Admin *AdminList = new Admin[10];
    Buyer *BuyerList = new Buyer[10];
    Seller *SellerList = new Seller[10];
    int DatabaseIndex = 0, ApprovalListIndex = 0, DatabaseSize = 50, ApprovalListSize = 10;
    int choice, repeat;
    cout<< "Do you want to BUY / SELL / Browse or are you Admin ? Enter 1,2,3,4 for each respectively\n";
    cin>> choice;
    while(!repeat)
        switch(choice){
            case 1:

        }
}