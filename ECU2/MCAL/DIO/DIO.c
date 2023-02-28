/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  DIO Driver
 *
 *      \details  The Driver Configurea Pins and Ports setting, clearing, toogling etc...
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Dio_Types.h"
#include "Mcu_Hw.h"

/************************************************************************************
* Service Name: Dio_ReadChannel
* Parameters (in): PortId, ChannelId
* Parameters (inout): None
* Parameters (out): None
* Return value: Low or High
* Description: Read the value of specific pin
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
	Dio_LevelType LevelType;
	if(Get_Bit(GPIODATA(PortId), ChannelId))
	{
		LevelType = High;
	}
	else
	{
		LevelType = Low;
	}

	return LevelType;
}


/************************************************************************************
* Service Name: Dio_WriteChannel
* Parameters (in): ChannelId - Channel number , level- high or low
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Writing value on pin
************************************************************************************/
void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType level)
{
	switch(level)
	{
		case Low:
		{	
			Clear_Bit(GPIODATA(PortId), ChannelId);
			break;
		}
		case High:
		{
			Set_Bit(GPIODATA(PortId), ChannelId);
			break;
		}
	}
}

/************************************************************************************
* Service Name: Dio_ReadPort
* Parameters (in): PortId - port number
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType 0-255
* Description: Reading the value of specific port
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType Port_Level = GPIODATA(PortId);
	return Port_Level;
}

/************************************************************************************
* Service Name: Dio_WritePort
* Parameters (in): PortId - port number , level - 0->255
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Writing value on specific port
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level)
{
	GPIODATA(PortId) = level;
}

/************************************************************************************
* Service Name: Dio_FlipChannel
* Parameters (in): ChannelId - Channel number
* Parameters (inout): None
* Parameters (out): None
* Return value: High or Low
* Description: flipping value of specific pin and returning the new value 
************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
	Toggle_Bit(GPIODATA(PortId), ChannelId);
	return Get_Bit(GPIODATA(PortId), ChannelId);
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
