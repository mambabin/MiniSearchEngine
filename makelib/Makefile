.PHONY:clean test
CC=g++
CFLAGS=-Wall -g
BIN=makepagelib.exe page_unique.exe make_inverted_index.exe query.exe run_query.exe
STAND= -std=c++0x
LINKS=-lmuduo_net -lmuduo_base -lpthread -ljsoncpp
all:$(BIN)
makepagelib.exe:makelib.o MakePageLib.o RobustIO.o ReadFile.o TruncFile.o
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)
page_unique.exe:unique_page.o RobustIO.o ReadFile.o TruncFile.o \
	Document.o PageUnique.o SegmentSingleton.o InvertedIndex.o
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)
make_inverted_index.exe:make_inverted_index.o RobustIO.o ReadFile.o \
	TruncFile.o Document.o SegmentSingleton.o InvertedIndex.o \
	MakeInvertedIndex.o
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)
query.exe:make_query.o RobustIO.o ReadFile.o TruncFile.o \
	Document.o SegmentSingleton.o InvertedIndex.o PageQuery.o
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)
run_query.exe:run_server.o RobustIO.o ReadFile.o TruncFile.o \
	Document.o SegmentSingleton.o InvertedIndex.o PageQuery.o \
	QueryServer.o
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(STAND)
clean:
	rm -f *.o $(BIN) $(TEST) core