char *__fastcall sub_2AF98(int a1)
{
  char *v1; // r4
  signed int v3; // r5
  char *v4; // r0
  char *v5; // r7
  size_t v6; // r0
  signed int v7; // r4
  __int64 v8; // r0
  __int64 v9; // r8
  char *v11; // r10
  size_t v12; // r11
  size_t v13; // r9
  unsigned int v14; // r0
  bool v15; // cc
  ssize_t v16; // r4
  bool v17; // nf
  int v18; // r4
  size_t v19; // r11
  char *v20; // r0
  struct timeval v21; // [sp+8h] [bp-3014h] BYREF
  struct timeval v22; // [sp+10h] [bp-300Ch] BYREF
  char s[4072]; // [sp+18h] [bp-3004h] BYREF
  char v24[8196]; // [sp+1018h] [bp-2004h] BYREF

  v1 = *(char **)(a1 + 616);
  if ( !strchr(v1, 10) )
  {
    sub_2A7A4(&v21);
    if ( !sub_28A54(a1, 60) )
    {
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        strcpy(v24, "Timed out waiting for data on socket_full");
        sub_385C8(7, v24, 0);
      }
      goto LABEL_18;
    }
    while ( 1 )
    {
      memset(v24, 0, 0x2000u);
      v16 = recv(*(_DWORD *)(a1 + 612), v24, 0x1FFCu, 0);
      if ( !v16 )
        break;
      sub_2A7A4(&v22);
      v17 = v16 < 0;
      v18 = (int)((double)(v22.tv_sec - v21.tv_sec) + (double)(v22.tv_usec - v21.tv_usec) / 1000000.0);
      if ( v17 )
      {
        if ( *_errno_location() != 11 || !sub_28A54(a1, 60 - v18) )
        {
          if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            strcpy(s, "Failed to recv sock in recv_line");
            sub_385C8(7, s, 0);
          }
          goto LABEL_38;
        }
      }
      else
      {
        v11 = *(char **)(a1 + 616);
        v12 = strlen(v24);
        v13 = strlen(v11);
        v14 = v12 + v13 + 1;
        if ( v14 >= *(_DWORD *)(a1 + 620) )
        {
          v19 = (v14 & 0xFFFFE000) + 0x2000;
          v20 = (char *)realloc(v11, v19);
          *(_DWORD *)(a1 + 616) = v20;
          if ( !v20 )
          {
            snprintf(s, 0x1000u, "Failed to realloc pool sockbuf in %s %s():%d", "util.c", "recalloc_sock", 1997);
            sub_385C8(3, s, 1);
            sub_16BE0(1);
          }
          memset(&v20[v13], 0, v19 - v13);
          v11 = *(char **)(a1 + 616);
          *(_DWORD *)(a1 + 620) = v19;
        }
        strcat(v11, v24);
      }
      v15 = v18 <= 59;
      v1 = *(char **)(a1 + 616);
      if ( !v15 || strchr(*(const char **)(a1 + 616), 10) )
        goto LABEL_2;
    }
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      strcpy(s, "Socket closed waiting in recv_line");
      sub_385C8(7, s, 0);
    }
LABEL_38:
    sub_2AE38(a1);
    v1 = *(char **)(a1 + 616);
  }
LABEL_2:
  v3 = strlen(v1);
  v4 = strtok(v1, ptr);
  if ( !v4 )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      strcpy(v24, "Failed to parse a \\n terminated string in recv_line");
      sub_385C8(7, v24, 0);
    }
    goto LABEL_18;
  }
  v5 = _strdup(v4);
  v6 = strlen(v5);
  v7 = v6;
  if ( v3 > (int)(v6 + 1) )
    memmove(*(void **)(a1 + 616), (const void *)(*(_DWORD *)(a1 + 616) + v6 + 1), v3 - v6 + 1);
  else
    **(_BYTE **)(a1 + 616) = 0;
  v8 = *(_QWORD *)(a1 + 560);
  v9 = *(_QWORD *)(a1 + 552) + v7;
  ++*(_QWORD *)(a1 + 544);
  *(_QWORD *)(a1 + 552) = v9;
  *(_QWORD *)(a1 + 560) = v7 + v8;
  if ( !v5 )
  {
LABEL_18:
    v5 = 0;
    sub_29500(a1);
    return v5;
  }
  if ( byte_781A8 && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(v24, 0x1000u, "RECVD: %s", v5);
    sub_385C8(7, v24, 0);
  }
  return v5;
}
