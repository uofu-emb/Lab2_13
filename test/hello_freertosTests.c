#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "blinky_switchCaseFunction.h"

void setUp(void) {}

void tearDown(void) {}

void testLowerToUppercase()
{
     char resultChar = 'A';
     char inputChar = 'a';

     for (int i=0; i<26; i++) {
          TEST_ASSERT_EQUAL_MESSAGE(resultChar, switch_case(inputChar),"Lower case to upper case failed");
          printf("\ninputChar %s",inputChar);
          printf("\nresultChar %s",resultChar);

          resultChar ++;
          inputChar ++;
     }

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
