#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Since the relationship between these classes is bidirectional, the Doctor class must use forward declaration here.
class Doctor;

class Patient {
private:
	string m_name;
	// thanks to the Doctor's forward declaration above, this line won't cause a compilation error
	vector<Doctor*> m_doctor;

	// we make addDoctor() method private because we don't want it to be public
	// instead it will be accessed via Doctor::addPatient()
	// we will define this method after the definition of the Doctor class, since we first need to define Doctor in order to use anything related to it
	void addDoctor(Doctor *doc);
public:
	Patient(string name): m_name{name} {}
	string getName() const { return m_name; }

	friend ostream& operator<<(ostream &out, const Patient &pat);

	// we make the Doctor class friendly so that we can access the private addDoctor() method
	friend class Doctor;
};

class Doctor {
private:
	string m_name;
	vector<Patient*> m_patient;
public:
	Doctor(string name): m_name{name} {}
	
	void addPatient(Patient *pat) {
		// doctor adds a patient
		m_patient.push_back(pat);
		// patient adds a doctor
		pat->addDoctor(this);
	}

	string getName() const { return m_name; }

	friend ostream& operator<<(ostream &out, const Doctor &doc) {
		unsigned int length = doc.m_patient.size();
		if(length == 0) {
			out << doc.m_name << " has no patients right now";
			return out;
		}

		out << doc.m_name << " is seeing patients: ";
		for(unsigned int count = 0; count < length; ++count)
			out << doc.m_patient[count]->getName() << ' ';
		
		return out;
	}
};

void Patient::addDoctor(Doctor *doc) {
	m_doctor.push_back(doc);
}

ostream& operator<<(ostream &out, const Patient &pat) {
	unsigned int length = pat.m_doctor.size();
	if(length == 0) {
		out << pat.getName() << " has no doctors right now";
		return out;
	}

	out << pat.m_name << " is seeing doctors: ";
	for(unsigned int count = 0; count < length; ++count)
		out << pat.m_doctor[count]->getName() << ' ';
	
	return out;
}

int main(int argc, const char *argv[]) {
	// creating Patients outside the scope of the Doctor class
	Patient *p1 = new Patient("Anton");
	Patient *p2 = new Patient("Ivan");
	Patient *p3 = new Patient("Derek");

	// creating Doctors outside the scope of the Patient class
	Doctor *d1 = new Doctor("John");
	Doctor *d2 = new Doctor("Tom");

	d1->addPatient(p1);

	d2->addPatient(p1);
	d2->addPatient(p3);

	cout << *d1 << '\n';
	cout << *d2 << '\n';
	cout << *p1 << '\n';
	cout << *p2 << '\n';
	cout << *p3 << '\n';

	delete p1;
	delete p2;
	delete p3;

	delete d1, d2;
	
	return 0;
}