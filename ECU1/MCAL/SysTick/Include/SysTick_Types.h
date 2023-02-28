/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_TYPES_H
#define SYSTICK_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	SysTick_Disable,
	SysTick_Enable
}SysTick_Status_Type;

typedef enum {
	SysTick_Interrupt_Disable,
	SysTick_Interrupt_Enable
}SysTick_IntStatus_Type;

typedef enum {
	SysTick_PIOSC_db4,
	SysTick_SystemClock
}SysTick_ClkSrc_Type;

//#define   SysTick_Disable      0UL
//#define   SysTick_Enable       1UL

//#define   SysTick_Interrupt_Disable   0UL
//#define   SysTick_Interrupt_Enable    1UL

//#define   SysTick_PIOSC_db4     0UL
//#define   SysTick_SystemClock   1UL

typedef   float32 Systick_TimeDelayType;
//typedef   uint32  Systick_CurrentValueType;

typedef struct {
	SysTick_Status_Type     ST_Status;
	SysTick_IntStatus_Type  ST_INT_Status;
	SysTick_ClkSrc_Type     ST_CLKSRC;
	Systick_TimeDelayType   ST_TimeDelay;
}SysTick_ConfigType;

#endif  /* SYSTICK_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick_Types.h
 *********************************************************************************************************************/
