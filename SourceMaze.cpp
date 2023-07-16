#include<iostream>
#include<fstream>
#include"HeaderMAZE.h"
using namespace std;



char** maze;
int main()
{
	ifstream input("MAZE.txt");
	
	char row='0';
	char col='0';
	char r, c;
	char data='0';
	int count = 1;

	while (!input.eof())
	{
		input >> data;
	
		if (data >= '0' && data <= '9')
		{
			if (count == 1)
			{
				row = data;
				row = row - 48;
				++count;
			}
			else if (count == 2)
			{
				col = data;
				col = col - 48;
				maze = new char* [row];
				cout << "ROWS " << row << "\nCOLS " << col << endl;
				for (int r = 0; r < row; r++)
				{
					maze[r] = new char[col];
				}
				count++;

				for (int r = 0; r < row; r++)
				{
					for (int c = 0; c < col; c++)
					{
						maze[r][c]=' ';
					}
					cout << endl;
				}	
				maze[0][0] = 'S';
				maze[col-1][col-1] = 'E';

			}
			else if (count == 3)
			{
				cout << "no of hurdles " << data << endl;
				++count;
			}

			else
			{
				if (count % 2 == 0)
				{
					cout << "row " << data << " ";
					r = data;
					++count;
				}
				else
				{
					cout << "col " << data << "\n";
					c = data;
					++count;
					maze[r - 48][c - 48] = '1';
				}
			}
		}
	}

	input.close();
	find_path(maze,row,col);

	
	return 0;
}
