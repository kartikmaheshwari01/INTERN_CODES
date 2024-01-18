#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
 {
    srand(time(0));
    int secretNumber = rand() % 51;
    int userGuess;
    int attempts = 0;

    cout << " NUMBER GUESSING GAME!! "<<endl;
    do 
	{
        cout<<"Enter your guess (between 1 and 50): ";
        cin >>userGuess;
        attempts++; 
        if (userGuess == secretNumber)
	    {
          cout <<"Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        } 
		else if (userGuess < secretNumber) 
		{
            cout <<"Too low! Plz Try again."<<endl;
        } 
		else 
		{
            cout <<"Too high! Plz Try again."<<endl;
        }
    } 
	while(userGuess != secretNumber);
    return 0;
}

