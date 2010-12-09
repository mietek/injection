#include <mach/mach_init.h>
#include <mach/thread_act.h>
#include <stddef.h>
#include <stdio.h>

void entry(ptrdiff_t codeOffset, void *param, size_t paramSize, void *pthreadData) {
#if defined(__i386__) || defined(__x86_64__)
	extern void __pthread_set_self(char *);
	__pthread_set_self(pthreadData);
#endif
	printf("Access granted\n");
	thread_suspend(mach_thread_self());
}
