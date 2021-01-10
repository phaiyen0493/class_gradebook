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

Courses::Courses()
{
	course_count = 0;
	course_capacity = CHUNKSIZE;
	course_list = new Course[CHUNKSIZE];
}
	
void Courses:: add_course()
{
	string ID;
	bool found_course;
	string name;
	string location;
	string time;
	string AM_PM;
	string meeting_date;
	
	//prompt user to enter course ID
	cout << "Enter your course's ID: ";
	cin >> ID;
	cin.ignore();

	//resize the dynamic array to make sure the array always starts with CHUNKSIZE size 
	if (course_count < course_capacity)
	{
		Course *temp = new Course [course_capacity];
		for (int i = 0; i < course_count; i++)
		{
			temp[i] = course_list[i];
		}
		delete [] course_list;
		course_list = temp;
	}
	
	//resize the dynamic array to add more space
	else
	{
		Course *temp;
		course_capacity += CHUNKSIZE; 
		temp = new Course[course_capacity];

		for (int i = 0; i < course_count; i++)
		{
			temp[i] = course_list[i];	
		}
		
		delete [] course_list;
		course_list = temp;
	}

	found_course = false;
	//find the course'ID that has been added before and prevent the user duplicate the course
	for (int i = 0; i < course_count; i++)
	{
		if (ID.compare(course_list[i].get_ID()) == 0)
		{
			found_course = true;
			cout << "This course was already in the list" << endl;
		}
	}

	//add course if no course ID in the course's list has been found
	if (found_course == false)
	{
		course_list[course_count].set_ID(ID);//set input ID as course's ID

		//prompt user to enter course's name
		cout << "Enter course's name: ";
		getline(cin, name);
		course_list[course_count].set_name(name); 
	
		//prompt user to enter course's location	
		cout << "Enter course's location: ";
		getline(cin, location);
		course_list[course_count].set_location(location);

		//prompt user to enter meeting time
		cout << "Enter course's meeting time (hh:mm-hh:mm): ";
		cin >> time;
		cin.ignore();

		//prompt user to enter meeting date
		cout << "Enter meeting dates: ";
		getline(cin, meeting_date);
		
		//prompt user to set up the time
		cout << "Start AM or PM? ";
		cin >> AM_PM;
		course_list[course_count].set_meeting_time(time, AM_PM, meeting_date);
		cout << "New course has been added succesfully" << endl;//display when add course succesfully
		course_count++;//increment to 1

		//sort course based on ID
		for (int i = 0; i < course_count-1; i++)
		{
			for (int j = i+1; j < course_count; j++)
			{
				if (course_list[i].get_ID() > course_list[j].get_ID())		
				{
					Course temp;
					temp = course_list[i];
					course_list[i] = course_list[j];
					course_list[j] = temp;
				}
			}
		}	

	}
}

void Courses:: print_course()//print courses in the course list array
{	
	for (int i = 0; i < course_count; i++)
	{
		cout << course_list[i].get_ID() << right << setw(25) << course_list[i].get_name() << right << setw(15) << course_list[i].get_location() << right << setw(25) << course_list[i].get_meeting_time() << endl;
	}
}

void Courses:: set_course_count(int num)
{
	course_count = num;
}

int Courses:: get_course_count()
{
	return course_count;
}

void Courses:: set_course_list(Course* course_list)
{
	this -> course_list = course_list;
}

Course* Courses:: get_course_list()
{
	return course_list;
}
