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

class Students
{
	private:
		int student_count;
		int student_capacity;
		Student *student_list;
	public:
		Students();
		void add_student();
		void print_student();
		void set_student_count(int num);
		int get_student_count();
		void set_student_list(Student* student_list);
		Student* get_student_list();
};
