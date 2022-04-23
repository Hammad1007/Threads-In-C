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
#include <cmath>     // has math functions in it

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
// arg is basically the argument taken as command line argument
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

// reverses the string sample.txt in the repository is just for testing purposes, it is not the file I dealt with
void *reverse(void *arg) {
	string s;
	string text;
	ifstream in;
	int i;
	int size = text.length();
	in.open("sample.txt");
	if(in.is_open()) {
		while(getline(in, text)) {
			cout << text << endl;
		}
		for(int i = 0; i < (size) / 2; i++) {
			swap(text[i], text[size - i - 1];
			s[i] = text[i];
		}
		cout << s << endl;
	}
}

// Main driver starts here
int main() {
	pthread_t t1, t2, t3;   // declaring the threads
	int ret1, ret2, ret3;
	ret1 = pthread_create(&t1, NULL, write, NULL);
	if(ret1 != 0) {
		cout << "Error making the thread.\n";
	}
	ret2 = pthread_create(&t2, NULL, read, NULL);
	if(ret2 != 0) {
		cout << "Error making the thread.\n";
	}
	ret3 = pthread_create(&t3, NULL, reverse, NULL);
	if(ret3 != 0) {
		cout << "Error making the thread.\n";
	}
	// joining the threads
	pthread_join(&t1, NULL);  // join thread1
	pthread_join(&t2, NULL);  // join thread2
	pthread_join(&t3, NULL);  // join thread3
	
	pthread_exit(NULL);   // exiting the thread system
}


