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
    std::string email; // for reading from StudentData_Emails.txt
};

int main(void)
{
#ifdef PRE_RELEASE  //Prerelease version of code
    cout << "Running pre-release version of the application." << endl;
    ifstream inputFile("C:\\Users\\adeyi\\source\\repos\\Project V\\StudentData_Emails.txt");
#else
    //Standard version of code
    cout << "Running standard version of the application." << endl;
    ifstream inputFile("C:\\Users\\adeyi\\source\\repos\\Project V\\StudentData.txt");
#endif
    //Vector holding students
    vector<STUDENT_DATA> students;
    //if there was an error accessing the input file, users will be notified
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    //if running on PRERELEASE
#ifdef PRE_RELEASE
    //GETTING INFORMATION FROM EACH LINE
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string firstName, lastName, email; //STRING holding firstname, lastname and email

        // Splitting the line by the comma
        if (getline(ss, firstName, ',') && getline(ss, lastName, ',') && getline(ss, email)) {
            // Creating a STUDENT_DATA object and pushing it into the vector
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            student.email = email;
            students.push_back(student); //PUSHING INTO THE VECTOR SPACE
        }
    }
#else
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
#endif
    //closing the inputfile
    inputFile.close();

    // Debugging
#ifdef _DEBUG
    //printing out student information
    cout << "Loaded Student Data:" << endl;
    for (const auto& student : students) {
        cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName;
        //printing email information 
        if (!student.email.empty()) {
            cout << ", Email: " << student.email;
        }
        cout << endl;
    }
#endif

    return 0;
}
