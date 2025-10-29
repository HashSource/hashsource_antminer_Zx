int __fastcall sub_30980(unsigned int *a1, int a2, int a3, int a4)
{
  char *v4; // r1
  int result; // r0

  if ( a4 )
    v4 = "{\"STATUS\":\"RESTART\"";
  else
    v4 = "RESTART";
  result = sub_30968(a1, v4);
  byte_78CAC = 1;
  byte_78CAD = 1;
  return result;
}
