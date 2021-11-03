
build_debug:
	gcc-11 -march=native -pthread -g -o bin/$(TARGET)_debug $(TARGET).c

build:
	gcc-11 -march=native -mtune=native -pthread -O3 -o bin/$(TARGET) $(TARGET).c

run: build
	./bin/$(TARGET) | pv

bench: build
	./bin/$(TARGET) | pv > /dev/null
