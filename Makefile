CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

EXEC = quad

SOURCE_FILES = main.cpp io.cpp solution.cpp unit_test.cpp utilities.cpp args.cpp run_tests.cpp
OBJECT_FILES = main.o io.o solution.o unit_test.o utilities.o args.o run_tests.o

all: compile execute

compile: $(SOURCE_FILES)
	g++ $(SOURCE_FILES) $(CFLAGS) -c

execute: $(OBJECT_FILES)
	g++ $(OBJECT_FILES) $(CFLAGS) -o $(EXEC)