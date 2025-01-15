#include<iostream>
#include<fstream>
using namespace std;
class node
{
public:
int num;
string name,fathername,address,email;
string phone;
string cnic;
int balance;
node* next;
node* priv;
node(int val,string sname,string sfathername,string saddress,string emailid,string phoneno,string cnicno,int acbalance)
{
num=val;
name=sname;
fathername=sfathername;
address=saddress;
email=emailid;
phone=phoneno;
cnic=cnicno;
balance=acbalance;
}
};
void newaccount(node* &head,int val,string sname,string sfathername,string saddress,string emailid,string phoneno,string cnicno,int acbalance)
{
node* n=new node(val,sname,sfathername,saddress,emailid,phoneno,cnicno,acbalance);
if(head==NULL)
{
head=n;
return;
}
node* temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=n;
n->priv=temp;
}
void display1(node* head)
{
fstream file;
file.open("bankfile.doc",ios::out);
node* temp=head;
while(temp!=NULL)
{
file<<temp->num<<"     ";
file<<temp->name<<"     ";
file<<temp->fathername<<"     ";
file<<temp->address<<"     ";
file<<temp->phone<<"     ";
file<<temp->cnic<<"     ";
file<<temp->balance<<"    ";
file<<endl;
temp=temp->next;
}
}
void display(node* head)
{
node* temp=head;
while(temp!=NULL)
{
cout<<temp->num<<"     ";
cout<<temp->name<<"     ";
cout<<temp->fathername<<"     ";
cout<<temp->address<<"     ";
cout<<temp->phone<<"     ";
cout<<temp->cnic<<"     ";
cout<<temp->balance<<"    ";
cout<<endl;
temp=temp->next;
}
}
void delfirst(node* &head)
{
node* temp=head;
head=head->next;
head->priv=NULL;
delete temp;
}

void deleteion(node* &head,int pos)
{
if(pos==1)
{
delfirst(head);
return;
}
node* temp=head;
int count=1;
while(count<pos)
{
temp=temp->next;
count++;
}
temp->priv->next=temp->next;
temp->next->priv=temp->priv;
}
void show(node* &head,int pos)
{
node* temp=head;
if(head==NULL)
{
cout<<"Create new account is empty"<<endl;
}
int count=1;
while(count<pos)
{

count++;
temp=temp->next;
}

cout<<temp->num<<"     ";
cout<<temp->name<<"     ";
cout<<temp->fathername<<"     ";
cout<<temp->address<<"     ";
cout<<temp->phone<<"     ";
cout<<temp->cnic<<"     ";
cout<<temp->balance<<"   ";
cout<<endl;
}
void deposit(node* &head,int pos)
{
int no;
int bal;
node* temp=head;
int count=1;
while(count<pos-1)
{
temp=temp->next;
count++;

}
cout<<temp->num<<"     ";
cout<<temp->name<<"     ";
cout<<temp->fathername<<"     ";
cout<<temp->address<<"     ";
cout<<temp->phone<<"     ";
cout<<temp->cnic<<"     ";
cout<<temp->balance<<"   ";
cout<<endl;
cout<<"Press 1 to deposit the amount";
cin>>no;
if(no==1)
{
cout<<"Enter the ammount"<<endl;
cin>>bal;
temp->balance=temp->balance+bal;
cout<<"Your new balance is "<<endl;
cout<<temp->balance;
cout<<endl;
}
}
void withdraw(node* &head,int pos)
{
int bal,no;
node* temp=head;
int count=1;
while(count<pos-1)
{
temp=temp->next;
count++;

}
cout<<temp->num<<"     ";
cout<<temp->name<<"     ";
cout<<temp->fathername<<"     ";
cout<<temp->address<<"     ";
cout<<temp->phone<<"     ";
cout<<temp->cnic<<"     ";
cout<<temp->balance<<"   ";
cout<<endl;
cout<<temp->balance<<endl;
cout<<"Press 1 to withdraw the amount"<<endl;
cin>>no;
cout<<"Enter the ammount"<<endl;
cin>>bal;
temp->balance=temp->balance-bal;
cout<<"Your new balance is "<<endl;
cout<<temp->balance;
cout<<endl;
}
int main()
{
string sname,sfathername,saddress,emailid,phoneno,cnicno;
int acbalance,val,pos;
int no;
node* head=NULL;
do
{
cout<<    "\t\t*BANKING SOFTWARE*"	<<endl;
cout<<"\tEnter 1 to create new account "<<endl;
cout<<"\tEnter 2 view account data  "<<endl;
cout<<"\tEnter 3 for deposit"<<endl;
cout<<"\tEnter 4 for withdraw"<<endl;
cout<<"\tEnter 5 to delete account"<<endl;
cout<<"\tEnter 6 to exit"<<endl;
cout<<"--------------------------------------------"<<endl;
cout<<"\n\n\tSelect Your Option (1-6) ";
cin>>no;

if(no==1)
{
cout<<"Enter Account Number"<<endl;
cin>>val;
cout<<"Your Name"<<endl;
cin>>sname;
cout<<"Enter Father Name"<<endl;
cin>>sfathername;
cout<<"Enter your Address"<<endl;
cin>>saddress;
cout<<"Enter Email id"<<endl;
cin>>emailid;
cout<<"Enter Phone No "<<endl;
cin>>phoneno;
cout<<"Enter CNIC Number "<<endl;
cin>>cnicno;
cout<<"Enter Balance"<<endl;
cin>>acbalance;
newaccount(head,val,sname,sfathername,saddress,emailid,phoneno,cnicno,acbalance);
display1(head);
}
else if(no==2)
{
cout<<"Enter Account Number"<<endl;
cin>>pos;
show(head,pos);
}
else if(no==3)
{
cout<<"Enter Account Number"<<endl;
cin>>val;
deposit(head,val);
}
else if(no==4)
{
cout<<"Enter Account Number"<<endl;
cin>>val;
withdraw(head,val);
}
else if(no==5)
{
string passward;
cout<<"Enter passward"<<endl;
cin>>passward;
if(passward=="123456")
{
cout<<"Enter position note account delete from file"<<endl;
cin>>pos;
deleteion(head,pos);
cout<<"Account deleted from file"<<endl;
}
else
cout<<"Incorrect passwad"<<endl;
}
else if(no==6)
{
cout<<"Thanks for visiting our bank"<<endl;
}
else
cout<<"Enter valid choice";
}
while(no!=6);
return 0;
}
