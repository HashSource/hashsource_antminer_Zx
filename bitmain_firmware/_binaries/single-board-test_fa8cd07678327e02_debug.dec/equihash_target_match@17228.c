bool __cdecl equihash_target_match(unsigned __int8 *result_value, unsigned __int8 *target)
{
  int i; // [sp+Ch] [bp+Ch]

  for ( i = 31; i >= 0; --i )
  {
    if ( result_value[i] < (unsigned int)target[i] )
      return 1;
    if ( result_value[i] > (unsigned int)target[i] )
      return 0;
  }
  return 1;
}
