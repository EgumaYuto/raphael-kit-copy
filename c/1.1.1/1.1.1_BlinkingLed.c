#include <wiringPi.h>
#include <stdio.h>
#define LedPin  0

int main(void) {
    if (wiringPiSetup() == -1) {
        printf("setup wiringPi failed !");
        return 1;
    }

    pinMode(LedPin, OUTPUT);
    
    while (1) {
        digitalWrite(LedPin, LOW);
        printf("..LED on\n");
        delay(500);

        digitalWrite(LedPin, HIGH);
        printf("..LED off\n");
        delay(500);
    }
}