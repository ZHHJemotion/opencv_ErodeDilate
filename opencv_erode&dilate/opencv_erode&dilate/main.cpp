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
int trackbarNumber = 1; // 0 ��ʾ��ʴ erode��1��ʾ���� dilate
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
    
    //system("color 5E"); // change the color of the console
    
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
    
    // ���г��θ�ʴ��������ʾЧ��ͼ
    namedWindow("Ч��ͼ");
    // ����Զ����
    Mat element = getStructuringElement(MORPH_RECT, Size(2*structElementSize+1, 2*structElementSize+1),Point(structElementSize, structElementSize));
    erode(srcImage, dstImage, element);
    imshow("Ч��ͼ",  dstImage);
    
    // create a TrackBar
    createTrackbar("��ʴ/����", "Ч��ͼ", &trackbarNumber, 1, onTrackBarNumberChange);
    createTrackbar("�ں˳ߴ�", "Ч��ͼ", &structElementSize, 21, onElementSizeChange);
    
    // output some helpful information
    cout<<endl<<"\t "
            <<""
            <<"\n by ZHHJemotion";
    //
    while (char(waitKey(1))!='q') {}
    
    
    
    
    // ==============================================================================================
    // doing the erode and dilate operation without using TrackBar �����޹켣���ĸ�ʴerode������dilate����
    // ==============================================================================================
    Mat image = imread(PATH+string("1.jpg"),1);
    namedWindow("original image");
    imshow("original image", image); // ����Ϊ���벢��ʾԭͼ
    
    Mat outErode, outDilate; // ��ʴ���������
    
    Mat element1 = getStructuringElement(MORPH_RECT, Size(7,7));
    erode(image, outErode, element1); // ��ʴ����
    dilate(image, outDilate, element1); // ���Ͳ���
    
    namedWindow("destination iamge of erode"); // ��ʾ��ʴЧ��ͼ
    imshow("destination iamge of erode", outErode);
    
    namedWindow("destination iamge of dilate"); // ��ʾ����Ч��ͼ
    imshow("destination iamge of dilate", outDilate);
    
    waitKey(0);
    
    
    
    
    
    return 0;
}


// ---------------------------- process() function --------------------------------
//    Describe: �����Զ���ĸ�ʴ�����Ͳ���
// --------------------------------------------------------------------------------
void proces()
{
    // ��ȡ�Զ����
    Mat element = getStructuringElement(MORPH_RECT, Size(2*structElementSize+1, 2*structElementSize+1), Point(structElementSize, structElementSize));
    
    // ���и�ʴor ���Ͳ���
    if (trackbarNumber == 0) {
        erode(srcImage, dstImage, element);
    }
    else
    {
        dilate(srcImage, dstImage, element);
    }
    
    // show the result of erode or dilate operation
    imshow("Ч��ͼ", dstImage);
}


// ------------------------- onTrackBarNumberChange() funtion ---------------------------
//    Describe: ��ʴ������֮���л����صĻص�����
// --------------------------------------------------------------------------------------
void onTrackBarNumberChange(int, void *)
{
    // ��ʴ������֮��Ч���Ѿ��л����ص��������������һ�� process �������Ǹı���Ч��������Ч����ʾ����
    proces();
}


// ------------------------- onElementSizeChange() function -----------------------------
//    Describe: ��ʴ�����Ͳ����ں˸ı�ʱ�Ļص�����
// --------------------------------------------------------------------------------------
void onElementSizeChange(int, void *)
{
    // �ں˳ߴ��Ѿ��ı䣬�ص��������������һ�� process �������Ǹı���Ч��������Ч����ʾ����
    proces();
}




