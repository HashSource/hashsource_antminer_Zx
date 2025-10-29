int __cdecl PIC1704_update_pic_app_program(unsigned int which_i2c, unsigned __int8 which_chain)
{
  unsigned __int8 *v3; // r3
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  unsigned __int8 buf[16]; // [sp+408h] [bp+408h] BYREF
  char data_read[8]; // [sp+418h] [bp+418h] BYREF
  unsigned __int8 program_data[5000]; // [sp+420h] [bp+420h] BYREF
  FILE *pic_program_file; // [sp+17A8h] [bp+17A8h]
  int ret; // [sp+17ACh] [bp+17ACh]
  unsigned int pic_flash_length; // [sp+17B0h] [bp+17B0h]
  unsigned __int8 end_addr_l; // [sp+17B4h] [bp+17B4h]
  unsigned __int8 end_addr_h; // [sp+17B5h] [bp+17B5h]
  unsigned __int8 start_addr_l; // [sp+17B6h] [bp+17B6h]
  unsigned __int8 start_addr_h; // [sp+17B7h] [bp+17B7h]
  unsigned int data_int; // [sp+17B8h] [bp+17B8h]
  unsigned int i; // [sp+17BCh] [bp+17BCh]

  memset(program_data, 0, sizeof(program_data));
  i = 0;
  memset(data_read, 0, 5);
  memset(buf, 0, sizeof(buf));
  data_int = 0;
  start_addr_h = 6;
  start_addr_l = 0;
  end_addr_h = 15;
  end_addr_l = 127;
  pic_flash_length = 0;
  ret = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "--- update pic program\n");
    applog(2, tmp42, 0);
  }
  pic_program_file = fopen("/mnt/card/pic16f1704_app.txt", "r");
  if ( pic_program_file )
  {
    fseek(pic_program_file, 0, 0);
    memset(program_data, 0, sizeof(program_data));
    pic_flash_length = (end_addr_h << 8) + end_addr_l - (start_addr_l + (start_addr_h << 8)) + 1;
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "pic_flash_length = %d\n", pic_flash_length);
      applog(2, tmp42, 0);
    }
    for ( i = 0; i < pic_flash_length; ++i )
    {
      fgets(data_read, 1023, pic_program_file);
      data_int = strtoul(data_read, 0, 16);
      program_data[2 * i] = BYTE1(data_int);
      program_data[2 * i + 1] = data_int;
    }
    fclose(pic_program_file);
    ret = reset_PIC16F1704_pic(which_i2c, which_chain);
    if ( ret )
    {
      ret = erase_PIC16F1704_app_flash(which_i2c, which_chain);
      if ( ret )
      {
        ret = set_PIC16F1704_flash_pointer(which_i2c, which_chain, 6u, 0);
        if ( ret )
        {
          for ( i = 0; 4 * (pic_flash_length >> 5) > i; ++i )
          {
            v3 = &program_data[16 * i];
            v4 = *(_DWORD *)v3;
            v5 = *((_DWORD *)v3 + 1);
            v6 = *((_DWORD *)v3 + 2);
            v7 = *((_DWORD *)v3 + 3);
            *(_DWORD *)buf = v4;
            *(_DWORD *)&buf[4] = v5;
            *(_DWORD *)&buf[8] = v6;
            *(_DWORD *)&buf[12] = v7;
            if ( use_syslog || opt_log_output || opt_log_level > 1 )
            {
              snprintf(tmp42, 0x400u, "send pic program time: %d\n", i);
              applog(2, tmp42, 0);
            }
            send_data_to_PIC16F1704(which_i2c, which_chain, buf);
            write_data_into_PIC16F1704_flash(which_i2c, which_chain);
          }
          ret = reset_PIC16F1704_pic(which_i2c, which_chain);
          if ( ret )
          {
            return 1;
          }
          else
          {
            if ( use_syslog || opt_log_output || opt_log_level > 1 )
            {
              snprintf(tmp42, 0x400u, "!!! %s: reset pic error!\n\n", "PIC1704_update_pic_app_program");
              applog(2, tmp42, 0);
            }
            return 0;
          }
        }
        else
        {
          if ( use_syslog || opt_log_output || opt_log_level > 1 )
          {
            snprintf(tmp42, 0x400u, "!!! %s: set flash pointer error!\n\n", "PIC1704_update_pic_app_program");
            applog(2, tmp42, 0);
          }
          return 0;
        }
      }
      else
      {
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "!!! %s: erase flash error!\n\n", "PIC1704_update_pic_app_program");
          applog(2, tmp42, 0);
        }
        return 0;
      }
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "!!! %s: reset pic error!\n\n", "PIC1704_update_pic_app_program");
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "%s: open pic16f1704_app.txt failed\n", "PIC1704_update_pic_app_program");
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
