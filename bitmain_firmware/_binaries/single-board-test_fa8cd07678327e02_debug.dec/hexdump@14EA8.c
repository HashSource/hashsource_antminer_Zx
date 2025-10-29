void __cdecl hexdump(const unsigned __int8 *p, unsigned int len)
{
  unsigned __int8 v2; // r1
  int v3; // [sp+0h] [bp-50h] BYREF
  unsigned int lena; // [sp+50h] [bp+0h]
  const unsigned __int8 *pa; // [sp+54h] [bp+4h]
  int pos; // [sp+5Ch] [bp+Ch]
  unsigned __int8 v; // [sp+63h] [bp+13h]
  unsigned __int8 (*p_line)[]; // [sp+64h] [bp+14h]
  int v9; // [sp+68h] [bp+18h]
  unsigned int wordlen; // [sp+6Ch] [bp+1Ch]
  unsigned int addr; // [sp+70h] [bp+20h]
  unsigned int i; // [sp+74h] [bp+24h]

  pa = p;
  lena = len;
  wordlen = 4;
  v9 = 79;
  p_line = (unsigned __int8 (*)[])&v3;
  for ( addr = 0; addr < lena; addr += 16 )
  {
    for ( i = 0; i < 0x50; ++i )
    {
      if ( 2 * (wordlen + 26) == i || 2 * wordlen + 69 == i )
      {
        *((_BYTE *)p_line + i) = 124;
      }
      else if ( 2 * (wordlen + 35) == i )
      {
        *((_BYTE *)p_line + i) = 0;
      }
      else
      {
        *((_BYTE *)p_line + i) = 32;
      }
    }
    for ( i = 0; 2 * wordlen > i; ++i )
    {
      v = addr >> (4 * (2 * wordlen - i - 1));
      *((_BYTE *)p_line + i) = nibble[(addr >> (4 * (2 * wordlen - i - 1))) & 0xF];
    }
    for ( i = 0; i <= 0xF; ++i )
    {
      pos = (i >> 3) + 2 * wordlen + 3;
      if ( addr + i >= lena )
        break;
      v = pa[i + addr];
      *((_BYTE *)p_line + 3 * i + pos) = nibble[v >> 4];
      *((_BYTE *)p_line + 3 * i + pos + 1) = nibble[v & 0xF];
      if ( v <= 0x1Fu || v > 0x7Eu )
        v2 = 46;
      else
        v2 = v;
      *((_BYTE *)p_line + 2 * wordlen + i + 53) = v2;
    }
    fprintf((FILE *)stderr, "%s\n", (const char *)p_line);
  }
}
