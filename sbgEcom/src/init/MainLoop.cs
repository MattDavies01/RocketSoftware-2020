#include "../helpers/Types.h"
#include "config/UOStateMachine.h"

#include "helpers/Helper.h"

#include <stdio.h>
#include "chrono"
#include "iostream"
#include <thread>

#define DEFAULT_TARGET_UPDATE_DURATION_NS 1000000000L / 30L // in nanoseconds = 33 miliseconds = 30Hz

int main()
{
	UOStateMachine uOttSM;

	time_point start, now;
	duration_ns target_ns, elapsed_ns;
	start = std::chrono::steady_clock::now();
	UOSMData data = UOSMData();

	const uint64_t targetUpdateDuration = 
			helper::getEnvOrDefault("TARGET_UPDATE_DURATION_NS", DEFAULT_TARGET_UPDATE_DURATION_NS);

	uint64_t count = 1;
	while (true)
	{
		now = std::chrono::steady_clock::now();

		data.now = now;

		uOttSM.updateStateMachine(&data);

		elapsed_ns = duration_ns(now - start);
		target_ns = duration_ns(targetUpdateDuration * count++);

		if (target_ns > elapsed_ns)
		{
			std::this_thread::sleep_for(target_ns - elapsed_ns);
		}
		else
		{
			std::cout << "Timing Error: Update took too long\n";
		}
	}

	return 0;
}