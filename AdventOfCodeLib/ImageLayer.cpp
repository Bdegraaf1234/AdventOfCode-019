#include "ImageLayer.h"
#include <iostream>
#include <fstream>

ImageLayer ImageLayer::Decode(vector<ImageLayer> layers) {
	int width = layers[0].Width;
	int height = layers[0].Height;
	int contentSize = width * height;
	int numLayers = layers.size();
	// use top layer as outlayer
	vector<int> outLayer = layers[0].Content;

	for (int i = 1; i < numLayers; i++)
	{
		for (size_t j = 0; j < contentSize; j++)
		{
			//only change if transparent
			if (outLayer[j] == 2)
			{
				outLayer[j] = layers[i].Content[j];
			}
		}
	}
	return ImageLayer(height, width, outLayer);
}

void ImageLayer::Print() {
	int xpos = 0;
	for (size_t i = 0; i < Content.size(); i++)
	{
		if (xpos == Width)
		{
			xpos = 0;
			cout << "\n";
		}
		if (Content[i] == 0 || Content[i] == 2)
		{
			std::cout << "  ";
		}
		if (Content[i] == 1)
		{
			std::cout << "\xDB\xDB";
		}
		xpos++;
	}
}

void ImageLayer::Print(string path) {

	ofstream fout;

	fout.open(path, ios::app);

	int xpos = 0;
	for (size_t i = 0; i < Content.size(); i++)
	{
		if (xpos == Width)
		{
			xpos = 0;
			fout << "\n";
			cout << "\n";
		}
		if (Content[i] == 0 || Content[i] == 2)
		{
			fout << "  ";
			std::cout << "  ";
		}
		if (Content[i] == 1)
		{
			std::cout << "\xDB\xDB";
			fout << "\xDB\xDB";
		}
		xpos++;
	}
}