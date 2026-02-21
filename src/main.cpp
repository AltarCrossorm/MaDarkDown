
#include "constants.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

#include "metadata.hpp"

using namespace std;



int main(int argc, char* argv[])
{
	ifstream sourceFile;
	ifstream styleFile;
	Metadata md;
	string fileCursor;
	

	if (argc > 1)
		sourceFile.open(argv[1]);

	if (argc > 2)
		styleFile.open(argv[2]);

	if (!sourceFile.is_open()) {
		cout << "Source file is not found." << endl;
		exit(to_underlying(ExitValue::ERR_FILE_NOT_FOUND));
	}

	/* 
	check if first line is "---" 
	if yes then
		loadMetadata()
	then check line by line :
		text, and only text
	*/

	getline(sourceFile,fileCursor); // get first line

	if(fileCursor == "---") // if the source contains metadata
	{
		cout << "file has metadata !" << endl;
		md.generateMetadata(&sourceFile);
	}
	else
	{
		cout << "no metadata to record" << endl;
		sourceFile.seekg(0, ios::beg);
	}
	
	while (sourceFile.eof())
	{
		getline(sourceFile,fileCursor);

	}
	

	sourceFile.close();
	styleFile.close();
	
	return 0;
}