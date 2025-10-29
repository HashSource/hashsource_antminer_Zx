void __fastcall check_every_chain_asic_number(bool whether_update_asic_num)
{
  int *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  uint8_t *chain_exist; // r5
  int i; // r4
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -23760;
    HIWORD(v2) = (unsigned int)"ngth is 0x%08x" >> 16;
    v3 = *v2;
    v4 = v2[1];
    v5 = v2[2];
    v6 = v2[3];
    v2 += 4;
    *(_DWORD *)tmp42 = v3;
    *(_DWORD *)&tmp42[4] = v4;
    *(_DWORD *)&tmp42[8] = v5;
    *(_DWORD *)&tmp42[12] = v6;
    v7 = v2[1];
    v8 = v2[2];
    v9 = v2[3];
    *(_DWORD *)&tmp42[16] = *v2;
    *(_DWORD *)&tmp42[20] = v7;
    *(_DWORD *)&tmp42[24] = v8;
    *(_WORD *)&tmp42[28] = v9;
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    if ( *chain_exist++ )
    {
      update_asic_num[i] = whether_update_asic_num;
      check_asic_reg(i, 0, 0, 1);
    }
    cgsleep_ms(100);
  }
}
