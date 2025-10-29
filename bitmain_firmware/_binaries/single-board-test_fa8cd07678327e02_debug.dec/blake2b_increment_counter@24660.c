int __cdecl blake2b_increment_counter(blake2b_state *S, const uint64_t inc)
{
  S->t[0] += inc;
  S->t[1] += S->t[0] < inc;
  return 0;
}
