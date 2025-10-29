int __fastcall sub_30824(unsigned int *a1, int a2, int a3, int a4)
{
  char *v4; // r1
  int result; // r0

  if ( a4 )
    v4 = "{\"STATUS\":\"BYE\"";
  else
    v4 = "BYE";
  result = sub_307D8(a1, v4);
  byte_75AEC = 1;
  byte_75AEE = 1;
  return result;
}
