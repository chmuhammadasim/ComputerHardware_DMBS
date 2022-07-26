#ifndef accessories_H 
#define accessories_H 
#include<iostream>
#include<iomanip> 
#include<fstream>
#include"mainH.h"
using namespace std;

class accessories
{
    private:
        mainc m;
        char aname[20]; 
        char acompany[20];    
        char aprice[20];
    
	public:	
	
/*	vehicle(){ 
		sname[20]="Null";
		sprice[20]="Null";
		scompany[20]="Null";
	}
	
	vehicle(string sname,string scompany,string sprice,int id){ 
	    this->sname=sname; 
        this->scompany=scompany;
        this->sprice=sprice;
	}*/
	void setaprice(){    
		cout<<"\"Price : ";
		cin>>aprice;  
	} 
	void setaname(){     
		cout<<"\nName : ";
		cin>>aname;
	}	 
	void setacompany(){ 
		cout<<"\nCompany : ";
		cin>>acompany;
	}
	void setsid(){ 
		m.setid();
	}
	string getaprice(){ 
		return aprice;
	}
	string getaname(){
		return aname;
	}
	string getacompany(){
		return acompany;
	}
	int getaid(){
        int id;
        id=m.getid();
		return id;
	}
	    
        void showaccessories()    
		{   
		    cout<<getaid()<<"\t"<<aname<<"\t"<<acompany<<"\t"<<aprice<<"\n";
    	}
		void getaccessories()
		{                     
		    m.setid();
		    cout<<"Name : "; 
			cin>>aname;
		    cout<<"Company : "; 
			cin>>acompany;
		    cout<<"Price : "; 
			cin>>aprice;
		}
        void updateaccessories(int n)                                
		{        
				int xid;                                                   
			    cout<<"\n\n\t\t\t\t*****----------------------*****";  
		        cout<<"\n\t\t\t\t*****-----Options Menu-----*****\n";
		        cout<<"\t\t\t\t*****----------------------*****\n";
		        cout<<"\n\tOption 1: Change ID";                                  
		        cout<<"\n\tOption 2: Change Price";
		        cout<<"\n\tOption 3: Change Name";
		        cout<<"\n\tOption 4: Change Company";
		        cout<<"\n\nEnter your choice: ";
		        cin>>n;
		        if(n==1){
		    		cout<<"ID : "; 
					cin>>xid;
					m.setid(xid);
				}
				else if(n==2){
		    		cout<<"PRICE : "; 
					cin>>aprice;
				}
				else if(n==3){
		    			cout<<"NAME : "; 
						cin>>aname;
				}
				else if(n==4){
		    			cout<<"COMPANY : "; 
						cin>>acompany;
				}
		}
		void add(accessories a){
			int n;
			ofstream f1;
			cout<<"\nHow many records do you wish to store? "; 
				cin>>n;
				f1.open("acce.dat",ios::app|ios::binary); 
				for(int i=0; i<n; i++)                   
                {
                 a.getaccessories();                            
                 f1.write((char*)&a,sizeof(a));          
                }
                f1.close();
		}
		void view(accessories a){
			ifstream f5;
                f5.open("acce.dat",ios::in|ios::binary);
                f5.seekg(0,ios::beg);
                cout<<"ID\t"<<"NAME\t"<<"COMPANY\t"<<"PRICE\t\n";
                while(f5.read((char*)&a,sizeof(a))){
                	if(!f5.eof())
                    a.showaccessories();	
				}
                f5.close();
		}
		void search(accessories a){
				ifstream f3; 
				int flag=0; 
                f3.open("acce.dat",ios::in|ios::binary);
                f3.seekg(0,ios::beg);
                int id;
                cout<<"\nEnter id number: "; 
				cin>>id;
                while(f3.read((char*)&a,sizeof(a)))
                    if(a.getaid()==id)
                    {
                        a.showaccessories();
                        flag=1;
                    }
                if(flag==0){  
                    cout<<"\nID number not found. SORRY!"; 
                f3.close(); }
		}
		void update(accessories a){
				ofstream f2;
                int j;
                f2.open("acce.dat", ios::out|ios::ate|ios::binary);
                int n1;
                cout<<"\nEnter the Id of the record which has to be modified: ";
				cin>>n1;
                int x=(n1-1)*sizeof(a);
                f2.seekp(x,ios::beg);
                a.updateaccessories(x);
                f2.write((char*)&a,sizeof(a));
				a.showaccessories();
                f2.close();
		}
};
#endif                                                         