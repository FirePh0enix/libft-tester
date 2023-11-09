#!/bin/env python3

import sys
import os
import subprocess

def main_source(tests):
	test_protos = ""
	for test in tests:
		test_protos += "extern void " + test + "();\n"

	tests_array = "void (*tests[])() = { " + ", ".join(tests) + " };\n"
	tests_count = len(tests)

	source = ""
	source += "#include \"test.h\"\n"
	source += "#include <signal.h>"
	source += "\n"
	source += test_protos
	source += "\n"
	source += tests_array
	source += "size_t current_test = 0;\n"
	source += "size_t num_tests = " + str(tests_count) + ";\n"
	source += "\n"
	source += "int main() {\n"
	source += "\tsignal(SIGSEGV, sigsegv);\n"
	source += "\tfor (; current_test < num_tests; current_test++)\n"
	source += "\t\ttests[current_test]();\n"
	source += "}\n"
	return source

if len(sys.argv) == 2:
	source_dir = "../" + sys.argv[1]
else:
	source_dir = ".."
tests = []
filenames = []

for filename in os.listdir(source_dir):
	s = os.path.basename(filename)
	if s.endswith(".o"):
		continue
	ft_name = s[:len(s) - 2]
	name = ft_name[3:]

	test_name = "test_" + name

	# Check if a test exists for a given file
	if os.path.exists(test_name + ".c"):
		tests.append(test_name)
	filenames.append(name)

# Compile libft.a
s = os.getcwd()
os.chdir("..")
subprocess.Popen([ "make" ]).wait()
os.chdir(s)

# Write `.main.c`
with open(".main.c", "w") as fd:
	fd.write(main_source(tests))

# Compile the test program
args = [ "cc", ".main.c", "tester.c", "tester-segfault.c" ]
for test in tests:
	args.append(test + ".c")
args.extend([ "../libft.a", "-o", "test", "-I..", "-lbsd" ])

if subprocess.Popen(args).wait() != 0:
	print("Compilation failed!")
	exit(1)
subprocess.Popen([ "./test" ]).wait()

# Some stats
print("Test coverage: {}/{} files".format(len(tests), len(filenames)))
