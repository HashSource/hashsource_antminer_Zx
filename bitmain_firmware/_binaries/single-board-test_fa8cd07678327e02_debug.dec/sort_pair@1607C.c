void __cdecl sort_pair(uint32_t *a, uint32_t len)
{
  uint32_t tmp; // [sp+8h] [bp+8h]
  uint32_t *b; // [sp+Ch] [bp+Ch]
  uint32_t i; // [sp+10h] [bp+10h]
  uint32_t need_sorting; // [sp+14h] [bp+14h]

  b = &a[len];
  need_sorting = 0;
  for ( i = 0; i < len; ++i )
  {
    if ( need_sorting || a[i] > b[i] )
    {
      need_sorting = 1;
      tmp = a[i];
      a[i] = b[i];
      b[i] = tmp;
    }
    else if ( a[i] < b[i] )
    {
      return;
    }
  }
}
