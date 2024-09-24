//Yinus Adeyinka Alamutu - Project V - Assignment 2
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct STUDENT_DATA //struct that contains student data
{
    std::string firstName;
    std::string lastName;
};

int main(void)
{
    ifstream inputFile("C:\\Users\\adeyi\\source\\repos\\ProjectV\\StudentData.txt");
    //Vector holding students
    vector<STUDENT_DATA> students;
    //if there was an error accessing the input file, users will be notified
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string firstName, lastName; // string holding firstname and lastname

        // Splitting the line by the comma
        if (getline(ss, lastName, ',') && getline(ss, firstName))
        {
            // Creating a STUDENT_DATA object and pushing it into the vector
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
    }

    inputFile.close();

    // Debugging
#ifdef _DEBUG
    //printing out student information
    cout << "Loaded Student Data:" << endl;
    for (const auto& student : students) {
        cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << endl;
    }
#endif
    return 0;
}
