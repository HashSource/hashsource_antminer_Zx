int PIC1704_update_pic_app_program_new()
{
  int v0; // r4
  int *v1; // r5
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r5
  const char *v11; // r1
  const char *v12; // r0
  FILE *v13; // r0
  FILE *v14; // r5
  const char *v15; // r2
  unsigned __int8 *v16; // r4
  __int16 v17; // r0
  const char *v19; // r2
  const char *v20; // r2
  const char *v21; // r2
  unsigned __int8 *v22; // r3
  int v23; // r0
  int v24; // r1
  int v25; // r2
  int v26; // r3
  const char *v27; // r2
  const char *v28; // r5
  int j; // r4
  const char *v30; // r2
  unsigned int i; // [sp+Ch] [bp-23A8h]
  char data_read[8]; // [sp+10h] [bp-23A4h] BYREF
  unsigned __int8 buf[16]; // [sp+18h] [bp-239Ch] BYREF
  char tmp42[4096]; // [sp+28h] [bp-238Ch] BYREF
  unsigned __int8 program_data[5000]; // [sp+1028h] [bp-138Ch] BYREF

  memset(program_data, 0, sizeof(program_data));
  data_read[4] = 0;
  *(_DWORD *)data_read = 0;
  memset(buf, 0, sizeof(buf));
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v1) = -27544;
    HIWORD(v1) = (unsigned int)"t pic error!\n\n" >> 16;
    v2 = *v1;
    v3 = v1[1];
    v4 = v1[2];
    v5 = v1[3];
    v1 += 4;
    *(_DWORD *)tmp42 = v2;
    *(_DWORD *)&tmp42[4] = v3;
    *(_DWORD *)&tmp42[8] = v4;
    *(_DWORD *)&tmp42[12] = v5;
    v6 = *v1;
    v7 = v1[1];
    v8 = v1[2];
    v9 = v1[3];
    v10 = v1[4];
    *(_DWORD *)&tmp42[16] = v6;
    *(_DWORD *)&tmp42[20] = v7;
    *(_DWORD *)&tmp42[24] = v8;
    *(_DWORD *)&tmp42[28] = v9;
    *(_WORD *)&tmp42[32] = v10;
    v0 = (int)&tmp42[34];
    tmp42[34] = BYTE2(v10);
    applog(5, tmp42, 0);
  }
  LOWORD(v11) = -23732;
  LOWORD(v12) = -27760;
  HIWORD(v11) = (unsigned int)"d has %d ASIC" >> 16;
  HIWORD(v12) = (unsigned int)"0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n" >> 16;
  v13 = fopen(v12, v11);
  v14 = v13;
  if ( !v13 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return v0;
    LOWORD(v20) = -27744;
    HIWORD(v20) = (unsigned int)"data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v20, "PIC1704_update_pic_app_program_new");
    goto LABEL_18;
  }
  fseek(v13, 0, 0);
  memset(program_data, 0, sizeof(program_data));
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v15) = -27704;
    HIWORD(v15) = (unsigned int)"x, read_back_data[11] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v15, "PIC1704_update_pic_app_program_new", 2432);
    applog(5, tmp42, 0);
  }
  v16 = program_data;
  do
  {
    v16 += 2;
    fgets(data_read, 1023, v14);
    v17 = strtoul(data_read, 0, 16);
    *(v16 - 1) = v17;
    *(v16 - 2) = HIBYTE(v17);
  }
  while ( v16 != &program_data[4864] );
  fclose(v14);
  v0 = reset_PIC16F1704_pic_new();
  if ( !v0 )
    goto LABEL_11;
  if ( erase_PIC16F1704_app_flash_new() )
  {
    v0 = set_PIC16F1704_flash_pointer_new(6u, 0);
    if ( !v0 )
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        return 0;
      LOWORD(v30) = -27624;
      HIWORD(v30) = (unsigned int)"t" >> 16;
      snprintf(tmp42, 0x1000u, v30, "PIC1704_update_pic_app_program_new");
LABEL_18:
      applog(3, tmp42, 0);
      return v0;
    }
    for ( i = 0; i != 304; ++i )
    {
      v22 = &program_data[16 * i];
      v23 = *(_DWORD *)v22;
      v24 = *((_DWORD *)v22 + 1);
      v25 = *((_DWORD *)v22 + 2);
      v26 = *((_DWORD *)v22 + 3);
      *(_DWORD *)buf = v23;
      *(_DWORD *)&buf[4] = v24;
      *(_DWORD *)&buf[8] = v25;
      *(_DWORD *)&buf[12] = v26;
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        LOWORD(v27) = -27592;
        HIWORD(v27) = (unsigned int)"txt failed\n" >> 16;
        snprintf(tmp42, 0x1000u, v27, i);
        applog(5, tmp42, 0);
      }
      LOWORD(v28) = -27564;
      for ( j = 0; j != 16; ++j )
      {
        HIWORD(v28) = (unsigned int)"ngth = %d\n" >> 16;
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, v28, j, buf[j]);
          applog(7, tmp42, 0);
        }
      }
      send_data_to_PIC16F1704_new(buf);
      write_data_into_PIC16F1704_flash_new();
    }
    v0 = reset_PIC16F1704_pic_new();
    if ( v0 )
      return 1;
LABEL_11:
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    LOWORD(v19) = -27676;
    HIWORD(v19) = (unsigned int)"\n" >> 16;
    snprintf(tmp42, 0x1000u, v19, "PIC1704_update_pic_app_program_new");
    goto LABEL_18;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
    return 0;
  LOWORD(v21) = -27652;
  HIWORD(v21) = (unsigned int)"e_loop = %d\n" >> 16;
  snprintf(tmp42, 0x1000u, v21, "PIC1704_update_pic_app_program_new");
  applog(3, tmp42, 0);
  return 0;
}
