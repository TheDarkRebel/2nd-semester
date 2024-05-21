#include <iostream>	
using namespace std;

struct Worker {
    string surname;
    string name;
    string position;
    int year_started;
    Worker* next;
};


void addWorker(Worker*& head, string surname, string name, string position, int year_started) {
    Worker* newWorker = new Worker;
    newWorker->surname = surname;
    newWorker->name = name;
    newWorker->position = position;
    newWorker->year_started = year_started;
    newWorker->next = nullptr;
    if (head == nullptr) {
        head = newWorker;
    }
    else {
        Worker* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newWorker;
    }
}

double averageExperience(Worker* head) {
    int totalExperience = 0;
    int numWorkers = 0;
    Worker* current = head;
    while (current != nullptr) {
        totalExperience += (2024 - current->year_started);
        numWorkers++;
        current = current->next;
    }
    return static_cast<double> (totalExperience) / numWorkers;
}


void displayEvgExp(Worker* head) {
    Worker* current = head;
    double avgExp = averageExperience(head);
    cout << "\nList of new workers: " << endl;
    while (current != nullptr) {
        if ((2024 - current->year_started) < avgExp) {
            cout << current->surname << endl;
        }
        current = current->next;
    }
}

void sortByYear(Worker*& head) {
    if (head == nullptr or head->next == nullptr) {
        return; 
    }
    Worker* sorted = nullptr;

    while (head != nullptr) {
        Worker* current = head;
        head = head->next;

        if (sorted == nullptr or current->year_started < sorted->year_started) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Worker* temp = sorted;
            while (temp->next != nullptr && temp->next->year_started < current->year_started) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}



void print_list(Worker* head) {
    Worker* current = head;
    while (current != nullptr) {
        cout << "Surname: " << current->surname << " , Name: " << current->name << " , Position: " << current->position << " , Year of start: " << current->year_started << endl;
        current = current->next;
    }
}

void delete_list(Worker* head) {
    Worker* current = head;
    while (current != nullptr) {
        Worker* temp = current;
        current = current->next;
        delete temp;
    }
    cout << "\nList has been deleted!";
    head = nullptr;
}


int main() {
    setlocale(LC_ALL, "RUS");
    Worker* head = nullptr;

    addWorker(head, "Smith", "John", "Manager", 2010);
    addWorker(head, "Johnson", "Anna", "Developer", 2015);
    addWorker(head, "Williams", "Michael", "Analyst", 2018);
    addWorker(head, "Jones", "Emily", "Designer", 2012);

    cout << "List of workers:" << endl;
    print_list(head);

    sortByYear(head);
    cout << "List of workers after sorting of year: " << endl;
    print_list(head);

    displayEvgExp(head);

    delete_list(head);
    return 0;
}