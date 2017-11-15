.PHONY:outcreate libcreate clean

CC = gcc
SOUCE_DIR = ./src/
BIN_DIR = ./bin/
OBJ = $(shell ls $(SOUCE_DIR)|grep ".c")
SCP = $(shell ls $(SOUCE_DIR)|grep ".scp")
SCP_USER = "s15023"
SCP_ADDR = "tnct20.tokyo-ct.ac.jp"
SCP_DIR = "/home/kitakosi/PracProg1/2017/3J04"
HAEDER_DIR = ./include/
LIB_DIR = ./lib/
LIB = $(shell ls $(LIB_DIR))
CREATE_LOG = echo "[*]create files [$@] from [$^]."

outcreate: $(addprefix $(BIN_DIR),$(OBJ:.c=.out))

libcreate: $(addprefix $(LIB_DIR),$(LIB:.c=.lib))

scp: $(addprefix $(SOUCE_DIR),$(SCP:.scp=.c))
	@scp $< $(SCP_USER)@$(SCP_ADDR):$(SCP_DIR)


$(addprefix $(BIN_DIR),%.out):$(addprefix $(BIN_DIR),%.o)
	@${CC} $< -o $@
	@${CREATE_LOG}

$(addprefix $(BIN_DIR),%.o):$(addprefix $(SOUCE_DIR),%.c)
	@${CC} -c $< -o $@

$(addprefix $(LIB_DIR),%.lib):$(addprefix $(LIB_DIR),%.o)
	@${CC} -shared $< -o $@
	@${CREATE_LOG}

$(addprefix $(LIB_DIR),%.o):$(addprefix $(LIB_DIR),%.c)
	@$(CC) -c $< -o $@

$(addprefix $(SOUCE_DIR),%.c):$(addprefix $(SOUCE_DIR),%.scp)
	@mv $< $@
	@$(CREATE_LOG)


clean:
	@rm -rf $(wildcard $(addprefix $(BIN_DIR),*.o))
	@echo "[*]delete files [$(wildcard $(addprefix $(BIN_DIR),*.o))]."

${LIB}:${LIB:.lib=.o}
