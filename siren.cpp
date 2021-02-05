#include "mbed.h"
// In your board, PB_8 corresponds to pin D15
//declaring functions from mbed.h
PwmOut speaker(PB_8);
InterruptIn mybutton(USER_BUTTON);

volatile float delay = 4.0; //declares variable delay to be 4
volatile bool Pressedornot=false; //sets Pressedornot to boolean value false

void pressed() //function that checks if the event of the button being pressed has occurred
{
    if (Pressedornot==false) //if Pressedornot is false, set it to true if the button is pressed
        Pressedornot=true;
    else
        Pressedornot=false; 
}

int main()//main function of type int
{
 //declares the variables needed
 int freq1=1200; //sets frequncy of tone 1 to be 1200
 int freq2=700; //sets frequency of tone 2 to be 700
 float delay=.5; //sets delay to be 0.5
 
 mybutton.fall(&pressed); //checks if the button is being pressed

     while(1){ //infinity loop
          if(Pressedornot==true){ //if the button is pressed
            // two tone effect -  two periods or two frequencies
            // increase volume - by changing the PWM duty cycle
            speaker.period(1.0/freq1);  //sets period of tone 1 
            speaker = 3/50.0; 
            wait(delay); //waits for 4 ms
            speaker.period(1.0/freq2); //sets period of tone 2
            wait(delay); //waits for 4 ms
        }
    }
}
