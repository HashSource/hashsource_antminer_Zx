void __cdecl Sha256_Transform(uint32_t *state, const uint32_t *data)
{
  uint32_t v2; // r1
  unsigned int v3; // r2
  int v4; // r3
  unsigned int i; // [sp+68h] [bp+68h]
  unsigned int j; // [sp+6Ch] [bp+6Ch]
  _BYTE v8[4]; // [sp+70h] [bp+70h] BYREF

  for ( j = 0; j <= 7; ++j )
    *(_DWORD *)&v8[4 * j - 104] = state[j];
  for ( j = 0; j <= 0x3F; j += 16 )
  {
    for ( i = 0; i <= 0xF; ++i )
    {
      v2 = (__ROR4__(*(_DWORD *)&v8[4 * ((4 - (_BYTE)i) & 7) - 104], 6)
          ^ __ROR4__(*(_DWORD *)&v8[4 * ((4 - (_BYTE)i) & 7) - 104], 11)
          ^ __ROR4__(*(_DWORD *)&v8[4 * ((4 - (_BYTE)i) & 7) - 104], 25))
         + ((*(_DWORD *)&v8[4 * ((6 - (_BYTE)i) & 7) - 104]
           ^ *(_DWORD *)&v8[4 * ((5 - (_BYTE)i) & 7) - 104])
          & *(_DWORD *)&v8[4 * ((4 - (_BYTE)i) & 7) - 104]
          ^ *(_DWORD *)&v8[4 * ((6 - (_BYTE)i) & 7) - 104])
         + K[i + j];
      if ( j )
      {
        v3 = i;
        *(_DWORD *)&v8[4 * i - 72] = *(_DWORD *)&v8[4 * (i & 0xF) - 72]
                                   + ((*(_DWORD *)&v8[4 * (((_BYTE)i - 15) & 0xF) - 72] >> 3)
                                    ^ __ROR4__(*(_DWORD *)&v8[4 * (((_BYTE)i - 15) & 0xF) - 72], 7)
                                    ^ __ROR4__(*(_DWORD *)&v8[4 * (((_BYTE)i - 15) & 0xF) - 72], 18))
                                   + (__ROR4__(*(_DWORD *)&v8[4 * (((_BYTE)i - 2) & 0xF) - 72], 17)
                                    ^ __ROR4__(*(_DWORD *)&v8[4 * (((_BYTE)i - 2) & 0xF) - 72], 19)
                                    ^ (*(_DWORD *)&v8[4 * (((_BYTE)i - 2) & 0xF) - 72] >> 10))
                                   + *(_DWORD *)&v8[4 * (((_BYTE)i - 7) & 0xF) - 72];
        v4 = *(_DWORD *)&v8[4 * v3 - 72];
      }
      else
      {
        *(_DWORD *)&v8[4 * i - 72] = data[i];
        v4 = *(_DWORD *)&v8[4 * i - 72];
      }
      *(_DWORD *)&v8[4 * ((7 - (_BYTE)i) & 7) - 104] += v2 + v4;
      *(_DWORD *)&v8[4 * ((3 - (_BYTE)i) & 7) - 104] += *(_DWORD *)&v8[4 * ((7 - (_BYTE)i) & 7) - 104];
      *(_DWORD *)&v8[4 * ((7 - (_BYTE)i) & 7) - 104] += ((*(_DWORD *)&v8[4 * ((1 - (_BYTE)i) & 7) - 104]
                                                        | *(_DWORD *)&v8[4 * (-i & 7) - 104])
                                                       & *(_DWORD *)&v8[4 * ((2 - (_BYTE)i) & 7) - 104]
                                                       | *(_DWORD *)&v8[4 * (-i & 7) - 104]
                                                       & *(_DWORD *)&v8[4 * ((1 - (_BYTE)i) & 7) - 104])
                                                      + (__ROR4__(*(_DWORD *)&v8[4 * (-i & 7) - 104], 2)
                                                       ^ __ROR4__(*(_DWORD *)&v8[4 * (-i & 7) - 104], 13)
                                                       ^ __ROR4__(*(_DWORD *)&v8[4 * (-i & 7) - 104], 22));
    }
  }
  for ( j = 0; j <= 7; ++j )
    state[j] += *(_DWORD *)&v8[4 * j - 104];
}
