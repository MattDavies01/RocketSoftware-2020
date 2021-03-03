#ifndef __SBG_ECOM_TRANSFER_H__
#define __SBG_ECOM_TRANSFER_H__

#include <sbgCommon.h>
#include <sbgECom.h>

//----------------------------------------------------------------------//
//- Global definitions                                                 -//
//----------------------------------------------------------------------//

#define SBG_ECOM_TRANSFER_MAX_SIZE			(8192u)			/*!< Maximum buffer that can be transmitted using the sbgECom transfer protocol. */
#define SBG_ECOM_TRANSFER_PACKET_SIZE		(1300u)			/*!< Max packet size transmitted in a single frame */

//----------------------------------------------------------------------//
//- Communication protocol structs and definitions                     -//
//----------------------------------------------------------------------//

/*!
 * Defines the ECom transfer commands
 */
typedef enum _SbgEComTransferCmd
{
	SBG_ECOM_TRANSFER_START = 0,							/*!< Command to initiate a transfer. */
	SBG_ECOM_TRANSFER_DATA	= 1,							/*!< Command to transmit/receive data. */
	SBG_ECOM_TRANSFER_END	= 2								/*!< Command to end a transfer. */
} SbgEComTransferCmd;

//----------------------------------------------------------------------//
//- Protocol transfer operations				                       -//
//----------------------------------------------------------------------//

/*!
 * Specific method to handle a large send into multiple frames.
 * \param[in]	pHandle					Pointer to a valid SbgEComHandle.
 * \param[in]	msgClass				Original protocol class asking for transfer.
 * \param[in]	msg						Original protocol message id asking for transfer.
 * \param[in]	pBuffer					Pointer to the buffer containing the data to send.
 * \param[in]	size					The size of the buffer.
 * \return								SBG_NO_ERROR in case of a successful upload.
 */
SbgErrorCode sbgEComTransferSend(SbgEComHandle *pHandle, uint8 msgClass, uint8 msg, const void *pBuffer, size_t size);

/*!
 * Specific method to handle a large receive from the device.
 * \param[in]	pHandle					Pointer to a valid SbgEComHandle.
 * \param[in]	msgClass				Original protocol class asking for transfer.
 * \param[in]	msg						Original protocol message id asking for transfer.
 * \param[in]	pBuffer					Pointer to the buffer where to write data.
 * \param[out]	pActualSize				The final size written into the buffer.
 * \param[in]	size					The size of the buffer.
 * \return								SBG_NO_ERROR in case of a successful download.
 */
SbgErrorCode sbgEComTransferReceive(SbgEComHandle *pHandle, uint8 msgClass, uint8 msg, void *pBuffer, size_t *pActualSize, size_t bufferSize);

#endif