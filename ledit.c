#include <termios.h>
#include <unistd.h>

#include <lua.h>
#include <lauxlib.h>

static void termios_erm(lua_State* L) {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);

  raw.c_lflag &= ~(ECHO);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

static const struct luaL_Reg leditlib [] = {
  {"enable_raw_mode", termios_erm},
  {NULL, NULL}
};
  
int luaopen_leditlib (lua_State *L) {
  luaL_newlib(L, leditlib);
  return 1;
}
