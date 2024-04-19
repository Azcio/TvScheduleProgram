
output: main.o channel.o 
	g++ main.o channel.o -o output

main.o: main.cpp
	g++ -c main.cpp

channel.o: channel.cpp channel.h
	g++ -c channel.cpp

ChannelManagerTests.o: ChannelManagerTests.cpp channel.h
	g++ -c ChannelManagerTests.cpp	




schedule.o: schedule.cpp schedule.h
	g++ -c schedule.cpp



clean:
	rm *.o output

