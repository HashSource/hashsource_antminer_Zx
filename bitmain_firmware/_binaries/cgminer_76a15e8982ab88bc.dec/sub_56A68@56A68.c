int __fastcall sub_56A68(const void **a1, void *src, size_t n)
{
  char *v4; // r3
  int v6; // r0
  const void *v8; // r6
  unsigned int v9; // r0
  char *v10; // r8
  void *v11; // r0
  const void *v12; // r2
  char *v13; // r5

  v4 = (char *)a1[1];
  v6 = (int)a1[2];
  if ( v6 - (int)v4 > n )
  {
    v8 = *a1;
LABEL_10:
    memcpy(&v4[(_DWORD)v8], src, n);
    v12 = *a1;
    v13 = (char *)a1[1] + n;
    a1[1] = v13;
    v13[(_DWORD)v12] = 0;
    return 0;
  }
  if ( v6 >= 0 && n != -1 && (unsigned int)v4 <= -2 - n )
  {
    v9 = 2 * v6;
    v10 = &v4[n + 1];
    if ( (unsigned int)v10 < v9 )
      v10 = (char *)v9;
    v11 = sub_56924((size_t)v10);
    v8 = v11;
    if ( v11 )
    {
      memcpy(v11, *a1, (size_t)a1[1]);
      sub_5694C((void *)*a1);
      v4 = (char *)a1[1];
      *a1 = v8;
      a1[2] = v10;
      goto LABEL_10;
    }
  }
  return -1;
}
