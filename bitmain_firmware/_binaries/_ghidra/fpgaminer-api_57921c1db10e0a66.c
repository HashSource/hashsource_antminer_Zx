// Decompiled: fpgaminer-api_57921c1db10e0a66

int _init(EVP_PKEY_CTX *ctx)

{
    int iVar1;

    iVar1 = FUN_00010b1c();
    return iVar1;
}

undefined4 main(int param_1, undefined4 *param_2)

{
    char cVar1;
    int iVar2;
    char *pcVar3;
    char *pcVar4;
    undefined4 uVar5;
    long lVar6;
    char *pcVar7;
    char cVar8;

    if (param_1 < 2) {
    LAB_00010aa6:
        pcVar7 = "summary";
    } else {
        pcVar7 = (char *)param_2[1];
        cVar1 = *pcVar7;
        if (cVar1 == '-') {
            cVar8 = pcVar7[1];
            if ((cVar8 == '?') || (cVar8 == 'h')) {
                if (pcVar7[2] == '\0')
                    goto LAB_000109e8;
                goto LAB_00010a06;
            }
            iVar2 = strcmp(pcVar7, "--help");
            if (iVar2 == 0)
                goto LAB_000109e8;
        LAB_00010a88:
            if ((cVar8 != 'o') || (pcVar7[2] != '\0'))
                goto LAB_00010a1c;
            DAT_000211b0 = 1;
            if (param_1 == 2)
                goto LAB_00010aa6;
            iVar2 = 2;
        } else {
        LAB_00010a06:
            iVar2 = strcmp(pcVar7, "--help");
            if (iVar2 == 0) {
            LAB_000109e8:
                fprintf(stderr, "usAge: %s [command [ip/host [port]]]\n",
                        *param_2);
                return 1;
            }
            if (cVar1 == '-') {
                cVar8 = pcVar7[1];
                goto LAB_00010a88;
            }
        LAB_00010a1c:
            iVar2 = 1;
        }
        pcVar3 = (char *)FUN_00010bcc(param_2[iVar2]);
        pcVar7 = "summary";
        if (*pcVar3 != '\0') {
            pcVar7 = pcVar3;
        }
        if (iVar2 + 1 < param_1) {
            pcVar4 = (char *)FUN_00010bcc(param_2[iVar2 + 1]);
            pcVar3 = "127.0.0.1";
            if (*pcVar4 != '\0') {
                pcVar3 = pcVar4;
            }
            if ((iVar2 + 2 < param_1) &&
                (pcVar4 = (char *)FUN_00010bcc(param_2[iVar2 + 2]),
                 *pcVar4 != '\0')) {
                lVar6 = strtol(pcVar4, (char **)0x0, 10);
                iVar2 = (int)(short)lVar6;
            } else {
                iVar2 = 0xfbc;
            }
            goto LAB_00010aba;
        }
    }
    iVar2 = 0xfbc;
    pcVar3 = "127.0.0.1";
LAB_00010aba:
    uVar5 = callapi(pcVar7, pcVar3, iVar2);
    return uVar5;
}

void _INIT_1(void)

{
    return;
}

void _start(undefined4 param_1)

{
    undefined4 in_stack_00000000;

    __libc_start_main(0x109c5, in_stack_00000000, &stack0x00000004, 0x10ec5,
                      0x10f05, param_1);
    /* WARNING: Subroutine does not return */
    abort();
}

/* WARNING: Removing unreachable block (ram,0x00010b30) */

void FUN_00010b1c(void)

{
    __gmon_start__();
    return;
}

/* WARNING: Removing unreachable block (ram,0x00010b50) */
/* WARNING: Removing unreachable block (ram,0x00010b5a) */

void FUN_00010b40(void)

{
    return;
}

void _FINI_0(void)

{
    if (DAT_000211ac == '\0') {
        FUN_00010b40();
        DAT_000211ac = '\x01';
    }
    return;
}

/* WARNING: Removing unreachable block (ram,0x00010b80) */
/* WARNING: Removing unreachable block (ram,0x00010bc8) */
/* WARNING: Removing unreachable block (ram,0x00010b8a) */

void _INIT_0(void)

{
    return;
}

byte *FUN_00010bcc(byte *param_1)

{
    byte *pbVar1;
    ushort **ppuVar2;
    byte *pbVar3;
    byte *pbVar4;

    ppuVar2 = __ctype_b_loc();
    do {
        pbVar3 = param_1;
        param_1 = pbVar3 + 1;
    } while (((*ppuVar2)[*pbVar3] & 0x2000) != 0);
    pbVar4 = (byte *)__rawmemchr(pbVar3, (*ppuVar2)[*pbVar3] & 0x2000);
    while (pbVar3 < pbVar4) {
        pbVar1 = pbVar4 + -1;
        pbVar4 = pbVar4 + -1;
        if ((int)((uint)(*ppuVar2)[*pbVar1] << 0x12) < 0) {
            *pbVar4 = 0;
        }
    }
    return pbVar3;
}

void display(char *param_1)

{
    char *pcVar1;
    char *pcVar2;
    ushort **ppuVar3;
    char *pcVar4;
    char *pcVar5;
    int iVar6;
    char *pcVar7;
    char *pcVar8;

    if (param_1 == (char *)0x0) {
        return;
    }
LAB_00010c38:
    do {
        pcVar1 = strchr(param_1, 0x7c);
        if (pcVar1 == (char *)0x0) {
            if (*param_1 == '\0') {
                return;
            }
            pcVar7 = (char *)0x0;
        } else {
            pcVar7 = pcVar1 + 1;
            *pcVar1 = '\0';
            if (*param_1 == '\0') {
                param_1 = pcVar7;
                if (pcVar7 == (char *)0x0) {
                    return;
                }
                goto LAB_00010c38;
            }
        }
        iVar6 = 0;
        do {
            pcVar1 = strchr(param_1, 0x2c);
            if (pcVar1 == (char *)0x0) {
                if (*param_1 == '\0')
                    break;
                pcVar2 = strchr(param_1, 0x3d);
                pcVar5 = (char *)0x0;
                pcVar1 = (char *)0x0;
                if (pcVar2 != (char *)0x0)
                    goto LAB_00010c90;
            LAB_00010d02:
                if (iVar6 == 0) {
                LAB_00010d04:
                    pcVar8 = (char *)0x0;
                    pcVar4 = "";
                    pcVar1 = pcVar5;
                    goto LAB_00010cbe;
                }
            LAB_00010d12:
                printf("   [%d] => %s\n", iVar6, param_1);
            } else {
                pcVar5 = pcVar1 + 1;
                *pcVar1 = '\0';
                if (*param_1 != '\0') {
                    pcVar2 = strchr(param_1, 0x3d);
                    pcVar1 = pcVar5;
                    if (pcVar2 == (char *)0x0)
                        goto LAB_00010d02;
                LAB_00010c90:
                    pcVar8 = pcVar2 + 1;
                    *pcVar2 = '\0';
                    if (iVar6 == 0) {
                        pcVar5 = pcVar1;
                        if (pcVar8 == (char *)0x0)
                            goto LAB_00010d04;
                        ppuVar3 = __ctype_b_loc();
                        pcVar4 = "";
                        if (((*ppuVar3)[(byte)pcVar2[1]] & 0x800) != 0) {
                            pcVar4 = pcVar8;
                        }
                    LAB_00010cbe:
                        printf("[%s%s] =>\n(\n", param_1, pcVar4);
                    }
                    pcVar5 = pcVar1;
                    if (pcVar8 == (char *)0x0)
                        goto LAB_00010d12;
                    printf("   [%s] => %s\n", param_1, pcVar8);
                }
            }
            param_1 = pcVar5;
            iVar6 = iVar6 + 1;
        } while (param_1 != (char *)0x0);
        puts(")");
        param_1 = pcVar7;
        if (pcVar7 == (char *)0x0) {
            return;
        }
    } while (true);
}

undefined4 callapi(char *param_1, char *param_2, uint param_3)

{
    hostent *phVar1;
    int __fd;
    int iVar2;
    size_t sVar3;
    ssize_t sVar4;
    char *pcVar5;
    undefined4 uVar6;
    int *piVar7;
    char *pcVar8;
    int iVar9;
    char *__buf;
    sockaddr local_30;

    phVar1 = gethostbyname(param_2);
    if (phVar1 == (hostent *)0x0) {
        printf("Couldn\'t get hostname: \'%s\'\n", param_2);
        return 1;
    }
    __fd = socket(2, 1, 0);
    if (__fd == -1) {
        piVar7 = __errno_location();
        pcVar5 = strerror(*piVar7);
        printf("Socket initialisation failed: %s\n", pcVar5);
        return 1;
    }
    iVar9 = 0;
    local_30.sa_data[6] = '\0';
    local_30.sa_data[7] = '\0';
    local_30.sa_data[8] = '\0';
    local_30.sa_data[9] = '\0';
    local_30.sa_data[10] = '\0';
    local_30.sa_data[0xb] = '\0';
    local_30.sa_data[0xc] = '\0';
    local_30.sa_data[0xd] = '\0';
    local_30.sa_data._2_4_ = *(undefined4 *)*phVar1->h_addr_list;
    local_30.sa_data._0_2_ =
        (ushort)((param_3 & 0xff) << 8) | (ushort)(param_3 >> 8) & 0xff;
    local_30.sa_family = 2;
    iVar2 = connect(__fd, &local_30, 0x10);
    if (iVar2 < 0) {
        piVar7 = __errno_location();
        pcVar5 = strerror(*piVar7);
        printf("Socket connect failed: %s\n", pcVar5);
        return 1;
    }
    sVar3 = strlen(param_1);
    sVar4 = send(__fd, param_1, sVar3, 0);
    if (sVar4 < 0) {
        piVar7 = __errno_location();
        uVar6 = 1;
        pcVar5 = strerror(*piVar7);
        printf("Send failed: %s\n", pcVar5);
    LAB_00010e00:
        close(__fd);
    } else {
        pcVar5 = (char *)malloc(0x10000);
        if (pcVar5 == (char *)0x0) {
            printf("Err: OOM (%d)\n", 0x10000);
            uVar6 = 1;
        } else {
            iVar2 = 0xffff;
            do {
                do {
                    __buf = pcVar5 + iVar9;
                    sVar4 = recv(__fd, __buf, iVar2 - iVar9, 0);
                    iVar9 = iVar9 + sVar4;
                    if (sVar4 < 0) {
                        piVar7 = __errno_location();
                        uVar6 = 1;
                        pcVar8 = strerror(*piVar7);
                        printf("Recv failed: %s\n", pcVar8);
                    LAB_00010e28:
                        *__buf = '\0';
                        if (DAT_000211b0 == 0) {
                            printf("Reply was \'%s\'\n", pcVar5);
                            display(pcVar5);
                        } else {
                            puts(pcVar5);
                        }
                        goto LAB_00010e00;
                    }
                    if (sVar4 == 0) {
                        uVar6 = 0;
                        goto LAB_00010e28;
                    }
                } while (iVar2 != iVar9);
                sVar3 = iVar2 + 0x10000;
                iVar2 = iVar2 + 0xffff;
                pcVar5 = (char *)realloc(pcVar5, sVar3);
            } while (pcVar5 != (char *)0x0);
            printf("Err: OOM (%d)\n", sVar3);
            uVar6 = 1;
        }
    }
    return uVar6;
}

void __libc_csu_init(EVP_PKEY_CTX *param_1, undefined4 param_2,
                     undefined4 param_3, undefined4 param_4)

{
    undefined **ppuVar1;
    int iVar2;

    _init(param_1);
    iVar2 = 0;
    do {
        ppuVar1 = &__DT_INIT_ARRAY + iVar2;
        iVar2 = iVar2 + 1;
        (*(code *)*ppuVar1)(param_1, param_2, param_3, *ppuVar1, param_4);
    } while (iVar2 != 2);
    return;
}

void __libc_csu_fini(void)

{
    return;
}

void _fini(void)

{
    return;
}
