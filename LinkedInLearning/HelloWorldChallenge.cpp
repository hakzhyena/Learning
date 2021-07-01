#include <iostream>
#include <string>

int main() 
{
	using namespace std;
	std::cout << "Enter your name " << endl;
	string name;
	cin >> name;
	cout << "Hello " << name << "! Enter your favourite food " << endl;
	string food;
	cin >> food;
	cout << "My favourite food is also " << food << "!" << endl;

}