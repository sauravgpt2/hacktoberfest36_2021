/*Usage of protected and deployement of Hierarchical Inheritance*/

#include <iostream> 
using namespace std;
class Side
{
	protected:
		int l;
	public:
	void set_values(int x){
		l = x;
	}
}; 

class Square: public Side{
	public:
	int sq()
	{ return (l *l); }
}; 

class Cube:public Side{
	public:
	int cub()
	{ return (l *l*l); }
}; 

int main (){
	Square s;
	s.set_values (10);
	cout << "The square value is::" << s.sq() << endl;
	Cube c;
	c.set_values (20);
	cout << "The cube value is::" << c.cub() << endl;
	return 0;
}
