void __cdecl equihash_init_algo(void *args)
{
  *((_DWORD *)args + 423) = 140;
  *((_DWORD *)args + 424) = 4;
  *((_DWORD *)args + 425) = 1344;
  *((_DWORD *)args + 426) = 32;
  *((_DWORD *)args + 735) = equihash_target_match;
  *((_DWORD *)args + 734) = equihash_nonce_verify;
}
