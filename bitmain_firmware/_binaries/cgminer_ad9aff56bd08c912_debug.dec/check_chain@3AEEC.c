void check_chain()
{
  _DWORD *v0; // r3
  int v1; // r1
  int v2; // r2
  int v3; // r4
  const char *v4; // r8
  int v5; // r10
  char *v6; // lr
  bool *v7; // [sp+0h] [bp-1014h]
  char tmp42[4096]; // [sp+10h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = -25980;
    HIWORD(v0) = (unsigned int)"ad thread for chain %d failed" >> 16;
    v1 = v0[1];
    v2 = v0[2];
    *(_DWORD *)tmp42 = *v0;
    *(_DWORD *)&tmp42[4] = v1;
    *(_DWORD *)&tmp42[8] = v2;
    applog(5, tmp42, 0);
  }
  v3 = 0;
  dev.chain_num = 0;
  LOWORD(v4) = -26000;
  v5 = axi_fpga_addr[2];
  v7 = &opt_log_output;
  do
  {
    v6 = (char *)&dev + v3;
    if ( ((v5 >> v3) & 1) != 0 )
    {
      v6[8] = 1;
      ++dev.chain_num;
      if ( use_syslog || *v7 || opt_log_level > 4 )
      {
        HIWORD(v4) = (unsigned int)"%d ok" >> 16;
        snprintf(tmp42, 0x1000u, v4, v3, v7);
        applog(5, tmp42, 0);
      }
    }
    else
    {
      v6[8] = 0;
    }
    ++v3;
  }
  while ( v3 != 4 );
}
