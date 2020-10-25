executable = main

in 		= ./io/in.txt
out 	= ./io/out.txt
file	= ./main.cpp

main: $(file)
	g++ -o $(executable) -Wall $(file) && ./main < $(in) > $(out) && rm ./main