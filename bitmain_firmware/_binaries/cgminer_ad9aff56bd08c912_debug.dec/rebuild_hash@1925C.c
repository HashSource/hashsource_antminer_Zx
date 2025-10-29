void __fastcall rebuild_hash(work *work)
{
  if ( opt_scrypt )
    scrypt_regenhash(work);
  else
    regen_hash(work);
}
