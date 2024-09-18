#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include "blinky_switchCaseFunction.h"

/**
 * This function will take a char and switch its case.
 * It will ignore special characters.
 */

char switch_case_char(char c)
{
        //if the character is lowercase change the ASCII code to be uppercase
        if (c <= 'z' && c >= 'a') return(c - 32);
        //if the character is uppercase change the ASCII code to be lowercase
        else if (c >= 'A' && c <= 'Z') return(c + 32);
        //if the character is not a letter do not change anything.
        else return(c);
}

/**
 * This code controls the blinking of the LED
 */
bool blink_LED(bool on, int *count)
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
    *count += 1;
    return *count % 11 ? !on : on;
}