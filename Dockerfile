FROM gcc:13

RUN mkdir /home/kerno

COPY HttpKey.cpp HttpObject.cpp HttpResponse.cpp ParseInput.cpp HttpKeysMap.cpp HttpRequest.cpp main.cpp ReportThread.cpp /home/kerno/

COPY Type.h HttpKey.h HttpKeysMap.h HttpObject.h HttpRequest.h HttpResponse.h ParseInput.h ReportThread.h /home/kerno/

COPY Makefile /home/kerno

COPY generator /home/kerno

COPY start-kerno /home/kerno

RUN chmod ug+x /home/kerno/start-kerno

RUN chmod ug+x /home/kerno/generator

WORKDIR /home/kerno

RUN make 

CMD ./start-kerno

