void __cdecl utils_flip_swab(void *dest_p, const void *src_p, unsigned int length)
{
  unsigned int i; // [sp+1Ch] [bp+1Ch]

  for ( i = 0; length >> 2 > i; ++i )
    *((_DWORD *)dest_p + i) = swab32(*((_DWORD *)src_p + i));
}
