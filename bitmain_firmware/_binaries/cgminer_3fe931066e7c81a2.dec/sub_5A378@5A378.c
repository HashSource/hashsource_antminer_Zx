int __fastcall sub_5A378(int result)
{
  if ( result )
  {
    if ( *(_DWORD *)result == 3 )
      return sub_5CB64(*(_QWORD *)(result + 8));
  }
  return result;
}
