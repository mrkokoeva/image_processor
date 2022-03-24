cmake_minimum_required(VERSION 3.21)
project(image_processor)

set(CMAKE_CXX_STANDARD 14)

add_executable(image_processor main.cpp BMPReader.cpp BMPReader.h BMPWriter.cpp BMPWriter.h Color.cpp Color.h CropFilter.cpp CropFilter.h EdgeDetectionFilter.cpp EdgeDetectionFilter.h Filter.cpp Filter.h GaussianBlurFilter.cpp GaussianBlurFilter.h GrayScaleFilter.cpp GrayScaleFilter.h Image.cpp Image.h NegativeFilter.cpp NegativeFilter.h SharpeningFilter.cpp SharpeningFilter.h)
