#include <stdio.h>
#include <wiringPi.h>
#define SDI 0
#define RCLK 1
#define SRCLK 2

// 7-segent display に、 1-9,A-F を表示させるためのデータ
unsigned char SegCode[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                             0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

void init(void) {
    pinMode(SDI, OUTPUT);
    pinMode(RCLK, OUTPUT);
    pinMode(SRCLK, OUTPUT);
    digitalWrite(SDI, 0);
    digitalWrite(RCLK, 0);
    digitalWrite(SRCLK, 0);
}

void hc595_shift(unsigned char dat) {
    int i;
    for (i = 0; i < 8; i++) {
        digitalWrite(SDI, 0x80 & (dat << i));  // 書き込むビットを取り出す
        digitalWrite(SRCLK,
                     1);  // Clock が UP するタイミングでレジスタにinputされる
        delay(1);
        digitalWrite(SRCLK, 0);  // 次のビットを書き込むための準備
    }
    digitalWrite(RCLK, 1);  // レジスタの状態をメモリに書き込む
    delay(1);
    digitalWrite(RCLK, 0);  // 次のデータを書き込むための準備
}

int main(void) {
    int i;
    if (wiringPiSetup() == -1) {
        printf("setup wiringPi failed !");
        return 1;
    }

    init();

    while (1) {
        for (i = 0; i < 16; i++) {
            printf("Print %1X on Segment\n", i);
            hc595_shift(SegCode[i]);
            delay(3000);
        }
    }

    return 0;
}