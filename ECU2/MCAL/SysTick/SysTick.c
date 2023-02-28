/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  SysTick Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "SysTick.h"
#include "SysTick_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 SysTickCounter;
static void (*SysTick_SetCallback_Ptr)(void) = NULL_PTR; /* Pointer to function and Set pointing to NULL */

void SysTick_Init(SysTick_ConfigType SysTickConfigPtr)
{
	/* Calculate Reload value */
	uint32 Reload_Value = (SysTickConfigPtr.ST_TimeDelay * SYSCLK_FREQUENCY) ;
	/* Set STRELOAD */
	if((Reload_Value > 0) && (Reload_Value <= MaxReloadValue))
  STRELOAD = (Reload_Value - 1);
	else
	{
		/*invalid*/
	}
	/* Reset STCURRENT */
	STCURRENT = 0UL;
	
	/* Set Clock Source */
	if(SysTickConfigPtr.ST_CLKSRC == SysTick_SystemClock)
	{
		STCTRL.Bit.CLK_SRC = 1UL;
	}
	else if (SysTickConfigPtr.ST_CLKSRC == SysTick_PIOSC_db4)
	{
		STCTRL.Bit.CLK_SRC = 0UL;
	}
	
	/* Enable/Disable SysTick interrupt */
	if(SysTickConfigPtr.ST_CLKSRC == SysTick_SystemClock)
	{
		STCTRL.Bit.INTEN  = 1UL;
	}
	else if (SysTickConfigPtr.ST_CLKSRC == SysTick_PIOSC_db4)
	{
		STCTRL.Bit.INTEN  = 0UL;
	}
}

void SysTick_Stop(void)
{
	STCTRL.Bit.ENABLE = 0UL; /* Disable SysTick */
}

void SysTick_Start()
{
	STCTRL.Bit.ENABLE = 1UL; /* Enable SysTick */
}

void SysTick_SetCallback(void (*Callback_Ptr) (void))
{
	SysTick_SetCallback_Ptr = Callback_Ptr;
}

void SysTick_Handler(void)
{
	SysTickCounter++;
	if (SysTick_SetCallback_Ptr != NULL_PTR) /* Check if the SysTick_SetCallBack is called */
	{
		(*SysTick_SetCallback_Ptr)(); /* call the function using call-back concept */
	}
}

/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
