_BYTE *__fastcall sub_29688(int a1, int a2)
{
  int v2; // r8
  _BYTE *result; // r0
  _BYTE *v6; // r3
  _BYTE *v7; // r2
  int v8; // r3
  unsigned int v9; // r12
  char v10; // r1
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  v2 = 2 * a2;
  result = calloc(4 - (v2 + 1) % 4 + v2 + 1, 1u);
  if ( !result )
  {
    snprintf(s, 0x1000u, "Failed to calloc in %s %s():%d", "util.c", "bin2hex", 920);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  v6 = result;
  if ( a2 > 0 )
  {
    v7 = result;
    v8 = 0;
    do
    {
      v9 = *(unsigned __int8 *)(a1 + v8++);
      v10 = aClearSock[(v9 & 0xF) + 84];
      LOBYTE(v9) = aClearSock[(v9 >> 4) + 84];
      v7[1] = v10;
      *v7 = v9;
      v7 += 2;
    }
    while ( v8 != a2 );
    v6 = &result[v2];
  }
  *v6 = 0;
  return result;
}
