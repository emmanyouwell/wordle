#include <iostream>
#include <fstream> //access files
#include <stdlib.h>
#include <time.h>
#include <algorithm> //finding elements in an array
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
	//Declaration section
	srand(time(0));
	string guess;
	
	int correct=0; //present and in the right position
	int wrong = 0; //not present
	int there=0;   // present but in the wrong position
	
	bool present; //unsure
	char origLetters[100]; //unsure
	char guessLetters[100];
	
	//reading files
	
	ifstream word("C:\\Users\\Emmanuel\\Documents\\notes\\wordle.txt");
	
	
	string text;
	int line = rand() % 21;
	int i=0;
	
	
	//Body
	while(i != line){
		word.ignore(1000,'\n'); //delimiter
		++i;
	
	}
	word >> text; //stores word to text variable
//	cout<<line<<endl;
	transform(text.begin(), text.end(), text.begin(), ::toupper); //convert words to upper case
	
	
//	cout<<text;
	cout<<"I'm thinking of a word"<<endl;
	word.close();

	while(correct != text.length()){
		
		there=0;
		present=0;
		wrong=0;
		correct=0;
		
		//INPUT
		cout<<"Guess: ";
		cin>>guess;
		transform(guess.begin(), guess.end(), guess.begin(), ::toupper); //convert to upper case
		cout<<guess<<endl;
	
	
		//PROCESS
		guessLetters[text.length()]; //setting the size of guessLetters to the size of the original word
		if (guess.length() == text.length()){
			
			for (int j=0; j<guess.length(); j++){
				if (guess[j] == text[j]){
					guessLetters[j] = guess[j];
					correct += 1;
				}
				//guessLetters = {E, R}
				//BREAD
				//EGRET
				else if (find(begin(text),end(text),guess[j]) != end(text)){
					if (find(begin(guessLetters),end(guessLetters),guess[j]) != end(guessLetters)){
						wrong += 1;
						there += 1;
					}
					else{
						guessLetters[j] = guess[j];
						there += 1;
						wrong += 1;
					}
					
				}
				else{
					wrong += 1;
				}
				
				
			}
		}
		else{
			cout<<"Different length";
		}
		
		//OUTPUT
	
		for (int i=0; i<guess.length(); i++){
			cout<<guessLetters[i]<<" ";
		}
		cout<<endl;
		cout<<"Present: "<<there<<endl;
		cout<<"Correct: "<<correct<<endl;
		cout<<"Wrong: "<<wrong<<endl;
		fill(begin(guessLetters), end(guessLetters), '\0');
	}
	cout<<endl;
	cout<<"Correct!"<<endl;
	getch();
}
