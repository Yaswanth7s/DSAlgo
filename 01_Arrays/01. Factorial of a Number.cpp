//Finding the factorial of a number
//Time complexity: O(n)
//Space complexity: O(n)
#include<iostream>
using namespace std;
int factorial(int n){
	if(n<=1){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}
int main(){
	int n;
	cout<<"Enter the Number: "<<endl;
	cin>>n;
	cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl;
}


