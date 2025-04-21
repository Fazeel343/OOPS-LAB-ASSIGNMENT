#include <iostream>
#include <string>
using namespace std;

class PatientRecord;

class Doctor {
public:
    void updateMedicalHistory(PatientRecord& pr, const string& history);
};

class Billing {
public:
    void addBillingDetails(PatientRecord& pr, const string& billing);
};

class PatientRecord {
private:
    string name, id, dob, medicalHistory, billingInfo;

    friend class Doctor;
    friend class Billing;

public:
    PatientRecord(string n, string i, string d) : name(n), id(i), dob(d) {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + id;
    }

    string getMedicalData(string role) const {
        if (role == "doctor") return medicalHistory;
        return "Access Denied";
    }

    void showBillingInfo(string role) const {
        if (role == "billing") cout << "Billing Info: " << billingInfo << endl;
        else cout << "Access Denied\n";
    }

private:
    void setMedicalHistory(const string& history) { medicalHistory = history; }
    void setBillingInfo(const string& billing) { billingInfo = billing; }
};

void Doctor::updateMedicalHistory(PatientRecord& pr, const string& history) {
    pr.setMedicalHistory(history);
}

void Billing::addBillingDetails(PatientRecord& pr, const string& billing) {
    pr.setBillingInfo(billing);
}

int main() {
    PatientRecord p("Zain", "P01", "1999-03-22");
    Doctor doc;
    Billing bill;

    doc.updateMedicalHistory(p, "Diabetes, Asthma");
    bill.addBillingDetails(p, "Paid: 5000 PKR");

    cout << p.getPublicData() << endl;
    cout << "Medical Data: " << p.getMedicalData("doctor") << endl;
    p.showBillingInfo("billing");

    return 0;
}
