run:
	g++ -std=c++11 main.cpp && ./a.out

run-verilog:
	iverilog -o main main.v && vvp main