main: main.o Student.o Students.o Course.o Courses.o Enrollment.o Enrollments.o
	g++ main.o Student.o Students.o Course.o Courses.o Enrollment.o Enrollments.o -o main

main.o: main.cpp Student.h Students.h Course.h Courses.h Enrollment.h Enrollments.h
	g++ -c main.cpp

Student.o: Student.cpp Student.h Students.h Course.h Courses.h Enrollment.h Enrollments.h
	g++ -c Student.cpp

Students.o: Students.cpp Student.h Students.h Course.h Courses.h Enrollment.h Enrollments.h
	g++ -c Students.cpp

Course.o: Course.cpp Student.h Students.h Course.h Courses.h Enrollment.h Enrollments.h
	g++ -c Course.cpp

Courses.o: Courses.cpp Student.h Students.h Course.h Courses.h Enrollment.h Enrollments.h
	g++ -c Courses.cpp

Enrollment.o: Enrollment.cpp Student.h Students.h Course.h Courses.h Enrollment.h Enrollments.h
	g++ -c Enrollment.cpp

Enrollments.o: Enrollments.cpp Student.h Students.h Course.h Courses.h Enrollment.h Enrollments.h
	g++ -c Enrollments.cpp

clean:
	rm *.o main