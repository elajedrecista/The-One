CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11

OBJ = obj
SRC = src
DEP = $(OBJ)/main.o $(OBJ)/traders.o $(OBJ)/simul.o

main: $(DEP)
	$(CC) $(CFLAGS) $^ -o main

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) -c $^
	mv *.o $(OBJ)/

$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CFLAGS) -c $<
	mv *.o $(OBJ)/

clean:
	rm $(OBJ)/*.o -f
	rm main -f