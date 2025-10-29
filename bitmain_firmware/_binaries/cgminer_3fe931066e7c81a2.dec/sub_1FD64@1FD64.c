void __fastcall sub_1FD64(_DWORD *a1)
{
  char v2[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( sub_18C2C((int)a1, (_BYTE *)a1 + 129) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(v2, 0x1000u, "Stratum connection to pool %d resumed", *a1);
      sub_38730(7, v2, 0);
    }
    sub_1FC34(a1);
  }
}
