
CC = gcc
COMPILER_FLAGS = -std=c99
LINKER_FLAGS = -lm
OBJ_NAME = siguel


siguel: main.o leitura.o
	$(CC) main.o leitura.o geometria.o escritasvg.o $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

main.o: main.c leitura.o leitura.h geometria.o geometria.h escritasvg.o escritasvg.h 
	$(CC) -c main.c

leitura.o: leitura.c leitura.h geometria.o geometria.h escritasvg.o escritasvg.h 
	$(CC) -c leitura.c

geometria.o: geometria.c geometria.h 
	$(CC) -c geometria.c

escritasvg.o: escritasvg.c escritasvg.h 
	$(CC) -c escritasvg.c