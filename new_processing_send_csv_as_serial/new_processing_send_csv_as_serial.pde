/* TextFile Sender: Written by Scott C on 5th April 2013
 using Processing Version 2.0b8 */

import processing.serial.*;

Serial comPort;
int counter=0; // Helps to keep track of values sent.
int numItems=0; //Keep track of the number of values in text file
boolean sendStrings=false; //Turns sending on and off
StringLoader sLoader; //Used to send values to Arduino

void setup(){
 comPort = new Serial(this, Serial.list()[0], 9600);
 background(255,0,0); //Start with a Red background
}

void draw(){
  while (comPort.available() > 0) {
    int inByte = comPort.read();

  }
}


void mousePressed() {
 //Toggle between sending values and not sending values
 sendStrings=!sendStrings;
 
 //If sendStrings is True - then send values to Arduino
 if(sendStrings){
 background(0,255,0); //Change the background to green
 
 /*When the background is green, transmit
 text file values to the Arduino */
 sLoader=new StringLoader();
 sLoader.start();
 
 }else{
 background(255,0,0); //Change background to red
 //Reset the counter
 counter=0;
 }
}



/*============================================================*/
/* The StringLoader class imports data from a text file
 on a new Thread and sends each value once every half second */
public class StringLoader extends Thread{
 
 public StringLoader(){
 //default constructor
 }
 
 public void run() {
 //String textFileLines[]=loadStrings("C:/Users/klyap_000/Documents/ones.txt");
 //String textFileLines[]=loadStrings("C:/Users/klyap_000/Documents/sampleData.txt");
 //String textFileLines[]=loadStrings("C:/Users/klyap_000/Documents/finaltwinned.txt");
 //String textFileLines[]=loadStrings("C:/Users/klyap_000/Documents/mergedfinal.txt");
 String textFileLines[]=loadStrings("C:/Users/klyap_000/Documents/9threshmerged.txt");
 //String textFileLines[]=loadStrings("C:/Users/klyap_000/Documents/GitHub/ArduinoVisualization/oneline.txt");
 
 String lineItems[]=splitTokens(textFileLines[0], ",");
 numItems=lineItems.length;
 System.out.println(numItems);
 int num = 0;
 //while(true){
 //counter = 0;
 for(int i = counter; i<numItems; i++){
 comPort.write(lineItems[i]);
 //comPort.write('1');
 //System.out.println("sent " + lineItems[i]);
 delay(5);
 if (i % 310 == 0) {
   num = num + 1;
   System.out.println("$$$$$$$$$$ # of 155's " + num + " $$$$$$$$$$");  
   delay(100);

 }
 //delay(500);
 //comPort.write("0");
 //System.out.println("sent 0");
 
 }
 counter=numItems;
 }
 //}// while
}

