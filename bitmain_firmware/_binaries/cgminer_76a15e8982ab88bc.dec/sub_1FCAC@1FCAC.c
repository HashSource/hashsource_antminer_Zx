void __fastcall sub_1FCAC(_DWORD *a1)
{
  char v2[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( sub_18200((int)a1, (_BYTE *)a1 + 129) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(v2, 0x1000u, "Stratum connection to pool %d resumed", *a1);
      sub_385C8(7, v2, 0);
    }
    sub_1FB7C(a1);
  }
}
