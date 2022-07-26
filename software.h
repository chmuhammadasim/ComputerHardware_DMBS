#ifndef Software_H 
#define Software_H 
#include<iostream>
#include<iomanip> 
#include<fstream>
#include"mainH.h"
using namespace std;

class software:public mainc
{
    private:
        char sname[20]; 
        char scompany[20];    
        char sprice[20];
    
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
	void setsprice(){    
		cout<<"\"Price : ";
		cin>>sprice;  
	} 
	void setsname(){     
		cout<<"\nName : ";
		cin>>sname;
	}	 
	void setscompany(){ 
		cout<<"\nCompany : ";
		cin>>scompany;
	}
	void setsid(){ 
		setid();
	}
	string getsprice(){ 
		return sprice;
	}
	string getsname(){
		return sname;
	}
	string getscompany(){
		return scompany;
	}
	int getsid(){
		return getid();
	}
	    
        void showsoftware()    
		{   
		    cout<<getsid()<<"\t"<<sname<<"\t"<<scompany<<"\t"<<sprice<<"\n";
    	}
		void getsoftware()
		{                     
		    setid();
		    cout<<"Name : "; 
			cin>>sname;
		    cout<<"Company : "; 
			cin>>scompany;
		    cout<<"Price : "; 
			cin>>sprice;
		}
        void updatesoftware(int n)                                
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
					setid(xid);
				}
				else if(n==2){
		    		cout<<"PRICE : "; 
					cin>>sprice;
				}
				else if(n==3){
		    			cout<<"NAME : "; 
						cin>>sname;
				}
				else if(n==4){
		    			cout<<"COMPANY : "; 
						cin>>scompany;
				}
		}
		void add(software a){
			int n;
			ofstream f1;
			cout<<"\nHow many records do you wish to store? "; 
				cin>>n;
				f1.open("soft.dat",ios::app|ios::binary); 
				for(int i=0; i<n; i++)                   
                {
                 a.getsoftware();                            
                 f1.write((char*)&a,sizeof(a));          
                }
                f1.close();
		}
		void view(software a){
			ifstream f5;
                f5.open("soft.dat",ios::in|ios::binary);
                f5.seekg(0,ios::beg);
                cout<<"ID\t"<<"NAME\t"<<"COMPANY\t"<<"PRICE\t\n";
                while(f5.read((char*)&a,sizeof(a))){
                	if(!f5.eof())
                    a.showsoftware();	
				}
                f5.close();
		}
		void search(software a){
				ifstream f3; 
				int flag=0; 
                f3.open("soft.dat",ios::in|ios::binary);
                f3.seekg(0,ios::beg);
                int id;
                cout<<"\nEnter id number: "; 
				cin>>id;
				cout<<"ID\t"<<"NAME\t"<<"COMPANY\t"<<"PRICE\t\n";
                while(f3.read((char*)&a,sizeof(a)))
                    if(a.getid()==id)
                    {
                        a.showsoftware();
                        flag=1;
                    }
                if(flag==0){  
                    cout<<"\nID number not found. SORRY!"; 
                f3.close(); }
		}
		void update(software a){
				ofstream f2;
                int j;
                f2.open("soft.dat", ios::out|ios::ate|ios::binary);
                int n1;
                cout<<"\nEnter the Id of the record which has to be modified: ";
				cin>>n1;
                int x=(n1-1)*sizeof(a);
                f2.seekp(x,ios::beg);
                a.updatesoftware(x);
                f2.write((char*)&a,sizeof(a));
                f2.close();
		}
};
#endif                                                         
