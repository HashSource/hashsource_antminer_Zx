void __fastcall cg_logwork_uint32(work *work, uint32_t nonce, bool ok)
{
  unsigned __int8 nonce_bin[8]; // [sp+0h] [bp-8h] BYREF

  if ( opt_logwork_path )
  {
    *(_DWORD *)nonce_bin = nonce;
    nonce_bin[4] = 0;
    cg_logwork_0(work, nonce_bin, ok);
  }
}
