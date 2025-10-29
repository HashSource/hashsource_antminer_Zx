int check_chain()
{
  char tmp42[1024]; // [sp+8h] [bp+0h] BYREF
  int ret; // [sp+408h] [bp+400h]
  unsigned __int8 which_chain; // [sp+40Fh] [bp+407h]

  which_chain = -1;
  ret = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "check_chain");
    applog(2, tmp42, 0);
  }
  cgpu.chain_num = 0;
  ret = read_axi_fpga(2u);
  if ( ret == 1 || ret == 2 || ret == 4 || ret == 8 )
  {
    for ( which_chain = 0; !which_chain; ++which_chain )
    {
      chain_info_0[0].which_chain = 0;
      chain_info_0[0].which_i2c = 0;
      if ( (ret & 1) != 0 )
      {
        cgpu.chain_exist[which_chain] = 1;
        ++cgpu.chain_num;
        gChain = which_chain;
        cgpu.runtime->chain_id = which_chain;
        gI2c = 0;
        chain_info_0[which_chain].which_chain = which_chain;
        chain_info_0[which_chain].which_i2c = gI2c;
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "%s: gChain = %d, gI2c = %d\n", "check_chain", gChain, gI2c);
          applog(2, tmp42, 0);
        }
      }
      else
      {
        cgpu.chain_exist[which_chain] = 0;
      }
    }
    return 0;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "%s: Test zhiju only support 1 plug, but now is 0x%08x\n", "check_chain", ret);
      applog(2, tmp42, 0);
    }
    return -1;
  }
}
