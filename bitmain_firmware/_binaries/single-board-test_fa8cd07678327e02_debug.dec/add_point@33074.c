void __cdecl add_point(int *point, int MAX_SIZE)
{
  if ( ++*point >= MAX_SIZE )
    *point = 0;
}
