#include <iostream>
#include <string>
using namespace std;

class Car{
private:
    static int ID;
    string Company;
    string Name;
    int EngineCC;
    int Mileage;
    string Color;
    int Price;
    int RegisterationYear;
    Car (Car &obj){}

public:
    string returnCompany(){
        return Company;
    }
    string returnName(){
        return Name;
    }
    int returnEngineCC(){
        return EngineCC;
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
    void setEngineCC(int input){
        EngineCC = input;
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
        cout<< "Company: "<< Company<< endl;
        cout<< "Name: "<< Name<<endl;
        cout<< "Engine CC: "<< EngineCC<< endl;
        cout<< "Mileage: "<< Mileage<< endl;
        cout<< "Color: "<< Color<< endl;
        cout<< "Registered In Year: "<< RegisterationYear<< endl;
        cout<< "Price: "<< Price<< endl;
    }
};
class Seller {
    private:
        string Name;
        string Email;
        int Number;
        Car *Selling;
        int sellingCount;
    public:
    Seller(string NameIn, string EmailIn, int NumberIn){
        
    }
};
class Buyer{};