#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#pragma comment(lib, "Winmm.lib") //ADD "winmm.lib"
#include <queue>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define ONE_SECOND 1000
#define MAX_COL_SIZE 20
#define MAX_ROW_SIZE 40
int arr[MAX_COL_SIZE][MAX_ROW_SIZE] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};


void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int score = 0;
int snakeX = 2;
int snakeY = 1;
int starX, starY = 0;
int snakeLength[50][50] = { 0 };
int Best_score;
std::string userName;
int userScore;
//std::queue<std::queue<int>> snakeLength;
std::queue<std::pair<int, int>> snakeQueue;
//std::queue<int> snakeLengthY;
bool Compare(const  std::pair<std::string, int> &a, const  std::pair<std::string, int> &b)
{
	return a.second > b.second;
}
void star()
{
	bool canPlace = true;
	srand((unsigned int)time(NULL));
	while (canPlace)
	{

		starX = ((rand() % (MAX_COL_SIZE - 1))) * 2;
		starY = (rand() % (MAX_ROW_SIZE - 1) + 1);

		if (snakeLength[starY][starX / 2] == 1)
		{
			continue;
		}
		if (arr[starX / 2][starY] == 1)
		{
			continue;
		}
		else
		{
			break;
		}

	}
	gotoxy(starX, starY);
	printf("¡Û");
}
void GameOver()
{
	system("cls");
	gotoxy(10, 1);
	printf("+----------------------+");
	gotoxy(10, 2);
	printf("|       GAME OVER      |");
	gotoxy(10, 3);
	printf("+----------------------+");
	gotoxy(10, 5);
	printf("\n  Score : %d\n", score);
}
int main()
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	system(" mode  con lines=100   cols=100 ");
	system("cls");
	for (int i = 0; i < MAX_COL_SIZE; i++)
	{
		for (int j = 0; j < MAX_ROW_SIZE; j++)
		{
			gotoxy(i * 2, j);
			if (arr[i][j] == 1)
			{
				printf("¡á"); // Print the maze wall
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	std::ifstream fin;
	fin.open("ranking.txt");
	if (fin.fail())
	{
		printf("Can't define");
	}
	std::string line;
	std::vector<std::pair<std::string, int>> v;
	while (getline(fin, line))
	{
		char arr[100];
		int pos = line.find(' ');
		userName = line.substr(0, pos);
		userScore = stoi(line.substr(pos+1, line.size()-1));
		v.push_back({ userName, userScore });
		line.clear();
		
	}
	gotoxy(MAX_ROW_SIZE + 10, 2);
	std::cout << "Best Score: " << v[0].second << "(" << v[0].first << ")" << '\n';

	fin.close();

	srand((unsigned int)time(NULL)); // Random star loction
	starX = (rand() % (MAX_COL_SIZE - 1) + 1);
	starY = (rand() % (MAX_ROW_SIZE - 1) + 1);
	starX = 2;
	starY = 2;
	gotoxy(starX, starY);
	printf("¡Û");
	unsigned __int64 prevTime = GetTickCount();
	int direction = 0;	// 0 down, 1 right, 2 up, 3 left
	int bFirst = false;
	snakeQueue.push({ snakeX, snakeY });
	while (1)
	{
		gotoxy(snakeX, snakeY);
		printf("¡Ý");
		snakeLength[snakeY][snakeX / 2] = 1;

		bool canPlay = true;

		int tempX = snakeX;
		int tempY = snakeY;
		char szChoice = 0;

		if (kbhit())
		{
			szChoice = getch();

			switch (szChoice)
			{
			case 'w':
				if (direction != 0)
					direction = 2;
				break;
			case 'a':
				if (direction != 1)
					direction = 3;
				break;
			case 's':
				if (direction != 2)
					direction = 0;
				break;
			case 'd':
				if (direction != 3)
					direction = 1;
				break;
			}
		}
		unsigned __int64 curtime = GetTickCount();
		if (curtime - prevTime > 100)
		{

			int bErase = true;
			switch (direction)
			{
			case 2:
				tempY--;
				break;
			case 3:
				tempX -= 2;
				break;
			case 0:
				tempY++;
				break;
			case 1:
				tempX += 2;
				break;
			}

			if (arr[tempX / 2][tempY] == 0)
			{
				snakeX = tempX;
				snakeY = tempY;
				gotoxy(snakeX, snakeY);
				printf("¡Ý");
				if (snakeLength[snakeY][snakeX / 2] == 1) // if it's already 1
				{
					Sleep(100);
					GameOver();
					break;
				}
				snakeLength[snakeY][snakeX / 2] = 1;
				snakeQueue.push({ snakeX, snakeY });
				if (snakeX == starX && snakeY == starY) //when added items
				{
					score+=10;
					bErase = false;
					bFirst = true;
					star();
				}
				gotoxy(MAX_ROW_SIZE + 10, 5);
				printf("Score: %d\n", score);
				
			}

			if (tempX / 2 == 0 || tempY == 0 || tempX / 2 == MAX_COL_SIZE - 1 || tempY == MAX_ROW_SIZE - 1)
			{
				/*snakeX = tempX;
				snakeY = tempY;
				while (!snakeQueue.empty())
				{
					snakeQueue.pop();
				}*/
				Sleep(100);
				GameOver();
				break;
			}
			
			if (bErase)
			{
				int eraseX = snakeQueue.front().first;
				int eraseY = snakeQueue.front().second;
				gotoxy(eraseX, eraseY);
				printf("  ");
				snakeLength[eraseY][eraseX / 2] = 0;
				snakeQueue.pop();
			}
			

			/*if (snakeLength[tempY - 1][ tempX / 2 - 1] == 1)
			{
				Sleep(100);
				GameOver();
				return 0;
			}*/

			


			prevTime = GetTickCount();
		}


	}

	std::cout << "Enter your name: ";
	std::cin >> userName;
	
	bool hasName = false;
	for (int i = 0;i<v.size();i++)
	{
		if (v[i].first == userName)
		{
			if(v[i].second < score)
				v[i].second = score;
			hasName = true;
			break;
		}
	}
	if (!hasName)
	{
		v.push_back({ userName, score });
	}
	std::sort(v.begin(), v.end(), Compare);
	gotoxy(5, 10);
	printf("Top5 \n");
	for (int i = 0; i < 5; i++)
	{
		gotoxy(5, 12+i);
		std::cout << i+1<<" : "<<v[i].first << " " << v[i].second << "\n";
	}


	std::ofstream fout("ranking.txt");
	for (auto user : v)
	{
		fout << user.first << " " << user.second << '\n';
	}

	fout.close();
	return 0;
}




