#include <iostream>
#include <ctime>

using namespace std;

void Game(int& Difficulty)
{
	int Code[3];
	int Answer[3];
	int Count = 3;
	char x;
	int CodeSum=0;
	int AnswerSum = 0;
	int CodeProduct = 0;

	for (int i = 0; i < 3; i++)		Code[i] = (rand() % 5 + Difficulty);
	for (int i = 0; i < 3; i++)		CodeSum += Code[i];
	CodeProduct = Code[0] * Code[1] * Code[2];

	cout << "LEVEL " << Difficulty << endl;
	cout << "SUM OF NUMBERS = " << CodeSum << "     PRODUCT OF NUMBERS = " << CodeProduct << endl;
	do {
		for (int i = 0; i < 3; i++) cin >> Answer[i];
		cin >> x;
		if (x == 'x' || x == 'X')
		{
			if (CodeSum == Answer[0] + Answer[1] + Answer[2] && CodeProduct == Answer[0] * Answer[1] * Answer[2])
			{
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
					{
						if (Code[i] == Answer[j]) Code[i] = Answer[j] = 0;
					}
				for (int i = 0; i < 3; i++)		AnswerSum += Answer[i];
				if (AnswerSum == 0)
				{
					cout << "Good job. You're going up!" << endl;
					Count = -1;
				}
				else
				{
					cout << "You are right, but this is not the code. You earn 1 more turn." << endl;
				}
			}
			else
			{
				cout << "You are mistaken." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				Count--;
			}
		}
		else
		{
			cout << "You failed to put correct code." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			Count--;
		}
	} while (Count > 0);
	if (Count == 0)
	{
		Difficulty = 11;
		cout << "Dragon woke up and ate you. Game over.";
	}
}

void Instructions()
{
	cout << "You're trying to reach princess Victoria locked in high tower guarded by a dragon." << endl;
	cout << "Every floor has a door which open only if you enter code made up from three numbers (order is not important)." << endl;
	cout << "You are given clues to guess right, but remember you have only 3 attempts." << endl;
	cout << "Each floor is harder to get to.  Write your answer and confirm with x (ex. 3 5 5 x). Good luck and dont wake the dragon!" << endl << endl;
}
int main()
{
	srand(time(NULL));
	
	int Diff = 1;
	const int MaxDiff = 10;
	Instructions();

	while (Diff <= MaxDiff)
	{
		Game(Diff);
		cin.clear();
		cin.ignore(1000, '\n');
		Diff++;
	}
	return 0;
}
