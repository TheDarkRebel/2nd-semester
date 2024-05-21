#include <iostream>

template <typename Z>
class Car{
private:
    std::string brand;
    std::string color;
    Z fuelSize;
    Z fuelConsumption;
    static int counter;
    int id;

public:
    Car(std::string brand = "NONE", std::string color = "None", Z fuelSize = 0, Z fuelConsumption = 0) : brand(brand), color(color), fuelSize(fuelSize), fuelConsumption(fuelConsumption), id(++counter){}

    void outputINFO(){
        std::cout << "Общая информация об автомобиле: " << std::endl;
        std::cout << "Марка автомобиля: " << brand << std::endl;
        std::cout << "Цвет автомобиля: " << color << std::endl;
        std::cout << "Объем топливного бака: " << fuelSize << " литров" << std::endl;
        std::cout << "Норма потребления бензина(на 100 км): " << fuelConsumption << " литров" << std::endl;
        std::cout << "Идентификатор автомобиля: " << id << std::endl;
    } 

    Z calculateDistance() const{
        return fuelSize / (fuelConsumption / 100);
    }

    Z retFuelCons(){
        return fuelConsumption;
    }

    static Z calculateCost(Z distance,Z fuelConsumption, Z fuelPrice){
        return (distance / 100) * fuelConsumption * fuelPrice;
    }

};

template<typename T>
int Car<T>::counter = 0;



int main() {
    double fuelPrice = 52.4;
    double distance = 300;
    std::cout << std::endl;
    Car<double> test1("BMW", "Черный", 50, 8.5);
    test1.outputINFO();
    std::cout <<"\nПосле полной заправки машина сможет проехать " << test1.calculateDistance() << " км." << std::endl;
    std::cout << "Для поездки на " << distance << " км со стоимостью на топливо в " << fuelPrice << " рублей за литр придется потратить " << test1.calculateCost(distance, test1.retFuelCons(), fuelPrice) << " рублей." << std::endl;
    
    std::cout << std::endl;
    Car<double> test2("Mersedes", "Белый", 120, 10);
    test2.outputINFO();
    std::cout << "\nПосле полной заправки машина сможет проехать " << test1.calculateDistance() << " км." << std::endl;
    std::cout << "Для поездки на " << distance << " км со стоимостью на топливо в " << fuelPrice << " рублей за литр придется потратить " << test1.calculateCost(distance, test2.retFuelCons(),fuelPrice) << " рублей." << std::endl;
    
}
