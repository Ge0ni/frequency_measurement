/*******************************************************************************
* File Name: Comp_PosInput.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Comp_PosInput_H) /* Pins Comp_PosInput_H */
#define CY_PINS_Comp_PosInput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Comp_PosInput_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Comp_PosInput_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Comp_PosInput_Read(void);
void    Comp_PosInput_Write(uint8 value);
uint8   Comp_PosInput_ReadDataReg(void);
#if defined(Comp_PosInput__PC) || (CY_PSOC4_4200L) 
    void    Comp_PosInput_SetDriveMode(uint8 mode);
#endif
void    Comp_PosInput_SetInterruptMode(uint16 position, uint16 mode);
uint8   Comp_PosInput_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Comp_PosInput_Sleep(void); 
void Comp_PosInput_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Comp_PosInput__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Comp_PosInput_DRIVE_MODE_BITS        (3)
    #define Comp_PosInput_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Comp_PosInput_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Comp_PosInput_SetDriveMode() function.
         *  @{
         */
        #define Comp_PosInput_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Comp_PosInput_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Comp_PosInput_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Comp_PosInput_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Comp_PosInput_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Comp_PosInput_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Comp_PosInput_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Comp_PosInput_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Comp_PosInput_MASK               Comp_PosInput__MASK
#define Comp_PosInput_SHIFT              Comp_PosInput__SHIFT
#define Comp_PosInput_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Comp_PosInput_SetInterruptMode() function.
     *  @{
     */
        #define Comp_PosInput_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Comp_PosInput_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Comp_PosInput_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Comp_PosInput_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Comp_PosInput__SIO)
    #define Comp_PosInput_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Comp_PosInput__PC) && (CY_PSOC4_4200L)
    #define Comp_PosInput_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Comp_PosInput_USBIO_DISABLE              ((uint32)(~Comp_PosInput_USBIO_ENABLE))
    #define Comp_PosInput_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Comp_PosInput_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Comp_PosInput_USBIO_ENTER_SLEEP          ((uint32)((1u << Comp_PosInput_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Comp_PosInput_USBIO_SUSPEND_DEL_SHIFT)))
    #define Comp_PosInput_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Comp_PosInput_USBIO_SUSPEND_SHIFT)))
    #define Comp_PosInput_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Comp_PosInput_USBIO_SUSPEND_DEL_SHIFT)))
    #define Comp_PosInput_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Comp_PosInput__PC)
    /* Port Configuration */
    #define Comp_PosInput_PC                 (* (reg32 *) Comp_PosInput__PC)
#endif
/* Pin State */
#define Comp_PosInput_PS                     (* (reg32 *) Comp_PosInput__PS)
/* Data Register */
#define Comp_PosInput_DR                     (* (reg32 *) Comp_PosInput__DR)
/* Input Buffer Disable Override */
#define Comp_PosInput_INP_DIS                (* (reg32 *) Comp_PosInput__PC2)

/* Interrupt configuration Registers */
#define Comp_PosInput_INTCFG                 (* (reg32 *) Comp_PosInput__INTCFG)
#define Comp_PosInput_INTSTAT                (* (reg32 *) Comp_PosInput__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Comp_PosInput_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Comp_PosInput__SIO)
    #define Comp_PosInput_SIO_REG            (* (reg32 *) Comp_PosInput__SIO)
#endif /* (Comp_PosInput__SIO_CFG) */

/* USBIO registers */
#if !defined(Comp_PosInput__PC) && (CY_PSOC4_4200L)
    #define Comp_PosInput_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Comp_PosInput_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Comp_PosInput_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Comp_PosInput_DRIVE_MODE_SHIFT       (0x00u)
#define Comp_PosInput_DRIVE_MODE_MASK        (0x07u << Comp_PosInput_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Comp_PosInput_H */


/* [] END OF FILE */
