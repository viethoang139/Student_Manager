
#include "Student.h"
#include<string>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<sstream>
#include<fstream>

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
	newStudent.writeToFile("data.txt");
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
			break;
		}
	}
	if (!found) {
		cout << "\t\t Can not found studen\n\n";
		return;
	}
	ofstream ofs("data.txt", ios::out, ios::trunc);
	if (ofs.is_open()) {
		for (Student& stu : student) {
			ofs << stu.getAge() << "," << stu.getName() << "," << stu.getGpa() << "\n";
		}
		ofs.close();
	}
	cout << "\t\tUpdate successfully!!!\n\n";
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
			break;
		}
	}
	if (!found) {
		cout << "\t\tStudent not found\n\n";
		return;
	}
	ofstream ofs("data.txt", ios::out, ios::trunc);
	if (ofs.is_open()) {
		for (Student& stu : student) {
			ofs << stu.getAge() << "," << stu.getName() << "," << stu.getGpa() << "\n";
		}
		ofs.close();
	}
	cout << "\t\t Student delete successfully" << "\n\n";
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

void Student::classifyStudentByGpa(vector<Student>& student) {
	unordered_map<string, vector<Student>> map;
	for (Student& stu : student) {
		if (stu.getGpa() >= 3.2) {
			map["excellent"].push_back(stu);
		}
		else if (stu.getGpa() >= 2.5) {
			map["good"].push_back(stu);
		}
		else {
			map["average"].push_back(stu);
		}
	}
	if (!map["excellent"].empty()) {
		cout << "\t\t Excellent Students: \n\n";
		sortStudentByGpaDesc(map["excellent"]);
;		displayAllStudent(map["excellent"]);
	}
	else {
		cout << "\t\t Not found any excellent students. \n\n";
	}

	if (!map["good"].empty()) {
		cout << "\t\t Good Students: \n\n";
		sortStudentByGpaDesc(map["good"]);
		displayAllStudent(map["good"]);
	}
	else {
		cout << "\t\t Not found any good students. \n\n";
	}

	if (!map["average"].empty()) {
		cout << "\t\t Average Students: \n\n";
		sortStudentByGpaDesc(map["average"]);
		displayAllStudent(map["average"]);
	}
	else {
		cout << "\t\t Not found any average students. \n\n";
	}

}

void Student::writeToFile(const string& fileName) {
	ofstream outFile(fileName, ios::app);
	if (outFile.is_open()) {
		outFile << getAge() << "," << getName() << "," 
			<< getGpa() << "\n";
		outFile.close();
	}
	else {
		cout << "Unable to open file" << "\n";
	}
}

void Student::readFromFile(const string& fileName,vector<Student>& student) {
	ifstream inFile(fileName);
	if (inFile.is_open()) {
		string line;
		while (getline(inFile, line)) {
			istringstream iss(line);
			string age, name, gpa;
			getline(iss, age, ',');
			getline(iss, name, ',');
			getline(iss, gpa, ',');

			int ageStudent = stoi(age);
			float gpaStudent = stof(gpa);
			student.emplace_back(++gId, ageStudent, name, gpaStudent);
		}
		cout << "\t\t Read data successfully\n";
		inFile.close();
	}
	else {
		cout << "Unable to open file." << "\n";
	}
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