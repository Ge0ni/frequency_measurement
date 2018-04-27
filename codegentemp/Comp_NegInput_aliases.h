/*******************************************************************************
* File Name: Comp_NegInput.h  
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

#if !defined(CY_PINS_Comp_NegInput_ALIASES_H) /* Pins Comp_NegInput_ALIASES_H */
#define CY_PINS_Comp_NegInput_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Comp_NegInput_0			(Comp_NegInput__0__PC)
#define Comp_NegInput_0_PS		(Comp_NegInput__0__PS)
#define Comp_NegInput_0_PC		(Comp_NegInput__0__PC)
#define Comp_NegInput_0_DR		(Comp_NegInput__0__DR)
#define Comp_NegInput_0_SHIFT	(Comp_NegInput__0__SHIFT)
#define Comp_NegInput_0_INTR	((uint16)((uint16)0x0003u << (Comp_NegInput__0__SHIFT*2u)))

#define Comp_NegInput_INTR_ALL	 ((uint16)(Comp_NegInput_0_INTR))


#endif /* End Pins Comp_NegInput_ALIASES_H */


/* [] END OF FILE */
