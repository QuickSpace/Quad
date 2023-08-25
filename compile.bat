@echo off

g++ quad.cpp io.cpp solution.cpp unittest.cpp utilities.cpp args.cpp readdata.cpp -c
g++ quad.o io.o solution.o unittest.o utilities.o args.o readdata.o -o test.exe

cmd \k