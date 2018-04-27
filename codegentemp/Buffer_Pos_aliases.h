/*******************************************************************************
* File Name: Buffer_Pos.h  
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

#if !defined(CY_PINS_Buffer_Pos_ALIASES_H) /* Pins Buffer_Pos_ALIASES_H */
#define CY_PINS_Buffer_Pos_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Buffer_Pos_0			(Buffer_Pos__0__PC)
#define Buffer_Pos_0_PS		(Buffer_Pos__0__PS)
#define Buffer_Pos_0_PC		(Buffer_Pos__0__PC)
#define Buffer_Pos_0_DR		(Buffer_Pos__0__DR)
#define Buffer_Pos_0_SHIFT	(Buffer_Pos__0__SHIFT)
#define Buffer_Pos_0_INTR	((uint16)((uint16)0x0003u << (Buffer_Pos__0__SHIFT*2u)))

#define Buffer_Pos_INTR_ALL	 ((uint16)(Buffer_Pos_0_INTR))


#endif /* End Pins Buffer_Pos_ALIASES_H */


/* [] END OF FILE */
