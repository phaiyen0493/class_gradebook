/*Name: Yen Pham	yenpham@my.unt.edu
Course: CSCE1040
Instructor: David Keathly
HW2
Description: This program is a simple program to manage a Grade Book
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Student.h"
#include "Students.h"
#include "Course.h"
#include "Courses.h"
#include "Enrollment.h"
#include "Enrollments.h"

using namespace std;

void Student::set_ID(int num)
{
	ID = num;
}

int Student::get_ID()
{
	return ID;
}

void Student::set_name(string name)
{
	this->name = name;
}

string Student::get_name()
{
	return name;
} 

void Student::set_classification(string classification)
{
	this->classification = classification;
}

string Student::get_classification()
{
	return classification;
} 
