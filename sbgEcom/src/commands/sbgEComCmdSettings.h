#ifndef __SBG_ECOM_CMD_SETTINGS_H__
#define __SBG_ECOM_CMD_SETTINGS_H__

#include "sbgEComCmdCommon.h"

//----------------------------------------------------------------------//
//- Settings action definition										   -//
//----------------------------------------------------------------------//

/*!
 * Defintion of all the settings actions available.
 */
typedef enum _SbgEComSettingsAction
{
	SBG_ECOM_REBOOT_ONLY 				= 0,		/*!< Only reboot the device. */
	SBG_ECOM_SAVE_SETTINGS				= 1,		/*!< Save the settings to non-volatile memory and then reboot the device. */
	SBG_ECOM_RESTORE_DEFAULT_SETTINGS	= 2			/*!< Restore default settings, save them to non-volatile memory and reboot the device. */
} SbgEComSettingsAction;

//----------------------------------------------------------------------//
//- Settings commands                                                  -//
//----------------------------------------------------------------------//

/*!
 *	Execute one of the available settings action : <BR>
 *			- SBG_ECOM_REBOOT_ONLY : Only reboot the device.<BR>
 *			- SBG_ECOM_SAVE_SETTINGS : Save the settings to non-volatile memory and then reboot the device.<BR>
 *			- SBG_ECOM_RESTORE_DEFAULT_SETTINGS : Restore default settings, save them to non-volatile memory and reboot the device.<BR>
 *	\param[in]	pHandle						A valid sbgECom handle.
 *	\param[in]	action						One of the available SbgEComSettingsAction.
 *	\return									SBG_NO_ERROR if the command has been executed successfully.
 */
SbgErrorCode sbgEComCmdSettingsAction(SbgEComHandle *pHandle, SbgEComSettingsAction action);

/*!
 *	Send a complete set of settings to the device and store them into the FLASH memory.
 *	The device will reboot automatically to use the new settings.
 *	\param[in]	pHandle						A valid sbgE
 
 
 
 
 
 Com handle.
 *	\param[in]	pBuffer						Read only buffer containing the settings.
 *	\param[in]	size						Size of the buffer.
 *	\return									SBG_NO_ERROR if the command has been executed successfully.
 */
SbgErrorCode sbgEComCmdImportSettings(SbgEComHandle *pHandle, const void *pBuffer, size_t size);

/*!
 *	Retrieve a complete set of settings from the device as a buffer.
 *	\param[in]	pHandle						A valid sbgECom handle.
 *	\param[in]	pBuffer						Allocated buffer that can hold the received settings.
 *	\param[out]	pSize						The number of bytes that have been stored into pBuffer.
 *	\param[in]	maxSize						The maximum buffer size in bytes that can be stored into pBuffer.
 *	\return									SBG_NO_ERROR if the command has been executed successfully.
 */
SbgErrorCode sbgEComCmdExportSettings(SbgEComHandle *pHandle, void *pBuffer, size_t *pSize, size_t maxSize);

#endif