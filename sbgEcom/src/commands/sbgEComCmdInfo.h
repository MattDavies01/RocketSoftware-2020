#ifndef __SBG_ECOM_CMD_INFO_H__
#define __SBG_ECOM_CMD_INFO_H__

#include "sbgEComCmdCommon.h"

#define SBG_ECOM_INFO_PRODUCT_CODE_LENGTH			(32)

typedef struct _SbgEComDeviceInfo
{
	uint8	productCode[SBG_ECOM_INFO_PRODUCT_CODE_LENGTH];	/*!< Human readable Product Code. */
	uint32	serialNumber;									/*!< Device serial number */
	uint32	calibationRev;									/*!< Calibration data revision */
	uint16	calibrationYear;								/*!< Device Calibration Year */
	uint8	calibrationMonth;								/*!< Device Calibration Month */
	uint8	calibrationDay;									/*!< Device Calibration Day */
	uint32	hardwareRev;									/*!< Device hardware revision */
	uint32	firmwareRev;									/*!< Firmware revision */
} SbgEComDeviceInfo;

//----------------------------------------------------------------------//
//- Info commands				                                       -//
//----------------------------------------------------------------------//

/*!
 *	Retrieve the device information.
 *	\param[in]	pHandle						A valid sbgECom handle.
 *	\param[in]	pInfo						A pointer to a structure to hold device information.
 *	\return									SBG_NO_ERROR if the command has been executed successfully.
 */
SbgErrorCode sbgEComCmdGetInfo(SbgEComHandle *pHandle, SbgEComDeviceInfo *pInfo);

#endif