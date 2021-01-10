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

class Courses
{
	private:
		int course_count;
		int course_capacity;
		Course *course_list;
	public:
		Courses();
		void add_course();//add course
		void print_course();//print course list
		void set_course_count(int num);
		int get_course_count();
		void set_course_list(Course* course_list);
		Course* get_course_list();
};
