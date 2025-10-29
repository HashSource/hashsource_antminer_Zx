void sub_45B50()
{
  int v0; // r5
  int v1; // r1
  unsigned int v2; // r3
  int v3; // r1
  unsigned int v4; // [sp+Ch] [bp-1008h]
  char s[4080]; // [sp+10h] [bp-1004h] BYREF

  v0 = 0;
  dword_9D6CE = 0;
  dword_9D6D2 = 0;
  while ( 1 )
  {
    if ( v0 <= 5 )
      goto LABEL_13;
    if ( (unsigned __int8)byte_9D6CC > 1u )
      break;
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "No %d Fan find, check again", 2);
      sub_38730(5, s, 0);
    }
    v0 = 0;
    sub_2A92C();
LABEL_13:
    v4 = *(_DWORD *)(dword_78E10[0] + 4);
    if ( v4 != -1 )
    {
      v1 = (v4 >> 8) & 7;
      v2 = 120 * (unsigned __int8)v4;
      *(_DWORD *)((char *)&unk_9D4B4 + 4 * v1 + 489) = v2;
      if ( (_BYTE)v4 )
      {
        if ( !*((_BYTE *)&unk_9D4B4 + v1 + 459) )
        {
          *((_BYTE *)&unk_9D4B4 + v1 + 459) = 1;
          ++byte_9D6CC;
          dword_9D4C8 |= 1 << v1;
        }
      }
      else if ( *((_BYTE *)&unk_9D4B4 + v1 + 459) == 1 )
      {
        *((_BYTE *)&unk_9D4B4 + v1 + 459) = v4;
        if ( 1 << v1 )
          v3 = 0;
        else
          v3 = dword_9D4C8 & 1;
        dword_9D4C8 = v3;
        --byte_9D6CC;
      }
      if ( v2 > dword_9D6CE )
        dword_9D6CE = 120 * (unsigned __int8)v4;
      if ( v2 < dword_9D6D2 && v2 || !dword_9D6D2 )
        dword_9D6D2 = 120 * (unsigned __int8)v4;
    }
    ++v0;
    sub_2A92C();
  }
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "fan-num %d fan-map %d\n", (unsigned __int8)byte_9D6CC, dword_9D4C8);
    sub_38730(5, s, 0);
  }
}
