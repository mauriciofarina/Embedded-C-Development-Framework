/**
 * @file mid_gpio.h
 * @author Mauricio Dall Oglio Farina
 * @brief GPIO Middleware Interface
 */
#ifndef __MID_GPIO_H__
#define __MID_GPIO_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief GPIO Pins
 */
typedef enum {

    // Outputs
    MID_GPIO_LED_0 = 0, /** LED 0 */
    MID_GPIO_LED_1,     /** LED 1 */
    MID_GPIO_LED_2,     /** LED 2 */

    // Inputs
    MID_GPIO_BUTTON_0, /** Button 0 */
    MID_GPIO_BUTTON_1, /** Button 1 */
    MID_GPIO_BUTTON_2, /** Button 2 */

} mid_gpio_pin_t;

/**
 * @brief Get GPIO Pin State
 *
 * @param pin[in] Pin
 *
 * @return true High
 * @return false Low
 */
bool mid_gpio_get_pin(mid_gpio_pin_t pin);

/**
 * @brief Set GPIO Pin State
 *
 * @param pin[in] Pin
 * @param enable[in] Enable/Disable (High/Low) Pin
 */
void mid_gpio_set_pin(mid_gpio_pin_t pin, bool enable);

#endif
