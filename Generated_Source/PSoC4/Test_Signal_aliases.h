/*******************************************************************************
* File Name: Test_Signal.h  
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

#if !defined(CY_PINS_Test_Signal_ALIASES_H) /* Pins Test_Signal_ALIASES_H */
#define CY_PINS_Test_Signal_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Test_Signal_0			(Test_Signal__0__PC)
#define Test_Signal_0_PS		(Test_Signal__0__PS)
#define Test_Signal_0_PC		(Test_Signal__0__PC)
#define Test_Signal_0_DR		(Test_Signal__0__DR)
#define Test_Signal_0_SHIFT	(Test_Signal__0__SHIFT)
#define Test_Signal_0_INTR	((uint16)((uint16)0x0003u << (Test_Signal__0__SHIFT*2u)))

#define Test_Signal_INTR_ALL	 ((uint16)(Test_Signal_0_INTR))


#endif /* End Pins Test_Signal_ALIASES_H */


/* [] END OF FILE */
