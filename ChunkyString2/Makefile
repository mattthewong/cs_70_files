# Makefile for ChunkySting Tester

CXXFLAGS = -g -stdlib=libc++ -std=c++11 -Wall -Wextra -pedantic 
CXX      = clang++

TARGETS 	    = stringtest-ours stringtest
STRINGTEST_OBJS     = stringtest.o chunkystring.o testing-logger.o
STRINGTEST_OURS_OBJS     = stringtest-ours.o chunkystring.o testing-logger.o
ALL_OBJS	    =   $(STRINGTEST_OBJS) $(STRINGTEST_OURS_OBJS)

LIBS        =   -ldl -rdynamic -stdlib=libc++

# ----- Make Rules -----

all:	$(TARGETS)

test: $(TARGETS)
	./stringtest-ours ./stringtest

stringtest-ours:	$(STRINGTEST_OURS_OBJS) 
	$(CXX) $(LDFLAGS) -o $@ $(STRINGTEST_OURS_OBJS) 

stringtest:	$(STRINGTEST_OBJS) 
	$(CXX) $(LDFLAGS) -o $@ $(STRINGTEST_OBJS) 

clean:
	rm -f $(TARGETS) $(ALL_OBJS)

stringtest-ours.o: stringtest-ours.cpp
	$(CXX) -c $(LDFLAGS) $(LIBS) $(CXXFLAGS) stringtest-ours.cpp

stringtest.o: stringtest.cpp
	$(CXX) -c $(LDFLAGS) $(LIBS) $(CXXFLAGS) stringtest.cpp

chunkystring.o: chunkystring.cpp chunkystring.hpp
	$(CXX) -c $(LDFLAGS) $(LIBS) $(CXXFLAGS) chunkystring.cpp 

testing-logger.o: testing-logger.cpp testing-logger.hpp
	$(CXX) -c $(CXXFLAGS) testing-logger.cpp
