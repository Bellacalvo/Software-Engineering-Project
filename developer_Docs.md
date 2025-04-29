# Project Overview
This project is a motion activated water pump system that uses an Arduino. It will read an input from the PIR motion sensor and then a relay will power on the water dump for a fized duration.
# Design Diagram
![Blank diagram](https://github.com/user-attachments/assets/209799d8-e8c7-49d9-a5c5-9beff86e478e)
# Code Breakdown
For this code I did not have mutiple files or libraries.
1. setup()
   - In this function I initialized all the input and output pins. I ensured that the relay is initially off and a I run a calibration looop for the motion sensor to "warm up"
2. loop()
   - The loop will always check for motion. If motion is detected and not triggered the relay will be activated which will turn on the water pump. During this time it will keep the pump on for 5 seconds. Once the 5 seconds is exceeded the relay will deactivate and turn the water pump off, reset the trigger state, and will being detecting motion again
3. Configurations
   - motionSensorPin: pin number connected to the sensor
   - relayPin: pin number connected to the relay
   - blockDuration: pump will stay on for x seconds
   - calibrationTime: time to wait for sensor to warm up.
