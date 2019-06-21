# Wireless-Robot-For-Disaster-Assistance-
gps.cpp/
..

//servo mail and gps



#include <ctime>
#include <fstream>
#include <iostream>
#include <unistd.h>
//#include <raspicam/raspicam.h>
#include <wiringPi.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <errno.h>
#include <wiringSerial.h>

//#include "opencv2/opencv.hpp"

//using namespace cv;
using namespace std;


#define PWM_SERVO     18      // this is PWM0, pin 12

#define LEFT          37      // manually calibrated values
#define RIGHT         125     // for the left, right and
#define CENTER        75      // center servo positions

int main(int, char**)
{
      int serial_port; 
  char dat,buff[100],GGA_code[3];
  unsigned char IsitGGAstring=0;
  unsigned char GGA_index=0;
  unsigned char is_GGA_received_completely = 0;
    
    

   wiringPiSetupGpio();                  // use the GPIO numbering
   pinMode(PWM_SERVO, PWM_OUTPUT);       // the PWM servo
   pwmSetMode(PWM_MODE_MS);              // use a fixed frequency
   pwmSetRange(1000);                    // 1000 steps
   pwmSetClock(384);                     // gives 50Hz precisely

//    VideoCapture cap(0); // open the default camera
  //  if(!cap.isOpened())  // check if we succeeded
    //    return -1;
   // Mat edges;
   // namedWindow("edges",1);

    for(int i=0; i<=3; i++)
    {

     if (i=1)
     { 
	 pwmWrite(PWM_SERVO, LEFT);
     //Mat frame;
    // cap >> frame; // get a new frame from camera
    // cvtColor(frame, edges, COLOR_BGR2GRAY);
//     if(waitKey(30) >= 0) break;
    // imwrite("test"+std::to_string(i) +".jpg", frame);
cout<<"Opening Camera...0"<<endl;    
 sleep(3);
}

 if (i=2)
{ 
     pwmWrite(PWM_SERVO, RIGHT);
   //  Mat frame;
    // cap >> frame; // get a new frame from camera
    // cvtColor(frame, edges, COLOR_BGR2GRAY);
    // if(waitKey(30) >= 0) break;
    // imwrite("test"+std::to_string(i) +".jpg", frame);
    

cout<<"Opening Camera...1"<<endl;
 sleep(3);
}

 if (i=3)
{ 
     pwmWrite(PWM_SERVO, CENTER);
   //  Mat frame;
    // cap >> frame; // get a new frame from camera
    // cvtColor(frame, edges, COLOR_BGR2GRAY);
    // if(waitKey(30) >= 0) break;
    // imwrite("test"+std::to_string(i) +".jpg", frame);
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
	  
		if(serialDataAvail (serial_port) )		/* check for any data available on serial port */
		  { 
			dat = serialGetchar(serial_port);		/* receive character serially */		
			if(dat == '$'){
				IsitGGAstring = 0;
				GGA_index = 0;
			}
			else if(IsitGGAstring ==1){
				buff[GGA_index++] = dat;
				if(dat=='\r')
					is_GGA_received_completely = 1;
				}
			else if(GGA_code[0]=='G' && GGA_code[1]=='G' && GGA_code[2]=='A'){
				IsitGGAstring = 1;
				GGA_code[0]= 0; 
				GGA_code[0]= 0;
				GGA_code[0]= 0;		
				}
			else{
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
file.open("Hello.txt",ios::out);
file << buff;
file.close();
system("sendemail -f disasterrobot@gmail.com -t lino.msamuel@gmail.com -u Distress Signal Orginated Please Respond Immediatly -o message-file=Hello.txt -s smtp.googlemail.com:587 -xu disasterrobot@gmail.com -xp Group2jlr -o tls=yes");
break;
}




}

	return 0;
    
}
}


}





