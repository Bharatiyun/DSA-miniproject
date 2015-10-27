 typedef struct address{
 	char dist[20],city[20];
 	char pin[8], state[50];
 	}address;
 	
 typedef struct date{
 	int dd, mm, yyyy;
 	}date;
 	
 typedef struct feedetails{
 	unsigned int id;
 	unsigned int deposit, monthlybill, snacksbill , fine, predues, servcharge;
 	}feedetails;
 	
typedef struct student{
	char name[20];
	unsigned int id;
	unsigned int room_no;
	date admdate;
	char contact[11], e_mail[128];
	address addr;
	feedetails fd;
	} student;
		
 void addstudent(char *name, unsigned int id, unsigned int room_no, date admdate, char *contact, char *email, address addr);
 void markattendance(unsigned int *id);
 void viewstudents();
 void viewmonthly_bill(unsigned int *id);
 
 void searchbyname(char *name);
 void searchbyid(unsigned int id);
 void searchbycontact(char *contact);
 void searchbyemail(char *e_mail);
 
 void deletestudent(unsigned int id);
 
 void editname(char *name, unsigned int id);
 void editcity(char *city, unsigned int id);
 void editcontact(char *contact, unsigned int id);
 void editdistrict(char *dist, unsigned int id);
 void editstate(char *state, unsigned int id);
 void editpincode(char *pincode, unsigned int id);
 void editdateofdep(date dateofdep, unsigned int id);
 void editstartingday(date startingday, unsigned int id);
 void editroom_no(char *room_no, unsigned int id);
 void editemail(char *e_mail, unsigned int id);
 void editadmissiondate(date dt, unsigned int id);
 void editdeposit(unsigned int deposit, unsigned int id);
 void editmonthlybill(unsigned int deposit, unsigned int id);
 void editsnacksbill(unsigned int snacksbill, unsigned int id);
 void editfine(unsigned int fine, unsigned int id);
 void editattendance(char *attendance, unsigned int id);
 void editid(char *name);
 
 int calmonthlybill();
 int calsnacksbill();
 int calguestbill();
 void readline (char *stng, int n);  
 
  
  
  
 
 
 
 
 
 	
 	
 	
 	
 	
	

