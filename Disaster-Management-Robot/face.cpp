#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
   
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

using namespace std;
using namespace cv;


#define MODE           17


int main( )
{
   // Load Face cascade (.xml file)
    //   CascadeClassifier face_cascade;
      // face_cascade.load( "haarcascade_frontalface_alt.xml" );
 wiringPiSetupGpio(); 
pinMode(MODE, OUTPUT);
   pullUpDnControl(MODE, PUD_DOWN);  //pull up to 3.3V,make GPIO1 a stable level
   digitalWrite(MODE, LOW);      
 
 VideoCapture capture(0);  
     
    while(1)
     { 
       Mat image; 
       capture >> image;  
       
 
      // Detect faces
      //std::vector<Rect> faces;
      //face_cascade.detectMultiScale( image, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
   
      // Draw circles on the detected faces
      //for( int i = 0; i < faces.size(); i++ )
     // {
       // Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        //ellipse( image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
      //}
       
  imshow( "Detected Face", image );
  waitKey(1);  
  cvDestroyWindow("window");
  if(digitalRead(MODE) == 1)
  {
    break; 
  }
  
  
}  
                
     return 0;
}
