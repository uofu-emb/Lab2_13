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
     //loop through the entire alphabet and make sure case gets switched.
     for (int i=0; i<26; i++) {
          TEST_ASSERT_EQUAL_MESSAGE(resultChar, switch_case_char(inputChar),"Lower case to upper case failed");
          printf("\ninputChar %c",inputChar);
          printf("\nresultChar %c",resultChar);

          resultChar ++;
          inputChar ++;
     }
     printf("\n");

}

void testUpperToLowerCase(void)
{
     char resultChar = 'a';
     char inputChar = 'A';
     //loop through the entire alphabet and make sure case gets switched
     for (int i=0; i<26; i++) {
          TEST_ASSERT_EQUAL_MESSAGE(resultChar, switch_case_char(inputChar),"Lower case to upper case failed");
          printf("\ninputChar %c",inputChar);
          printf("\nresultChar %c",resultChar);

          resultChar ++;
          inputChar ++;
     }
     printf("\n");
}

void testLongSentence()
{    
     //test a long sentence with special characters and make sure everything changes as expected.
     char sentence[] = "This is a Long Sentence. This Will Test The Program!@#$%^&*()_+";
     char sentence1[] = "tHIS IS A lONG sENTENCE. tHIS wILL tEST tHE pROGRAM!@#$%^&*()_+";
     for (int i = 0; sentence[i] != '\0'; i++) {
          TEST_ASSERT_EQUAL_MESSAGE(sentence1[i], switch_case_char(sentence[i]),"Long sentence failed");
    }

}

void testOnState(void)
{
     //calls the blink function and makes sure the stated of the LED changes at the right time.
     hard_assert(cyw43_arch_init() == PICO_OK);
     bool on_state = 0;
     int counter = 0;
     while (counter<10){
          printf("\nState %d", on_state);
          printf("\nCounter %d\n", counter);
          TEST_ASSERT_EQUAL_MESSAGE(!on_state,blink_LED(on_state,&counter),"State toggled early.");
     }
     TEST_ASSERT_EQUAL_MESSAGE(on_state,blink_LED(on_state,&counter),"State not toggled");

}

int main (void)
{
    stdio_init_all();
    sleep_ms(20000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(testLowerToUppercase);
    RUN_TEST(testUpperToLowerCase);
    RUN_TEST(testLongSentence);
    RUN_TEST(testOnState);
    sleep_ms(10000);
    return UNITY_END();
}
