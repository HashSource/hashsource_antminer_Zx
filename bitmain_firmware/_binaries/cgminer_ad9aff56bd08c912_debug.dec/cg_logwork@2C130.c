void __fastcall cg_logwork(work *work, unsigned __int8 *nonce_bin, bool ok)
{
  if ( opt_logwork_path )
    cg_logwork_0(work, nonce_bin, ok);
}
