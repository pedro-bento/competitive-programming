executable = main

cpp = ./cpp/main.cpp 
go = ./go/main.go 
haskell = ./haskell/main.hs 

cpp: $(cpp)
	g++ -o $(executable) -Wall $(cpp) && ./main < in.txt > out.txt && rm ./main

go: $(go)
	go build $(go) && ./main < in.txt > out.txt && rm ./main

haskell: $(haskell)
	ghc $(haskell) && rm ./haskell/main.o && rm ./haskell/main.hi && ./haskell/main < in.txt > out.txt && rm ./haskell/main