@echo off

g++ main.cpp io.cpp solution.cpp unit_test.cpp utilities.cpp args.cpp read_data.cpp -c
g++ main.o io.o solution.o unit_test.o utilities.o args.o read_data.o -o test.exe

cmd \k