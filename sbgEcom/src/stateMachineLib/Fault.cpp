#include "Fault.h"
#include "DataTypes.h"

#if WIN32
#include <assert.h>
#endif


// Fault Handler

void FaultHandler(const char* file, unsigned short line)
{
    #if WIN32
        DebugBreak();

            assert(0);
    #endif

            while(1);

}