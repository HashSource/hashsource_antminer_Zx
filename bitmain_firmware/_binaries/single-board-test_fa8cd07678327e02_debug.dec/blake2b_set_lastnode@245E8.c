int __cdecl blake2b_set_lastnode(blake2b_state *S)
{
  S->f[1] = -1;
  return 0;
}
