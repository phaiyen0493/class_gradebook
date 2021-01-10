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
#include <sstream> 
#include <fstream>
#include "Student.h"
#include "Students.h"
#include "Course.h"
#include "Courses.h"
#include "Enrollment.h"
#include "Enrollments.h"

using namespace std;

void store_GradeBook(Students student, Courses course, Enrollments enrollment);

void load_GradeBook(Students* student, Courses* course, Enrollments * enrollment);

int main()
{
// Display name, EUID, e-mail address, the department name, and course number
	cout << "\n\t+----------------------------------------------+" << endl;
	cout << "\t|       Computer Science and Engineering       |" << endl;
	cout << "\t|        CSCE 1040 - Computer Science 2        |" << endl;
	cout << "\t|   Yen Pham    yhp0005    yenpham@my.unt.edu  |" << endl;
	cout << "\t+----------------------------------------------+" << endl;

	int choice;
	Courses course;
	Students student;
	Enrollments enrollment;

	do
	{
		cout << endl << "-----------------------Grade Book--------------------------" << endl;
		cout << "0. Exit" << endl;
		cout << "1. Add a new course" << endl;
		cout << "2. Add a new student" << endl;
		cout << "3. Add enrollment" << endl;
		cout << "4. Add grades for a student in a course" << endl;
		cout << "5. Print a list of all grades for a student in a course" << endl;
		cout << "6. Print a list of all students in a course" << endl;
		cout << "7. Compute the average for a student in a course" << endl;
		cout << "8. Print a list of all courses" << endl;
		cout << "9. Print a list of all students" << endl;
		cout << "10. Compute the average for a course" << endl;
		cout << "11. Store Grade book" << endl;
		cout << "12. Load Grade book" << endl;
		cout << "-----------------------------------------------------------" << endl;

		cout << "Enter your choice from 0 to 12: ";
		cin >> choice;
		
		switch(choice)
		{
			case 0: cout << "Good bye!" << endl; break;
			case 1: course.add_course(); break;//add course
			case 2: student.add_student(); break;//add student
			case 3: enrollment.add_enrollment(student, course); break;//add student in a course
			case 4: enrollment.add_grade(); break;//add grade for a student in a course
			case 5: enrollment.print_grade(); break;//print grade
			case 6: enrollment.print_enrollment(); break;//print enrollment
			case 7: enrollment.compute_student_average(); break;//print student average
			case 8: course.print_course(); break;//print course
			case 9: student.print_student(); break;//print student
			case 10: enrollment.compute_course_average(); break;//print course average
			case 11: store_GradeBook(student, course, enrollment); break;//store grade book
			case 12: load_GradeBook(&student, &course, &enrollment); break;//load grade book
			default: cout << "Wrong choice. Please enter number from 0 to 12.\n"; break;
		}
	} while (choice != 0);
	return 0;
}

int number_of_students()//count number of students in file students
{
	string line;
	int count=0;
	ifstream fin;fin.open("students"); //open file
	
	if(fin.fail())
	{
		exit(EXIT_FAILURE); //exit if fail
	}
	
	while(getline(fin, line))
	{
		++count; //count how many lines in the file
	}
	fin.close();//close file
	return count;//return number of student in the file
}

int number_of_courses()//count number of courses in file students
{
	string line;
	int count=0;
	ifstream fin4;
	fin4.open("courses"); //open file
	
	if(fin4.fail())
	{
		exit(EXIT_FAILURE); //exit if fail
	}
	
	while(getline(fin4, line))
	{
		++count; //count how many lines in the file
	}
	fin4.close();//close file
	return count;//return number of student in the file
}

int number_of_enrollments()//count number of enrollments in file enrollments
{
	string line1;
	string line2;
	int count=0;
	ifstream fin5;
	fin5.open("enrollments"); //open file
	
	if(fin5.fail())
	{
		exit(EXIT_FAILURE); //exit if fail
	}
	
	while(getline(fin5, line1) && getline(fin5, line2))
	{
		++count; //count how many lines in the file
	}
	fin5.close();//close file
	return count;//return number of student in the file
}

void store_GradeBook(Students student, Courses course, Enrollments enrollment)//store gradebook
{
	ofstream fout1;
	fout1.open("students");
	if(fout1.fail())
	{
		cout << "Cannot open the file students" << endl;//display if fail to open the file
		exit(EXIT_FAILURE);
	}

	Student *student_list = student.get_student_list();
	Course *course_list = course.get_course_list();
	Enrollment *enrollment_list = enrollment.get_enrollment_list();

	for (int i = 0; i < student.get_student_count(); i++)
	{
		//store student's list in file students
		fout1 << student_list[i].get_ID() << "\t" << student_list[i].get_name() << "\t" << student_list[i].get_classification() << endl;
	}
	fout1.close();

	ofstream fout2;
	fout2.open("courses");
	if(fout2.fail())
	{
		cout << "Cannot open the file courses" << endl;//display if fail to open the file
		exit(EXIT_FAILURE);			
	}
	
	for ( int i = 0; i < course.get_course_count(); i++)
	{
		//store the course list in file courses
		fout2 << course_list[i].get_ID() << "\t" << course_list[i].get_name() << "\t" << course_list[i].get_location() << "\t" << course_list[i].get_meeting_time() << endl;
	}
	fout2.close();

	ofstream fout3;
	fout3.open("enrollments");
	if(fout3.fail())
	{
		cout << "Cannot open the file enrollments" << endl;//display if fail to open
		exit(EXIT_FAILURE);			
	}

	int* grade;
	for (int i = 0; i < enrollment.get_enrollment_count(); i++)
	{
		grade = enrollment_list[i].get_grade();
		//display enrollments, including enrollment ID, course ID and student ID
		fout3 << enrollment_list[i].get_enrollment_ID() << "\t" << enrollment_list[i].get_course_ID() << "\t" << enrollment_list[i].get_student_ID() << "\t" << enrollment_list[i].get_student_name() << endl;
		//display grades
		for (int z = 0; z < enrollment_list[i].get_grade_count(); z++)
		{
			fout3 << "\t" << grade[z];
		}
		fout3 << endl;
	}
	fout3.close();
	cout << "Grade Book has been stored successfully." << endl;  		
}
	
void load_GradeBook(Students* student, Courses* course, Enrollments * enrollment)
{
	int student_ID;
	string student_name;
	string course_ID;
	string course_name;
	string course_location;
	string meeting_time;
	string meeting_date;
	string AM_PM;
	int enrollment_ID;
	string enrolled_course_ID;
	string enrolled_student_name;
	int enrolled_student_ID;
	string student_classification;
	int* grade;
	int grade_count;
	string line;
	
	int student_count = 0;
	int course_count = 0;
	int enrollment_count = 0;

	ifstream fin1;
	fin1.open("students");
	if(fin1.fail())
	{
		cout << "Cannot open the file students" << endl;//display if fail to open the file
		exit(EXIT_FAILURE);
	}

	student_count = number_of_students();

	Student *student_list = new Student[student_count];

	for (int i = 0; i < student_count; i++)
	{
		//read contents in file students, including student's ID, name and classification
		fin1 >> student_ID;
		fin1.ignore();
		getline(fin1, student_name, '\t');
		getline(fin1, student_classification);

		student_list[i].set_ID(student_ID);
		student_list[i].set_name(student_name);
		student_list[i].set_classification(student_classification);
	}
	student->set_student_list(student_list);//set student's list
	student->set_student_count(student_count);
	fin1.close();

	ifstream fin2;
	fin2.open("courses");
	if(fin2.fail())
	{
		cout << "Cannot open the file courses" << endl;//display if fail to open the file
		exit(EXIT_FAILURE);
	}
	
	course_count = number_of_courses();

	Course *course_list = new Course[course_count];

	for (int i = 0; i < course_count; i++)
	{
		//read contents in file courses, including course ID, name, location and meeting time
		fin2 >> course_ID;
		fin2.ignore();

		getline(fin2, course_name, '\t');
		getline(fin2, course_location, '\t');
	
		fin2 >> meeting_time;
		fin2 >> AM_PM;
		fin2.ignore();	

		getline(fin2, meeting_date);

		course_list[i].set_ID(course_ID);
		course_list[i].set_name(course_name);
		course_list[i].set_location(course_location);
		course_list[i].set_meeting_time(meeting_time, AM_PM, meeting_date);
	}
	course->set_course_list(course_list);//set course list
	course->set_course_count(course_count);
	fin2.close();

	ifstream fin3;
	fin3.open("enrollments");
	if(fin3.fail())
	{
		cout << "Cannot open the file enrollments" << endl;//display if fail to open
		exit(EXIT_FAILURE);
	}
	
	enrollment_count = number_of_enrollments();
	Enrollment* enrollment_list = new Enrollment[enrollment_count];

	for (int i = 0; i < enrollment_count; i++)
	{
		//read the enrollment ID, course ID and student ID
		fin3 >> enrollment_ID >> enrolled_course_ID >> enrolled_student_ID;
		fin3.ignore();
		getline(fin3, enrolled_student_name);
		getline(fin3, line);//read the line containing student's grades
		istringstream is(line);
		
		grade = new int [10];
		grade_count = 0;
		while(is >> grade[grade_count])
		{
			grade_count++;//read grades
		}

		enrollment_list[i].set_enrollment_ID(enrollment_ID);
		enrollment_list[i].set_course_ID(enrolled_course_ID);
		enrollment_list[i].set_student_ID(enrolled_student_ID);
		enrollment_list[i].set_student_name(enrolled_student_name);
		enrollment_list[i].set_grade(grade);
		enrollment_list[i].set_grade_count(grade_count);
	}

	enrollment->set_enrollment_list(enrollment_list);//set enrollment list
	enrollment->set_enrollment_count(enrollment_count);

	fin3.close();
	cout << "Grade Book has been loaded" << endl;
}