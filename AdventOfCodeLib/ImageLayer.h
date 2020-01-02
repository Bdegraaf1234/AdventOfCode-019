#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <string>
#include <vector>

class ADVENTOFCODELIB_API ImageLayer {
public:
	ImageLayer(int height, int width, vector<int> content) {
		Width = width;
		Height = height;
		Content = content;
	}
	int Width;
	int Height;
	vector<int> Content;
	static ImageLayer Decode(vector<ImageLayer> layers);
	void Print();
	void Print(string path);
};