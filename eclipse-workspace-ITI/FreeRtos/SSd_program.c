
/*********************************************************************/
/* Author  : Khlood Amin

                                                                    */
/* Version : V01                                                    */
/* Date    : 14 FEB 2018                                            */
/*********************************************************************/
/* Description                                                       */
/* -------------                                                     */
/*                                                                   */
/* This file has the implementaion of both private and public        */
/* function corresponding to 7 Segment Display Module                */
/*********************************************************************/

#include "H:\Device Drivers\01-COTS\04-LIB\01-STD_TYPES\LSTD_TYPES.h"
#include "H:\Device Drivers\01-COTS\04-LIB\02-BIT-CALC\bit_calc.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"


u8 Ssd_u8SsdIdArray[1]={1};
u8 Ssd_u8SsdDisplayArrayNormal[16]={
							  0x7E,
							  0x30,
							  0x6D,
							  0x79,
							  0x33,
							  0x5B,
							  0x5F,
							  0x70,
							  0x7F,
							  0x7B,
							  0x77,
							  0x1F,
							  0x4E,
							  0x3D,
							  0x4F,
							  0x47
                              };

u8 Ssd_u8SsdDisplayArrayReverse[10]={0x3F,
									 0x06,
									 0x5B,
									 0x4F,
									 0x66,
									 0x6D,
									 0x7D,
									 0x07,
									 0x7F,
									 0x6F,

									};
									



//______________________________________________________________________________________________________
u8 SSD_u8DisplayOn (u8 Copy_u8SsdId)
{
	u8 u8ErrorState = 0;
	/*Validate input*/
	if (Copy_u8SsdId > DIO_MAXPINNB )
	{
		u8ErrorState = 1;
	}
	else 
	{
		if (SSD_u8ASSDType[Copy_u8SsdId] == SSD_u8_COMMON_CATHOD)
		{
			DIO_u8SetPinDirection (SSD_Au8SSDCommonPin[Copy_u8SsdId],DIO_u8_OUTPUT );
			DIO_u8SetPinValue (SSD_Au8SSDCommonPin[Copy_u8SsdId],DIO_u8_LOW );
		}
		else if (SSD_u8ASSDType[Copy_u8SsdId]== SSD_u8_COMMON_ANODE	)
		{
			DIO_u8SetPinDirection (SSD_Au8SSDCommonPin[Copy_u8SsdId],DIO_u8_OUTPUT );
			DIO_u8SetPinValue (SSD_Au8SSDCommonPin[Copy_u8SsdId],DIO_u8_HIGH );
		}
	}
	return u8ErrorState;
}

//__________________________________________________________________________


u8 SSD_u8DisplayOff(u8 Copy_u8SsdId)
{
	u8 u8ErrorState = 0;
	/*Validate input*/
	if (Copy_u8SsdId > DIO_MAXPINNB )
	{
		u8ErrorState = 1;
	}
	else 
	{

		if (SSD_u8ASSDType[Copy_u8SsdId] == SSD_u8_COMMON_CATHOD	)
		{
			DIO_u8SetPinDirection (SSD_Au8SSDCommonPin [ Copy_u8SsdId] , DIO_u8_OUTPUT);
			DIO_u8SetPinValue (SSD_Au8SSDCommonPin [ Copy_u8SsdId], DIO_u8_HIGH );
		}
		else if (SSD_u8ASSDType[Copy_u8SsdId]== SSD_u8_COMMON_ANODE	)
		{
			DIO_u8SetPinDirection (SSD_Au8SSDCommonPin [ Copy_u8SsdId] ,DIO_u8_OUTPUT);
			DIO_u8SetPinValue (SSD_Au8SSDCommonPin [ Copy_u8SsdId] , DIO_u8_LOW );
		}
	}
	return u8ErrorState;
}

//____________________________________________________________________________


u8 SSD_u8WriteNumber(u8 Copy_u8SsdId, u8 Copy_SsdData)
{
	u8 u8ErrorState = 0;
	if (Copy_u8SsdId > DIO_MAXPINNB )
	{
		u8ErrorState = 1;
	}
	else 
	{
		if(SSD_u8ASSDType[Copy_u8SsdId]== SSD_u8_COMMON_ANODE)
		{
			DIO_u8SetPortValue(SSD_Au8SSDPort[Copy_u8SsdId],Ssd_u8SsdDisplayArrayReverse[Copy_SsdData]);
		}

	    else if(SSD_u8ASSDType[Copy_u8SsdId]== SSD_u8_COMMON_CATHOD)
	   {
	    	DIO_u8SetPortValue(SSD_Au8SSDPort[Copy_u8SsdId],(Ssd_u8SsdDisplayArrayReverse[Copy_SsdData]));
	   }

   }
	return u8ErrorState ;
}
			
			
		
		
