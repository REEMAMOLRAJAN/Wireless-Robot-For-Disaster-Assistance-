//servo mail and gps



#include <ctime>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <wiringSerial.h>


#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;


#define PWM_SERVO     18      // this is PWM0, pin 12
#define LEFT          37      // manually calibrated values
#define RIGHT         125     // for the left, right and
#define CENTER        75      // center servo positions
#define PIR            5
#define MODE           17

int main(int, char**)
{
   int serial_port;
  char dat,buff[100],GGA_code[3];
   buff[0]='$';
buff[1]='G';buff[2]='P';
buff[3]='G';
buff[4]='G';
buff[5]='A';
buff[6]=',';
  unsigned char IsitGGAstring=0;
  unsigned int GGA_index=7;
  unsigned char is_GGA_received_completely = 0;
    
 //  VideoCapture cap(0); // open the default camera
 //  if(!cap.isOpened())  // check if we succeeded
 //   return -1;
    
   wiringPiSetupGpio();                  // use the GPIO numbering
   pinMode(PWM_SERVO, PWM_OUTPUT);       // the PWM servo
   pwmSetMode(PWM_MODE_MS);              // use a fixed frequency
   pwmSetRange(1000);                    // 1000 steps
   pwmSetClock(384);                     // gives 50Hz precisely
   pinMode(PIR, INPUT);
   pullUpDnControl(PIR, PUD_DOWN);  //pull up to 3.3V,make GPIO1 a stable level
   pinMode(MODE, OUTPUT);
   pullUpDnControl(MODE, PUD_DOWN);  //pull up to 3.3V,make GPIO1 a stable level
   digitalWrite(MODE, LOW);
   
   
  
   


while(1)
{
    
    
if(digitalRead(MODE) == 1)
{
if(digitalRead(PIR) == 1)
{

    for(int i=0; i<=3; i++)
    {

     if (i=1)
     { 
	 pwmWrite(PWM_SERVO, LEFT);
	 VideoCapture cap(0); // open the default camera
    Mat frame;
 
   cap >> frame; // get a new frame from camera
   //cvtColor(frame, edges, COLOR_BGR2GRAY);
// if(waitKey(30) >= 0) break;
  imwrite("test"+std::to_string(i) +".jpg", frame);
  cap.release();
cout<<"Opening Camera...0"<<endl;    
 sleep(3);
}

 if (i=2)
{ 
     pwmWrite(PWM_SERVO, RIGHT);
     VideoCapture cap(0); // open the default camera
  Mat frame;
  cap >> frame; // get a new frame from camera
    //cvtColor(frame, edges, COLOR_BGR2GRAY);
   //if(waitKey(30) >= 0) break;
   imwrite("test"+std::to_string(i) +".jpg", frame);
    cap.release();
cout<<"Opening Camera...1"<<endl;
 sleep(3);
}

 if (i=3)
{ 
     pwmWrite(PWM_SERVO, CENTER);
  VideoCapture cap(0); // open the default camera
  Mat frame;
   cap >> frame; // get a new frame from camera
    // cvtColor(frame, edges, COLOR_BGR2GRAY);
    //if(waitKey(30) >= 0) break;
imwrite("test"+std::to_string(i) +".jpg", frame);
cap.release();
cout<<"Opening Camera...2"<<endl;    

 sleep(3);






if ((serial_port = serialOpen ("/dev/ttyS0", 9600)) < 0)		/* open serial port */
 {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
   return 1 ;
 }

 if (wiringPiSetup () == -1)							/* initializes wiringPi setup */
  {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    return 1 ;
  }
 
  while(1)
{
	  
if ((serial_port = serialOpen ("/dev/ttyS0", 9600)) < 0) /* open serial port */
	{
		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
		return 1 ;
	}

 if (wiringPiSetup () == -1) /* initializes wiringPi setup */
	{
		fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
		return 1 ;
	}
 
 
if(serialDataAvail (serial_port) ) /* check for any data available on serial port */
	{
		dat = serialGetchar(serial_port); /* receive character serially */
			if(dat == '$')
			{
				IsitGGAstring = 0;
				GGA_index = 7;
			}
else if(IsitGGAstring ==1)
		{
		buff[GGA_index++] = dat;
		if(dat=='\r')
		is_GGA_received_completely = 1;
		}
else if(GGA_code[0]=='G' && GGA_code[1]=='G' && GGA_code[2]=='A')
		{
			IsitGGAstring = 1;
			GGA_code[0]= 0;
			GGA_code[0]= 0;
			GGA_code[0]= 0;
		}
else
	{
		GGA_code[0] = GGA_code[1];
		GGA_code[1] = GGA_code[2];
		GGA_code[2] = dat;
	}
 }
if(is_GGA_received_completely==1)


{
for (int ii=0;ii<1;ii++)
{
		printf("%s",buff);
		is_GGA_received_completely = 0;
}
fstream file;
file.open("gps.txt",ios::out);
file << buff;
file.close();
system("cat Message.txt gps.txt > Final.txt");
system("sendemail -f disasterrobot@gmail.com -t lino.msamuel@gmail.com -u Distress Signal Orginated Please Respond Immediatly -o message-file=Final.txt -s smtp.googlemail.com:587 -xu disasterrobot@gmail.com -xp Group2jlr -o tls=yes");
digitalWrite(MODE, LOW);
break;

}
}
}
}
}

}
else 
{
    
    
     VideoCapture capture(0); 
 
  // Check if camera opened successfully
  if(!capture.isOpened())
  {
    cout << "Error opening video stream" << endl; 
    return -1; 
  } 
 
  // Default resolution of the frame is obtained.The default resolution is system dependent. 
  int frame_width = capture.get(CV_CAP_PROP_FRAME_WIDTH); 
  int frame_height = capture.get(CV_CAP_PROP_FRAME_HEIGHT); 
    while(1)
    {
    cout<<"camera mode"<<endl;
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
  cout<<"After break1"<<endl;
  if(digitalRead(MODE) == 1)
  {
      cout<<"After break2"<<endl;
    break; 
    cout<<"After break3"<<endl;
  }
}
 
}


}


return 0;
}





