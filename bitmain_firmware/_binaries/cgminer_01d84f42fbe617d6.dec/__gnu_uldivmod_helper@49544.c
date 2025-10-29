int __fastcall _gnu_uldivmod_helper(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v5; // r0

  LODWORD(v5) = sub_499D8(a1, HIDWORD(a1), a2, HIDWORD(a2));
  *a3 = a1 - v5 * a2;
  return v5;
}
