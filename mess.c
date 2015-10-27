#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "minipro.h"
int printmenu3() { 
	int choice;
	printf(	"\n		1. Add a student \n"\
		"		2. Edit a student record\n"\
		"		3. Delete a student record\n"\
		"		4. Remove some records of a student\n"\
		"		5. Search for a student\n"\
		"		6. Find student status\n"\
		"		7. Calculate monthly bill of a student\n"\
		"		8. Edit attendence of a student\n"\
		"		9. Calculate no of absent days\n"\
		"		10. Calculate monthly bill of a student\n"\
		"		11. Calculation of guest bill\n"\
		"		12.Calculation of student snacks bill\n"\
		"		13.View all students\n"\
		"		14. Logout\n"\
		"		15. Exit \n");
	scanf("%d", &choice);	
	return choice;
}
int printmenu4() {
	int choice;
	printf("\n		1. See a record \n"\
		"		2. View no of absent days\n"\
		"		3. Edit a record \n"\
		"		4. Search for a student record \n"\
		"		5. Calculate the monthly bill \n"\
		"		6. Calculate the snacks bill\n"\
		"		7. Calculate guest bill\n"\
		"		8. Logout \n"\
		"		9. Exit \n");
	scanf("%d", &choice);	
	return choice;
}
int printmenu2() {
	int choice;
	printf("\n*****************************************************************\n");
	printf("                             LOGIN                              \n");
	printf("*****************************************************************\n");
	printf("			1. Administrator\n"\
		"			2. Student\n");
	printf("*****************************************************************\n");
	scanf("%d", &choice);
	return choice;
}

int printmenu1() {
	int choice;
	printf("\n*****************************************************************\n");
	printf("****************************WELCOME******************************\n");
	printf("*****************************************************************\n");
	printf("			1. LOGIN \n"\
		"			2. CREATE NEW STUDENT ID \n"\
		"*****************************************************************\n");
	scanf("%d", &choice);	
	return choice;
}
int main() {
	int choice1, choice2, choice3, choice4, ch;
	char pw[20];
	char name[20], contact[11], email[120], city[20], dist[20], pin[8], state[50]; 
	unsigned int id, rmn;
	date admdate;
	address addr1;
	FILE *ptr;
	student s;
	while(1) {
		logout:
		choice1 = printmenu1();
		switch(choice1) {
			case 1: /*Login*/
				choice2 = printmenu2();
				switch(choice2) {
					case 1: /*Admin*/
						printf("Enter password\n");
						scanf("%s", pw);
						if(strcmp(pw, "lovefood") == 0) {
							while(1) {
								choice3 = printmenu3();
								switch(choice3) {
									case 1: /*Add a student*/
										printf("Enter the name: ");
										getchar();	
										readline(name, 20);
										printf("student id: ");
										scanf("%u", &id);
										printf("Room no.: ");
										scanf("%u", &rmn);
										printf("contact no.: ");
										getchar();
										readline(contact, 11);
										printf("Email id: ");
										getchar();
										readline(email, 128);
										printf("Enter date");
										scanf("%d %d %d", &admdate.dd, &admdate.mm,&admdate.yyyy);
										printf("city: ");
										getchar();
										readline(addr1.city, 20);
										printf("District: ");
										getchar();
										readline(addr1.dist, 20);
										printf("pincode: ");
										getchar();
										readline(addr1.pin, 8);
										printf("state: ");
										getchar();
										readline(addr1.state, 50);
										addstudent(name, id, rmn, admdate, contact, email, addr1); 
										break;
									case 2: /*Edit a student record*/
										printf("Enter the student id whose record you want to edit");
										scanf("%u",&id);
										printf( "       1. Edit student details\n"
										 	"	2. Edit student address \n"
											"	3. Edit student Fee details\n");
										scanf("%d", &ch);
										switch(ch) {
											case 1: /*edit student details*/
												printf( "	1. Edit name\n"
													"	2. Edit room no.\n"
													"	3. Edit contact no\n"
													"	4. Edit email id\n");
													scanf("%d", &ch);
													//"	5. Edit date of admission\n"\
													"	6. Edit attendance\n"\);
												switch(ch){
													case 1:/*edit name*/
														printf("Enter the student name");
														getchar();
														readline(name, 20);
														editname(name, id);
														break;
													case 2:/*edit room no.*/
														printf("Enter room no.");
														scanf("%u", &rmn);
													//	editroom_no(rmn, id);
														break;
													case 3:/*edit contact no.*/
														printf("Enter contact no.");
														getchar();
														readline(contact, 11);
														editcontact(contact, id);
														break;
													case 4:/*edit email id*/
														printf("Enter email");
														getchar();
														readline(email, 128);
														editemail(email, id);
														break;
													}
													/*case 5:edit date of admission
														printf("Enter day,month and year");
														scanf("%d %d %d",&d,&m,&y);
														editadmissiondate(dt, id);
														break;
														
													case 6:edit attendance
														printf("Enter absentee or presentee");
														scanf("%c",&attendance);
														editattendance(attendance, id);
														break;
												}
												*/
											case 2:/*edit student address*/
												printf( "	1.Edit city\n"
													"	2.Edit District\n"
													"	3.Edit state\n"
													"	4.Edit pincode\n");
												scanf("%d", &ch);
												switch(ch){
													case 1:/*edit city*/
														printf("Enter city");
														getchar();
														readline(city, 20);
														editcity(city, id);
														break;
													case 2:/*edit district*/
														printf("Enter district");
														getchar();
														readline(dist, 20);
														editdistrict(dist, id);
														break;
													case 3:/*edit state*/
														printf("Enter state");
														getchar();
														readline(state, 20);
														editstate(state, 20);
														break;
													case 4:/*edit pincode*/
														printf("Enter pincode");
														getchar();
														readline(pin, 10);
														editpincode(pin, id);
														break;
												}
											}
										}
									}	 					
								}						
							}						 
													
						}								
					}					
				}
