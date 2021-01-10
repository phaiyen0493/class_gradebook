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


Enrollments::Enrollments()
{
	enrollment_count = 0;
	enrollment_capacity = CHUNKSIZE;		
	enrollment_list = new Enrollment [enrollment_capacity];
}

void Enrollments:: add_enrollment(Students student, Courses course)//add enrollment
{
	int student_ID;
	string course_ID;
	int enrollment_ID;
	int enrollment_count_per_course = 0;
	int course_per_student_count;
	int course_count = course.get_course_count();
	int student_count = student.get_student_count();

	bool found_student;
	bool found_course;
	bool ID_check;
	bool found_enrollment;
	char answer = 'y';

	Student *student_list = student.get_student_list();
	Course *course_list = course.get_course_list();

	//prompt user to enter course ID
	cout << "Enter course's ID: ";
	cin >> course_ID;
	
	//resize array to make sure it starts with CHUNKSIZE
	if (enrollment_count < enrollment_capacity)
	{
		Enrollment *temp = new Enrollment [enrollment_capacity];
		for (int i = 0; i < enrollment_count; i++)
		{
			temp[i] = enrollment_list[i];
		}
		delete [] enrollment_list;
		enrollment_list = temp;
	}

	for(int i = 0; i < course_count; i++)
	{
		found_course = false;
		if (course_ID == course_list[i].get_ID())
		{
			found_course = true;

			while (answer == 'y')
			{
				//count how many enrollments have been in a course
				for (int h = 0; h < enrollment_count; h++)
				{
					if(course_ID == enrollment_list[h].get_course_ID())
					{
						enrollment_count_per_course++;
					}
				}
				
				//display if course have 48 enrollment already
				if (enrollment_count_per_course >= 48)
				{
					answer = 'n';
					cout << "This course has reached the maximum of 48 student enrollments." << endl; 
					break;
				}
				
				else
				{
					enrollment_list[enrollment_count].set_course_ID(course_ID);
					found_student = false;
					//prompt user to enter student's ID
					cout << "Enter student's ID: ";
					cin >> student_ID;
				
					for (int z = 0; z < student_count; z++)
					{
						if (student_ID == student_list[z].get_ID())//execute if student's ID is found in the student list
						{
							found_student = true;
							ID_check = false;
						
							for (int n = 0; n < enrollment_count; n++)
							{
								//execute if course ID and student ID is found in the enrollment list
								if( course_ID == enrollment_list[n].get_course_ID() && student_ID == enrollment_list[n].get_student_ID())
								{
									ID_check = true;
									cout << "This student has already been added to this course. Please add another student." << endl;
									cout << "Continue to add another student for this course? y/n:";
									cin >> answer;
								}
							}

							if (ID_check == false)
							{
								enrollment_list[enrollment_count].set_student_ID(student_ID);
								enrollment_list[enrollment_count].set_student_name(student_list[z].get_name());
								course_per_student_count = 0;
	
								//count how many courses a student have been taken
								for (int g = 0; g < enrollment_count; g++)
								{
									if( student_ID == enrollment_list[g].get_student_ID())
									{
										course_per_student_count++;
									}
								}
									
								//continue if student has not taken 5 courses yet and user wants to continue to add student in the course
								if (course_per_student_count < 5)
								{
									cout << "Enter enrollment's ID: ";
									cin >> enrollment_ID;
									//resize if enrollment count reach enrollment capacity
									if (enrollment_count >= enrollment_capacity)
									{
										enrollment_capacity += CHUNKSIZE;
										Enrollment *temp = new Enrollment[enrollment_capacity];
										for (int g = 0; g < enrollment_count; g++)
										{
											temp[g] = enrollment_list[g];
										}
										delete [] enrollment_list;
										enrollment_list = temp;
									}

									found_enrollment = false;
									//check if enrollment ID has been used for another student	
									for (int m = 0; m < enrollment_count; m++)
									{
										if (enrollment_ID == enrollment_list[m].get_enrollment_ID())
										{
											found_enrollment = true;
											cout << "Error! This enrollment ID was already used for another student's enrollment." << endl;
											cout << "Continue to add another student for this course? y/n: ";
											cin >> answer;
										}
									}							
									
									//add student if input enrollment ID has not been used for other students yet
									if (found_enrollment == false)
									{
										enrollment_list[enrollment_count].set_enrollment_ID(enrollment_ID);
										enrollment_count++;//increment by 1 when adding enrollment successfully
										cout << "New enrollment has been added successfully." << endl;

										//sort enrollment list by course ID
										for (int h = 0; h < (enrollment_count-1); h++)
										{
											for (int j = h+1; j < enrollment_count; j++)
											{
												if (enrollment_list[h].get_course_ID() > enrollment_list[j].get_course_ID())		
												{
													Enrollment temp;
													temp = enrollment_list[h];
													enrollment_list[h] = enrollment_list[j];
													enrollment_list[j] = temp;
												}
											}
										}

										//continue to sort enrollment list by enrollment ID after enrollments are grouped and sorted by course
										for (int h = 0; h < (enrollment_count-1); h++)
										{
											for (int j = h+1; j < enrollment_count; j++)
											{
												if (enrollment_list[h].get_course_ID() == enrollment_list[j].get_course_ID())		
												{
													if(enrollment_list[h].get_enrollment_ID() > enrollment_list[j].get_enrollment_ID())
													{
														Enrollment temp;
														temp = enrollment_list[h];
														enrollment_list[h] = enrollment_list[j];
														enrollment_list[j] = temp;
													}
												}
											}
										}	
 
										cout << "Continue to add another student for this course? y/n: ";//prompt user to add more students for a course
										cin >> answer;
									}
								}
								else
								{
									answer = 'n';
									cout << "This student has already taken 5 courses and cannot add more course." << endl;//display if student has been taken 5 courses and wants to take more course
									break;
								}
							}
							break;
						}
					}
				}

				if (found_student == false)
				{
					//display if input student's ID cannot be found
					cout << "This student's ID does not match any one in the database. Please add this student before taking enrollment." << endl;
					cout << "Continue to add student for this course? y/n: ";
					cin >> answer;
				}
			}
			break;
		}
	}

	if (found_course == false)
	{
		//display if entered course ID does not match any in the database 
		cout << "This course's ID does not match any one in the database. Please add this class before taking enrollment." << endl;
	}
}
	

void Enrollments::print_enrollment() //print enrollment list by course
{
	string ID;
	bool found_course = false;
	cout << "Enter course's ID: ";
	cin >> ID;

	for (int i = 0; i < enrollment_count; i++)
	{
		if (ID == enrollment_list[i].get_course_ID()) //execute if course is found
		{
			found_course = true;
			cout << "Student ID: " << enrollment_list[i].get_student_ID() << right << setw(30) << "Name: " << enrollment_list[i].get_student_name() << right << setw(25) << "Enrollment ID: " << enrollment_list[i].get_enrollment_ID() << endl;
		}
	}

	if (found_course == false)
	{
		cout << "No enrollment was added to this course. Please add enrollment first." << endl;
	}
}

void Enrollments:: add_grade()
{
	int student_ID;
	string course_ID;
	int* new_grade = new int [10];
	int grade_count;	
	bool found = false;
	int num;
	char answer;
	
	//prompt user to enter student's ID
	cout << "Enter student's ID: ";
	cin >> student_ID;
	//prompt user to enter course's ID
	cout << "Enter course's ID: ";
	cin >> course_ID;

	for (int i = 0; i < enrollment_count; i++)
	{
		//check if input student Id and course ID matches ones in the enrollment
		if (student_ID == enrollment_list[i].get_student_ID() && course_ID == enrollment_list[i].get_course_ID())
		{
			found = true;
			do
			{
				num = 0;
				grade_count = enrollment_list[i].get_grade_count();
				if (grade_count > 0) //check if grade count of any enrollment is larger than 0
				{	
					for (int n = 0; n < enrollment_list[i].get_grade_count(); n++)
					{
						new_grade[n] = enrollment_list[i].get_grade()[n]; //copy elements from the grade list to a new grade list
					}
				}

				cout << "Grade #" << enrollment_list[i].get_grade_count() + 1 << ": "; //prompt user to add new grade
				cin >> new_grade[enrollment_list[i].get_grade_count()];
				num++;
				enrollment_list[i].set_grade_count(grade_count+num);//set new grade count
				enrollment_list[i].set_grade(new_grade);//set new grade list

				cout << "Add more grade? y/n: ";//prompt user to continue to add grade
				cin >> answer;

			} while (enrollment_list[i].get_grade_count() < 10 && answer == 'y');

			//check if user has added 10 grades or not
			if (enrollment_list[i].get_grade_count() >= 10)
			{
				cout << "Cannot enter more than 10 grades for a student in a course" << endl;
			}
			break;
		}
	}

	if (found == false)
	{
		cout << "This student's ID is not in the database or did not enter this course. Please add enrollment first before adding grades." << endl;
	}
}

void Enrollments:: compute_student_average() //calculate student's average
{
	int student_ID;
	string course_ID;
	int sum = 0;
	int *grade = new int [10];
	float student_average = 0;
	bool found = false;
	char letter_grade;

	//prompt user to enter student's ID
	cout << "Enter student's ID: ";
	cin >> student_ID;
	//prompt user to enter course's ID
	cout << "Enter course's ID: ";
	cin >> course_ID;

	for (int i = 0; i < enrollment_count; i++)
	{
		if (student_ID == enrollment_list[i].get_student_ID() && course_ID == enrollment_list[i].get_course_ID())
		{
			found = true;
			grade = enrollment_list[i].get_grade();
			//check if entered course ID and student ID match any in the enrollment list
			if (enrollment_list[i].get_grade_count() > 0 && enrollment_list[i].get_grade_count() <= 10)
			{	
				for (int z = 0; z < enrollment_list[i].get_grade_count(); z++)
				{
					sum += grade[z];//add up all grades of a student in a course
				}
				student_average = (float) sum/ enrollment_list[i].get_grade_count();//calculate the average
				enrollment_list[i].set_student_average(student_average);//set the average

				//print student's average
				cout << "Student's average in course " << enrollment_list[i].get_course_ID() << " is: " << fixed << setprecision(2) << enrollment_list[i].get_student_average() << endl;
				if (student_average >= 90)
				{	
					letter_grade = 'A';
					cout << "Letter grade: " << letter_grade << endl;
					enrollment_list[i].set_letter_grade(letter_grade);
				}

				else if (student_average >= 80)
				{
					letter_grade = 'B';
					cout << "Letter grade: " << letter_grade << endl;
					enrollment_list[i].set_letter_grade(letter_grade);

				}

				else if (student_average > 70)
				{
					letter_grade = 'C';
					cout << "Letter grade: " << letter_grade << endl;
					enrollment_list[i].set_letter_grade(letter_grade);
				}

				else
				{
					letter_grade = 'F';
					cout << "Letter grade: " << letter_grade << endl;
					enrollment_list[i].set_letter_grade(letter_grade);
				}

				break;
			}

			else
			{
				cout << "This student does not have any grade entered in the database yet. Please add grades for this student before computing the average" << endl;
			}
		}
	}

	if (found == false)
	{
		cout << "This student's ID is not in the database or did not enter this course. Please add enrollment first before adding grades." << endl;
	}
}

void Enrollments:: print_grade()
{
	int student_ID;
	int *grade = new int [10];
	string course_ID;
	bool found = false;

	//prompt user to enter student's ID
	cout << "Enter student's ID: ";
	cin >> student_ID;
	//prompt user to enter course's ID
	cout << "Enter course's ID: ";
	cin >> course_ID;

	for (int i = 0; i < enrollment_count; i++)
	{
		if (student_ID == enrollment_list[i].get_student_ID() && course_ID == enrollment_list[i].get_course_ID())
		{
			found = true;
			grade = enrollment_list[i].get_grade();
			//check if user's inputs match with ones in the enrollment list
			if (enrollment_list[i].get_grade_count() > 0 && enrollment_list[i].get_grade_count() <= 10)
			{
				for (int z = 0; z < enrollment_list[i].get_grade_count(); z++)
				{
					cout << "Grade #" << z+1 << ": " << grade[z] << endl;//display grades
				}
			}
			else
			{
				cout << "This student has not got any grade yet." << endl;//display if student has not been entered grades to display the average
			}
		}
	}

	if (found == false)
	{
		//display if user's inputs do not macth with the enrollment list database
		cout << "This student's ID is not in the database or did not enter this course. Please add enrollment first before adding grades." << endl;
	}
}

void Enrollments:: compute_course_average()
{
	string course_ID;
	int course_student_count = 0;
	float sum = 0;
	float course_average = 0;
	bool found_course = false;
	bool found_grade = false;

	cout << "Enter course's ID: ";//prompt user to enter course's ID
	cin >> course_ID;

	for (int i = 0; i < enrollment_count; i++)
	{
		if (course_ID == enrollment_list[i].get_course_ID())
		{
			found_course = true;
			if(enrollment_list[i].get_grade_count() > 0)
			{
				found_grade = true;
				course_student_count++;
				sum += enrollment_list[i].get_student_average();//add up all the computed student's averages
			}
		}
	}
	
	if (found_course == false)
	{
		cout << "This course ID is not in the enrollment's list. Please add enrollment first, then add students' grades before computing course's average." << endl;
	}

	if (found_course == true && found_grade == false)
	{
		cout << "No student's grades have been entered for this course yet. Please enter students' grades then try again." << endl; 
	}

	else
	{
		course_average = (float) (sum / course_student_count);//calculate the course average
		cout << "Course's average: " << fixed << setprecision(2) << course_average << endl;//display course average
		if (course_average == 0)
		{
			cout << "Grades may have not been added or not all student's averages have been computed. Please do these steps before computing course's average" << endl;
		}
	}
}

void Enrollments:: set_enrollment_count(int num)
{
	enrollment_count = num;
}

int Enrollments:: get_enrollment_count()
{
	return enrollment_count;
}

void Enrollments:: set_enrollment_list(Enrollment* enrollment_list)
{
	this -> enrollment_list = enrollment_list;
}

Enrollment* Enrollments:: get_enrollment_list()
{
	return enrollment_list;
}
