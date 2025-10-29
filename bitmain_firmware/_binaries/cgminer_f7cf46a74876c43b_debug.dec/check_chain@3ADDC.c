void check_chain()
{
  int v0; // r4
  int v1; // r10
  char *v2; // lr
  bool *v3; // [sp+0h] [bp-1014h]
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "check_chain");
    applog(5, tmp42, 0);
  }
  v0 = 0;
  dev.chain_num = 0;
  v1 = axi_fpga_addr[2];
  v3 = &opt_log_output;
  do
  {
    v2 = (char *)&dev + v0;
    if ( ((v1 >> v0) & 1) != 0 )
    {
      v2[8] = 1;
      ++dev.chain_num;
      if ( use_syslog || *v3 || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "Chain %d existed!", v0, v3);
        applog(5, tmp42, 0);
      }
    }
    else
    {
      v2[8] = 0;
    }
    ++v0;
  }
  while ( v0 != 4 );
}
