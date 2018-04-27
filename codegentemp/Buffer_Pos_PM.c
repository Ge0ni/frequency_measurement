/*******************************************************************************
* File Name: Buffer_Pos.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Buffer_Pos.h"

static Buffer_Pos_BACKUP_STRUCT  Buffer_Pos_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Buffer_Pos_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Buffer_Pos_SUT.c usage_Buffer_Pos_Sleep_Wakeup
*******************************************************************************/
void Buffer_Pos_Sleep(void)
{
    #if defined(Buffer_Pos__PC)
        Buffer_Pos_backup.pcState = Buffer_Pos_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Buffer_Pos_backup.usbState = Buffer_Pos_CR1_REG;
            Buffer_Pos_USB_POWER_REG |= Buffer_Pos_USBIO_ENTER_SLEEP;
            Buffer_Pos_CR1_REG &= Buffer_Pos_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Buffer_Pos__SIO)
        Buffer_Pos_backup.sioState = Buffer_Pos_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Buffer_Pos_SIO_REG &= (uint32)(~Buffer_Pos_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Buffer_Pos_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Buffer_Pos_Sleep() for an example usage.
*******************************************************************************/
void Buffer_Pos_Wakeup(void)
{
    #if defined(Buffer_Pos__PC)
        Buffer_Pos_PC = Buffer_Pos_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Buffer_Pos_USB_POWER_REG &= Buffer_Pos_USBIO_EXIT_SLEEP_PH1;
            Buffer_Pos_CR1_REG = Buffer_Pos_backup.usbState;
            Buffer_Pos_USB_POWER_REG &= Buffer_Pos_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Buffer_Pos__SIO)
        Buffer_Pos_SIO_REG = Buffer_Pos_backup.sioState;
    #endif
}


/* [] END OF FILE */
