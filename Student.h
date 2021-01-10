/*Name: Yen Pham	yenpham@my.unt.edu
Course: CSCE1040
Instructor: David Keathly
HW2
Description: This program is a simple program to manage a Grade Book
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
	private:
		int ID;
		string name;
		string classification;
	public:
		void set_ID(int num);
		int get_ID();
		void set_name(string name);
		string get_name();
		void set_classification(string classification);
		string get_classification();
};
