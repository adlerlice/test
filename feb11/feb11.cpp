#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;
int main()
{
	std::ifstream ifs("file.txt");


	in.seekg(0, in.end);

	int n = in.tellg();// размер файла

	in.seekg(0);

	char* text = new char[n];
	for (int i = 0; i != n; i++) {
		char s;
		if (in.get(s)) {
			text[i] = s;
		}
	}
	cout << text;





}