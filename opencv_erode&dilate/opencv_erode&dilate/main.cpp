//
//  main.cpp
//  opencv_erode&dilate
//
//  Created by ZHHJemotion on 2016/10/14.
//  Copyright � 2016�� Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <string>

using namespace cv;
using namespace std;

#define PATH string("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test8/opencv_erode&dilate/opencv_erode&dilate/")


// ---------------------------- global variables declaration section -------------------------
//    Describe: global variables declaration ȫ�ֱ���
// ----------------------------------------------------------------------------------------
Mat srcImage, dstImage; // ԭͼ��Ч��ͼ
int trackbarNumber = 0; // 0 ��ʾ��ʴ erode��1��ʾ���� dilate
int structElementSize = 3; // �ṹԪ��(�ں˾���)�ĳߴ�


// ---------------------------- global function declaration section -----------------------
//    Describe: global function declaraion ȫ�ֺ���
// ---------------------------------------------------------------------------------------
void process(); // ���ͺ͸�ʴ�Ĵ�����
void onTrackBarNumberChange(int, void *); // callback function
void onElementSizeChange(int, void *); // callback function


// --------------------------- main() function ---------------------------------

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    system("color 5E"); // change the color of the console
    
    //read image
    srcImage = imread(PATH+string("1.jpg"),1);
    //exception handling
    if (!srcImage.data) {
        printf("error: there is a error so we can't read the iamge 1.jpg");
        return false;
    }
    
    // show the original image
    namedWindow("ԭʼͼ");
    imshow("ԭʼͼ", srcImage);
    
    //
    
    return 0;
}



