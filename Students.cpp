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

Students::Students()
{
	student_count = 0;
	student_capacity = CHUNKSIZE;
	student_list = new Student[CHUNKSIZE];
}

void Students::add_student() //add student list
{	
	int ID;
	bool found_student;
	string name;
	string classification;
	cout << "Enter student's ID: ";
	cin >> ID;
	cin.ignore();

	//resize the array to make sure that it starts with student capacity
	if (student_count < student_capacity)
	{
		Student *temp = new Student [student_capacity];
		for (int i = 0; i < student_count; i++)
		{
			temp[i] = student_list[i];
		}
		delete [] student_list;
		student_list = temp;
	}

	else
	{
		//resize the array size by adding a value CHUNKSIZE to student capacity
		Student *temp;
		student_capacity += CHUNKSIZE;
		temp = new Student [student_capacity];

		for (int i = 0; i < student_count; i++)
		{
			temp[i] = student_list[i];
		}
		delete [] student_list;
		student_list = temp;
	}

	found_student = false;

	//find if the student's ID is already entered in the student's array list, prevent user from entering duplicated information
	for (int i = 0; i < student_count; i++)
	{
		if (ID == student_list[i].get_ID())
		{
			found_student = true;
			cout << "This student's ID was already in the student's list" << endl;
		}
	}

	//add student if no student ID was found in the student array
	if (found_student == false)
	{
		student_list[student_count].set_ID(ID);
		
		//prompt user to enter student's name
		cout << "Enter student's first name and last name: ";
		getline(cin, name);
		student_list[student_count].set_name(name);

		//prompt user to enter student's classification
		cout << "Enter student's classification (freshman, sophomore, junior, senior): ";
		cin >> classification;
		student_list[student_count].set_classification(classification);
		cout << "New student has been added successfully" << endl;
		
		student_count++;
		
		// sorting
		for (int i = 0; i < (student_count-1); i++)
		{
			for (int j = i+1; j< student_count; j++)
			{
				if (student_list[i].get_ID() > student_list[j].get_ID())		
				{
					Student temp;
					temp = student_list[i];
					student_list[i] = student_list[j];
					student_list[j] = temp;
				}
			}
		}	
		
	}
			
}

void Students:: print_student()//print student's list
{
	for (int i = 0; i < student_count; i++)
	{
		cout << "ID: " << student_list[i].get_ID() << right << setw(25) << "Name: " << student_list[i].get_name() << setw(25) << "Classification: " << student_list[i].get_classification() << endl;
	}
}

void Students:: set_student_count(int num)
{
	student_count = num;
}

int Students:: get_student_count()
{
	return student_count;
}

void Students:: set_student_list(Student* student_list)
{
	this -> student_list = student_list;
}

Student* Students:: get_student_list()
{
	return student_list;
}
