void __fastcall sub_1174C(char *a1, unsigned int a2)
{
  int v2; // r2
  int v3; // r4
  char v4[1016]; // [sp+8h] [bp-1400h] BYREF
  char v5[4096]; // [sp+408h] [bp-1000h] BYREF

  v2 = 4;
  v3 = 0;
  do
  {
    --v2;
    v3 = (unsigned __int8)a2 + (v3 << 8);
    a2 >>= 8;
  }
  while ( v2 );
  sub_29630(v4, a1, 128);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(v5, 0x1000u, "BENCHFILE nonce %u=0x%08x for work=%s", v3, v3, v4);
    sub_385C8(3, v5, 0);
  }
}
