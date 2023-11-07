import sys
import os
import subprocess

def main_source(tests):
	prototypes = ""
	for test in tests:
		prototypes += "void "
		prototypes += test
		prototypes += "();\n"

	fn = ""
	for test in tests:
		fn += "\t"
		fn += test
		fn += "();\n"

	source = ""
	source += "#include \"test.h\"\n"
	source += "\n"
	source += prototypes
	source += "\n"
	source += "int main() {\n"
	source += fn
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

# Some stats
print("Test coverage: {}/{} files".format(len(tests), len(filenames)))

# Write `.main.c`
with open(".main.c", "w") as fd:
	fd.write(main_source(tests))

# Compile libft.a
s = os.getcwd()
os.chdir("..")
subprocess.Popen([ "make" ]).wait()
os.chdir(s)

# Compile the test program
args = [ "cc", ".main.c"]
for test in tests:
	args.append(test + ".c")
args.extend([ "-o", "test", "-I..", "-L..", "-lbsd", "-lft" ])

if subprocess.Popen(args).wait() != 0:
	print("Compilation failed!")
	exit(1)
subprocess.Popen([ "./test" ]).wait()
