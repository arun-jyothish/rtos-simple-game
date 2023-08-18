# RTOS simple game


## Simple rtos game using FRDM K64 to test reflex

## Expected Working
+ Enter command in console. when start command received game starts.
+ when stop command receives game stops.
+ when user press button at wrong time, that user lose game. game ends
+ when game ends red led glows   
+ user score is displayed in console anytime when game stop
+ when game starts red led off & randomly light up blue and green led's 

## Milestone
+ create requirements document
+ create multiple tasks in rtos
+ create random function for led blink   
+ create design document
+ implement design in MCU express
+ verify implementation

## Unit Test

* increment delay for testing

### case 1:
+ Two players press switches when corresponding colours on (say 3 times), then press switch off
	inference:
		wrong press stops game and print score.
		score is tested for each person, score will be incremented for right press( for 3 presses ).
