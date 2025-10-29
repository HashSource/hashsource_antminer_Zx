int __fastcall _gnu_ldivmod_helper(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v5; // r0

  LODWORD(v5) = sub_5A0C0(a1, a2);
  *a3 = a1 - a2 * v5;
  return v5;
}
