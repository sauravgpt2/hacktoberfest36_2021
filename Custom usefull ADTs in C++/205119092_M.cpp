/*
	Usage of static member which helps to find out total number of students and to auto generate roll for each student
	serially
*/
#include <iostream>
using namespace std;
class Student
{
	public:
		int roll;
		string name;
		float grade;
		static int addNo;
		
		Student(){}
		
		Student(string n, float g){
			addNo++;
			roll=addNo;
			name=n;
			grade = g;
		}
		
		void addStudent(string n, float g){
			addNo++;
			roll=addNo;
			name=n;
			grade = g;
		}
		void display(){
			cout<<"Name: "<<name<<" "<<"Roll: "<<roll<< " " << "Grade: " << grade<<endl;
		}
		
		static float avg(Student *S){
			float sum = 0;
			for(int i=0; i<S[i].addNo; i++) sum += S[i].grade;
			return (float)sum/addNo;
		}
};

int Student::addNo=0;
int main()
{
	int i = 0;
	Student *S;
	cout << "Enter max number of Students: ";
	int num; cin >> num;
	S = new Student[num];
	int ch; string name;
	float grade;
	while(1){
		cout << endl;
		cout << "1. Add new student\n";
		cout << "2. Find average\n";
		cout << "3. Display Details\n";
		cout << "0. Exit\n";
		cout << "YOUR CHOICE: "; cin >> ch;
		switch(ch){
			case 1:
				cout << "Name: "; cin >> name;
				cout << "Grade: "; cin >> grade;
				S[i].addStudent(name, grade); i++; break;
			
			case 2:
				
				cout << Student::avg(S); break;
			case 3:
				for(int j=0; j<i; j++){
					S[j].display();
				} break;
				
			case 0:
				exit(1);
		}
	}
}
