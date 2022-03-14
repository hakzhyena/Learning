class A 
{
public:
	A(const int& data) :data(data) {}
	A& operator=(A& a) 
	{
		data = a.data;
		return *this;
	}

	/*void operator=(A& a)
	{
		data = a.data;
	}*/
private:
	int data;
};
int main() 
{
	
	A a(1);
	A b(2);
	A c(3);
	c = a = b;
	
	
}