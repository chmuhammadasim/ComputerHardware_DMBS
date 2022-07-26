#include<dos.h>
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<process.h>
#include"software.h"
#include"accessories.h"
#include"extraF.h"
#include"mainH.h"
using namespace std;

int main()
{
    dbmsintro();
    ofstream f1;                                     
	software a;
    accessories b;                                          
	int n,ch;
	char ch1,cas1,cas2,cas3,cas4;
	   
    do
    {   
        mainmenu:
        dbmsmenu();
		cin>>ch;            
        switch(ch)          
        {
            case 1:         
            {   
                ca1:
                class1();
                cin>>cas1;
                switch (cas1)
                {
                case '1':
                    a.add(a);
                    system("pause");
                    break;
                case '2':
                    b.add(b);
                    system("pause");
                    break;
                case '3':
                    goto mainmenu;
                    break;
                default:
                    cout<<"\n\t!!Invalid Input!!\n";
                    break;
                }
            	goto ca1;
                break;
            }
            case 2: 
            {
                ca2:
                class2();
                cin>>cas2;
                switch (cas2)
                {
                case '1':
                    a.view(a);
                    system("pause");
                    break;
                case '2':
                    b.view(b);
                    system("pause");
                    break;
                case '3':
                    goto mainmenu;
                    break;
                default:
                    cout<<"\n\t!!Invalid Input!!\n";
                    break;
                }
            	goto ca2;                                       
                break;
            }
            case 3:
            {
                ca3:
                class3();
                cin>>cas3;
                switch (cas3)
                {
                case '1':
                    a.search(a);
                    system("pause");
                    break;
                case '2':
                    b.search(b);
                    system("pause");
                    break;
                case '3':
                    goto mainmenu;
                    break;
                default:
                    cout<<"\n\t!!Invalid Input!!\n";
                    break;
                }
            	goto ca3;                                 
                break;
            }
            case 4:
            {
                ca4:
                class4();
                cin>>cas4;
                switch (cas4)
                {
                case '1':
                    a.update(a);
                    system("pause");
                    break;
                case '2':
                    b.update(b);
                    system("pause");
                    break;
                case '3':
                    goto mainmenu;
                    break;
                default:
                    cout<<"\n\t!!Invalid Input!!\n";
                    break;
                }
            	goto ca3;
            	break;
            }
            case 5:
            {
                system("cls");
                cout<<"\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                cout<<"\n\t\t\t                Thank Your Very Much			   \n";
                cout<<"\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                
                exit(0);
            }
            
        }
        cout<<"\nDo you wish to continue? (Y/N)";
		cin>>ch1; 
    }
    while(ch1=='Y'||ch1=='y');
    return 0;
}
