CC = gcc
CFLAGS = -s -O3
EXE = bin/azuli.exe

OBJ = src/main.o

all: $(EXE) clean

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

clean:
	rm -f src/*.o