void __fastcall set_freq_asic(unsigned __int8 which_chain, unsigned __int8 which_asic, unsigned int frequency)
{
  const char *v6; // r2
  freq_pll_str *v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int freq; // t1
  uint32_t regaddr; // r3
  uint32_t v12; // [sp+4h] [bp-1020h]
  uint8_t cmd[11]; // [sp+14h] [bp-1010h] BYREF
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  *(_DWORD *)&cmd[7] = 0;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v6) = -26492;
    HIWORD(v6) = (unsigned int)"chainid%d %s: nonce shift = %08x" >> 16;
    v12 = which_asic;
    snprintf(tmp42, 0x1000u, v6, "set_freq_asic", which_chain);
    applog(7, tmp42, 0);
  }
  v7 = freq_pll;
  v8 = 100;
  v9 = 0;
  while ( 1 )
  {
    if ( frequency == v8 )
    {
      regaddr = *(_DWORD *)&_FUNCTION___15596[16 * v9 + 2016];
      goto LABEL_10;
    }
    if ( ++v9 == 119 )
      break;
    freq = v7[1].freq;
    ++v7;
    v8 = freq;
  }
  regaddr = 4194881;
LABEL_10:
  bm1740_makeup_set_config_cmd(cmd, 0, dev.addrInterval * which_asic, 0xCu, regaddr, v12);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(100);
}
