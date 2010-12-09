#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "mach_inject.h"

void inject(pid_t pid) {
	void *lib;
	if (!(lib = dlopen("injectant.dylib", RTLD_NOW))) {
		printf("Error: dlopen() -> NULL");
		return;
	}
	mach_inject_entry entry = dlsym(lib, "entry");
	const char *err1;
	if ((err1 = dlerror())) {
		printf("Error: dlsym() -> %s", err1);
		return;
	}
	mach_error_t err2;
	if ((err2 = mach_inject(entry, NULL, 0, pid, 0))) {
		printf("Error: mach_inject() -> %d", err2);
		return;
	}
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: injector <pid>\n");
		return 1;
	}
	pid_t pid = atoi(argv[1]);
	inject(pid);
	return 0;
}
