#include <Arduino.h>
#include <avr/interrupt.h>
#include <ADC.h>
#include <LED.h>
#include <7segment.h>

int main() {
    #ifdef __DEBUG__
        dbg_start();
    #endif
    int x;
    int y;
    char text[30];
    LED_init();

    while (1) {

        sprintf(text, "X: %d, Y: %d\n", x, y);
    }
}
