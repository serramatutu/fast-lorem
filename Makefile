
build:
	gcc -O3 -o bin/$(TARGET) $(TARGET).c

run: build
	./bin/$(TARGET) | pv

bench: build
	./bin/$(TARGET) | pv > /dev/null
