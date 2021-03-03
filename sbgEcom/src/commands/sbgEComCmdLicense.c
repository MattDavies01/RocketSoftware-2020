#include "sbgEComCmdLicense.h"
#include "transfer/sbgEComTransfer.h"

SbgErrorCode sbgEComCmdLicenseApply(SbgEComHandle *pHandle, const void *pBuffer, size_t size)
{
	SbgErrorCode	errorCode;
	uint32			currentTimeOut;

	//
	// Define a time out of 10s to let enough time for the GNSS receiver to apply the license
	//
	currentTimeOut = pHandle->cmdDefaultTimeOut;
	pHandle->cmdDefaultTimeOut = 10000;

	//
	// Call function that handle data transfer
	//
	errorCode = sbgEComTransferSend(pHandle, SBG_ECOM_CLASS_LOG_CMD_0, SBG_ECOM_CMD_LICENSE_APPLY, pBuffer, size);

	//
	// Restore the default time out
	//
	pHandle->cmdDefaultTimeOut = currentTimeOut;

	return errorCode;
}