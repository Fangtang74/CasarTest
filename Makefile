INCDIR   := inc
SRCDIR   := src

CC = g++

SOURCE = main.cpp ./$(SRCDIR)/*.cpp 
SOURCEFE = ./$(SRCDIR)/*.c ./$(SRCDIR)/NIST/*.c ./$(SRCDIR)/BCH/*.c 

HEADER = -I./$(INCDIR) -I./$(INCDIR)/bch -I./$(INCDIR)/NIST -I/usr/local/include/cryptopp 



CFLAGS  = -march=native -mtune=native -O3 -fomit-frame-pointer 
LDFLAGS = -lcryptopp -lcrypto

ALL:
	$gcc  -c  $(SOURCEFE) $(HEADER) $(CFLAGS)
	$(CC)  -c  $(SOURCE) $(HEADER) $(CFLAGS)
	$(CC)  *.o -o main $(LDFLAGS) $(CFLAGS)
	rm *.o