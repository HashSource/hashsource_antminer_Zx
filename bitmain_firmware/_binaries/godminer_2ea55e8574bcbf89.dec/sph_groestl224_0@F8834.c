void *__fastcall sph_groestl224_0(_DWORD *a1, char *a2, size_t a3)
{
  int v3; // r8
  _BYTE *v4; // r6
  int *v5; // r7
  int *v6; // r12
  int v7; // r0
  int v8; // r1
  _DWORD *v9; // lr
  int v10; // r2
  int v11; // r3
  size_t i; // r4
  char *v13; // r0
  int *v14; // r12
  _BYTE *v15; // r0
  int *v16; // r1
  _DWORD *v17; // r3
  int v18; // r6
  int v19; // t1
  int v20; // t1
  int v21; // r4
  int v22; // r2
  int v23; // lr
  int v24; // r11
  int v25; // r3
  unsigned int v26; // r6
  unsigned int v27; // r4
  int v28; // r0
  unsigned int v29; // r5
  int v30; // r9
  unsigned int v31; // r3
  unsigned int v32; // r2
  int v33; // r10
  _QWORD *v34; // r4
  _QWORD *v35; // lr
  _DWORD *v36; // r12
  int v37; // r0
  _QWORD *v38; // r9
  int v39; // r12
  int v40; // r11
  int *v41; // r10
  int v42; // r12
  int v43; // r10
  int v44; // r8
  _QWORD *v45; // r4
  int v46; // r5
  _DWORD *v47; // r12
  int v48; // r5
  int v49; // r1
  int v50; // r1
  int v51; // r3
  int v52; // r0
  __int64 v53; // r0
  int v54; // r9
  int v55; // r2
  int v56; // r11
  int v57; // r3
  _QWORD *v58; // r8
  _QWORD *v59; // r4
  int v60; // r5
  _QWORD *v61; // r6
  int v62; // r3
  int v63; // r4
  unsigned int v64; // r7
  unsigned int v65; // r9
  unsigned int v66; // r12
  _QWORD *v67; // lr
  __int64 v68; // r10
  int v69; // r8
  _QWORD *v70; // r9
  int v71; // r6
  __int64 v72; // r2
  int v73; // r12
  int v74; // r4
  int *v75; // r5
  int v76; // lr
  __int64 v77; // r2
  int v78; // r7
  int v79; // r5
  int v80; // r4
  int v81; // r5
  int v82; // r7
  int v83; // r12
  int v84; // r6
  int v85; // r12
  int v86; // r9
  int v87; // r9
  int v88; // r7
  int v89; // r8
  int v90; // r6
  int v91; // r9
  int v92; // r7
  int v93; // r2
  int v94; // r7
  int v95; // r0
  int v96; // r9
  int v97; // r6
  int v98; // r10
  int v99; // r2
  int v100; // r3
  int v101; // r12
  unsigned int v102; // r8
  _QWORD *v103; // lr
  _QWORD *v104; // r7
  _QWORD *v105; // r10
  _QWORD *v106; // r4
  int v107; // r2
  unsigned int v108; // r8
  int v109; // r10
  int v110; // r12
  _QWORD *v111; // r11
  int v112; // r4
  _QWORD *v113; // r5
  int v114; // lr
  int v115; // r3
  int v116; // r1
  int v117; // r4
  int v118; // r5
  int v119; // r1
  int v120; // r2
  _QWORD *v121; // r5
  int v122; // r12
  int v123; // r1
  _QWORD *v124; // r11
  int v125; // r2
  int v126; // r1
  int v127; // lr
  int v128; // r2
  int v129; // r7
  unsigned int v130; // r3
  int v131; // r1
  int v132; // r2
  __int64 v133; // r0
  int v134; // r3
  unsigned int v135; // r2
  __int64 v136; // r0
  int v137; // r3
  unsigned int v138; // r7
  int *v139; // r3
  int v140; // r2
  __int64 v141; // r8
  _QWORD *v142; // r12
  int v143; // r4
  __int64 v144; // r10
  int v145; // r3
  int v146; // r2
  int v147; // r6
  int v148; // r7
  int v149; // r12
  int v150; // lr
  int v151; // r2
  int v152; // r4
  int v153; // r2
  _QWORD *v154; // r7
  _QWORD *v155; // r12
  int v156; // r2
  int v157; // r12
  int v158; // r7
  int v159; // r6
  int v160; // r5
  int v161; // r3
  int v162; // r7
  int v163; // r11
  int *v164; // r12
  __int64 *v165; // r0
  int v166; // r5
  int v167; // r4
  int v168; // r3
  int v169; // r2
  int v170; // lr
  int v171; // t1
  int v172; // r4
  int v173; // r2
  _DWORD *v174; // r12
  __int64 *v175; // r5
  void *result; // r0
  int v177; // r1
  int v178; // r2
  int v179; // r3
  size_t v181; // r4
  __int64 v182; // [sp+0h] [bp-1BCh]
  __int64 v183; // [sp+0h] [bp-1BCh]
  __int64 v184; // [sp+10h] [bp-1ACh]
  int v185; // [sp+10h] [bp-1ACh]
  int v186; // [sp+10h] [bp-1ACh]
  unsigned int v187; // [sp+10h] [bp-1ACh]
  _QWORD *v188; // [sp+10h] [bp-1ACh]
  int v189; // [sp+14h] [bp-1A8h]
  int v190; // [sp+14h] [bp-1A8h]
  unsigned int v191; // [sp+14h] [bp-1A8h]
  _QWORD *v192; // [sp+14h] [bp-1A8h]
  int v193; // [sp+18h] [bp-1A4h]
  unsigned int v194; // [sp+18h] [bp-1A4h]
  unsigned int v195; // [sp+18h] [bp-1A4h]
  int v196; // [sp+18h] [bp-1A4h]
  unsigned int v197; // [sp+18h] [bp-1A4h]
  _QWORD *v198; // [sp+18h] [bp-1A4h]
  unsigned int v199; // [sp+1Ch] [bp-1A0h]
  unsigned int v200; // [sp+1Ch] [bp-1A0h]
  int v201; // [sp+1Ch] [bp-1A0h]
  int v202; // [sp+1Ch] [bp-1A0h]
  unsigned int v203; // [sp+1Ch] [bp-1A0h]
  _QWORD *v204; // [sp+1Ch] [bp-1A0h]
  int v205; // [sp+20h] [bp-19Ch]
  unsigned int v206; // [sp+20h] [bp-19Ch]
  int v207; // [sp+20h] [bp-19Ch]
  int v208; // [sp+20h] [bp-19Ch]
  unsigned int v209; // [sp+20h] [bp-19Ch]
  int v210; // [sp+20h] [bp-19Ch]
  unsigned int v211; // [sp+20h] [bp-19Ch]
  int v212; // [sp+20h] [bp-19Ch]
  int v213; // [sp+20h] [bp-19Ch]
  unsigned int v214; // [sp+24h] [bp-198h]
  unsigned int v215; // [sp+24h] [bp-198h]
  int v216; // [sp+24h] [bp-198h]
  unsigned int v217; // [sp+24h] [bp-198h]
  unsigned int v218; // [sp+24h] [bp-198h]
  int v219; // [sp+28h] [bp-194h]
  unsigned int v220; // [sp+28h] [bp-194h]
  unsigned int v221; // [sp+28h] [bp-194h]
  int v222; // [sp+28h] [bp-194h]
  unsigned int v223; // [sp+28h] [bp-194h]
  int v224; // [sp+28h] [bp-194h]
  unsigned int v225; // [sp+2Ch] [bp-190h]
  unsigned int v226; // [sp+2Ch] [bp-190h]
  int v227; // [sp+2Ch] [bp-190h]
  unsigned int v228; // [sp+2Ch] [bp-190h]
  unsigned int v229; // [sp+2Ch] [bp-190h]
  int v230; // [sp+2Ch] [bp-190h]
  int v231; // [sp+30h] [bp-18Ch]
  unsigned int v232; // [sp+30h] [bp-18Ch]
  _QWORD *v233; // [sp+30h] [bp-18Ch]
  unsigned int v234; // [sp+30h] [bp-18Ch]
  int v235; // [sp+30h] [bp-18Ch]
  unsigned int v236; // [sp+30h] [bp-18Ch]
  unsigned int v237; // [sp+30h] [bp-18Ch]
  int v238; // [sp+34h] [bp-188h]
  _QWORD *v239; // [sp+34h] [bp-188h]
  unsigned int v240; // [sp+34h] [bp-188h]
  unsigned int v241; // [sp+34h] [bp-188h]
  unsigned int v242; // [sp+34h] [bp-188h]
  int v243; // [sp+34h] [bp-188h]
  int v244; // [sp+38h] [bp-184h]
  unsigned int v245; // [sp+38h] [bp-184h]
  _QWORD *v246; // [sp+38h] [bp-184h]
  unsigned int v247; // [sp+38h] [bp-184h]
  int v248; // [sp+38h] [bp-184h]
  unsigned int v249; // [sp+38h] [bp-184h]
  int v250; // [sp+38h] [bp-184h]
  int v251; // [sp+3Ch] [bp-180h]
  unsigned int v252; // [sp+3Ch] [bp-180h]
  unsigned int v253; // [sp+3Ch] [bp-180h]
  int v254; // [sp+3Ch] [bp-180h]
  int v255; // [sp+3Ch] [bp-180h]
  unsigned int v256; // [sp+3Ch] [bp-180h]
  _QWORD *v257; // [sp+3Ch] [bp-180h]
  int v258; // [sp+40h] [bp-17Ch]
  int v259; // [sp+40h] [bp-17Ch]
  _QWORD *v260; // [sp+40h] [bp-17Ch]
  unsigned int v261; // [sp+40h] [bp-17Ch]
  __int16 v262; // [sp+40h] [bp-17Ch]
  _QWORD *v263; // [sp+40h] [bp-17Ch]
  unsigned int v264; // [sp+40h] [bp-17Ch]
  _QWORD *v265; // [sp+40h] [bp-17Ch]
  size_t n; // [sp+44h] [bp-178h]
  int v267; // [sp+48h] [bp-174h]
  int v268; // [sp+48h] [bp-174h]
  int v269; // [sp+48h] [bp-174h]
  unsigned int v270; // [sp+48h] [bp-174h]
  int v271; // [sp+48h] [bp-174h]
  unsigned int v272; // [sp+48h] [bp-174h]
  int v273; // [sp+48h] [bp-174h]
  int v274; // [sp+4Ch] [bp-170h]
  int v275; // [sp+4Ch] [bp-170h]
  int v276; // [sp+4Ch] [bp-170h]
  unsigned int v277; // [sp+4Ch] [bp-170h]
  int v278; // [sp+50h] [bp-16Ch]
  unsigned int v279; // [sp+50h] [bp-16Ch]
  int v280; // [sp+50h] [bp-16Ch]
  unsigned int v281; // [sp+50h] [bp-16Ch]
  __int64 v282; // [sp+50h] [bp-16Ch]
  int v283; // [sp+54h] [bp-168h]
  int v284; // [sp+54h] [bp-168h]
  int v285; // [sp+54h] [bp-168h]
  _QWORD *v286; // [sp+54h] [bp-168h]
  unsigned int v287; // [sp+54h] [bp-168h]
  unsigned int v288; // [sp+54h] [bp-168h]
  _QWORD *v289; // [sp+54h] [bp-168h]
  int v290; // [sp+58h] [bp-164h]
  unsigned int v291; // [sp+58h] [bp-164h]
  _QWORD *v292; // [sp+58h] [bp-164h]
  _QWORD *v293; // [sp+58h] [bp-164h]
  int v294; // [sp+58h] [bp-164h]
  unsigned int v295; // [sp+58h] [bp-164h]
  _DWORD *v296; // [sp+5Ch] [bp-160h]
  int v297; // [sp+5Ch] [bp-160h]
  int v298; // [sp+5Ch] [bp-160h]
  _QWORD *v299; // [sp+5Ch] [bp-160h]
  _QWORD *v300; // [sp+5Ch] [bp-160h]
  _DWORD *v301; // [sp+5Ch] [bp-160h]
  _QWORD *v302; // [sp+5Ch] [bp-160h]
  int v303; // [sp+5Ch] [bp-160h]
  unsigned int v304; // [sp+5Ch] [bp-160h]
  _QWORD *v305; // [sp+60h] [bp-15Ch]
  _QWORD *v306; // [sp+60h] [bp-15Ch]
  int v307; // [sp+60h] [bp-15Ch]
  unsigned int v308; // [sp+60h] [bp-15Ch]
  _QWORD *v309; // [sp+64h] [bp-158h]
  int v310; // [sp+64h] [bp-158h]
  int v311; // [sp+64h] [bp-158h]
  _DWORD *v312; // [sp+64h] [bp-158h]
  _QWORD *v313; // [sp+64h] [bp-158h]
  int v314; // [sp+64h] [bp-158h]
  unsigned int v315; // [sp+64h] [bp-158h]
  unsigned int v316; // [sp+68h] [bp-154h]
  _QWORD *v317; // [sp+68h] [bp-154h]
  _QWORD *v318; // [sp+68h] [bp-154h]
  int v319; // [sp+68h] [bp-154h]
  int v320; // [sp+68h] [bp-154h]
  __int64 v321; // [sp+6Ch] [bp-150h]
  unsigned int v322; // [sp+70h] [bp-14Ch]
  int v323; // [sp+74h] [bp-148h]
  _QWORD *v324; // [sp+74h] [bp-148h]
  _QWORD *v325; // [sp+74h] [bp-148h]
  __int64 v326; // [sp+74h] [bp-148h]
  _QWORD *v327; // [sp+78h] [bp-144h]
  int v328; // [sp+78h] [bp-144h]
  _QWORD *v329; // [sp+78h] [bp-144h]
  _DWORD *v330; // [sp+78h] [bp-144h]
  _QWORD *v331; // [sp+7Ch] [bp-140h]
  _QWORD *v332; // [sp+7Ch] [bp-140h]
  _QWORD *v333; // [sp+7Ch] [bp-140h]
  _QWORD *v334; // [sp+7Ch] [bp-140h]
  int v335; // [sp+7Ch] [bp-140h]
  _QWORD *v336; // [sp+7Ch] [bp-140h]
  _QWORD *v337; // [sp+7Ch] [bp-140h]
  _DWORD *v338; // [sp+7Ch] [bp-140h]
  _DWORD *v339; // [sp+80h] [bp-13Ch]
  _QWORD *v340; // [sp+80h] [bp-13Ch]
  int v341; // [sp+80h] [bp-13Ch]
  int v342; // [sp+80h] [bp-13Ch]
  _QWORD *v343; // [sp+80h] [bp-13Ch]
  _QWORD *v344; // [sp+80h] [bp-13Ch]
  int v345; // [sp+80h] [bp-13Ch]
  char *src; // [sp+84h] [bp-138h]
  _QWORD *v347; // [sp+88h] [bp-134h]
  _QWORD *v348; // [sp+88h] [bp-134h]
  int v349; // [sp+88h] [bp-134h]
  _QWORD *v350; // [sp+88h] [bp-134h]
  int v351; // [sp+88h] [bp-134h]
  _QWORD *v352; // [sp+88h] [bp-134h]
  _QWORD *v353; // [sp+8Ch] [bp-130h]
  _DWORD *v354; // [sp+8Ch] [bp-130h]
  _QWORD *v355; // [sp+8Ch] [bp-130h]
  _QWORD *v356; // [sp+8Ch] [bp-130h]
  _QWORD *v357; // [sp+8Ch] [bp-130h]
  _QWORD *v358; // [sp+90h] [bp-12Ch]
  int v359; // [sp+90h] [bp-12Ch]
  _QWORD *v360; // [sp+90h] [bp-12Ch]
  _QWORD *v361; // [sp+90h] [bp-12Ch]
  _QWORD *v362; // [sp+90h] [bp-12Ch]
  _QWORD *v363; // [sp+90h] [bp-12Ch]
  _QWORD *v364; // [sp+94h] [bp-128h]
  _QWORD *v365; // [sp+94h] [bp-128h]
  _QWORD *v366; // [sp+94h] [bp-128h]
  int v367; // [sp+94h] [bp-128h]
  _QWORD *v368; // [sp+98h] [bp-124h]
  int v369; // [sp+98h] [bp-124h]
  _QWORD *v370; // [sp+98h] [bp-124h]
  _QWORD *v371; // [sp+98h] [bp-124h]
  _QWORD *v372; // [sp+98h] [bp-124h]
  _QWORD *v373; // [sp+9Ch] [bp-120h]
  int v374; // [sp+9Ch] [bp-120h]
  int v375; // [sp+9Ch] [bp-120h]
  _QWORD *v376; // [sp+9Ch] [bp-120h]
  _QWORD *v377; // [sp+9Ch] [bp-120h]
  _QWORD *v378; // [sp+9Ch] [bp-120h]
  _QWORD *v379; // [sp+A0h] [bp-11Ch]
  _DWORD *v380; // [sp+A0h] [bp-11Ch]
  _QWORD *v381; // [sp+A0h] [bp-11Ch]
  _QWORD *v382; // [sp+A0h] [bp-11Ch]
  int v383; // [sp+A4h] [bp-118h]
  _QWORD *v384; // [sp+A4h] [bp-118h]
  _QWORD *v385; // [sp+A4h] [bp-118h]
  _QWORD *v386; // [sp+A4h] [bp-118h]
  _QWORD *v387; // [sp+A8h] [bp-114h]
  int v388; // [sp+A8h] [bp-114h]
  _QWORD *v389; // [sp+A8h] [bp-114h]
  _QWORD *v390; // [sp+A8h] [bp-114h]
  _QWORD *v391; // [sp+A8h] [bp-114h]
  _QWORD *v392; // [sp+ACh] [bp-110h]
  _DWORD *v393; // [sp+ACh] [bp-110h]
  int v394; // [sp+ACh] [bp-110h]
  _QWORD *v395; // [sp+ACh] [bp-110h]
  _QWORD *v396; // [sp+ACh] [bp-110h]
  _QWORD *v397; // [sp+B0h] [bp-10Ch]
  unsigned int v398; // [sp+B0h] [bp-10Ch]
  _QWORD *v399; // [sp+B0h] [bp-10Ch]
  _QWORD *v400; // [sp+B0h] [bp-10Ch]
  _QWORD *v401; // [sp+B0h] [bp-10Ch]
  _QWORD *v402; // [sp+B4h] [bp-108h]
  int v403; // [sp+B4h] [bp-108h]
  _QWORD *v404; // [sp+B4h] [bp-108h]
  _QWORD *v405; // [sp+B4h] [bp-108h]
  _QWORD *v406; // [sp+B4h] [bp-108h]
  int v407; // [sp+B8h] [bp-104h]
  _QWORD *v408; // [sp+B8h] [bp-104h]
  unsigned int v409; // [sp+B8h] [bp-104h]
  int v410; // [sp+B8h] [bp-104h]
  _QWORD *v411; // [sp+BCh] [bp-100h]
  _DWORD *v412; // [sp+BCh] [bp-100h]
  int v413; // [sp+BCh] [bp-100h]
  int v414; // [sp+BCh] [bp-100h]
  _QWORD *v415; // [sp+C0h] [bp-FCh]
  _QWORD *v416; // [sp+C0h] [bp-FCh]
  int v417; // [sp+C0h] [bp-FCh]
  int v418; // [sp+C0h] [bp-FCh]
  int v419; // [sp+C4h] [bp-F8h]
  _QWORD *v420; // [sp+C4h] [bp-F8h]
  int v421; // [sp+C4h] [bp-F8h]
  int v422; // [sp+C4h] [bp-F8h]
  int v423; // [sp+C4h] [bp-F8h]
  int v424; // [sp+C4h] [bp-F8h]
  int v425; // [sp+C8h] [bp-F4h]
  _QWORD *v426; // [sp+C8h] [bp-F4h]
  int v427; // [sp+C8h] [bp-F4h]
  unsigned int v428; // [sp+C8h] [bp-F4h]
  _QWORD *v429; // [sp+CCh] [bp-F0h]
  int v430; // [sp+CCh] [bp-F0h]
  int v431; // [sp+CCh] [bp-F0h]
  int v432; // [sp+CCh] [bp-F0h]
  int v433; // [sp+D0h] [bp-ECh]
  int v434; // [sp+D0h] [bp-ECh]
  int v435; // [sp+D0h] [bp-ECh]
  int v436; // [sp+D0h] [bp-ECh]
  unsigned int v437; // [sp+D0h] [bp-ECh]
  unsigned int v438; // [sp+D0h] [bp-ECh]
  unsigned int v439; // [sp+D4h] [bp-E8h]
  int v440; // [sp+D4h] [bp-E8h]
  unsigned int v441; // [sp+D8h] [bp-E4h]
  unsigned int v442; // [sp+D8h] [bp-E4h]
  int v443; // [sp+DCh] [bp-E0h]
  int v444; // [sp+E0h] [bp-DCh]
  int v445; // [sp+E4h] [bp-D8h]
  int v447; // [sp+F0h] [bp-CCh] BYREF
  _DWORD *v448; // [sp+F4h] [bp-C8h]
  _BYTE v449[56]; // [sp+F8h] [bp-C4h] BYREF
  _BYTE v450[8]; // [sp+130h] [bp-8Ch] BYREF
  __int64 v451; // [sp+138h] [bp-84h] BYREF
  int v452; // [sp+140h] [bp-7Ch] BYREF
  int v453; // [sp+144h] [bp-78h]
  int v454; // [sp+148h] [bp-74h]
  int v455; // [sp+14Ch] [bp-70h]
  int v456; // [sp+150h] [bp-6Ch]
  int v457; // [sp+154h] [bp-68h]
  int v458; // [sp+158h] [bp-64h]
  int v459; // [sp+15Ch] [bp-60h]
  int v460; // [sp+160h] [bp-5Ch]
  int v461; // [sp+164h] [bp-58h]
  int v462; // [sp+168h] [bp-54h]
  int v463; // [sp+16Ch] [bp-50h]
  int v464; // [sp+170h] [bp-4Ch] BYREF
  int v465; // [sp+174h] [bp-48h]
  int v466; // [sp+178h] [bp-44h]
  int v467; // [sp+17Ch] [bp-40h]
  __int64 v468; // [sp+180h] [bp-3Ch] BYREF
  int v469; // [sp+188h] [bp-34h]
  int v470; // [sp+18Ch] [bp-30h]
  int v471; // [sp+190h] [bp-2Ch]
  int v472; // [sp+194h] [bp-28h]
  int v473; // [sp+198h] [bp-24h]
  int v474; // [sp+19Ch] [bp-20h]
  int v475; // [sp+1A0h] [bp-1Ch]
  int v476; // [sp+1A4h] [bp-18h]
  int v477; // [sp+1A8h] [bp-14h]
  int v478; // [sp+1ACh] [bp-10h]
  int v479; // [sp+1B0h] [bp-Ch]
  int v480; // [sp+1B4h] [bp-8h]

  v3 = a1[16];
  n = a3;
  src = a2;
  if ( 64 - v3 > a3 )
  {
    v181 = v3 + a3;
    result = memcpy((char *)a1 + v3, a2, a3);
    a1[16] = v181;
  }
  else
  {
    v4 = v449;
    v5 = a1 + 34;
    v6 = a1 + 18;
    v448 = a1 + 18;
    do
    {
      v7 = *v6;
      v6 += 4;
      v8 = *(v6 - 3);
      v9 = v4;
      v10 = *(v6 - 2);
      v4 += 16;
      v11 = *(v6 - 1);
      *v9 = v7;
      v9[1] = v8;
      v9[2] = v10;
      v9[3] = v11;
    }
    while ( v6 != v5 );
    if ( n )
    {
      for ( i = 64 - v3; ; i = 64 - v3 )
      {
        if ( n < i )
          i = n;
        v13 = (char *)a1 + v3;
        v3 += i;
        memcpy(v13, src, i);
        n -= i;
        src += i;
        if ( v3 == 64 )
        {
          v447 = (int)&v447;
          v14 = &v447;
          v15 = v450;
          v16 = &v464;
          v17 = a1 - 2;
          do
          {
            v19 = v17[2];
            v17 += 2;
            v18 = v19;
            v20 = v14[2];
            v14 += 2;
            v21 = v17[1];
            v22 = v14[1];
            v16[2] = v18;
            v16 += 2;
            *((_DWORD *)v15 + 2) = v20 ^ v18;
            v15 += 8;
            v16[1] = v21;
            *((_DWORD *)v15 + 1) = v22 ^ v21;
          }
          while ( a1 + 14 != v17 );
          v182 = 0;
          v321 = v451;
          v23 = v462;
          v24 = v464;
          v267 = v465;
          v231 = v452;
          v278 = v453;
          v244 = v454;
          v258 = v455;
          v238 = v456;
          v283 = v457;
          v193 = v458;
          v205 = v459;
          v219 = v460;
          v251 = v461;
          v25 = v463;
          do
          {
            v184 = v321 ^ v182;
            v225 = v278 ^ ((unsigned __int64)(v182 + 16) >> 32);
            v199 = v258 ^ ((unsigned __int64)(v182 + 32) >> 32);
            v26 = v193 ^ (v182 + 64);
            v214 = v205 ^ ((unsigned __int64)(v182 + 64) >> 32);
            v27 = v219 ^ (v182 + 80);
            v220 = (v182 + 96) ^ v23;
            v28 = (v267 ^ ((unsigned __int64)(v182 + 112) >> 32)) >> 24;
            v259 = v267 ^ ((unsigned __int64)(v182 + 112) >> 32);
            v194 = v231 ^ (v182 + 16);
            v29 = (v182 + 32) ^ v244;
            v245 = v27;
            v30 = v251;
            v31 = v25 ^ ((unsigned __int64)(v182 + 96) >> 32);
            v206 = v283 ^ ((unsigned __int64)(v182 + 48) >> 32);
            v252 = (v182 + 112) ^ v24;
            v32 = ((unsigned __int64)(v182 + 80) >> 32) ^ v30;
            v232 = (v182 + 48) ^ v238;
            v327 = &qword_15BBD8[HIBYTE(v26)];
            v296 = &dword_15A3E0[2 * ((unsigned int)(HIDWORD(v321) ^ HIDWORD(v182)) >> 24)];
            v339 = &dword_15A3E0[2 * HIBYTE(v225)];
            v353 = &qword_15BBD8[HIBYTE(v27)];
            HIDWORD(v321) = HIBYTE(v31);
            v373 = &qword_15BBD8[HIBYTE(v220)];
            v397 = &qword_15BBD8[HIBYTE(v252)];
            v33 = dword_15A3E0[2 * v28 + 1];
            v402 = &qword_15BBD8[((unsigned int)v321 ^ (unsigned int)v182) >> 24];
            v316 = HIBYTE(v32);
            v34 = &qword_15ABE8[BYTE1(v194)];
            v35 = &qword_15B3E8[BYTE2(v29)];
            v36 = &dword_159BE0[2 * (unsigned __int8)(v321 ^ v182)];
            v429 = &qword_15BBD8[HIBYTE(v29)];
            v443 = (unsigned __int8)v29;
            v309 = &qword_15ABE8[BYTE1(v29)];
            v37 = *v36 ^ (v182 + 1) ^ dword_15A3E0[2 * v28] ^ *((_DWORD *)v34 - 2);
            v38 = &qword_15BBD8[HIBYTE(v232)];
            LODWORD(v321) = &qword_15B3E8[BYTE2(v232)];
            v39 = v36[1] ^ ((unsigned __int64)(v182 + 1) >> 32) ^ v33;
            v331 = &qword_15C3E8[(unsigned __int8)v32];
            v40 = BYTE1(v31);
            v323 = BYTE2(v32);
            v41 = &dword_15D3E0[2 * BYTE2(v31)];
            v358 = &qword_15C3E8[(unsigned __int8)v31];
            v419 = *v41;
            v42 = v39 ^ *((_DWORD *)v34 - 1);
            v425 = v41[1];
            v43 = BYTE6(v184);
            v44 = (unsigned __int8)((v182 + 48) ^ v238);
            v347 = &qword_15ABE8[BYTE1(v232)];
            v45 = &qword_15C3E8[(unsigned __int8)v214];
            v46 = v296[1] ^ ((unsigned __int64)(v182 + 17) >> 32) ^ dword_159BE0[2 * (unsigned __int8)v194 + 1];
            v433 = *v296 ^ (v182 + 17) ^ dword_159BE0[2 * (unsigned __int8)v194];
            v379 = &qword_15C3E8[(unsigned __int8)(v267 ^ ((unsigned __int64)(v182 + 112) >> 32))];
            v444 = BYTE5(v184);
            v233 = &qword_15C3E8[BYTE4(v184)];
            v239 = &qword_15ABE8[BYTE1(v26)];
            v368 = &qword_15B3E8[BYTE2(v245)];
            v445 = BYTE2(v225);
            v297 = (unsigned __int8)v245;
            v387 = &qword_15ABE8[BYTE1(v245)];
            v284 = BYTE1(v225);
            v392 = &qword_15B3E8[BYTE2(v220)];
            v415 = &qword_15C3E8[(unsigned __int8)(v278 ^ ((unsigned __int64)(v182 + 16) >> 32))];
            v226 = v42
                 ^ *((_DWORD *)v35 - 1)
                 ^ *((_DWORD *)v38 + 3)
                 ^ *((_DWORD *)v45 - 1)
                 ^ dword_15CBE0[2 * BYTE1(v32) + 1]
                 ^ v425;
            v290 = BYTE2(v199);
            v47 = &dword_15D3E0[2 * BYTE6(v184)];
            HIDWORD(v184) = v37
                          ^ *((_DWORD *)v35 - 2)
                          ^ *((_DWORD *)v38 + 2)
                          ^ *((_DWORD *)v45 - 2)
                          ^ dword_15CBE0[2 * BYTE1(v32)]
                          ^ v419;
            v48 = v46 ^ *((_DWORD *)v309 - 1) ^ *(_DWORD *)(v321 - 4);
            v49 = v433 ^ *((_DWORD *)v309 - 2) ^ *(_DWORD *)(v321 - 8) ^ *((_DWORD *)v327 + 2);
            v310 = (unsigned __int8)v220;
            v411 = &qword_15ABE8[BYTE1(v220)];
            v50 = v49 ^ *((_DWORD *)v331 - 2);
            v51 = dword_15CBE0[2 * BYTE1(v31) + 1]
                ^ v48
                ^ *((_DWORD *)v327 + 3)
                ^ *((_DWORD *)v331 - 1)
                ^ dword_15D3E0[2 * BYTE2(v259) + 1];
            v328 = dword_15A3E0[2 * HIBYTE(v199)];
            v434 = dword_15A3E0[2 * HIBYTE(v199) + 1];
            v332 = &qword_15B3E8[BYTE2(v252)];
            v268 = BYTE1(v199);
            v420 = &qword_15C3E8[(unsigned __int8)v199];
            v52 = v184;
            LODWORD(v184) = v51;
            v364 = &qword_15B3E8[BYTE2(v52)];
            v426 = &qword_15ABE8[BYTE1(v52)];
            v246 = &qword_15ABE8[BYTE1(v252)];
            LODWORD(v321) = (unsigned __int8)v252;
            v253 = v50 ^ dword_15CBE0[2 * v40] ^ dword_15D3E0[2 * BYTE2(v259)];
            v53 = qword_15B3E8[BYTE2(v26) - 1];
            v200 = *v339
                 ^ dword_15D3E0[2 * v43]
                 ^ dword_159BE0[2 * v443]
                 ^ (v182 + 33)
                 ^ *((_DWORD *)v347 - 2)
                 ^ v53
                 ^ *((_DWORD *)v353 + 2)
                 ^ *((_DWORD *)v358 - 2)
                 ^ dword_15CBE0[2 * BYTE1(v259)];
            v221 = v339[1]
                 ^ v47[1]
                 ^ dword_159BE0[2 * v443 + 1]
                 ^ ((unsigned __int64)(v182 + 33) >> 32)
                 ^ *((_DWORD *)v347 - 1)
                 ^ HIDWORD(v53)
                 ^ *((_DWORD *)v353 + 3)
                 ^ *((_DWORD *)v358 - 1)
                 ^ dword_15CBE0[2 * BYTE1(v259) + 1];
            v54 = *((_DWORD *)v368 - 1);
            v55 = dword_159BE0[2 * v44]
                ^ dword_15CBE0[2 * v444]
                ^ (v182 + 49)
                ^ v328
                ^ *((_DWORD *)v239 - 2)
                ^ *((_DWORD *)v368 - 2);
            v369 = dword_15CBE0[2 * v284 + 1];
            v56 = *((_DWORD *)v233 - 2);
            HIDWORD(v53) = v233;
            v234 = v55 ^ *((_DWORD *)v373 + 2) ^ *((_DWORD *)v379 - 2) ^ dword_15D3E0[2 * v445];
            v240 = *((_DWORD *)v373 + 3)
                 ^ dword_159BE0[2 * v44 + 1]
                 ^ dword_15CBE0[2 * v444 + 1]
                 ^ ((unsigned __int64)(v182 + 49) >> 32)
                 ^ v434
                 ^ *((_DWORD *)v239 - 1)
                 ^ v54
                 ^ *((_DWORD *)v379 - 1)
                 ^ dword_15D3E0[2 * v445 + 1];
            v285 = dword_15CBE0[2 * v284];
            v374 = dword_15D3E0[2 * v290 + 1];
            v291 = dword_15D3E0[2 * v290];
            v57 = dword_15A3E0[2 * HIBYTE(v206) + 1]
                ^ *(_DWORD *)(HIDWORD(v53) - 4)
                ^ dword_159BE0[2 * (unsigned __int8)v26 + 1]
                ^ ((unsigned __int64)(v182 + 65) >> 32);
            v58 = v387;
            v407 = dword_15CBE0[2 * v268 + 1];
            HIDWORD(v53) = *((_DWORD *)v387 - 1);
            v388 = dword_15CBE0[2 * v268];
            v435 = dword_15D3E0[2 * BYTE2(v206)];
            v59 = &qword_15B3E8[BYTE2(v194)];
            v260 = &qword_15BBD8[HIBYTE(v194)];
            v274 = v57 ^ HIDWORD(v53) ^ *((_DWORD *)v392 - 1) ^ *((_DWORD *)v397 + 3);
            v269 = dword_15A3E0[2 * HIBYTE(v206)]
                 ^ v56
                 ^ dword_159BE0[2 * (unsigned __int8)v26]
                 ^ (v182 + 65)
                 ^ *((_DWORD *)v58 - 2)
                 ^ *((_DWORD *)v392 - 2)
                 ^ *((_DWORD *)v397 + 2);
            v60 = (v182 + 81) ^ *((_DWORD *)v402 + 2) ^ dword_159BE0[2 * v297] ^ dword_15A3E0[2 * HIBYTE(v214)];
            v298 = dword_159BE0[2 * v297 + 1]
                 ^ *((_DWORD *)v402 + 3)
                 ^ ((unsigned __int64)(v182 + 81) >> 32)
                 ^ dword_15A3E0[2 * HIBYTE(v214) + 1];
            LODWORD(v53) = *((_DWORD *)v364 - 2) ^ dword_159BE0[2 * v310];
            v61 = &qword_15C3E8[(unsigned __int8)v206];
            v62 = dword_159BE0[2 * v310 + 1]
                ^ *((_DWORD *)v364 - 1)
                ^ ((unsigned __int64)(v182 + 97) >> 32)
                ^ dword_15A3E0[2 * v316 + 1];
            v311 = *((_DWORD *)v59 - 1);
            HIDWORD(v53) = dword_159BE0[2 * (_DWORD)v321]
                         ^ *((_DWORD *)v426 - 2)
                         ^ (v182 + 113)
                         ^ dword_15A3E0[2 * HIDWORD(v321)]
                         ^ *((_DWORD *)v59 - 2);
            v63 = dword_15CBE0[2 * BYTE1(v214)];
            v195 = v274 ^ v369 ^ v374;
            LODWORD(v53) = v53
                         ^ (v182 + 97)
                         ^ dword_15A3E0[2 * v316]
                         ^ *((_DWORD *)v246 - 2)
                         ^ *((_DWORD *)v260 + 2)
                         ^ *((_DWORD *)v420 - 2)
                         ^ dword_15CBE0[2 * BYTE1(v206)]
                         ^ dword_15D3E0[2 * BYTE2(v214)];
            v64 = dword_15D3E0[2 * BYTE2(v214) + 1]
                ^ v62
                ^ *((_DWORD *)v246 - 1)
                ^ *((_DWORD *)v260 + 3)
                ^ *((_DWORD *)v420 - 1)
                ^ dword_15CBE0[2 * BYTE1(v206) + 1];
            v215 = dword_159BE0[2 * (_DWORD)v321 + 1]
                 ^ *((_DWORD *)v426 - 1)
                 ^ ((unsigned __int64)(v182 + 113) >> 32)
                 ^ dword_15A3E0[2 * HIDWORD(v321) + 1]
                 ^ v311
                 ^ *((_DWORD *)v429 + 3)
                 ^ *((_DWORD *)v61 - 1)
                 ^ dword_15CBE0[2 * BYTE1(v214) + 1]
                 ^ dword_15D3E0[2 * v323 + 1];
            v65 = (v269 ^ v285 ^ v291) >> 24;
            v66 = v298
                ^ *((_DWORD *)v411 - 1)
                ^ *((_DWORD *)v332 - 1)
                ^ *((_DWORD *)v415 - 1)
                ^ v407
                ^ dword_15D3E0[2 * BYTE2(v206) + 1];
            v207 = v269 ^ v285 ^ v291;
            v322 = v60 ^ *((_DWORD *)v411 - 2) ^ *((_DWORD *)v332 - 2) ^ *((_DWORD *)v415 - 2) ^ v388 ^ v435;
            v398 = HIDWORD(v53) ^ *((_DWORD *)v429 + 2) ^ *((_DWORD *)v61 - 2) ^ v63 ^ dword_15D3E0[2 * v323];
            v261 = HIBYTE(v221);
            v247 = BYTE3(v184);
            v270 = HIBYTE(v240);
            v359 = v53;
            v292 = &qword_15BBD8[HIBYTE(v234)];
            v299 = &qword_15BBD8[v65];
            v312 = &dword_15A3E0[2 * BYTE3(v184)];
            v365 = &qword_15BBD8[HIBYTE(v398)];
            v324 = &qword_15BBD8[HIBYTE(v322)];
            v340 = &qword_15BBD8[BYTE3(v53)];
            v354 = &dword_15A3E0[2 * HIBYTE(v240)];
            v380 = &dword_15A3E0[2 * HIBYTE(v195)];
            v441 = HIBYTE(v64);
            v370 = &qword_15BBD8[HIBYTE(HIDWORD(v184))];
            v412 = &dword_15A3E0[2 * HIBYTE(v64)];
            v389 = &qword_15BBD8[HIBYTE(v253)];
            v416 = &qword_15BBD8[HIBYTE(v200)];
            v67 = &qword_15ABE8[BYTE1(v253)];
            v393 = &dword_15A3E0[2 * HIBYTE(v66)];
            HIDWORD(v53) = (unsigned __int8)v253;
            v439 = HIBYTE(v66);
            v305 = &qword_15C3E8[(unsigned __int8)v66];
            v408 = &qword_15B3E8[BYTE2(v253)];
            v182 += 2;
            v383 = *((_DWORD *)v67 - 1) ^ dword_15A3E0[2 * HIBYTE(v215) + 1];
            v403 = (unsigned __int8)v200;
            v286 = &qword_15B3E8[BYTE2(v200)];
            v68 = qword_15ABE8[BYTE1(v200) - 1];
            v69 = BYTE2(v64);
            v375 = *((_DWORD *)v67 - 2) ^ dword_15A3E0[2 * HIBYTE(v215)];
            LODWORD(v53) = dword_159BE0[2 * (unsigned __int8)v253 + 1]
                         ^ dword_15A3E0[2 * HIBYTE(v226) + 1]
                         ^ HIDWORD(v68);
            v329 = &qword_15C3E8[(unsigned __int8)v64];
            v70 = &qword_15C3E8[(unsigned __int8)v195];
            v71 = BYTE1(v66);
            v254 = BYTE2(v66);
            HIDWORD(v68) = BYTE2(v226);
            v72 = qword_15B3E8[BYTE2(v234) - 1];
            v73 = dword_15CBE0[2 * BYTE1(v64)];
            LODWORD(v53) = v53 ^ HIDWORD(v72);
            v74 = dword_15CBE0[2 * BYTE1(v64) + 1];
            HIDWORD(v53) = dword_159BE0[2 * HIDWORD(v53)] ^ dword_15A3E0[2 * HIBYTE(v226)] ^ v68 ^ v72;
            v430 = (unsigned __int8)v234;
            v75 = &dword_15D3E0[2 * BYTE2(v215)];
            v76 = *v75;
            v317 = &qword_15ABE8[BYTE1(v234)];
            v77 = v299[1];
            v78 = v75[1];
            LODWORD(v53) = v53 ^ HIDWORD(v77);
            v421 = BYTE1(v215);
            v300 = &qword_15B3E8[BYTE2(v207)];
            HIDWORD(v77) = *((_DWORD *)v305 - 1);
            v348 = &qword_15C3E8[(unsigned __int8)v215];
            v79 = *((_DWORD *)v305 - 2);
            v427 = BYTE1(v226);
            LODWORD(v68) = &qword_15C3E8[(unsigned __int8)v226];
            v436 = BYTE2(v184);
            v201 = (unsigned __int8)v207;
            v306 = &qword_15ABE8[BYTE1(v207)];
            v278 = v53 ^ HIDWORD(v77) ^ v74 ^ v78;
            v231 = HIDWORD(v53) ^ v77 ^ v79 ^ v73 ^ v76;
            v80 = dword_159BE0[2 * BYTE4(v184)] ^ v375;
            v333 = &qword_15B3E8[BYTE2(v322)];
            HIDWORD(v77) = (unsigned __int8)v184;
            LODWORD(v184) = BYTE1(v184);
            v376 = &qword_15C3E8[HIDWORD(v77)];
            v216 = (unsigned __int8)v322;
            LODWORD(v77) = *((_DWORD *)v292 + 3);
            HIDWORD(v77) = *((_DWORD *)v292 + 2);
            v293 = &qword_15ABE8[BYTE1(v322)];
            v81 = dword_159BE0[2 * BYTE4(v184) + 1] ^ v383 ^ *((_DWORD *)v286 - 1) ^ v77;
            LODWORD(v53) = *((_DWORD *)v70 - 2);
            LODWORD(v77) = *((_DWORD *)v70 - 1);
            LOWORD(v70) = v359;
            v360 = &qword_15B3E8[BYTE2(v359)];
            v208 = BYTE2(v221);
            v227 = (unsigned __int8)v70;
            v384 = &qword_15ABE8[BYTE1(v70)];
            v82 = dword_15A3E0[2 * HIBYTE(v221) + 1];
            HIDWORD(v321) = v81 ^ v77 ^ dword_15CBE0[2 * v71 + 1] ^ dword_15D3E0[2 * v69 + 1];
            v83 = v80 ^ *((_DWORD *)v286 - 2) ^ HIDWORD(v77) ^ v53 ^ dword_15CBE0[2 * v71] ^ dword_15D3E0[2 * v69];
            LOWORD(v81) = v398;
            LODWORD(v77) = dword_15D3E0[2 * HIDWORD(v68)] ^ dword_159BE0[2 * v403];
            HIDWORD(v53) = dword_159BE0[2 * v403 + 1] ^ dword_15D3E0[2 * HIDWORD(v68) + 1] ^ v312[1];
            BYTE4(v77) = v221;
            v313 = &qword_15B3E8[BYTE2(v398)];
            v84 = *((_DWORD *)v317 - 2);
            LODWORD(v321) = v83;
            v222 = BYTE1(v221);
            v85 = dword_15A3E0[2 * v261];
            v399 = &qword_15C3E8[BYTE4(v77)];
            HIDWORD(v77) = BYTE2(v240);
            v86 = *((_DWORD *)v300 - 1) ^ HIDWORD(v53) ^ *((_DWORD *)v317 - 1);
            v318 = &qword_15B3E8[BYTE6(v184)];
            v404 = &qword_15ABE8[BYTE5(v184)];
            LODWORD(v53) = *((_DWORD *)v324 + 2);
            v87 = v86 ^ *((_DWORD *)v324 + 3);
            v325 = &qword_15ABE8[BYTE1(v81)];
            v258 = v87 ^ *((_DWORD *)v329 - 1) ^ dword_15CBE0[2 * v421 + 1];
            v244 = *((_DWORD *)v300 - 2)
                 ^ v77
                 ^ dword_15A3E0[2 * v247]
                 ^ v84
                 ^ v53
                 ^ *((_DWORD *)v329 - 2)
                 ^ dword_15CBE0[2 * v421];
            v301 = &dword_15D3E0[2 * BYTE2(v240)];
            v330 = &dword_159BE0[2 * (unsigned __int8)v81];
            v189 = BYTE1(v240);
            v88 = v82
                ^ dword_159BE0[2 * v430 + 1]
                ^ dword_15CBE0[2 * v427 + 1]
                ^ dword_15D3E0[2 * v436 + 1]
                ^ *((_DWORD *)v306 - 1)
                ^ *((_DWORD *)v333 - 1);
            v89 = dword_15D3E0[2 * v436]
                ^ dword_159BE0[2 * v430]
                ^ dword_15CBE0[2 * v427]
                ^ v85
                ^ *((_DWORD *)v306 - 2)
                ^ *((_DWORD *)v333 - 2);
            v334 = &qword_15C3E8[(unsigned __int8)v240];
            v283 = v88 ^ *((_DWORD *)v340 + 3) ^ *((_DWORD *)v348 - 1);
            v238 = v89 ^ *((_DWORD *)v340 + 2) ^ *((_DWORD *)v348 - 2);
            HIDWORD(v53) = *(_DWORD *)(v68 - 4)
                         ^ dword_159BE0[2 * v201 + 1]
                         ^ dword_15CBE0[2 * (_DWORD)v184 + 1]
                         ^ v354[1];
            v90 = *((_DWORD *)v293 - 2)
                ^ *(_DWORD *)(v68 - 8)
                ^ dword_159BE0[2 * v201]
                ^ dword_15CBE0[2 * (_DWORD)v184]
                ^ dword_15A3E0[2 * v270];
            v341 = dword_15CBE0[2 * v222 + 1];
            v349 = dword_15D3E0[2 * HIDWORD(v77)];
            v91 = BYTE1(v195);
            v185 = BYTE2(v195);
            v193 = v90 ^ *((_DWORD *)v360 - 2) ^ *((_DWORD *)v365 + 2) ^ dword_15D3E0[2 * v208];
            v205 = *((_DWORD *)v293 - 1)
                 ^ HIDWORD(v53)
                 ^ *((_DWORD *)v360 - 1)
                 ^ *((_DWORD *)v365 + 3)
                 ^ dword_15D3E0[2 * v208 + 1];
            v92 = dword_15D3E0[2 * v254 + 1];
            v23 = dword_15D3E0[2 * v185]
                ^ *((_DWORD *)v318 - 2)
                ^ dword_159BE0[2 * v227]
                ^ *((_DWORD *)v389 + 2)
                ^ dword_15A3E0[2 * v439]
                ^ *((_DWORD *)v325 - 2)
                ^ *((_DWORD *)v399 - 2)
                ^ dword_15CBE0[2 * v189];
            v24 = *v330
                ^ *((_DWORD *)v404 - 2)
                ^ *((_DWORD *)v408 - 2)
                ^ dword_15A3E0[2 * v441]
                ^ *((_DWORD *)v416 + 2)
                ^ *((_DWORD *)v334 - 2)
                ^ dword_15CBE0[2 * v91]
                ^ dword_15D3E0[2 * v254];
            v25 = dword_15D3E0[2 * v185 + 1]
                ^ *((_DWORD *)v318 - 1)
                ^ dword_159BE0[2 * v227 + 1]
                ^ *((_DWORD *)v389 + 3)
                ^ v393[1]
                ^ *((_DWORD *)v325 - 1)
                ^ *((_DWORD *)v399 - 1)
                ^ dword_15CBE0[2 * v189 + 1];
            v219 = *((_DWORD *)v376 - 2)
                 ^ dword_159BE0[2 * v216]
                 ^ *((_DWORD *)v370 + 2)
                 ^ *v380
                 ^ *((_DWORD *)v384 - 2)
                 ^ *((_DWORD *)v313 - 2)
                 ^ dword_15CBE0[2 * v222]
                 ^ v349;
            v251 = dword_159BE0[2 * v216 + 1]
                 ^ *((_DWORD *)v370 + 3)
                 ^ *((_DWORD *)v376 - 1)
                 ^ v380[1]
                 ^ *((_DWORD *)v384 - 1)
                 ^ *((_DWORD *)v313 - 1)
                 ^ v341
                 ^ v301[1];
            v93 = v330[1]
                ^ *((_DWORD *)v404 - 1)
                ^ *((_DWORD *)v408 - 1)
                ^ v412[1]
                ^ *((_DWORD *)v416 + 3)
                ^ *((_DWORD *)v334 - 1)
                ^ dword_15CBE0[2 * v91 + 1]
                ^ v92;
            v267 = v93;
          }
          while ( v182 != 10 );
          v94 = dword_15D3E0[2 * v185 + 1]
              ^ *((_DWORD *)v318 - 1)
              ^ dword_159BE0[2 * v227 + 1]
              ^ *((_DWORD *)v389 + 3)
              ^ v393[1]
              ^ *((_DWORD *)v325 - 1)
              ^ *((_DWORD *)v399 - 1)
              ^ dword_15CBE0[2 * v189 + 1];
          v95 = v93;
          v314 = v466;
          v183 = -1;
          v319 = v467;
          v326 = v468;
          v271 = v469;
          v275 = v470;
          v294 = v471;
          v335 = v472;
          v451 = v321;
          v452 = v231;
          v453 = v278;
          v235 = v473;
          v454 = v244;
          v342 = v474;
          v455 = v258;
          v96 = v475;
          v456 = v238;
          v460 = v219;
          v97 = v476;
          v457 = v283;
          v98 = v477;
          v99 = v480;
          v458 = v193;
          v459 = v205;
          v100 = v479;
          v461 = v251;
          v462 = v23;
          v463 = v94;
          v464 = v24;
          v465 = v95;
          v186 = v478;
          do
          {
            v287 = HIDWORD(v183) ^ 0x70000000 ^ v99;
            v255 = ~v314;
            v190 = v319 ^ HIDWORD(v183);
            v196 = ~(_DWORD)v326;
            v248 = ~v100;
            v209 = ~v271;
            v101 = ~v294;
            v279 = v186 ^ HIDWORD(v183) ^ 0x60000000;
            v217 = v275 ^ HIDWORD(v183) ^ 0x20000000;
            v228 = ~v235;
            v272 = HIDWORD(v326) ^ HIDWORD(v183) ^ 0x10000000;
            v241 = ~v98;
            v236 = HIDWORD(v183) ^ 0x50000000 ^ v97;
            v409 = ((unsigned int)v319 ^ HIDWORD(v183)) >> 24;
            v102 = (unsigned int)~(_DWORD)v326 >> 24;
            v103 = &qword_15BBD8[(unsigned int)~v314 >> 24];
            LODWORD(v326) = &qword_15BBD8[(unsigned int)~v100 >> 24];
            v355 = &qword_15BBD8[HIBYTE(v209)];
            v350 = &qword_15BBD8[v102];
            v366 = &qword_15BBD8[(unsigned int)~v294 >> 24];
            v442 = (v335 ^ HIDWORD(v183) ^ 0x30000000u) >> 24;
            v437 = HIBYTE(v217);
            v315 = HIBYTE(v236);
            v104 = &qword_15C3E8[(unsigned __int8)(BYTE4(v326) ^ BYTE4(v183))];
            v377 = &qword_15BBD8[HIBYTE(v228)];
            v105 = &qword_15ABE8[BYTE1(v228)];
            v106 = &qword_15B3E8[BYTE2(v241)];
            v262 = v342 ^ WORD2(v183);
            v295 = (v342 ^ HIDWORD(v183) ^ 0x40000000u) >> 24;
            v302 = &qword_15ABE8[BYTE1(v101)];
            v107 = *((_DWORD *)v106 - 2)
                 ^ ~dword_159BE0[2 * (unsigned __int8)v209]
                 ^ dword_15A3E0[2 * HIBYTE(v287)]
                 ^ *((_DWORD *)v105 - 2)
                 ^ *((_DWORD *)v103 + 2);
            HIDWORD(v326) = &qword_15C3E8[(unsigned __int8)(v319 ^ BYTE4(v183))];
            v394 = (unsigned __int8)((v342 ^ HIDWORD(v183) ^ 0x40000000u) >> 16);
            v202 = 0xFFFFFF - HIDWORD(v183);
            v108 = dword_159BE0[2 * (unsigned __int8)v209 + 1]
                 ^ (0xFFFFFF - HIDWORD(v183))
                 ^ 0xEFFFFFFF
                 ^ dword_15A3E0[2 * HIBYTE(v287) + 1]
                 ^ *((_DWORD *)v105 - 1);
            v109 = (unsigned __int8)v101;
            v385 = &qword_15B3E8[BYTE2(v101)];
            v110 = (unsigned __int8)v228;
            v400 = &qword_15B3E8[BYTE2(v228)];
            v111 = &qword_15ABE8[BYTE1(v241)];
            v343 = &qword_15B3E8[BYTE2(v255)];
            v361 = &qword_15C3E8[(unsigned __int8)(v335 ^ BYTE4(v183))];
            v320 = (unsigned __int8)((v335 ^ HIDWORD(v183) ^ 0x30000000u) >> 16);
            v422 = (unsigned __int8)((unsigned __int16)(WORD2(v183) ^ v97) >> 8);
            v381 = &qword_15C3E8[(unsigned __int8)(BYTE4(v183) ^ v97)];
            v229 = *((_DWORD *)v104 - 2)
                 ^ v107
                 ^ dword_15CBE0[2 * (unsigned __int8)((unsigned __int16)(v335 ^ WORD2(v183)) >> 8)]
                 ^ dword_15D3E0[2 * BYTE2(v236)];
            v237 = v108
                 ^ *((_DWORD *)v106 - 1)
                 ^ *((_DWORD *)v103 + 3)
                 ^ *((_DWORD *)v104 - 1)
                 ^ dword_15CBE0[2 * (unsigned __int8)((unsigned __int16)(v335 ^ WORD2(v183)) >> 8) + 1]
                 ^ dword_15D3E0[2 * BYTE2(v236) + 1];
            v112 = dword_159BE0[2 * (unsigned __int8)v196 + 1]
                 ^ dword_15A3E0[2 * HIBYTE(v279) + 1]
                 ^ (HIDWORD(v183) - 0xFFFFFF);
            HIDWORD(v183) -= 0x1FFFFFF;
            v113 = &qword_15B3E8[(unsigned __int8)((unsigned int)~v96 >> 16)];
            v336 = &qword_15ABE8[(unsigned __int8)((unsigned __int16)~(_WORD)v96 >> 8)];
            v114 = ~(dword_159BE0[2 * (unsigned __int8)v196] ^ dword_15A3E0[2 * HIBYTE(v279)])
                 ^ *((_DWORD *)v302 - 2)
                 ^ *((_DWORD *)v113 - 2);
            v115 = *(_DWORD *)(v326 + 8);
            v116 = *(_DWORD *)(v326 + 12) ^ v112 ^ *((_DWORD *)v302 - 1) ^ *((_DWORD *)v113 - 1);
            LODWORD(v326) = &qword_15B3E8[BYTE2(v248)];
            v117 = *(_DWORD *)(HIDWORD(v326) - 4);
            v118 = *(_DWORD *)(HIDWORD(v326) - 8);
            v303 = BYTE2(v217);
            HIDWORD(v326) = &qword_15C3E8[(unsigned __int8)v217];
            v431 = (unsigned __int8)~(_BYTE)v96;
            v413 = HIBYTE(v262);
            v371 = &qword_15C3E8[(unsigned __int8)v262];
            v223 = v116 ^ v117 ^ dword_15CBE0[2 * BYTE1(v217) + 1] ^ dword_15D3E0[2 * v394 + 1];
            v417 = BYTE2(v279);
            v390 = &qword_15BBD8[(unsigned int)~v96 >> 24];
            v218 = v115 ^ v114 ^ v118 ^ dword_15CBE0[2 * BYTE1(v217)] ^ dword_15D3E0[2 * v394];
            v119 = *((_DWORD *)v111 - 2) ^ dword_15A3E0[2 * HIBYTE(v272)] ^ ~dword_159BE0[2 * v110];
            v120 = dword_15A3E0[2 * HIBYTE(v272) + 1]
                 ^ dword_159BE0[2 * v110 + 1]
                 ^ ~(v202 ^ 0x30000000)
                 ^ *((_DWORD *)v111 - 1);
            v276 = (unsigned __int8)v248;
            v121 = &qword_15ABE8[BYTE1(v248)];
            v122 = *((_DWORD *)v355 + 3);
            v123 = v119 ^ *((_DWORD *)v343 - 2) ^ *((_DWORD *)v355 + 2);
            v124 = &qword_15B3E8[BYTE2(v196)];
            v356 = &qword_15ABE8[BYTE1(v196)];
            v125 = v120 ^ *((_DWORD *)v343 - 1) ^ v122 ^ *((_DWORD *)v361 - 1);
            v126 = v123 ^ *((_DWORD *)v361 - 2);
            v440 = BYTE1(v279);
            v127 = dword_15CBE0[2 * v422];
            v362 = &qword_15C3E8[(unsigned __int8)v279];
            v128 = v125 ^ dword_15CBE0[2 * v422 + 1];
            v129 = BYTE2(v190);
            v280 = BYTE1(v190);
            v423 = (unsigned __int8)v241;
            v130 = HIBYTE(v241);
            v242 = v126 ^ v127 ^ dword_15D3E0[2 * BYTE2(v287)];
            v405 = &qword_15BBD8[v130];
            v307 = (unsigned __int8)v255;
            v249 = v128 ^ dword_15D3E0[2 * BYTE2(v287) + 1];
            v344 = &qword_15ABE8[BYTE1(v255)];
            v131 = *((_DWORD *)v336 - 2);
            v132 = *((_DWORD *)v336 - 1);
            v337 = &qword_15B3E8[BYTE2(v209)];
            v263 = &qword_15C3E8[(unsigned __int8)v287];
            v395 = &qword_15ABE8[BYTE1(v209)];
            v210 = BYTE2(v272);
            v273 = BYTE1(v272);
            v191 = *(_DWORD *)(v326 - 8)
                 ^ ~dword_159BE0[2 * v109]
                 ^ dword_15A3E0[2 * v409]
                 ^ v131
                 ^ *((_DWORD *)v350 + 2)
                 ^ *(_DWORD *)(HIDWORD(v326) - 8)
                 ^ dword_15CBE0[2 * v413]
                 ^ dword_15D3E0[2 * v417];
            v197 = *(_DWORD *)(v326 - 4)
                 ^ dword_159BE0[2 * v109 + 1]
                 ^ ~(v202 ^ 0x20000000)
                 ^ dword_15A3E0[2 * v409 + 1]
                 ^ v132
                 ^ *((_DWORD *)v350 + 3)
                 ^ *(_DWORD *)(HIDWORD(v326) - 4)
                 ^ dword_15CBE0[2 * v413 + 1]
                 ^ dword_15D3E0[2 * v417 + 1];
            v133 = *(v121 - 1);
            v134 = ~dword_159BE0[2 * v431] ^ dword_15A3E0[2 * v437] ^ v133;
            v135 = dword_159BE0[2 * v431 + 1]
                 ^ v202
                 ^ 0xBFFFFFFF
                 ^ dword_15A3E0[2 * v437 + 1]
                 ^ HIDWORD(v133)
                 ^ *((_DWORD *)v124 - 1);
            v136 = v366[1];
            v256 = v135
                 ^ HIDWORD(v136)
                 ^ *((_DWORD *)v371 - 1)
                 ^ dword_15CBE0[2 * v440 + 1]
                 ^ dword_15D3E0[2 * v129 + 1];
            v351 = dword_15D3E0[2 * v210];
            v367 = dword_15D3E0[2 * v210 + 1];
            v211 = v134
                 ^ *((_DWORD *)v124 - 2)
                 ^ v136
                 ^ *((_DWORD *)v371 - 2)
                 ^ dword_15CBE0[2 * v440]
                 ^ dword_15D3E0[2 * v129];
            HIDWORD(v136) = v202
                          ^ 0x9FFFFFFF
                          ^ dword_159BE0[2 * v276 + 1]
                          ^ dword_15A3E0[2 * v295 + 1]
                          ^ *((_DWORD *)v356 - 1)
                          ^ *((_DWORD *)v385 - 1)
                          ^ *((_DWORD *)v390 + 3)
                          ^ *((_DWORD *)v362 - 1)
                          ^ dword_15CBE0[2 * v280 + 1];
            v137 = ~dword_159BE0[2 * v276]
                 ^ dword_15A3E0[2 * v295]
                 ^ *((_DWORD *)v356 - 2)
                 ^ *((_DWORD *)v385 - 2)
                 ^ *((_DWORD *)v390 + 2)
                 ^ *((_DWORD *)v362 - 2)
                 ^ dword_15CBE0[2 * v280];
            v277 = ~dword_159BE0[2 * v307]
                 ^ dword_15A3E0[2 * v315]
                 ^ *((_DWORD *)v395 - 2)
                 ^ *((_DWORD *)v400 - 2)
                 ^ *((_DWORD *)v405 + 2)
                 ^ *((_DWORD *)v263 - 2)
                 ^ dword_15CBE0[2 * v273]
                 ^ dword_15D3E0[2 * v320];
            v281 = ~(v202 ^ 0x70000000)
                 ^ dword_159BE0[2 * v307 + 1]
                 ^ dword_15A3E0[2 * v315 + 1]
                 ^ *((_DWORD *)v395 - 1)
                 ^ *((_DWORD *)v400 - 1)
                 ^ *((_DWORD *)v405 + 3)
                 ^ *((_DWORD *)v263 - 1)
                 ^ dword_15CBE0[2 * v273 + 1]
                 ^ dword_15D3E0[2 * v320 + 1];
            v203 = dword_15A3E0[2 * v442 + 1]
                 ^ dword_159BE0[2 * v423 + 1]
                 ^ v202
                 ^ 0xAFFFFFFF
                 ^ *((_DWORD *)v344 - 1)
                 ^ *((_DWORD *)v337 - 1)
                 ^ *((_DWORD *)v377 + 3)
                 ^ *((_DWORD *)v381 - 1)
                 ^ dword_15CBE0[2 * BYTE1(v287) + 1]
                 ^ v367;
            v187 = *((_DWORD *)v344 - 2)
                 ^ ~dword_159BE0[2 * v423]
                 ^ dword_15A3E0[2 * v442]
                 ^ *((_DWORD *)v337 - 2)
                 ^ *((_DWORD *)v377 + 2)
                 ^ *((_DWORD *)v381 - 2)
                 ^ dword_15CBE0[2 * BYTE1(v287)]
                 ^ v351;
            v138 = dword_15D3E0[2 * v303 + 1] ^ HIDWORD(v136);
            v288 = HIBYTE(v223);
            LOWORD(v273) = LOWORD(dword_15D3E0[2 * v303 + 1]) ^ WORD2(v136);
            v428 = HIBYTE(v197);
            v264 = v137 ^ dword_15D3E0[2 * v303];
            v304 = HIBYTE(v256);
            v438 = HIBYTE(v249);
            v308 = HIBYTE(v203);
            v139 = &dword_15A3E0[2 * HIBYTE(v138)];
            v378 = &qword_15BBD8[HIBYTE(v242)];
            v338 = &dword_15A3E0[2 * HIBYTE(v223)];
            v386 = &qword_15BBD8[HIBYTE(v211)];
            v140 = *v139;
            v141 = qword_15C3E8[(unsigned __int8)v223 - 1];
            v142 = &qword_15ABE8[BYTE1(v242)];
            LODWORD(v136) = &qword_15B3E8[BYTE2(v187)];
            v143 = BYTE1(v249);
            v144 = qword_15BBD8[HIBYTE(v277) + 1];
            v145 = v139[1]
                 ^ dword_159BE0[2 * (unsigned __int8)v229 + 1]
                 ^ *((_DWORD *)v142 - 1)
                 ^ *(_DWORD *)(v136 - 4)
                 ^ HIDWORD(v144)
                 ^ HIDWORD(v141);
            v410 = (unsigned __int8)v242;
            v396 = &qword_15B3E8[BYTE2(v242)];
            v146 = v140 ^ dword_159BE0[2 * (unsigned __int8)v229] ^ *((_DWORD *)v142 - 2) ^ *(_DWORD *)(v136 - 8) ^ v144;
            LODWORD(v144) = &qword_15ABE8[BYTE1(v187)];
            HIDWORD(v141) = &qword_15B3E8[BYTE2(v277)];
            v243 = BYTE2(v197);
            v314 = v146 ^ v141 ^ dword_15CBE0[2 * BYTE1(v197)] ^ dword_15D3E0[2 * BYTE2(v256)];
            v147 = BYTE1(v256);
            v319 = v145 ^ dword_15CBE0[2 * BYTE1(v197) + 1] ^ dword_15D3E0[2 * BYTE2(v256) + 1];
            v382 = &qword_15C3E8[(unsigned __int8)v256];
            v414 = BYTE2(v138);
            v418 = (unsigned __int8)v211;
            v406 = &qword_15B3E8[BYTE2(v211)];
            v257 = &qword_15ABE8[BYTE1(v264)];
            v363 = &qword_15B3E8[BYTE2(v218)];
            v372 = &qword_15C3E8[(unsigned __int8)v249];
            v250 = BYTE2(v249);
            LODWORD(v141) = BYTE1(v203);
            v391 = &qword_15C3E8[(unsigned __int8)v203];
            v148 = BYTE2(v223);
            v224 = BYTE1(v223);
            v432 = v148;
            v424 = (unsigned __int8)v187;
            v326 = *(_QWORD *)&dword_159BE0[2 * (unsigned __int8)v191]
                 ^ *(_QWORD *)&dword_15A3E0[2 * HIBYTE(v281)]
                 ^ qword_15ABE8[BYTE1(v211) - 1]
                 ^ qword_15B3E8[BYTE2(v264) - 1]
                 ^ qword_15BBD8[HIBYTE(v218) + 1]
                 ^ qword_15C3E8[(unsigned __int8)v237 - 1]
                 ^ *(_QWORD *)&dword_15CBE0[2 * v143]
                 ^ *(_QWORD *)&dword_15D3E0[2 * BYTE2(v203)];
            v149 = dword_15A3E0[2 * v288] ^ dword_159BE0[2 * v410];
            v188 = &qword_15BBD8[HIBYTE(v187)];
            v150 = *(_DWORD *)(v144 - 8);
            v151 = v338[1] ^ dword_159BE0[2 * v410 + 1] ^ *(_DWORD *)(v144 - 4);
            v212 = (unsigned __int8)v277;
            LODWORD(v144) = &qword_15BBD8[HIBYTE(v229)];
            v289 = &qword_15ABE8[BYTE1(v277)];
            v152 = *(_DWORD *)(v144 + 8);
            v153 = v151 ^ *(_DWORD *)(HIDWORD(v141) - 4) ^ *(_DWORD *)(v144 + 12);
            v154 = &qword_15C3E8[(unsigned __int8)v197];
            LODWORD(v144) = &qword_15B3E8[BYTE2(v229)];
            v357 = &qword_15ABE8[BYTE1(v229)];
            HIDWORD(v144) = BYTE1(v273);
            v198 = &qword_15C3E8[(unsigned __int8)v273];
            v345 = (unsigned __int8)v264;
            v204 = &qword_15BBD8[HIBYTE(v264)];
            v265 = &qword_15ABE8[BYTE1(v218)];
            v275 = v153 ^ *((_DWORD *)v154 - 1) ^ dword_15CBE0[2 * v147 + 1] ^ dword_15D3E0[2 * v414 + 1];
            v271 = v149
                 ^ v150
                 ^ *(_DWORD *)(HIDWORD(v141) - 8)
                 ^ v152
                 ^ *((_DWORD *)v154 - 2)
                 ^ dword_15CBE0[2 * v147]
                 ^ dword_15D3E0[2 * v414];
            v352 = &qword_15B3E8[BYTE2(v191)];
            v401 = &qword_15ABE8[BYTE1(v191)];
            v155 = &qword_15BBD8[HIBYTE(v191)];
            v192 = &qword_15C3E8[(unsigned __int8)v281];
            v230 = BYTE1(v237);
            v335 = dword_159BE0[2 * v418 + 1]
                 ^ dword_15A3E0[2 * HIBYTE(v237) + 1]
                 ^ *((_DWORD *)v257 - 1)
                 ^ *((_DWORD *)v363 - 1)
                 ^ *((_DWORD *)v155 + 3)
                 ^ *((_DWORD *)v372 - 1)
                 ^ dword_15CBE0[2 * (_DWORD)v141 + 1]
                 ^ dword_15D3E0[2 * BYTE2(v281) + 1];
            v294 = dword_15A3E0[2 * HIBYTE(v237)]
                 ^ dword_159BE0[2 * v418]
                 ^ *((_DWORD *)v257 - 2)
                 ^ *((_DWORD *)v363 - 2)
                 ^ *((_DWORD *)v155 + 2)
                 ^ *((_DWORD *)v372 - 2)
                 ^ dword_15CBE0[2 * (_DWORD)v141]
                 ^ dword_15D3E0[2 * BYTE2(v281)];
            v156 = dword_15A3E0[2 * v438] ^ dword_159BE0[2 * v345];
            HIDWORD(v136) = dword_159BE0[2 * v424 + 1]
                          ^ dword_15A3E0[2 * v428 + 1]
                          ^ *((_DWORD *)v289 - 1)
                          ^ *(_DWORD *)(v144 - 4)
                          ^ *((_DWORD *)v378 + 3);
            v157 = dword_159BE0[2 * v424]
                 ^ dword_15A3E0[2 * v428]
                 ^ *((_DWORD *)v289 - 2)
                 ^ *(_DWORD *)(v144 - 8)
                 ^ *((_DWORD *)v378 + 2);
            v158 = dword_15CBE0[2 * BYTE1(v281)];
            v159 = dword_15CBE0[2 * BYTE1(v281) + 1];
            v282 = *(_QWORD *)&dword_15D3E0[2 * BYTE2(v237)];
            v160 = dword_15A3E0[2 * v438 + 1] ^ dword_159BE0[2 * v345 + 1] ^ *((_DWORD *)v265 - 1);
            v235 = *((_DWORD *)v382 - 2) ^ v157 ^ dword_15CBE0[2 * HIDWORD(v144)] ^ dword_15D3E0[2 * v432];
            v342 = HIDWORD(v136)
                 ^ *((_DWORD *)v382 - 1)
                 ^ dword_15CBE0[2 * HIDWORD(v144) + 1]
                 ^ dword_15D3E0[2 * v432 + 1];
            v161 = dword_159BE0[2 * v212] ^ dword_15A3E0[2 * v304];
            LODWORD(v136) = dword_15A3E0[2 * v304 + 1] ^ dword_159BE0[2 * v212 + 1];
            v213 = *((_DWORD *)v386 + 2)
                 ^ v156
                 ^ *((_DWORD *)v265 - 2)
                 ^ *((_DWORD *)v352 - 2)
                 ^ *((_DWORD *)v391 - 2)
                 ^ v158;
            v98 = dword_15D3E0[2 * v243]
                ^ v161
                ^ *((_DWORD *)v357 - 2)
                ^ *((_DWORD *)v396 - 2)
                ^ *((_DWORD *)v188 + 2)
                ^ *((_DWORD *)v198 - 2)
                ^ dword_15CBE0[2 * v224];
            v162 = dword_15D3E0[2 * v250];
            v163 = dword_159BE0[2 * (unsigned __int8)v218]
                 ^ dword_15A3E0[2 * v308]
                 ^ *((_DWORD *)v401 - 2)
                 ^ *((_DWORD *)v406 - 2)
                 ^ *((_DWORD *)v204 + 2)
                 ^ *((_DWORD *)v192 - 2)
                 ^ dword_15CBE0[2 * v230];
            v100 = v163 ^ v162;
            v97 = v160 ^ *((_DWORD *)v352 - 1) ^ *((_DWORD *)v386 + 3) ^ *((_DWORD *)v391 - 1) ^ v159 ^ HIDWORD(v282);
            v96 = v213 ^ v282;
            v186 = v136
                 ^ *((_DWORD *)v357 - 1)
                 ^ *((_DWORD *)v396 - 1)
                 ^ *((_DWORD *)v188 + 3)
                 ^ *((_DWORD *)v198 - 1)
                 ^ dword_15CBE0[2 * v224 + 1]
                 ^ dword_15D3E0[2 * v243 + 1];
            v99 = dword_159BE0[2 * (unsigned __int8)v218 + 1]
                ^ dword_15A3E0[2 * v308 + 1]
                ^ *((_DWORD *)v401 - 1)
                ^ *((_DWORD *)v406 - 1)
                ^ *((_DWORD *)v204 + 3)
                ^ *((_DWORD *)v192 - 1)
                ^ dword_15CBE0[2 * v230 + 1]
                ^ dword_15D3E0[2 * v250 + 1];
          }
          while ( v183 != 0xF5FFFFFFFFFFFFFFLL );
          v164 = &v452;
          v165 = &v468;
          v166 = v314;
          v468 = v326;
          v167 = v319;
          v479 = v163 ^ v162;
          v480 = v99;
          v466 = v314;
          v469 = v271;
          v467 = v319;
          v475 = v213 ^ v282;
          v470 = v275;
          v476 = v97;
          v477 = v98;
          v471 = v294;
          v478 = v186;
          v168 = v447;
          v472 = v335;
          v169 = HIDWORD(v321);
          v473 = v235;
          v474 = v342;
          v170 = v321;
          while ( 1 )
          {
            v171 = *(_DWORD *)(v168 + 8);
            v168 += 8;
            v172 = v167 ^ v169;
            v173 = *(_DWORD *)(v168 + 4);
            *(_DWORD *)v168 = v171 ^ v170 ^ v166;
            *(_DWORD *)(v168 + 4) = v173 ^ v172;
            if ( v450 == (_BYTE *)v168 )
              break;
            v170 = *v164;
            ++v165;
            v169 = v164[1];
            v164 += 2;
            v166 = *((_DWORD *)v165 - 2);
            v167 = *((_DWORD *)v165 - 1);
          }
          v3 = 0;
          ++*((_QWORD *)a1 + 17);
          if ( !n )
            break;
        }
        else if ( !n )
        {
          break;
        }
      }
    }
    v174 = v448;
    v175 = (__int64 *)v449;
    do
    {
      v174 += 4;
      result = *(void **)v175;
      v177 = *((_DWORD *)v175 + 1);
      v178 = *((_DWORD *)v175 + 2);
      v179 = *((_DWORD *)v175 + 3);
      v175 += 2;
      *(v174 - 4) = result;
      *(v174 - 3) = v177;
      *(v174 - 2) = v178;
      *(v174 - 1) = v179;
    }
    while ( v175 != &v451 );
    a1[16] = v3;
  }
  return result;
}
