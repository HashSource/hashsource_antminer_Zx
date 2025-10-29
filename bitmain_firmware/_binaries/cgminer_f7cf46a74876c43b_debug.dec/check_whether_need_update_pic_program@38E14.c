void check_whether_need_update_pic_program()
{
  int v0; // r6
  unsigned __int8 *v1; // r8
  int v2; // r5
  int PIC16F1704_software_version_new; // r4
  unsigned int v4; // r3
  bool v5; // zf
  int v6; // r4
  unsigned int v7; // r2
  bool v8; // r3
  uint8_t *chain_exist; // [sp+8h] [bp-100Ch]
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "check_whether_need_update_pic_program");
    applog(5, tmp42, 0);
  }
  v0 = 0;
  chain_exist = dev.chain_exist;
  v1 = pic_version;
  do
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = v0;
      reset_PIC16F1704_pic_new();
      cgsleep_ms(100);
      jump_from_loader_to_app_PIC16F1704_new();
      cgsleep_ms(100);
      PIC16F1704_software_version_new = get_PIC16F1704_software_version_new(&pic_version[v0]);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
      v4 = *v1;
      v5 = v4 == 128;
      if ( v4 <= 0x80 )
        v5 = PIC16F1704_software_version_new == 1;
      if ( v5 )
      {
        do
        {
          pthread_mutex_lock(&iic_mutex);
          i2c_slave_addr = v0;
          PIC1704_update_pic_app_program_new();
          cgsleep_ms(100);
          jump_from_loader_to_app_PIC16F1704_new();
          cgsleep_ms(200);
          v6 = get_PIC16F1704_software_version_new(&pic_version[v0]);
          pthread_mutex_unlock(&iic_mutex);
          cgsleep_ms(100);
          if ( use_syslog || opt_log_output || opt_log_level > 4 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "%s: Chain%d pic update for %d times",
              "check_whether_need_update_pic_program",
              v0,
              v2);
            applog(5, tmp42, 0);
          }
          v7 = (unsigned __int8)v2;
          v8 = *v1 != 129 || v6 == 0;
          ++v2;
        }
        while ( v7 <= 2 && v8 );
      }
    }
    ++v0;
    ++v1;
  }
  while ( v0 != 4 );
}
