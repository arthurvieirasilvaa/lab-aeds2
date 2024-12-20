# Makefile para compilar os arquivos CSR ou Linearizada

CC = gcc
CFLAGS = -Wall -std=c99 -I./

MATRIX_TYPE ?= linearizada

SRCS_LINEARIZADA = main_linearizada.c linearizada.c
OBJS_LINEARIZADA = $(SRCS_LINEARIZADA:.c=.o)
EXEC_LINEARIZADA = prog_linearizada

SRCS_CSR = main_csr.c csr.c
OBJS_CSR = $(SRCS_CSR:.c=.o)
EXEC_CSR = prog_csr

OBJ_DIR = obj

ifeq ($(MATRIX_TYPE), linearizada)
  SRCS = $(SRCS_LINEARIZADA)
  OBJS = $(OBJS_LINEARIZADA)
  EXEC = $(EXEC_LINEARIZADA)
else
  SRCS = $(SRCS_CSR)
  OBJS = $(OBJS_CSR)
  EXEC = $(EXEC_CSR)
endif

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
