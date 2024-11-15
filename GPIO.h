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

#ifndef GPIO_H_
#define GPIO_H_

#include "bits.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

void GPIO_config(void);

#endif /* GPIO_H_ */
