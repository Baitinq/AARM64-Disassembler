all: ./bin/disasm

./bin/disasm: ./src/main.cpp
	./build.sh

clean: ./bin
	rm -rf bin

