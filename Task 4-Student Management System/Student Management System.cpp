#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks;
};

const int MAX = 100;
Student students[MAX];
int count = 0;

// Function to add a student
void addStudent() {
    if (count >= MAX) {
        cout << "Maximum limit reached!\n";
        return;
    }
    cout << "Enter name: ";
    cin >> students[count].name;
    cout << "Enter roll number: ";
    cin >> students[count].rollNumber;
    cout << "Enter marks: ";
    cin >> students[count].marks;
    count++;
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        cout << "No student records found.\n";
        return;
    }
    cout << "\n---- Student Records ----\n";
    for (int i = 0; i < count; i++) {
        cout << "Roll: " << students[i].rollNumber
             << " | Name: " << students[i].name
             << " | Marks: " << students[i].marks << endl;
    }
}

// Function to update a student
void updateStudent() {
    int roll;
    cout << "Enter roll number of student to update: ";
    cin >> roll;

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            cout << "Enter new name: ";
            cin >> students[i].name;
            cout << "Enter new marks: ";
            cin >> students[i].marks;
            cout << "Record updated!\n";
            return;
        }
    }
    cout << "Student with roll number " << roll << " not found.\n";
}

// Function to delete a student
void deleteStudent() {
    int roll;
    cout << "Enter roll number of student to delete: ";
    cin >> roll;

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student with roll number " << roll << " not found.\n";
}

// Function to save data to file
void saveToFile() {
    ofstream file("students.txt");
    for (int i = 0; i < count; i++) {
        file << students[i].rollNumber << " "
             << students[i].name << " "
             << students[i].marks << "\n";
    }
    file.close();
    cout << "Data saved to file.\n";
}

// Function to load data from file
void loadFromFile() {
    ifstream file("students.txt");
    count = 0;
    while (file >> students[count].rollNumber >> students[count].name >> students[count].marks) {
        count++;
    }
    file.close();
    cout << "Data loaded from file.\n";
}

int main() {
    int choice;
    do {
        cout << "\n====== Student Management Menu ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: displayStudents(); break;
        case 3: updateStudent(); break;
        case 4: deleteStudent(); break;
        case 5: saveToFile(); break;
        case 6: loadFromFile(); break;
        case 0: cout << "Exiting system.\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
