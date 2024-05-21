//2
#include <iostream>

using namespace std;

double user_func(double x){
    return sqrt(x);
}

double diff2(double (*f)(double), double x, double eps){
    double delta_x = sqrt(eps);

    double result = (f(x - delta_x) - 2 * f(x) + f(x + delta_x)) / (delta_x * delta_x);

    return result;
}

int main(){
    setlocale(LC_ALL, "RUS");
    double x, h;

    cout << "Введите значение х: " << endl; //Координата точки
    cin >> x;

    cout << "Введите значение h: " << endl; //Значение точности
    cin >> h;

    double sd = diff2(user_func, x, h);

    cout << "Вторая производная от х = " << x << ": " << sd << endl;

    return 0;
}

//2
#include <iostream>

using namespace std;

double minim(const double array[], int razm, int* num, int* min){      //функция ищет минимальное значение и его номер в массиве 
    int min_zn = array[0], num_of_min = 0;

    for(int i = 0; i < razm; i++){
        if (array[i] < min_zn){
            min_zn = array[i];
            num_of_min = i;
        }
    }

    *num = num_of_min;

    *min = min_zn;

    return 0;
}

double summ(const double array[], int razm){ //функция ищет сумму между двумя, первыми, отрицательными числами
    bool flag = false;
    double sum = 0;

    for(int i = 0; i < razm; i++) {
        if ((array[i] < 0) and (not flag)) {
            flag = true;
            continue;
        }

        else if (array[i] < 0 and flag) {
            break;
        }

        else if (flag) {
            sum += array[i];
        }
    }
    
    return sum;
}

int main(){
    setlocale(LC_ALL, "RUS");
    cout << "В программе создается два отдельных массива для того, чтобы наглядно показать работу обеих функций.\n (Для второй функции нужно вводить элементы вручную)\n Размер указывается один для обоих массивов.\n \n";
    int n, nom, min;
    double su;
    cout << "Введите размер массива: \n";
    cin >> n;

    double *mass = new double[n];
    double *arr = new double[n];

    cout << "Введите элементы массива: \n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cout << "\n";
    }

    for(int i = 0; i < n; i++){
        mass[i] = rand() % 100;
    }

    for(int i = 0; i < n; i++){
        cout << mass[i] << " ";
    }

    cout << "\n";

    minim(mass, n, &nom, &min);
    cout << "Минимальное значение: " << min << endl;
    cout << "Номер минимального значения в массиве: " << nom << endl;


    su = summ(arr, 6);
    cout << "Сумма между двумя отрицательными элементами: " << su << endl;

    delete [] mass;
    delete [] arr;
    return 0;
}
