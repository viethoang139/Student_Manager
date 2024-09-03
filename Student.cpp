
#include "Student.h"
#include<string>
#include<iomanip>
#include<algorithm>
#include<type_traits>

void Student::addStudent(vector<Student>& student) {
	int age;
	string name;
	float gpa;
	if (student.empty()) {
		gId = 0;
	}

	cout << "\t\t Enter age: ";
	cin >> age;
	cout << "\t\t Enter name: ";
	cin.ignore();
	getline(cin, name);
	cout << "\t\t Enter gpa: ";
	cin >> gpa;
	Student newStudent{ ++gId , age, name, gpa };
	student.push_back(newStudent);
	cout << "\n";
	cout << "\t\t Add student successfully!!!" << "\n";
	cout << "\n";
}

void Student::updateStudent(vector<Student>& student) {
	if (student.empty()) {
		cout << "\t\t Student list is empty" << "\n";
		return;
	}
	int id;
	bool found = false;
	int choice;
	cout << "\t\t Enter id to update: ";
	cin >> id;

	for (int i = 0; i < student.size(); i++) {
		if (student[i].getId() == id) {
			found = true;
			cout << "\t\t---Student Found -----" << "\n";

			cout << "\t\t 1. Update age " << "\n";

			cout << "\t\t 2. Update name " << "\n";

			cout << "\t\t  Enter Your Choice :";

			cin >> choice;

			switch (choice)
			{
			case 1: {
				int age;
				cout << "\t\t Enter new age: ";
				cin >> age;
				student[i].setAge(age);
				break;
			}
			case 2: {
				string name;
				cout << "\t\t Enter new name: ";
				cin.ignore();
				getline(cin, name);
				student[i].setName(name);
				break;
			}
			default:
				cout << "\t\t Invalid choice...!" << "\n";
			}
		}
		else {
			break;
		}
		cout << "\t\t Update succuessfully!!!\n\n";
		return;
	}
	if (!found) {
		cout << "\t\t Student not found " << "\n\n";
	}
}

void Student::deleteStudent(vector<Student>& student) {
	if (student.empty()) {
		cout << "\t\t Student list is empty" << "\n";
		return;
	}
	int id;
	cout << "\t\t Enter id to delete: ";
	cin >> id;
	bool found = false;
	for (int i = 0; i < student.size(); i++) {
		if (student[i].getId() == id) {
			found = true;
			student.erase(student.begin() + i);
			gId--;
			cout << "\t\t Student delete successfully" << "\n";
			break;
		}
	}
	if (!found) {
		cout << "\t\tStudent not found\n\n";
	}
}

void Student::searchStudent(vector<Student>& student) {
	if (student.empty()) {
		cout << "\t\t Student list is empty" << "\n";
		return;
	}
	int id;
	cout << "\t\t Enter id: ";
	cin >> id;

	for (int i = 0; i < student.size(); i++) {
		if (student[i].getId() == id) {
			cout << "\t\t--------Student Found ------------" << "\n\n";

			student[i].display();
			return;
		}
	}
	cout << "\t\t Student not found!!!";
}

void Student::sortStudentByGpaDesc(vector<Student>& student) {
	if (student.empty()) {
		cout << "\t\t Student list is empty\n\n";
		return;
	}
	sort(student.begin(), student.end(), Student::comapreGpa);
	cout << "\t\t Sort successfully\n\n";
}

void Student::displayAllStudent(vector<Student>& student) {
	if (student.empty()) {
		cout << "\t\t Student list is empty" << "\n\n";
		return;
	}
	for (int i = 0; i < student.size(); i++) {
		student[i].display();
		cout << "\n";
	}
}