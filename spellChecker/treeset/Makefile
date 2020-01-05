#
# Makefile for CS 70 TreeSet
# 

###############################################################################
# MAKEFILE VARIABLES
###############################################################################

# CXX is the name of the compiler we are using (clang++)

CXX = clang++

# CXXFLAGS are the flags we will be passing each compile

CXXFLAGS       = -g -std=c++11 -Wall -Wextra -pedantic 

# TARGETS is the list of all programs created when we do "make all"
#   (and which should be deleted when we do "make clean")

TARGETS = treeset-cow-test treeset-int-test myspell

###############################################################################
# "PHONY" (BUT USEFUL) MAKEFILE TARGETS
###############################################################################


# "make all" brings all programs up-to-date (recursively)
#     and then runs no commands.

all: $(TARGETS)

# "make clean" brings nothing up to date, but always
#      runs commands to delete all created files

clean:
	rm -f $(TARGETS)
	rm -rf *.o

# "make test" brings all the testing programs up-to-date (recursively)
#       and then runs them.
# You should probably use a more realistic number of buckets than 10
#       for stringhash-test, but the exact number is up to you.

test: treeset-cow-test treeset-int-test 
	./treeset-cow-test
	./treeset-int-test


###############################################################################
# CREATING PROGRAMS
###############################################################################

# "make stringhash-test" brings the relevant .o files up-to-date (recursively)
#      and then links them.

# In a command run by the makefile, $^ stands for the things the target
#      depends on (in this case, the list stringhash-test.o stringhash.o")
#      This is useful so that we don't have to duplicate this list
#      both in the dependency list and in the linking command, and we
#      don't have to define a STRINGHASH_TEST_OBJS variable that is
#      used only for these two lines.

# "make treeset-cow-test" brings the relevant .o files up-to-date (recursively)
#      and then links them.

treeset-cow-test: treeset-cow-test.o testing-logger.o 
	$(CXX) $(CXXFLAGS) -o treeset-cow-test $^

treeset-int-test: treeset-int-test.o testing-logger.o 
	$(CXX) $(CXXFLAGS) -o treeset-int-test $^

myspell: myspell.o spellChecker.o
	$(CXX) $(CXXFLAGS) -o myspell $^
	
doxygen: doxygen.config
	doxygen doxygen.config
# Rules for your own test program would go here (you don't have to
#      add a comment that says what it does, if it follows the
#      standard pattern.)


###############################################################################
# GENERATING OBJECT FILES
###############################################################################

# The .o files depend on the corresponding .cpp file and the .hpp
#      files that C++ code includes.
#      In each case, the command to generate the .o file uses
#      our C++ compiler to compile the .cpp file, with the -c flag.

treeset-cow-test.o: treeset-cow-test.cpp treeset.hpp treeset-private.hpp
	$(CXX) $(CXXFLAGS) -c treeset-cow-test.cpp

treeset-int-test.o: treeset-int-test.cpp treeset.hpp treeset-private.hpp
	$(CXX) $(CXXFLAGS) -c treeset-int-test.cpp

testing-logger.o: testing-logger.cpp testing-logger.hpp
	$(CXX) $(CXXFLAGS) -c testing-logger.cpp

spellChecker.o: spellChecker.cpp treeset.hpp
	$(CXX) $(CXXFLAGS) -c spellChecker.cpp

myspell.o: myspell.cpp treeset.hpp treeset-private.hpp spellChecker.hpp
	$(CXX) $(CXXFLAGS) -c myspell.cpp spellChecker.cpp
# When/if you need more .o files, their dependencies and the
#    compilation commands would go here.
