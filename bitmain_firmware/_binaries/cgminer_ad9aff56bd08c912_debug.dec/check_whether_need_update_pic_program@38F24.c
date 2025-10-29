void check_whether_need_update_pic_program()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r1
  int v10; // r6
  unsigned __int8 *v11; // r8
  int v12; // r5
  int PIC16F1704_software_version_new; // r4
  unsigned int v14; // r3
  bool v15; // zf
  int v16; // r4
  const char *v17; // r2
  unsigned int v18; // r2
  bool v19; // r3
  uint8_t *chain_exist; // [sp+8h] [bp-100Ch]
  char tmp42[4096]; // [sp+10h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = -27328;
    HIWORD(v0) = (unsigned int)"every_chain_enable_PIC16F1704_dc_dc_new" >> 16;
    v1 = *v0;
    v2 = v0[1];
    v3 = v0[2];
    v4 = v0[3];
    v0 += 4;
    *(_DWORD *)tmp42 = v1;
    *(_DWORD *)&tmp42[4] = v2;
    *(_DWORD *)&tmp42[8] = v3;
    *(_DWORD *)&tmp42[12] = v4;
    v5 = *v0;
    v6 = v0[1];
    v7 = v0[2];
    v8 = v0[3];
    v0 += 4;
    *(_DWORD *)&tmp42[16] = v5;
    *(_DWORD *)&tmp42[20] = v6;
    *(_DWORD *)&tmp42[24] = v7;
    *(_DWORD *)&tmp42[28] = v8;
    v9 = v0[1];
    *(_DWORD *)&tmp42[32] = *v0;
    *(_WORD *)&tmp42[36] = v9;
    applog(5, tmp42, 0);
  }
  v10 = 0;
  chain_exist = dev.chain_exist;
  v11 = pic_version;
  do
  {
    v12 = *chain_exist++;
    if ( v12 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = v10;
      reset_PIC16F1704_pic_new();
      cgsleep_ms(100);
      jump_from_loader_to_app_PIC16F1704_new();
      cgsleep_ms(100);
      PIC16F1704_software_version_new = get_PIC16F1704_software_version_new(&pic_version[v10]);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
      v14 = *v11;
      v15 = v14 == 128;
      if ( v14 <= 0x80 )
        v15 = PIC16F1704_software_version_new == 1;
      if ( v15 )
      {
        do
        {
          pthread_mutex_lock(&iic_mutex);
          i2c_slave_addr = v10;
          PIC1704_update_pic_app_program_new();
          cgsleep_ms(100);
          jump_from_loader_to_app_PIC16F1704_new();
          cgsleep_ms(200);
          v16 = get_PIC16F1704_software_version_new(&pic_version[v10]);
          pthread_mutex_unlock(&iic_mutex);
          cgsleep_ms(100);
          LOWORD(v17) = -27364;
          if ( use_syslog || opt_log_output || opt_log_level > 4 )
          {
            HIWORD(v17) = (unsigned int)"ain_disable_PIC16F1704_dc_dc_new" >> 16;
            snprintf(tmp42, 0x1000u, v17, "check_whether_need_update_pic_program", v10, v12);
            applog(5, tmp42, 0);
          }
          v18 = (unsigned __int8)v12;
          v19 = *v11 != 129 || v16 == 0;
          ++v12;
        }
        while ( v18 <= 2 && v19 );
      }
    }
    ++v10;
    ++v11;
  }
  while ( v10 != 4 );
}
