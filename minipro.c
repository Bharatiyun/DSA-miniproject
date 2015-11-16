#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include "minipro.h"
 void addstudent(char *name, unsigned int id, unsigned int room_no, char *admdate, char *contact, char *e_mail, address addr){
 	FILE *ptr;
	student s;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed. Try again.\n");
		return;
	}
		strcpy(s.name, name);
		strcpy(s.contact, contact);
		strcpy(s.e_mail, e_mail);
		strcpy(s.addr.city, addr.city);
		strcpy(s.addr.dist, addr.dist);
		strcpy(s.addr.pin, addr.pin);
		strcpy(s.addr.state, addr.state);
		s.id = id;
		s.room_no = room_no;
		strcpy(s.admdate, admdate);
		ptr = fopen("students", "a");
		if(ptr == NULL) {
			printf("	Operation failed. Try again.\n");
			return;
		}
		fwrite(&s, sizeof(s), 1, ptr);
		fclose(ptr);
	}
void viewstudents() {
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	No student has registered yet.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		flag = 1;
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n\n", s.id, s.name, s.contact);
	}
	if(flag == 0)
		printf("	No student has registered yet.\n");
	fclose(ptr);
}
void editname(char *name, unsigned int id) {
	printf("kol");
	FILE *ptr;
	student s;
	int flag = 0, count = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		count++;
		if(id == s.id) {
			flag = 1;
			strcpy(s.name, name);
			break;
		}
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n", s.id, s.name, s.contact);
			
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
/* To edit contact of a student */
void editcontact( char *contact, unsigned int id) {
	FILE *ptr;
	student s;
	int flag = 0,count= 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		count++;
		if(id == s.id) {
			flag = 1;
			strcpy(s.contact, contact);
			break;
		}
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n\n", s.id, s.name, s.contact);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}

/*To edit room number*/
 void editroom_no( unsigned int room_no, unsigned int id)
{
	FILE *ptr;
	student s;
	int flag = 0,count= 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		count++;
		if(id == s.id) {
			flag = 1;
			s.room_no = room_no;
			break;
		}
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	room no.	: %u\n"
			"	Contact		: %s\n", s.id, s.name, s.room_no, s.contact);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
/*To edit city*/
void editcity(char *city,unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)) {
		count++;
		if(id == s.id)
			flag = 1;
			strcpy(s.addr.city,city);
			break;
		}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n"
			"	city		: %s\n",s.id, s.name, s.contact, s.addr.city);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
void editdistrict(char *dist, unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(id==s.id){
			flag = 1;
			strcpy(s.addr.dist, dist);
			break;
		}
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n"
			"	city		: %s\n"
			"	District	: %s\n",s.id, s.name, s.contact, s.addr.city, s.addr.dist);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}

/*To edit state*/
void editstate(char *state, unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(id == s.id){
			flag = 1;
			strcpy(s.addr.state, state);
			break;
		}
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n"
			"	city		: %s\n"
			"	District	: %s\n"
			"	state		: %s\n",s.id, s.name, s.contact, s.addr.city, s.addr.dist, s.addr.state);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}

/*To edit pincode*/
void editpincode(char *pin, unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(id == s.id)
			flag = 1;
			strcpy(s.addr.pin, pin);
			break;
		}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
	fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n"
			"	city		: %s\n"
			"	District	: %s\n"
			"	pin		: %s\n",s.id, s.name, s.contact, s.addr.city, s.addr.dist, s.addr.pin);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
void editemail(char *e_mail, unsigned int id) {
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(id == s.id){
			flag = 1;
			strcpy(s.e_mail, e_mail);
		}
		//break;
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
	fseek(ptr, 0 , 0);
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact		: %s\n"
			"	e_mail		: %s\n", s.id, s.name, s.contact, s.e_mail);
			//"	city		: %s\n"
			//"	District	: %s\n"
			//"	pin		: %s\n",s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.dist, s.addr.pin);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}

/*
void searchbyname(char *name)
{	printf("love\n");
	printf("name is %s\n", name);
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		printf("name in while loop is %s\n", s.name);
		if(strcasecmp(name, s.name) == 0) {
			printf("we");
			printf("name in if is %s\n", name);
			flag = 1;
			printf("	id		: %u\n"
				"	name		: %s\n"
				"	contact		: %s\n"
				"	e_mail		: %s\n"
				"	city		: %s\n"
				"	state		: %s\n", s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.state);
		}
		break;
	}
	if(flag == 0)
		printf("	name doesn't exist\n");
	fclose(ptr);
	return;
}*/

/*To search by ID*/
void searchbyid(unsigned int id)
{
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(id == s.id) {
			flag = 1;
			printf("	id		: %u\n"
				"	name		: %s\n"
				"	contact		: %s\n"
				"	e_mail		: %s\n"
				"	city		: %s\n"
				"	state		: %s\n", s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.state);
			break;
		}
		//break;
	}
	if(flag == 0)
		printf("	name doesn't exist\n");
	fclose(ptr);
}

/*To search by contact*/
void searchbycontact(char *contact)
{
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(strcasecmp(contact, s.contact) == 0) {
			flag = 1;
			printf("	id		: %u\n"
				"	name		: %s\n"
				"	contact		: %s\n"
				"	e_mail		: %s\n"
				"	city		: %s\n"
				"	state		: %s\n", s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.state);
			break;
		}
		//break;
	}
	if(flag == 0)
		printf("	name doesn't exist\n");
	fclose(ptr);
}

/*To search by email*/
void searchbyemail(char *e_mail)
{
	printf("lol\n");
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(strcasecmp(e_mail, s.e_mail) == 0) {
			flag = 1;
			printf("	id		: %u\n"
				"	name		: %s\n"
				"	contact		: %s\n"
				"	e_mail		: %s\n"
				"	city		: %s\n"
				"	state		: %s\n", s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.state);
		break;
		}
		//break;
	}
	if(flag == 0)
		printf("	name doesn't exist\n");
	fclose(ptr);
}

 void readline(char *str, int n) {
	int i = 0;
	char ch;
	while((i < (n - 1)) && ((ch = getchar()) != '\n') && (ch != EOF)) {
		str[i] = ch;
		i++;	
	}
	str[i] = '\0';
} 

/*To mark presentee*/
 void markpresentee(unsigned int id, int mnth, int dt)
 {
 	FILE *ptr;
	student s;
	int flag = 0, count = 0;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(id == s.id) {
			flag = 1;
 			s.attendance[mnth][dt] = 1;
			break;
 		}
 	}
 	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
	}
	fseek(ptr, 0 , 0);
	
}
/* To mark attendance */
void markattendance(unsigned int id, unsigned int mnth)
{ 	
	FILE *ptr;
	student s;
	//int *p, *q;
	int flag = 0, count = 0, j;
	ptr = fopen("students", "a+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(id == s.id) {
		flag = 1;
		//	for(i = 0; i < 12; i++){
				for(j = 0; j < 31; j++){
					s.attendance[mnth][j] = 0;				
				}
			break;
		}
		//break;
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		printf("HEYO\n");
		}
	fseek(ptr, 0 , 0);
}

/*To edit attendance*/
 void editattendance(unsigned int mnth, unsigned int dt, unsigned int id)
 {	
 	FILE *ptr;
 	student s;
 	int flag = 0;
 	int count = 0;
 	ptr = fopen("students", "a+");
 	if(ptr == NULL){
 		printf("operation failed");
 		return;
 	}	
 	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(id == s.id) {
			flag = 1;
 				
 			if(s.attendance[mnth][dt] == 1){
 				s.attendance[mnth][dt] = 0;
 			}
 			s.attendance[mnth][dt] = 1;
			break;
 		}
	}
 	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	else {
		fseek(ptr, (count - 1) * sizeof(s), 0);		/* file pointer is taken to the position where edited record is to be written*/
		fwrite(&s, sizeof(s), 1, ptr);
		}
		fseek(ptr, 0 , 0);
}

/*To calculate present days*/
int calpresentdays(unsigned int id, unsigned int mnth){
	FILE *ptr;
 	int  j;
 	int flag = 0;
 	int count = 0;
 	student s;
 	ptr = fopen("students", "a+");
 	if(ptr == NULL){
 		printf("operation failed");
 		return;
 	}	
 	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(id == s.id) {
			flag = 1;
			for(j = 0; j < 30; j++){
				if(s.attendance[mnth][j] == 1){
					count++;
				}
				}
			}
		}
	fseek(ptr, 0, 0);
	return count;
}

/*To calculate monthly bill*/
int calmonthlybill(int p, int charge, int n)
{
	int bill = 0;
	bill = p * n * charge;
	printf("Monthly bill is %d", bill);
	return bill;
}

void viewstudent(unsigned int id)
{
	FILE *ptr;
 	student s;
 	int flag = 0;
 	int count = 0, c;
 	ptr = fopen("students", "a+");
 	if(ptr == NULL){
 		printf("operation failed");
 		return;
 	}	
 	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(id == s.id) {
			flag = 1;
			printf("	name		: %s\n"
				"	id		: %u\n"
				"	Room no.	: %u\n"									
				"	contact no.	: %s\n "
				"	Email id	: %s\n"
				"	Enter date of admission:%s\n "
				"	city		: %s\n"
				"	District	: %s\n"
				"	pincode		: %s\n"
				"	state		: %s\n", s.name, s.id, s.room_no, s.contact, s.e_mail, s.admdate, s.addr.city, s.addr.dist, s.addr.pin, s.addr.state);
		break;
		}
	}
	if(flag == 0) 
		printf("		This Student ID doesn't exist\n");
	fclose(ptr);
}

 int calabsentdays(unsigned int id, unsigned int mnth)
 {
 	FILE *ptr;
 	int i, j;
 	int flag = 0;
 	int count = 0;
 	student s;
 	ptr = fopen("students", "a+");
 	if(ptr == NULL){
 		printf("operation failed");
 		return;
 	}	
 	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(id == s.id) {
			flag = 1;
		//	for(i = 1; i <= 12; i++){
				for(j = 0; j < 31; j++){
					if(s.attendance[mnth][j] == 0)
						count++;
				}
			}
		}
	return count;
}











		
