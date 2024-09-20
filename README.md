# Stepper Motor Control with Light Sensor and Buttons

## Author: Virakboth Hang
### Date: September 19 2024

## Description
This project controls a stepper motor using the AccelStepper library and a light sensor. The motor's position can be adjusted incrementally by pressing buttons, with the angle displayed via the Serial Monitor. The system features:
- **Increase button (Blue)**: Increments the motor angle by 1 degree (up to 180 degrees).
- **Decrease button (Red)**: Decrements the motor angle by 1 degree (down to 0 degrees).
- **Reset button (Black)**: Resets the motor to 0 degrees.
- **Light sensor**: Reads light intensity and adjusts values accordingly (currently for future use).

## Hardware Setup
- **Stepper Motor**: Connected to pins for direction and steps.
- **Buttons**: Wired to GPIO pins with internal pull-up resistors.
- **Light Sensor**: Connected to an analog pin for light intensity readings.

## Components
- ESP32/Arduino microcontroller
- Stepper motor driver
- Buttons (3: Increase, Decrease, Reset)
- Light sensor (e.g., LM393)
- Serial monitor for debugging

## Pin Connections (Can be modified)
| Component           | Pin Number |
|---------------------|------------|
| Light Sensor        | A0 (Pin 36)|
| Motor Direction Pin | GPIO 32    |
| Motor Step Pin      | GPIO 33    |
| Increase Button     | GPIO 21    |
| Decrease Button     | GPIO 22    |
| Reset Button        | GPIO 19    |

## Software Requirements
- Arduino IDE
- AccelStepper Library

## Usage
1. Upload the sketch to your ESP32 or compatible microcontroller.
2. Monitor the angle of the motor using the Serial Monitor.
3. Use the buttons to increase, decrease, or reset the motor's angle.
4. The light sensor is currently not used for any motor control but can be adapted for future applications.

## Future Improvements
- Add functionality to adjust the motor speed or angle based on light sensor readings.
- Implement additional feedback, such as LEDs or an LCD screen.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
