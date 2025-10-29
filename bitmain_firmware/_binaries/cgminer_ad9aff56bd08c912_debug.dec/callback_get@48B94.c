int __fastcall callback_get(void *data)
{
  unsigned int v1; // r3
  int (__fastcall *v3)(void *, int, _DWORD); // r3
  int v4; // r0
  int result; // r0

  v1 = *((_DWORD *)data + 257);
  if ( v1 < *((_DWORD *)data + 256) )
    goto LABEL_4;
  v3 = (int (__fastcall *)(void *, int, _DWORD))*((_DWORD *)data + 258);
  *((_DWORD *)data + 257) = 0;
  v4 = v3(data, 1024, *((_DWORD *)data + 259));
  *((_DWORD *)data + 256) = v4;
  if ( (unsigned int)(v4 - 1) <= 0xFFFFFFFD )
  {
    v1 = *((_DWORD *)data + 257);
LABEL_4:
    result = *((unsigned __int8 *)data + v1);
    *((_DWORD *)data + 257) = v1 + 1;
    return result;
  }
  return -1;
}
