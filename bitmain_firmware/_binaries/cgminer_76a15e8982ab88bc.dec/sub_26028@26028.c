int __fastcall sub_26028(const char *a1)
{
  char *v1; // r4
  int v2; // r5

  v1 = sub_25F34(a1);
  v2 = strtol(v1, 0, 10);
  free(v1);
  return v2;
}
