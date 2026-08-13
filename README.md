# ESP32 PIR Motion Buzzer

A simple **ESP32 embedded C project** that interfaces a PIR motion sensor with a buzzer using **ESP-IDF and FreeRTOS**.

## Project Overview

The ESP32 continuously reads the output of a PIR motion sensor.

* **Motion detected** → buzzer ON
* **No motion detected** → buzzer OFF

This project demonstrates basic GPIO interfacing and FreeRTOS task delay on the ESP32.

## Hardware

* ESP32 development board
* PIR motion sensor (e.g. HC-SR501)
* Buzzer
* Jumper wires

## Pin Connections

### PIR Sensor

| PIR Pin | ESP32    |
| ------- | -------- |
| VCC     | 5V / VIN |
| GND     | GND      |
| OUT     | GPIO 21  |

### Buzzer

| Buzzer       | ESP32  |
| ------------ | ------ |
| Positive (+) | GPIO 4 |
| Negative (-) | GND    |

> Make sure the buzzer is suitable for direct GPIO driving. For a higher-current buzzer, use a transistor or MOSFET driver.

## Program Flow

```text
PIR Sensor
    │
    │ OUT
    ▼
ESP32 GPIO 21
    │
    ▼
gpio_get_level()
    │
    ▼
Check sensor value
    │
    ├── 1 → Motion detected → GPIO 4 HIGH → Buzzer ON
    │
    └── 0 → No motion → GPIO 4 LOW → Buzzer OFF
```

## Software

* **Language:** Embedded C
* **Framework:** ESP-IDF
* **RTOS:** FreeRTOS
* **Microcontroller:** ESP32

## Main ESP-IDF Functions Used

```c
gpio_set_direction()
gpio_get_level()
gpio_set_level()
vTaskDelay()
```

### GPIO configuration

`gpio_set_direction()` configures a GPIO as an input or output.

```c
gpio_set_direction(PIR_INPUT, GPIO_MODE_INPUT);
gpio_set_direction(BUZZER_OUT, GPIO_MODE_OUTPUT);
```

### Reading the PIR

```c
int motion = gpio_get_level(PIR_INPUT);
```

This reads the digital state of GPIO 21.

### Controlling the buzzer

```c
gpio_set_level(BUZZER_OUT, 1);
```

sets GPIO 4 HIGH.

```c
gpio_set_level(BUZZER_OUT, 0);
```

sets GPIO 4 LOW.

### FreeRTOS delay

```c
vTaskDelay(pdMS_TO_TICKS(100));
```

The task waits for approximately 100 ms before checking the sensor again.



## How to Build and Flash

Open the project using ESP-IDF and run:

```bash
idf.py build
```

Flash the program:

```bash
idf.py flash
```

Monitor the serial output:

```bash
idf.py monitor
```

Or combine the operations:

```bash
idf.py build flash monitor
```

## Example Output

```text
Motion not detected
Motion not detected
Motion detected
Motion detected
Motion not detected
```

When motion is detected, the buzzer is activated.







