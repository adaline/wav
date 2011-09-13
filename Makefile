

all : driver.o wav_in.o wav_out.o
	g++ $^ -o wave 


%.o : %.cpp
	g++ -c -g $^ 


clean :
	rm *.o wave