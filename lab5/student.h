#define _STUDENTS
typedef struct CGPA{
	float data ;
}key;

typedef struct student{
	char* studentName ;
	key  k ;
}element;

element* readFileAndStore(char* filename , int noOfRecords);
void printStudents(element* students , int size);
