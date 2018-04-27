/*******************************************************************************
* File Name: Input_Signal_Counter2_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Input_Signal_Counter2.h"

static Input_Signal_Counter2_BACKUP_STRUCT Input_Signal_Counter2_backup;


/*******************************************************************************
* Function Name: Input_Signal_Counter2_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Input_Signal_Counter2_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter2_Sleep(void)
{
    if(0u != (Input_Signal_Counter2_BLOCK_CONTROL_REG & Input_Signal_Counter2_MASK))
    {
        Input_Signal_Counter2_backup.enableState = 1u;
    }
    else
    {
        Input_Signal_Counter2_backup.enableState = 0u;
    }

    Input_Signal_Counter2_Stop();
    Input_Signal_Counter2_SaveConfig();
}


/*******************************************************************************
* Function Name: Input_Signal_Counter2_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Input_Signal_Counter2_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter2_Wakeup(void)
{
    Input_Signal_Counter2_RestoreConfig();

    if(0u != Input_Signal_Counter2_backup.enableState)
    {
        Input_Signal_Counter2_Enable();
    }
}


/* [] END OF FILE */
