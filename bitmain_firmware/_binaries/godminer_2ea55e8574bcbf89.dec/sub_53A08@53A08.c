int __fastcall sub_53A08(_QWORD *a1, int *a2)
{
  int result; // r0
  int v4; // r2

  result = 0;
  v4 = dword_1741E0 + 1;
  if ( (unsigned int)(dword_1741E0 + 1) >= 0x400000 )
    v4 = 0;
  dword_1741E0 = v4;
  *a1 = *a2;
  return result;
}
