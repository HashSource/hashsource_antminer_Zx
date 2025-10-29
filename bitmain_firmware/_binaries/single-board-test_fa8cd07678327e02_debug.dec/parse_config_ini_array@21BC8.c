int __cdecl parse_config_ini_array(const char *str, void **pointer)
{
  __int64 v2; // d0
  int v3; // r3
  _QWORD *v4; // r4
  int *v5; // r4
  char item_str[32]; // [sp+8h] [bp+8h] BYREF
  int str_len; // [sp+28h] [bp+28h]
  int i_0; // [sp+2Ch] [bp+2Ch]
  int j; // [sp+30h] [bp+30h]
  int item_str_counter; // [sp+34h] [bp+34h]
  int i; // [sp+38h] [bp+38h]
  void *local_pointer; // [sp+3Ch] [bp+3Ch]
  int item_num; // [sp+40h] [bp+40h]
  int type; // [sp+44h] [bp+44h]
  _BYTE v18[4]; // [sp+48h] [bp+48h] BYREF

  str_len = strlen(str);
  type = 1;
  item_num = 0;
  local_pointer = 0;
  for ( i = 0; i < str_len; ++i )
  {
    if ( str[i] == 46 )
      type = 0;
    if ( str[i] == 44 )
      ++item_num;
  }
  ++item_num;
  if ( type )
  {
    local_pointer = malloc(4 * item_num);
    memset(local_pointer, 0, 4 * item_num);
  }
  else
  {
    local_pointer = malloc(8 * item_num);
    memset(local_pointer, 0, 8 * item_num);
  }
  item_str_counter = 0;
  memset(item_str, 0, sizeof(item_str));
  j = 0;
  for ( i_0 = 0; i_0 < str_len; ++i_0 )
  {
    if ( (unsigned __int8)str[i_0] > 0x2Fu && (unsigned __int8)str[i_0] <= 0x39u || str[i_0] == 46 )
    {
      v3 = item_str_counter++;
      v18[v3 - 64] = str[i_0];
    }
    if ( str[i_0] == 44 || str[i_0] == 93 )
    {
      item_str[item_str_counter] = 0;
      if ( type )
      {
        v5 = (int *)((char *)local_pointer + 4 * j);
        *v5 = atoi(item_str);
      }
      else
      {
        v4 = (char *)local_pointer + 8 * j;
        atof(item_str);
        *v4 = v2;
      }
      ++j;
      memset(item_str, 32, sizeof(item_str));
      item_str_counter = 0;
    }
  }
  *pointer = local_pointer;
  return item_num;
}
