#include <iostream>
using namespace std;

struct Note {
    string firstName;
    string lastName;
    long int num_of_ph;
    int date[3];
};

void enter_sp(Note spis[], const int n){
    for (int i = 0; i < n; i++){
        cin.ignore();
        cout << "Введите имя: ";
        getline(cin, spis[i].firstName);
        cout << "\n";

        cout << "Введите фамилию: ";
        getline(cin, spis[i].lastName);
        cout << "\n";

        cout << "Введите номер телефона: ";
        cin >> spis[i].num_of_ph;
        cout << "\n";

        cout << "Введите дату рождения в формате: день, месяц, год " << "\n";
        for (int j = 0; j < 3; j++){
            cin >> spis[i].date[j];
        }
        cout << "\n";
    }
}

void alp_sort(Note spis[], const int n){
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if ((spis[j].lastName + spis[j].firstName) > (spis[j + 1].lastName + spis[j + 1].firstName)) {
                Note temp = spis[j];
                spis[j] = spis[j + 1];
                spis[j + 1] = temp;
            }
        }
    }
}


int main(){
    setlocale(LC_ALL, "RUS");
    const int n = 4;
    Note spis[n];

    int choice = 3;

    while (choice != 0){
    cout << "Выберите, что хотите сделать (для выбора следует ввести соответсвующую цифру): \n";
    cout << "1.Ввод данных\n";
    cout << "2.Поиск по номеру телефона\n";
    cout << "3.Вывод списка имен\n";
    cout << "0.Выход\n";
    cout << "\n";

    cin >> choice;


    if (choice == 1){
        enter_sp(spis,n);
        alp_sort(spis,n);
    }

    if (choice == 3){
        cout << "\nСписок: \n";
        for (int i = 0; i < n; i++){
            cout << spis[i].firstName << " " << spis[i].lastName << "\n";
        }
        cout << "\n";
    }

    if (choice == 2){
        long int nump;

        cout << "Введите номер телефона: ";
        cin >> nump;

        bool flag = false;
        for(int i = 0; i < n; i++){
            if (nump == spis[i].num_of_ph){

                cout << "\nИмя: " << spis[i].firstName << "\n";
                cout << "Фамилия: " << spis[i].lastName << "\n";
                cout << "Номер телефона: " << spis[i].num_of_ph << "\n"; 
                cout << "Дата рождения: ";
                for (int k = 0; k < 3; k++){
                    cout << spis[i].date[k];
                    if (k != 2){
                        cout << ".";
                    }
                }
                cout << "\n";
                cout << "\n";
                flag = true;
                break;
            }
            else {
                continue;
        }
        }
        if (flag == false){
            cout << "\nТакого номера телефона нет в базе данных!\n";
            cout << "\n";
    }
    }

    if (choice == 0){
        cout << "Программа завершена.";
        break;
    }

    if (choice < 0 and choice > 3){
        cout << "Неккоректный ввод!\n";
    }
    }
   
    return 0;    
}
