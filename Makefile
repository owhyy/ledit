LUA=lua5.4
CLUA=$(shell pkg-config --cflags ${LUA})

leditlib.so: ledit.c
		$(CC) -O2 $(CLUA) ledit.c -fPIC -shared -o leditlib.so
