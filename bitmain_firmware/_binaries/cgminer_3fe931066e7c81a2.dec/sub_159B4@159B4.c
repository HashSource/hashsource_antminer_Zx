void __fastcall sub_159B4(int a1)
{
  int v2; // r3
  char v3[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( *(_BYTE *)(a1 + 1761) || *(_DWORD *)(a1 + 1728) || *(_BYTE *)(a1 + 1760) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(v3, "Discarded cloned or rolled work");
      sub_38730(7, v3, 0);
    }
  }
  else
  {
    v2 = *(_DWORD *)(a1 + 1748);
    if ( v2 )
    {
      ++*(_DWORD *)(v2 + 156);
      --*(_DWORD *)(*(_DWORD *)(a1 + 1748) + 64);
      --*(_DWORD *)(*(_DWORD *)(a1 + 1748) + 68);
    }
    ++*(_QWORD *)&dword_7B7C8;
  }
  sub_15780((void **)a1);
}
