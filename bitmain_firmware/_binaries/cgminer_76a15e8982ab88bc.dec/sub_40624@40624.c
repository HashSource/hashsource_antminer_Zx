void sub_40624()
{
  FILE *v0; // r0
  FILE *v1; // r5
  _BYTE *v2; // r4
  __int16 v3; // r0
  int i; // r10
  int *v5; // r3
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int j; // r9
  char nptr[8]; // [sp+10h] [bp-23A4h] BYREF
  int v12; // [sp+18h] [bp-239Ch] BYREF
  int v13; // [sp+1Ch] [bp-2398h]
  int v14; // [sp+20h] [bp-2394h]
  int v15; // [sp+24h] [bp-2390h]
  char s[4056]; // [sp+28h] [bp-238Ch] BYREF
  _BYTE v17[5000]; // [sp+1028h] [bp-138Ch] BYREF

  memset(v17, 0, sizeof(v17));
  v13 = 0;
  nptr[0] = 0;
  v14 = 0;
  v12 = 0;
  v15 = 0;
  nptr[1] = 0;
  nptr[2] = 0;
  nptr[3] = 0;
  nptr[4] = 0;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(s, "PIC1704_update_pic_app_program_new");
    sub_385C8(5, s, 0);
  }
  v0 = fopen("/sbin/pic.txt", "r");
  v1 = v0;
  if ( !v0 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
    {
      snprintf(s, 0x1000u, "%s: open pic16f1704_app_new.txt failed\n", "PIC1704_update_pic_app_program_new");
      sub_385C8(3, s, 0);
    }
    return;
  }
  fseek(v0, 0, 0);
  memset(v17, 0, sizeof(v17));
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s: pic_flash_length = %d\n", "PIC1704_update_pic_app_program_new", 2432);
    sub_385C8(5, s, 0);
  }
  v2 = v17;
  do
  {
    fgets(nptr, 1023, v1);
    v3 = strtoul(nptr, 0, 16);
    v2[1] = v3;
    *v2 = HIBYTE(v3);
    v2 += 2;
  }
  while ( v2 != &v17[4864] );
  fclose(v1);
  if ( !sub_3DC38() )
  {
LABEL_11:
    if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
    {
      snprintf(s, 0x1000u, "%s: reset pic error!\n\n", "PIC1704_update_pic_app_program_new");
LABEL_15:
      sub_385C8(3, s, 0);
      return;
    }
    return;
  }
  if ( sub_4057C() )
  {
    if ( !sub_3CCC0(6, 0) )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
      {
        snprintf(s, 0x1000u, "%s: set flash pointer error!\n\n", "PIC1704_update_pic_app_program_new");
        goto LABEL_15;
      }
      return;
    }
    for ( i = 0; i != 304; ++i )
    {
      v5 = (int *)&v17[16 * i];
      v6 = *v5;
      v7 = v5[1];
      v8 = v5[2];
      v9 = v5[3];
      v12 = v6;
      v13 = v7;
      v14 = v8;
      v15 = v9;
      if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
      {
        snprintf(s, 0x1000u, "send pic program time: %d", i);
        sub_385C8(5, s, 0);
      }
      for ( j = 0; j != 16; ++j )
      {
        if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          snprintf(s, 0x1000u, "buf[%d] = 0x%02x", j, *((unsigned __int8 *)&v12 + j));
          sub_385C8(7, s, 0);
        }
      }
      sub_3CE6C((int)&v12);
      sub_3D8E8();
    }
    if ( sub_3DC38() )
      return;
    goto LABEL_11;
  }
  if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(s, 0x1000u, "%s: erase flash error!\n\n", "PIC1704_update_pic_app_program_new");
    goto LABEL_15;
  }
}
