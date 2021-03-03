#pragma once

#include "data/SBGData.h"
#include "data/UOSMData.h"


struct sensorsData
{
    uint64_t timeStamp;
    uint16_t currentStateNo;

#if USE_SBG
    sbgData sbg;
#endif

#if USE_INPUT
    int inputEventNumber = -1;
#endif

#if USE_SOCKET_CLIENT
    int clientEventNumber = -1;
#endif
};