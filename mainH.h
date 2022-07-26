#ifndef mainh_H
#define mainh_H
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
class mainc{
	private:
		int id;
	public:
		mainc(){
			id=0;
		}
		mainc(int id){
			this->id=id;
		}
		setid(int id){
			this->id=id;
		}
		void setid(){       
		cout<<"\nEnter ID number: ";
		cin>>id;
		}
		int getid(){
    		return id;
    	}
};
#endif