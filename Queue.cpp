#include<iostream>
using namespace std;
class Branch
{
	private:
		int ID;
	    string address ;
	    int phone;
        string pharmacistList;
        string drugList;
        public :
		int getID()
		{
		  return ID;	
		}
		int getPhone()
		{
			return phone;
		}
		string getAdress()
		{
			return address;
		}
		void setID(int d)
		{
			ID = d;
		}
		void setaddtess(string ad)
		{
			address = ad;
		}
		void setPhone(int p)
		{
			phone = p;
		}
};
class Pharmacist 
{
	public :
		int getID()
		{
			return ID;
		}
		string getname()
		{
			return name;
		}
		int getlicenseID()
		{
			return leicenseID;
		}
		double getsalary()
		{
			return salary;
			
		}      
		double getsales()
		{
			return sales;
		 } 
		void steID(int d)
		{
			ID = d;
		}
		void setname(string n)
		{
			name = n;
		}
		void setlicenseID(int l)
		{
			leicenseID = l;
		}
		void setsalary(double s)
		{
			salary = s;
		}
		void setsales(double sa)
		{
			sales = sa;
		}
	   void PharmacistBouns(double sales)
	   {        
	           double bonus = 0;
    		   if (sales >= 10)
    		   {
        		    bonus += 5; 
        		    cout<<"Bouns: "<<bonus<<endl;
             	}
        		else
        	    {
				    cout<<"Not bonus"<<endl;
				}
	 }
		private:
		 int ID;
		 string name;
		 int leicenseID;
		 double salary ;
		 double sales;
};
class Drug 
{
	public :
		int getID()
		{
			return ID;
		}
		string gettitle()
		{
			return title;
		}
		float getprice()
		{
			return price;
		}
		int getquantity()
		{
			return quantity;
		}
		void setID(int d)
		{
			ID = d;
		}
		void settitle(string t)
		{
			title = t;
		}
		void setprice(float p)
		{
			price = p;
		}
		void setquantity(int q)
		{
			quantity = q;
		}
		private:
		int ID;
		string title;
		float price;
		int quantity;		
};
class Customer
{
	public:
		int getID()
		{
			return ID;
		}
		string getname()
		{
			return name;
		}
		int getphone()
		{
			return phone;
		}
		string getemail()
		{
			return email;
		}
		double getpoints()
		{
			return points;
		}
		void setID(int d)
		{
			ID = d;
		}
		void setname(string n)
		{
			name = n;
		}
		void setphone(int p)
		{
			phone = p;
		}
		void setemail(string e)
		{
			email = e ;
		}
		void setpoints(double po)
		{
			points = po;
		}
		void collectPoints(double price)
     	{
    		   if (price >= 40)
                {
        		    points += 10; 
        		    cout<<"Points: "<<points<<endl;
        		}
                else if (price < 40)
                {
             		points += 5;
        		    cout<<"Points: "<<points<<endl;
        		}
	           }
		private:
		int ID ;
		string name;
		int phone;
		string email;
		double points;		
};
// linked list for all classes
// linked list for class Branch
class branchNode {
public:
	double data;
	char adress[20];
	branchNode* next;	
};
class branchList {
public:
	branchList(void) { head = NULL; }	
	~branchList(){ branchNode* currNode = head, *nextNode = NULL;
   while (currNode != NULL)
   {
	nextNode	=	currNode->next;
	delete currNode;	
	currNode	=	nextNode;
   }
}				
	bool IsEmpty() { return head == NULL; }
	branchNode* InsertNode(int index, double x){
		if (index < 0) return NULL;	
	    int currIndex	=	1;
    	branchNode* currNode	=	head;
    	while (currNode && index > currIndex) {
    		currNode	=	currNode->next;
    		currIndex++;
	    }
    	if (index > 0 && currNode == NULL) return NULL;
    	branchNode* newNode	=	new branchNode;
    	newNode->data = x;
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	currNode->next;
		currNode->next	=	newNode;
	   }
    	return newNode;
	}	
	branchNode* InsertName(int index, char x[20]){
		if (index < 0) return NULL;	
	    int currIndex	=	1;
    	branchNode* currNode	=	head;
    	while (currNode && index > currIndex) {
    		currNode	=	currNode->next;
    		currIndex++;
	    }
    	if (index > 0 && currNode == NULL) return NULL;
    	branchNode* newNode	=	new branchNode;
    	
    	newNode->adress[20] =	x[20];	
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	currNode->next;
		currNode->next	=	newNode;
	   }
    	return newNode;
	}	
 int BranchFindNode(double x)
	{
		branchNode* currNode	=	head;
	    int currIndex	=	1;
	    while (currNode && currNode->data != x) {
		currNode	=	currNode->next;
		currIndex++;
	}
	if (currNode) 
          return currIndex;
		  return 0;
   }	
	int BranchDeleteNode(double x){
		branchNode* prevNode = NULL;
	    branchNode* currNode = head;
	    int currIndex = 1;
    	while (currNode && currNode->data != x) {
		 prevNode = currNode;
		 currNode =	currNode->next;
		 currIndex++;
	   }
	    if (currNode) {
		if (prevNode) {
			prevNode->next	= currNode->next;
			delete currNode;
		}
		else {
			head =	currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}
	void DisplayList(void){  
		   int num		=	0;
            branchNode* currNode	=	head;
            if (currNode != NULL){
	            cout << currNode->data << endl;
	            currNode	=	currNode->next;
	            num++;
           }
            cout << "Number of nodes in the list: " << num << endl;
	}  
private:
	branchNode* head;
	friend class QueueBranch;

	
};
// linked list for class Drug
class drugNode {
public:
	double data;
	drugNode* next;
	char title[20];		
};
class drugList {
public:
	drugList(void) { head = NULL; }	
	~drugList(){
	    drugNode* currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
        	nextNode	=	currNode->next;
        	delete currNode;	
        	currNode	=	nextNode;
       }
   }							
	bool IsEmpty() { return head == NULL; }
	drugNode* InsertNode(int index, double x){
		if (index < 0) return NULL;	
	    int drugcurrIndex	=	1;
    	drugNode* drugcurrNode	=	head;
    	while (drugcurrNode && index > drugcurrIndex) {
    		drugcurrNode = drugcurrNode->next;
    		drugcurrIndex++;
	    }
    	if (index > 0 && drugcurrNode == NULL) return NULL;
    	drugNode* newNode	=	new	drugNode;
    	newNode->data	=	x;	
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	drugcurrNode->next;
		drugcurrNode->next	=	newNode;
	   }
    	return newNode;
	}
	drugNode* InsertTitle(int index, char x[20] ){
		if (index < 0) return NULL;	
	    int drugcurrIndex	=	1;
    	drugNode* drugcurrNode	=	head;
    	while (drugcurrNode && index > drugcurrIndex) {
    		drugcurrNode = drugcurrNode->next;
    		drugcurrIndex++;
	    }
    	if (index > 0 && drugcurrNode == NULL) return NULL;
    	drugNode* newNode	=	new	drugNode;
    	newNode->title[20]	=	x[20];
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	drugcurrNode->next;
		drugcurrNode->next	=	newNode;
	   }
    	return newNode;
	}				
	int DrugFindNode(double x)
	{
		drugNode* currNode	=	head;
	    int currIndex	=	1;
	    while (currNode && currNode->data != x) {
		currNode	=	currNode->next;
		currIndex++;
	}
	if (currNode) 
          return currIndex;
		  return 0;
   }	
	int drugDeleteNode(double x){
			if (IsEmpty())
		 cout<<"error\n";
		drugNode*currnode = head; 
		if(head->data == x)
		{
			head = head->next;
			delete currnode;
		}
		else
		{
			drugNode*prev = NULL;
			currnode = head;
			while(currnode->data != x)
			{
				prev = currnode;
				currnode = currnode->next;
			}
			prev->next = currnode->next;
			delete currnode;
		}
}	
	void DisplayList(void){
		   int num		=	0;
            drugNode* currNode	=	head;
            while (currNode != NULL){
	        cout << currNode->data << endl;
	        currNode	=	currNode->next;
	        num++;
       }
        cout << "Number of nodes in the list: " << num << endl;
	}
private:
	drugNode* head;
	friend class QDrug;
};
//linked list for class Pharmacist
class PharmacistNode {
public:
	double data;	
	PharmacistNode* next;
	char name[20];		
};
class PharmacistList {
public:
	PharmacistList(void) { head = NULL; }	
	~PharmacistList(){ 
	    PharmacistNode* currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
        	nextNode	=	currNode->next;
        	delete currNode;	
        	currNode	=	nextNode;
        }
   }								
	bool IsEmpty() { return head == NULL; }
	PharmacistNode* InsertNode(int index, double x){
		if (index < 0) return NULL;	
	    int PharmacistcurrIndex	=	1;
    	PharmacistNode* PharmacistcurrNode	=	head;
    	while (PharmacistcurrNode && index > PharmacistcurrIndex) {
    		PharmacistcurrNode = PharmacistcurrNode->next;
    		PharmacistcurrIndex++;
	    }
    	if (index > 0 && PharmacistcurrNode == NULL) return NULL;
    	PharmacistNode* newNode	=	new	PharmacistNode;
    	newNode->data	=	x;	
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	PharmacistcurrNode->next;
		PharmacistcurrNode->next	=	newNode;
	   }
    	return newNode;
	}
	
		PharmacistNode* InsertName(int index, char x[20]){
		if (index < 0) return NULL;	
	    int PharmacistcurrIndex	=	1;
    	PharmacistNode* PharmacistcurrNode	=	head;
    	while (PharmacistcurrNode && index > PharmacistcurrIndex) {
    		PharmacistcurrNode = PharmacistcurrNode->next;
    		PharmacistcurrIndex++;
	    }
    	if (index > 0 && PharmacistcurrNode == NULL) return NULL;
    	PharmacistNode* newNode	=	new	PharmacistNode;
    	newNode->name[20]	=	x[20];	
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	PharmacistcurrNode->next;
		PharmacistcurrNode->next	=	newNode;
	   }
    	return newNode;
	}
	
	int PharmacistFindNode(double x)
	{
		PharmacistNode* currNode	=	head;
	    int currIndex	=	1;
	    while (currNode && currNode->data != x) {
		currNode	=	currNode->next;
		currIndex++;
	}
	if (currNode) 
          return currIndex;
		  return 0;
   }	
	int PharmacistDeleteNode(double x){
			if (IsEmpty())
		 cout<<"error\n";
		PharmacistNode*currnode = head; 
		if(head->data == x)
		{
			head = head->next;
			delete currnode;
		}
		else
		{
			PharmacistNode*prev = NULL;
			currnode = head;
			while(currnode->data != x)
			{
				prev = currnode;
				currnode = currnode->next;
			}
			prev->next = currnode->next;
			delete currnode;
		}
}	
	void DisplayList(){
		   int num		=	0;
            PharmacistNode* currNode	=	head;
            while (currNode != NULL){
	        cout << currNode->data << endl;
	        currNode	=	currNode->next;
	        num++;
       }
        cout << "Number of nodes in the list: " << num << endl;
	}
private:
	PharmacistNode* head;
	friend class QPharmacist;
};
// linked list for class customer
class customerNode {
public:
	double data;	
	char N[10];
	customerNode* next;		
};
class customerList {
public:
	customerList(void) { head = NULL; }	
	~customerList()	{ 
	    customerNode* currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
        	nextNode	=	currNode->next;
        	delete currNode;	
        	currNode	=	nextNode;
        }
   }		
	bool IsEmpty() { return head == NULL; }
	customerNode* InsertNode(int index, double x){
		if (index < 0) return NULL;	
	    int customercurrIndex	=	1;
    	customerNode* customercurrNode	=	head;
    	while (customercurrNode && index > customercurrIndex) {
    		customercurrNode = customercurrNode->next;
    		customercurrIndex++;
	    }
    	if (index > 0 && customercurrNode == NULL) return NULL;
    	customerNode* newNode	=	new	customerNode;
    	newNode->data	=	x;	
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	customercurrNode->next;
		customercurrNode->next	=	newNode;
	   }
    	return newNode;
	}	
		customerNode* InsertName(int index, char x[10]){
		if (index < 0) return NULL;	
	    int customercurrIndex	=	1;
    	customerNode* customercurrNode	=	head;
    	while (customercurrNode && index > customercurrIndex) {
    		customercurrNode = customercurrNode->next;
    		customercurrIndex++;
	    }
    	if (index > 0 && customercurrNode == NULL) return NULL;
    	customerNode* newNode	=	new	customerNode;
    	newNode->N[10]= x[10];	
    	if (index == 0) {
	    	newNode->next	=	head;
	    	head		=	newNode;
       }
    	else {
		newNode->next	=	customercurrNode->next;
		customercurrNode->next	=	newNode;
	   }
    	return newNode;
	}
	int customerFindNode(double x)
	{
		customerNode* currNode	=	head;
	    int currIndex	=	1;
	    while (currNode && currNode->data != x) {
		currNode	=	currNode->next;
		currIndex++;
	}
	if (currNode) 
          return currIndex;
		  return 0;
   }	
	int customerDeleteNode(double x){
			if (IsEmpty())
		 cout<<"error\n";
		customerNode*currnode = head; 
		if(head->data == x)
		{
			head = head->next;
			delete currnode;
		}
		else
		{
			customerNode*prev = NULL;
			currnode = head;
			while(currnode->data != x)
			{
				prev = currnode;
				currnode = currnode->next;
			}
			prev->next = currnode->next;
			delete currnode;
		}
}	
	void DisplayList(void){
		   int num		=	0;
            customerNode* currNode	=	head;
            while (currNode != NULL){
	        cout << currNode->data << endl;
	        currNode	=	currNode->next;
	        num++;
       }
        cout << "Number of nodes in the list: " << num << endl;
	}
private:
	customerNode* head;
	friend class Qcustomer;
};
// Queue for class Branch
class QueueBranch : public branchList {
public:
	QueueBranch() {		
		front = rear = NULL;
		counter	= 0;
	}		
	~QueueBranch() {		
		double value;
		while (!IsEmpty()) Dequeue(value);
	}
	bool IsEmpty() {
		if (counter) 	return false;
		else	    	return true;
	}
	void Enqueue(double x){
	branchNode* newNode	=	new branchNode;
	newNode->data	=	x;
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}
void EnqueueStr( char x[20] ){
	branchNode* newNode	=	new branchNode;
	newNode->adress[20]	=	x[20];
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}

	bool Dequeue(double & x){
	if (IsEmpty()) {
	   cout << "Error: the queue is empty." << endl;
	  return false;
	}
	else {
		x = front->data;
		branchNode* nextNode =	front->next;
		delete front;
		front =	nextNode;
		counter--;
	}
}
bool findNode(int item)
{
	bool found = false;
	branchNode* currNode = front;
	while(currNode != NULL)
	{
	   if(currNode->data == item)
	      found = true;
		  currNode = currNode->next;	
	}
	return found;
}
	void DisplayQueue(void){
	cout << "front -->";
	branchNode* currNode	=	front;
	for (int i = 0; i < counter; i++) {
		if (i == 0) cout << "\t";
		else		cout << "\t\t"; 
		cout << currNode->data;
		if (i != counter - 1)
			cout << endl;
		else
			cout << "\t<-- rear" << endl;
		currNode	=	currNode->next;		
	}
}
private:
	branchNode* front;	
	branchNode* rear;	
	int counter;	
};
//Drug
class QueueDr: public drugList {
public:
	QueueDr() {		
		front = rear = NULL;
		counter	= 0;
	}		
	~QueueDr() {		
		double value;
		while (!IsEmpty()) Dequeue(value);
	}
	bool IsEmpty() {
		if (counter) 	return false;
		else	    	return true;
	}
	void Enqueue(double x){
	drugNode* newNode	=	new drugNode;
	newNode->data	=	x;
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}
void EnqueueString(char d[20]){
	drugNode* newNode	=	new drugNode;
	newNode->title[20]	=	d[20];
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}
	bool Dequeue(double & x){
	if (IsEmpty()) {
	   cout << "Error: the queue is empty." << endl;
	  return false;
	}
	else {
		x = front->data;
		drugNode* nextNode =	front->next;
		delete front;
		front =	nextNode;
		counter--;
	}
}
bool findNode(int item)
{
	bool found = false;
	drugNode* currNode = front;
	while(currNode != NULL)
	{
	   if(currNode->data == item)
	      found = true;
		  currNode = currNode->next;	
	}
	return found;
}
	void DisplayQueue(void){
	cout << "front -->";
	drugNode* currNode	=	front;
	for (int i = 0; i < counter; i++) {
		if (i == 0) cout << "\t";
		else		cout << "\t\t"; 
		cout << currNode->data;
		if (i != counter - 1)
			cout << endl;
		else
			cout << "\t<-- rear" << endl;
		currNode	=	currNode->next;		
	}
}
private:
	drugNode* front;	
	drugNode* rear;	
	int counter;	
};
//Pharma
class Queueph : public PharmacistList {
public:
	Queueph() {		
		front = rear = NULL;
		counter	= 0;
	}		
	~Queueph() {		
		double value;
		while (!IsEmpty()) Dequeue(value);
	}
	bool IsEmpty() {
		if (counter) 	return false;
		else	    	return true;
	}
	void Enqueue(double x){
	PharmacistNode* newNode	=	new PharmacistNode;
	newNode->data	=	x;
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}
void EnqueueString(char a[20]){
	PharmacistNode* newNode	=	new PharmacistNode;
	newNode->name[20]	=	a[20];
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}
	bool Dequeue(double & x){
	if (IsEmpty()) {
	   cout << "Error: the queue is empty." << endl;
	  return false;
	}
	else {
		x = front->data;
		PharmacistNode* nextNode =	front->next;
		delete front;
		front =	nextNode;
		counter--;
	}
}
bool findNode(int item)
{
	bool found = false;
	PharmacistNode* currNode = front;
	while(currNode != NULL)
	{
	   if(currNode->data == item)
	      found = true;
		  currNode = currNode->next;	
	}
	return found;
}
	void DisplayQueue(void){
	cout << "front -->";
	PharmacistNode* currNode	=	front;
	for (int i = 0; i < counter; i++) {
		if (i == 0) cout << "\t";
		else		cout << "\t\t"; 
		cout << currNode->data;
		if (i != counter - 1)
			cout << endl;
		else
			cout << "\t<-- rear" << endl;
		currNode	=	currNode->next;		
	}
}
private:
	PharmacistNode* front;	
	PharmacistNode* rear;	
	int counter;	
};
//Customer
class QueueCu : public customerList {
public:
	QueueCu() {		
		front = rear = NULL;
		counter	= 0;
	}		
	~QueueCu() {		
		double value;
		while (!IsEmpty()) Dequeue(value);
	}
	bool IsEmpty() {
		if (counter) 	return false;
		else	    	return true;
	}
	void Enqueue(double x){
	customerNode* newNode	=	new customerNode;
	newNode->data	=	x;
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}
	void EnqueueString(char p[20]){
	customerNode* newNode	=	new customerNode;
	newNode->N[20]	=	p[20];
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
	counter++;
}
	bool Dequeue(double & x){
	if (IsEmpty()) {
	   cout << "Error: the queue is empty." << endl;
	  return false;
	}
	else {
		x = front->data;
		customerNode* nextNode =	front->next;
		delete front;
		front =	nextNode;
		counter--;
	}
}
bool findNode(int item)
{
	bool found = false;
	customerNode* currNode = front;
	while(currNode != NULL)
	{
	   if(currNode->data == item)
	      found = true;
		  currNode = currNode->next;	
	}
	return found;
}
	void DisplayQueue(void){
	cout << "front -->";
	customerNode* currNode	=	front;
	for (int i = 0; i < counter; i++) {
		if (i == 0) cout << "\t";
		else		cout << "\t\t"; 
		cout << currNode->data;
		if (i != counter - 1)
			cout << endl;
		else
			cout << "\t<-- rear" << endl;
		currNode	=	currNode->next;		
	}
}
private:
	customerNode* front;	
	customerNode* rear;	
	int counter;	
};

int main() {
   	int choice;
   	do{
        cout <<"Main Menu:"<<endl;
        cout<<"1. Branch  2. Drug  3.Pharmacist  4.Customer  5.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
 	 switch(choice){
	case 1: //Branch
	{
		int c;
	do
	{
        cout << "\nBranch Menu:" << endl;
        cout << "1. Display Branches" << endl;
        cout << "2. Insert Branch" << endl;
        cout << "3. Delete Branch" << endl;
        cout << "4. Modify Branch" << endl;
        cout << "5. Find Branch" << endl;
        cout << "0. Back" << endl;
        cout<<"Enter operation"<<endl;
		cin>>c;
        Branch b;
        QueueBranch br;
        int d ;
        char a[20] ;
        int p ;
        switch(c)
        {
        	case 1:
        	cout<<"Infromation for Branch"<<"\nID: "<<b.getID()<<"\nAdress:  "<<a<<"\nPhone: "<<b.getPhone()<<endl;
				break;
        	case 2:
			{
               cout<<"Enter ID for Branch"<<endl;
               cin>>d;
               b.setID(d);
               br.Enqueue(d);
               cout<<"Enter Adress for Branch"<<endl;
               cin>>a;
               b.setaddtess(a);
               br.EnqueueStr(a);
               cout<<"Enter Phone for Branch"<<endl;
               cin>>p;
               b.setPhone(p);
               br.Enqueue(p);
               break;
           }
		     case 3:
		   	{ 
		   		br.Enqueue(d);
		   		br.EnqueueStr(a);
		   		br.Enqueue(p);
		   		double value;
            	br.Dequeue(value);
            	cout << "Retrieved element = " << value << endl;
	            br.DisplayQueue();
				break;
		   }
		   case 4:
		   	{
		   		int m;
		   		cout<<"What would you modify: 1. ID  2. Adrees  3. phone"<<endl;
		   		cin>>m;
		   		if(m == 1)
		   		{
		   			int n;
		   			cout<<"Enter new ID"<<endl;
		   			cin>>n;
		   			b.setID(n);
		   			br.Enqueue(n);
				   }
				   else if(m == 2)
				   {
				   	 char na[20];
				   	 cout<<"Enter new Address ";
				   	 cin>>na;
				   	 b.setaddtess(na);
				   	 br.EnqueueStr(na);
				   }
				   else
				   {
				   	 int nf;
				   	 cout<<"Enter new phone number ";
				   	 cin>>nf;
				   	 b.setPhone(nf);
				   	 br.Enqueue(nf);
				   }
				   break;
			   }
			   case 5:
			   	{
			   		br.Enqueue(d);
		   	    	br.EnqueueStr(a);
		   	    	br.Enqueue(p);
			   		int f;
			   		cout<<"Enter item to find ";
			   		cin>>f;
			   		if(br.findNode(f))
			   		    cout<<"Is found"<<endl;
			   		else
			   		    cout<<"Not found"<<endl;
			   		break;
				   }
		case 0:
			cout<<"You Back!"<<endl;
			break;
	}
}while(c != 0);
break;
}
	case 2: //Drug
		{
			int ch;
			do{
		        cout << "\nDrug Menu:" << endl;
                cout << "1. Display Drugs" << endl;
                cout << "2. Insert Drug" << endl;
                cout << "3. Delete Drug" << endl;
                cout << "4. Modify Drug" << endl;
                cout << "5. Find Drug" << endl;
                cout << "0. Back" << endl;
                 cout<<"Enter operation"<<endl;
		        cin>>ch;
		        Drug d;
		        QueueDr dr;
		        int o;
        		char S[10];
        		float pri;
        		int q;	
        		switch(ch)
        		{
        			case 1:
        				cout<<"Infromation for Drug"<<"\nID: "<<d.getID()<<"\nTitle: "<<S<<"\nPrice: "<<d.getprice()<<"\nQuantity: "<<d.getquantity()<<endl;
        			    break;
        			case 2:
        				{
        					cout<<"Enter ID for Drug"<<endl;
                            cin>>o;
                            d.setID(o);
                            dr.Enqueue(o);
                            cout<<"Enter Title"<<endl;
                            cin>>S;
                            dr.EnqueueString(S);
                            cout<<"Enter Price"<<endl;
                            cin>>pri; 
                            d.setprice(pri);
                            dr.Enqueue(pri);
                            cout<<"Enter Quantity"<<endl;
                            cin>>q;
                            d.setquantity(q);
                            dr.Enqueue(q);
     		                break;
						}
						case 3:
							{
								dr.Enqueue(o);
                		   		dr.EnqueueString(S);
                		   		dr.Enqueue(pri);
                		   		dr.Enqueue(q);
                            	double value;
                            	dr.Dequeue(value);
            	                cout << "Retrieved element = " << value << endl;
	                            dr.DisplayQueue();
			                	break;
							}
							case 4: 
							{
								int m;
                 		   		cout<<"What would you modify: 1. ID  2. Title  3. Price  4. Quantity"<<endl;
                		   		cin>>m;
                		   		switch(m)
        	        	   		{
        	        	   			case 1:{
	        	   	        	    	cout<<"Enter new ID"<<endl;
	     	   	            	    	cin>>o;
		   		                    	d.setID(o);
		   	                	    	dr.Enqueue(o);
		   	                	    	break;
            				           }
            				   case 2: 
             				   {
				   	             cout<<"Enter new Title ";
		             		   	 cin>>S;
		             		   	 d.settitle(S);
                                 dr.EnqueueString(S);
				   	             break;
				                }
	             			   case 3:
             				   {
            				   	 cout<<"Enter new Price ";
				            	 cin>>pri;
			            	   	 d.setprice(pri);
			            	   	 dr.Enqueue(pri);
			            	   	 break;
				               }
				               case 4:
				               	{
				               		 cout<<"Enter new Quantity ";
				               		 cin>>q;
				               		 d.setquantity(q);
				               		 dr.Enqueue(q);
				               		break;
								   }
			   }
			   break;
		}
			   case 5:
			   	{
			   	    dr.Enqueue(o);
                	dr.EnqueueString(S);
                	dr.Enqueue(pri);
                	dr.Enqueue(q);
			   		int f;
			   		cout<<"Enter item to find ";
			   		cin>>f;
			   		if(dr.findNode(f))
			   		    cout<<"Is found"<<endl;
			   		else
			   		    cout<<"Not found"<<endl;
			   		break;
				   }
		case 0:
			cout<<"You Back!"<<endl;
			break;
							
				}    
}while(ch != 0);
break;
}
       case 3: //Pharmacist 
    	{
    		int ce;
    		do{
                cout << "\nPharmacist Menu:" << endl;
                cout << "1. Display Pharmacists" << endl;
                cout << "2. Insert Pharmacist" << endl;
                cout << "3. Delete Pharmacist" << endl;
                cout << "4. Modify Pharmacist" << endl;
                cout << "5. Find Pharmacist" << endl;
                cout <<"6. Pharmacist Bonus" <<endl;
                cout << "0. Back" << endl;
                cout<<"Enter operation"<<endl;
		        cin>>ce;
		        Pharmacist p;
		        Queueph ph;
		        int i;
		        char N[10] ;
		        int le;
         		double sar;
		        double sal;
		        switch(ce)
		        {
		        	case 1:
		        		cout<<"Infromation for Pharmacist\n"<<"ID: "<<p.getID()<<"\nLicenseID: "<<p.getlicenseID()<<"\nName: "<<N<<"\nSalary: "<<p.getsalary()<<"\nSales: "<<p.getsales()<<endl;
				    break;
				case 2:
					{
						cout<<"Enter ID for Pharmacist"<<endl;
                        cin>>i;
                        p.steID(i);
                        ph.Enqueue(i);
                        cout<<"Enter LicenseID"<<endl;
                        cin>>le;
                        p.setlicenseID(le);
                        ph.Enqueue(le);
                        cout<<"Enter Name"<<endl;
                        cin>>N;
                        p.setname(N);
                        ph.EnqueueString(N);
                        cout<<"Enter Salary"<<endl;
                        cin>>sar;
                        p.setsalary(sar);
                        ph.Enqueue(sar);
                        cout<<"Enter Sales"<<endl;
                        cin>>sal;
                        p.setsales(sal);
                        ph.Enqueue(sal);
     		           break;
					}
					case 3:
		   	       { 
		   	    	ph.Enqueue(i);
		   	    	ph.Enqueue(le);
		   	    	ph.EnqueueString(N);
		   	        ph.Enqueue(sar);
		   	    	ph.Enqueue(sal);
                	double value;
                    ph.Dequeue(value);
            	    cout << "Retrieved element = " << value << endl;
	                ph.DisplayQueue();
			    	break;
					}
		   case 4:
		   	{
		   		int m;
		   		cout<<"What would you modify: 1. ID  2. LicenseID   3. Name  4. Salary  5. Sales"<<endl;
		   		cin>>m;
		   		switch(m)
		   		{
		   			case 1:
		   				{
		   	    	    	cout<<"Enter new ID "<<endl;
		   		        	cin>>i;
		   		        	p.steID(i);
		   		        	ph.Enqueue(i);
		   		        	break;
				       }
					   case 2:
					   	{
				   	         cout<<"Enter new LicenseID ";
				        	 cin>>le;
				        	 p.setlicenseID(le);
				        	 ph.Enqueue(le);
				        	 break;
				        }
				        case 3:
						{
				   	     cout<<"Enter new Name ";
				     	 cin>>N;
				     	 p.setname(N);
				     	 ph.EnqueueString(N);
				     	 break;
				       }
				       case 4:
				       	{
				       		cout<<"Enter new salary ";
				       		cin>>sar;
				       		p.setsalary(sar);
				       		ph.Enqueue(sar);
				       		break;
						}
						case 5:
							{
								cout<<"Enter new sales ";
								cin>>sal;
								p.setsales(sal);
								ph.Enqueue(sal);
								break;
							}
			   }
				   break;
			}
			   case 5:
			   	{
			   		ph.Enqueue(i);
		   	    	ph.Enqueue(le);
		   	    	ph.EnqueueString(N);
		   	        ph.Enqueue(sar);
		   	    	ph.Enqueue(sal);
			   		int f;
			   		cout<<"Enter item to find ";
			   		cin>>f;
			   		if(ph.findNode(f))
			   		    cout<<"Is found"<<endl;
			   		else
			   		    cout<<"Not found"<<endl;
			   		break;
				   }
				   case 6 :
				   	{
				   		p.PharmacistBouns(sal);
				   		break;
					   }
		            case 0:
		              	cout<<"You Back!"<<endl;
		            	break;
		       }
		}while(ce != 0);
		break;
}
    case 4: //Customer
    	{
    		int cu;
    		do {
    			cout << "\nCustomer Menu:" << endl;
                cout << "1. Display Customers" << endl;
                cout << "2. Insert Customer" << endl;
                cout << "3. Delete Customer" << endl;
                cout << "4. Modify Customer" << endl;
                cout << "5. Find Customer" << endl;
                cout <<"6. collectPoints"<<endl;
                cout << "0. Back" << endl;
                cout<<"Enter operation"<<endl;
		        cin>>cu;
		        Customer c;
		        QueueCu cr;
		        int i;
		        char N[10] ;
		        int po;
         		double pos = 0;
		        char em[15];
		        switch(cu)
		        {
		        	case 1:
		        	    cout<<"Infromation for Customer\n"<<"ID: "<<c.getID()<<"\nName: "<<N<<"\nPhone: "<<c.getphone()<<"\nPoints:  "<<c.getpoints()<<"\nEmail: "<<em<<endl;
						break;
				case 2:
					{
						cout<<"Enter ID for Customer"<<endl;
                        cin>>i;
                        c.setID(i);
                        cr.Enqueue(i);
                        cout<<"Enter Name"<<endl;
                        cin>>N;
                        cr.EnqueueString(N);
                        cout<<"Enter Phone number"<<endl;
                        cin>>po;
                        c.setphone(po);
                        cr.Enqueue(po);
                        cout<<"Enter Email"<<endl;
                        cin>>em;
                        cr.EnqueueString(em);
                        cout<<"Enter Points"<<endl;
                        cin>>pos;
                        c.setpoints(pos);
                        cr.Enqueue(pos);
     		           break;
					}
					case 3:
		   	       { 
		   	    	cr.Enqueue(i);
		   	    	cr.EnqueueString(N);
		   	    	cr.Enqueue(po);
		   	    	cr.EnqueueString(em);
		   	    	cr.Enqueue(pos);
                	double value;
                    cr.Dequeue(value);
            	    cout << "Retrieved element = " << value << endl;
	                cr.DisplayQueue();
			    	break;
					}
		   case 4:
		   	{
		   		int m;
		   		cout<<"What would you modify: 1. ID  2. Email   3. Name  4. Points  5. Phone"<<endl;
		   		cin>>m;
		   		switch(m)
		   		{
		   			case 1:
		   				{
		   	    	    	cout<<"Enter new ID "<<endl;
		   		        	cin>>i;
		   		        	c.setID(i);
		   		        	cr.Enqueue(i);
		   		        	break;
				       }
					   case 2:
					   	{
				   	         cout<<"Enter new Email ";
				        	 cin>>em;
				        	 c.setemail(em);
				        	 cr.EnqueueString(em);
				        	 break;
				        }
				        case 3:
						{
				   	     cout<<"Enter new Name ";
				     	 cin>>N;
				     	 c.setname(N);
				     	 cr.EnqueueString(N);
				     	 break;
				       }
				       case 4:
				       	{
				       		cout<<"Enter new Points ";
				       		cin>>pos;
				       		c.setpoints(pos);
				       		cr.Enqueue(pos);
				       		break;
						}
						case 5:
							{
								cout<<"Enter new Phone ";
								cin>>po;
								c.setphone(po);
								cr.Enqueue(po);
								break;
							}
			   }
				   break;
		}
			   case 5:
			   	{
			   		cr.Enqueue(i);
		   	    	cr.EnqueueString(N);
		   	    	cr.Enqueue(po);
		   	    	cr.EnqueueString(em);
		   	    	cr.Enqueue(pos);
			   		int f;
			   		cout<<"Enter item to find ";
			   		cin>>f;
			   		if(cr.findNode(f))
			   		    cout<<"Is found"<<endl;
			   		else
			   		    cout<<"Not found"<<endl;
			   		break;
				   }
				   case 6:
				   	{
				   		float priceDrug = 0;
				   		cout<<"Enter price of drug ";
				   		cin>>priceDrug;
                        c.collectPoints(priceDrug);
				   		break;
					   }
		            case 0:
		              	cout<<"You Back!"<<endl;
		            	break;
			}
	}while (cu != 0);
	break;
} 
    case 5:
    	cout<<"You Exit!"<<endl;
     break;   
 }
} while(choice != 5);
}


