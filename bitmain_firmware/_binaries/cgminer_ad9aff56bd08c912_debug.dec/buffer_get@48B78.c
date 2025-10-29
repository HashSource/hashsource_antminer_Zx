int __fastcall buffer_get(void *data)
{
  __int64 v1; // r2

  v1 = *(_QWORD *)((char *)data + 4);
  if ( HIDWORD(v1) >= (unsigned int)v1 )
    return -1;
  LODWORD(v1) = HIDWORD(v1) + 1;
  HIDWORD(v1) = *(unsigned __int8 *)(*(_DWORD *)data + HIDWORD(v1));
  *((_DWORD *)data + 2) = v1;
  return HIDWORD(v1);
}
