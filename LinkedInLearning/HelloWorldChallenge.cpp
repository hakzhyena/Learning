#include <iostream>
#include <string>

void TimeComplexity() 
{
	int a = 0, N = 5;
	for (int i = 0; i < N; i++) {
		for (int j = N; j > i; j--) {
			a = a + i + j;
			std::cout << " i:" << i << " j:" << j;
		}
		std::cout << std::endl;
	}
}
int main() 
{
	TimeComplexity();
	/*using namespace std;
	std::cout << "Enter your name " << endl;
	string name;
	cin >> name;
	cout << "Hello " << name << "! Enter your favourite food " << endl;
	string food;
	cin >> food;
	cout << "My favourite food is also " << food << "!" << endl;*/

}