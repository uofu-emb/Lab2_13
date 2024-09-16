/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//include necessary dependancies
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

// count is used to determine the length the LED blinks on
//on is used for changing the LED state
int count = 0;
bool on = false;

//Here we define the task priority structure for the two tasks.
//Here the blink task has a higher priority
#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

//blink_task changes the LED state while also using a delay to delay the next LED change
void blink_task(__unused void *params) {
    hard_assert(cyw43_arch_init() == PICO_OK);
    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
        if (count++ % 11) on = !on;
        vTaskDelay(500);
    }
}
// the main_task is used to change the case of characters given to it. 
void main_task(__unused void *params) {
    //here we create the blink task to interrupt this task
    xTaskCreate(blink_task, "BlinkThread",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
    //here we listen for a character from the serial monitor
    char c;
    while(c = getchar()) {
        //if the character is lowercase change the ASCII code to be uppercase
        if (c <= 'z' && c >= 'a') putchar(c - 32);
        //if the character is uppercase change the ASCII code to be lowercase
        else if (c >= 'A' && c <= 'Z') putchar(c + 32);
        //if the character is not a letter do not change anything.
        else putchar(c);
    }
}

int main( void )
{
    stdio_init_all();
    //instantiate the RTOS
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    //create the main task
    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    //start the scheduler so the tasks can begin.
    vTaskStartScheduler();
    return 0;
}
