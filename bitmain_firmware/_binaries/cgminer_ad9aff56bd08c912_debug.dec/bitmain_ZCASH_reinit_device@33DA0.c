void __fastcall bitmain_ZCASH_reinit_device(cgpu_info *bitmain)
{
  if ( !status_error )
    j_system("/etc/init.d/cgminer.sh restart > /dev/null 2>&1 &");
}
