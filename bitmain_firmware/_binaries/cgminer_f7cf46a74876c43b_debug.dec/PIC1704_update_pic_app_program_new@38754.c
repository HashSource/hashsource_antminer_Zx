int PIC1704_update_pic_app_program_new()
{
  int v0; // r4
  FILE *v1; // r0
  FILE *v2; // r5
  unsigned __int8 *v3; // r4
  __int16 v4; // r0
  unsigned __int8 *v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int j; // r4
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
    strcpy(tmp42, "PIC1704_update_pic_app_program_new");
    v0 = (int)&tmp42[34];
    applog(5, tmp42, 0);
  }
  v1 = fopen("/sbin/pic.txt", "r");
  v2 = v1;
  if ( !v1 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return v0;
    snprintf(tmp42, 0x1000u, "%s: open pic16f1704_app_new.txt failed\n", "PIC1704_update_pic_app_program_new");
    goto LABEL_18;
  }
  fseek(v1, 0, 0);
  memset(program_data, 0, sizeof(program_data));
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%s: pic_flash_length = %d\n", "PIC1704_update_pic_app_program_new", 2432);
    applog(5, tmp42, 0);
  }
  v3 = program_data;
  do
  {
    v3 += 2;
    fgets(data_read, 1023, v2);
    v4 = strtoul(data_read, 0, 16);
    *(v3 - 1) = v4;
    *(v3 - 2) = HIBYTE(v4);
  }
  while ( v3 != &program_data[4864] );
  fclose(v2);
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
      snprintf(tmp42, 0x1000u, "%s: set flash pointer error!\n\n", "PIC1704_update_pic_app_program_new");
LABEL_18:
      applog(3, tmp42, 0);
      return v0;
    }
    for ( i = 0; i != 304; ++i )
    {
      v6 = &program_data[16 * i];
      v7 = *(_DWORD *)v6;
      v8 = *((_DWORD *)v6 + 1);
      v9 = *((_DWORD *)v6 + 2);
      v10 = *((_DWORD *)v6 + 3);
      *(_DWORD *)buf = v7;
      *(_DWORD *)&buf[4] = v8;
      *(_DWORD *)&buf[8] = v9;
      *(_DWORD *)&buf[12] = v10;
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "send pic program time: %d", i);
        applog(5, tmp42, 0);
      }
      for ( j = 0; j != 16; ++j )
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, "buf[%d] = 0x%02x", j, buf[j]);
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
    snprintf(tmp42, 0x1000u, "%s: reset pic error!\n\n", "PIC1704_update_pic_app_program_new");
    goto LABEL_18;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
    return 0;
  snprintf(tmp42, 0x1000u, aSEraseFlashErr, "PIC1704_update_pic_app_program_new");
  applog(3, tmp42, 0);
  return 0;
}
