/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: 6 de jul de 2019
 *      Author: Fernando
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"


/*
 * GPIO Driver
 * Fernando Kaba Surjus
 * Date: 06/07/2019
 * Description: GPIO Driver for STM32F446xx
 * API Functions: GPIO Initialization, EN/DI GPIO Clk, Read/Write Pin, Alternate Function, Interrupt Handling
 */


typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;				/*Values: @GPIO_PIN_MODES */
	uint8_t GPIO_PinSpeed;				/*Values: @GPIO_SPEED*/
	uint8_t GPIO_PinPuPdControl;		/*Values: @GPIO_PUPD*/
	uint8_t GPIO_PinOPType;				/*Values: @GPIO_OUTPUT_MODES*/
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * Handle Structure for GPIO pins
 */
typedef struct{
	GPIO_RegDef_t		*pGPIOX; /* This point will be used to hold the base address of the GPIO port */
	GPIO_PinConfig_t	GPIO_PinConfig;  /* This holds GPIO Pin settings */
}GPIO_Handle_t;


/*
 * @GPIO_PINS
 * GPIO Pins
 */
#define GPIO_PIN_0				0
#define GPIO_PIN_1				1
#define GPIO_PIN_2				2
#define GPIO_PIN_3				3
#define GPIO_PIN_4				4
#define GPIO_PIN_5				5
#define GPIO_PIN_6				6
#define GPIO_PIN_7				7
#define GPIO_PIN_8				8
#define GPIO_PIN_9				9
#define GPIO_PIN_10				10
#define GPIO_PIN_11				11
#define GPIO_PIN_12				12
#define GPIO_PIN_13				13
#define GPIO_PIN_14				14
#define GPIO_PIN_15				15



/*
 * @GPIO_PIN_MODES
 * GPIO Pin Modes configuration macros
 */

#define GPIO_MODE_IN			0
#define GPIO_MODE_OUT			1
#define GPIO_MODE_ALTFN			2	/* Alternate function mode*/
#define GPIO_MODE_ANALOG		3	/* Analog mode*/
#define GPIO_MODE_IT_FT			4	/*Interrupt mode Rising edge trigger */
#define GPIO_MODE_IT_RT			5	/*Interrupt mode Falling edge trigger */
#define GPIO_MODE_IT_RFT		6	/*Interrupt mode Rising-Falling edge trigger */

/*
 * @GPIO_OUTPUT_MODES
 * GPIO Pin Output types configuration macros
 */
#define GPIO_OP_TYPE_PP			0	/*Push pull */
#define GPIO_OP_TYPE_OD			1	/* Open Drain*/

/*
 * @GPIO_SPEED
 * GPIO Speed mode  configuration macros
*/

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3

/*
 * @GPIO_PUPD
 * GPIO Pull up and pull down mode configuration macros
*/
#define GPIO_NO_PUPD			0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2



/***********************************************************
 * APIS
 ***********************************************************/

/*
 * Peripheral clock
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnableDisable); /* First parameter is to select with peripheral (port) so we use base address */

/*
 * Init and De-Init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data management
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ config and handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnableDisable);
void GPIO_IRQHandling(uint8_t PinNumber);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);







#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
