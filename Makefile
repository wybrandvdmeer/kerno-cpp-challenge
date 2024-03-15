all: ee

ee: main.o ParseInput.o HttpObject.o HttpRequest.o HttpResponse.o HttpKey.o ReportThread.o HttpKeysMap.o
	g++ -o ee ParseInput.o main.o HttpObject.o HttpRequest.o HttpResponse.o HttpKey.o \
        ReportThread.o HttpKeysMap.o

ParseInput.o: ParseInput.cpp ParseInput.h
	g++ -c ParseInput.cpp

HttpObject.o: HttpObject.cpp HttpObject.h
	g++ -c HttpObject.cpp

HttpKeysMap.o: HttpKeysMap.cpp HttpKeysMap.h
	g++ -c HttpKeysMap.cpp

ReportThread.o: ReportThread.cpp ReportThread.h
	g++ -c ReportThread.cpp

HttpKey.o: HttpKey.cpp HttpKey.h
	g++ -c HttpKey.cpp

HttpRequest.o: HttpRequest.cpp HttpRequest.h
HttpRequest.o: HttpRequest.cpp HttpRequest.h
	g++ -c HttpRequest.cpp

HttpResponse.o: HttpResponse.cpp HttpResponse.h
	g++ -c HttpResponse.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o ee
