/*
	Program to use static member
*/
#include <iostream>
using namespace std;
class Student{
	public:
 		int roll;
 		string name;
 		static int addNo;
 		Student(string n){
 			addNo++;
 			roll=addNo;
 			name=n;
 		}
 		void display(){
 			cout<<"Name "<<name<<endl<<"Roll "<<roll<<endl;
		}
};
int Student::addNo=0;
int main(){
 Student s1("Saurav");
 Student s2("Praveen");
 Student s3("Sharad");
 Student s4("Ankita");
 Student s5("Harshita");
 Student s6("Harsh");


 s1.display();
 s6.display();
 cout<<"Number Admission "<<Student::addNo<<endl;
}
