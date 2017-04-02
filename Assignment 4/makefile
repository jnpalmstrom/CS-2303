# Jack Palmstrom            ccc username: jnpalmstrom





CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =	Bank.o Queue.o

LIBS =

TARGET =	qSim

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
	