/*******************************************************************************
* File Name: Frequency_Input.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Frequency_Input_ALIASES_H) /* Pins Frequency_Input_ALIASES_H */
#define CY_PINS_Frequency_Input_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Frequency_Input_0			(Frequency_Input__0__PC)
#define Frequency_Input_0_PS		(Frequency_Input__0__PS)
#define Frequency_Input_0_PC		(Frequency_Input__0__PC)
#define Frequency_Input_0_DR		(Frequency_Input__0__DR)
#define Frequency_Input_0_SHIFT	(Frequency_Input__0__SHIFT)
#define Frequency_Input_0_INTR	((uint16)((uint16)0x0003u << (Frequency_Input__0__SHIFT*2u)))

#define Frequency_Input_INTR_ALL	 ((uint16)(Frequency_Input_0_INTR))


#endif /* End Pins Frequency_Input_ALIASES_H */


/* [] END OF FILE */
