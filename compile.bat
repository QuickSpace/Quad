@echo off

g++ main.cpp io.cpp solution.cpp unit_test.cpp utilities.cpp args.cpp run_tests.cpp -c
g++ main.o io.o solution.o unit_test.o utilities.o args.o run_tests.o -o test.exe

cmd \k