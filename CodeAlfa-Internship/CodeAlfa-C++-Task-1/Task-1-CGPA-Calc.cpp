#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

struct Course {
    string name;
    double gradePoints;
    double creditHours;
};

double letterToGradePoints(char letter) {
    switch (toupper(letter)) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default:  return -1.0;
    }
}

int main() {
    int numCourses;

    setColor(11);
    cout << "\n==============================================\n";
    cout << "           CGPA CALCULATOR SYSTEM             \n";
    cout << "==============================================\n";

    setColor(14);
    cout << "Enter the number of courses: ";
    setColor(15);
    if (!(cin >> numCourses) || numCourses <= 0) {
        setColor(12);
        cout << "Error: Invalid number of courses." << endl;
        setColor(7);
        return 1;
    }

    vector<Course> courses(numCourses);
    double totalCreditHours = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numCourses; ++i) {
        char gradeLetter;

        setColor(13);
        cout << "\n--- Course " << (i + 1) << " ---" << endl;

        setColor(11);
        cout << "  Course Name/Code: ";
        setColor(15);
        cin >> courses[i].name;

        setColor(11);
        cout << "  Grade (A, B, C, D, F): ";
        setColor(15);
        cin >> gradeLetter;
        courses[i].gradePoints = letterToGradePoints(gradeLetter);

        while (courses[i].gradePoints < 0.0) {
            setColor(12);
            cout << "  Invalid grade! Enter A, B, C, D, or F: ";
            setColor(15);
            cin >> gradeLetter;
            courses[i].gradePoints = letterToGradePoints(gradeLetter);
        }

        setColor(11);
        cout << "  Credit Hours: ";
        setColor(15);
        cin >> courses[i].creditHours;
        while (courses[i].creditHours <= 0) {
            setColor(12);
            cout << "  Credit hours must be > 0. Re-enter: ";
            setColor(15);
            cin >> courses[i].creditHours;
        }

        totalCreditHours += courses[i].creditHours;
        totalGradePoints += (courses[i].gradePoints * courses[i].creditHours);
    }

    setColor(9);
    cout << "\n====================== ACADEMIC SUMMARY ======================\n";
    setColor(15); // Bright White
    cout << left << setw(18) << "Course"
         << setw(16) << "Grade Point"
         << setw(16) << "Credit Hours"
         << setw(16) << "Quality Points" << endl;

    setColor(9);
    cout << "--------------------------------------------------------------\n";

    setColor(7);
    for (const auto& course : courses) {
        double qualityPoints = course.gradePoints * course.creditHours;
        cout << left << setw(18) << course.name
             << fixed << setprecision(2)
             << setw(16) << course.gradePoints
             << setw(16) << course.creditHours
             << setw(16) << qualityPoints << endl;
    }

    setColor(9);
    cout << "--------------------------------------------------------------\n";

    setColor(14);
    cout << "Total Credit Hours:  ";
    setColor(15);
    cout << fixed << setprecision(2) << totalCreditHours << endl;

    setColor(14);
    cout << "Total Quality Points:";
    setColor(15);
    cout << " " << totalGradePoints << endl;

    double cgpa = (totalCreditHours > 0) ? (totalGradePoints / totalCreditHours) : 0.0;

    cout << "\nFinal CGPA: ";
    if (cgpa >= 3.0) {
        setColor(10);
    } else if (cgpa >= 2.0) {
        setColor(14);
    } else {
        setColor(12);
    }
    cout << fixed << setprecision(2) << cgpa << " / 4.00" << endl;

    setColor(9);
    cout << "==============================================================\n\n";

    setColor(7);

    return 0;
}