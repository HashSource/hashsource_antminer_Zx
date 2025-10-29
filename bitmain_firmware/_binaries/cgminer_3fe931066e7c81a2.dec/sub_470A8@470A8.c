int sub_470A8()
{
  int *v0; // r9
  int v1; // r8
  int v2; // r6
  int v3; // r4
  int v4; // t1
  char *v6; // r11
  int *v7; // r7
  int v8; // r5
  int v9; // r0
  int v10; // t1
  const char *v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // t1
  FILE *v15; // r6
  int i; // r5
  int v17; // t1
  int j; // r4
  int *v19; // r3
  _DWORD v20[9]; // [sp+14h] [bp-1028h] BYREF
  char s[4100]; // [sp+38h] [bp-1004h] BYREF

  v0 = dword_7C130;
  if ( dword_7C130[0] > 0 )
  {
    v1 = 644283;
    v2 = 0;
    v3 = 0;
    memset(v20, 0, sizeof(v20));
    while ( 1 )
    {
      v4 = *(unsigned __int8 *)++v1;
      if ( v4 != 1 )
        goto LABEL_4;
      v6 = (char *)v20 + 9 * v3;
      v7 = &dword_7C130[3 * v3 + 60];
      v8 = 0;
      *((_BYTE *)v20 + v2) = 78;
      do
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          snprintf(s, 0x1000u, "pic write chain%d asic%d freq %d\n", v3, v8, v7[1]);
          sub_38730(5, s, 0);
          v14 = v7[1];
          ++v7;
          v9 = v14;
          if ( v14 == 100 )
          {
LABEL_17:
            LOBYTE(v12) = 0;
            goto LABEL_14;
          }
        }
        else
        {
          v10 = v7[1];
          ++v7;
          v9 = v10;
          if ( v10 == 100 )
            goto LABEL_17;
        }
        v11 = "d";
        v12 = 1;
        while ( 1 )
        {
          v13 = *((_DWORD *)v11 + 4);
          v11 += 16;
          if ( v9 == v13 )
            break;
          if ( ++v12 == 115 )
          {
            LOBYTE(v12) = -1;
            break;
          }
        }
LABEL_14:
        ++v8;
        *++v6 = v12;
      }
      while ( v8 != 3 );
      sub_56B3C((_DWORD *)((char *)v20 + 9 * v3 + 1), 2, (int)&unk_69AF8 + 16 * v3);
LABEL_4:
      ++v3;
      v2 += 9;
      if ( v3 == 4 )
      {
        sub_46B94((unsigned __int8 *)v20);
        return 0;
      }
    }
  }
  v15 = fopen("/config/chips_freq.config", "w+");
  if ( v15 )
  {
    for ( i = 644283; i != 644287; ++i )
    {
      v17 = *(unsigned __int8 *)(i + 1);
      if ( v17 == 1 )
      {
        for ( j = 0; j != 3; ++j )
        {
          v19 = &v0[j];
          fprintf(v15, "%d ", v19[61]);
        }
      }
      v0 += 3;
    }
    fclose(v15);
    return 0;
  }
  else if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s open %s failed\n", "scan_freq_save_freq", "/config/chips_freq.config");
    sub_38730(5, s, 0);
    return -1;
  }
  else
  {
    return -1;
  }
}
