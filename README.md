# 2440Controller
## Based on nRF52840 architecture (M4 chip)

### Summary
For the final project of ECEN 2400, Nayef, Luke, and I wanted to create a retro game controller that utlized wireless communication since most retro controllers use wires due to hardware limitations of old systems. With this in mind, we would have to use the controller on a emulator on PC that way we could communicate through bluetooth.
This controller was created using the Sparkfun nRF52840 mini breakbout board. It has 5 face buttons including 2 side triggers on the rear side. It communicates with a slave over BLE and UART. ADC for the thumbstick is still in Progress
To communicate with the PC, we would have to program an arduino based board (ESP32, Arduino Micro w/BLE module, etc) to connect with our nRF over BLE and decipher the characteristics being sent from the nRF. By doing this through arduino, we would be able to utilize libraries that already work with the PC to give it controller inputs
