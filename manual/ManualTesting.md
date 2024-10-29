This is a document that covers how to test the hello_freertos.c

# tasks
There are two tasks seen in this program. The first is a blink task and the second is a main task.

# Main task
This main task is the focus of the program after using the Serial monitor and reading the code it appears that the device is takes in a character and flips the case of it. To test this functionality it is important to test all characters both lower and upder case and ensure that it changes cases properly. It would also be important to test words and characters next to each other to make sure it still works. Finally it is important to test the special characters as those should be unchanged.