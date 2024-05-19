#include <Servo.h>







/*************************************************************



  Download latest Blynk library here:



    https://github.com/blynkkk/blynk-library/releases/latest







  Blynk is a platform with iOS and Android apps to control



  Arduino, Raspberry Pi and the likes over the Internet.



  You can easily build graphic interfaces for all your



  projects by simply dragging and dropping widgets.



  Blynk library is licensed under MIT license



  This example code is in public domain.







 *************************************************************



  This example runs directly on ESP8266 chip.







  Note: This requires ESP8266 support package:



    https://github.com/esp8266/Arduino







  Please be sure to select the right ESP8266 module



  in the Tools -> Board menu!







  Change WiFi ssid, pass, and Blynk auth token to run :)



  Feel free to apply it to any other example. It's simple!



 *************************************************************/







/* Comment this out to disable prints and save space */



#define BLYNK_PRINT Serial







/* Fill-in your Template ID (only if using Blynk.Cloud) */



//#define BLYNK_TEMPLATE_ID   "YourTemplateID"







#define BLYNK_TEMPLATE_ID "TMPL3Q_IpzsoY"
#define BLYNK_TEMPLATE_NAME "Robotic Arm"
#define BLYNK_AUTH_TOKEN "A-llNZzwdJx7tgR6uSh1V0nrhOJbae-D"

#include <ESP8266WiFi.h>



#include <BlynkSimpleEsp8266_SSL.h>







// You should get Auth Token in the Blynk App.



// Go to the Project Settings (nut icon).



char auth[] = "A-llNZzwdJx7tgR6uSh1V0nrhOJbae-D";







// Your WiFi credentials.



// Set password to "" for open networks.



char ssid[] = "Realme 11 Pro";



char pass[] = "";







int M1PWM = D6; //GPIO12



Servo servo1;



Servo servo2;



Servo servo3;



Servo servo4;



Servo servo5;







BLYNK_WRITE(V1)







{







  int pinValue1 = param.asInt(); // assigning incoming value from pin V1 to a variable







  analogWrite(M1PWM,pinValue1);







  Blynk.virtualWrite(V1, pinValue1);







  Serial.print("V1 Slider value is: ");







  Serial.println(pinValue1);







}







BLYNK_WRITE(V2){



  servo1.write(param.asInt());



}







BLYNK_WRITE(V3){



  servo2.write(param.asInt());



}





BLYNK_WRITE(V4){



  servo3.write(param.asInt());



}



BLYNK_WRITE(V5){



  servo4.write(param.asInt());



}



BLYNK_WRITE(V6){



  servo5.write(param.asInt());



}



void setup()



{



  // Debug console



  Serial.begin(9600);

  servo1.attach(D0);

  servo2.attach(D1);

  servo3.attach(D2);

  servo4.attach(D3);

  servo5.attach(D4);



  pinMode (M1PWM,OUTPUT);

  pinMode (D0,OUTPUT);

  pinMode (D1,OUTPUT);

  pinMode (D2,OUTPUT);

  pinMode (D3,OUTPUT);

  pinMode (D4,OUTPUT);

  



  Blynk.begin(auth, ssid, pass);



}







void loop()



{



  Blynk.run();



}