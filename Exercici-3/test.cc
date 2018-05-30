#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	char buffer [100];
	int h = 10, m = 50;
	sprintf (buffer, "Alama -- %d:%d", h, m);

	string str(buffer);

	cout << str;
}