#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const int NUM_SUBJECTS = 3;
const int MAX_STUDENTS = 50;
const string SUBJECT_NAMES[NUM_SUBJECTS] = {"Math", "Database", "English"};

//Function to validate scores
bool validateScore(double& score) {
    if (cin.fail() || score < 0 || score > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid score. Please enter a valid numeric value.\n";
        return false;
    }
    return true;
}

//Function to input student information -Adila
void inputStudentInfo(int& studentID, string& studentName, double scores[], int numSubjects) {
    cout << "Enter Student ID: ";
    cin >> studentID;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, studentName);

    for (int j = 0; j < numSubjects; ++j) {
        do {
            cout << "Enter score for " << SUBJECT_NAMES[j] << ": ";
            cin >> scores[j];
        } while (!validateScore(scores[j]));
    }
}

// Desclare all te variales - Hanan
int main() {
    int Student_ID[MAX_STUDENTS];
    string Student_Name[MAX_STUDENTS];
    double Score[MAX_STUDENTS][NUM_SUBJECTS];
    int Attendance[MAX_STUDENTS];

    //Enter numbers into the array
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        inputStudentInfo(Student_ID[i], Student_Name[i], Score[i], NUM_SUBJECTS);

        do {
            cout << "Enter Attendance: ";
            cin >> Attendance[i];

            if (Attendance[i] < 0 || Attendance[i] > 100) {
                cout << "Invalid attendance. Please enter a value between 0 and 100.\n";
            }

        } while (Attendance[i] < 0 || Attendance[i] > 100);
    }

    //Display the list of students information with subject scores - Zainab
    cout << "\nList of Students Information with Subject Scores:" << endl;

    cout << "\tStudentID\t\tStudentName\t\tMath\t\tDatabase\tEnglish\t\tAverageScore%\tAttendance" << endl;

    //Show the number in array and calculate - Anis Athirah
    for (int x = 0; x < MAX_STUDENTS; x++) {
        int i = x;
        cout << i + 1 << ".\t" << Student_ID[x] << "\t\t\t";
        cout << Student_Name[x] << "\t\t\t";
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            cout << Score[x][j] << "\t\t";
        }

        //Calculate and display average
        double sum = 0.0;
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            sum += Score[x][j];
        }
        double averageScore = sum / NUM_SUBJECTS;

        cout << averageScore << "\t\t" << Attendance[x] << endl;
    }

    return 0;
}
