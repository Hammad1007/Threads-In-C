#include <iostream>
#include <pthread.h>  // for using threads
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>   // header file for handling files
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cmath>

using namespace std;

// writes in file
void* write(void* arg) {
	string s;
	ofstream out;
	out.open("sample.txt");
	if(out.is_open()) {
		cout << "Enter data in file: \n";
		out << s << endl; 
	}
	out.close();
}

// reads from the file
void* read(void *arg) {
	string s;
	ifstream in;
	string text;
	int i;
	in.open("sample.txt");
	if(in.is_open()) {
		while(getline(in, text)) {
			cout << text << endl;
		}
		for(int i = 0; i < text.length(); i++) {
			int k = i;
			while(i < text.length() && text[i] != ' ') {
				i++;
				if(text[k] >= 'a' && text[i] <= 'z') {
					text[k] = text[k] - 32;
				}
				if(text[i - 1] >= 'a' && text[i - 1] <= 'z') {
					text[i - 1] = text[i - 1] - 32;
				}
			}
		}
		in.close();
	}
	
}

