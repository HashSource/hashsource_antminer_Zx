_QWORD *__fastcall sub_575D4(__int64 a1)
{
  _QWORD *result; // r0

  result = sub_56924(0x10u);
  if ( result )
  {
    result[1] = a1;
    *(_DWORD *)result = 3;
    *((_DWORD *)result + 1) = 1;
  }
  return result;
}
