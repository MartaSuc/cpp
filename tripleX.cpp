#include <iostream>
#include <ctime>

using namespace std;

void Game(int& difficulty)
{
	int code[3];
	int answer[3];
	int count = 3;
	char x;
	int sum=0;
	int sum2 = 0;
	int product = 0;

	for (int i = 0; i < 3; i++)		code[i] = (rand() % 5 + difficulty);
	for (int i = 0; i < 3; i++)		sum += code[i];
	product = code[0] * code[1] * code[2];

	cout << "LEVEL " << difficulty << endl;
	cout << "SUM OF NUMBERS = " << sum << "     PRODUCT OF NUMBERS = " << product << endl;
	do {
		for (int i = 0; i < 3; i++) cin >> answer[i];
		cin >> x;
		if (x == 'x' || x == 'X')
		{
			if (sum == answer[0] + answer[1] + answer[2] && product == answer[0] * answer[1] * answer[2])
			{
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
					{
						if (code[i] == answer[j]) code[i] = answer[j] = 0;
					}
				for (int i = 0; i < 3; i++)		sum2 += code[i];
				if (sum2 == 0)
				{
					cout << "Good job. You're going up!" << endl;
					count = -1;
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
				count--;
			}
		}
		else
		{
			cout << "You failed to put correct code." << endl;
			count--;
		}
	} while (count > 0);
	if (count == 0)
	{
		difficulty = 11;
		cout << "Dragon woke up and ate you. Game over.";
	}
}

int main()
{
	srand(time(NULL));
	cout << "You're trying to reach princess Victoria locked in high tower guarded by a dragon." << endl;
	cout << "Every floor has a door which open only if you enter code made up from three numbers (order is not important)." << endl;
	cout << "You are given clues to guess right, but remember you have only 3 attempts." << endl;
	cout << "Each floor is harder to get to.  Write your answer and confirm with x (ex. 3 5 5 x). Good luck and dont wake the dragon!" <<endl<<endl;

	int diff = 1;
	int maxdiff = 10;

	while (diff <= maxdiff)
	{
		Game(diff);
		cin.clear();
		cin.ignore(1000, '\n');
		diff++;
	}
	return 0;
}
