#define _STUDENTS
int i , maxSize ;
extern int i ;
extern int maxSize ;
typedef struct CGPA{
	float data ;
}key;

typedef struct student{
	char* studentName ;
	key  k ;
}element;

element* readFileAndStore(char* filename);
void printStudents(element* students, int size,char* fileName);
void readLargeAndSort(char* filename);
void mergeFiles(char* file1, char* file2 , char* outputFile);
void sort(char* fName);
