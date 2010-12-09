all: injectee injectant.dylib injector

injectee: injectee.c
	gcc -Wall -std=c99 -o injectee injectee.c

injectant.dylib: injectant.c
	gcc -Wall -std=c99 -shared -o injectant.dylib injectant.c

injector: injector.c
	gcc -Wall -std=c99 -o injector mach_inject.c injector.c

clean:
	rm -f injectee injectant.dylib injector
