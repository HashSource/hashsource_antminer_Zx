int __fastcall luaL_addstring(const void **a1, char *s)
{
  size_t v4; // r0

  v4 = strlen(s);
  return sub_56A68(a1, s, v4);
}
