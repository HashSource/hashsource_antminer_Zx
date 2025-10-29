int __fastcall sub_59F7C(__int64 a1, __int64 a2)
{
  __int64 v3; // [sp+8h] [bp-8h] BYREF

  if ( a2 )
    return _gnu_uldivmod_helper(a1, a2, &v3);
  else
    return raise(8);
}
