void __fastcall sub_158EC(int a1)
{
  int v2; // r3
  char v3[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( *(_BYTE *)(a1 + 1761) || *(_DWORD *)(a1 + 1728) || *(_BYTE *)(a1 + 1760) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      strcpy(v3, "Discarded cloned or rolled work");
      sub_385C8(7, v3, 0);
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
    ++*(_QWORD *)&dword_785F0;
  }
  sub_156B8((void **)a1);
}
