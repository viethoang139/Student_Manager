
#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<vector>
#include<iomanip>
#include<iostream>
using namespace std;

static int gId = 0;

class Student {
private:
	int mId;
	int mAge;
	string mName;
	float mGpa;

public:

	Student() {

	}

	Student(int id, int age, string name, float gpa)
		: mId{ id }, mAge{ age }, mName{ name }, mGpa{ gpa }
	{

	}

	int getId()const { return mId; }

	void setAge(int age) { mAge = age; }

	int getAge() const { return mAge; }

	void setName(string name) { mName = name; }

	string getName()const { return mName; }

	float getGpa() const { return mGpa; }

	static bool comapreGpa(const Student& a, const Student& b) {
		return a.mGpa > b.mGpa;
	}

	void addStudent(vector<Student>& student);

	void updateStudent(vector<Student>& student);

	void deleteStudent(vector<Student>& student);

	void searchStudent(vector<Student>& student);

	void displayAllStudent(vector<Student>& student);

	void sortStudentByGpaDesc(vector<Student>& student);

	void classifyStudentByGpa(vector<Student>& student);

	void writeToFile(const string& fileName);

	void readFromFile(const string& fileName, vector<Student>& student);

	void display() {
		cout << "\t\t ID: " << mId << "\n";
		cout << "\t\t Age: " << mAge << "\n";
		cout << "\t\t Name: " << mName << "\n";
		cout << "\t\t Gpa: " << fixed << setprecision(2) << mGpa << "\n";
	}
};

#endif // !STUDENT_H
