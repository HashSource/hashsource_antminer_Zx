int __cdecl blake2b_is_lastblock(const blake2b_state *S)
{
  return S->f[0] != 0;
}
