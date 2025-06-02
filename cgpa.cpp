#include <iostream>
using namespace std;

int main() {
    int numCourses;
    float grade, credit, totalGradePoints = 0, totalCredits = 0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 1; i <= numCourses; i++) {
        
        cout << "\nCourse " << i << ":\n";
        cout << "Enter grade (out of 10): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> credit;

        totalGradePoints += grade * credit;
        totalCredits += credit;

        cout << "Grade: " << grade << ", Credit Hours: " << credit << endl;
    }

    float cgpa = 0;
    if (totalCredits != 0) {
        cgpa = totalGradePoints / totalCredits;  
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Your CGPA (out of 10): " << cgpa << endl;

    return 0;
}
