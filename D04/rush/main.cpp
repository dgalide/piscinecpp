#include <sys/resource.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#include <iostream>
#include <cstring>
#include <string>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <ctime>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
int main(void)
{
	struct rusage t;
	// sysctlbyname
	// getpwuid
	// getuid
	// sysctl

	std::cout << std::to_string(getrusage(0, &t)) << std::endl;

	std::cout << "max resident set size ->" << t.ru_maxrss << std::endl;
	std::cout << "integral shared text memory size ->" << t.ru_ixrss << std::endl;
	std::cout << "integral unshared stack size ->" << t.ru_isrss << std::endl;
	std::cout << "integral unshared data size ->" << t.ru_idrss << std::endl;
	std::cout << "page reclaims ->" << t.ru_minflt << std::endl;
	std::cout << "page faults ->" << t.ru_majflt << std::endl;
	std::cout << "swap ->" << t.ru_nswap << std::endl;
	std::cout << "block input operation ->" << t.ru_inblock << std::endl;
	std::cout << "block output operations ->" << t.ru_oublock << std::endl;
	std::cout << "messages sent ->" << t.ru_msgsnd << std::endl;
	std::cout << "signals received ->" << t.ru_nsignals << std::endl;
	std::cout << "voluntary context switches ->" << t.ru_nvcsw << std::endl;
	std::cout << "involuntary context switches ->" << t.ru_nivcsw << std::endl;
	return 0;
}
