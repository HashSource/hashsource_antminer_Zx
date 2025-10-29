int __cdecl blake2b_init0(blake2b_state *S)
{
  int i; // [sp+Ch] [bp+Ch]

  memset(S, 0, sizeof(blake2b_state));
  for ( i = 0; i <= 7; ++i )
    S->h[i] = blake2b_IV[i];
  return 0;
}
