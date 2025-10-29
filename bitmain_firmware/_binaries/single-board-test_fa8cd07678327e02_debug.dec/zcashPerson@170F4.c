void __cdecl zcashPerson(uint8_t *person, const int n, const int k)
{
  memcpy(person, "ZcashPoW", 8u);
  *((_DWORD *)person + 2) = n;
  *((_DWORD *)person + 3) = k;
}
