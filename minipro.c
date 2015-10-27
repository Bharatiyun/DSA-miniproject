#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include "minipro.h"
 void addstudent(char *name, unsigned int id, unsigned int room_no, date admdate, char *contact, char *e_mail, address addr){
 	FILE *ptr;
	student s;
	ptr = fopen("student", "r");
	if(ptr == NULL) {
		printf("	Operation failed. Try again.\n");
		return;
	}
	//h = (student *)malloc(sizeof(student));
		strcpy(s.name, name);
		strcpy(s.contact, contact);
		strcpy(s.e_mail, e_mail);
		strcpy(s.addr.city, addr.city);
		strcpy(s.addr.dist, addr.dist);
		strcpy(s.addr.pin, addr.pin);
		strcpy(s.addr.state, addr.state);
		s.id = id;
		s.room_no = room_no;
		s.admdate.dd = admdate.dd;
		s.admdate.mm = admdate.mm; 
		s.admdate.yyyy = admdate.yyyy;
		ptr = fopen("student", "a");
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
	ptr = fopen("student", "r");
	if(ptr == NULL) {
		printf("	No student has registered yet.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		flag = 1;
		printf("	ID		: %u\n"
			"	Name		: %s\n"
			"	Contact	6	: %s\n\n", s.id, s.name, s.contact);
	}
	if(flag == 0)
		printf("	No student has registered yet.\n");
	fclose(ptr);
}
void editname(char *name, unsigned int id) {
	FILE *ptr;
	student s;
	int flag = 0, count = 0;
	ptr = fopen("student", "r+");
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
			"	Contact		: %s\n\n", s.id, s.name, s.contact);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
/* To edit contact of a student */
/* Input : Student id and contact */
void editcontact( char *contact, unsigned int id) {
	FILE *ptr;
	student s;
	int flag=0,count= 0;
	ptr = fopen("student", "r+");
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
/*To edit city*/
void editcity(char *city,unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("student", "r+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)) {
		count++;
		if(city==s.addr.city)
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
			"	city		: %s\n",s.id,s.name, s.contact, s.addr.city);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
void editdistrict(char *dist, unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("student", "r+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(dist==s.addr.dist)
			flag = 1;
			strcpy(s.addr.dist, dist);
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
			"	District	: %s\n",s.id,s.name, s.contact, s.addr.city, s.addr.dist);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
void editstate(char *state, unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("student", "r+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(state == s.addr.state)
			flag = 1;
			strcpy(s.addr.state, state);
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
			"	state		: %s\n",s.id, s.name, s.contact, s.addr.city, s.addr.dist, s.addr.state);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
void editpincode(char *pin, unsigned int id)
{
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("student", "r+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(pin == s.addr.pin)
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
			"	pin		: %s\n",s.id, s.name, s.contact, s.addr.city, s.addr.dist, s.addr.state);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
void editemail(char *e_mail, unsigned int id) {
	FILE *ptr;
	student s;
	int count = 0, flag = 0;
	ptr = fopen("student", "r+");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr)){
		count++;
		if(e_mail == s.e_mail)
			flag = 1;
			strcpy(s.e_mail, e_mail);
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
			"	e_mail		: %s\n"
			"	city		: %s\n"
			"	District	: %s\n"
			"	pin		: %s\n",s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.dist, s.addr.state);
		printf("		Student Record Edited Successfully\n");
	}
	fclose(ptr);
}
void searchbyname(char *name)
{
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("books", "r");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(strcasecmp(name, s.name) == 0) {
			flag = 1;
			printf("	id		: %u\n"
				"	name		: %s\n"
				"	contact		: %s\n"
				"	e_mail		: %s\n"
				"	city		: %s\n"
				"	state		: %sn\n", s.id, s.name, s.contact, s.e_mail, s.addr.dist,s.addr.state);
		}
	}
	if(flag == 0)
		printf("	name doesn't exist\n");
	fclose(ptr);
}
void searchbyid(unsigned int id)
{
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("books", "r");
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
				"	state		: %sn\n", s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.dist);
		}
	}
	if(flag == 0)
		printf("	name doesn't exist\n");
	fclose(ptr);
}
void searchbycontact(char *contact)
{
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("books", "r");
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
				"	state		: %sn\n", s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.state);
		}
	}
	if(flag == 0)
		printf("	name doesn't exist\n");
	fclose(ptr);
}
void searchbyemail(char *e_mail)
{
	FILE *ptr;
	student s;
	int flag = 0;
	ptr = fopen("books", "r");
	if(ptr == NULL) {
		printf("	Operation failed.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		if(strcasecmp(e_mail, s.e_mail == 0)) {
			flag = 1;
			printf("	id		: %u\n"
				"	name		: %s\n"
				"	contact		: %s\n"
				"	e_mail		: %s\n"
				"	city		: %s\n"
				"	state		: %sn\n", s.id, s.name, s.contact, s.e_mail, s.addr.city, s.addr.state);
		}
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
 
