#include "test.h"
#include <signal.h>

extern size_t current_test;
extern size_t num_tests;
extern void (*tests[])();

void sigsegv()
{
	printf(RED_S "💣 Segfault while running tests ! 💣 (Are your malloc correctly protected?) 💣\n\n" RESET);
	current_test += 1; // skip the faulty test
	enable_malloc();
	for (; current_test < num_tests; current_test++)
		tests[current_test]();
	exit(1);
}
