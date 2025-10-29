void __fastcall set_freq_asic(unsigned __int8 which_chain, unsigned __int8 which_asic, unsigned int frequency)
{
  freq_pll_str *v6; // r1
  int v7; // r2
  int v8; // r3
  unsigned int freq; // t1
  uint32_t regaddr; // r3
  uint32_t v11; // [sp+4h] [bp-1020h]
  uint8_t cmd[11]; // [sp+14h] [bp-1010h] BYREF
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  *(_DWORD *)&cmd[7] = 0;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "%s %d %d freq=%d\n", "set_freq_asic", which_chain, which_asic, frequency);
    applog(7, tmp42, 0);
  }
  v6 = freq_pll;
  v7 = 100;
  v8 = 0;
  while ( 1 )
  {
    if ( frequency == v7 )
    {
      regaddr = *(_DWORD *)&_FUNCTION___15596[16 * v8 + 2016];
      goto LABEL_10;
    }
    if ( ++v8 == 119 )
      break;
    freq = v6[1].freq;
    ++v6;
    v7 = freq;
  }
  regaddr = 4194881;
LABEL_10:
  bm1740_makeup_set_config_cmd(cmd, 0, dev.addrInterval * which_asic, 0xCu, regaddr, v11);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(100);
}
