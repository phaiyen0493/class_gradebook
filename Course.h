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

class Course
{
	private:
		string ID;
		string name;
		string location;
		string meeting_time;
	public:
		void set_ID(string ID);
		string get_ID();
		void set_name(string name);
		string get_name();
		void set_location(string location);
		string get_location();
		void set_meeting_time(string time, string AM_PM, string meeting_date);
		string get_meeting_time();
};
