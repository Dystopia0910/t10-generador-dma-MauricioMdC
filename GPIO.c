/**
 * @file
 * @brief
 * This is the source file for the MVC device driver for Kinetis K64.
 * It contains some configuration functions and runtime functions.
 * It is implemented using CMSIS Core functions.
 *
 * @authors: Mauricio Martin Del Campo
 * @date 02/10/2024
 *
 * @todo
 *
 */

#include "GPIO.h"

void GPIO_config(void)
{
    gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
    };

    const port_pin_config_t push_button = {
        kPORT_PullUp,              // Internal pull-up resistor is enabled
        kPORT_FastSlewRate,        // Fast slew rate is configured
        kPORT_PassiveFilterDisable,// Passive filter is disabled
        kPORT_OpenDrainDisable,    // Open drain is disabled
        kPORT_HighDriveStrength,   // High drive strength is configured
        kPORT_MuxAsGpio,           // Pin is configured as PTA4
        kPORT_UnlockRegister       // Pin Control Register fields [15:0] are not locked
    };

    CLOCK_EnableClock(kCLOCK_PortC);
    PORT_SetPinConfig(PORTC, bit_6, &push_button);
    GPIO_PinInit(GPIOC, bit_6, &sw_config);
    PORT_SetPinInterruptConfig(PORTC, bit_6, kPORT_DMAFallingEdge); // Se utiliza para transferencias DMA

    CLOCK_EnableClock(kCLOCK_PortA);
    PORT_SetPinConfig(PORTC, bit_4, &push_button);
    GPIO_PinInit(GPIOC, bit_4, &sw_config);
    PORT_SetPinInterruptConfig(PORTC, bit_4, kPORT_DMAFallingEdge);
}

