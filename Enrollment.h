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

class Enrollment
{
	private:
		int enrollment_ID;
		int student_ID;
		string student_name;
		string course_ID;
		int *grade;
		int grade_count;
		float student_average;
		char letter_grade;	
	public:
		Enrollment();
		void set_enrollment_ID(int ID);
		int get_enrollment_ID();
		void set_student_ID(int ID);
		int get_student_ID();
		void set_student_name(string name);
		string get_student_name();
		void set_course_ID(string ID);
		string get_course_ID();
		void set_grade(int *student_grade);
		int* get_grade();
		void set_grade_count(int num);
		int get_grade_count();
		void set_student_average(float average);
		float get_student_average();
		void set_letter_grade(char letter);
		char get_letter_grade();
};
