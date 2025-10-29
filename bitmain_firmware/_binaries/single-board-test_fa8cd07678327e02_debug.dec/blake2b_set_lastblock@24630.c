int __cdecl blake2b_set_lastblock(blake2b_state *S)
{
  if ( S->last_node )
    blake2b_set_lastnode(S);
  LODWORD(S->f[0]) = -1;
  HIDWORD(S->f[0]) = -1;
  return 0;
}
