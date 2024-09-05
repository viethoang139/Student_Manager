#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include "Student.h"

using namespace std;

int main() {

	vector<Student>studentList;
	Student student;
	char choice;

	do {
		int option;
		cout << "\n\t\t--------------------------------";

		cout << "\n\t\t*** Student Management System ***";

		cout << "\n\t\t--------------------------------";

		cout << "\n\t\t 1. Add New Student" << endl;

		cout << "\t\t 2. Display All Student " << endl;

		cout << "\t\t 3. Search Student" << endl;

		cout << "\t\t 4. Update Student" << endl;

		cout << "\t\t 5. Delete Student " << endl;

		cout << "\t\t 6. Sort Student By Gpa Descending " << endl;

		cout << "\t\t 7. Classify Student By Gpa" << endl;

		cout << "\t\t 8. Read data from file " << endl;

		cout << "\t\t 9. Exit" << endl;

		cout << "\t\t Enter Your Choice : ";

		cin >> option;

		cout << "\n";

		switch (option)
		{
		case 1:
			student.addStudent(studentList);
			break;
		case 2:
			student.displayAllStudent(studentList);
			break;
		case 3:
			student.searchStudent(studentList);
			break;
		case 4:
			student.updateStudent(studentList);
			break;
		case 5:
			student.deleteStudent(studentList);
			break;
		case 6:
			student.sortStudentByGpaDesc(studentList);
			break;
		case 7:
			student.classifyStudentByGpa(studentList);
			break;
		case 8:
			student.readFromFile("data.txt", studentList);
			break;
		case 9:
			exit(1);
		default:
			cout << "\t\t Invalid number " << "\n";
		}
		cout << "\t\t Do you want to continue [Yes/No]: ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y' || choice == 'Yes');
}



