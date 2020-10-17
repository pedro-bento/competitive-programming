executable = main

in = ./io/in.txt
out = ./io/out.txt

default = ./src/default.cpp
st = ./src/segment_tree.cpp

default: $(default)
	g++ -o $(executable) -Wall $(default) && ./main < $(in) > $(out) && rm ./main

st: $(st)
	g++ -o $(executable) -Wall $(st) && ./main < $(in) > $(out) && rm ./main