void check_every_chain_asic_pll()
{
  int *v0; // r5
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  uint8_t *chain_exist; // r5
  int v8; // r4
  int v9; // t1
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = -23788;
    HIWORD(v0) = (unsigned int)"%08x" >> 16;
    v1 = *v0;
    v2 = v0[1];
    v3 = v0[2];
    v4 = v0[3];
    v0 += 4;
    *(_DWORD *)tmp42 = v1;
    *(_DWORD *)&tmp42[4] = v2;
    *(_DWORD *)&tmp42[8] = v3;
    *(_DWORD *)&tmp42[12] = v4;
    v5 = v0[1];
    v6 = v0[2];
    *(_DWORD *)&tmp42[16] = *v0;
    *(_DWORD *)&tmp42[20] = v5;
    *(_WORD *)&tmp42[24] = v6;
    tmp42[26] = BYTE2(v6);
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  LOBYTE(v8) = 0;
  do
  {
    v9 = *chain_exist++;
    if ( v9 == 1 )
    {
      check_asic_reg(v8, 0, 0xCu, 1);
      cgsleep_ms(100);
    }
    v8 = (unsigned __int8)(v8 + 1);
  }
  while ( v8 != 4 );
}
