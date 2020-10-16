AMP = @

AR = ${AMP}ar

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude

RM = ${AMP}rm -f

JULIUS_NAMES = 
JULIUS_NAMES += julius

JULIUS_OBJ_NAMES = ${addsuffix .o, ${JULIUS_NAMES}}
JULIUS_OBJS = ${addprefix build/obj/, ${JULIUS_OBJ_NAMES}}

JULIUS_STATIC_LIB = build/libjulius.a
JULIUS_DYNAMIC_LIB = build/libjulius.so

MAIN_SRC = src/main.c
MAIN_OBJ = build/main.o

BIN = build/julius

default: ${BIN}

debug:
	${eval AMP := }

${MAIN_OBJ}: ${MAIN_SRC}
	${CC} -c $< -o $@ ${INCLUDE_FLAG}

${JULIUS_OBJS}: build/obj/%.o: lib/%.c include/%.h
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${JULIUS_STATIC_LIB}: ${JULIUS_OBJS}
	${AR} rcs $@ $^

${JULIUS_DYNAMIC_LIB}: ${JULIUS_OBJS}
	${CC} -shared $^ -o $@

${BIN}: ${MAIN_OBJ} ${JULIUS_STATIC_LIB}
	${CC} $^ -o $@

lib: ${JULIUS_STATIC_LIB} ${JULIUS_DYNAMIC_LIB}

redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${JULIUS_STATIC_LIB}
	${RM} ${JULIUS_DYNAMIC_LIB}
	${RM} ${MAIN_OBJ}
	${RM} ${JULIUS_OBJS}


