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

void Course:: set_ID(string ID)
{
	this->ID = ID;
}

string Course:: get_ID()
{
	return ID;
}

void Course:: set_name(string name)
{
	this->name = name;
}

string Course:: get_name()
{
	return name;
}

void Course:: set_location(string location)
{
	this->location = location;
}

string Course:: get_location()
{
	return location;
}

void Course:: set_meeting_time(string time, string AM_PM, string meeting_date)
{
	meeting_time = time + " " + AM_PM + " " + meeting_date;
}

string Course:: get_meeting_time()
{
	return meeting_time;
}
