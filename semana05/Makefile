CC = gcc
CFLAGS = -Wall -std=c99

EXEC = prog

SRC_DIR = .
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/listaprioridade.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Cria o diretório de objetos caso não exista
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

rebuild: clean $(EXEC)

.PHONY: clean rebuild