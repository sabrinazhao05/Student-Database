#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct student {
    string name;
    int rollNum;
    float mark;
};

class studentDatabase {
private:
    vector<student> students;

public:
    void addStudent() {
        student newStudent;
        cout << "Enter name: ";
        getline (cin, newStudent.name);
        cout << "Enter roll number: ";
        cin >> newStudent.rollNum;
        cout << "Enter mark(s): ";
        cin >> newStudent.mark;

        students.push_back(newStudent);

        cout << "Student added successfully\n"; 
    }

void displayAllStudent() {
    if (students.empty()) {
        cout << "No students in the database.\n";
    } else {
        cout << "List of all students: \n";
        cout << setw(20) << "Name" << setw(15) << "Roll Number" << setw(10) << "Marks\n";
        for (const auto &student : students) {
            cout << setw(20) << student.name << setw(15) << student.rollNum << setw(10) << student.mark << "\n";
        }
    }
}

void deleteStudent(int rollNum) {
    auto it = find_if(students.begin(),students.end(),
        [rollNum](const student &s)
        {return s.rollNum == rollNum;}); 
    if (it != students.end()) {
        students.erase(it);
        cout << "Student with roll number " << rollNum << " deleted successfully\n";
    } else {
        cout << "Student with roll number " << rollNum << " cannot be found\n";
    }
}

void updateStudent(int rollNum) {
    auto it = find_if(students.begin(),students.end(),
        [rollNum](const student &s)
        {return s.rollNum == rollNum;});
    if (it != students.end()) {
        cout << "Enter new name: ";
        getline (cin, it->name);
        cout << "Enter new marks: ";
        cin >> it->mark;
        cout << "Student with roll number " << rollNum << " updated successfully\n";
    } else {
        cout << "Student with roll number " << rollNum << " cannot be found\n";
    }
}
};

int main() {
    studentDatabase database;
    int choice, rollNum;

    do {
        cout << "\nStudent Database System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit System\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
             cin.ignore();
             database.addStudent();
             break;

        case 2:
            database.displayAllStudent();
            break;

         case 3:
            cout << "Enter roll number to delete: ";
            cin >> rollNum;
            database.deleteStudent(rollNum);
            break;

        case 4:
            cout << "Enter roll number to update: ";
            cin >> rollNum;
            cin.ignore();
            database.updateStudent(rollNum);
            break;

        case 5:
            cout << "Exiting program. Bye! \n";
            break;

        default:
            cout << "Invalid choice. Please try again. \n";
        }
    } while (choice != 5);

    return 0;
}
