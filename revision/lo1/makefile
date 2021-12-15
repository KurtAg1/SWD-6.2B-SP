rebuild: clean build

build: dirs debug_build release_build

dirs:
	mkdir -p debug
	mkdir -p release

debug_build:
	gcc -Wall -g -O0 lo1.c -o debug/counter
	gcc -Wall -g -O0 lo1.c -DEXTENDED -o debug/counter2

release_build:
	gcc -Wall lo1.c -o release/counter
	gcc -Wall lo1.c -DEXTENDED -o release/counter2

clean:
	-rm -f release/*
	-rm -f intermediates/*