// FaceDetectorApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "facedetector.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid command call. ";
		std::cout << "Specify image location." << std::endl;
	}
	else
	{
		std::string imagePath = argv[1];
		detectFace(imagePath);

		std::cout << std::endl << "Press any key to exit...";
		std::cin.get();
	}

	return 0;
}
