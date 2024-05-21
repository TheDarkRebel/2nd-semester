#include <iostream>
#include <fstream>
#include <string>

int main(){
    setlocale(LC_ALL, "RUS");

    int n;
    std::cout << "Введите кол-во целых чисел, которые вы хотите записать: ";
    std::cin >> n;
    int *mass = new int[n];
    

    for(int i = 0; i < n; i++){
        std::cout << "Введите " << i + 1 << " число: ";
        std::cin >> mass[i];
        std::cout << "\n";
    }

    std::ofstream fout;
    fout.open("1.txt");
    for(int i = 0; i < n; i++){
        fout << mass[i] << " ";
    }
    fout.close();

    int sum;
    for(int j = 0; j < n; j++){
        sum += mass[j];
    }
    int avg = sum / n;
    std::cout << "Среднее арифметическое всех чисел в файле: " << avg << std::endl;
    

    std::ifstream fin;
    fin.open("1.txt");
    std::string strk;
    getline(fin, strk);
    std::cout << "Содержимое файла на данный момент: \n" << strk << std::endl;
    fin.close();
    
    
    int *mass2 = new int[n];
    int sch = 0;
    for(int i = 0; i < n; i++){
        if(mass[i] < avg){
            mass2[sch] = mass[i];
            sch++;
        }
    }
    for(int i = 0; i < n; i++){
        if(mass[i] >= avg){
            mass2[sch] = mass[i];
            sch++;
        }
    }

    std::ofstream fout1;
    fout1.open("1.txt");
    for(int i = 0; i < n; i++){
        fout1 << mass2[i] << " ";
    }
    fout1.close();
    
    std::ifstream fin1;
    fin1.open("1.txt");
    std::string strok;
    getline(fin1, strok);
    std::cout << "Содержимое файла после сортировки: \n" << strok << std::endl;
    fin1.close();

    delete [] mass;
    delete [] mass2;
    return 0;
}
