void sub_43668()
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

  v0 = 631471;
  for ( i = 0; i != 4; ++i )
  {
    if ( *(unsigned __int8 *)++v0 )
    {
      v3 = *(unsigned __int8 *)(v0 + 489);
      if ( *(_BYTE *)(v0 + 489) )
      {
        v4 = 0;
        v5 = 0;
        v11 = 8 * i;
        v6 = 19 * i + 631464;
        do
        {
          if ( (v5 & 7) == 0 )
          {
            v7 = v5 + v4;
            if ( (int)(v5 + v4) > 19 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
            {
              snprintf(s, 0x1000u, "offset[%d] ERR", v5 + v4);
              sub_385C8(3, s, 0);
              v7 = v5 + v4;
            }
            v4 = (unsigned __int8)(v4 + 1);
            *(_BYTE *)(v6 + v7 + 323) = 32;
          }
          v8 = v5 + v4;
          if ( (int)(v5 + v4) > 19 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
          {
            snprintf(s, 0x1000u, "offset[%d] ERR", v5 + v4);
            sub_385C8(3, s, 0);
            v8 = v5 + v4;
          }
          *(_BYTE *)(v6 + v8 + 323) = 111;
          v9 = 4 * (3 * i + v5 + 56) + 631464;
          v5 = (unsigned __int8)(v5 + 1);
          v10 = *(_DWORD *)(v9 + 4);
          *(_BYTE *)(v9 + 3) = 0;
          *(_DWORD *)(v9 + 4) = v10 & 0xFF000000;
        }
        while ( *(unsigned __int8 *)(v0 + 489) > v5 );
        v3 = v5 + v4;
        if ( v3 > 19 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf(s, 0x1000u, "offset[%d] ERR", v3);
          sub_385C8(3, s, 0);
        }
      }
      else
      {
        v11 = 8 * i;
      }
      *((_BYTE *)&unk_9A2A8 + 2 * v11 + 2 * i + i + v3 + 323) = 0;
    }
  }
}
