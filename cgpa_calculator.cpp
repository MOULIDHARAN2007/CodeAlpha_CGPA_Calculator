#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert letter grade to grade points
float getGradePoint(string grade) {
    if (grade == "O" || grade == "o")
        return 10.0;
    else if (grade == "A+" || grade == "a+")
        return 9.0;
    else if (grade == "A" || grade == "a")
        return 8.0;
    else if (grade == "B+" || grade == "b+")
        return 7.0;
    else if (grade == "B" || grade == "b")
        return 6.0;
    else if (grade == "C+" || grade == "c+")
        return 5.0;
    else if (grade == "C" || grade == "c")
        return 4.0;
    else {
        cout << "Invalid grade entered! Defaulting to 0.\n";
        return 0.0;
    }
}

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    string subject[100];
    string gradeLetter[100];
    float gradePoint[100], credit[100];
    float totalPoints = 0, totalCredits = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Subject Name: ";
        cin >> subject[i];

        cout << "Enter Grade (O, A+, A, B+, B, C+, C): ";
        cin >> gradeLetter[i];

        // Convert letter grade to numeric grade point
        gradePoint[i] = getGradePoint(gradeLetter[i]);

        cout << "Credit Hours: ";
        cin >> credit[i];

        totalPoints += gradePoint[i] * credit[i];
        totalCredits += credit[i];
    }

    float cgpa = totalPoints / totalCredits;

    cout << "\n----------- RESULT -----------\n";
    for (int i = 0; i < n; i++) {
        cout << subject[i]
             << " - Grade: " << gradeLetter[i]
             << " (" << gradePoint[i] << ")"
             << ", Credits: " << credit[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nFinal CGPA = " << cgpa << endl;

    return 0;
}