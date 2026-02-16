#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
#include <string>

/*Title: Multi-Student Performance Management System
(Nested Menus + Functions)

Problem Context:
An institute wants a console-based academic analytics system that can handle multiple students, each enrolled in multiple subjects.
The system must be menu-driven with nested menus and implemented only using functions and arrays.

Data Model:
- Maximum students: 50
- Maximum subjects per student: 10
- Store Student ID, Student Name, and subject-wise marks
- Use parallel arrays only (no structures or classes)

Main Menu (Level 1):
1. Student Operations
2. Reports & Analytics
3. Exit

Student Operations Menu (Level 2):
1. Add New Student
2. Enter / Update Marks
3. View Student Details
4. Back to Main Menu

Functions to Implement:

1. addStudent(int ids[], string names[], int &count)
- Adds a new student
- Prevents overflow beyond 50 students

2. searchStudent(int ids[], int count, int key)
- Returns index if student found, else -1

3. inputMarks(int marks[][10], int index, int subjects)
- Accepts and validates marks (0–100)

4. displayStudent(...)
- Displays student details
- Shows average, grade, and pass/fail status

Reports & Analytics Menu (Level 2):
1. Class Average
2. Top Scorer
3. Student-wise Result Summary
4. Back to Main Menu

5. calculateStudentAverage(...)
6. calculateClassAverage(...)
7. findTopScorer(...)
8. calculateGrade(float avg)
9. isPass(...)

Grade Rules:
>=90 : A
>=75 : B
>=60 : C
>=40 : D
<40  : F

Constraints:
- No global variables
- No classes or structures
- No STL
- No recursion
- Use arrays, loops, and functions only

Bonus:
- Handle duplicate IDs
- Rank list
- Subject-wise toppers

Learning Outcomes:
- Mastery of functions
- Nested menu handling
- Real-world logic building
*/

int ids[50];
string names[50];
int marks[50][10];
int count = 0;
int subjects[10];
int numSubjects;

void addStudent(int ids[], string names[], int &count) {
    if (count >= 50) {
        cout << "Cannot add more students. Maximum limit reached." << endl;
        return;
    }
    int id;
    string name;
    cout << "Enter Student ID: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            cout << "Student ID already exists. Please try again." << endl;
            return;
        }
    }
    cout << "Enter Student Name: ";
    cin >> name;
    ids[count] = id;
    names[count] = name;
    count++;
    cout << "Student added successfully!" << endl;
}

void inputMarks(int marks[][10], int index, int subjects) {
    cout << "Enter marks for " << subjects << " subjects (0-100): ";
    for (int i = 0; i < subjects; i++) {
        int mark;
        cin >> mark;
        if (mark < 0 || mark > 100) {
            cout << "Invalid mark. Please enter a value between 0 and 100." << endl;
            return;
        }
        marks[index][i] = mark;
    }
    cout << "Marks entered successfully!" << endl;
}

void displayStudent(int ids[], string names[], int marks[][10], int index, int subjects) {
    cout << "Student ID: " << ids[index] << endl;
    cout << "Student Name: " << names[index] << endl;
    cout << "Marks: ";
    for (int i = 0; i < subjects; i++) {
        cout << marks[index][i] << " ";
    }
    cout << endl;
    float avg = calculateStudentAverage(marks, index, subjects);
    cout << "Average: " << avg << endl;
    calculateGrade(avg); // Assuming first subject's mark is used for grade calculation
    isPass(marks, index, subjects);
}

float calculateStudentAverage(int marks[][10], int index, int subjects) {
    float total = 0;
    for (int i = 0; i < subjects; i++) {
        total += marks[index][i];
    }
    float average = total / subjects;
    return average;
}

void calculateGrade(float avg) {
    if (avg >= 90) {
        cout << "Grade: A" << endl;
    } else if (avg >= 75) {
        cout << "Grade: B" << endl;
    } else if (avg >= 60) {
        cout << "Grade: C" << endl;
    } else if (avg >= 40) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: F" << endl;
    }
}

void isPass(int marks[][10], int index, int subjects) {
    bool isPassed = true;
    for (int i = 0; i < subjects; i++) {
        if (marks[index][i] < 40) {
            isPassed = false;
            break;
        }
    }
    if (isPassed) {
        cout << "Status: Passed" << endl;
    } else {
        cout << "Status: Failed" << endl;
    }
}

void calculateClassAverage(int marks[][10], int count, int subjects) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < subjects; j++) {
            total += marks[i][j];
        }
    }
    float average = total / (count * subjects);
    cout << "Class Average: " << average << endl;
}

void findTopScorer(int ids[], string names[], int marks[][10], int count, int subjects) {
    int topIndex = 0;
    float topAverage = 0;
    for (int i = 0; i < count; i++) {
        float total = 0;
        for (int j = 0; j < subjects; j++) {
            total += marks[i][j];
        }
        float average = total / subjects;
        if (average > topAverage) {
            topAverage = average;
            topIndex = i;
        }
    }
    cout << "Top Scorer: " << names[topIndex] << " with an average of " << topAverage << endl;
}

void resultSummary(int ids[], string names[], int marks[][10], int count, int subjects) {
    for (int i = 0; i < count; i++) {
        displayStudent(ids, names, marks, i, subjects);
        calculateStudentAverage(marks, i, subjects);
        isPass(marks, i, subjects);
        cout << "-----------------------------" << endl;
    }
}

void studentOperationsMenu() {
    while (true) {
        cout << "Student Operations Menu:\n1. Add New Student\n2. Enter / Update Marks\n3. View Student Details\n4. Back to Main Menu\nEnter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            addStudent(ids, names, count);
        } else if (choice == 2) {
            int index;
            cout << "Enter student index to update marks: ";
            cin >> index;
            inputMarks(marks, index, numSubjects);
        } else if (choice == 3) {
            int index;
            cout << "Enter student index to view details: ";
            cin >> index;
            displayStudent(ids, names, marks, index, numSubjects);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void reportsAnalyticsMenu() {
    while (true) {
        cout << "Reports & Analytics Menu:\n1. Class Average\n2. Top Scorer\n3. Student-wise Result Summary\n4. Back to Main Menu\nEnter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            calculateClassAverage(marks, count, numSubjects);
        } else if (choice == 2) {
            findTopScorer(ids, names, marks, count, numSubjects);
        } else if (choice == 3) {
            resultSummary(ids, names, marks, count, numSubjects);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    while (true) {
        cout << "Main Menu:\n1. Student Operations\n2. Reports & Analytics\n3. Exit\nEnter your choice: ";
        int mainChoice;
        cin >> mainChoice;

        if (mainChoice == 1) {
            studentOperationsMenu();
        } else if (mainChoice == 2) {
            reportsAnalyticsMenu();
        } else if (mainChoice == 3) {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

