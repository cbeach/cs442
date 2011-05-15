TARGET := ch

OBJECTS :=\
	driver.o\
	board.o

SOURCE :=\
	driver.cpp\
	board.cpp

CC := g++
HEADERFILES := 
LDFLAGS := -o
CPFLAGS := -c -Wall -fpermissive -g


INCLUDES := 

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) $(TARGET) $(INCLUDES)

$(OBJECTS): $(SOURCE)
	$(CC) $(HEADERFILES) $(SOURCE) $(CPFLAGS)

clean:
	rm -f *.o
	

