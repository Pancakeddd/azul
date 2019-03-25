CC = gcc
CFLAGS = -s -O3
EXE = bin/azuli.exe

OBJ = src/main.o src/lex.o src/parse.o

all: $(EXE) clean

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	del /S *.o