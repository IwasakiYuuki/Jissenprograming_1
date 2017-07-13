.PHONY:outcreate libcreate clean

#a
CC = gcc
SOUCE_DIR = ./src/
BIN_DIR = ./bin/
OBJ = $(shell ls $(SOUCE_DIR))
HAEDER_DIR = ./include/
LIB_DIR = ./lib/
LIB = $(shell ls $(LIB_DIR))
CREATE_LOG = echo "[*]create files [$@] from [$^]."

outcreate: $(addprefix $(BIN_DIR),$(OBJ:.c=.out))

libcreate: $(addprefix $(LIB_DIR),$(LIB:.c=.lib))


$(addprefix $(BIN_DIR),%.out):$(addprefix $(BIN_DIR),%.o)
	@${CC} $< -o $@
	@${CREATE_LOG}

$(addprefix $(BIN_DIR),%.o):$(addprefix $(SOUCE_DIR),%.c)
	@${CC} -c $< -o $@

$(addprefix $(LIB_DIR),%.lib):$(addprefix $(LIB_DIR),%.o)
	@${CC} -shared $< -o $@
	@${CREATE_LOG}

$(addprefix $(IB_DIR),%.o):$(addprefix $(LIB_DIR),%.c)
	@$(CC) -c $< -o $@

clean:
	@rm -rf $(wildcard $(addprefix $(BIN_DIR),*.o))
	@echo "[*]delete files [$(wildcard $(addprefix $(BIN_DIR),*.o))]."

${LIB}:${LIB:.lib=.o}
