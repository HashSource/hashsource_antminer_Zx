void __fastcall digestInit(blake2b_state *S, const int n, const int k)
{
  int v6; // r3
  int v7; // r2
  bool v8; // cf
  int v9; // r3
  blake2b_param P[1]; // [sp+0h] [bp-44h] BYREF

  memset(P, 0, 0x30u);
  *(_WORD *)&P[0].fanout = 257;
  v6 = n * (512 / n);
  *(_DWORD *)&P[0].personal[8] = n;
  v7 = v6 + 7;
  *(_DWORD *)&P[0].personal[12] = k;
  v8 = v6 < 0;
  v9 = v6 & ~(v6 >> 31);
  if ( v8 )
    v9 = v7;
  qmemcpy(P[0].personal, "ZcashPoW", 8);
  P[0].digest_length = v9 >> 3;
  blake2b_init_param(S, P);
}
