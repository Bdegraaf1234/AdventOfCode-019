#include "ArcadeGame.h"
#include "Instruction.h"
#include <iostream>

void ArcadeGame::Init(IntCodeProcessor cpu)
{
	long long prevout = 0;
	int outcounter = 0;
	int tileInstructions[3];
	int prevxball = 0;
	int prevyball = 0;
	int xball = 0;
	int yball = 0;
	int xpaddle = 0;
	int ypaddle = 0;
	int xdir = 1;
	int ydir = -1;
	int ydist = 3;
	int move = 0;
	int exit = 0;
	while (1)
	{
		if (outcounter > 2)
		{
			outcounter = 0;
			if (tileInstructions[0] == -1 && tileInstructions[1] == 0)
			{
				DisplayScore(tileInstructions[2]);
				int blockCounter = CountRemainingBlocks();
				if (blockCounter == 0)
				{
					Display();
					exit = 1;
				}
				cout << blockCounter;
			}
			if (tileInstructions[2] == 4)
			{
				prevxball = xball;
				prevyball = yball;
				xball = tileInstructions[0];
				yball = tileInstructions[1];
				xdir = xball - prevxball;
				ydir = prevyball - yball;
				ydist = 23 - yball;
			}
			if (tileInstructions[2] == 3)
			{
				xpaddle = tileInstructions[0];
				ypaddle = tileInstructions[1];
			}
			Tile newTile = Tile(tileInstructions);
			Alter(newTile);
		}
		Instruction instruction = Instruction(cpu.Memory[cpu.Pointer], cpu.Pointer, prevout);
		bool write = instruction.Identifier == 4; 
		if (instruction.Identifier == 3)
		{
			//Display();
			/*cout << "move joystick:";
			char choice = ' ';*/
			if (1)//ydir == -1)
			{
				if (xball + (ydist * xdir) == xpaddle)
				{
					move = 0;
				}
				else if (xball + (ydist * xdir) > xpaddle)
				{
					move = 1;
				}
				else
				{
					move = -1;
				}
			}
			instruction.Input = move;
			/*while (isspace(choice))
			{
				choice = getchar();
			}
			
			if (choice == 'd')
			{
				instruction.Input = 1;
			}
			else if (choice == 'a')
			{
				instruction.Input = -1;
			}
			else
			{
				
			}*/
		}
		prevout = instruction.Execute(cpu.Memory, cpu.Pointer, cpu.RelativeBase, cpu.OutPath);
		if (write)
		{
			tileInstructions[outcounter] = prevout;
			outcounter++;
		}
	}
}

void ArcadeGame::Display()
{
	//TODO hardcoded size...?
	for (size_t y = 0; y < 26; y++)
	{
		for (size_t x = 0; x < 50; x++)
		{
			cout << Grid[y][x];
		}
		cout << "\n";
	}
	cout << "123456789012456789012345678901234567890\n";
}

void ArcadeGame::DisplayScore(int score)
{
	cout << "\n";
	cout << "SCORE:\n";
	cout << score;
	cout << "\n";
}

void ArcadeGame::Alter(Tile newTile)
{
	Grid[newTile.Y][newTile.X] = newTile.Id;
}

int ArcadeGame::CountRemainingBlocks() {
	int toreturn = 0;
	for (size_t y = 0; y < 26; y++)
	{
		for (size_t x = 0; x < 50; x++)
		{
			if (Grid[y][x] == 'D')
			{
				toreturn++;
			}
		}
	}
	return toreturn;
}
