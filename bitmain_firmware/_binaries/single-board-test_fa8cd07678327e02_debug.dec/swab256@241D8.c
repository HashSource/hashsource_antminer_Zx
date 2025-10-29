void __cdecl swab256(void *dest_p, void *src_p)
{
  *(_DWORD *)dest_p = bswap32(*((_DWORD *)src_p + 7));
  *((_DWORD *)dest_p + 1) = bswap32(*((_DWORD *)src_p + 6));
  *((_DWORD *)dest_p + 2) = bswap32(*((_DWORD *)src_p + 5));
  *((_DWORD *)dest_p + 3) = bswap32(*((_DWORD *)src_p + 4));
  *((_DWORD *)dest_p + 4) = bswap32(*((_DWORD *)src_p + 3));
  *((_DWORD *)dest_p + 5) = bswap32(*((_DWORD *)src_p + 2));
  *((_DWORD *)dest_p + 6) = bswap32(*((_DWORD *)src_p + 1));
  *((_DWORD *)dest_p + 7) = bswap32(*(_DWORD *)src_p);
}
