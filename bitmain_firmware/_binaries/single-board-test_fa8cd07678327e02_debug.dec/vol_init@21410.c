int __cdecl vol_init(unsigned __int16 vol)
{
  char tmp42[1026]; // [sp+10h] [bp+8h] BYREF
  unsigned __int16 read_back; // [sp+412h] [bp+40Ah]
  int which_asic; // [sp+414h] [bp+40Ch]

  if ( vol <= 0x384u && vol > 0x2EDu )
  {
    if ( vol == 800 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "setting voltage == configed voltage %d\n", vol);
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      for ( which_asic = 0; which_asic <= 2; ++which_asic )
      {
        read_back = ISL_set_voltage(gChain, 0, isl_dev_addr[which_asic], vol);
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "asic%d read back voltage = %d\n", which_asic, read_back);
          applog(2, tmp42, 0);
        }
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "illeagel setting voltage is %d\n", vol);
      applog(2, tmp42, 0);
    }
    return -1;
  }
}
