int __cdecl blake2b_init_param(blake2b_state *S, const blake2b_param *P)
{
  size_t i; // [sp+Ch] [bp+Ch]

  blake2b_init0(S);
  for ( i = 0; i <= 7; ++i )
    S->h[i] ^= load64((char *)P + 8 * i);
  return 0;
}
