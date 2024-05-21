#include <iostream>
#include <string>

const int count_of_marks = 5;

class Dynamic_list{
private:
    struct Student{
        std::string name;
        std::string surname;
        int num_of_group;
        int* marks; 
        Student* next;

        
        Student(std::string name = "None", std::string surname = "None", int num_of_group = 0, int* marks = nullptr) :
            name(name), surname(surname), num_of_group(num_of_group), marks(marks), next(nullptr) {}

        

        double avgMark(){
            int sum = 0;
            for(int i = 0; i < count_of_marks; i++){
                sum += marks[i];
            }
            return static_cast<double>(sum) / count_of_marks;
        }
    };

    Student* head = nullptr;

public:
    Dynamic_list() : head(nullptr){}

    void insert(std::string name, std::string surname, int num_of_group, int* marks){
        Student* newStudent = new Student(name, surname, num_of_group, marks);
        if (!head || head->num_of_group > num_of_group){   
            newStudent->next = head;
            head = newStudent;
        }
        else{
            Student* current = head;
            while(current->next && current->next->num_of_group < num_of_group){
                current = current->next;
            }
            newStudent->next = current->next;
            current->next =  newStudent;
        }
    }

    void display(){                 //Показывает студентов, средняя оценка которых выше средней общей оценки
        if(!head){
            std::cout << "List is empty!" << std::endl;
        }
        
        double totalAVG = 0;
        int count = 0;
        Student* current = head;

        while(current != nullptr){
            for(int i = 0; i < count_of_marks; i++){
                totalAVG += current->marks[i];
            }
            count++;
            current = current->next;
        }
        totalAVG = totalAVG / static_cast <double> (count * count_of_marks);
        std::cout << "Total average mark is " << totalAVG << std::endl;
        current = head;
        std::cout << "People who has mark bigger than average mark: " << std::endl;
        while(current){
            if(current->avgMark() > totalAVG){
                std::cout << current->surname << std::endl;
            }
            current = current->next;
        }
    }

    void print_all_list(){
        Student* current = head;
        std::cout << "\n";
        while(current){
            std::cout << "Фамилия: " << current->surname << " , Имя: " << current->name << " , Number of group: " << current->num_of_group << std::endl;
            current = current->next;
        }
    }

    
    ~Dynamic_list(){
        while(head){
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(){
    Dynamic_list list;

    int marks1[count_of_marks] = {5, 4, 4, 5, 3};
    int marks2[count_of_marks] = {4, 3, 5, 4, 4};
    int marks3[count_of_marks] = {3, 4, 5, 5, 5};
    int marks4[count_of_marks] = {5, 5, 5, 5, 5};


    list.insert("Иван", "Иванов", 101, marks1);
    list.insert("Петр", "Петров", 102, marks2);
    list.insert("Сидор", "Сидоров", 101, marks3);
    list.insert("Козел", "Козлов", 103, marks4);

   
    list.display();
    list.print_all_list();

    return 0;
}
