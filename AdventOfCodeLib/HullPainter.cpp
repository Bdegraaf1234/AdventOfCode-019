#include "HullPainter.h"

#include <string>
#include <fstream>
#include <iterator>
#include <iostream>

void HullPainter::Turn(bool clockWise)
{
	if (clockWise)
	{
		Direction++;
	}
	else
	{
		Direction--;
	}
	if (Direction == -1)
	{
		Direction = 3;
	}
	else if (Direction == 4)
	{
		Direction = 0;
	}
}

bool HullPainter::Move(bool outColor, bool clockWise)
{
	Grid[XCoordinate][YCoordinate] = outColor;
	if (Painted[XCoordinate].end() == find(Painted[XCoordinate].begin(), Painted[XCoordinate].end(), YCoordinate))
	{
		Painted[XCoordinate].push_back(YCoordinate);
		NumPainted++;
	}
	Turn(clockWise);
	if (Direction == 0)
	{
		YCoordinate++;
	}
	else if (Direction == 1)
	{
		XCoordinate++;
	}
	else if (Direction == 2)
	{
		YCoordinate--;
	}
	else if (Direction == 3)
	{
		XCoordinate--;
	}
	return Grid[XCoordinate][YCoordinate];
}

int HullPainter::Run(IntCodeProcessor processor, bool input)
{
	int newColor = processor.RunUntilFirstOutputForceInput(input);
	int clockWise = processor.RunUntilFirstOutputForceInput({});
	while (1) {
		bool oldColor = Move(newColor, clockWise);
		newColor = processor.RunUntilFirstOutputForceInput(oldColor);
		if (newColor == -1337)
		{
			return NumPainted;
		}
		clockWise = processor.RunUntilFirstOutputForceInput({});
		if (clockWise == -1337)
		{
			return NumPainted;
		}
	}
}

void HullPainter::WriteOut(string path)
{
	std::ofstream output_file(path, std::ios::app);
	std::ostream_iterator<long long> output_iterator(output_file, ",");
	for (size_t x = 0; x < sizeof(*Grid) / sizeof(**Grid); ++x)
	{
		for (size_t y = 0; y < sizeof(Grid) / sizeof(*Grid); ++y) {
			if (Grid[x][y]) {
				output_file << "X";
			}
			else
			{
				output_file << " ";
			}
		}
		output_file << "\n";
	}
}
