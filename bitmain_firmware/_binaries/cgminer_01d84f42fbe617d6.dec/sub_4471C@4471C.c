int __fastcall sub_4471C(int a1, char *a2)
{
  int v2; // r3
  char *v3; // r12
  unsigned int v4; // r4
  int v5; // lr
  int v6; // t1
  int result; // r0

  v2 = (unsigned __int8)*a2;
  if ( *a2 )
  {
    v3 = a2;
    v4 = 5381;
    do
    {
      v5 = v2 + 32 * v4;
      v6 = (unsigned __int8)*++v3;
      v2 = v6;
      v4 += v5;
    }
    while ( v6 );
  }
  else
  {
    v4 = 5381;
  }
  result = sub_44194(a1, (int *)(*(_DWORD *)(a1 + 4) + 8 * (v4 % dword_56E0C[*(_DWORD *)(a1 + 8)])), a2, v4);
  if ( result )
    result += 4;
  return result;
}
