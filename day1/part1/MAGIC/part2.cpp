#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef unsigned int nat;

int main() {
	ifstream file;
	string line;
	int initValue = 50;
	nat password = 0;

	file.open("input.txt"); //We open the doc
	if(!file.is_open()){ //We check if the doc is open
		cout << "(!) An error happened while opening the file" << endl;
		return -1;
	}

	while (getline(file, line)) {
		//Parsing <L,R><STEP>
		//For example: L37
		char dir= line[0]; //L
		line= line.substr(1, line.size() - 1); //37
		nat step = stoi(line); //String to int
        //********PART TWO*********
        for (int i=1 ; i <= step; i++){
            initValue += (dir == 'L' ? -1 : 1);
		    if ((initValue % 100) == 0) password++;
        }
	}

	cout << "The password is " << password;


	file.close();
	return 0;
}
