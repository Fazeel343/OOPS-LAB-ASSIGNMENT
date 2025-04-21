#include <iostream>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int credits) = 0;
};

class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }
    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(string status, int credits) override {
        if (status == "undergraduate") return credits * 200;
        else if (status == "graduate") return credits * 300;
        else if (status == "doctoral") return credits * 400;
        else return 0;
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("AI in Healthcare");

    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    cout << "Tuition for Graduate (9 credits): $" << gs.getTuition("graduate", 9) << endl;
    cout << "Tuition for Doctoral (12 credits): $" << gs.getTuition("doctoral", 12) << endl;

    return 0;
}
