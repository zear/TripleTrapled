ifeq ($(PLATFORM), gcw0)
	CC		:= /opt/gcw0-toolchain/usr/bin/mipsel-linux-gcc
	STRIP		:= /opt/gcw0-toolchain/usr/bin/mipsel-linux-strip
	SYSROOT		:= $(shell $(CC) --print-sysroot)
	CFLAGS		:= $(shell $(SYSROOT)/usr/bin/sdl-config --cflags)
	CFLAGS		+= -DNO_FRAMELIMIT
	LDFLAGS		:= $(shell $(SYSROOT)/usr/bin/sdl-config --libs) -lm
	RELEASEDIR	:= release
endif

CC		?= gcc
STRIP		?= strip
CFLAGS		?= -I/usr/include/SDL
LDFLAGS		?= -lSDL -lm
TARGET		?= tt.elf
OBJS		:= block.o board.o fileio.o font.o game.o hiscore.o input.o main.o states.o title.o video.o

ifdef DEBUG
	CFLAGS	+= -ggdb
else
	CFLAGS	+= -O2
endif

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
ifndef DEBUG
	$(STRIP) $(TARGET)
endif

opk: $(TARGET)
ifeq ($(PLATFORM), gcw0)
	mkdir -p		$(RELEASEDIR)
	cp $(TARGET)		$(RELEASEDIR)
	cp default.gcw0.desktop	$(RELEASEDIR)
	cp tt.png		$(RELEASEDIR)
	cp README.md		$(RELEASEDIR)
	mksquashfs		$(RELEASEDIR) tripleTrapled.opk -all-root -noappend -no-exports -no-xattrs
endif

clean:
	rm -Rf $(TARGET) $(OBJS) $(RELEASEDIR)

