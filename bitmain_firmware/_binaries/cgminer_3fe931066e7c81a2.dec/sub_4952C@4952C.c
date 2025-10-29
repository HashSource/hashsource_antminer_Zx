int __fastcall sub_4952C(int result, char a2)
{
  if ( *((_BYTE *)&unk_9D4B4 + result + 8) )
  {
    *((_BYTE *)&dword_78E10[864] + result) = a2;
    return sub_481EC(result, 0, 0, 1);
  }
  return result;
}
