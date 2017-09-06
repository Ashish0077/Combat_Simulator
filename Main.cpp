#include<iostream>
#include<conio.h>
#include<string>

#include"Menu.h"

using namespace std;

int main() {

	Menu menu;
	menu.load();
	while (true) {
		menu.process();
		menu.controlmenu();
	}

	return 0;
	
}