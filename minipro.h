 typedef struct address{
 	char dist[20],city[20];
 	char pin[10], state[30];
 	}address;
 	
typedef struct student{
	char name[20];
	unsigned int id, mnth, dt;
	unsigned int room_no;
	char admdate[20];
	char contact[11], e_mail[128];
	int attendance[12][31];
	address addr;
	} student;
 void init();
		
 void addstudent(char *name, unsigned int id, unsigned int room_no, char *admdate, char *contact, char *email, address addr);
 void markpresentee(unsigned int id, int mnth, int dt);
 void markattendance(unsigned int id, unsigned int mnth);
 void viewstudent(unsigned int id);
 //void viewmonthly_bill(unsigned int id);
 
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
// void editdateofdep(date dateofdep, unsigned int id);
// void editstartingday(date startingday, unsigned int id);
 void editroom_no( unsigned int room_no, unsigned int id);
 void editemail(char *e_mail, unsigned int id);
// void editadmissiondate(date dt, unsigned int id);
 void editdeposit(unsigned int deposit, unsigned int id);
 void editmonthlybill(unsigned int deposit, unsigned int id);
 void editsnacksbill(unsigned int snacksbill, unsigned int id);
 void editfine(unsigned int fine, unsigned int id);
 void editattendance(unsigned int mnth, unsigned int dt, unsigned int id);
 void editid(char *name);
 
 int calmonthlybill(int p, int charge, int n);
 int calsnacksbill(unsigned int id);
 int calguestbill();
 int calpresentdays(unsigned int id, unsigned int mnth);
 int calabsentdays(unsigned int id, unsigned int mnth);
 void readline (char *str, int n);  
 
  
  
  
 
 
 
 
 
 	
 	
 	
 	
 	
	

