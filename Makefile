CC = gcc
CFLAGS = -s -O3
EXE = bin/azuli.exe

OBJ = src/main.o src/lex.o

all: $(EXE)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f src/*.o