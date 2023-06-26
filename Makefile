include config.mk

SRC = vsleep.c
OBJ = ${SRC:.c=.o}

all: options vsleep

options: 
	@echo vsleep build options:
	@echo "CC = ${CC}"

.c.o:
	${CC} -c $<

#${OBJ}: config.h config.mk
${OBJ}: config.mk

#config.h:
#	cp config.def.h $@

vsleep: ${OBJ}
	${CC} -o $@ ${OBJ}

clean:
	rm -f vlseep *.o

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f vsleep ${DESTDIR}${PREFIX}/bin/
	chmod 755 ${DESTDIR}${PREFIX}/bin/vsleep
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	cp -fv vsleep.1 ${DESTDIR}${MANPREFIX}/man1/
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/vlseep.1


uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/vsleep \
		${DESTDIR}${MANPREFIX}/man1/vsleep.1

.PHONY: all options clean install uninstall
