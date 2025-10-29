void __fastcall bitmain_ZCASH_update(cgpu_info *bitmain)
{
  int *v1; // r3
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v1) = -32336;
    HIWORD(v1) = (unsigned int)"ndle" >> 16;
    v2 = *v1;
    v3 = v1[1];
    v4 = v1[2];
    v5 = v1[3];
    *(_DWORD *)tmp42 = v2;
    *(_DWORD *)&tmp42[4] = v3;
    *(_DWORD *)&tmp42[8] = v4;
    *(_WORD *)&tmp42[12] = v5;
    applog(7, tmp42, 0);
  }
  new_block[0] = 1;
  new_block[1] = 1;
  new_block[2] = 1;
  new_block[3] = 1;
}
