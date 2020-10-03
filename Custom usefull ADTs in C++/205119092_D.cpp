/* Type Conversion
Take input string having maths equation and return a value for that*/

#include<bits/stdc++.h>
using namespace std;

class Evaluate{
	string infix;
	string postfix;
	
	public:
		int prec(char c) { 
		    if(c == '^') 
		    return 3; 
		    else if(c == '*' || c == '/') 
		    return 2; 
		    else if(c == '+' || c == '-') 
		    return 1; 
		    else
		    return -1; 
		} 
		void operator=(string s){
			infix = s;
			stack<char> st; 
		    st.push('N'); 
		    int l = s.length(); 
		    string ns; 
		    for(int i = 0; i < l; i++) 
		    { 
		        if(s[i] >= '0' && s[i] <= '9') 
		        ns+=s[i]; 
		  
		        else if(s[i] == '(') 
		          
		        st.push('('); 
		          
		        else if(s[i] == ')') 
		        { 
		            while(st.top() != 'N' && st.top() != '(') 
		            { 
		                char c = st.top(); 
		                st.pop(); 
		               ns += c; 
		            } 
		            if(st.top() == '(') 
		            { 
		                char c = st.top(); 
		                st.pop(); 
		            } 
		        } 
		          
		        else{ 
		            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
		            { 
		                char c = st.top(); 
		                st.pop(); 
		                ns += c; 
		            } 
		            st.push(s[i]); 
		        } 
		  
		    } 
		    while(st.top() != 'N') 
		    { 
		        char c = st.top(); 
		        st.pop(); 
		        ns += c; 
		    }
		    postfix = ns;
		}
		
		
		friend ostream & operator<<(ostream&out, const Evaluate&obj){
			string exp = obj.postfix;
			stack<int> Stack;  
		    for (int i = 0; exp[i]; ++i)  
		    {    
		        if (isdigit(exp[i]))  
		            Stack.push(exp[i] - '0');   
		        else
		        {  
		            int val1 = Stack.top();  Stack.pop();
		            int val2 = Stack.top();  Stack.pop();
		            switch (exp[i])  
		            {  
		            case '+': Stack.push(val2 + val1); break;  
		            case '-': Stack.push(val2 - val1); break;  
		            case '*': Stack.push(val2 * val1); break;  
		            case '/': Stack.push(val2/val1); break;  
		            }  
		        }  
		    } 
		    out << Stack.top(); 
		}
		
};



int main(){
	Evaluate E;
	E = "1+2-6*7/(4-3*6)"; 
	cout << E;
	cout << endl; //Output 6
	
	Evaluate F;
	F = "(92*14)/(24-21)-36";
	cout << F;
}
