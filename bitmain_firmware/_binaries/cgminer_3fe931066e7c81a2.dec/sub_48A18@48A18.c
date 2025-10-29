void __noreturn sub_48A18()
{
  int v0; // r6
  int v1; // r4
  int v2; // r5
  int v3; // t1
  __int16 *v4; // r5
  int v5; // r4
  int v6; // r9
  int v7; // r11
  int v8; // r10
  int v9; // t1
  __int16 *v10; // r7
  _BYTE *v11; // r8
  __int16 *v12; // r3
  int v13; // r5
  int v14; // r4
  __int16 *v15; // r12
  __int16 v16; // r2
  __int16 v17; // r2
  int v18; // r1
  int v19; // r2
  char *v20; // r12
  int v21; // lr
  int v22; // r3
  int v23; // r0
  int i; // r8
  int v25; // r10
  int v26; // r1
  __int16 *v27; // [sp+14h] [bp-1028h]
  __int16 *v28; // [sp+14h] [bp-1028h]
  char v29[4100]; // [sp+38h] [bp-1004h] BYREF

  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(v29, "read_temp_func");
    sub_38730(7, v29, 0);
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v0 = 644283;
      sleep(1u);
      v1 = 0;
      v2 = 644283;
      do
      {
        v3 = *(unsigned __int8 *)++v2;
        if ( v3 == 1 && byte_790EC[v1] )
        {
          for ( i = 0; i != 3; ++i )
          {
            v25 = (unsigned __int8)i;
            v26 = (unsigned __int8)i;
            sub_4886C((unsigned __int8)v1, v26, 76, 1u);
            sub_4886C((unsigned __int8)v1, v25, 76, 0);
          }
        }
        ++v1;
        sub_2A92C();
      }
      while ( v1 != 4 );
      v4 = (__int16 *)&unk_9D4B4;
      v5 = 0;
      v6 = -256;
      v7 = 0;
      v8 = -256;
      do
      {
        v9 = *(unsigned __int8 *)++v0;
        if ( v9 == 1 && byte_790EC[v5] )
        {
          v10 = (__int16 *)((char *)&unk_9D4B4 + 24 * v5 + 130);
          v11 = &byte_79BA4[12 * v5 + 16];
          v12 = v4;
          v13 = v5;
          v14 = 0;
          v15 = v12;
          do
          {
            if ( *v11 )
            {
              v7 = 1;
            }
            else if ( v11[1] )
            {
              v7 = 1;
            }
            v16 = *(v10 - 1);
            if ( v16 > v6 )
            {
              if ( v16 > 80 && !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
              {
                v6 = v16;
                v27 = v15;
                snprintf(
                  v29,
                  0x1000u,
                  "%s: Chain%d sensor%d local temp is %d `C, higher than MAX_TEMP",
                  "read_temp_func",
                  v13,
                  v14,
                  v16);
                sub_38730(3, v29, 0);
                v15 = v27;
              }
              else
              {
                v6 = v16;
              }
            }
            v17 = *v10;
            if ( *v10 > v8 )
            {
              if ( v17 > 110 && !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
              {
                v8 = v17;
                v28 = v15;
                snprintf(
                  v29,
                  0x1000u,
                  "%s: Chain%d sensor%d remote temp is %d `C, higher than MAX_CHIP_TEMP",
                  "read_temp_func",
                  v13,
                  v14,
                  v17);
                sub_38730(3, v29, 0);
                v15 = v28;
              }
              else
              {
                v8 = v17;
              }
            }
            ++v14;
            v11 += 4;
            v10 += 4;
          }
          while ( v14 != 3 );
          v5 = v13;
          v18 = v15[68];
          v4 = v15;
          v19 = v15[64];
          v20 = (char *)&unk_9D4B4 + 4 * v5;
          v21 = v4[65];
          v22 = -256;
          if ( v18 >= v19 )
            v19 = v18;
          if ( v19 < -256 )
            v19 = -256;
          if ( v21 < v4[69] )
            v21 = v4[69];
          if ( v21 >= -256 )
            v22 = v21;
          if ( v4[72] >= v19 )
            v19 = v4[72];
          if ( v4[73] >= v22 )
            v22 = v4[73];
          v23 = (unsigned __int8)byte_78E09;
          *(_DWORD *)(v20 + 653) = v19;
          *(_DWORD *)(v20 + 669) = v22;
          if ( v23 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            snprintf(v29, 0x1000u, "chain%d, max local temp :%d, max remote temp: %d", v5, v19, v22);
            sub_38730(7, v29, 0);
          }
        }
        ++v5;
        v4 += 12;
      }
      while ( v5 != 4 );
      dword_9D6D6 = v6;
      dword_9D6DA = v8;
      if ( !v7 )
        break;
      byte_79126 = 0;
      if ( !byte_790F0 )
        goto LABEL_16;
LABEL_62:
      sub_45D88(100);
    }
    byte_79126 = 1;
    if ( !byte_78E3C && byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(v29, 0x1000u, "%s: can't read all sensor's temperature, close PIC and need reboot!!!", "read_temp_func");
      sub_38730(7, v29, 0);
    }
    if ( byte_790F0 )
      goto LABEL_62;
LABEL_16:
    sub_45EC0();
  }
}
