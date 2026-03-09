#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll No: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks << endl;
    }
};

vector<Student> students;

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (auto &s : students) {
        s.display();
    }
}

void searchStudent() {
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.rollNo == roll) {
            cout << "Student Found:\n";
            s.display();
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void saveToFile() {
    ofstream file("students.txt");

    for (auto &s : students) {
        file << s.rollNo << " "
             << s.name << " "
             << s.marks << endl;
    }

    file.close();
    cout << "Data saved to file.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save to File\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            saveToFile();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}