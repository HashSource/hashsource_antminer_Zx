void sub_44DB4()
{
  int v0; // r5
  int v1; // r1
  unsigned int v2; // r3
  int v3; // r1
  unsigned int v4; // [sp+Ch] [bp-1008h]
  char s[4080]; // [sp+10h] [bp-1004h] BYREF

  v0 = 0;
  dword_9A4A2 = 0;
  dword_9A4A6 = 0;
  while ( 1 )
  {
    if ( v0 <= 5 )
      goto LABEL_13;
    if ( (unsigned __int8)byte_9A4A0 > 1u )
      break;
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(s, 0x1000u, "No %d Fan find, check again", 2);
      sub_385C8(5, s, 0);
    }
    v0 = 0;
    sub_2A884();
LABEL_13:
    v4 = *(_DWORD *)(dword_75C50[0] + 4);
    if ( v4 != -1 )
    {
      v1 = (v4 >> 8) & 7;
      v2 = 120 * (unsigned __int8)v4;
      *(_DWORD *)((char *)&unk_9A2A8 + 4 * v1 + 457) = v2;
      if ( (_BYTE)v4 )
      {
        if ( !*((_BYTE *)&unk_9A2A8 + v1 + 427) )
        {
          *((_BYTE *)&unk_9A2A8 + v1 + 427) = 1;
          ++byte_9A4A0;
          dword_9A2BC |= 1 << v1;
        }
      }
      else if ( *((_BYTE *)&unk_9A2A8 + v1 + 427) == 1 )
      {
        *((_BYTE *)&unk_9A2A8 + v1 + 427) = v4;
        if ( 1 << v1 )
          v3 = 0;
        else
          v3 = dword_9A2BC & 1;
        dword_9A2BC = v3;
        --byte_9A4A0;
      }
      if ( v2 > dword_9A4A2 )
        dword_9A4A2 = 120 * (unsigned __int8)v4;
      if ( v2 < dword_9A4A6 && v2 || !dword_9A4A6 )
        dword_9A4A6 = 120 * (unsigned __int8)v4;
    }
    ++v0;
    sub_2A884();
  }
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "fan-num %d fan-map %d\n", (unsigned __int8)byte_9A4A0, dword_9A2BC);
    sub_385C8(5, s, 0);
  }
}
