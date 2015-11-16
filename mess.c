/*****************************************************************************
 * Copyright (C) Bharati yun 2015 yunbharati@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/* This file contains the code for main() function, the main logic of the code */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "minipro.h"
int printmenu3() { 
	int choice;
	printf(	"\n		1. Add a student \n"\
		"		2. Edit a student record\n"\
		"		3. Search for a student\n"\
		"		4. Mark attendance\n"\
		"		5. Mark presentee\n"\
		"		6. Edit attendence of a student\n"\
		"		7. Calculate monthly bill\n"\
		"		8. view student\n"		
		"		9. Logout\n"\
		"		10. Exit \n");
	scanf("%d", &choice);	
	return (choice);
}
int printmenu4() {
	int choice;
	printf("\n		1. view student \n"\
		"		2. View no of absent days\n"\
		"		3. Logout \n"\
		"		4. Exit \n");
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
	char name[20], contact[11], e_mail[120], city[20], dist[20], pin[10], state[30], admdate[20];
	int attendance[12][31], p = 0, a = 0, b = 0, charge = 0, n = 0; 
	unsigned int id, rmn, mnth, dt;
//	date admdate;
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
						if(strcmp(pw, "lovefood") == 0){
							while(1) {
								choice3 = printmenu3();
								//printf("choice3 is %d", choice3);
								switch(choice3) {
									case 1: /*Add a student*/
										printf("Enter name: ");
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
										readline(e_mail, 128);
										printf("Enter date of admission: ");
										getchar();
										readline(admdate, 20);
										//scanf("%d %d %d", &admdate.dd, &admdate.mm,&admdate.yyyy);
										printf("city: ");
										getchar();
										readline(addr1.city, 20);
										printf("District: ");
										getchar();
										readline(addr1.dist, 20);
										printf("pincode: ");
										getchar();
										readline(addr1.pin, 10);
										printf("state: ");
										getchar();
										readline(addr1.state, 30);
										addstudent(name, id, rmn, admdate, contact, e_mail, addr1); 
										break;
									case 2: /*Edit a student record*/
										printf("Enter the student id whose record you want to edit: ");
										scanf("%u",&id);
										printf( "       1. Edit student details\n"
										 	"	2. Edit student address \n");
											//"	3. Edit student Fee details\n");
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
														printf("Enter the student name: ");
														getchar();
														readline(name, 20);
														printf("ABC");
														editname(name, id);
														break;
													case 2:/*edit room no.*/
														printf("Enter room no.: ");
														scanf("%u", &rmn);
														editroom_no(rmn, id);
														break;

													case 3:/*edit contact no.*/
														printf("Enter contact no.: ");
														getchar();
														readline(contact, 11);
														editcontact(contact, id);
														break;
													case 4:/*edit email id*/
														printf("Enter email: ");
														getchar();
														readline(e_mail, 128);
														editemail(e_mail, id);
														break;
													default: 
														printf("Invalid entry");
												
													}
												break;
												//}
												
												
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
														printf("Enter city: ");
														getchar();
														readline(city, 20);
														editcity(city, id);
														break;
													case 2:/*edit district*/
														printf("Enter district: ");
														getchar();
														readline(dist, 20);
														editdistrict(dist, id);
														break;
													case 3:/*edit state*/
														printf("Enter state: ");
														getchar();
														readline(state, 20);
														editstate(state, 20);
														break;
													case 4:/*edit pincode*/
														printf("Enter pincode: ");
														getchar();
														readline(pin, 10);
														editpincode(pin, id);
														break;
													default:
														printf("Invalid entry");
												}
											break;
											}
										break;
									case 3: /* search for a student */
										printf( "	1.search by ID\n"
											"	2.search by contact\n"
											"	3.search by email\n");
										scanf("%d", &ch);
										switch(ch){
											case 1:/*search by ID*/
												printf("Enter ID: \n");
												scanf("%u", &id);
												searchbyid(id);
												break;
											case 2:/*search by contact*/
												printf("Enter contact: \n");
												scanf("%s", contact);
												searchbycontact(contact);
												break;
											case 3:/*search by email*/
												printf("Enter email: \n");
												scanf("%s", e_mail);
												searchbyemail(e_mail);
												break;
											default:
												printf("Invalid entry");
												break;
											}
										break;
									case 4: /* mark attendance (initialising attendance to zero)*/
										printf("ID of the student: ");
										scanf("%u", &id);
										printf("month: ");
										scanf("%u", &mnth);
										markattendance(id, mnth);
										printf("	All attendance successfully marked to zero\n");
										break;
										
									case 5: /* mark presentee */
										printf("Enter the student ID: ");
										scanf("%u", &id);
										printf("Enter month in number: ");
										scanf("%u", &mnth);
										printf("date:");
										scanf("%u", &dt);
										markpresentee(id, mnth, dt);
										printf("	Presentee successfully marked\n");
										break;
										
									case 6:/* Edit attendance */
										printf("Enter the student ID: ");
										scanf("%u", &id);
										printf("Edit attendance of month: ");
										scanf("%u", &mnth);
										printf("Edit attendance of date: ");
										scanf("%u", &dt);
										editattendance(mnth, dt, id);
										printf("	Attendance edited successfully\n");
										break;
										
									case 7:/*calculate monthly bill*/
										printf("Enter the student ID: ");
										scanf("%u", &id);
										printf("Enter the month: ");
										scanf("%u", &mnth); 
										printf("Charge per meal: ");
										scanf("%d", &charge);
										printf("No of meals per day: ");
										scanf("%d", &n);
										p = 0;
										p = calpresentdays(id, mnth);
										printf("No of present days is %d\n", p);
										b = calmonthlybill(p, charge, n);
										printf("	Monthly bill is %d	", b);
										break;
										
									case 8:/*view student*/
										printf("Enter the student ID: ");
										scanf("%u", &id);
										viewstudent(id);
										break;
										
									case 9:/*Logout*/
										 goto logout;
										 break;
										 
									case 10: /*exit */
										return;
										
									default:
									 	("Invalid entry");
										break;				
			
										}
									}
								}
							else {
							printf("			WRONG PASSWORD\n");
							break;
							}
						case 2:/*student*/
							printf("	Enter your ID		");
							scanf("%u", &id);
							ptr = fopen("students", "a+");
							if(ptr == NULL) {
								printf("Operation failed. Try again.\n");
								break;
							}
							while(fread(&s, sizeof(s), 1, ptr) == 1) {
								if(id == s.id && s.id != 0) {
									printf("\n	ID	: %u\n"\
										"	Name	: %s\n"\
										"	Contact	: %s\n", s.id, s.name, s.contact);
									while(1) {
										choice4 = printmenu4();
										switch(choice4) {
											case 1: /*view student*/
												printf("Enter the student ID: ");
												scanf("%u", &id);
												viewstudent(id);
												break;
											case 2: /*view no. of absent days*/
												printf("Enter the student ID: ");
												scanf("%u", &id);
												printf("Month: ");
												scanf("%u", &mnth);
												a = calabsentdays(id, mnth);
												printf("Number of absent days is %d", a);
												break;
											case 3:/*Logout*/
												goto logout;
										 		break;
										 
											case 4: /*exit */
												exit(0);
												break;
										
											default: 
												printf("Invalid entry");
												break;	
										}
									}
								}
								
							}
							break;
							fclose(ptr);
								printf("	Invalid ID. Register your ID first.	");
						break;
						}
						
					case 2:/*create	new student id*/
						printf("           Enter your Name		");
						getchar();	
						readline(name, 20);
						printf("           Enter your contact no	");
						readline(contact, 11);
						printf("           Enter your ID no		");
						scanf("%u", &id);
						break;
						
					default:
						printf("Invalid entry");
						break;
					}
				}
			return 0;
		}	
						
