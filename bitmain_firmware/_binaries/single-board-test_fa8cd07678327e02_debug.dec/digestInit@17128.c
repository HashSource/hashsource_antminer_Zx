void __cdecl digestInit(blake2b_state *S, const int n, const int k)
{
  blake2b_param P[1]; // [sp+10h] [bp+10h] BYREF

  memset(P, 0, sizeof(P));
  P[0].fanout = 1;
  P[0].depth = 1;
  P[0].digest_length = n * (512 / n) / 8;
  zcashPerson(P[0].personal, n, k);
  blake2b_init_param(S, P);
}
