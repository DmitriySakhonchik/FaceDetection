// facedetector.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "facedetector.h"

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/types_c.h"

#include <iostream>

void detectFace(std::string imagePath)
{
	int delay = 5;

	// Load image
	cv::Mat image;
	image = cv::imread(imagePath);

	if (image.empty())
	{
		printf("No image in given path.\n");
	}
	else
	{
		cv::imshow("Original Image", image);
		cv::waitKey(delay);

		// Convert image into grayscale
		cv::Mat grayImage;
		cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

		// Load cascade
		cv::CascadeClassifier faceCascade = cv::CascadeClassifier("haarcascade_frontalface_default.xml");

		// Apply cascade
		std::vector<cv::Rect> faceVector;
		faceCascade.detectMultiScale(grayImage, faceVector, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

		//Draw rectangles
		double scale = 1;
		for (size_t i = 0; i < faceVector.size(); i++)
		{
			cv::Rect r = faceVector[i];

			// Draw rectangle on face
			/*cv::Scalar color = cv::Scalar(255, 0, 0);
			cv::Point point1 = cvPoint(cvRound(r.x*scale), cvRound(r.y*scale));
			cv::Point point2 = cvPoint(cvRound((r.x + r.width - 1)*scale), cvRound((r.y + r.height - 1)*scale));
			rectangle(image, point1, point2, color, 3, 8, 0);*/

			// Blur face
			cv::GaussianBlur(image(r), image(r), cv::Size(55, 55), 55);
		}

		if (faceVector.size() != 0)
		{
			// Resize image
			cv::resize(image, image, image.size() / 2);

			// Show result
			cv::imshow("Face Detection", image);
			cv::waitKey(delay);
		}

		// Show notification
		std::cout << std::endl << "Image path: " << imagePath << std::endl;
		std::cout << "Number of detected faces: " << faceVector.size() << std::endl;

		//Save result
		cv::imwrite("ImageWithFaceDetection1.jpg", image);
	}
}