#define MAX_COURSES 100
#define MAX_STUDENTS 1000
#define MAX_HALLS 50
#define MAX_DATE_LENGTH 20
#define MAX_CODE_LENGTH 10

// Define structures for storing data
typedef struct {
    char code[MAX_CODE_LENGTH];
    char date[MAX_DATE_LENGTH];
    char hall[MAX_HALLS];
} Exam;

typedef struct {
    int id;
    char courses[MAX_COURSES][MAX_CODE_LENGTH];
    int numCourses;
} Student;

// Function prototypes
void readCourses(Exam *exams, int *numExams);
void readStudents(Student *students, int *numStudents);
int findMinStudentID(Student *students, int numStudents);
void printNumberStudents(int numStudents);
void printNumberHalls(int numExams);
void printMinStudentID(int minID);
void printDroppedIDs(Student *students, int numStudents);
void printExamsPeriod(Exam *exams, int numExams);
void printCourseStudents(Student *students, int numStudents, char *courseCode);
void printCoursesMoreThanN(Student *students, int numStudents, int n);
void printStudentsLessThanN(Student *students, int numStudents, int n);
void printHallStudents(Exam *exams, Student *students, int numExams, int numStudents, char *hall, char *date);
void printHallStudentsInAnyDay(Exam *exams, Student *students, int numExams, int numStudents, char *hall);

int main() {
    Exam exams[MAX_COURSES];
    Student students[MAX_STUDENTS];

    int numExams = 0;
    int numStudents = 0;

    readCourses(exams, &numExams);
    readStudents(students, &numStudents);

    char operation[30];

    while (1) {
        printf("Enter operation: ");
        fgets(operation, sizeof(operation), stdin);

        if (strncmp(operation, "Number_Students", 15) == 0) {
            printNumberStudents(numStudents);
        } else if (strncmp(operation, "Number_Halls", 12) == 0) {
            printNumberHalls(numExams);
        } else if (strncmp(operation, "Student_ID_Min", 15) == 0) {
            int minID = findMinStudentID(students, numStudents);
            printMinStudentID(minID);
        }
        // Add other operations here...

        else if (strncmp(operation, "Quit", 4) == 0) {
            break;
        } else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}

// Implement the functions based on the specifications
// ...

