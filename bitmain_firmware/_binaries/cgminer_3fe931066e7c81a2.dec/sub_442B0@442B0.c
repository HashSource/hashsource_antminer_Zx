void sub_442B0()
{
  int v0; // r8
  int i; // r7
  int v3; // r4
  int v4; // r6
  unsigned int v5; // r4
  int v6; // r10
  int v7; // r12
  int v8; // r12
  int v9; // r3
  int v10; // r2
  int v11; // [sp+8h] [bp-100Ch]
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  v0 = 644283;
  for ( i = 0; i != 4; ++i )
  {
    if ( *(unsigned __int8 *)++v0 )
    {
      v3 = *(unsigned __int8 *)(v0 + 521);
      if ( *(_BYTE *)(v0 + 521) )
      {
        v4 = 0;
        v5 = 0;
        v11 = 8 * i;
        v6 = 19 * i + 644276;
        do
        {
          if ( (v5 & 7) == 0 )
          {
            v7 = v5 + v4;
            if ( (int)(v5 + v4) > 19 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
            {
              snprintf(s, 0x1000u, "offset[%d] ERR", v5 + v4);
              sub_38730(3, s, 0);
              v7 = v5 + v4;
            }
            v4 = (unsigned __int8)(v4 + 1);
            *(_BYTE *)(v6 + v7 + 355) = 32;
          }
          v8 = v5 + v4;
          if ( (int)(v5 + v4) > 19 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
          {
            snprintf(s, 0x1000u, "offset[%d] ERR", v5 + v4);
            sub_38730(3, s, 0);
            v8 = v5 + v4;
          }
          *(_BYTE *)(v6 + v8 + 355) = 111;
          v9 = 4 * (3 * i + v5 + 64) + 644276;
          v5 = (unsigned __int8)(v5 + 1);
          v10 = *(_DWORD *)(v9 + 4);
          *(_BYTE *)(v9 + 3) = 0;
          *(_DWORD *)(v9 + 4) = v10 & 0xFF000000;
        }
        while ( *(unsigned __int8 *)(v0 + 521) > v5 );
        v3 = v5 + v4;
        if ( v3 > 19 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf(s, 0x1000u, "offset[%d] ERR", v3);
          sub_38730(3, s, 0);
        }
      }
      else
      {
        v11 = 8 * i;
      }
      *((_BYTE *)&unk_9D4B4 + 2 * v11 + 2 * i + i + v3 + 355) = 0;
    }
  }
}
