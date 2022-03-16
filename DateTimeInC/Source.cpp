
#include <Windows.h>
#include <iostream>

void printDate() 
{
	using namespace std;
	cout << __DATE__ << endl;//The date at which the file is compiled
}
void printTime()
{
	using namespace std;
	cout << __TIME__ << endl;//The time at which the file is compiled
}
void printLineOfCompilation() 
{
	using namespace std;
	cout << __LINE__ << endl;//The line of compilation
}
void printFileName() 
{
	using namespace std;
	cout << __FILE__ << endl;//The source file name of the compilation
}

int main() 
{
	using namespace std;
	printDate();
	printTime();
	printLineOfCompilation();
	printFileName();
	{
        char buff[70];
        tm my_time;
        my_time.tm_year = 112; // = year 2012
        my_time.tm_mon = 9;    // = 10th month
        my_time.tm_mday = 9;    // = 9th day
        my_time.tm_hour = 8;   // = 8 hours
        my_time.tm_min = 10;   // = 10 minutes
        my_time.tm_sec = 20;   // = 20 secs
        

        if (strftime(buff, sizeof buff, "%A %c", &my_time)) {
            puts(buff);
        }
        else {
            puts("strftime failed");
        }

        setlocale(LC_TIME, "el_GR.utf8");

        if (strftime(buff, sizeof buff, "%A %c", &my_time)) {
            puts(buff);
        }
        else {
            puts("strftime failed");
        }

	}
}