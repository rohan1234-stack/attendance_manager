
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
public:
    string regNo, name;
    int total = 0, present = 0;

    Student(string r, string n) : regNo(r), name(n) {}

    float getPercentage() {
        if(total == 0) return 0;
        return (present * 100.0) / total;
    }
};

class AttendanceManager {
    vector<Student> students;

public:
    void addStudent() {
        string reg, name;
        cout << "Enter RegNo: ";
        cin >> reg;
        for(auto &s: students) {
            if(s.regNo == reg) {
                cout << "Duplicate student!\n";
                return;
            }
        }
        cout << "Enter Name: ";
        cin >> name;
        students.push_back(Student(reg, name));
    }

    void markAttendance() {
        string reg;
        char status;
        cout << "Enter RegNo: ";
        cin >> reg;
        for(auto &s: students) {
            if(s.regNo == reg) {
                cout << "Enter P/A: ";
                cin >> status;
                if(status != 'P' && status != 'A') {
                    cout << "Invalid input!\n";
                    return;
                }
                s.total++;
                if(status == 'P') s.present++;
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void showReport() {
        float total = 0;
        for(auto &s: students) {
            float p = s.getPercentage();
            cout << s.regNo << " " << s.name << " -> " << p << "%\n";
            total += p;
        }
        cout << "Class Avg: " << total/students.size() << "%\n";
    }
};

int main() {
    AttendanceManager am;
    int ch;
    do {
        cout << "\n1.Add\n2.Mark\n3.Report\n4.Exit\n";
        cin >> ch;
        if(ch == 1) am.addStudent();
        else if(ch == 2) am.markAttendance();
        else if(ch == 3) am.showReport();
    } while(ch != 4);
}
