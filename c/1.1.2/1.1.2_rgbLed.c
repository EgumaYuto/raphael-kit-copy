#include <softPwm.h>
#include <stdio.h>
#include <wiringPi.h>
#define uchar unsigned char
#define LedPinRed 0
#define LedPinGreen 1
#define LedPinBlue 2

void ledInit(void) {
    softPwmCreate(LedPinRed, 0, 100);
    softPwmCreate(LedPinGreen, 0, 100);
    softPwmCreate(LedPinBlue, 0, 100);
}

void ledColorSet(uchar r_val, uchar g_val, uchar b_val) {
    softPwmWrite(LedPinRed, r_val);
    softPwmWrite(LedPinGreen, g_val);
    softPwmWrite(LedPinBlue, b_val);
}

int main(void) {
    if (wiringPiSetup() == -1) {
        printf("setup wiringPi failed !");
        return 1;
    }

    ledInit();
    while (1) {
        printf("Red\n");
        ledColorSet(0xff, 0x00, 0x00);
        delay(500);

        printf("Green\n");
        ledColorSet(0x00, 0xff, 0x00);
        delay(500);

        printf("Blue\n");
        ledColorSet(0x00, 0x00, 0xff);
        delay(500);

        printf("Yellow\n");
        ledColorSet(0xff, 0xff, 0x00);
        delay(500);

        printf("Purple\n");
        ledColorSet(0x00, 0xff, 0xff);
        delay(500);

        printf("Cyan\n");
        ledColorSet(0xc0, 0xff, 0x3e);
        delay(500);

        printf("White\n");
        ledColorSet(0xff, 0xff, 0xff);
        delay(500);
    }
    return 0;
}