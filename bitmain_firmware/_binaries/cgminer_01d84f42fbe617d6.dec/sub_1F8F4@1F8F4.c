void __fastcall sub_1F8F4(_DWORD *a1)
{
  char v2[2048]; // [sp+0h] [bp-800h] BYREF

  if ( sub_1822C((int)a1, (_BYTE *)a1 + 97) )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf(v2, 0x800u, "Stratum connection to pool %d resumed", *a1);
      sub_38438(7, v2, 0);
    }
    sub_1F7C4(a1);
  }
}
