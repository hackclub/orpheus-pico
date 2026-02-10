#include <stdio.h>
#include "pico/stdlib.h"
#include "Adafruit_NeoPixel.hpp"

const int NEOPIXEL = 24;

int gpios[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 26, 27, 28
};

int config_leds(void) {
    for(int i = 0; i < sizeof(gpios)/sizeof(gpios[0]); i++) {
        gpio_init(gpios[i]);
        gpio_set_dir(gpios[i], GPIO_OUT);
    }
    return PICO_OK;
}

int main()
{
    stdio_init_all();
    printf("configuring leds\n");
    int result = config_leds();
    hard_assert(result == PICO_OK);
    printf("leds configured, turning pins on\n");

    Adafruit_NeoPixel pixels(1, NEOPIXEL, NEO_GRB + NEO_KHZ800);
    pixels.begin();

    while (true) {
        for(int i = 0; i < sizeof(gpios)/sizeof(gpios[0]); i++) { //active low
            printf("turning on pin %d\n", gpios[i]);
            gpio_put(gpios[i], 0);
            if(gpios[i] == 23) {gpio_put(gpios[i], 1);}
            sleep_ms(150);
        }
        for(int i = 0; i < sizeof(gpios)/sizeof(gpios[0]); i++) {
            printf("turning off pin %d\n", gpios[i]);
            gpio_put(gpios[i], 1);
            if(gpios[i] == 23) {gpio_put(gpios[i], 0);}
            sleep_ms(300);
        }

        for (int i = 0; i < 10; ++i) {
            pixels.setPixelColor(0, pixels.Color((i%3)*150, ((i+1)%3)*150 ,((i+2)%3)*150));
            pixels.show();
            sleep_ms(300);
        }
    }

}
