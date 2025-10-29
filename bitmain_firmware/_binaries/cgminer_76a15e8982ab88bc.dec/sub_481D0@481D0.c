int __fastcall sub_481D0(int result, char a2)
{
  if ( *((_BYTE *)&unk_9A2A8 + result + 8) )
  {
    *((_BYTE *)&dword_75C50[864] + result) = a2;
    return sub_46F24(result, 0, 0, 1);
  }
  return result;
}
