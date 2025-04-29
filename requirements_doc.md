# Requirements Document

## Functional Requirements:
- This software will detect motion from the digital input using a PIR motion sensor.
- This software will also activate a 4 channel relay module that is connected to the water pump when motion is detected.
- The software will keep the pumo for a fixed duration of 5 seconds afer the motion is detected.
- The software will make sure that pump will remain off when motion is not detected
- The software will print status messages such as when motion is detected and the pump is on through the serial monitor.
# Non-Functional Requirements;
- This system will work in indoor or outdoor lighting and conditions
- It will utilize all components and give real time feedback through the serial monitor
- The system will avoid false triggerings through delays.
- This system can be readable and maintainable for changes or upgrades in the future.
# Acceptance Criteria:
- When motion is detected the pump will active and remain on for 5 seconds.
- After the 5 second duration it will turn off immediatly.
- When motion is not detected the pump will remain off.
- The product will be triggered again once it is activated after 5 seconds upon triggering.
