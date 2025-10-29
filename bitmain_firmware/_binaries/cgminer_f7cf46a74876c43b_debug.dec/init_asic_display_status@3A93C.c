void init_asic_display_status()
{
  int v0; // r8
  uint8_t *chain_exist; // r11
  int v3; // r6
  int v4; // r6
  int v5; // r10
  unsigned int v6; // r5
  int v7; // r4
  char *v8; // r3
  unsigned int v9; // r3
  char *v10; // r3
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v0 = 0;
  chain_exist = dev.chain_exist;
  do
  {
    if ( *chain_exist++ )
    {
      v3 = chain_exist[520];
      if ( chain_exist[520] )
      {
        v4 = 0;
        v5 = v0;
        v6 = 0;
        do
        {
          v7 = v4 + v6;
          if ( !(v6 << 29) )
          {
            if ( v7 > 19 && (use_syslog || opt_log_output || opt_log_level > 2) )
            {
              snprintf(tmp42, 0x1000u, "offset[%d] ERR", v4 + v6);
              applog(3, tmp42, 0);
            }
            v4 = (unsigned __int8)(v4 + 1);
            v8 = (char *)&dev + v5 * 19 + v7;
            v7 = v6 + v4;
            v8[355] = 32;
          }
          if ( v7 > 19 && (use_syslog || opt_log_output || opt_log_level > 2) )
          {
            snprintf(tmp42, 0x1000u, "offset[%d] ERR", v7);
            applog(3, tmp42, 0);
          }
          dev.chain_asic_status_string[v5][v7] = 111;
          v9 = 3 * v0 + v6;
          v6 = (unsigned __int8)(v6 + 1);
          v10 = (char *)&dev.chain_hw[v9 + 3] + 1;
          v10[3] = 0;
          v10[4] = 0;
          v10[5] = 0;
          v10[6] = 0;
        }
        while ( chain_exist[520] > v6 );
        v3 = v4 + v6;
        if ( v3 > 19 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(tmp42, 0x1000u, "offset[%d] ERR", v3);
          applog(3, tmp42, 0);
        }
      }
      dev.chain_asic_status_string[v0][v3] = 0;
    }
    ++v0;
  }
  while ( v0 != 4 );
}
