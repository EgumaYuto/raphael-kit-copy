#include <stdio.h>
#include <wiringPi.h>

int pins[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void oddLedBarGraph(void) {
    for (int i = 0; i < 5; i++) {
        int j = i * 2;
        digitalWrite(pins[j], HIGH);
        delay(300);
        digitalWrite(pins[j], LOW);
    }
}

void evenLedBarGraph(void) {
    for (int i = 0; i < 5; i++) {
        int j = i * 2 + 1;
        digitalWrite(pins[j], HIGH);
        delay(300);
        digitalWrite(pins[j], LOW);
    }
}

void allLedBarGraph(void) {
    for (int i = 0; i < 10; i++) {
        digitalWrite(pins[i], HIGH);
        delay(300);
        digitalWrite(pins[i], LOW);
    }
}

int main(void) {
    if (wiringPiSetup() == -1) {
        printf("setup wiringPi failed !");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], LOW);
    }

    while (1) {
        oddLedBarGraph();
        delay(300);
        evenLedBarGraph();
        delay(300);
        allLedBarGraph();
        delay(300);
    }
    return 0;
}