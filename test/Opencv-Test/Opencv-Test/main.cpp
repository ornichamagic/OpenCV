////
////  main.cpp
////  Opencv-Test
////
////  Created by Ornicha Choungaramvong on 1/8/2559 BE.
////  Copyright © 2559 Ornicha Choungaramvong. All rights reserved.
////
//
//
//
#include <iostream>
#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;
//
//int main(int argc, const char * argv[]) {
//
//    
//    cv::Mat image,dst;
//    image = cv::imread("/Users/Ornicha/Desktop/test/Opencv-Test/Opencv-Test/fruits.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
//    
//    if(! image.data )                              // Check for invalid input
//    {
//        std::cout <<  "Could not open or find the image" << std::endl ;
//        return -1;
//    }
//    
//    namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
//    imshow( "Display window", image );                   // Show our image inside it.
//    
//    dst = image.clone();
//    GaussianBlur( image, dst, Size( 15, 15 ), 0, 0 );
//    
//    namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
//    imshow( "Display", dst );                   // Show our image inside it.
//    
//    cv::waitKey(0);                                          // Wait for a keystroke in the window
//    return 0;
//}
///

char window_name[30] = "HSV Segmentation";
Mat src;



static void onMouse( int event, int x, int y, int f, void* ){
    //src = cv::imread("/Users/Ornicha/Desktop/test/Opencv-Test/Opencv-Test/fruits.jpg", CV_LOAD_IMAGE_COLOR);
    Mat image=src.clone();
    Vec3b rgb=image.at<Vec3b>(y,x);
    int B=rgb.val[0];
    int G=rgb.val[1];
    int R=rgb.val[2];
    
    Mat HSV;
    
    Mat RGB=image(Rect(x,y,1,1));
    cvtColor(RGB, HSV,CV_BGR2HSV);
    
    Vec3b hsv=HSV.at<Vec3b>(0,0);
    int H=hsv.val[0];
    int S=hsv.val[1];
    int V=hsv.val[2];
    
    char name[30];
    sprintf(name,"B=%d",B);
    putText(image,name, Point(150,40) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );
    
    sprintf(name,"G=%d",G);
    putText(image,name, Point(150,80) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );
    
    sprintf(name,"R=%d",R);
    putText(image,name, Point(150,120) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );
    
    sprintf(name,"H=%d",H);
    putText(image,name, Point(25,40) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );
    
    sprintf(name,"S=%d",S);
    putText(image,name, Point(25,80) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );
    
    sprintf(name,"V=%d",V);
    putText(image,name, Point(25,120) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );
    
    sprintf(name,"X=%d",x);
    putText(image,name, Point(25,300) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,0,255), 2,8,false );
    
    sprintf(name,"Y=%d",y);
    putText(image,name, Point(25,340) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,0,255), 2,8,false );
    
    if(S == 0)
    {
        if(V == 255)
        {
        cout << " Color: White" << endl;
        }
        else if(V == 0)
        {
            cout << " Color: Black" << endl;
        }
    }
    
    else if (H >= 0 && H <= 3)
    {
        cout << " Color: Red" << endl;
    }
    else if (H >= 4 && H <= 10)
    {
        cout << " Color: Red-Orange" << endl;
    }
    else if (H >= 11 && H <=12 )
    {
        cout << " Color: Orange" << endl;
    }
    else if (H >= 13 && H < 20)
    {
        cout << " Color: Orange-Brown" << endl;
    }
    else if (H >= 21 && H < 25)
    {
        cout << " Color: Orange-Yellow" << endl;
    }
    else if (H >= 26 && H < 30)
    {
        cout << " Color: Yellow" << endl;
    }
    else if (H >= 31 && H < 40)
    {
        cout << " Color: Yellow-Green" << endl;
    }
    else if (H >= 41 && H < 70)
    {
        cout << " Color: Green" << endl;
    }
    else if (H >= 71 && H < 85)
    {
        cout << " Color: Green-Cyan" << endl;
    }
    else if (H >= 86 && H < 100)
    {
        cout << " Color: Cyan" << endl;
    }
    else if (H >= 101 && H < 110)
    {
        cout << " Color: Cyan-Blue" << endl;
    }
    else if (H >= 111 && H < 130)
    {
        cout << " Color: Blue" << endl;
    }
    else if (H >= 131 && H < 140)
    {
        cout << " Color: Violet" << endl;
    }
    else if (H >= 141 && H < 160)
    {
        cout << " Color: Magenta" << endl;
    }
    else if (H >= 161 && H < 167)
    {
        cout << " Color: Magenta-Pink" << endl;
    }
    else if (H >= 168 && H < 175)
    {
        cout << " Color: Pink" << endl;
    }
    else if (H >= 176 && H < 177)
    {
        cout << " Color: Pink-Red" << endl;
    }
    else if (H >= 176 && H < 177)
    {
        cout << " Color: Pink-Red" << endl;
    }
    else if (H >= 178 && H < 180)
    {
        cout << " Color: Red" << endl;
    }

    
    
    //imwrite("hsv.jpg",image);
    imshow( window_name, image );
}



int main(){

    src = imread("/Users/MagicMagic/Desktop/OpenCV/image/pill2.jpg",1);

    imshow(window_name,src);
    setMouseCallback( window_name, onMouse, 0 );
    waitKey();  
}