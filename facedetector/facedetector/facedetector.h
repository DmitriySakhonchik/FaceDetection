#pragma once

#include <iostream>

#ifdef FACEDETECTOR_EXPORTS
#define FACEDETECTOR_API __declspec(dllexport)
#else
#define FACEDETECTOR_API __declspec(dllimport)
#endif

extern "C" FACEDETECTOR_API void detectFace(std::string imagePath);