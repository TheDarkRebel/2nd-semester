#include <iostream>
using namespace std;

class Vector{
    private:
    double x;
    double y;
    double z;

    public: 
    Vector(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z){}

    double length(){
        double len = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        cout << "Длина вектора равна: " << len << endl;
        return len;
    }

    void check_info(){
        cout << "Значение х: ";
        cout << x << "\n";
        cout << "Значение y: ";
        cout << y << "\n";
        cout << "Значение z: ";
        cout << z << "\n";
        cout << endl;
    }

    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    Vector operator+(const Vector other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector operator-(const Vector other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    static double scalar(const Vector v1, const Vector v2){
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    static Vector vect(const Vector v1, const Vector v2){
        return Vector(v1.y * v2.z - v1.z * v2.y,
                      v1.z * v2.x - v1.x * v2.z,
                      v1.x * v2.y - v1.y * v2.x);
    }
};



int main(){
    setlocale(LC_ALL, "RUS");
    Vector example1(5, 7, 9);
    Vector example2(4, 6, 8);

    //Вывод характеристик векторов
    example1.check_info();
    example2.check_info();

    //Вывод длины вектора
    example1.length();
    example2.length();

    //Умножение вектора на число
    Vector test1 = example1 * 2;
    cout << "\nЗначения первого вектора после умножения на число:\n";
    test1.check_info();
    Vector test2 = example2 * 3;
    cout << "\nЗначения второго вектора после умножения на число:\n";
    test2.check_info();

    //Сложение двух векторов
    Vector test_pl = example1 + example2;
    cout << "\nКоординаты нового вектора:\n";
    test_pl.check_info();

    //Разность двух векторов
    Vector test_min = example2 - example1;
    cout << "\nКоординаты нового вектора:\n";
    test_min.check_info();

    //Cкалярное умножение двух векторов
    double result_scal = Vector::scalar(example1, example2);
    cout << "\nРезультат скалярного умножения двух векторов: " << result_scal << endl;
    
    //Векторное умножение двух векторов
    Vector result_vect = Vector::vect(example1, example2);
    cout << "\nРезультат векторного умножения двух векторов: " << endl;
    result_vect.check_info();
    return 0;
}
