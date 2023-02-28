/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  PORT Driver
 *
 *      \details  The Driver Configure GPIO registers
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Port_Types.h"
#include "Mcu_Hw.h"

// -dLaunchPadDLL 
/************************************************************************************
* Service Name: Port_Init
* Parameters (in): *PortConfigPtr
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Configure GPIO Ports and Pins
************************************************************************************/
void Port_Init(Port_ConfigType *PortConfigPtr)
{
	uint8 PinCounter;
	for(PinCounter = 0; PinCounter < PORT_PINS_NUM; PinCounter++)
	{
		Port_NumberType PortNum = PortConfigPtr[PinCounter].PortNum;
		Port_PinNumberType PinNum = PortConfigPtr[PinCounter].PortPinNum;
		
		/* Unlock Locked Pins */
		if(PortNum == PORT_F && PinNum == PIN_0) GPIOLOCK(PortNum) = GPIO_LOCK_KEY;
		
		/* Step 1 Enable the clock */
		Set_Bit(SYSCTL_RCGCGPIO, PortNum); //enable and disable GPIO modules in Run mode
		
		/* Step 2 select the direction */
		if(PORT_PIN_OUTPUT == PortConfigPtr[PinCounter].PortPinDirection)
		{
			Set_Bit(GPIODIR(PortNum), PinNum);
			/* Step 2 Select the level */
			if(PORT_PIN_HIGH == PortConfigPtr[PinCounter].PortPinLevelValue)
			{
				Set_Bit(GPIODATA(PortNum), PinNum);
			}
			else if(PORT_PIN_LOW == PortConfigPtr[PinCounter].PortPinLevelValue)
			{
				Clear_Bit(GPIODATA(PortNum), PinNum);
			}
			else
			{	
				/*Invalid*/
				break;
			}
			/* Step 4 Select the current */
			switch(PortConfigPtr[PinCounter].PortPinOutputCurrent)
			{
				case PORT_PIN_CUR_2MA:
					Set_Bit(GPIODR2R(PortNum), PinNum);
					break;
				case PORT_PIN_CUR_4MA:
					Set_Bit(GPIODR4R(PortNum), PinNum);
					break;
				case PORT_PIN_CUR_8MA:
					Set_Bit(GPIODR8R(PortNum), PinNum);
					break;
				default:
					/*Invalid*/
					PinCounter = PORT_PINS_NUM;
					continue;
			}
			
			/* Step 5 Select internal attach */
			switch(PortConfigPtr[PinCounter].PortPinInternalAttach)
			{
				case PORT_PIN_OD:
					Set_Bit(GPIOODR(PortNum), PinNum);
					break;
				case PORT_PIN_PU:
					Set_Bit(GPIOPUR(PortNum), PinNum);
					break;
				case PORT_PIN_PD:
					Set_Bit(GPIOPDR(PortNum), PinNum);
					break;
				default:
					Set_Bit(GPIOPUR(PortNum), PinNum);
					continue;
			}
		}
		
		/* Step 2 select the direction */
		else if(PORT_PIN_INPUT == PortConfigPtr[PinCounter].PortPinDirection)
		{
			Clear_Bit(GPIODIR(PortNum), PinNum);
			/* Step 4 Select the current */
			switch(PortConfigPtr[PinCounter].PortPinOutputCurrent)
			{
				case PORT_PIN_CUR_2MA:
					Set_Bit(GPIODR2R(PortNum), PinNum);
					break;
				case PORT_PIN_CUR_4MA:
					Set_Bit(GPIODR4R(PortNum), PinNum);
					break;
				case PORT_PIN_CUR_8MA:
					Set_Bit(GPIODR8R(PortNum), PinNum);
					break;
				default:
					/*Invalid*/
					PinCounter = PORT_PINS_NUM;
					continue;
			}
			
			/* Step 5 Select internal attach */
			switch(PortConfigPtr[PinCounter].PortPinInternalAttach)
			{
				case PORT_PIN_OD:
					Set_Bit(GPIOODR(PortNum), PinNum);
					break;
				case PORT_PIN_PU:
					Set_Bit(GPIOPUR(PortNum), PinNum);
					break;
				case PORT_PIN_PD:
					Set_Bit(GPIOPDR(PortNum), PinNum);
					break;
				default:
					Set_Bit(GPIOPUR(PortNum), PinNum);
					continue;
			}
		}
		
		/* Step 6 Setting Digital MODE */
		if(PORT_PIN_DEN == PortConfigPtr[PinCounter].PortPinMode)
		{
			/* Clear corresponding bit in GPIOAFSEL to disable any alt functionality on pin */
			Clear_Bit(GPIOAFSEL(PortNum), PinNum);
			/* Set corresponding bit in GPIODEN to enable digital functionality on pin */
			Set_Bit(GPIODEN(PortNum), PinNum);
			/* Clear corresponding bit in GPIOAFSEL to disable analog functionality on pin */
			Clear_Bit(GPIOAMSEL(PortNum), PinNum);
		}
		else
		{
			/*invalid*/
			break;
		}

	}

}


/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
