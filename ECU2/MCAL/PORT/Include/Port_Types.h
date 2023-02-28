/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 Port_PinType;

#define PORT_PIN_A0              ((Port_PinType)00)
#define PORT_PIN_A1              ((Port_PinType)01)
#define PORT_PIN_A2              ((Port_PinType)02)
#define PORT_PIN_A3              ((Port_PinType)03)
#define PORT_PIN_A4              ((Port_PinType)04)
#define PORT_PIN_A5              ((Port_PinType)05)
#define PORT_PIN_A6              ((Port_PinType)06)
#define PORT_PIN_A7              ((Port_PinType)07)

#define PORT_PIN_B0              ((Port_PinType)08)
#define PORT_PIN_B1              ((Port_PinType)09)
#define PORT_PIN_B2              ((Port_PinType)10)
#define PORT_PIN_B3              ((Port_PinType)11)
#define PORT_PIN_B4              ((Port_PinType)12)
#define PORT_PIN_B5              ((Port_PinType)13)
#define PORT_PIN_B6              ((Port_PinType)14)
#define PORT_PIN_B7              ((Port_PinType)15)

#define PORT_PIN_C0              ((Port_PinType)16)
#define PORT_PIN_C1              ((Port_PinType)17)
#define PORT_PIN_C2              ((Port_PinType)18)
#define PORT_PIN_C3              ((Port_PinType)19)
#define PORT_PIN_C4              ((Port_PinType)20)
#define PORT_PIN_C5              ((Port_PinType)21)
#define PORT_PIN_C6              ((Port_PinType)22)
#define PORT_PIN_C7              ((Port_PinType)23)

#define PORT_PIN_D0              ((Port_PinType)24)
#define PORT_PIN_D1              ((Port_PinType)25)
#define PORT_PIN_D2              ((Port_PinType)26)
#define PORT_PIN_D3              ((Port_PinType)27)
#define PORT_PIN_D4              ((Port_PinType)28)
#define PORT_PIN_D5              ((Port_PinType)29)
#define PORT_PIN_D6              ((Port_PinType)30)
#define PORT_PIN_D7              ((Port_PinType)31)

#define PORT_PIN_E0              ((Port_PinType)32)
#define PORT_PIN_E1              ((Port_PinType)33)
#define PORT_PIN_E2              ((Port_PinType)34)
#define PORT_PIN_E3              ((Port_PinType)35)
#define PORT_PIN_E4              ((Port_PinType)36)
#define PORT_PIN_E5              ((Port_PinType)37)

#define PORT_PIN_F0              ((Port_PinType)40)
#define PORT_PIN_F1              ((Port_PinType)41)
#define PORT_PIN_F2              ((Port_PinType)42)
#define PORT_PIN_F3              ((Port_PinType)43)
#define PORT_PIN_F4              ((Port_PinType)44)

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
}Port_NumberType;

typedef enum
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}Port_PinNumberType;

typedef enum
{
	PORT_PIN_AF,
	PORT_PIN_DEN
}Port_PinModeType;

typedef enum {
	PORT_PIN_LOW,
	PORT_PIN_HIGH
}Port_PinLevelType;

typedef enum {
	PORT_PIN_INPUT,
	PORT_PIN_OUTPUT
}Port_PinDirectionType;	

typedef enum
{
	PORT_PIN_PU,
	PORT_PIN_PD,
	PORT_PIN_OD
}Port_PinInternalAttachType;

typedef enum
{
   PORT_PIN_CUR_2MA,
   PORT_PIN_CUR_4MA,
   PORT_PIN_CUR_8MA
}Port_PinOutputCurrentType;

typedef struct 
{
    Port_NumberType                 PortNum;
    Port_PinNumberType              PortPinNum;
    Port_PinModeType                PortPinMode;
    Port_PinLevelType               PortPinLevelValue;
    Port_PinDirectionType           PortPinDirection;
    Port_PinInternalAttachType      PortPinInternalAttach;
    Port_PinOutputCurrentType       PortPinOutputCurrent;
}Port_ConfigType;

#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
