void __fastcall regen_hash(work *work)
{
  unsigned __int8 *v1; // r1
  unsigned __int8 *v2; // r2
  unsigned int v3; // t1
  unsigned __int8 *hash; // r5
  char *v5; // r0
  char *v6; // r4
  unsigned __int8 hash1[32]; // [sp+0h] [bp-1074h] BYREF
  unsigned __int8 swap[80]; // [sp+20h] [bp-1054h] BYREF
  char tmp42[4100]; // [sp+70h] [bp-1004h] BYREF

  v1 = &work[-1].device_target[35];
  v2 = &hash1[28];
  do
  {
    v3 = *((_DWORD *)v1 + 1);
    v1 += 4;
    *((_DWORD *)v2 + 1) = bswap32(v3);
    v2 += 4;
  }
  while ( v2 != &swap[76] );
  hash = work->hash;
  sha256(swap, 0x50u, hash1);
  sha256(hash1, 0x20u, hash);
  v5 = bin2hex(hash, 0x20u);
  v6 = v5;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "regen:%s", v5);
    applog(5, tmp42, 0);
    free(v6);
  }
  else
  {
    free(v5);
  }
}
