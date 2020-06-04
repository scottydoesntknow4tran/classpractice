#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

using namespace std;

class Animal{
private:
    string name;
    double height;
    double weight;

    static int numOfAnimals;

public:
    string GetName(){return name;}
    void SetName(string name){this->name =name;}
    double GetHeight(){return height;}
    void SetHeight(double height){this->height =height;}
    double GetWeight(){return weight;}
    void SetWeight(double weight){this->weight =weight;}

    void SetAll(string, double, double);
    Animal(string, double, double);
    Animal();
    ~Animal();
    static int GetNumOfAnimals(){return numOfAnimals;}
    void ToString();


    };

int Animal::numOfAnimals =0;

void Animal :: SetAll(string name,double height,double weight){
    this-> name= name;
    this-> weight= weight;
    this-> height= height;
    Animal::numOfAnimals++;
}

Animal :: Animal (string name,double height,double weight){
    this-> name= name;
    this-> weight= weight;
    this-> height= height;
    Animal::numOfAnimals++;
}

Animal::Animal(){
    this->name= " ";
    this->weight=0;
    this->height=0;
    Animal::numOfAnimals++;
}

Animal::~Animal(){
    cout << "Animal" << this -> name<< "destroyed\n";
}

void Animal:: ToString(){
    cout<< this -> name << " is "<< this -> height << " cm's tall and "<<
    this-> weight << " kg's in weight\n";
}

class Dog: public Animal{
    private:
        string sound = "woof";
    public:
        void MakeSound(){
            cout << "The dog "<< this->GetName() <<" says " <<
            this-> sound <<"\n";
    }
    Dog (string, double, double, string);
    Dog(): Animal(){};
    void ToString();
};

Dog::Dog(string name, double height, double weight, string sound):
Animal(name, height,weight){
    this->sound =sound;
}

void Dog:: ToString(){
    cout<< this -> GetName() << " is "<< this -> GetHeight() << " cm's tall and "<<
    this-> GetWeight() << " kg's in weight and says "
    << this-> sound <<"\n";
}


int main(){
    Animal fred;
    fred.ToString();
    fred.SetHeight(33);
    fred.SetWeight(10);
    fred.SetName ("Fred");
    fred.ToString();
    Animal tom("Tom", 36, 15);
    tom.ToString();
    Dog spot("Spot", 38, 16, "Woooof");
    spot.ToString();

    cout << "Number of animals: "<<
    Animal :: GetNumOfAnimals() << "\n";

    return 0;
}
