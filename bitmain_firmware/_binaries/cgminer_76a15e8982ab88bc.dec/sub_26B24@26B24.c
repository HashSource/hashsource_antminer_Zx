int __fastcall sub_26B24(int a1, int a2, char *a3, const char *a4, const char *a5)
{
  char *v8; // r0
  size_t v9; // r8
  size_t v10; // r8
  char *v11; // r0
  int v12; // r1
  int *v13; // r2
  char v15[4096]; // [sp+8h] [bp-1000h] BYREF

  v8 = sub_2AC38(a3, a1);
  *(_DWORD *)(a1 + 204) = a4;
  *(_DWORD *)(a1 + 208) = a5;
  *(_DWORD *)(a1 + 196) = v8;
  v9 = strlen(a4);
  v10 = v9 + strlen(a5) + 2;
  v11 = (char *)malloc(v10);
  *(_DWORD *)(a1 + 200) = v11;
  if ( !v11 )
  {
    strcpy(v15, "Failed to malloc userpass");
    sub_385C8(3, v15, 1);
    sub_16BE0(1);
  }
  snprintf(v11, v10, "%s:%s", a4, a5);
  v12 = *(_DWORD *)(a1 + 132);
  v13 = (int *)(a2 ^ 1);
  *(_BYTE *)(a1 + 139) = a2 ^ 1;
  if ( v12 != 1 )
  {
    *(_DWORD *)(a1 + 132) = 1;
    v13 = &dword_7840C;
  }
  *(_BYTE *)(a1 + 316) = 1;
  *(_BYTE *)(a1 + 129) = 1;
  if ( v12 != 1 )
    ++*v13;
  pthread_create((pthread_t *)(a1 + 312), 0, (void *(*)(void *))start_routine, (void *)a1);
  if ( a2 )
    return 1;
  pthread_join(*(_DWORD *)(a1 + 312), 0);
  return (unsigned __int8)byte_74148;
}
