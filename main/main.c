#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define PIR_INPUT 21
#define BUZZER_OUT 4

void app_main(void)
{
    gpio_set_direction(PIR_INPUT, GPIO_MODE_INPUT);
    gpio_set_direction(BUZZER_OUT, GPIO_MODE_OUTPUT);

    while (1)
    {
        int motion = gpio_get_level(PIR_INPUT);

        if (motion == 1)
        {
            printf("Motion detected\n");
            gpio_set_level(BUZZER_OUT, 1);
        }
        else
        {
            printf("Motion not detected\n");
            gpio_set_level(BUZZER_OUT, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}