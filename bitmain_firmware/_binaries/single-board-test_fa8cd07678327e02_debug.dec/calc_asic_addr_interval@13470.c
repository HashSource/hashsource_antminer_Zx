int __cdecl calc_asic_addr_interval(int actual_asic_number)
{
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  int i; // [sp+40Ch] [bp+40Ch]

  i = 0;
  if ( actual_asic_number == 1 )
  {
    i = 1;
    return 256 / i;
  }
  if ( actual_asic_number == 2 )
  {
    i = 2;
    return 256 / i;
  }
  if ( actual_asic_number > 2 && actual_asic_number <= 4 )
  {
    i = 4;
    return 256 / i;
  }
  if ( actual_asic_number > 4 && actual_asic_number <= 8 )
  {
    i = 8;
    return 256 / i;
  }
  if ( actual_asic_number > 8 && actual_asic_number <= 16 )
  {
    i = 16;
    return 256 / i;
  }
  if ( actual_asic_number > 16 && actual_asic_number <= 32 )
  {
    i = 32;
    return 256 / i;
  }
  if ( actual_asic_number > 32 && actual_asic_number <= 64 )
  {
    i = 64;
    return 256 / i;
  }
  if ( actual_asic_number > 64 && actual_asic_number <= 128 )
  {
    i = 128;
    return 256 / i;
  }
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 3) )
  {
    snprintf(tmp42, 0x400u, "actual_asic_number = %d, but it is error\n", actual_asic_number);
    applog(4, tmp42, 0);
  }
  return -1;
}
