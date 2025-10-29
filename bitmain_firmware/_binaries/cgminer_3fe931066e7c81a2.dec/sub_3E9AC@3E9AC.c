int __fastcall sub_3E9AC(unsigned int a1)
{
  int v3; // [sp+0h] [bp-8h] BYREF
  unsigned int v4; // [sp+4h] [bp-4h]

  v3 = 32;
  sub_3E6E0(0, (unsigned __int8 *)&v3, 1);
  sleep(1u);
  BYTE1(v3) = 64;
  v4 = (unsigned int)(((double)a1 / 1000.0 - 0.25) / 0.005 + 1.0);
  LOBYTE(v3) = v4;
  return sub_3E6E0(19, (unsigned __int8 *)&v3, 2);
}
