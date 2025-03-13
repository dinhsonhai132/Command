all:
	g++ cw.cpp -o cw
	g++ wcat.cpp -o wcat
	g++ wtouch.cpp -o wtouch

clean:
	rm -f cw wcat wtouch

.PHONY: all clean