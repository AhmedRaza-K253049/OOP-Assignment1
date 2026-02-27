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
    static int Id;
    string Company;
    string Name;
    Engine engine;
    int Mileage;
    string Color;
    int Price;
    int RegisterationYear;
public:
    Car(){};
    Car(string CompanyIn, string NameIn, int MileageIn, string ColorIn, int PriceIn, int RegisterationIn, int CCIn, string FuelIn, string TransmissionIn, int CylinderIn, int TurboIn): engine(CCIn, FuelIn, TransmissionIn, CylinderIn, TurboIn){
        Id++;
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
    static int returnID(){
        return ID;
    }
};

class Seller {
    private:
        string Name;
        int Number;
        const string Username;
        const string Password;
        Car Selling[5];
        int SellingCount;
    public:
        Seller(string NameIn, string UsernameIn, string PasswordIn, int NumberIn): Username(UsernameIn), Password(PasswordIn){
            Name = NameIn;
            Number = NumberIn;
            SellingCount = 0;
        }
        void addCar(string CompanyIn, string NameIn, int MileageIn, string ColorIn, int PriceIn, int RegisterationIn, int CCIn, string FuelIn, string TransmissionIn, int CylinderIn, int TurboIn){
            Selling[SellingCount] = Car(CompanyIn, NameIn, MileageIn, ColorIn, PriceIn, RegisterationIn, CCIn, FuelIn, TransmissionIn, CylinderIn, TurboIn);
            SellingCount++;
        }
        void removeCar(int IdIn){
            for(int i = 0; i < SellingCount; i++){
                if(Selling[i].returnID() == IdIn){
                    for(int j = i; j < SellingCount; j++){
                        Selling[j] = Selling[j + 1];
                    }
                SellingCount--;
                }
            }
        }
};
class Buyer{
   private:
        string Name;
        int Number;
        const string Username;
        const string Password;
        Car **Favourite;
        int FavouriteMax;
        int FavouriteCount;
    public:
        Buyer(string NameIn, string UsernameIn, string PasswordIn, int NumberIn): Username(UsernameIn), Password(PasswordIn){
            Name = NameIn;
            Number = NumberIn;
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