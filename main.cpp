#include <iostream>
#include <string> // String Library
#include <string.h>// string functions
#include <vector>
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <limits>

#include <stdio.h>
#include <ctype.h>
#include <ncurses.h>
#include <termios.h>

#include "colors.h"

//using namespace std;

std::vector<std::string> detailInfo; /*Global vector - user information*/

std::vector<std::string> playerItem;
std::string user;
std::string password;



#include "database_model.h"
//GLOBAL Variables
int op;
int op2;



void hideInput(){

    termios tty;

    tcgetattr(0, &tty);

    /* we want to disable echo */
    tty.c_lflag &= ~ECHO;

    tcsetattr(0, TCSANOW, &tty);
}

void showInput(){
	termios tty;

    tcgetattr(0, &tty);

    /* we want to reenable echo */
    tty.c_lflag |= ECHO;

    tcsetattr(0, TCSANOW, &tty);
}


void pressAnyToContinue(){//Joao
	//wait for enter trigger , hide future type
	std::cout<<"Press ENTER to continue ...";
	hideInput();


	std::cin.clear();
	std::cin.get();
	std::cin.ignore(INT_MAX,'\n');
	showInput();
}



void clearCon(){// Joao

	//clear log on console
	//system("reset");// reset log console
	system("clear");// clear actual screen log on console

	/*Create 100 lines in the console giving the ideia of clean*/
	//cout << std::string( 100, '\n' );
}


bool checkUP(std::string username,std::string password){
	if(username=="ok"||password=="ok"){
		return true;
	}else{
		return false;
	}

};


int main(int argc, char *argv[]){ //Joao

	std::string us;
	std::string pw;
	std::string ans;

	database_model ok;
	us="3";
	ok.checkConnection(us);
	
/*
	std::cout<<std::endl;
	std::cout<<BLUE_TEXT("		  Text Adventure ")<<std::endl;
	std::cout<<YELLOW_TEXT("		▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄")<<std::endl;
	std::cout<<YELLOW_TEXT("		█                █")<<std::endl;
	std::cout<<YELLOW_TEXT("		█                █")<<std::endl;
	std::cout<<YELLOW_TEXT("		█   ")CYAN_TEXT("1 - Start")YELLOW_TEXT("    █")<<std::endl;
	std::cout<<YELLOW_TEXT("		█   ")BLUE_TEXT("2 - Score")YELLOW_TEXT("    █")<<std::endl;
	std::cout<<YELLOW_TEXT("		█   ")GREEN_TEXT("3 - More")YELLOW_TEXT("     █")<<std::endl;
	std::cout<<YELLOW_TEXT("		█   ")RED_TEXT("4 - Quit")YELLOW_TEXT("     █")<<std::endl;
	std::cout<<YELLOW_TEXT("		█                █")<<std::endl;
	std::cout<<YELLOW_TEXT("		█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█")<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Choose an option. \t";
	cin>>op;

	while (std::cin.fail()) {//Joao
		std::cin.clear(); // clear input buffer to restore cin to a usable state
		std::cin.ignore(INT_MAX, '\n'); // ignore last input
		cout << "You can only enter numbers."<<std::endl;
		cout << "Choose an option"<<std::endl;
		cin >> op;
	}

	switch(op) { //Joao
		case 0:{

			clearCon();
			std::cout<<std::endl;
			std::cout<<"Invalid Number! Try Again"<<std::endl;
			main();
			break;
		}
		case 1:{
			
			std::cout<<"Username\t";
			cin>>us;
			hideInput();
			std::cout<<"Password  (*hided)\n";
			cin>>pw;
			showInput();
			while( checkUP(us,pw)!=true){
				std::cout<<"Wrong credentials"<<std::endl;
				std::cout<<"Wish go back (y/n)?"<<std::endl;
				cin>>ans;
				if(ans=="y" ||ans=="Y" || ans=="yes" || ans=="Yes" || ans=="YEs" || ans=="YES" || ans=="yeS" || ans=="yES"){

					clearCon();
					main();
				}

				std::cout<<"Username\t";
				cin>>us;
				hideInput();
				std::cout<<"Password\t";
				cin>>pw;
				showInput();
				checkUP(us,pw);
				}
				
				clearCon();
				
				//main();
					

				break;
			}
		case 2:{

			clearCon();
			
			pressAnyToContinue();
			clearCon();
			showInput();
			main();
			break;
		}
		case 3:{
		
		
			break;
		}
		case 4:{

			clearCon();
			break;
		default:
			std::cout<<std::endl;
			std::cout<<"Invalid Number! Try Again"<<std::endl;
			main();
			break;}
	}
clearCon();
main();
*/

return 0;
}

