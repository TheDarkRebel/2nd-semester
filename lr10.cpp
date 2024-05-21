//1
#include <iostream>
using namespace std;

double funcHelper(int current, int base, double number, double result) {
    if (current > base) {
        return result;
    }

    return funcHelper(current + 1, base, number, result * number);
}

double func(int base, double number) {
    if (base < 0) {
        cerr << "Ошибка: степень должна быть неотрицательной." << endl;
        exit(EXIT_FAILURE);
    }

    return funcHelper(1, base, number, 1.0);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int base;
    double number;

    cout << "Введите число, которое хотите возвести в степень: ";
    cin >> number;
    cout << "\nВведите степень, в которую хотите возвести: ";
    cin >> base;

    double result = func(base, number);
    cout << "Результат: " << result;

    return 0;
}
//2
#include <iostream>
using namespace std;

double funcHelper(double current, double num, double result){
    if (current > num){
        return  result;
    }

    return funcHelper(current + 1, num, result + sqrt(current));
}


double func(double num){
    if (num == 1){
        return 1;
    }

    if (num < 1){
        cerr << "Ошибка: число должно быть неотрицательным." << endl;
        exit(EXIT_FAILURE);
    }

    return funcHelper(1, num, 0);
}


int main(){
    setlocale(LC_ALL, "RUS");

    cout << "Введите число: ";
    double num;
    cin >> num;

    double result = func(num);
    cout << "Результат: " << result;
    
    return 0;
}
