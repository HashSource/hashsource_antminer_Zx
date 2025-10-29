int __fastcall blake2b_init_param(blake2b_state *S, const blake2b_param *P)
{
  blake2b_state *v4; // r3
  const uint64_t *v5; // r1
  __int64 v6; // r6
  blake2b_state *v7; // r2
  __int64 v8; // t1
  const blake2b_param *v9; // r1
  int v10; // t1
  int v11; // r5
  int v12; // r0

  memset(S, 0, sizeof(blake2b_state));
  v4 = (blake2b_state *)((char *)S - 8);
  v5 = &blake2b_IV[1];
  v6 = 0x6A09E667F3BCC908LL;
  v7 = (blake2b_state *)((char *)S - 8);
  while ( 1 )
  {
    v7->h[1] = v6;
    v7 = (blake2b_state *)((char *)v7 + 8);
    if ( v7 == (blake2b_state *)&S->h[7] )
      break;
    v8 = *v5++;
    v6 = v8;
  }
  v9 = P;
  do
  {
    v10 = v4->h[1];
    v4 = (blake2b_state *)((char *)v4 + 8);
    v9 = (const blake2b_param *)((char *)v9 + 8);
    v11 = *(_DWORD *)&v9[-1].personal[12];
    v12 = HIDWORD(v4->h[0]);
    LODWORD(v4->h[0]) = v10 ^ *(_DWORD *)&v9[-1].personal[8];
    HIDWORD(v4->h[0]) = v12 ^ v11;
  }
  while ( v4 != v7 );
  return 0;
}
