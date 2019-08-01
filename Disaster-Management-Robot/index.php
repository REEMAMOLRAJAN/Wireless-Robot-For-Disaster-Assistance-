<html>
<head>
<meta name="viewport" content="width=device-width" />
<title>Disaster Assistance Robot</title>
</head>
       <body style="background:url(https://www.pixelstalk.net/wp-content/uploads/2016/08/Funny-Robot-Wallpaper.jpg);background-repeat:no-repeat;background-size:100% 100%">
       <center><h1>Disaster Assistance Robot Rasberry pi</h1>      
         <form method="get" action="index.php">                
	 <input type="submit" style = "font-size: 14 pt" value="FORWARD" name="forward"> <h1>                
         <input type="submit" style = "font-size: 14 pt" value="        LEFT        " name="left">
         <input type="submit" style = "font-size: 14 pt" value="     STOP     " name="stop">  
         <input type="submit" style = "font-size: 14 pt" value="        RIGHT        " name="right"> <h1>
         <input type="submit" style = "font-size: 14 pt" value="REVERSE" name="reverse">
</head>
       <body>
       <center><h1>Servo control</h1>      
         <form method="get" action="index.php">                
	 <input type="submit" style = "font-size: 14 pt" value="LEFTSERVO" name="leftservo" > 
         <input type="submit" style = "font-size: 14 pt" value="CENTERSERVO" name="rightservo">
         <input type="submit" style = "font-size: 14 pt" value="RIGHTSERVO" name="centerservo">
</head>
       <body>
       <center><h1>PIR/CAMERA/SendMail</h1>      
         <form method="get" action="index.php">                
	 <input type="submit" style = "font-size: 14 pt" value="PIR-MODE" name="pir-mode" >
	<input type="submit" style = "font-size: 14 pt" value="CAMERA-MODE" name="camera-mode">
         <input type="submit" style = "font-size: 14 pt" value="SEND-EMAIL" name="send-email">   



<?php
    shell_exec("/usr/local/bin/gpio -g mode 18 pwm");
    shell_exec("/usr/local/bin/gpio -g pwm-ms");
    shell_exec("/usr/local/bin/gpio -g pwmc 384");
     shell_exec("/usr/local/bin/gpio -g pwmr 1000");


    shell_exec("/usr/local/bin/gpio -g mode 13 out");
    shell_exec("/usr/local/bin/gpio -g mode 17 out");
    shell_exec("/usr/local/bin/gpio -g mode 19 out");
    shell_exec("/usr/local/bin/gpio -g mode 26 out");
    shell_exec("/usr/local/bin/gpio -g mode 16 out");
    shell_exec("/usr/local/bin/gpio -g mode 20 out");
    shell_exec("/usr/local/bin/gpio -g mode 21 out");
    shell_exec("/usr/local/bin/gpio -g write 13 1");
    shell_exec("/usr/local/bin/gpio -g write 16 1");
//------------------------------------------------FORWARD MOVEMENT-------------------------------------------------
     if(isset($_GET['forward']))
        {
                       // echo "Robot moved Forward";
                        shell_exec("/usr/local/bin/gpio -g write 19 0");
                        shell_exec("/usr/local/bin/gpio -g write 26 1");
			shell_exec("/usr/local/bin/gpio -g write 21 1");
			shell_exec("/usr/local/bin/gpio -g write 20 0");
			
			shell_exec("sleep 0.5s");
                        shell_exec("/usr/local/bin/gpio -g write 19 0");
                        shell_exec("/usr/local/bin/gpio -g write 26 0");
                        shell_exec("/usr/local/bin/gpio -g write 21 0");
                        shell_exec("/usr/local/bin/gpio -g write 20 0");
        }
//---------------------------------------------REVERSE MOVEMENT-----------------------------------------------
            else if(isset($_GET['reverse']))
            {
                        //echo "Robot moved Reverse";
                        shell_exec("/usr/local/bin/gpio -g write 19 1");
         		shell_exec("/usr/local/bin/gpio -g write 26 0");
			shell_exec("/usr/local/bin/gpio -g write 21 0");
			shell_exec("/usr/local/bin/gpio -g write 20 1");
              		
			  shell_exec("sleep 0.5s");
    			 shell_exec("/usr/local/bin/gpio -g write 19 0");
                        shell_exec("/usr/local/bin/gpio -g write 26 0");
                        shell_exec("/usr/local/bin/gpio -g write 21 0");
                        shell_exec("/usr/local/bin/gpio -g write 20 0"); 
            }

//---------------------------------------LEFT MOVEMENT-------------------------------------------------------
            else if(isset($_GET['left']))
            {
                	// echo "Robot moved to left";
			shell_exec("/usr/local/bin/gpio -g write 19 1");
			shell_exec("/usr/local/bin/gpio -g write 26 0");
			shell_exec("/usr/local/bin/gpio -g write 20 0");
			shell_exec("/usr/local/bin/gpio -g write 21 1");

			shell_exec("sleep 0.2s");
                        shell_exec("/usr/local/bin/gpio -g write 19 0");
                        shell_exec("/usr/local/bin/gpio -g write 26 0");
                        shell_exec("/usr/local/bin/gpio -g write 20 0");
                        shell_exec("/usr/local/bin/gpio -g write 21 0");


            }
//-----------------------------------------RIGHT MOVEMENT---------------------------------------------------------
            else if(isset($_GET['right']))
            {
                       // echo "Robot moved right";
			shell_exec("/usr/local/bin/gpio -g write 19 0");
			shell_exec("/usr/local/bin/gpio -g write 26 1");
			shell_exec("/usr/local/bin/gpio -g write 20 1");
			shell_exec("/usr/local/bin/gpio -g write 21 0");

			shell_exec("sleep 0.2s");
                        shell_exec("/usr/local/bin/gpio -g write 19 0");
                        shell_exec("/usr/local/bin/gpio -g write 26 0");
                        shell_exec("/usr/local/bin/gpio -g write 20 0");
                        shell_exec("/usr/local/bin/gpio -g write 21 0");


            }

//----------------------------------------------STOP--------------------------------------------------------------
            else if(isset($_GET['stop']))
            {
                     // echo "Robot Stopped";
                        shell_exec("/usr/local/bin/gpio -g write 19 0");
                        shell_exec("/usr/local/bin/gpio -g write 26 0");
			shell_exec("/usr/local/bin/gpio -g write 20 0");
			shell_exec("/usr/local/bin/gpio -g write 21 0");
            }

//--------------------------------------------SERVO LEFT----------------------------------------------------------

else if(isset($_GET['leftservo']))
            {
                    
                        shell_exec("/usr/local/bin/gpio -g pwm 18 125");
                        
            }
//------------------------------------------SERVO RIGHT----------------------------------------------------------
else if(isset($_GET['rightservo']))
            {
                       
                        shell_exec("/usr/local/bin/gpio -g pwm 18 75");
            }
//-----------------------------------------SERVO CENTER-----------------------------------------------------------

else if(isset($_GET['centerservo']))
            {
                      
                        shell_exec("/usr/local/bin/gpio -g pwm 18 37");
            }
//---------------------------------------------------pir-mode----------------------------------------------

else if(isset($_GET['pir-mode']))
           {

                       shell_exec("/usr/local/bin/gpio -g write 17 1");
                       shell_exec("/usr/local/bin/gpio -g write 27 0");
           }
//------------------------------------------CAMERA-MODE----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

else if(isset($_GET['camera-mode']))
           {

                       shell_exec("/usr/local/bin/gpio -g write 17 0");
                       shell_exec("/usr/local/bin/gpio -g write 27 1");
           }

//---------------------------------------------------------SEND-EMAIL----------------------------------------------------------------------------------------
else if(isset($_GET['send-email']))
           {

                       shell_exec("/usr/local/bin/gpio -g write 22 1");
           }




?>
 </body>
</html>




