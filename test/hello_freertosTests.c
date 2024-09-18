#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "hello_freertos.h"

void setUp(void) {}

void tearDown(void) {}

void testLowerToUppercase()
{
     //fill in
    int x = 1;
    TEST_ASSERT_TRUE_MESSAGE(x == 1,"Variable assignment failed.");
}

void testUpperToLowerCase(void)
{
     //fill in
}

void testLongSentence()
{
     //fill in

}

void testSpecialCharacters()
{
     //fill in
}

int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(testLowerToUppercase);
    RUN_TEST(testUpperToLowerCase);
    RUN_TEST(testLongSentence);
    RUN_TEST(testSpecialCharacters);

    sleep_ms(5000);
    return UNITY_END();
}
