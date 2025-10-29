void sub_260FC()
{
  const char *v0; // r3
  char *v1; // r11
  char *v2; // r12
  char *v3; // lr
  const char *v4; // r11
  char *v5; // r12
  const char *v6; // lr
  const char *v7; // r12
  const char *v8; // r2
  const char *v9; // r2
  int v10; // r3
  char *v11; // r3
  int v12; // r3
  int v13; // r3
  const char *v14; // r3
  int v15; // r3
  char *v16; // r3
  int v17; // r0
  int v18; // r1
  int v19; // r12
  int v20; // r3
  bool v21; // zf
  unsigned int v22; // r0
  const char *v23; // [sp+0h] [bp-1034h]
  const char *v24; // [sp+4h] [bp-1030h]
  const char *v25; // [sp+8h] [bp-102Ch]
  const char *v26; // [sp+10h] [bp-1024h]
  char s1; // [sp+2Fh] [bp-1005h] BYREF
  char s[4048]; // [sp+30h] [bp-1004h] BYREF

  byte_7BAC8 = 1;
  immedok((WINDOW *)dword_7B430, 1);
  sub_18AD8();
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            strcpy(s, "[N]ormal [C]lear [S]ilent mode (disable all output)\n");
            sub_18BC0(s);
            v0 = "off";
            if ( byte_7B858 )
              v1 = (char *)"on";
            else
              v1 = "off";
            v23 = v1;
            if ( byte_7BC78 )
              v2 = (char *)"on";
            else
              v2 = "off";
            v24 = v2;
            if ( byte_78E08 )
              v3 = (char *)"on";
            else
              v3 = "off";
            v25 = v3;
            if ( byte_7B380 )
              v4 = "on";
            else
              v4 = "off";
            if ( byte_7B85A )
              v5 = (char *)"on";
            else
              v5 = "off";
            v26 = v5;
            if ( byte_7B940 )
              v6 = "on";
            else
              v6 = "off";
            if ( byte_78E09 )
              v0 = "on";
            if ( byte_77155 )
              v7 = "enabled";
            else
              v7 = "disabled";
            if ( byte_77318 )
              v8 = "enabled";
            else
              v8 = "disabled";
            snprintf(
              s,
              0x1000u,
              "[D]ebug:%s\n"
              "[P]er-device:%s\n"
              "[Q]uiet:%s\n"
              "[V]erbose:%s\n"
              "[R]PC debug:%s\n"
              "[W]orkTime details:%s\n"
              "co[M]pact: %s\n"
              "[T]oggle status switching:%s\n"
              "w[I]descreen:%s\n"
              "[Z]ero statistics\n"
              "[L]og interval:%d\n",
              v0,
              v23,
              v24,
              v25,
              v4,
              v26,
              v6,
              v7,
              v8,
              dword_75DCC);
            sub_18BC0(s);
            strcpy(s, "Select an option or any other key to return\n");
            sub_18BC0(s);
            sub_18B44();
            s1 = wgetch((WINDOW *)stdscr);
            if ( !strncasecmp(&s1, "q", 1u) )
            {
              v9 = "Quiet mode %s\n";
              v10 = (unsigned __int8)byte_7BC78 ^ 1;
              byte_7BC78 ^= 1u;
              if ( v10 )
                v11 = "enabled";
              else
                v11 = "disabled";
              goto LABEL_64;
            }
            if ( !strncasecmp(&s1, "v", 1u) )
            {
              v9 = "Verbose mode %s\n";
              v12 = (unsigned __int8)byte_78E08 ^ 1;
              byte_78E08 ^= 1u;
              if ( v12 )
              {
                byte_7BC78 = 0;
                v11 = "enabled";
              }
              else
              {
                v11 = "disabled";
              }
              goto LABEL_64;
            }
            if ( strncasecmp(&s1, "n", 1u) )
              break;
            byte_78E09 = 0;
            byte_78E08 = 0;
            byte_7BC78 = 0;
            byte_7B380 = 0;
            strcpy(s, "Output mode reset to normal\n");
            byte_7B940 = 0;
            byte_7B858 = 0;
            sub_18BC0(s);
            v17 = sub_17FE4();
            if ( v17 )
              goto LABEL_47;
          }
          if ( strncasecmp(&s1, "d", 1u) )
            break;
          v13 = (unsigned __int8)byte_78E09 ^ 1;
          byte_78E09 ^= 1u;
          byte_78E08 = v13;
          if ( v13 )
          {
            byte_7BC78 = 0;
            v14 = "enabled";
          }
          else
          {
            v14 = "disabled";
          }
          snprintf(s, 0x1000u, "Debug mode %s\n", v14);
          sub_18BC0(s);
        }
        if ( strncasecmp(&s1, "m", 1u) )
          break;
        v15 = (unsigned __int8)byte_7B940 ^ 1;
        byte_7B940 ^= 1u;
        if ( v15 )
          v16 = "enabled";
        else
          v16 = "disabled";
        snprintf(s, 0x1000u, "Compact mode %s\n", v16);
        sub_18BC0(s);
        v17 = sub_17FE4();
        if ( v17 )
LABEL_47:
          sub_18178(v17, v18);
      }
      if ( !strncasecmp(&s1, "p", 1u) )
      {
        v9 = "Per-device stats %s\n";
        v19 = (unsigned __int8)byte_7B858 ^ 1;
        byte_7B858 ^= 1u;
        byte_78E08 = v19;
        if ( v19 )
          v11 = "enabled";
        else
          v11 = "disabled";
        goto LABEL_64;
      }
      if ( !strncasecmp(&s1, "r", 1u) )
      {
        v20 = (unsigned __int8)byte_7B380 ^ 1;
        byte_7B380 ^= 1u;
        v9 = "RPC protocol debugging %s\n";
        if ( v20 )
        {
          byte_7BC78 = 0;
          v11 = "enabled";
        }
        else
        {
          v11 = "disabled";
        }
        goto LABEL_64;
      }
      if ( !strncasecmp(&s1, "c", 1u) )
        goto LABEL_75;
      if ( strncasecmp(&s1, "l", 1u) )
        break;
      v22 = sub_260D0("Interval in seconds");
      if ( v22 <= 0x270F )
      {
        dword_75DCC = v22;
        snprintf(s, 0x1000u, "Log interval set to %d seconds\n", v22);
      }
      else
      {
        strcpy(s, "Invalid selection\n");
      }
      sub_18BC0(s);
    }
    if ( !strncasecmp(&s1, "s", 1u) )
      break;
    if ( !strncasecmp(&s1, "w", 1u) )
    {
      v11 = "enabled";
      v21 = byte_7B85A == 1;
      byte_7B85A ^= 1u;
      v9 = "WorkTime details %s\n";
      if ( v21 )
        v11 = "disabled";
LABEL_64:
      snprintf(s, 0x1000u, v9, v11);
      sub_18BC0(s);
    }
    else if ( !strncasecmp(&s1, "t", 1u) )
    {
      byte_77155 ^= 1u;
    }
    else if ( !strncasecmp(&s1, "i", 1u) )
    {
      byte_77318 ^= 1u;
    }
    else
    {
      if ( strncasecmp(&s1, "z", 1u) )
      {
LABEL_75:
        sub_18AD8();
        goto LABEL_76;
      }
      sub_1B8B4();
    }
  }
  byte_7BB18 = 1;
LABEL_76:
  immedok((WINDOW *)dword_7B430, 0);
  byte_7BAC8 = 0;
}
