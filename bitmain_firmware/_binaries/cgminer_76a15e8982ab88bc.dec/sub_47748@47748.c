void __noreturn sub_47748()
{
  char *v0; // r9
  int v1; // r6
  int v2; // r4
  int v3; // r7
  int v4; // t1
  __int16 *v5; // r5
  int v6; // r4
  int v7; // r11
  int v8; // r10
  int v9; // t1
  int v10; // r3
  char *v11; // r3
  char *v12; // r7
  char *v13; // r8
  __int16 *v14; // r9
  int v15; // r5
  int v16; // r4
  char *v17; // r12
  int v18; // r2
  __int16 v19; // r2
  __int16 v20; // r2
  int v21; // r2
  int v22; // r12
  char *v23; // r0
  int v24; // r1
  int v25; // r2
  char *v26; // [sp+14h] [bp-1028h]
  char *v27; // [sp+14h] [bp-1028h]
  int v28; // [sp+18h] [bp-1024h]
  char v29[4100]; // [sp+38h] [bp-1004h] BYREF

  if ( byte_75C49 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
    {
      v0 = (char *)&unk_9A2A8;
      strcpy(v29, "read_temp_func");
      sub_385C8(7, v29, 0);
    }
    else
    {
      v0 = (char *)&unk_9A2A8;
    }
  }
  else
  {
    v0 = (char *)&unk_9A2A8;
  }
  while ( 1 )
  {
    v1 = 631471;
    sleep(1u);
    v2 = 0;
    v3 = 631471;
    do
    {
      v4 = *(unsigned __int8 *)++v3;
      if ( v4 == 1 && byte_75F2C[v2] )
      {
        sub_475A0((unsigned __int8)v2, 0, 76, 1u);
        sub_475A0((unsigned __int8)v2, 0, 76, 0);
        sub_475A0((unsigned __int8)v2, 1, 76, 1u);
        sub_475A0((unsigned __int8)v2, 1, 76, 0);
      }
      ++v2;
      sub_2A884();
    }
    while ( v2 != 4 );
    v5 = (__int16 *)&unk_9A2A8;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v28 = 0;
    do
    {
      v9 = *(unsigned __int8 *)++v1;
      if ( v9 == 1 && byte_75F2C[v6] )
      {
        v11 = v0;
        v12 = &v0[16 * v6 + 130];
        v13 = (char *)&unk_769F4 + 8 * v6;
        v14 = v5;
        v15 = v6;
        v16 = 0;
        v17 = v11;
        do
        {
          if ( *v13 )
          {
            v28 = 1;
          }
          else
          {
            v18 = v28;
            if ( v13[1] )
              v18 = 1;
            v28 = v18;
          }
          v19 = *((_WORD *)v12 - 1);
          if ( v8 < v19 )
          {
            if ( v19 > 80 && !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
            {
              v8 = v19;
              v26 = v17;
              snprintf(
                v29,
                0x1000u,
                "%s: Chain%d sensor%d local temp is %d `C, higher than MAX_TEMP",
                "read_temp_func",
                v15,
                v16,
                v19);
              sub_385C8(3, v29, 0);
              v17 = v26;
            }
            else
            {
              v8 = v19;
            }
          }
          v20 = *(_WORD *)v12;
          if ( *(__int16 *)v12 > v7 )
          {
            if ( v20 > 110 && !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
            {
              v7 = v20;
              v27 = v17;
              snprintf(
                v29,
                0x1000u,
                "%s: Chain%d sensor%d remote temp is %d `C, higher than MAX_CHIP_TEMP",
                "read_temp_func",
                v15,
                v16,
                v20);
              sub_385C8(3, v29, 0);
              v17 = v27;
            }
            else
            {
              v7 = v20;
            }
          }
          ++v16;
          v13 += 4;
          v12 += 8;
        }
        while ( v16 != 2 );
        v6 = v15;
        v5 = v14;
        v21 = v14[68];
        v0 = v17;
        v22 = v5[64];
        v23 = &v0[4 * v6];
        v24 = v5[65];
        if ( v22 < v21 )
          v22 = v21;
        v25 = v5[69];
        *(_DWORD *)(v23 + 621) = v22 & ~(v22 >> 31);
        if ( v24 >= v25 )
          v25 = v24;
        *(_DWORD *)(v23 + 637) = v25 & ~(v25 >> 31);
      }
      ++v6;
      v5 += 8;
    }
    while ( v6 != 4 );
    *(_DWORD *)(v0 + 514) = v8;
    *(_DWORD *)(v0 + 518) = v7;
    if ( v28 )
    {
      byte_75F66 = 0;
    }
    else
    {
      byte_75F66 = 1;
      if ( !byte_75C7C && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        snprintf(
          v29,
          0x1000u,
          "%s: can't read all sensor's temperature, close PIC and need reboot!!!",
          "read_temp_func");
        sub_385C8(7, v29, 0);
      }
    }
    if ( byte_75F30 )
    {
      v10 = dword_75C50[0];
      v0[502] = 100;
      *(_DWORD *)(v10 + 132) = 6553600;
    }
    else
    {
      sub_45120();
    }
  }
}
