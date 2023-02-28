/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Dio_ChannelType;

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
}Dio_PortType;

typedef enum
{
	Low,
	High
}Dio_LevelType;

typedef uint8 Dio_PortLevelType;

#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
