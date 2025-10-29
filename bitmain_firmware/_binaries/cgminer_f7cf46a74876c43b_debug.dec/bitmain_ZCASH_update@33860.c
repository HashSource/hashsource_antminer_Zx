void __fastcall bitmain_ZCASH_update(cgpu_info *bitmain)
{
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "Updated Work!");
    applog(7, tmp42, 0);
  }
  new_block[0] = 1;
  new_block[1] = 1;
  new_block[2] = 1;
  new_block[3] = 1;
}
