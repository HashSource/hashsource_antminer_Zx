void __fastcall set_frequency_chain(unsigned __int8 which_chain, unsigned int frequency)
{
  int v2; // r5
  freq_pll_str *v4; // r1
  int v5; // r2
  int v6; // r3
  unsigned int freq; // t1
  uint32_t regaddr; // r6
  uint32_t v9; // [sp+4h] [bp-1014h]
  uint8_t cmd[11]; // [sp+Ch] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  v2 = which_chain;
  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  *(_DWORD *)&cmd[7] = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "chainid%d %s freq=%d", which_chain, "set_frequency_chain", frequency);
    applog(5, tmp42, 0);
  }
  v4 = freq_pll;
  v5 = 100;
  v6 = 0;
  while ( 1 )
  {
    if ( frequency == v5 )
    {
      regaddr = *(_DWORD *)&_FUNCTION___15596[16 * v6 + 2016];
      goto LABEL_9;
    }
    if ( ++v6 == 119 )
      break;
    freq = v4[1].freq;
    ++v4;
    v5 = freq;
  }
  regaddr = 4194881;
LABEL_9:
  default_pll_reg = regaddr;
  bm1740_makeup_set_config_cmd(cmd, 1u, 0, 0xCu, regaddr, v9);
  uart_send(v2, cmd, 0xBu);
  dev.freq[v2] = frequency;
  cgsleep_ms(50);
}
