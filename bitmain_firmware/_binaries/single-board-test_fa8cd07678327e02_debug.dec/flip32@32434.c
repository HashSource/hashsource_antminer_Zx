void __cdecl flip32(void *dest_p, const void *src_p)
{
  int i; // [sp+14h] [bp+14h]

  for ( i = 0; i <= 7; ++i )
    *((_DWORD *)dest_p + i) = swab32(*((_DWORD *)src_p + i));
}
