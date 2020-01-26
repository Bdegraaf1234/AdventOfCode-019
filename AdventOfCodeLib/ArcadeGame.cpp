#include "ArcadeGame.h"
#include "Instruction.h"
#include <iostream>

void ArcadeGame::Init(IntCodeProcessor cpu)
{
	long long prevout = 0;
	int outcounter = 0;
	int tileInstructions[3];

	while (1)
	{
		if (outcounter > 2)
		{
			outcounter = 0;
			if (tileInstructions[0] == -1 && tileInstructions[1] == 0)
			{
				DisplayScore(tileInstructions[2]);
			}
			Tile newTile = Tile(tileInstructions);
			Alter(newTile);
		}
		Instruction instruction = Instruction(cpu.Memory[cpu.Pointer], cpu.Pointer, prevout);
		bool write = instruction.Identifier == 4; 
		if (instruction.Identifier == 3)
		{
			Display();
			cout << "move joystick:";
			char choice = ' ';

			while (isspace(choice))
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
				instruction.Input = 0;
			}
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
