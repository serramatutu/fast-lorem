
build:
	gcc -O3 -o bin/$(TARGET) $(TARGET).c

bench: build
	./bin/$(TARGET) | pv
