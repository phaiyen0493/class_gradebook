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
#include "Student.h"
#include "Students.h"
#include "Course.h"
#include "Courses.h"
#include "Enrollment.h"
#include "Enrollments.h"

using namespace std;
#define CHUNKSIZE 50

Enrollment::Enrollment()
{
	grade_count = 0;
	student_average = 0;
}

void Enrollment:: set_enrollment_ID(int ID)
{
	enrollment_ID = ID;
}

int Enrollment:: get_enrollment_ID()
{
	return enrollment_ID;
}

void Enrollment:: set_student_ID(int ID)
{
	student_ID = ID;
}

int Enrollment:: get_student_ID()
{
	return student_ID;
}

void Enrollment:: set_student_name(string name)
{
	student_name = name;
}

string Enrollment:: get_student_name()
{
	return student_name;
}

void Enrollment:: set_course_ID(string ID)
{
	course_ID = ID;
}

string Enrollment:: get_course_ID()
{
	return course_ID;
}

void Enrollment:: set_grade(int *student_grade)
{
	grade = student_grade;
}

int* Enrollment:: get_grade()
{
	return grade;
}

void Enrollment:: set_grade_count(int num)
{
	grade_count = num;
}

int Enrollment:: get_grade_count()
{
	return grade_count;
}

void Enrollment:: set_student_average(float average)
{
	student_average = average;
}

float Enrollment:: get_student_average()
{
	return student_average;
}

void Enrollment:: set_letter_grade(char letter)
{
	letter_grade = letter;
}

char Enrollment:: get_letter_grade()
{
	return letter_grade;
}
