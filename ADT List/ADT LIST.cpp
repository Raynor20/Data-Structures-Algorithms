#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char fName[20];
	char lName[20];
}studName;

typedef struct {
	int month;
	int year;
}bday;

typedef struct {
	studName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct {
	studentInfo studList[20];
	int studcount;
}classRecord;

void insertFirst(classRecord * CR, studentInfo stud){
	if (CR->studcount < 20) {
		for (int i = CR->studcount; i > 0; i--) {
			CR->studList[i] = CR->studList[i - 1];
		}
		CR->studList[0] = stud;
		CR->studcount++;
	}	
}
void insertLast(classRecord * CR, studentInfo stud){
	if(CR->studcount < 20){
			CR->studList[CR->studcount++] = stud;
		}
}
void insertAt(classRecord *CR, studentInfo stud, int pos){
	if(CR->studcount <20 && pos <= CR->studcount && pos >= 0) {
		for(int i = CR->studcount; i > pos; i--) {
			CR->studList[i] = CR->studList[i - 1];
		}
		CR->studList[pos] = stud;
		CR->studcount++;
	}
}
void insertSorted(classRecord *CR, studentInfo stud) {
        int i;
        for (i = CR->studcount - 1; (i >= 0 && CR->studList[i].age > stud.age); i--) {
            CR->studList[i + 1] = CR->studList[i];
        }
        CR->studList[i + 1] = stud;
        CR->studcount++;		
}
void delFirst(classRecord * CR){
	if (CR->studcount > 0) {
		for (int i = 0; i < CR->studcount-1; i++){
			CR->studList[i] = CR->studList[i+1];
		}
		CR->studcount--;
	}
	
}
void delLast(classRecord * CR){
	if(CR->studcount > 0){
		CR->studcount--;
	}
}
void display(classRecord * CR) {
    for (int i = 0; i < CR->studcount; i++) {
        printf("Student %d:\n", i + 1);
        printf("First Name: %s\n", CR->studList[i].name.fName);
        printf("Last Name: %s\n", CR->studList[i].name.lName);
        printf("Birth Month: %d\n", CR->studList[i].birthdate.month);
        printf("Birth Year: %d\n", CR->studList[i].birthdate.year);
        printf("Age: %d\n", CR->studList[i].age);
        printf("ID Number: %d\n\n", CR->studList[i].idNum);
    }
}

int main() {
	classRecord CR;
    studentInfo stud;
    int pos;
    int i, recs;
    printf("Input how many student records: ");
    scanf("%d", &recs);
    
    for(i=0; i<recs; i++);
    //Insert a student at the first position
    printf("Inserting student at the first position:\n");
    printf("Student First Name: ");
    scanf("%s", stud.name.fName);
    printf("Student Last Name: ");
    scanf("%s", stud.name.lName);
    printf("Student Birth Month: ");
    scanf("%d", &stud.birthdate.month);
    printf("Student Birth Year: ");
    scanf("%d", &stud.birthdate.year);
    printf("Student Age: ");
    scanf("%d", &stud.age);
    printf("Student ID Number: ");
    scanf("%d", &stud.idNum);
    insertFirst(&CR, stud);

    // Insert a student at the last position
    printf("Inserting student at the last position:\n");
    printf("Student First Name: ");
    scanf("%s", stud.name.fName);
    printf("Student Last Name: ");
    scanf("%s", stud.name.lName);
    printf("Student Birth Month: ");
    scanf("%d", &stud.birthdate.month);
    printf("Student Birth Year: ");
    scanf("%d", &stud.birthdate.year);
    printf("Student Age: ");
    scanf("%d", &stud.age);
    printf("Student ID Number: ");
    scanf("%d", &stud.idNum);
    insertLast(&CR, stud);
    
    //Insert a student at a specific position
    printf("Inserting student at a specific position:\n");
    printf("Student First Name: ");
    scanf("%s", stud.name.fName);
    printf("Student Last Name: ");
    scanf("%s", stud.name.lName);
    printf("Student Birth Month: ");
    scanf("%d", &stud.birthdate.month);
    printf("Student Birth Year: ");
    scanf("%d", &stud.birthdate.year);
    printf("Student Age: ");
    scanf("%d", &stud.age);
    printf("Student ID Number: ");
    scanf("%d", &stud.idNum);
    printf("Position to insert (0 first index): ");
    scanf("%d", &pos);
    insertAt(&CR, stud, pos);
    
    
    //Display the class record
    printf("\nClass Record:\n");
    //insertSorted(&CR, stud);
    display(&CR);
    
    
    /*
    //Delete the first student
    printf("\nDeleting the first student:\n");
    delFirst(&CR);
    display(&CR);
    
    //Delete the last student
    printf("\nDeleting the last student:\n");
    delLast(&CR);
    display(&CR);
    */
    return 0;
}
