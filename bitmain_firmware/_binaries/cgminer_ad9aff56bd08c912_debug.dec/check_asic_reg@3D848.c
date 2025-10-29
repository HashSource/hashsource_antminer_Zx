void __fastcall check_asic_reg(unsigned __int8 which_chain, unsigned __int8 chip_addr, unsigned __int8 reg, bool mode)
{
  uint32_t v4; // r5
  int v5; // r11
  int v6; // r10
  unsigned int status_cmd; // r0
  int i; // r4
  uint32_t reg_value_num; // r7
  int v10; // r4
  uint32_t p_rd; // r3
  char *v12; // r2
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r3
  const char *v16; // r2
  unsigned int v17; // r1
  const char *v18; // r2
  const char *v19; // r2
  const char *v20; // r2
  const char *v21; // r2
  unsigned __int8 *v22; // r12
  bool *v23; // r0
  int v24; // r1
  int v25; // t1
  const char *v26; // r2
  const char *v27; // r2
  uint8_t regaddr; // [sp+0h] [bp-1044h]
  uint8_t all[4]; // [sp+10h] [bp-1034h]
  int v30; // [sp+18h] [bp-102Ch]
  int16_t v31; // [sp+2Ch] [bp-1018h]
  uint8_t cmd_buf[8]; // [sp+38h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+40h] [bp-1004h] BYREF

  v4 = mode;
  v5 = which_chain;
  *(_DWORD *)cmd_buf = 0;
  v6 = reg;
  *(_DWORD *)all = chip_addr;
  *(_DWORD *)&cmd_buf[3] = 0;
  clear_register_value_buf();
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s: check chain J%d mode %d chipaddr %02x regaddr %02x",
      "check_asic_reg",
      v5,
      v4,
      *(_DWORD *)all,
      v6);
    applog(7, tmp42, 0);
  }
  status_cmd = bm1740_makeup_get_status_cmd(cmd_buf, v4, all[0], v6, regaddr);
  uart_send(v5, cmd_buf, status_cmd);
  if ( !v6 && *((_BYTE *)&axi_fpga_addr + v5 + 3456) )
    dev.chain_asic_num[v5] = 0;
  for ( i = 0; i != 3; ++i )
  {
LABEL_9:
    usleep(0x493E0u);
    pthread_mutex_lock(&reg_mutex);
    reg_value_num = reg_fifo.reg_value_num;
    pthread_mutex_unlock(&reg_mutex);
    if ( reg_value_num )
    {
      v10 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          pthread_mutex_lock(&reg_mutex);
          p_rd = reg_fifo.p_rd;
          v12 = (char *)&reg_fifo + 7 * reg_fifo.p_rd;
          v13 = (unsigned __int8)v12[18];
          if ( v13 == v5 )
            break;
          ++reg_fifo.p_rd;
          if ( p_rd == 99 )
            reg_fifo.p_rd = 0;
          --reg_fifo.reg_value_num;
          if ( use_syslog || opt_log_output || opt_log_level > 4 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "%s: the return data is from chain%d, but it should be from chain%d chipaddr=0x%02x reg=0x%02x\n",
              "check_asic_reg",
              v13,
              v5,
              *(_DWORD *)all,
              v6);
            applog(5, tmp42, 0);
          }
          ++v10;
          pthread_mutex_unlock(&reg_mutex);
          if ( reg_value_num == v10 )
          {
LABEL_25:
            i = 0;
            goto LABEL_9;
          }
        }
        v14 = (unsigned __int8)v12[17];
        v15 = bswap32(*(_DWORD *)reg_fifo.reg_buffer[reg_fifo.p_rd].reg_data);
        if ( v6 )
        {
          switch ( v6 )
          {
            case 12:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                LOWORD(v16) = -23976;
                HIWORD(v16) = (unsigned int)"om chain%d chipaddr=0x%02x reg=0x%02x\n" >> 16;
                snprintf(tmp42, 0x1000u, v16, "check_asic_reg", v15);
LABEL_31:
                applog(5, tmp42, 0);
              }
              break;
            case 20:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                LOWORD(v20) = -23948;
                HIWORD(v20) = (unsigned int)"eg=0x%02x\n" >> 16;
                snprintf(tmp42, 0x1000u, v20, "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
            case 28:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                LOWORD(v21) = -23920;
                HIWORD(v21) = (unsigned int)"ress is 0x%08x" >> 16;
                snprintf(tmp42, 0x1000u, v21, "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
            case 32:
              if ( (v15 & 0xC0000000) == 0 )
              {
                v22 = TempChipAddr;
                v23 = g_chip_temp_return[(__int16)v5][0];
                v31 = (unsigned __int8)v15 - 64;
                v30 = v15 & 0xFF00;
                v24 = 4 * (__int16)v5;
                do
                {
                  v25 = *v22++;
                  if ( v14 == v25 )
                  {
                    if ( (v15 & 0xFF00) != 0 )
                    {
                      switch ( v30 )
                      {
                        case 256:
                          v23[1] = 1;
                          dev.chain_asic_temp[0][v24 - v5][1] = v31;
                          break;
                        case 4352:
                          send_back_gTempOffsetValue[v24] = v15;
                          v23[2] = 1;
                          break;
                        case 65024:
                          sensor_id[v24] = v15;
                          v23[3] = 1;
                          break;
                      }
                    }
                    else
                    {
                      *v23 = 1;
                      dev.chain_asic_temp[0][v24 - v5][0] = v31;
                    }
                  }
                  ++v24;
                  v23 += 4;
                }
                while ( v24 != 4 * (__int16)v5 + 3 );
              }
              break;
            case 84:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                LOWORD(v26) = -23892;
                HIWORD(v26) = (unsigned int)" freq is 0x%08x" >> 16;
                snprintf(tmp42, 0x1000u, v26, "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
            default:
              if ( v6 == 48 && (use_syslog || opt_log_output || opt_log_level > 4) )
              {
                LOWORD(v27) = -23852;
                HIWORD(v27) = (unsigned int)"x" >> 16;
                snprintf(tmp42, 0x1000u, v27, "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
          }
        }
        else if ( *((_BYTE *)&axi_fpga_addr + v5 + 3456) )
        {
          ++dev.chain_asic_num[v5];
        }
        else if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          LOWORD(v19) = -24008;
          HIWORD(v19) = (unsigned int)"rom chain%d, but it should be from chain%d chipaddr=0x%02x reg=0x%02x\n" >> 16;
          snprintf(tmp42, 0x1000u, v19, "check_asic_reg", v15);
          goto LABEL_31;
        }
        ++v10;
        ++reg_fifo.p_rd;
        --reg_fifo.reg_value_num;
        if ( reg_fifo.p_rd == 100 )
          reg_fifo.p_rd = 0;
        pthread_mutex_unlock(&reg_mutex);
        if ( reg_value_num == v10 )
          goto LABEL_25;
      }
    }
    usleep((__useconds_t)&loc_1869E + 2);
  }
  if ( !v6 )
  {
    v17 = dev.chain_asic_num[v5];
    if ( dev.max_asic_num_in_one_chain < v17 )
      dev.max_asic_num_in_one_chain = dev.chain_asic_num[v5];
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      LOWORD(v18) = -23816;
      HIWORD(v18) = (unsigned int)"the start nonce offset is 0x%08x" >> 16;
      snprintf(tmp42, 0x1000u, v18, "check_asic_reg", v5, v17);
      applog(5, tmp42, 0);
    }
  }
  clear_register_value_buf();
}
