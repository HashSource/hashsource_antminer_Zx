void __fastcall scrypt_1024_1_1_256_sp(const uint32_t *input, char *scratchpad, uint32_t *ostate)
{
  int *v3; // r6
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int *v7; // r7
  int *v8; // r8
  int *v9; // r4
  int v10; // t1
  __int64 v11; // r2
  unsigned int v12; // r0
  int *v13; // lr
  unsigned int v14; // r1
  unsigned int v15; // r3
  _DWORD *i; // r0
  unsigned int v17; // t1
  int v18; // t1
  int v19; // r7
  uint32_t *v20; // r8
  uint32_t *v21; // r2
  uint32_t *v22; // r1
  unsigned int v23; // t1
  int v24; // r7
  int v25; // r10
  int v26; // r0
  int v27; // r9
  int v28; // r12
  int v29; // r11
  int v30; // r3
  int v31; // lr
  int v32; // r2
  int v33; // r1
  int v34; // r4
  int v35; // r8
  int v36; // r7
  int v37; // r6
  int v38; // r5
  int v39; // r4
  int v40; // r10
  int v41; // r9
  int v42; // r3
  int v43; // r3
  int v44; // r12
  int v45; // r0
  int v46; // r2
  int v47; // r1
  int v48; // r11
  int v49; // r5
  int v50; // r6
  int v51; // r7
  uint32_t v52; // r1
  int v53; // r2
  int v54; // r10
  int v55; // lr
  int v56; // r3
  int v57; // r7
  int v58; // r11
  int v59; // r9
  int v60; // r12
  int v61; // r0
  int v62; // r5
  int v63; // r2
  int v64; // r8
  int v65; // r4
  int v66; // r6
  int v67; // r9
  int v68; // r10
  int v69; // r0
  int v70; // r3
  int v71; // r12
  int v72; // r7
  int v73; // r4
  int v74; // r11
  int v75; // r2
  int v76; // r6
  int v77; // r1
  int v78; // r10
  int v79; // r9
  int v80; // r1
  int v81; // r11
  int v82; // r2
  int v83; // r3
  int v84; // r12
  int v85; // r4
  int v86; // r0
  int v87; // lr
  int v88; // r8
  int v89; // r7
  int v90; // r6
  int v91; // r5
  int v92; // r4
  int v93; // r10
  int v94; // r9
  int v95; // r3
  int v96; // r3
  int v97; // r12
  int v98; // r0
  int v99; // r2
  int v100; // r1
  int v101; // r11
  int v102; // r5
  int v103; // r6
  int v104; // r7
  uint32_t v105; // r6
  int v106; // r2
  int v107; // r7
  int v108; // r10
  int v109; // lr
  int v110; // r3
  int v111; // r7
  int v112; // r11
  int v113; // r9
  int v114; // r12
  int v115; // r0
  int v116; // r5
  int v117; // r2
  int v118; // r8
  int v119; // r4
  int v120; // r6
  int v121; // r9
  int v122; // r10
  int v123; // r0
  int v124; // r3
  int v125; // r12
  int v126; // r7
  int v127; // r4
  int v128; // r11
  int v129; // r2
  int v130; // r6
  int v131; // r1
  __int16 v132; // r4
  uint32_t *v133; // r11
  int v134; // r4
  uint32_t v135; // r2
  int v136; // r0
  int v137; // r1
  int v138; // r3
  uint32_t v139; // r10
  uint32_t v140; // lr
  uint32_t v141; // r4
  uint32_t v142; // r9
  uint32_t v143; // r8
  uint32_t v144; // r12
  uint32_t v145; // r7
  uint32_t v146; // r2
  uint32_t v147; // r3
  uint32_t v148; // r6
  int v149; // lr
  int v150; // r12
  int v151; // r9
  int v152; // r11
  int v153; // r10
  int v154; // r2
  int v155; // r7
  int v156; // r3
  int v157; // r5
  int v158; // r12
  int v159; // r4
  int v160; // r3
  int v161; // r1
  int v162; // r0
  uint32_t v163; // lr
  int v164; // r9
  int v165; // r10
  int v166; // r8
  uint32_t v167; // r12
  int v168; // r3
  int v169; // r4
  uint32_t v170; // r2
  int v171; // r7
  int v172; // r5
  int v173; // lr
  int v174; // r7
  int v175; // r12
  int v176; // r9
  int v177; // r8
  int v178; // r10
  int v179; // r11
  int v180; // r5
  int v181; // r3
  int v182; // lr
  int v183; // r1
  int v184; // r4
  int v185; // r7
  int v186; // r2
  int v187; // r6
  int v188; // r0
  int v189; // r4
  int v190; // r6
  uint32_t *v191; // r1
  uint32_t v192; // r0
  uint32_t v193; // r2
  int v194; // r5
  int v195; // r4
  int v196; // r3
  uint32_t v197; // r10
  uint32_t v198; // r8
  uint32_t v199; // lr
  uint32_t v200; // r9
  uint32_t v201; // r12
  uint32_t v202; // r1
  uint32_t v203; // r11
  uint32_t v204; // r2
  uint32_t v205; // r3
  uint32_t v206; // r6
  int v207; // r8
  int v208; // r9
  int v209; // r4
  int v210; // lr
  int v211; // r11
  int v212; // r10
  int v213; // r5
  int v214; // r3
  int v215; // r7
  int v216; // r1
  int v217; // r5
  int v218; // r3
  int v219; // r0
  int v220; // r4
  uint32_t v221; // r8
  uint32_t v222; // lr
  uint32_t v223; // r2
  uint32_t v224; // r6
  int v225; // r12
  uint32_t v226; // r4
  uint32_t v227; // r5
  int v228; // r9
  int v229; // r10
  uint32_t v230; // r0
  uint32_t v231; // r11
  uint32_t v232; // r3
  uint32_t v233; // r2
  uint32_t v234; // r6
  uint32_t v235; // r7
  int v236; // r8
  int v237; // lr
  int v238; // r5
  int v239; // r0
  int v240; // r9
  int v241; // r10
  int v242; // r12
  int v243; // r6
  int v244; // r7
  int v245; // r2
  int v246; // r11
  int v247; // r5
  int v248; // r4
  bool v249; // zf
  char *v250; // r8
  int *v251; // r6
  int *v252; // r5
  uint32_t v253; // r1
  uint32_t v254; // r2
  uint32_t v255; // r3
  char *v256; // r12
  uint32_t v257; // r0
  int v258; // r1
  int v259; // r2
  int v260; // r3
  int v261; // r0
  int v262; // r1
  int v263; // r2
  int v264; // r3
  int v265; // t1
  int v266; // t1
  int v267; // [sp+0h] [bp-160h]
  int v268; // [sp+0h] [bp-160h]
  int v269; // [sp+0h] [bp-160h]
  int v270; // [sp+0h] [bp-160h]
  int v271; // [sp+0h] [bp-160h]
  int v272; // [sp+0h] [bp-160h]
  int v273; // [sp+0h] [bp-160h]
  int v274; // [sp+0h] [bp-160h]
  uint32_t v275; // [sp+0h] [bp-160h]
  int v276; // [sp+0h] [bp-160h]
  uint32_t v277; // [sp+0h] [bp-160h]
  int v278; // [sp+0h] [bp-160h]
  int v279; // [sp+4h] [bp-15Ch]
  int v280; // [sp+4h] [bp-15Ch]
  int v281; // [sp+4h] [bp-15Ch]
  int v282; // [sp+4h] [bp-15Ch]
  int v283; // [sp+4h] [bp-15Ch]
  int v284; // [sp+4h] [bp-15Ch]
  int v285; // [sp+4h] [bp-15Ch]
  uint32_t v286; // [sp+4h] [bp-15Ch]
  int v287; // [sp+4h] [bp-15Ch]
  uint32_t v288; // [sp+4h] [bp-15Ch]
  int v289; // [sp+4h] [bp-15Ch]
  int v290; // [sp+8h] [bp-158h]
  int v291; // [sp+8h] [bp-158h]
  int v292; // [sp+8h] [bp-158h]
  int v293; // [sp+8h] [bp-158h]
  int v294; // [sp+8h] [bp-158h]
  int v295; // [sp+8h] [bp-158h]
  uint32_t v296; // [sp+8h] [bp-158h]
  int v297; // [sp+8h] [bp-158h]
  uint32_t v298; // [sp+8h] [bp-158h]
  int v299; // [sp+8h] [bp-158h]
  int v300; // [sp+Ch] [bp-154h]
  int v301; // [sp+Ch] [bp-154h]
  int v302; // [sp+Ch] [bp-154h]
  int v303; // [sp+Ch] [bp-154h]
  uint32_t v304; // [sp+Ch] [bp-154h]
  uint32_t v305; // [sp+Ch] [bp-154h]
  uint32_t v306; // [sp+Ch] [bp-154h]
  int v307; // [sp+Ch] [bp-154h]
  int v308; // [sp+10h] [bp-150h]
  int v309; // [sp+10h] [bp-150h]
  int v310; // [sp+10h] [bp-150h]
  int v311; // [sp+10h] [bp-150h]
  int v312; // [sp+10h] [bp-150h]
  int v313; // [sp+10h] [bp-150h]
  uint32_t v314; // [sp+10h] [bp-150h]
  int v315; // [sp+10h] [bp-150h]
  int v316; // [sp+10h] [bp-150h]
  uint32_t v317; // [sp+10h] [bp-150h]
  int v318; // [sp+10h] [bp-150h]
  int v319; // [sp+14h] [bp-14Ch]
  int v320; // [sp+14h] [bp-14Ch]
  int v321; // [sp+14h] [bp-14Ch]
  int v322; // [sp+14h] [bp-14Ch]
  int v323; // [sp+14h] [bp-14Ch]
  uint32_t v324; // [sp+14h] [bp-14Ch]
  uint32_t v325; // [sp+14h] [bp-14Ch]
  int v326; // [sp+14h] [bp-14Ch]
  int v327; // [sp+18h] [bp-148h]
  int v328; // [sp+18h] [bp-148h]
  int v329; // [sp+18h] [bp-148h]
  int v330; // [sp+18h] [bp-148h]
  uint32_t v331; // [sp+18h] [bp-148h]
  int v332; // [sp+18h] [bp-148h]
  int v333; // [sp+18h] [bp-148h]
  int v334; // [sp+18h] [bp-148h]
  int v335; // [sp+1Ch] [bp-144h]
  int v336; // [sp+1Ch] [bp-144h]
  int v337; // [sp+1Ch] [bp-144h]
  int v338; // [sp+1Ch] [bp-144h]
  int v339; // [sp+1Ch] [bp-144h]
  int v340; // [sp+1Ch] [bp-144h]
  int v341; // [sp+1Ch] [bp-144h]
  int v342; // [sp+1Ch] [bp-144h]
  int v343; // [sp+20h] [bp-140h]
  int v344; // [sp+20h] [bp-140h]
  int v345; // [sp+20h] [bp-140h]
  int v346; // [sp+20h] [bp-140h]
  int v347; // [sp+20h] [bp-140h]
  int v348; // [sp+20h] [bp-140h]
  int v349; // [sp+20h] [bp-140h]
  int v350; // [sp+24h] [bp-13Ch]
  int v351; // [sp+24h] [bp-13Ch]
  int v352; // [sp+24h] [bp-13Ch]
  int v353; // [sp+24h] [bp-13Ch]
  int v354; // [sp+24h] [bp-13Ch]
  int v355; // [sp+24h] [bp-13Ch]
  int v356; // [sp+24h] [bp-13Ch]
  int v357; // [sp+24h] [bp-13Ch]
  uint32_t *dest; // [sp+28h] [bp-138h]
  int desta; // [sp+28h] [bp-138h]
  void *destb; // [sp+28h] [bp-138h]
  int destc; // [sp+28h] [bp-138h]
  int destd; // [sp+28h] [bp-138h]
  uint32_t v363; // [sp+2Ch] [bp-134h]
  int v364; // [sp+2Ch] [bp-134h]
  int v365; // [sp+2Ch] [bp-134h]
  uint32_t v366; // [sp+2Ch] [bp-134h]
  int v367; // [sp+2Ch] [bp-134h]
  int v368; // [sp+2Ch] [bp-134h]
  uint32_t v369; // [sp+30h] [bp-130h]
  int v370; // [sp+30h] [bp-130h]
  uint32_t v371; // [sp+30h] [bp-130h]
  int v372; // [sp+30h] [bp-130h]
  uint32_t v373; // [sp+30h] [bp-130h]
  uint32_t v374; // [sp+30h] [bp-130h]
  uint32_t v375; // [sp+34h] [bp-12Ch]
  int v376; // [sp+34h] [bp-12Ch]
  uint32_t v377; // [sp+34h] [bp-12Ch]
  int v378; // [sp+34h] [bp-12Ch]
  uint32_t v379; // [sp+34h] [bp-12Ch]
  uint32_t v380; // [sp+34h] [bp-12Ch]
  uint32_t v381; // [sp+34h] [bp-12Ch]
  uint32_t v382; // [sp+38h] [bp-128h]
  int v383; // [sp+38h] [bp-128h]
  uint32_t v384; // [sp+38h] [bp-128h]
  int v385; // [sp+38h] [bp-128h]
  uint32_t v386; // [sp+38h] [bp-128h]
  uint32_t v387; // [sp+38h] [bp-128h]
  uint32_t v388; // [sp+38h] [bp-128h]
  uint32_t v389; // [sp+3Ch] [bp-124h]
  int v390; // [sp+3Ch] [bp-124h]
  uint32_t v391; // [sp+3Ch] [bp-124h]
  int v392; // [sp+3Ch] [bp-124h]
  uint32_t v393; // [sp+3Ch] [bp-124h]
  uint32_t v394; // [sp+3Ch] [bp-124h]
  uint32_t v395; // [sp+3Ch] [bp-124h]
  uint32_t v396; // [sp+40h] [bp-120h]
  int v397; // [sp+40h] [bp-120h]
  int v398; // [sp+40h] [bp-120h]
  uint32_t v399; // [sp+40h] [bp-120h]
  uint32_t v400; // [sp+40h] [bp-120h]
  uint32_t v401; // [sp+40h] [bp-120h]
  uint32_t v402; // [sp+44h] [bp-11Ch]
  int v403; // [sp+44h] [bp-11Ch]
  int v404; // [sp+44h] [bp-11Ch]
  uint32_t v405; // [sp+44h] [bp-11Ch]
  uint32_t v406; // [sp+44h] [bp-11Ch]
  uint32_t v407; // [sp+48h] [bp-118h]
  int v408; // [sp+48h] [bp-118h]
  int v409; // [sp+48h] [bp-118h]
  uint32_t v410; // [sp+48h] [bp-118h]
  uint32_t v411; // [sp+48h] [bp-118h]
  uint32_t v412; // [sp+4Ch] [bp-114h]
  int v413; // [sp+4Ch] [bp-114h]
  int v414; // [sp+4Ch] [bp-114h]
  uint32_t v415; // [sp+4Ch] [bp-114h]
  uint32_t v416; // [sp+4Ch] [bp-114h]
  uint32_t v417; // [sp+50h] [bp-110h]
  int v418; // [sp+50h] [bp-110h]
  uint32_t v419; // [sp+50h] [bp-110h]
  int v420; // [sp+50h] [bp-110h]
  uint32_t v421; // [sp+50h] [bp-110h]
  uint32_t v422; // [sp+50h] [bp-110h]
  uint32_t v423; // [sp+54h] [bp-10Ch]
  int v424; // [sp+54h] [bp-10Ch]
  uint32_t v425; // [sp+54h] [bp-10Ch]
  int v426; // [sp+54h] [bp-10Ch]
  int v427; // [sp+54h] [bp-10Ch]
  uint32_t v428; // [sp+58h] [bp-108h]
  int v429; // [sp+58h] [bp-108h]
  uint32_t v430; // [sp+58h] [bp-108h]
  int v431; // [sp+58h] [bp-108h]
  int v432; // [sp+58h] [bp-108h]
  uint32_t v433; // [sp+5Ch] [bp-104h]
  int v434; // [sp+5Ch] [bp-104h]
  uint32_t v435; // [sp+5Ch] [bp-104h]
  int v436; // [sp+5Ch] [bp-104h]
  uint32_t v437; // [sp+5Ch] [bp-104h]
  uint32_t v438; // [sp+5Ch] [bp-104h]
  uint32_t v439; // [sp+60h] [bp-100h]
  int v440; // [sp+60h] [bp-100h]
  uint32_t v441; // [sp+60h] [bp-100h]
  int v442; // [sp+60h] [bp-100h]
  uint32_t v443; // [sp+60h] [bp-100h]
  uint32_t v444; // [sp+64h] [bp-FCh]
  int v445; // [sp+64h] [bp-FCh]
  uint32_t v446; // [sp+64h] [bp-FCh]
  int v447; // [sp+64h] [bp-FCh]
  uint32_t v448; // [sp+64h] [bp-FCh]
  uint32_t v449; // [sp+64h] [bp-FCh]
  uint32_t v450; // [sp+64h] [bp-FCh]
  uint32_t v451; // [sp+68h] [bp-F8h]
  int v452; // [sp+68h] [bp-F8h]
  uint32_t v453; // [sp+68h] [bp-F8h]
  int v454; // [sp+68h] [bp-F8h]
  uint32_t v455; // [sp+68h] [bp-F8h]
  uint32_t v456; // [sp+68h] [bp-F8h]
  uint32_t v457; // [sp+6Ch] [bp-F4h]
  int v458; // [sp+6Ch] [bp-F4h]
  uint32_t v459; // [sp+6Ch] [bp-F4h]
  int v460; // [sp+6Ch] [bp-F4h]
  uint32_t v461; // [sp+6Ch] [bp-F4h]
  uint32_t v462; // [sp+6Ch] [bp-F4h]
  uint32_t v463; // [sp+6Ch] [bp-F4h]
  uint32_t v464; // [sp+70h] [bp-F0h]
  int v465; // [sp+70h] [bp-F0h]
  uint32_t v466; // [sp+70h] [bp-F0h]
  int v467; // [sp+70h] [bp-F0h]
  uint32_t v468; // [sp+70h] [bp-F0h]
  uint32_t v469; // [sp+74h] [bp-ECh]
  int v470; // [sp+74h] [bp-ECh]
  uint32_t v471; // [sp+74h] [bp-ECh]
  int v472; // [sp+74h] [bp-ECh]
  uint32_t v473; // [sp+74h] [bp-ECh]
  uint32_t v474; // [sp+74h] [bp-ECh]
  uint32_t v475; // [sp+74h] [bp-ECh]
  uint32_t v476; // [sp+78h] [bp-E8h]
  int v477; // [sp+78h] [bp-E8h]
  uint32_t v478; // [sp+78h] [bp-E8h]
  int v479; // [sp+78h] [bp-E8h]
  uint32_t v480; // [sp+7Ch] [bp-E4h]
  int v481; // [sp+7Ch] [bp-E4h]
  uint32_t v482; // [sp+7Ch] [bp-E4h]
  int v483; // [sp+7Ch] [bp-E4h]
  uint32_t v484; // [sp+7Ch] [bp-E4h]
  uint32_t v485; // [sp+7Ch] [bp-E4h]
  uint32_t v486; // [sp+80h] [bp-E0h]
  int v487; // [sp+80h] [bp-E0h]
  int v488; // [sp+80h] [bp-E0h]
  uint32_t v489; // [sp+84h] [bp-DCh]
  int v490; // [sp+84h] [bp-DCh]
  int v491; // [sp+84h] [bp-DCh]
  uint32_t v492; // [sp+84h] [bp-DCh]
  uint32_t v493; // [sp+84h] [bp-DCh]
  uint32_t v494; // [sp+88h] [bp-D8h]
  int v495; // [sp+88h] [bp-D8h]
  int v496; // [sp+88h] [bp-D8h]
  uint32_t v497; // [sp+8Ch] [bp-D4h]
  int v498; // [sp+8Ch] [bp-D4h]
  int v499; // [sp+8Ch] [bp-D4h]
  int v500; // [sp+8Ch] [bp-D4h]
  uint32_t v501; // [sp+8Ch] [bp-D4h]
  uint32_t v502; // [sp+8Ch] [bp-D4h]
  uint32_t v503; // [sp+90h] [bp-D0h]
  int v504; // [sp+90h] [bp-D0h]
  uint32_t v505; // [sp+94h] [bp-CCh]
  uint32_t v506; // [sp+94h] [bp-CCh]
  int v507; // [sp+94h] [bp-CCh]
  uint32_t v508; // [sp+94h] [bp-CCh]
  uint32_t v509; // [sp+94h] [bp-CCh]
  uint32_t v510; // [sp+98h] [bp-C8h]
  uint32_t v511; // [sp+98h] [bp-C8h]
  int v512; // [sp+98h] [bp-C8h]
  uint32_t v513; // [sp+9Ch] [bp-C4h]
  int v514; // [sp+9Ch] [bp-C4h]
  uint32_t v515; // [sp+9Ch] [bp-C4h]
  uint32_t v516; // [sp+9Ch] [bp-C4h]
  uint32_t v517; // [sp+9Ch] [bp-C4h]
  uint32_t v518; // [sp+A0h] [bp-C0h]
  int v519; // [sp+A0h] [bp-C0h]
  uint32_t v520; // [sp+A0h] [bp-C0h]
  int v521; // [sp+A0h] [bp-C0h]
  uint32_t v522; // [sp+A4h] [bp-BCh]
  uint32_t v523; // [sp+A4h] [bp-BCh]
  uint32_t v524; // [sp+A4h] [bp-BCh]
  uint32_t v525; // [sp+A8h] [bp-B8h]
  int v526; // [sp+A8h] [bp-B8h]
  int v527; // [sp+A8h] [bp-B8h]
  int v528; // [sp+ACh] [bp-B4h]
  int v529; // [sp+ACh] [bp-B4h]
  int v530; // [sp+ACh] [bp-B4h]
  uint32_t v531; // [sp+ACh] [bp-B4h]
  uint32_t v532; // [sp+ACh] [bp-B4h]
  int v533; // [sp+B0h] [bp-B0h]
  int v534; // [sp+B0h] [bp-B0h]
  uint32_t v535; // [sp+B0h] [bp-B0h]
  int v536; // [sp+B4h] [bp-ACh]
  int v537; // [sp+B4h] [bp-ACh]
  uint32_t *v538; // [sp+B4h] [bp-ACh]
  int v539; // [sp+B8h] [bp-A8h]
  int v540; // [sp+B8h] [bp-A8h]
  int v541; // [sp+BCh] [bp-A4h]
  uint32_t v542; // [sp+C0h] [bp-A0h]
  uint32_t v543; // [sp+C4h] [bp-9Ch]
  int v544; // [sp+C8h] [bp-98h]
  uint32_t *V; // [sp+D4h] [bp-8Ch]
  const uint32_t *v547; // [sp+D8h] [bp-88h]
  uint32_t state; // [sp+E0h] [bp-80h] BYREF
  int v550; // [sp+E4h] [bp-7Ch]
  int v551; // [sp+E8h] [bp-78h]
  int v552; // [sp+ECh] [bp-74h]
  int v553; // [sp+F0h] [bp-70h]
  int v554; // [sp+F4h] [bp-6Ch]
  int v555; // [sp+F8h] [bp-68h]
  _DWORD v556[8]; // [sp+FCh] [bp-64h] BYREF
  int v557; // [sp+11Ch] [bp-44h] BYREF
  uint32_t v558; // [sp+120h] [bp-40h] BYREF
  uint32_t v559; // [sp+124h] [bp-3Ch]
  uint32_t v560; // [sp+128h] [bp-38h]
  uint32_t v561; // [sp+12Ch] [bp-34h]
  uint32_t v562; // [sp+130h] [bp-30h]
  uint32_t v563; // [sp+134h] [bp-2Ch]
  uint32_t v564; // [sp+138h] [bp-28h]
  uint32_t v565; // [sp+13Ch] [bp-24h] BYREF
  uint32_t v566[7]; // [sp+140h] [bp-20h] BYREF
  int v567; // [sp+15Ch] [bp-4h] BYREF
  uint32_t block; // [sp+160h] [bp+0h] BYREF
  int v569; // [sp+164h] [bp+4h]
  int v570; // [sp+168h] [bp+8h]
  int v571; // [sp+16Ch] [bp+Ch]
  int v572; // [sp+170h] [bp+10h]
  int v573; // [sp+174h] [bp+14h]
  int v574; // [sp+178h] [bp+18h]
  int v575; // [sp+17Ch] [bp+1Ch]
  _DWORD v576[8]; // [sp+180h] [bp+20h] BYREF
  uint32_t v577; // [sp+1A0h] [bp+40h] BYREF
  int v578; // [sp+1A4h] [bp+44h]
  int v579; // [sp+1A8h] [bp+48h]
  int v580; // [sp+1ACh] [bp+4Ch]
  int v581; // [sp+1B0h] [bp+50h]
  int v582; // [sp+1B4h] [bp+54h]
  int v583; // [sp+1B8h] [bp+58h]
  int v584; // [sp+1BCh] [bp+5Ch] BYREF
  uint32_t v585[4]; // [sp+1C0h] [bp+60h] BYREF
  int v586; // [sp+1D0h] [bp+70h] BYREF
  char v587; // [sp+1FCh] [bp+9Ch] BYREF
  uint32_t v588; // [sp+200h] [bp+A0h] BYREF
  uint32_t v589; // [sp+204h] [bp+A4h]
  uint32_t v590; // [sp+208h] [bp+A8h]
  uint32_t v591; // [sp+20Ch] [bp+ACh]
  uint32_t v592; // [sp+210h] [bp+B0h]
  uint32_t v593; // [sp+214h] [bp+B4h]
  uint32_t v594; // [sp+218h] [bp+B8h]
  int v595; // [sp+21Ch] [bp+BCh]
  uint32_t v596[16]; // [sp+220h] [bp+C0h] BYREF
  uint32_t X[32]; // [sp+260h] [bp+100h] BYREF
  int v598; // [sp+2E0h] [bp+180h] BYREF

  V = (uint32_t *)((unsigned int)(scratchpad + 63) & 0xFFFFFFC0);
  state = 1779033703;
  v550 = -1150833019;
  v547 = input + 16;
  v3 = v556;
  v552 = -1521486534;
  v553 = 1359893119;
  v554 = -1694144372;
  v555 = 528734635;
  v556[0] = 1541459225;
  v551 = 1013904242;
  SHA256_Transform(&state, input, 1);
  v4 = v547[1];
  v5 = v547[2];
  v6 = v547[3];
  block = *v547;
  v569 = v4;
  v570 = v5;
  v571 = v6;
  v7 = &v567;
  v572 = 128;
  v573 = 0;
  v574 = 0;
  v575 = 0;
  memset(v576, 0, 28);
  v576[7] = -2147352576;
  SHA256_Transform(&state, &block, 1);
  v580 = -1521486534;
  v581 = 1359893119;
  v582 = -1694144372;
  v556[1] = state;
  v556[2] = v550;
  v556[3] = v551;
  v556[4] = v552;
  v577 = 1779033703;
  v578 = -1150833019;
  v8 = &v567;
  v583 = 528734635;
  v584 = 1541459225;
  v9 = v556;
  v579 = 1013904242;
  v556[5] = v553;
  v556[6] = v554;
  v556[7] = v555;
  v557 = v556[0];
  do
  {
    v10 = v9[1];
    ++v9;
    v8[1] = v10 ^ 0x36363636;
    ++v8;
  }
  while ( &v557 != v9 );
  memset(v576, 54, sizeof(v576));
  SHA256_Transform(&v577, &block, 0);
  SHA256_Transform(&v577, input, 1);
  v11 = *((_QWORD *)input + 9);
  v12 = input[16];
  v13 = &v586;
  v14 = input[17];
  v585[3] = bswap32(HIDWORD(v11));
  v585[0] = bswap32(v12);
  v585[1] = bswap32(v14);
  v585[2] = bswap32(v11);
  v15 = 0x80000000;
  for ( i = &innerpad_13357; ; ++i )
  {
    v13[1] = v15;
    if ( &v587 == (char *)++v13 )
      break;
    v17 = i[1];
    v15 = bswap32(v17);
  }
  v588 = 1779033703;
  v589 = -1150833019;
  v590 = 1013904242;
  v591 = -1521486534;
  v592 = 1359893119;
  v593 = -1694144372;
  v594 = 528734635;
  v595 = 1541459225;
  do
  {
    v18 = v3[1];
    ++v3;
    v7[1] = v18 ^ 0x5C5C5C5C;
    ++v7;
  }
  while ( v9 != v3 );
  memset(v576, 92, sizeof(v576));
  v19 = 0;
  v20 = X;
  SHA256_Transform(&v588, &block, 0);
  v596[8] = 0x80000000;
  memset(&v596[9], 0, 24);
  v596[15] = 768;
  do
  {
    ++v19;
    v558 = v577;
    v559 = v578;
    v560 = v579;
    v561 = v580;
    v586 = v19;
    v562 = v581;
    v563 = v582;
    v564 = v583;
    v565 = v584;
    SHA256_Transform(&v558, v585, 0);
    v596[0] = v558;
    v596[1] = v559;
    v596[2] = v560;
    v596[3] = v561;
    v596[4] = v562;
    v596[5] = v563;
    v596[6] = v564;
    v596[7] = v565;
    v566[0] = v588;
    v566[1] = v589;
    v566[2] = v590;
    v566[3] = v591;
    v566[4] = v592;
    v566[5] = v593;
    v566[6] = v594;
    v567 = v595;
    SHA256_Transform(v566, v596, 0);
    v21 = &v565;
    v22 = v20;
    do
    {
      v23 = v21[1];
      ++v21;
      *v22++ = bswap32(v23);
    }
    while ( v21 != (uint32_t *)&v567 );
    v20 += 8;
  }
  while ( v19 != 4 );
  v513 = X[0];
  dest = V;
  v363 = X[16];
  v518 = X[1];
  v486 = X[17];
  v522 = X[2];
  v489 = X[18];
  v417 = X[3];
  v494 = X[19];
  v525 = X[4];
  v497 = X[20];
  v423 = X[5];
  v369 = X[21];
  v428 = X[6];
  v375 = X[22];
  v433 = X[7];
  v382 = X[23];
  v439 = X[8];
  v389 = X[24];
  v444 = X[9];
  v503 = X[25];
  v451 = X[10];
  v505 = X[26];
  v457 = X[11];
  v396 = X[27];
  v464 = X[12];
  v402 = X[28];
  v469 = X[13];
  v407 = X[29];
  v476 = X[14];
  v510 = X[30];
  v480 = X[15];
  v412 = X[31];
  do
  {
    memcpy(dest, X, 0x80u);
    v24 = v513 ^ v363;
    v514 = v518 ^ v486;
    v25 = v522 ^ v489;
    v519 = v522 ^ v489;
    v418 = v417 ^ v494;
    v26 = v525 ^ v497;
    v528 = v24;
    v424 = v423 ^ v369;
    v429 = v428 ^ v375;
    v434 = v433 ^ v382;
    v440 = v439 ^ v389;
    v445 = v444 ^ v503;
    v452 = v451 ^ v505;
    v458 = v457 ^ v396;
    v27 = v434;
    v465 = v464 ^ v402;
    v327 = v458;
    v470 = v469 ^ v407;
    v28 = v470;
    v29 = v452;
    v477 = v476 ^ v510;
    v30 = v477;
    v308 = v424;
    v481 = v480 ^ v412;
    v31 = v481;
    v319 = v429;
    v350 = 4;
    v279 = v514;
    v32 = v445;
    v34 = v418;
    v33 = v440;
    v35 = v465;
    v267 = v24;
    do
    {
      v36 = v279;
      v37 = v26 ^ __ROR4__(v267 + v35, 25);
      v38 = v30 ^ __ROR4__(v319 + v29, 25);
      v290 = v34 ^ __ROR4__(v31 + v327, 25);
      v280 = v32 ^ __ROR4__(v279 + v308, 25);
      v39 = v308;
      v300 = v33 ^ __ROR4__(v37 + v267, 23);
      v40 = v25 ^ __ROR4__(v29 + v38, 23);
      v41 = v27 ^ __ROR4__(v31 + v290, 23);
      v42 = v308 + v280;
      v309 = v37;
      v43 = v28 ^ __ROR4__(v42, 23);
      v335 = v38;
      v44 = v35 ^ __ROR4__(v37 + v300, 19);
      v45 = v327 ^ __ROR4__(v290 + v41, 19);
      v46 = v36 ^ __ROR4__(v280 + v43, 19);
      v47 = v319 ^ __ROR4__(v38 + v40, 19);
      v268 = v267 ^ __ROR4__(v300 + v44, 14);
      v48 = v29 ^ __ROR4__(v40 + v47, 14);
      v49 = v280;
      v50 = v39 ^ __ROR4__(v43 + v46, 14);
      v343 = v31 ^ __ROR4__(v41 + v45, 14);
      v35 = v44 ^ __ROR4__(v335 + v343, 25);
      v327 = v45 ^ __ROR4__(v280 + v48, 25);
      v279 = v46 ^ __ROR4__(v290 + v268, 25);
      v319 = v47 ^ __ROR4__(v309 + v50, 25);
      v27 = v41 ^ __ROR4__(v50 + v319, 23);
      v25 = v40 ^ __ROR4__(v279 + v268, 23);
      v28 = v43 ^ __ROR4__(v343 + v35, 23);
      v33 = v300 ^ __ROR4__(v48 + v327, 23);
      v26 = v309 ^ __ROR4__(v319 + v27, 19);
      v32 = v49 ^ __ROR4__(v327 + v33, 19);
      v34 = v290 ^ __ROR4__(v279 + v25, 19);
      v30 = v335 ^ __ROR4__(v35 + v28, 19);
      v51 = v268 ^ __ROR4__(v25 + v34, 14);
      v29 = v48 ^ __ROR4__(v33 + v32, 14);
      v267 = v51;
      v308 = v50 ^ __ROR4__(v27 + v26, 14);
      v31 = v343 ^ __ROR4__(v28 + v30, 14);
      --v350;
    }
    while ( v350 );
    v419 = v418 + v34;
    v544 = v528 + v51;
    v425 = v424 + v308;
    v430 = v429 + v319;
    v435 = v434 + v27;
    v441 = v440 + v33;
    v446 = v445 + v32;
    v453 = v452 + v29;
    v459 = v458 + v327;
    v466 = v465 + v35;
    v471 = v470 + v28;
    v52 = v528 + v51;
    v515 = v514 + v279;
    v523 = (v525 ^ v497) + v26;
    v478 = v477 + v30;
    v520 = v519 + v25;
    v482 = v481 + v31;
    v364 = v363 ^ (v528 + v51);
    v487 = v486 ^ v515;
    v490 = v489 ^ v520;
    v495 = v494 ^ v419;
    v498 = v497 ^ v523;
    v376 = v375 ^ v430;
    v370 = v369 ^ v425;
    v383 = v382 ^ v435;
    v390 = v389 ^ v441;
    v526 = v503 ^ v446;
    v53 = v503 ^ v446;
    v54 = v490;
    v529 = v396 ^ v459;
    v504 = v505 ^ v453;
    v55 = v396 ^ v459;
    v533 = v402 ^ v466;
    v536 = v407 ^ v471;
    v344 = v407 ^ v471;
    v56 = v53;
    v320 = v376;
    v57 = v510 ^ v478;
    v539 = v510 ^ v478;
    v541 = v412 ^ v482;
    v291 = v370;
    v58 = v412 ^ v482;
    v328 = v487;
    v59 = v383;
    v60 = v390;
    v61 = v495;
    v62 = v505 ^ v453;
    v63 = v498;
    v351 = 4;
    X[0] = v52;
    X[13] = v471;
    v64 = v402 ^ v466;
    X[1] = v515;
    v269 = v364;
    X[2] = v520;
    X[3] = v419;
    X[4] = v523;
    X[5] = v425;
    X[6] = v430;
    X[7] = v435;
    X[8] = v441;
    X[9] = v446;
    X[10] = v453;
    X[11] = v459;
    X[12] = v466;
    X[14] = v478;
    X[15] = v482;
    do
    {
      v65 = v291;
      v281 = v63 ^ __ROR4__(v269 + v64, 25);
      v66 = v56 ^ __ROR4__(v291 + v328, 25);
      v292 = v57 ^ __ROR4__(v320 + v62, 25);
      v301 = v61 ^ __ROR4__(v58 + v55, 25);
      v67 = v59 ^ __ROR4__(v301 + v58, 23);
      v336 = v66;
      v310 = v60 ^ __ROR4__(v269 + v281, 23);
      v68 = v54 ^ __ROR4__(v292 + v62, 23);
      v69 = v65;
      v70 = v344 ^ __ROR4__(v65 + v66, 23);
      v71 = v64 ^ __ROR4__(v281 + v310, 19);
      v72 = v55 ^ __ROR4__(v301 + v67, 19);
      v73 = v320 ^ __ROR4__(v292 + v68, 19);
      v74 = v58 ^ __ROR4__(v67 + v72, 14);
      v75 = v328 ^ __ROR4__(v66 + v70, 19);
      v270 = v269 ^ __ROR4__(v310 + v71, 14);
      v76 = v62 ^ __ROR4__(v68 + v73, 14);
      v77 = v69 ^ __ROR4__(v70 + v75, 14);
      v64 = v71 ^ __ROR4__(v292 + v74, 25);
      v55 = v72 ^ __ROR4__(v336 + v76, 25);
      v328 = v75 ^ __ROR4__(v301 + v270, 25);
      v320 = v73 ^ __ROR4__(v281 + v77, 25);
      v59 = v67 ^ __ROR4__(v77 + v320, 23);
      v54 = v68 ^ __ROR4__(v328 + v270, 23);
      v344 = v70 ^ __ROR4__(v74 + v64, 23);
      v60 = v310 ^ __ROR4__(v76 + v55, 23);
      v63 = v281 ^ __ROR4__(v320 + v59, 19);
      v61 = v301 ^ __ROR4__(v328 + v54, 19);
      v56 = v336 ^ __ROR4__(v55 + v60, 19);
      v57 = v292 ^ __ROR4__(v64 + v344, 19);
      v269 = v270 ^ __ROR4__(v54 + v61, 14);
      v291 = v77 ^ __ROR4__(v59 + v63, 14);
      v58 = v74 ^ __ROR4__(v344 + v57, 14);
      v62 = v76 ^ __ROR4__(v60 + v56, 14);
      --v351;
    }
    while ( v351 );
    v542 = v364 + v269;
    v543 = v487 + v328;
    v506 = v490 + v54;
    v511 = v495 + v61;
    v365 = v498 + v63;
    v371 = v370 + v291;
    v377 = v376 + v320;
    v384 = v383 + v59;
    v397 = v526 + v56;
    v391 = v390 + v60;
    v403 = v504 + v62;
    v408 = v529 + v55;
    v413 = v533 + v64;
    X[20] = v498 + v63;
    v488 = v536 + v344;
    X[21] = v371;
    v491 = v539 + v57;
    X[22] = v377;
    v496 = v541 + v58;
    X[23] = v384;
    X[16] = v542;
    X[17] = v543;
    X[25] = v526 + v56;
    X[18] = v506;
    X[19] = v511;
    X[26] = v504 + v62;
    X[24] = v391;
    X[27] = v529 + v55;
    X[28] = v533 + v64;
    X[29] = v536 + v344;
    X[30] = v539 + v57;
    X[31] = v541 + v58;
    memcpy(dest + 32, X, 0x80u);
    v499 = v544 ^ v542;
    v527 = v515 ^ v543;
    v420 = v419 ^ v511;
    v78 = v520 ^ v506;
    v521 = v520 ^ v506;
    v426 = v425 ^ v371;
    v431 = v430 ^ v377;
    v436 = v435 ^ v384;
    v79 = v436;
    v442 = v441 ^ v391;
    v447 = v446 ^ v397;
    v454 = v453 ^ (v504 + v62);
    v460 = v459 ^ v408;
    v321 = v431;
    v467 = v466 ^ (v533 + v64);
    v282 = v515 ^ v543;
    v80 = v442;
    v472 = v471 ^ (v536 + v344);
    v81 = v454;
    v82 = v447;
    v83 = v478 ^ (v539 + v57);
    v479 = v83;
    v84 = v472;
    v85 = v420;
    v86 = v523 ^ v365;
    v87 = v482 ^ v496;
    v311 = v426;
    v329 = v460;
    v88 = v467;
    v483 = v482 ^ v496;
    v352 = 4;
    v271 = v544 ^ v542;
    do
    {
      v89 = v282;
      v90 = v86 ^ __ROR4__(v88 + v271, 25);
      v91 = v83 ^ __ROR4__(v321 + v81, 25);
      v293 = v85 ^ __ROR4__(v87 + v329, 25);
      v283 = v82 ^ __ROR4__(v311 + v282, 25);
      v92 = v311;
      v302 = v80 ^ __ROR4__(v271 + v90, 23);
      v93 = v78 ^ __ROR4__(v91 + v81, 23);
      v94 = v79 ^ __ROR4__(v87 + v293, 23);
      v95 = v311 + v283;
      v312 = v90;
      v96 = v84 ^ __ROR4__(v95, 23);
      v337 = v91;
      v97 = v88 ^ __ROR4__(v90 + v302, 19);
      v98 = v329 ^ __ROR4__(v293 + v94, 19);
      v99 = v89 ^ __ROR4__(v283 + v96, 19);
      v100 = v321 ^ __ROR4__(v91 + v93, 19);
      v272 = v271 ^ __ROR4__(v302 + v97, 14);
      v101 = v81 ^ __ROR4__(v93 + v100, 14);
      v102 = v283;
      v103 = v92 ^ __ROR4__(v96 + v99, 14);
      v345 = v87 ^ __ROR4__(v94 + v98, 14);
      v88 = v97 ^ __ROR4__(v337 + v345, 25);
      v329 = v98 ^ __ROR4__(v283 + v101, 25);
      v282 = v99 ^ __ROR4__(v293 + v272, 25);
      v321 = v100 ^ __ROR4__(v312 + v103, 25);
      v79 = v94 ^ __ROR4__(v103 + v321, 23);
      v78 = v93 ^ __ROR4__(v282 + v272, 23);
      v84 = v96 ^ __ROR4__(v345 + v88, 23);
      v80 = v302 ^ __ROR4__(v101 + v329, 23);
      v86 = v312 ^ __ROR4__(v321 + v79, 19);
      v82 = v102 ^ __ROR4__(v329 + v80, 19);
      v85 = v293 ^ __ROR4__(v282 + v78, 19);
      v83 = v337 ^ __ROR4__(v88 + v84, 19);
      v104 = v272 ^ __ROR4__(v78 + v85, 14);
      v81 = v101 ^ __ROR4__(v80 + v82, 14);
      v271 = v104;
      v311 = v103 ^ __ROR4__(v79 + v86, 14);
      v87 = v345 ^ __ROR4__(v84 + v83, 14);
      --v352;
    }
    while ( v352 );
    v513 = v499 + v104;
    v105 = v521 + v78;
    v417 = v420 + v85;
    v423 = v426 + v311;
    v428 = v431 + v321;
    v433 = v436 + v79;
    v439 = v442 + v80;
    v444 = v447 + v82;
    v451 = v454 + v81;
    v457 = v460 + v329;
    v464 = v467 + v88;
    v469 = v472 + v84;
    v476 = v479 + v83;
    v518 = v527 + v282;
    v525 = (v523 ^ v365) + v86;
    v522 = v105;
    v500 = v542 ^ (v499 + v104);
    v507 = v506 ^ v105;
    v512 = v511 ^ v417;
    v530 = v365 ^ v525;
    v372 = v371 ^ v423;
    v480 = v483 + v87;
    v378 = v377 ^ v428;
    v385 = v384 ^ v433;
    v392 = v391 ^ v439;
    v534 = v397 ^ v444;
    v106 = v397 ^ v444;
    v107 = v403;
    v108 = v507;
    v404 = v408 ^ v457;
    v398 = v107 ^ v451;
    v109 = v408 ^ v457;
    v409 = v413 ^ v464;
    v284 = v413 ^ v464;
    v414 = v488 ^ v469;
    v346 = v488 ^ v469;
    v110 = v106;
    v330 = v378;
    v111 = v491 ^ v476;
    v537 = v491 ^ v476;
    v540 = v496 ^ v480;
    v294 = v372;
    v112 = v496 ^ v480;
    v322 = v543 ^ v518;
    v113 = v385;
    v114 = v392;
    v115 = v512;
    v116 = v398;
    v117 = v365 ^ v525;
    v353 = 4;
    X[0] = v513;
    X[13] = v469;
    v118 = v284;
    X[1] = v518;
    v273 = v542 ^ v513;
    X[2] = v105;
    X[3] = v417;
    X[4] = v525;
    X[5] = v423;
    X[6] = v428;
    X[7] = v433;
    X[8] = v439;
    X[9] = v444;
    X[10] = v451;
    X[11] = v457;
    X[12] = v464;
    X[14] = v476;
    X[15] = v480;
    do
    {
      v119 = v294;
      v285 = v117 ^ __ROR4__(v118 + v273, 25);
      v120 = v110 ^ __ROR4__(v294 + v322, 25);
      v295 = v111 ^ __ROR4__(v116 + v330, 25);
      v303 = v115 ^ __ROR4__(v112 + v109, 25);
      v121 = v113 ^ __ROR4__(v112 + v303, 23);
      v338 = v120;
      v313 = v114 ^ __ROR4__(v285 + v273, 23);
      v122 = v108 ^ __ROR4__(v116 + v295, 23);
      v123 = v119;
      v124 = v346 ^ __ROR4__(v119 + v120, 23);
      v125 = v118 ^ __ROR4__(v285 + v313, 19);
      v126 = v109 ^ __ROR4__(v303 + v121, 19);
      v127 = v330 ^ __ROR4__(v295 + v122, 19);
      v128 = v112 ^ __ROR4__(v121 + v126, 14);
      v129 = v322 ^ __ROR4__(v120 + v124, 19);
      v274 = v273 ^ __ROR4__(v313 + v125, 14);
      v130 = v116 ^ __ROR4__(v122 + v127, 14);
      v131 = v123 ^ __ROR4__(v124 + v129, 14);
      v118 = v125 ^ __ROR4__(v295 + v128, 25);
      v109 = v126 ^ __ROR4__(v338 + v130, 25);
      v322 = v129 ^ __ROR4__(v303 + v274, 25);
      v330 = v127 ^ __ROR4__(v285 + v131, 25);
      v113 = v121 ^ __ROR4__(v131 + v330, 23);
      v108 = v122 ^ __ROR4__(v322 + v274, 23);
      v346 = v124 ^ __ROR4__(v128 + v118, 23);
      v114 = v313 ^ __ROR4__(v130 + v109, 23);
      v117 = v285 ^ __ROR4__(v330 + v113, 19);
      v115 = v303 ^ __ROR4__(v322 + v108, 19);
      v110 = v338 ^ __ROR4__(v109 + v114, 19);
      v111 = v295 ^ __ROR4__(v118 + v346, 19);
      v273 = v274 ^ __ROR4__(v108 + v115, 14);
      v294 = v131 ^ __ROR4__(v113 + v117, 14);
      v112 = v128 ^ __ROR4__(v346 + v111, 14);
      v116 = v130 ^ __ROR4__(v114 + v110, 14);
      --v353;
    }
    while ( v353 );
    v363 = v500 + v273;
    v486 = (v543 ^ v518) + v322;
    v489 = v507 + v108;
    v494 = v512 + v115;
    v497 = v530 + v117;
    v369 = v372 + v294;
    v375 = v378 + v330;
    v382 = v385 + v113;
    v389 = v392 + v114;
    v503 = v534 + v110;
    v505 = v398 + v116;
    v396 = v404 + v109;
    v402 = v409 + v118;
    X[18] = v489;
    X[19] = v512 + v115;
    X[20] = v530 + v117;
    X[23] = v382;
    X[24] = v389;
    X[25] = v534 + v110;
    v407 = v414 + v346;
    X[26] = v505;
    v510 = v537 + v111;
    v412 = v540 + v112;
    dest += 64;
    X[16] = v363;
    X[17] = v486;
    X[21] = v369;
    X[22] = v375;
    X[27] = v396;
    X[28] = v402;
    X[29] = v407;
    X[30] = v537 + v111;
    X[31] = v540 + v112;
  }
  while ( dest != V + 0x8000 );
  v132 = v363;
  v432 = (char *)V - (char *)X;
  v427 = 512;
  do
  {
    v133 = X;
    v134 = v432 + ((v132 & 0x3FF) << 7);
    do
    {
      v135 = v133[1];
      v136 = *(uint32_t *)((char *)v133 + v134 + 4);
      v137 = *(uint32_t *)((char *)v133 + v134);
      v133 += 2;
      v138 = *(v133 - 2);
      *(v133 - 1) = v135 ^ v136;
      *(v133 - 2) = v138 ^ v137;
    }
    while ( &v598 != (int *)v133 );
    desta = 4;
    v373 = X[16] ^ X[0];
    v296 = X[16] ^ X[0];
    v386 = X[17] ^ X[1];
    v139 = X[18] ^ X[2];
    v286 = X[17] ^ X[1];
    v399 = X[18] ^ X[2];
    v140 = X[3] ^ X[19];
    v141 = X[20] ^ X[4];
    v304 = X[5] ^ X[21];
    v461 = X[6] ^ X[22];
    v331 = X[6] ^ X[22];
    v142 = X[7] ^ X[23];
    v473 = X[7] ^ X[23];
    v484 = X[8] ^ X[24];
    v143 = X[8] ^ X[24];
    v144 = X[9] ^ X[25];
    v492 = X[9] ^ X[25];
    v501 = X[10] ^ X[26];
    v314 = X[10] ^ X[26];
    v508 = X[11] ^ X[27];
    v145 = X[12] ^ X[28];
    v275 = X[11] ^ X[27];
    v516 = X[12] ^ X[28];
    v524 = X[13] ^ X[29];
    v146 = X[13] ^ X[29];
    v147 = X[30] ^ X[14];
    v531 = X[30] ^ X[14];
    v538 = v133;
    v148 = X[15] ^ X[31];
    v535 = X[15] ^ X[31];
    do
    {
      v339 = v141 ^ __ROR4__(v296 + v145, 25);
      v354 = v147 ^ __ROR4__(v331 + v314, 25);
      v149 = v140 ^ __ROR4__(v275 + v148, 25);
      v150 = v144 ^ __ROR4__(v286 + v304, 25);
      v151 = v142 ^ __ROR4__(v149 + v148, 23);
      v152 = v143 ^ __ROR4__(v339 + v296, 23);
      v153 = v139 ^ __ROR4__(v354 + v314, 23);
      v154 = v146 ^ __ROR4__(v150 + v304, 23);
      v155 = v145 ^ __ROR4__(v339 + v152, 19);
      v156 = v150 + v154;
      v347 = v150;
      v157 = v296 ^ __ROR4__(v152 + v155, 14);
      v158 = v275 ^ __ROR4__(v149 + v151, 19);
      v159 = v331 ^ __ROR4__(v354 + v153, 19);
      v160 = v286 ^ __ROR4__(v156, 19);
      v323 = v148 ^ __ROR4__(v151 + v158, 14);
      v161 = v314 ^ __ROR4__(v153 + v159, 14);
      v145 = v155 ^ __ROR4__(v354 + v323, 25);
      v162 = v304 ^ __ROR4__(v154 + v160, 14);
      v275 = v158 ^ __ROR4__(v347 + v161, 25);
      v331 = v159 ^ __ROR4__(v339 + v162, 25);
      v142 = v151 ^ __ROR4__(v162 + v331, 23);
      v286 = v160 ^ __ROR4__(v149 + v157, 25);
      v139 = v153 ^ __ROR4__(v157 + v286, 23);
      v146 = v154 ^ __ROR4__(v323 + v145, 23);
      v143 = v152 ^ __ROR4__(v161 + v275, 23);
      v140 = v149 ^ __ROR4__(v286 + v139, 19);
      v141 = v339 ^ __ROR4__(v331 + v142, 19);
      v144 = v347 ^ __ROR4__(v275 + v143, 19);
      v296 = v157 ^ __ROR4__(v139 + v140, 14);
      v147 = v354 ^ __ROR4__(v145 + v146, 19);
      v304 = v162 ^ __ROR4__(v142 + v141, 14);
      v314 = v161 ^ __ROR4__(v143 + v144, 14);
      v148 = v323 ^ __ROR4__(v146 + v147, 14);
      --desta;
    }
    while ( desta );
    X[0] = v373 + v296;
    X[1] = v386 + v286;
    X[2] = v399 + v139;
    v163 = (X[3] ^ X[19]) + v140;
    X[4] = (X[20] ^ X[4]) + v141;
    X[5] = (X[5] ^ X[21]) + v304;
    X[6] = v461 + v331;
    X[7] = v473 + v142;
    X[8] = v484 + v143;
    X[9] = v492 + v144;
    X[10] = v501 + v314;
    X[11] = v508 + v275;
    X[12] = v516 + v145;
    X[13] = v524 + v146;
    X[14] = v531 + v147;
    X[15] = v535 + v148;
    v421 = X[16] ^ (v373 + v296);
    v437 = X[17] ^ (v386 + v286);
    destb = (void *)(X[18] ^ (v399 + v139));
    v366 = X[19] ^ v163;
    v448 = X[22] ^ (v461 + v331);
    v379 = X[23] ^ (v473 + v142);
    v387 = X[24] ^ (v484 + v143);
    v393 = X[25] ^ (v492 + v144);
    v340 = v448;
    v164 = v379;
    v455 = X[26] ^ (v501 + v314);
    v165 = (int)destb;
    v400 = X[27] ^ (v508 + v275);
    v166 = v387;
    v167 = X[19] ^ v163;
    v405 = X[28] ^ (v516 + v145);
    v315 = v455;
    v462 = X[29] ^ (v524 + v146);
    v410 = X[30] ^ (v531 + v147);
    v287 = v400;
    v415 = X[31] ^ (v535 + v148);
    v168 = v393;
    v355 = 4;
    v169 = v415;
    X[3] = v163;
    v297 = v437;
    v305 = X[21] ^ X[5];
    v170 = X[20] ^ X[4];
    v171 = v410;
    v172 = v405;
    v173 = v462;
    v324 = v421;
    do
    {
      v276 = v170 ^ __ROR4__(v172 + v324, 25);
      v174 = v171 ^ __ROR4__(v340 + v315, 25);
      v175 = v167 ^ __ROR4__(v287 + v169, 25);
      v332 = v168 ^ __ROR4__(v297 + v305, 25);
      v176 = v164 ^ __ROR4__(v169 + v175, 23);
      v177 = v166 ^ __ROR4__(v324 + v276, 23);
      v178 = v165 ^ __ROR4__(v315 + v174, 23);
      v179 = v172 ^ __ROR4__(v276 + v177, 19);
      v180 = v174;
      v181 = v173 ^ __ROR4__(v305 + v332, 23);
      v182 = v287 ^ __ROR4__(v175 + v176, 19);
      v183 = v169 ^ __ROR4__(v176 + v182, 14);
      v184 = v315;
      v185 = v340 ^ __ROR4__(v174 + v178, 19);
      v316 = v180;
      v172 = v179 ^ __ROR4__(v180 + v183, 25);
      v186 = v297 ^ __ROR4__(v332 + v181, 19);
      v187 = v324 ^ __ROR4__(v177 + v179, 14);
      v188 = v184 ^ __ROR4__(v178 + v185, 14);
      v189 = v305 ^ __ROR4__(v181 + v186, 14);
      v287 = v182 ^ __ROR4__(v332 + v188, 25);
      v340 = v185 ^ __ROR4__(v276 + v189, 25);
      v164 = v176 ^ __ROR4__(v189 + v340, 23);
      v297 = v186 ^ __ROR4__(v175 + v187, 25);
      v165 = v178 ^ __ROR4__(v187 + v297, 23);
      v166 = v177 ^ __ROR4__(v188 + v287, 23);
      v173 = v181 ^ __ROR4__(v183 + v172, 23);
      v167 = v175 ^ __ROR4__(v297 + v165, 19);
      v170 = v276 ^ __ROR4__(v340 + v164, 19);
      v190 = v187 ^ __ROR4__(v165 + v167, 14);
      v168 = v332 ^ __ROR4__(v287 + v166, 19);
      v324 = v190;
      v171 = v316 ^ __ROR4__(v172 + v173, 19);
      v305 = v189 ^ __ROR4__(v164 + v170, 14);
      v315 = v188 ^ __ROR4__(v166 + v168, 14);
      v169 = v183 ^ __ROR4__(v173 + v171, 14);
      --v355;
    }
    while ( v355 );
    X[17] = v437 + v297;
    X[16] = v421 + v190;
    v191 = X;
    v192 = v432 + (((v421 + v190) & 0x3FF) << 7);
    X[21] = (X[21] ^ X[5]) + v305;
    X[25] = v393 + v168;
    X[26] = v455 + v315;
    X[28] = v405 + v172;
    X[18] = (uint32_t)destb + v165;
    X[19] = v366 + v167;
    X[20] = (X[20] ^ X[4]) + v170;
    X[22] = v448 + v340;
    X[23] = v379 + v164;
    X[24] = v387 + v166;
    X[27] = v400 + v287;
    X[29] = v462 + v173;
    X[30] = v410 + v171;
    X[31] = v415 + v169;
    do
    {
      v193 = v191[1];
      v194 = *(uint32_t *)((char *)v191 + v192 + 4);
      v195 = *(uint32_t *)((char *)v191 + v192);
      v191 += 2;
      v196 = *(v191 - 2);
      *(v191 - 1) = v193 ^ v194;
      *(v191 - 2) = v196 ^ v195;
    }
    while ( v191 != v538 );
    v367 = 4;
    v380 = X[16] ^ X[0];
    v288 = X[16] ^ X[0];
    v394 = X[17] ^ X[1];
    v277 = X[17] ^ X[1];
    v197 = X[2] ^ X[18];
    v406 = X[2] ^ X[18];
    v198 = X[3] ^ X[19];
    v199 = X[4] ^ X[20];
    v449 = X[5] ^ X[21];
    v298 = X[5] ^ X[21];
    v463 = X[6] ^ X[22];
    v200 = X[7] ^ X[23];
    v317 = X[6] ^ X[22];
    v474 = X[7] ^ X[23];
    v201 = X[8] ^ X[24];
    v485 = X[8] ^ X[24];
    v202 = X[25] ^ X[9];
    v493 = X[25] ^ X[9];
    v502 = X[10] ^ X[26];
    v203 = X[11] ^ X[27];
    v306 = X[10] ^ X[26];
    v509 = X[11] ^ X[27];
    v517 = X[12] ^ X[28];
    v204 = X[13] ^ X[29];
    v205 = X[14] ^ X[30];
    v532 = X[14] ^ X[30];
    v206 = X[15] ^ X[31];
    v325 = X[12] ^ X[28];
    do
    {
      v207 = v198 ^ __ROR4__(v203 + v206, 25);
      v333 = v199 ^ __ROR4__(v288 + v325, 25);
      v208 = v200 ^ __ROR4__(v207 + v206, 23);
      v209 = v205 ^ __ROR4__(v317 + v306, 25);
      v210 = v201 ^ __ROR4__(v333 + v288, 23);
      v211 = v203 ^ __ROR4__(v207 + v208, 19);
      v212 = v197 ^ __ROR4__(v209 + v306, 23);
      v213 = v202 ^ __ROR4__(v277 + v298, 25);
      v356 = v204 ^ __ROR4__(v213 + v298, 23);
      v214 = v213 + v356;
      v215 = v325 ^ __ROR4__(v333 + v210, 19);
      v341 = v213;
      v348 = v209;
      v216 = v317 ^ __ROR4__(v209 + v212, 19);
      v217 = v288 ^ __ROR4__(v210 + v215, 14);
      v218 = v277 ^ __ROR4__(v214, 19);
      destc = v206 ^ __ROR4__(v208 + v211, 14);
      v219 = v306 ^ __ROR4__(v212 + v216, 14);
      v325 = v215 ^ __ROR4__(v209 + destc, 25);
      v220 = v298 ^ __ROR4__(v356 + v218, 14);
      v203 = v211 ^ __ROR4__(v341 + v219, 25);
      v201 = v210 ^ __ROR4__(v219 + v203, 23);
      v317 = v216 ^ __ROR4__(v333 + v220, 25);
      v200 = v208 ^ __ROR4__(v220 + v317, 23);
      v277 = v218 ^ __ROR4__(v207 + v217, 25);
      v197 = v212 ^ __ROR4__(v217 + v277, 23);
      v199 = v333 ^ __ROR4__(v317 + v200, 19);
      v204 = v356 ^ __ROR4__(destc + v325, 23);
      v198 = v207 ^ __ROR4__(v277 + v197, 19);
      v202 = v341 ^ __ROR4__(v203 + v201, 19);
      v205 = v348 ^ __ROR4__(v325 + v204, 19);
      v288 = v217 ^ __ROR4__(v197 + v198, 14);
      v298 = v220 ^ __ROR4__(v200 + v199, 14);
      v306 = v219 ^ __ROR4__(v201 + v202, 14);
      v206 = destc ^ __ROR4__(v204 + v205, 14);
      --v367;
    }
    while ( v367 );
    X[0] = v380 + v288;
    X[1] = v394 + v277;
    X[2] = v406 + v197;
    v221 = (X[3] ^ X[19]) + v198;
    v222 = (X[4] ^ X[20]) + v199;
    X[5] = v449 + v298;
    X[6] = v463 + v317;
    X[7] = v474 + v200;
    X[8] = v485 + v201;
    X[9] = v493 + v202;
    X[10] = v502 + v306;
    X[11] = v509 + v203;
    X[12] = v517 + v325;
    X[13] = (X[13] ^ X[29]) + v204;
    X[14] = v532 + v205;
    v223 = v380 + v288;
    v224 = (X[15] ^ X[31]) + v206;
    v381 = X[18] ^ (v406 + v197);
    v374 = X[16] ^ v223;
    v388 = X[19] ^ v221;
    v438 = X[17] ^ (v394 + v277);
    v443 = X[21] ^ (v449 + v298);
    v395 = X[20] ^ v222;
    v401 = X[23] ^ (v474 + v200);
    v450 = X[22] ^ (v463 + v317);
    v456 = X[24] ^ (v485 + v201);
    v225 = v456;
    v226 = v502 + v306;
    v307 = v443;
    v411 = X[26] ^ v226;
    v334 = v450;
    v416 = X[27] ^ (v509 + v203);
    v289 = v438;
    v422 = X[28] ^ (v517 + v325);
    v278 = v416;
    v299 = v422;
    v468 = X[30] ^ (v532 + v205);
    v227 = X[16] ^ v223;
    v228 = v401;
    v229 = v381;
    v475 = X[31] ^ v224;
    v230 = X[19] ^ v221;
    v231 = X[26] ^ v226;
    v232 = X[25] ^ (v493 + v202);
    v233 = X[20] ^ v222;
    v368 = 4;
    X[15] = v224;
    v235 = X[30] ^ X[14];
    v234 = X[29] ^ X[13];
    X[3] = v221;
    X[4] = v222;
    v236 = v227;
    v237 = v475;
    do
    {
      v238 = v235 ^ __ROR4__(v334 + v231, 25);
      v239 = v230 ^ __ROR4__(v278 + v237, 25);
      v342 = v233 ^ __ROR4__(v236 + v299, 25);
      v240 = v228 ^ __ROR4__(v239 + v237, 23);
      v349 = v232 ^ __ROR4__(v289 + v307, 25);
      v241 = v229 ^ __ROR4__(v238 + v231, 23);
      v357 = v238;
      v326 = v234 ^ __ROR4__(v349 + v307, 23);
      v318 = v225 ^ __ROR4__(v342 + v236, 23);
      v242 = v299 ^ __ROR4__(v318 + v342, 19);
      v243 = v334 ^ __ROR4__(v238 + v241, 19);
      v244 = v278 ^ __ROR4__(v239 + v240, 19);
      v245 = v289 ^ __ROR4__(v349 + v326, 19);
      v246 = v231 ^ __ROR4__(v241 + v243, 14);
      v247 = v236 ^ __ROR4__(v318 + v242, 14);
      destd = v237 ^ __ROR4__(v240 + v244, 14);
      v248 = v307 ^ __ROR4__(v326 + v245, 14);
      v278 = v244 ^ __ROR4__(v349 + v246, 25);
      v299 = v242 ^ __ROR4__(v357 + destd, 25);
      v334 = v243 ^ __ROR4__(v342 + v248, 25);
      v228 = v240 ^ __ROR4__(v248 + v334, 23);
      v289 = v245 ^ __ROR4__(v239 + v247, 25);
      v229 = v241 ^ __ROR4__(v247 + v289, 23);
      v225 = v318 ^ __ROR4__(v246 + v278, 23);
      v230 = v239 ^ __ROR4__(v289 + v229, 19);
      v234 = v326 ^ __ROR4__(destd + v299, 23);
      v236 = v247 ^ __ROR4__(v229 + v230, 14);
      v233 = v342 ^ __ROR4__(v334 + v228, 19);
      v232 = v349 ^ __ROR4__(v278 + v225, 19);
      v231 = v246 ^ __ROR4__(v225 + v232, 14);
      v235 = v357 ^ __ROR4__(v299 + v234, 19);
      v307 = v248 ^ __ROR4__(v228 + v233, 14);
      v237 = destd ^ __ROR4__(v234 + v235, 14);
      --v368;
    }
    while ( v368 );
    v132 = v374 + v236;
    X[16] = v374 + v236;
    X[17] = v438 + v289;
    X[18] = v381 + v229;
    X[19] = v388 + v230;
    X[20] = v395 + v233;
    X[21] = v443 + v307;
    X[28] = v422 + v299;
    X[22] = v450 + v334;
    X[23] = v401 + v228;
    X[24] = v456 + v225;
    X[25] = (X[25] ^ (v493 + v202)) + v232;
    X[26] = v411 + v231;
    X[27] = v416 + v278;
    X[29] = (X[29] ^ X[13]) + v234;
    X[30] = v468 + v235;
    v249 = v427 == 1;
    X[31] = v475 + v237;
    --v427;
  }
  while ( !v249 );
  v572 = 1359893119;
  v571 = -1521486534;
  v250 = &v587;
  v251 = &v576[7];
  v573 = -1694144372;
  v574 = 528734635;
  v575 = 1541459225;
  v252 = &v576[7];
  block = 1779033703;
  v569 = -1150833019;
  v570 = 1013904242;
  SHA256_Transform(&block, input, 1);
  v253 = v547[1];
  v254 = v547[2];
  v255 = v547[3];
  v588 = *v547;
  v589 = v253;
  v590 = v254;
  v591 = v255;
  v592 = 128;
  v593 = 0;
  v594 = 0;
  v595 = 0;
  memset(v596, 0, 28);
  v596[7] = -2147352576;
  SHA256_Transform(&block, &v588, 1);
  v256 = &v587;
  v257 = block;
  v258 = v569;
  v259 = v570;
  v260 = v571;
  *ostate = 1779033703;
  ostate[1] = -1150833019;
  v577 = v257;
  v578 = v258;
  v579 = v259;
  v580 = v260;
  v261 = v572;
  v262 = v573;
  v263 = v574;
  v264 = v575;
  ostate[2] = 1013904242;
  ostate[3] = -1521486534;
  ostate[4] = 1359893119;
  ostate[5] = -1694144372;
  ostate[6] = 528734635;
  ostate[7] = 1541459225;
  v581 = v261;
  v582 = v262;
  v583 = v263;
  v584 = v264;
  do
  {
    v265 = v252[1];
    ++v252;
    *((_DWORD *)v256 + 1) = v265 ^ 0x5C5C5C5C;
    v256 += 4;
  }
  while ( &v584 != v252 );
  memset(v596, 92, 32);
  SHA256_Transform(ostate, &v588, 0);
  block = 1779033703;
  v569 = -1150833019;
  v570 = 1013904242;
  v571 = -1521486534;
  v572 = 1359893119;
  v573 = -1694144372;
  v574 = 528734635;
  v575 = 1541459225;
  do
  {
    v266 = v251[1];
    ++v251;
    *((_DWORD *)v250 + 1) = v266 ^ 0x36363636;
    v250 += 4;
  }
  while ( v251 != v252 );
  memset(v596, 54, 32);
  SHA256_Transform(&block, &v588, 0);
  SHA256_Transform(&block, X, 1);
  SHA256_Transform(&block, &X[16], 1);
  SHA256_Transform(&block, &ihash_finalblk_13384, 0);
  v588 = block;
  v589 = v569;
  v590 = v570;
  v591 = v571;
  v592 = v572;
  v593 = v573;
  v594 = v574;
  v595 = v575;
  v596[0] = 0x80000000;
  memset(&v596[1], 0, 24);
  v596[7] = 768;
  SHA256_Transform(ostate, &v588, 0);
}
