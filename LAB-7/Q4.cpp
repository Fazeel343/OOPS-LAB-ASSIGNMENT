#include <iostream>
#include <vector>
using namespace std;

class Person {
    protected:
        string name;
        int id;
        string email;

    public:
        Person(string n, int i, string mail) : name(n), id(i), email(mail) {}

        virtual void displayInfo() {
            cout << "Name: " << name << ", ID: " << id << ", Email: " << email << endl;
        }

        string getName() { return name; }  
};

class Student : public Person {
    private:
        vector<string> coursesEnrolled;
        double GPA;

    public:
        Student(string n, int i, string mail, double gpa) : Person(n, i, mail), GPA(gpa) {}

        void enrollInCourse(string course) {
            coursesEnrolled.push_back(course);
            cout << name << " enrolled in " << course << endl;
        }

        void displayInfo() override {
            Person::displayInfo();
            cout << "GPA: " << GPA << ", Courses Enrolled: ";
            for (const string &course : coursesEnrolled)
                cout << course << " ";
            cout << endl;
        }
};

class Professor : public Person {
    private:
        string department;
        vector<string> coursesTaught;

    public:
        Professor(string n, int i, string mail, string dept) : Person(n, i, mail), department(dept) {}

        void assignCourse(string course) {
            coursesTaught.push_back(course);
            cout << name << " Assigned to Teach " << course << endl;
        }

        void displayInfo() override {
            Person::displayInfo();
            cout << "Department: " << department << ", Courses Taught: ";
            for (const string &course : coursesTaught)
                cout << course << " ";
            cout << endl;
        }
};

class Course {
    private:
        string courseName;
        string instructor;
        vector<Student *> enrolledStudents;

    public:
        Course(string name, string instr) : courseName(name), instructor(instr) {}

        void registerStudent(Student &student) {
            enrolledStudents.push_back(&student);
            student.enrollInCourse(courseName);
        }

        void displayCourseInfo() {
            cout << "Course: " << courseName << ", Instructor: " << instructor << endl;
            cout << "Enrolled Students: ";
            for (Student *s : enrolledStudents)
                cout << s->getName() << " "; 
            cout << endl;
        }
};

int main() {

    vector<Person *> universityMembers;

    Student s1("Ali", 1191, "ali@mail.com", 3.8);
    Student s2("Adam", 1022, "adam@mail.com", 2.9);

    Professor p1("Dr. Ahmad", 211, "ahmad@uni.com", "Computer Science");

    Course c1("Data Structures", "Dr. Ahmad");

    c1.registerStudent(s1);
    c1.registerStudent(s2);

    p1.assignCourse("Data Structures");

    universityMembers.push_back(&s1);
    universityMembers.push_back(&s2);
    universityMembers.push_back(&p1);

    for (Person *member : universityMembers) {
        member->displayInfo();
    }

    c1.displayCourseInfo();

    return 0;
}
