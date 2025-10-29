void __fastcall reg_handle(uint8_t *str, int len, uint32_t chainid)
{
  char v4; // r6
  int v5; // r0
  const char *v6; // r2
  uint32_t p_wr; // r1
  bool v8; // cc
  uint32_t v9; // r3
  char *v10; // r3
  uint8_t v11; // r2
  const char *v12; // r2
  const char *v13; // r2
  _DWORD *v14; // r3
  int v15; // r1
  int v16; // r2
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v4 = chainid;
  v5 = CRC5(str + 2, 0x33u);
  if ( (str[8] & 0x1F) == v5 )
  {
    if ( reg_fifo.reg_value_num > 0x63 || reg_fifo.p_wr > 0x63 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        LOWORD(v14) = -22324;
        HIWORD(v14) = (unsigned int)"02x %02x %02x %02x\n" >> 16;
        v15 = v14[1];
        v16 = v14[2];
        *(_DWORD *)tmp42 = *v14;
        *(_DWORD *)&tmp42[4] = v15;
        *(_DWORD *)&tmp42[8] = v16;
        applog(5, tmp42, 0);
      }
      clear_register_value_buf();
    }
    else
    {
      pthread_mutex_lock(&reg_mutex);
      p_wr = reg_fifo.p_wr;
      v8 = reg_fifo.p_wr > 0x62;
      v9 = reg_fifo.p_wr;
      *(_DWORD *)reg_fifo.reg_buffer[v9].reg_data = *(_DWORD *)(str + 3);
      v10 = (char *)&reg_fifo + v9 * 7;
      v10[17] = str[7];
      v11 = str[2];
      v10[18] = v4;
      v10[12] = v11;
      if ( v8 )
      {
        reg_fifo.p_wr = 0;
      }
      else
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v12) = -22312;
          HIWORD(v12) = (unsigned int)"x %02x\n" >> 16;
          snprintf(tmp42, 0x1000u, v12, "reg_handle", p_wr, reg_fifo.reg_value_num);
          applog(7, tmp42, 0);
        }
        ++reg_fifo.p_wr;
      }
      if ( reg_fifo.reg_value_num > 0x63 )
      {
        reg_fifo.reg_value_num = 100;
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          LOWORD(v13) = -22276;
          HIWORD(v13) = (unsigned int)"Will Clean!" >> 16;
          snprintf(tmp42, 0x1000u, v13, "reg_handle");
          applog(4, tmp42, 0);
        }
      }
      else
      {
        ++reg_fifo.reg_value_num;
      }
      pthread_mutex_unlock(&reg_mutex);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    LOWORD(v6) = -22352;
    HIWORD(v6) = (unsigned int)"02x\n" >> 16;
    snprintf(tmp42, 0x1000u, v6, "reg_handle", v5);
    applog(3, tmp42, 0);
  }
}
