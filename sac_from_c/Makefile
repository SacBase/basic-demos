SAC2C := sac2c
SAC4C := sac4c
CC := gcc
NOOUTPUT := >/dev/null 2>&1

.PHONY: all

all: summarizer

%: %.c cwrapper.h
	$(CC) -o $* $*.c `sac4c Sum -ccflags` `sac4c Sum -ldflags`

cwrapper.h: libSumTree.so
	$(SAC4C) Sum

lib%Tree.so: %.sac
	$(SAC2C) $*.sac $(NOOUTPUT)

clean:
	rm -f lib*Mod.so lib*Tree.so lib*Mod.a libcwrapper.a libcwrapper.so
	rm -f cwrapper.h summarizer
