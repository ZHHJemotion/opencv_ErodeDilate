//
//  main.cpp
//  opencv_erode&dilate
//
//  Created by ZHHJemotion on 2016/10/14.
//  Copyright � 2016�� Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    VideoCapture cap(0);
    if(!cap.isOpened()){
        return -1;
    }
    Mat frame;
    
    while(true){
        cap>>frame;
        imshow("��ǰ��Ƶ", frame);
        if(waitKey(30) >= 0) break;
    }
    
    return 0;
}
