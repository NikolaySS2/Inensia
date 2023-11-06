#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Student {
private:
    string name;
    int facultyNumber;
    vector <int> marks;

public:
    Student(string name_data) {
        name = name_data;
        facultyNumber = rand() % 100000;
        int numberOfMarks = 1 + rand() % 9;
        for (int i = 0; i < numberOfMarks; i++) {
            marks.push_back(rand() % 7);
        }
    }
    void setName(string N) {
        name = N;
    }
    string getName()const {
        return name;
    }

    double calculateMarks() {
        if (marks.empty()) {
            return 0.0;
        }
        else {
            int sum = 0;
            for (int i = 0; i < marks.size(); i++) {
                sum = sum + marks[i];
            }
            return sum / marks.size();
        }
    }
};

void GPAoutput(vector <Student>& studentslist, string studentName) {
    for (int i = 0; i < studentslist.size(); i++) {
        if (studentslist[i].getName() == studentName) {
           cout<<studentslist[i].calculateMarks();
           return;
        }
    }
    cout << "student not found ";
    return ;
}

  int main() {
      vector <Student> students;
      int n;
      cout << "Enter number of students"<<endl;
      cin >> n;
      cout << "Enter the names of these students" << endl;
      for (int i = 0; i < n; i++) {
          string studentName;
          cin >> studentName;
          students.push_back(Student(studentName));
      }
      cout << "Type a student's name to get their GPA" << endl;
      string nameToSearch;
      cin >> nameToSearch;

      GPAoutput(students, nameToSearch);
    }
    
