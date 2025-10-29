// Alternative name is 'add_item_buf.isra.2'
void __fastcall add_item_buf(K_ITEM *item, const char *str)
{
  const char *name; // r6
  size_t v5; // r0
  int v6; // r7
  size_t v7; // r4
  unsigned int v8; // r1
  size_t v9; // r10
  char *v10; // r6
  int v11; // r11
  int v12; // r3
  const char *v13; // r2
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  name = item->name;
  v5 = strlen(str);
  v6 = *((_DWORD *)name + 1);
  v7 = v5;
  v8 = *((_DWORD *)name + 2);
  v9 = v5 + 1;
  v10 = *(char **)name;
  if ( v6 + 1 + v5 > v8 )
  {
    v11 = v5 + 4097 - (v9 & 0xFFF);
    v10 = (char *)realloc(v10, v8 + v11);
    *(_DWORD *)item->name = v10;
    if ( !v10 )
    {
      LOWORD(v12) = 20356;
      HIWORD(v12) = (unsigned int)&_func___11888.__data.__nusers >> 16;
      LOWORD(v13) = 21128;
      HIWORD(v13) = (unsigned int)"(%s) (%d)" >> 16;
      snprintf(tmp42, 0x1000u, v13, v7, *((_DWORD *)item->name + 2), v11, v12, "add_item_buf", 1179);
      applog(3, tmp42, 1);
      quit(1);
    }
    *((_DWORD *)item->name + 2) += v11;
  }
  memcpy(&v10[v6], str, v9);
  *((_DWORD *)item->name + 1) += v7;
}
