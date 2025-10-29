void __fastcall sub_3C66C(int a1)
{
  int v2; // r4

  v2 = 22;
  do
  {
    if ( *(int *)(dword_78E10[0] + 48) < 0 )
    {
      *(_DWORD *)(dword_78E10[0] + 48) = a1;
      return;
    }
    usleep(0x1388u);
    --v2;
  }
  while ( v2 );
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    sub_3ADE0();
}
