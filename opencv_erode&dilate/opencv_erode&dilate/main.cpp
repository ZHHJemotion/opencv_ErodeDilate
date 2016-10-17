//
//  main.cpp
//  opencv_erode&dilate
//
//  Created by ZHHJemotion on 2016/10/14.
//  Copyright ý 2016Äê Lukas_Zhang. All rights reserved.
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
//    Describe: global variables declaration È«¾Ö±äÁ¿
// ----------------------------------------------------------------------------------------
Mat srcImage, dstImage; // Ô­Í¼ºÍÐ§¹ûÍ¼
int trackbarNumber = 1; // 0 ±íÊ¾¸¯Ê´ erode£¬1±íÊ¾ÅòÕÍ dilate
int structElementSize = 3; // ½á¹¹ÔªËØ(ÄÚºË¾ØÕó)µÄ³ß´ç


// ---------------------------- global function declaration section -----------------------
//    Describe: global function declaraion È«¾Öº¯Êý
// ---------------------------------------------------------------------------------------
void process(); // ÅòÕÍºÍ¸¯Ê´µÄ´¦Àíº¯Êý
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
    namedWindow("Ô­Ê¼Í¼");
    imshow("Ô­Ê¼Í¼", srcImage);
    
    // ½øÐÐ³õ´Î¸¯Ê´²Ù×÷²¢ÏÔÊ¾Ð§¹ûÍ¼
    namedWindow("Ð§¹ûÍ¼");
    // »ñµÃ×Ô¶¨ÒåºË
    Mat element = getStructuringElement(MORPH_RECT, Size(2*structElementSize+1, 2*structElementSize+1),Point(structElementSize, structElementSize));
    erode(srcImage, dstImage, element);
    imshow("Ð§¹ûÍ¼",  dstImage);
    
    // create a TrackBar
    createTrackbar("¸¯Ê´/ÅòÕÍ", "Ð§¹ûÍ¼", &trackbarNumber, 1, onTrackBarNumberChange);
    createTrackbar("ÄÚºË³ß´ç", "Ð§¹ûÍ¼", &structElementSize, 21, onElementSizeChange);
    
    // output some helpful information
    cout<<endl<<"\t "
            <<""
            <<"\n by ZHHJemotion";
    //
    while (char(waitKey(1))!='q') {}
    
    
    
    
    // ==============================================================================================
    // doing the erode and dilate operation without using TrackBar ½øÐÐÎÞ¹ì¼£ÌõµÄ¸¯Ê´erodeºÍÅòÕÍdilate²Ù×÷
    // ==============================================================================================
    Mat image = imread(PATH+string("1.jpg"),1);
    namedWindow("original image");
    imshow("original image", image); // ÒÔÉÏÎªÔØÈë²¢ÏÔÊ¾Ô­Í¼
    
    Mat outErode, outDilate; // ¸¯Ê´ÓëÅòÕÍÊä³ö
    
    Mat element1 = getStructuringElement(MORPH_RECT, Size(7,7));
    erode(image, outErode, element1); // ¸¯Ê´²Ù×÷
    dilate(image, outDilate, element1); // ÅòÕÍ²Ù×÷
    
    namedWindow("destination iamge of erode"); // ÏÔÊ¾¸¯Ê´Ð§¹ûÍ¼
    imshow("destination iamge of erode", outErode);
    
    namedWindow("destination iamge of dilate"); // ÏÔÊ¾ÅòÕÍÐ§¹ûÍ¼
    imshow("destination iamge of dilate", outDilate);
    
    waitKey(0);
    
    
    
    
    
    return 0;
}


// ---------------------------- process() function --------------------------------
//    Describe: ½øÐÐ×Ô¶¨ÒåµÄ¸¯Ê´ºÍÅòÕÍ²Ù×÷
// --------------------------------------------------------------------------------
void proces()
{
    // »ñÈ¡×Ô¶¨ÒåºË
    Mat element = getStructuringElement(MORPH_RECT, Size(2*structElementSize+1, 2*structElementSize+1), Point(structElementSize, structElementSize));
    
    // ½øÐÐ¸¯Ê´or ÅòÕÍ²Ù×÷
    if (trackbarNumber == 0) {
        erode(srcImage, dstImage, element);
    }
    else
    {
        dilate(srcImage, dstImage, element);
    }
    
    // show the result of erode or dilate operation
    imshow("Ð§¹ûÍ¼", dstImage);
}


// ------------------------- onTrackBarNumberChange() funtion ---------------------------
//    Describe: ¸¯Ê´ÓëÅòÕÍÖ®¼äÇÐ»»¿ª¹ØµÄ»Øµ÷º¯Êý
// --------------------------------------------------------------------------------------
void onTrackBarNumberChange(int, void *)
{
    // ¸¯Ê´ÓëÅòÕÍÖ®¼äÐ§¹ûÒÑ¾­ÇÐ»»£¬»Øµ÷º¯ÊýÌåÄÚÐèµ÷ÓÃÒ»´Î process º¯Êý£¬ÊÇ¸Ä±äºóµÄÐ§¹ûÁ¢¼´ÉúÐ§²¢ÏÔÊ¾³öÀ´
    proces();
}


// ------------------------- onElementSizeChange() function -----------------------------
//    Describe: ¸¯Ê´ÓëÅòÕÍ²Ù×÷ÄÚºË¸Ä±äÊ±µÄ»Øµ÷º¯Êý
// --------------------------------------------------------------------------------------
void onElementSizeChange(int, void *)
{
    // ÄÚºË³ß´çÒÑ¾­¸Ä±ä£¬»Øµ÷º¯ÊýÌåÄÚÐèµ÷ÓÃÒ»´Î process º¯Êý£¬ÊÇ¸Ä±äºóµÄÐ§¹ûÁ¢¼´ÉúÐ§²¢ÏÔÊ¾³öÀ´
    proces();
}




