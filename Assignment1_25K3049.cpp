#include <iostream>
#include <string>
using namespace std;

class Engine{
    private:
        int CC;
        string FuelType;
        string TransmissionType;
        int Cylinder;
        int Turbo;
    public:
        Engine(){};
        Engine(int CCIn, string FuelIn, string TransmissionIn, int CylinderIn, int TurboIn){
            CC = CCIn;
            FuelType = FuelIn;
            TransmissionType = TransmissionIn;
            Cylinder = CylinderIn;
            Turbo = TurboIn;
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
    string Color;
    int Price;
    int RegisterationYear;
public:
    Car(){};
    Car(string CompanyIn, string NameIn, int MileageIn, string ColorIn, int PriceIn, int RegisterationIn, int CCIn, string FuelIn, string TransmissionIn, int CylinderIn, int TurboIn): engine(CCIn, FuelIn, TransmissionIn, CylinderIn, TurboIn), Id(CarCount++){
        Company = CompanyIn;
        Name = NameIn;
        Mileage = MileageIn;
        Color = ColorIn;
        Price = PriceIn;
        RegisterationYear = RegisterationIn;
    }
    string returnCompany(){
        return Company;
    }
    string returnName(){
        return Name;
    }
    int returnMileage(){
        return Mileage;
    }
    string returnColor(){
        return Color;
    }
    int returnRegisterationYear(){
        return RegisterationYear;
    }
    int returnPrice(){
        return Price;
    }
    int returnID(){
        return Id;
    }
    void setCompany(string input){
        Company = input;
    }
    void setName(string input){
        Name = input;
    }
    void setMileage(int input){
        Mileage = input;
    }
    void setColor(string input){
        Color = input;
    }
    void setRegisterationYear(int input){
        RegisterationYear = input;
    }
    void setPrice(int input){
        Price = input;
    }
    void Display(){
        cout<< "Car ID: "<< Id<< endl;
        cout<< "Company: "<< Company<< endl;
        cout<< "Name: "<< Name<<endl;
        cout<< "Mileage: "<< Mileage<< endl;
        cout<< "Color: "<< Color<< endl;
        cout<< "Registered In Year: "<< RegisterationYear<< endl;
        cout<< "Price: "<< Price<< endl;
    }
};

class Seller {
    private:
        string Name;
        const int Number;
        const string Email;
        Car Selling[5];
        int SellingCount;
    public:
        Seller(string NameIn, string EmailIn, string PasswordIn, int NumberIn): Email(EmailIn), Number(NumberIn){
            Name = NameIn;
            SellingCount = 0;
        }
        void addCar(Car *&ApprovalList,int *ApprovalListIndex, int *size, string CompanyIn, string NameIn, int MileageIn, string ColorIn, int PriceIn, int RegisterationIn, int CCIn, string FuelIn, string TransmissionIn, int CylinderIn, int TurboIn){
            if(*ApprovalListIndex > *size){
                Car *temp = new Car[*size * 2];
                for(int i = 0; i < *size; i++){
                    temp[i] = ApprovalList[i]; 
                }
                delete[] ApprovalList;
                ApprovalList = temp;
                ApprovalList[*ApprovalListIndex] = Car(CompanyIn, NameIn, MileageIn, ColorIn, PriceIn, RegisterationIn, CCIn, FuelIn, TransmissionIn, CylinderIn, TurboIn);
                *ApprovalListIndex++;
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
        string Name;
        const string Email;
        const int Number;
        Car **Favourite;
        int FavouriteMax;
        int FavouriteCount;
    public:
        Buyer(string NameIn, string EmailIn, string PasswordIn, int NumberIn): Email(EmailIn), Number(NumberIn){
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
};