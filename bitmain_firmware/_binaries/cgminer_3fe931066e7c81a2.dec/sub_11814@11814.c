void __fastcall sub_11814(char *a1, unsigned int a2)
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
  sub_296D8(v4, a1, 128);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
  {
    snprintf(v5, 0x1000u, "BENCHFILE nonce %u=0x%08x for work=%s", v3, v3, v4);
    sub_38730(3, v5, 0);
  }
}
