INCDIR   := inc
SRCDIR   := src

CC = g++

SOURCE = main.cpp ./$(SRCDIR)/*.cpp

HEADER = -I./$(INCDIR) -I/usr/local/include/cryptopp



CFLAGS  = -march=native -mtune=native -O3 -fomit-frame-pointer 
LDFLAGS = -lcryptopp

ALL:
	$(CC)  -c  $(SOURCE) $(HEADER) $(CFLAGS)
	$(CC)  *.o -o main $(LDFLAGS) $(CFLAGS)
	rm *.o