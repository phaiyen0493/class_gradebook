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

class Enrollments
{
	private:
		int enrollment_count;
		int enrollment_capacity;
		Enrollment *enrollment_list; //list of students in a course
	public:
		Enrollments();
		void set_enrollment_count(int num);
		int get_enrollment_count();
		void add_enrollment(Students student, Courses course); //add student to a course
		void print_enrollment(); //print all students in a course
		void add_grade(); //add grades for a student in a course
		void print_grade();//print a list of all grades for a student in a course
		void compute_student_average(); //compute the average for a student in a course
		void compute_course_average(); //compute the average for a course
		void set_enrollment_list(Enrollment* enrollment_list);
		Enrollment* get_enrollment_list();
};
