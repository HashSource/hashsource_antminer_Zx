int __fastcall blake2b_compress(blake2b_state *S, const uint8_t *block)
{
  uint64_t *v2; // r3
  uint64_t *v3; // r2
  int v4; // r4
  blake2b_state *v5; // r1
  uint64_t v6; // t1
  uint64_t v7; // kr08_8
  int v8; // r10
  int v9; // r8
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r8
  uint64_t v13; // kr268_8
  unsigned int v14; // r5
  unsigned int v15; // r2
  int v16; // r3
  int v17; // r1
  __int64 v18; // r10
  unsigned int v19; // r5
  unsigned int v20; // r3
  int v21; // lr
  unsigned int v22; // r3
  unsigned int v23; // r1
  int v24; // r2
  unsigned int v25; // r9
  unsigned int v26; // r3
  unsigned int v27; // lr
  uint64_t v28; // kr2A0_8
  int v29; // r2
  int v30; // r3
  int v31; // r4
  int v32; // r5
  unsigned int v33; // r6
  unsigned int v34; // r12
  unsigned int v35; // r2
  unsigned int v36; // r4
  int v37; // r0
  unsigned int v38; // r7
  int v39; // lr
  __int64 v40; // r2
  __int64 v41; // r4
  int v42; // r7
  int v43; // r12
  unsigned int v44; // lr
  int v45; // r4
  int v46; // r0
  int v47; // r8
  unsigned int v48; // kr34_4
  unsigned int v49; // r1
  unsigned int v50; // r7
  signed __int64 v51; // r8
  unsigned int v52; // r12
  unsigned int v53; // r0
  unsigned int v54; // r4
  int v55; // r1
  unsigned int v56; // lr
  unsigned int v57; // r6
  unsigned __int64 v58; // kr2C8_8
  unsigned int v59; // lr
  unsigned __int64 v60; // kr298_8
  unsigned int v61; // r0
  unsigned int v62; // r0
  unsigned __int64 v63; // kr2E0_8
  unsigned int v64; // lr
  unsigned int v65; // r6
  unsigned int v66; // r12
  unsigned int v67; // r7
  unsigned int v68; // r1
  unsigned int v69; // r7
  unsigned int v70; // r6
  __int64 v71; // kr2F8_8
  unsigned int v72; // r12
  int v73; // r6
  unsigned __int64 v74; // kr300_8
  unsigned int v75; // lr
  unsigned int v76; // r0
  unsigned __int64 v77; // kr2A8_8
  unsigned int v78; // r6
  unsigned int v79; // lr
  unsigned int v80; // r6
  uint64_t v81; // kr308_8
  unsigned __int64 v82; // kr310_8
  unsigned int v83; // r6
  unsigned int v84; // r7
  int v85; // r12
  int v86; // r1
  __int64 v87; // r6
  __int64 v88; // kr330_8
  unsigned int v89; // r12
  int v90; // r12
  uint64_t v91; // kr2B0_8
  unsigned int v92; // r1
  int v93; // lr
  unsigned __int64 v94; // kr2B8_8
  uint64_t v95; // kr340_8
  bool v96; // cf
  int v97; // r1
  int v98; // r0
  unsigned int v99; // r1
  int v100; // r0
  unsigned int v101; // lr
  unsigned int v102; // r12
  unsigned int v103; // r12
  uint64_t v104; // kr350_8
  uint64_t v105; // kr368_8
  int v106; // r0
  int v107; // lr
  unsigned __int64 v108; // kr370_8
  unsigned int v109; // r0
  int v110; // r1
  unsigned int v111; // lr
  unsigned __int64 v112; // kr380_8
  int v113; // r0
  uint64_t v114; // kr388_8
  int v115; // lr
  unsigned int v116; // r0
  int v117; // r12
  __int64 v118; // r0
  unsigned int v119; // r12
  unsigned int v120; // lr
  int v121; // r12
  unsigned int v122; // lr
  int v123; // lr
  uint64_t v124; // kr3A0_8
  uint64_t v125; // kr2C0_8
  int v126; // lr
  uint64_t v127; // kr3C0_8
  unsigned int v128; // lr
  int v129; // r12
  int v130; // lr
  uint64_t v131; // kr2D0_8
  unsigned int v132; // r12
  unsigned __int64 v133; // kr3D8_8
  unsigned int v134; // lr
  int v135; // lr
  int v136; // r12
  uint64_t v137; // kr3E0_8
  unsigned int v138; // lr
  unsigned int v139; // r12
  int v140; // r12
  int v141; // lr
  uint64_t v142; // kr3F8_8
  unsigned int v143; // r12
  unsigned int v144; // lr
  unsigned int v145; // r12
  int v146; // r12
  signed __int64 v147; // r10
  unsigned int v148; // r12
  unsigned __int64 v149; // kr418_8
  int v150; // lr
  unsigned int v151; // lr
  unsigned __int64 v152; // kr428_8
  unsigned int v153; // lr
  uint64_t v154; // r2
  int v155; // r12
  unsigned __int64 v156; // kr2D8_8
  unsigned int v157; // r12
  unsigned int v158; // lr
  int v159; // r12
  uint64_t v160; // kr438_8
  uint64_t v161; // kr440_8
  unsigned int v162; // lr
  int v163; // lr
  unsigned __int64 v164; // kr460_8
  unsigned int v165; // lr
  int v166; // r12
  int v167; // lr
  uint64_t v168; // kr2E8_8
  unsigned int v169; // r12
  unsigned int v170; // lr
  int v171; // lr
  int v172; // r12
  uint64_t v173; // kr488_8
  unsigned int v174; // lr
  unsigned int v175; // r12
  int v176; // r12
  int v177; // lr
  __int64 v178; // kr498_8
  uint64_t v179; // kr2F0_8
  unsigned int v180; // r12
  unsigned int v181; // r12
  int v182; // r12
  uint64_t v183; // kr4B8_8
  __int64 v184; // r10
  unsigned int v185; // r12
  uint64_t v186; // kr4C0_8
  unsigned int v187; // lr
  unsigned __int64 v188; // kr4E8_8
  unsigned int v189; // lr
  unsigned int v190; // lr
  int v191; // r12
  unsigned __int64 v192; // r0
  unsigned int v193; // r12
  uint64_t v194; // kr4F8_8
  unsigned int v195; // lr
  int v196; // r12
  uint64_t v197; // kr500_8
  unsigned int v198; // lr
  int v199; // lr
  uint64_t v200; // kr520_8
  unsigned int v201; // lr
  int v202; // r12
  int v203; // lr
  uint64_t v204; // kr530_8
  unsigned int v205; // r12
  unsigned int v206; // lr
  int v207; // lr
  int v208; // r12
  uint64_t v209; // kr540_8
  unsigned int v210; // lr
  unsigned int v211; // r12
  int v212; // r12
  int v213; // lr
  int v214; // lr
  int v215; // r12
  unsigned int v216; // lr
  uint64_t v217; // kr558_8
  unsigned int v218; // r12
  int v219; // r12
  uint64_t v220; // kr318_8
  unsigned __int64 v221; // kr570_8
  unsigned int v222; // r12
  uint64_t v223; // kr320_8
  int v224; // lr
  unsigned __int64 v225; // kr5A8_8
  unsigned int v226; // lr
  int v227; // lr
  unsigned int v228; // r12
  unsigned int v229; // r12
  unsigned int v230; // lr
  int v231; // r12
  uint64_t v232; // kr5C8_8
  int v233; // lr
  unsigned int v234; // lr
  uint64_t v235; // kr5D0_8
  unsigned __int64 v236; // kr5E8_8
  unsigned int v237; // lr
  int v238; // lr
  unsigned int v239; // lr
  int v240; // r12
  int v241; // lr
  uint64_t v242; // kr608_8
  unsigned int v243; // r12
  unsigned __int64 v244; // kr610_8
  unsigned int v245; // lr
  int v246; // lr
  int v247; // r12
  unsigned int v248; // lr
  unsigned int v249; // r12
  int v250; // r12
  int v251; // lr
  uint64_t v252; // kr620_8
  uint64_t v253; // kr638_8
  int v254; // r12
  int v255; // lr
  unsigned int v256; // lr
  uint64_t v257; // kr640_8
  unsigned int v258; // r12
  int v259; // r12
  signed __int64 v260; // r10
  unsigned int v261; // r12
  int v262; // lr
  unsigned __int64 v263; // kr668_8
  unsigned __int64 v264; // kr678_8
  unsigned int v265; // lr
  uint64_t v266; // kr680_8
  int v267; // lr
  unsigned int v268; // r12
  unsigned int v269; // r12
  unsigned int v270; // lr
  uint64_t v271; // kr690_8
  int v272; // r12
  unsigned int v273; // kr120_4
  unsigned int v274; // lr
  uint64_t v275; // kr698_8
  unsigned int v276; // lr
  unsigned int v277; // lr
  uint64_t v278; // kr6C0_8
  unsigned int v279; // lr
  int v280; // r12
  int v281; // lr
  uint64_t v282; // kr6D0_8
  unsigned __int64 v283; // kr6D8_8
  unsigned int v284; // r12
  unsigned int v285; // lr
  int v286; // lr
  int v287; // r12
  uint64_t v288; // kr6E0_8
  unsigned int v289; // lr
  unsigned int v290; // r12
  int v291; // r12
  int v292; // lr
  uint64_t v293; // kr328_8
  uint64_t v294; // kr700_8
  int v295; // r12
  int v296; // lr
  uint64_t v297; // kr708_8
  unsigned int v298; // lr
  unsigned int v299; // r12
  int v300; // r12
  signed __int64 v301; // r10
  unsigned int v302; // r12
  uint64_t v303; // kr728_8
  int v304; // lr
  unsigned __int64 v305; // kr730_8
  unsigned int v306; // lr
  unsigned __int64 v307; // kr740_8
  unsigned int v308; // lr
  uint64_t v309; // kr748_8
  int v310; // r12
  unsigned int v311; // r12
  uint64_t v312; // kr758_8
  unsigned int v313; // lr
  int v314; // r12
  int v315; // lr
  uint64_t v316; // kr760_8
  uint64_t v317; // kr768_8
  unsigned int v318; // lr
  unsigned __int64 v319; // kr780_8
  unsigned int v320; // lr
  int v321; // lr
  __int64 v322; // kr788_8
  uint64_t v323; // kr790_8
  unsigned int v324; // lr
  int v325; // r12
  int v326; // lr
  uint64_t v327; // kr7A0_8
  unsigned int v328; // r12
  unsigned __int64 v329; // kr7A8_8
  unsigned int v330; // lr
  int v331; // lr
  int v332; // r12
  uint64_t v333; // kr7B0_8
  unsigned int v334; // lr
  unsigned int v335; // r12
  int v336; // r12
  int v337; // lr
  unsigned int v338; // r12
  int v339; // lr
  unsigned int v340; // lr
  uint64_t v341; // kr7C8_8
  unsigned int v342; // r12
  int v343; // r12
  signed __int64 v344; // r10
  uint64_t v345; // r2
  unsigned int v346; // r12
  uint64_t v347; // kr338_8
  unsigned __int64 v348; // kr7F8_8
  int v349; // lr
  unsigned int v350; // lr
  unsigned int v351; // lr
  int v352; // r12
  uint64_t v353; // kr348_8
  unsigned int v354; // r12
  unsigned int v355; // lr
  uint64_t v356; // kr818_8
  int v357; // r12
  uint64_t v358; // kr820_8
  unsigned int v359; // lr
  unsigned int v360; // lr
  int v361; // lr
  unsigned int v362; // lr
  int v363; // r12
  int v364; // lr
  uint64_t v365; // kr850_8
  __int64 v366; // r10
  unsigned int v367; // kr194_4
  unsigned int v368; // r12
  unsigned int v369; // lr
  int v370; // lr
  int v371; // r12
  uint64_t v372; // kr860_8
  unsigned int v373; // lr
  unsigned int v374; // r12
  int v375; // r12
  int v376; // lr
  int v377; // r12
  unsigned int v378; // lr
  uint64_t v379; // kr878_8
  unsigned int v380; // r12
  int v381; // r12
  signed __int64 v382; // r10
  unsigned __int64 v383; // r2
  unsigned int v384; // r12
  int v385; // lr
  unsigned __int64 v386; // kr8A0_8
  unsigned int v387; // lr
  unsigned int v388; // lr
  uint64_t v389; // kr358_8
  unsigned int v390; // r12
  unsigned int v391; // r12
  unsigned int v392; // lr
  int v393; // r12
  unsigned __int64 v394; // kr360_8
  uint64_t v395; // kr8D8_8
  uint64_t v396; // kr8E0_8
  int v397; // lr
  unsigned int v398; // lr
  int v399; // lr
  uint64_t v400; // kr900_8
  unsigned int v401; // lr
  int v402; // r12
  int v403; // lr
  uint64_t v404; // kr378_8
  unsigned int v405; // lr
  unsigned int v406; // r12
  int v407; // lr
  int v408; // r12
  uint64_t v409; // kr920_8
  unsigned int v410; // lr
  unsigned int v411; // r12
  int v412; // r12
  int v413; // lr
  uint64_t v414; // kr928_8
  unsigned int v415; // kr68_4
  uint64_t v416; // kr930_8
  unsigned __int64 v417; // kr390_8
  uint64_t v418; // kr398_8
  int v419; // r12
  int v420; // lr
  unsigned int v421; // lr
  unsigned __int64 v422; // kr1D0_8
  uint64_t v423; // kr940_8
  unsigned int v424; // r12
  int v425; // r12
  signed __int64 v426; // r10
  unsigned int v427; // r12
  uint64_t v428; // kr960_8
  int v429; // lr
  unsigned __int64 v430; // kr968_8
  uint64_t v431; // kr970_8
  unsigned __int64 v432; // kr978_8
  unsigned int v433; // lr
  int v434; // lr
  unsigned int v435; // r12
  unsigned int v436; // r12
  unsigned int v437; // lr
  int v438; // r12
  uint64_t v439; // kr990_8
  unsigned int v440; // lr
  int v441; // lr
  unsigned __int64 v442; // kr9B0_8
  uint64_t v443; // kr9B8_8
  unsigned int v444; // lr
  int v445; // r12
  int v446; // lr
  uint64_t v447; // kr9C8_8
  unsigned int v448; // r12
  unsigned int v449; // lr
  int v450; // lr
  int v451; // r12
  uint64_t v452; // kr9D8_8
  unsigned int v453; // lr
  unsigned int v454; // r12
  int v455; // r12
  int v456; // lr
  unsigned int v457; // krC8_4
  uint64_t v458; // kr9F0_8
  unsigned int v459; // r12
  int v460; // lr
  unsigned int v461; // lr
  uint64_t v462; // kr9F8_8
  unsigned int v463; // r12
  int v464; // r12
  signed __int64 v465; // r10
  __int64 v466; // r2
  unsigned int v467; // r12
  unsigned __int64 v468; // krA10_8
  int v469; // lr
  unsigned __int64 v470; // krA20_8
  unsigned int v471; // lr
  unsigned int v472; // lr
  int v473; // r12
  unsigned int v474; // r12
  int v475; // lr
  int v476; // r12
  uint64_t v477; // krA78_8
  unsigned int v478; // lr
  int v479; // r12
  unsigned int v480; // lr
  uint64_t v481; // krA98_8
  unsigned int v482; // lr
  __int64 v483; // krAA0_8
  unsigned int v484; // r12
  uint64_t v485; // krAA8_8
  signed __int64 v486; // krAB0_8
  uint64_t v487; // kr3A8_8
  unsigned int v488; // lr
  int v489; // lr
  unsigned int v490; // r12
  unsigned int v491; // lr
  unsigned __int64 v492; // krAD0_8
  unsigned int v493; // r12
  uint64_t v494; // krAD8_8
  uint64_t v495; // krAE8_8
  int v496; // kr25C_4
  unsigned int v497; // r12
  uint64_t v498; // krAF8_8
  signed __int64 v499; // r8
  unsigned int v500; // r12
  unsigned int v501; // lr
  unsigned __int64 v502; // krB00_8
  uint64_t v503; // krB08_8
  unsigned int v504; // lr
  unsigned int v505; // lr
  uint64_t v506; // krB10_8
  unsigned int v507; // r12
  unsigned int v508; // r12
  uint64_t v509; // r0
  unsigned __int64 v510; // krB20_8
  int v511; // lr
  uint64_t v512; // krB38_8
  unsigned int v513; // lr
  uint64_t v514; // krB40_8
  uint64_t v515; // krB50_8
  unsigned int v516; // r12
  size_t *v517; // r2
  uint64_t *v518; // r5
  uint64_t v519; // r6
  uint64_t v520; // t1
  size_t v521; // t1
  size_t v522; // r0
  unsigned int v524; // [sp+4h] [bp-210h]
  unsigned int v525; // [sp+14h] [bp-200h]
  int v526; // [sp+14h] [bp-200h]
  int v527; // [sp+20h] [bp-1F4h]
  unsigned __int64 v528; // [sp+2Ch] [bp-1E8h]
  uint64_t v529; // [sp+34h] [bp-1E0h]
  unsigned int v530; // [sp+3Ch] [bp-1D8h]
  int v531; // [sp+3Ch] [bp-1D8h]
  unsigned int v532; // [sp+44h] [bp-1D0h]
  _BYTE v533[12]; // [sp+48h] [bp-1CCh]
  unsigned int v534; // [sp+50h] [bp-1C4h]
  unsigned int v535; // [sp+54h] [bp-1C0h]
  int v536; // [sp+54h] [bp-1C0h]
  int v537; // [sp+58h] [bp-1BCh]
  int v538; // [sp+58h] [bp-1BCh]
  unsigned int v539; // [sp+58h] [bp-1BCh]
  int v540; // [sp+5Ch] [bp-1B8h]
  int v541; // [sp+5Ch] [bp-1B8h]
  unsigned int v542; // [sp+5Ch] [bp-1B8h]
  int v543; // [sp+60h] [bp-1B4h]
  int v544; // [sp+60h] [bp-1B4h]
  unsigned int v545; // [sp+70h] [bp-1A4h]
  unsigned int v546; // [sp+78h] [bp-19Ch]
  int v547; // [sp+7Ch] [bp-198h]
  unsigned int v548; // [sp+88h] [bp-18Ch]
  unsigned int v549; // [sp+88h] [bp-18Ch]
  unsigned int v550; // [sp+88h] [bp-18Ch]
  int v551; // [sp+88h] [bp-18Ch]
  int v552; // [sp+88h] [bp-18Ch]
  unsigned int v553; // [sp+88h] [bp-18Ch]
  unsigned int v554; // [sp+88h] [bp-18Ch]
  unsigned int v555; // [sp+88h] [bp-18Ch]
  unsigned int v556; // [sp+88h] [bp-18Ch]
  int v557; // [sp+88h] [bp-18Ch]
  unsigned int v558; // [sp+88h] [bp-18Ch]
  unsigned int v559; // [sp+88h] [bp-18Ch]
  unsigned int v560; // [sp+88h] [bp-18Ch]
  int v561; // [sp+88h] [bp-18Ch]
  unsigned int v562; // [sp+88h] [bp-18Ch]
  unsigned int v563; // [sp+88h] [bp-18Ch]
  unsigned int v564; // [sp+88h] [bp-18Ch]
  int v565; // [sp+88h] [bp-18Ch]
  unsigned int v566; // [sp+88h] [bp-18Ch]
  unsigned int v567; // [sp+88h] [bp-18Ch]
  __int64 v568; // [sp+8Ch] [bp-188h]
  unsigned __int64 v569; // [sp+94h] [bp-180h]
  _BYTE v570[12]; // [sp+9Ch] [bp-178h]
  unsigned int v571; // [sp+A4h] [bp-170h]
  int v572; // [sp+A4h] [bp-170h]
  int v573; // [sp+A4h] [bp-170h]
  unsigned int v574; // [sp+A4h] [bp-170h]
  __int64 v575; // [sp+A8h] [bp-16Ch]
  _BYTE v576[20]; // [sp+B0h] [bp-164h]
  unsigned int v577; // [sp+B0h] [bp-164h]
  unsigned int v578; // [sp+B0h] [bp-164h]
  unsigned int v579; // [sp+B0h] [bp-164h]
  unsigned int v580; // [sp+B0h] [bp-164h]
  int v581; // [sp+B4h] [bp-160h]
  int v582; // [sp+C0h] [bp-154h]
  int v583; // [sp+C0h] [bp-154h]
  int v584; // [sp+C0h] [bp-154h]
  __int64 v585; // [sp+C4h] [bp-150h]
  uint64_t v586; // [sp+C4h] [bp-150h]
  __int64 v587; // [sp+C4h] [bp-150h]
  blake2b_state *v588; // [sp+CCh] [bp-148h]
  size_t *p_buflen; // [sp+D4h] [bp-140h]
  unsigned __int64 v590; // [sp+D8h] [bp-13Ch]
  _BYTE v591[24]; // [sp+D8h] [bp-13Ch]
  uint64_t v592; // [sp+D8h] [bp-13Ch]
  uint64_t v593; // [sp+D8h] [bp-13Ch]
  uint64_t v594; // [sp+D8h] [bp-13Ch]
  uint64_t v595; // [sp+D8h] [bp-13Ch]
  uint64_t v596; // [sp+D8h] [bp-13Ch]
  unsigned int v597; // [sp+E0h] [bp-134h]
  unsigned int v598; // [sp+E4h] [bp-130h]
  unsigned int v599; // [sp+E8h] [bp-12Ch]
  unsigned int v600; // [sp+E8h] [bp-12Ch]
  int v601; // [sp+ECh] [bp-128h]
  unsigned int v602; // [sp+ECh] [bp-128h]
  int v603; // [sp+ECh] [bp-128h]
  int v604; // [sp+ECh] [bp-128h]
  unsigned int v605; // [sp+ECh] [bp-128h]
  int v606; // [sp+F0h] [bp-124h]
  unsigned int v607; // [sp+F0h] [bp-124h]
  int v608; // [sp+F0h] [bp-124h]
  unsigned int v609; // [sp+F0h] [bp-124h]
  unsigned int v610; // [sp+F0h] [bp-124h]
  unsigned __int64 v611; // [sp+F0h] [bp-124h]
  _BYTE v612[20]; // [sp+F0h] [bp-124h]
  unsigned int v613; // [sp+F4h] [bp-120h]
  int v614; // [sp+F4h] [bp-120h]
  unsigned int v615; // [sp+F4h] [bp-120h]
  unsigned int v616; // [sp+F4h] [bp-120h]
  unsigned int v617; // [sp+F4h] [bp-120h]
  int v618; // [sp+F4h] [bp-120h]
  int v619; // [sp+F8h] [bp-11Ch]
  int v620; // [sp+F8h] [bp-11Ch]
  unsigned int v621; // [sp+F8h] [bp-11Ch]
  int v622; // [sp+F8h] [bp-11Ch]
  unsigned int v623; // [sp+F8h] [bp-11Ch]
  unsigned int v624; // [sp+F8h] [bp-11Ch]
  unsigned int v625; // [sp+FCh] [bp-118h]
  int v626; // [sp+FCh] [bp-118h]
  int v627; // [sp+FCh] [bp-118h]
  int v628; // [sp+FCh] [bp-118h]
  unsigned int v629; // [sp+FCh] [bp-118h]
  int v630; // [sp+FCh] [bp-118h]
  int v631; // [sp+FCh] [bp-118h]
  int v632; // [sp+100h] [bp-114h]
  int v633; // [sp+100h] [bp-114h]
  int v634; // [sp+100h] [bp-114h]
  unsigned int v635; // [sp+100h] [bp-114h]
  unsigned int v636; // [sp+100h] [bp-114h]
  int v637; // [sp+100h] [bp-114h]
  int v638; // [sp+100h] [bp-114h]
  int v639; // [sp+100h] [bp-114h]
  unsigned int v640; // [sp+100h] [bp-114h]
  int v641; // [sp+100h] [bp-114h]
  unsigned int v642; // [sp+100h] [bp-114h]
  __int64 v643; // [sp+104h] [bp-110h] BYREF
  int v644; // [sp+10Ch] [bp-108h]
  uint64_t m[16]; // [sp+110h] [bp-104h] BYREF
  uint64_t v[16]; // [sp+190h] [bp-84h] BYREF

  v2 = (uint64_t *)((char *)&v643 + 4);
  v3 = &m[15];
  do
  {
    block += 8;
    v4 = *((_DWORD *)block - 1);
    *((_DWORD *)v2++ + 2) = *((_DWORD *)block - 2);
    *((_DWORD *)v2 + 1) = v4;
  }
  while ( &m[15] != v2 );
  v5 = (blake2b_state *)((char *)S - 8);
  p_buflen = &S[-1].buflen;
  do
  {
    v6 = v5->h[1];
    v5 = (blake2b_state *)((char *)v5 + 8);
    v3[1] = v6;
    ++v3;
  }
  while ( &S->h[7] != (uint64_t *)v5 );
  v7 = v[4] + v[0] + m[0];
  v588 = v5;
  v8 = HIDWORD(v7) ^ 0x510E527F ^ HIDWORD(S->t[0]);
  v9 = v7 ^ 0xADE682D1 ^ LODWORD(S->t[0]);
  v10 = __CFADD__(v8, -205731576) + v9 + 1779033703;
  LODWORD(v585) = ((LODWORD(v[4]) ^ (unsigned int)(v8 - 205731576)) >> 24) | ((HIDWORD(v[4]) ^ v10) << 8);
  HIDWORD(v585) = ((HIDWORD(v[4]) ^ (unsigned int)v10) >> 24) | ((LODWORD(v[4]) ^ (v8 - 205731576)) << 8);
  v11 = LODWORD(v[4]) + LODWORD(v[0]) + LODWORD(m[0]) + LODWORD(m[1]) + v585;
  v529 = v7 + m[1] + v585;
  v12 = HIDWORD(v529) ^ v9;
  v534 = ((v8 ^ v11) >> 16) | (v12 << 16);
  v543 = HIWORD(v12) | ((v8 ^ v11) << 16);
  v590 = __PAIR64__(v10, v8 - 205731576) + __PAIR64__(v543, v534);
  v13 = v[5] + v[1] + m[2];
  v14 = HIDWORD(v13) ^ 0x9B05688C ^ HIDWORD(S->t[1]);
  v15 = v14 - 2067093701;
  v16 = v13 ^ 0x2B3E6C1F ^ LODWORD(S->t[1]);
  v17 = __CFADD__(v14, -2067093701) + v16 - 1150833019;
  LODWORD(v18) = ((LODWORD(v[5]) ^ (v14 - 2067093701)) >> 24) | ((HIDWORD(v[5]) ^ v17) << 8);
  HIDWORD(v18) = ((HIDWORD(v[5]) ^ (unsigned int)v17) >> 24) | ((LODWORD(v[5]) ^ (v14 - 2067093701)) << 8);
  *(_QWORD *)v533 = v13 + m[3] + v18;
  v19 = v14 ^ (LODWORD(v[5]) + LODWORD(v[1]) + LODWORD(m[2]) + LODWORD(m[3]) + v18);
  v20 = v16 ^ *(_DWORD *)&v533[4];
  v537 = HIWORD(v19) | (v20 << 16);
  v540 = HIWORD(v20) | (v19 << 16);
  LODWORD(v568) = v15 + v537;
  HIDWORD(v568) = v15 + v537;
  v21 = ((v[6] + v[2] + m[4]) >> 32) ^ 0x1F83D9AB ^ HIDWORD(S->f[0]);
  v22 = (LODWORD(v[6]) + LODWORD(v[2]) + LODWORD(m[4])) ^ 0xFB41BD6B ^ LODWORD(S->f[0]);
  v23 = v21 - 23791573;
  v24 = __CFADD__(v21, -23791573) + v22 + 1013904242;
  v25 = ((LODWORD(v[6]) ^ (unsigned int)(v21 - 23791573)) >> 24) | ((HIDWORD(v[6]) ^ v24) << 8);
  v532 = ((HIDWORD(v[6]) ^ (unsigned int)v24) >> 24) | ((LODWORD(v[6]) ^ (v21 - 23791573)) << 8);
  v535 = LODWORD(v[6]) + LODWORD(v[2]) + LODWORD(m[4]) + LODWORD(m[5]) + v25;
  v26 = v22 ^ ((v[6] + v[2] + m[4] + m[5] + __PAIR64__(v532, v25)) >> 32);
  v597 = (v[6] + v[2] + m[4] + m[5] + __PAIR64__(v532, v25)) >> 32;
  v27 = v535 ^ v21;
  v582 = HIWORD(v26) | (v27 << 16);
  v632 = HIWORD(v27) | (v26 << 16);
  v530 = (__PAIR64__(v24, v23) + __PAIR64__(v582, v632)) >> 32;
  v28 = v[7] + v[3] + m[6];
  v29 = HIDWORD(v28) ^ 0x5BE0CD19 ^ HIDWORD(S->f[1]);
  v30 = v29 + 1595750129;
  v31 = v28 ^ 0x137E2179 ^ LODWORD(S->f[1]);
  v32 = __CFADD__(v29, 1595750129) + v31 - 1521486534;
  v33 = ((LODWORD(v[7]) ^ (unsigned int)(v29 + 1595750129)) >> 24) | ((HIDWORD(v[7]) ^ v32) << 8);
  v34 = v568 ^ v18;
  LODWORD(v18) = ((HIDWORD(v[7]) ^ (unsigned int)v32) >> 24) | ((LODWORD(v[7]) ^ (v29 + 1595750129)) << 8);
  v35 = v29 ^ (LODWORD(v[7]) + LODWORD(v[3]) + LODWORD(m[6]) + LODWORD(m[7]) + v33);
  v548 = (v28 + m[7] + __PAIR64__(v18, v33)) >> 32;
  v36 = v31 ^ v548;
  v598 = LODWORD(v[7]) + LODWORD(v[3]) + LODWORD(m[6]) + LODWORD(m[7]) + v33;
  v37 = HIWORD(v36) | (v35 << 16);
  v38 = HIDWORD(v568) ^ HIDWORD(v18);
  HIDWORD(v18) = HIWORD(v35) | (v36 << 16);
  v39 = 2 * v38;
  LODWORD(v40) = m[8];
  HIDWORD(v41) = v32 + __CFADD__(v30, HIDWORD(v18)) + v37;
  v547 = v30 + HIDWORD(v18);
  v42 = (2 * v34) | (v38 >> 31);
  HIDWORD(v40) = HIDWORD(v529);
  v43 = v39 | (v34 >> 31);
  LODWORD(v18) = HIDWORD(v41) ^ v18;
  v44 = (__PAIR64__(HIDWORD(m[8]), v529) + v40 + __PAIR64__(v43, v42)) >> 32;
  LODWORD(v40) = v529 + LODWORD(m[8]) + v42;
  v45 = HIDWORD(v18) ^ v40;
  v46 = v44 ^ v37;
  v48 = v23 + v632;
  v47 = v23 + v632 + v46;
  v49 = (v23 + v632) ^ v25;
  v50 = v47 ^ v42;
  v51 = __PAIR64__(v530, v48) + __PAIR64__(HIDWORD(v18) ^ (unsigned int)v40, v46);
  v52 = ((__PAIR64__(v530, v48) + __PAIR64__(HIDWORD(v18) ^ (unsigned int)v40, v46)) >> 32) ^ v43;
  *(_DWORD *)&v576[8] = HIBYTE(v50) | (v52 << 8);
  HIDWORD(v40) = HIDWORD(m[9]);
  *(_DWORD *)&v576[12] = HIBYTE(v52) | (v50 << 8);
  v569 = v40 + __PAIR64__(v44, m[9]) + *(_QWORD *)&v576[8];
  LODWORD(v40) = (2 * v49) | ((v530 ^ v532) >> 31);
  v53 = v46 ^ v569;
  v54 = v45 ^ HIDWORD(v569);
  v581 = HIWORD(v54) | (v53 << 16);
  v55 = (2 * (v530 ^ v532)) | (v49 >> 31);
  *(_QWORD *)v570 = v51 + __PAIR64__(v581, HIWORD(v53) | (v54 << 16));
  LODWORD(v643) = HIWORD(v53) | (v54 << 16);
  LODWORD(v41) = (*(_QWORD *)v533 + m[10] + __PAIR64__(v55, v40)) >> 32;
  v56 = *(_DWORD *)v533 + LODWORD(m[10]) + v40;
  LODWORD(v51) = v56 ^ v534;
  v57 = v33 ^ v547;
  LODWORD(v40) = v40 ^ (v547 + (v41 ^ v543));
  v58 = __PAIR64__(v56 ^ v534, v547) + (v41 ^ (unsigned int)v543);
  v577 = (((unsigned int)v55 ^ HIDWORD(v58)) >> 24) | ((_DWORD)v40 << 8);
  HIDWORD(v18) = (2 * v57) | ((unsigned int)v18 >> 31);
  v613 = BYTE3(v40) | ((v55 ^ HIDWORD(v58)) << 8);
  v60 = __PAIR64__(v41, v56) + m[11] + __PAIR64__(v577, v613);
  v59 = HIDWORD(v60);
  v571 = v60;
  HIDWORD(v51) = (2 * v18) | (v57 >> 31);
  LODWORD(v51) = v59 ^ v51;
  v61 = v41 ^ v543 ^ v571;
  v599 = v59;
  v601 = HIWORD(v61) | ((_DWORD)v51 << 16);
  v62 = WORD1(v51) | (v61 << 16);
  v575 = v58 + __PAIR64__(v62, v601);
  v625 = v62;
  v63 = __PAIR64__(v597, v535) + m[12] + __PAIR64__(HIDWORD(v51), HIDWORD(v18));
  v541 = v540 ^ HIDWORD(v63);
  LODWORD(v40) = (v590 + v541) ^ HIDWORD(v18);
  v64 = ((v590 + __PAIR64__((unsigned int)v63 ^ v537, v541)) >> 32) ^ HIDWORD(v51);
  HIDWORD(v51) = BYTE3(v40) | (v64 << 8);
  HIDWORD(v18) = HIBYTE(v64) | ((_DWORD)v40 << 8);
  v65 = (2 * (v590 ^ v585)) | ((unsigned int)(HIDWORD(v590) ^ HIDWORD(v585)) >> 31);
  HIDWORD(v41) = v541 ^ (v63 + LODWORD(m[13]) + HIDWORD(v51));
  v66 = (__int64)(v590 ^ v585) >> 31;
  v67 = v63 ^ v537 ^ ((v63 + m[13] + __PAIR64__(HIDWORD(v18), HIDWORD(v51))) >> 32);
  v586 = v63 + m[13] + __PAIR64__(HIDWORD(v18), HIDWORD(v51));
  LODWORD(v40) = HIWORD(HIDWORD(v41)) | (v67 << 16);
  v68 = v590 + v541 + v40;
  v606 = v40;
  HIDWORD(v40) = HIWORD(v67) | (HIDWORD(v41) << 16);
  LODWORD(v41) = (v590 + __PAIR64__((unsigned int)v63 ^ v537, v541) + v40) >> 32;
  HIDWORD(v18) ^= v41;
  v619 = HIDWORD(v40);
  LODWORD(v18) = (v598 + LODWORD(m[14]) + v65) ^ v632;
  LODWORD(v51) = (__PAIR64__(v548, v598) + m[14] + __PAIR64__(v66, v65)) >> 32;
  v69 = v598 + LODWORD(m[14]) + v65;
  v549 = *(_DWORD *)v570 ^ *(_DWORD *)&v576[8];
  v70 = v65 ^ (v568 + (v51 ^ v582));
  *(_DWORD *)&v576[8] = *(_DWORD *)&v570[4] ^ *(_DWORD *)&v576[12];
  v71 = v568 + __PAIR64__(v18, (unsigned int)v51 ^ v582);
  v72 = ((v568 + __PAIR64__(v18, (unsigned int)v51 ^ v582)) >> 32) ^ v66;
  LODWORD(v568) = HIBYTE(v70) | (v72 << 8);
  v73 = HIBYTE(v72) | (v70 << 8);
  HIDWORD(v568) = (v58 + v601) ^ v613;
  v74 = __PAIR64__(v51, v69) + m[15] + __PAIR64__(v73, v568);
  v75 = v74 ^ v51 ^ v582;
  LODWORD(v18) = HIDWORD(v74) ^ v18;
  HIDWORD(v40) = WORD1(v18);
  LODWORD(v18) = HIWORD(v75) | ((_DWORD)v18 << 16);
  v77 = v71 + __PAIR64__(HIDWORD(v40) | (v75 << 16), v18);
  v76 = HIDWORD(v77);
  LODWORD(v40) = v77;
  v578 = HIDWORD(v575) ^ v577;
  *(_DWORD *)&v576[12] = v68 ^ HIDWORD(v51);
  v614 = HIDWORD(v40) | (v75 << 16);
  v78 = v73 ^ ((v71 + __PAIR64__(v614, v18)) >> 32);
  v79 = (2 * ((v71 + v18) ^ v568)) | (v78 >> 31);
  v80 = (2 * v78) | (((unsigned int)v40 ^ (unsigned int)v568) >> 31);
  v81 = v569 + m[14] + __PAIR64__(v80, v79);
  v82 = __PAIR64__(v41, v68) + __PAIR64__((unsigned int)v81 ^ v601, HIDWORD(v81) ^ v625);
  LODWORD(v41) = (__PAIR64__(v41, v68) + __PAIR64__((unsigned int)v81 ^ v601, HIDWORD(v81) ^ v625)) >> 32;
  HIDWORD(v41) = v80 ^ v41;
  v83 = (((unsigned int)v82 ^ v79) >> 24) | ((v80 ^ (unsigned int)v41) << 8);
  HIDWORD(v41) = HIBYTE(HIDWORD(v41)) | (((unsigned int)v82 ^ v79) << 8);
  v84 = HIDWORD(v81) ^ v625 ^ (LODWORD(m[10]) + v81 + v83);
  *(_QWORD *)&v591[8] = m[10] + v81 + __PAIR64__(HIDWORD(v41), v83);
  LODWORD(v51) = *(_DWORD *)&v591[12] ^ v81 ^ v601;
  LODWORD(v569) = HIWORD(v84) | ((_DWORD)v51 << 16);
  HIDWORD(v569) = WORD1(v51) | (v84 << 16);
  v85 = (2 * v549) | (*(_DWORD *)&v576[8] >> 31);
  HIDWORD(v40) = (2 * *(_DWORD *)&v576[8]) | (v549 >> 31);
  v550 = (__PAIR64__(v41, v82) + v569) >> 32;
  v602 = v82 + v569;
  *(_DWORD *)&v576[8] = (v82 + v569) ^ v83;
  LODWORD(v41) = (m[4] + __PAIR64__(v599, v571) + __PAIR64__(HIDWORD(v40), v85)) >> 32;
  v86 = LODWORD(m[4]) + v571 + v85;
  HIDWORD(v87) = v86 ^ v606;
  LODWORD(v87) = v619 ^ v41;
  v583 = v550 ^ HIDWORD(v41);
  v88 = __PAIR64__(v76, v40) + v87;
  v89 = (v40 + (v619 ^ v41)) ^ v85;
  HIDWORD(v51) = HIDWORD(v40) ^ ((__PAIR64__(v76, v40) + v87) >> 32);
  HIDWORD(v40) = HIBYTE(v89) | (HIDWORD(v51) << 8);
  v90 = HIBYTE(HIDWORD(v51)) | (v89 << 8);
  v91 = m[8] + __PAIR64__(v41, v86) + __PAIR64__(v90, HIDWORD(v40));
  v607 = HIDWORD(v91);
  v600 = v91;
  v92 = v619 ^ v41 ^ (LODWORD(m[8]) + v86 + HIDWORD(v40));
  HIDWORD(v87) ^= v607;
  HIDWORD(v41) = HIWORD(v92) | (HIDWORD(v87) << 16);
  v572 = HIWORD(HIDWORD(v87)) | (v92 << 16);
  v620 = HIDWORD(v41);
  v94 = v88 + __PAIR64__(v572, HIDWORD(v41));
  v93 = HIDWORD(v94);
  HIDWORD(v41) = v94;
  LODWORD(v41) = (2 * HIDWORD(v568)) | (v578 >> 31);
  v95 = v586;
  LODWORD(v87) = (2 * v578) | (HIDWORD(v568) >> 31);
  LODWORD(v568) = v93;
  v96 = __CFADD__(m[9], (_DWORD)v586);
  v97 = LODWORD(m[9]) + v586;
  v579 = HIDWORD(v41) ^ HIDWORD(v40);
  LODWORD(v586) = HIDWORD(v41);
  v98 = HIDWORD(v95) + v96 + HIDWORD(m[9]);
  v96 = __CFADD__(v97, (_DWORD)v41);
  v99 = v97 + v41;
  v100 = v98 + v96 + (_DWORD)v87;
  v101 = v93 ^ v90;
  LODWORD(v41) = v41 ^ (*(_DWORD *)v570 + (v100 ^ v614));
  HIDWORD(v568) = *(_DWORD *)v570 + (v100 ^ v614);
  HIDWORD(v41) = (*(_QWORD *)v570 + __PAIR64__(v99 ^ (unsigned int)v18, v100 ^ (unsigned int)v614)) >> 32;
  LODWORD(v87) = v87 ^ HIDWORD(v41);
  HIDWORD(v51) = BYTE3(v41) | ((_DWORD)v87 << 8);
  v102 = BYTE3(v87) | ((_DWORD)v41 << 8);
  HIDWORD(v40) = v100 ^ v614 ^ (LODWORD(m[15]) + v99 + HIDWORD(v51));
  HIDWORD(v87) = v99 ^ v18 ^ ((m[15] + __PAIR64__(v100, v99) + __PAIR64__(v102, HIDWORD(v51))) >> 32);
  v615 = (m[15] + __PAIR64__(v100, v99) + __PAIR64__(v102, HIDWORD(v51))) >> 32;
  HIDWORD(v586) = LODWORD(m[15]) + v99 + HIDWORD(v51);
  LODWORD(v40) = HIWORD(HIDWORD(v40)) | (HIDWORD(v87) << 16);
  HIDWORD(v87) = HIWORD(HIDWORD(v87)) | (HIDWORD(v40) << 16);
  v626 = v40;
  LODWORD(v51) = (2 * HIDWORD(v18)) | (*(_DWORD *)&v576[12] >> 31);
  v96 = __CFADD__(HIDWORD(v568), (_DWORD)v40);
  LODWORD(v40) = HIDWORD(v568) + v40;
  HIDWORD(v41) += v96 + HIDWORD(v87);
  v633 = HIDWORD(v87);
  LODWORD(v87) = (2 * *(_DWORD *)&v576[12]) | (HIDWORD(v18) >> 31);
  *(_DWORD *)v570 = v40 ^ HIDWORD(v51);
  v103 = HIDWORD(v41) ^ v102;
  HIDWORD(v18) = (LODWORD(m[13]) + v74 + v87) ^ v643;
  v104 = m[13] + v74 + __PAIR64__(v51, v87);
  HIDWORD(v568) = v575 + (HIDWORD(v104) ^ v581);
  LODWORD(v87) = v87 ^ HIDWORD(v568);
  LODWORD(v41) = (v575 + __PAIR64__(HIDWORD(v18), HIDWORD(v104) ^ (unsigned int)v581)) >> 32;
  LODWORD(v51) = v41 ^ v51;
  HIDWORD(v87) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  LODWORD(v87) = HIDWORD(v87) | ((_DWORD)v87 << 8);
  HIDWORD(v51) = (LODWORD(m[6]) + v104 + v51) ^ HIDWORD(v104) ^ v581;
  v105 = m[6] + v104 + __PAIR64__(v87, v51);
  HIDWORD(v18) ^= HIDWORD(v105);
  v106 = HIWORD(HIDWORD(v18));
  HIDWORD(v18) = HIWORD(HIDWORD(v51)) | (HIDWORD(v18) << 16);
  HIDWORD(v51) = v106 | (HIDWORD(v51) << 16);
  LODWORD(v18) = 2 * v101;
  v107 = (2 * v579) | (v101 >> 31);
  v108 = __PAIR64__(v41, HIDWORD(v568)) + __PAIR64__(HIDWORD(v51), HIDWORD(v18));
  LODWORD(v41) = (__PAIR64__(v41, HIDWORD(v568)) + __PAIR64__(HIDWORD(v51), HIDWORD(v18))) >> 32;
  LODWORD(v18) = v18 | (v579 >> 31);
  LODWORD(v575) = v87 ^ v41;
  v109 = (m[1] + *(_QWORD *)&v591[8] + __PAIR64__(v18, v107)) >> 32;
  v110 = LODWORD(m[1]) + *(_DWORD *)&v591[8] + v107;
  HIDWORD(v18) ^= v110;
  HIDWORD(v51) ^= v109;
  *(_DWORD *)&v570[4] = v108 ^ v51;
  v111 = (v40 + HIDWORD(v51)) ^ v107;
  v112 = __PAIR64__(HIDWORD(v41), v40) + __PAIR64__(HIDWORD(v18), HIDWORD(v51));
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), v40) + __PAIR64__(HIDWORD(v18), HIDWORD(v51))) >> 32;
  v114 = m[12] + __PAIR64__(v109, v110);
  v113 = (m[12] + __PAIR64__(v109, v110)) >> 32;
  LODWORD(v18) = HIDWORD(v41) ^ v18;
  LODWORD(v40) = BYTE3(v18);
  LODWORD(v18) = HIBYTE(v111) | ((_DWORD)v18 << 8);
  v115 = v40 | (v111 << 8);
  HIDWORD(v51) ^= v114 + (_DWORD)v18;
  LODWORD(v590) = v114 + v18;
  HIDWORD(v18) ^= v115 + __CFADD__((_DWORD)v114, (_DWORD)v18) + v113;
  HIDWORD(v590) = v115 + __CFADD__((_DWORD)v114, (_DWORD)v18) + v113;
  v116 = *(_DWORD *)v570;
  LODWORD(v643) = HIWORD(HIDWORD(v51)) | (HIDWORD(v18) << 16);
  *(_DWORD *)v570 = HIWORD(HIDWORD(v18)) | (HIDWORD(v51) << 16);
  LODWORD(v40) = (2 * v103) | (v116 >> 31);
  HIDWORD(v568) = *(_DWORD *)v570 + __CFADD__((_DWORD)v112, (_DWORD)v643) + HIDWORD(v41);
  v117 = (2 * v116) | (v103 >> 31);
  HIDWORD(v575) = (v112 + v643) ^ v18;
  LODWORD(v87) = m[2];
  HIDWORD(v87) = (m[0] + __PAIR64__(v607, v600) + __PAIR64__(v40, v117)) >> 32;
  LODWORD(v118) = LODWORD(m[0]) + v600 + v117;
  LODWORD(v51) = HIDWORD(v87) ^ HIDWORD(v569);
  HIDWORD(v40) = v108 + (HIDWORD(v87) ^ HIDWORD(v569));
  v119 = HIDWORD(v40) ^ v117;
  LODWORD(v41) = v41 + __CFADD__((_DWORD)v108, HIDWORD(v87) ^ HIDWORD(v569)) + (v118 ^ v569);
  LODWORD(v40) = v40 ^ v41;
  HIDWORD(v569) = HIDWORD(v568) ^ v115;
  v120 = BYTE3(v40);
  LODWORD(v40) = HIBYTE(v119) | ((_DWORD)v40 << 8);
  HIDWORD(v118) = HIDWORD(m[2]);
  v121 = v120 | (v119 << 8);
  v122 = (v87 + v118 + __PAIR64__(v121, v40)) >> 32;
  HIDWORD(v118) = LODWORD(m[2]) + v118 + v40;
  LODWORD(v51) = HIDWORD(v118) ^ v51;
  HIDWORD(v41) = v118 ^ v569 ^ v122;
  *(_QWORD *)&v591[12] = __PAIR64__(v122, HIDWORD(v118));
  HIDWORD(v118) = HIWORD(HIDWORD(v41));
  HIDWORD(v87) = WORD1(v51) | (HIDWORD(v41) << 16);
  HIDWORD(v41) = *(_DWORD *)&v570[4];
  LODWORD(v569) = HIDWORD(v118) | ((_DWORD)v51 << 16);
  LODWORD(v118) = 2 * *(_DWORD *)&v570[4];
  *(_DWORD *)&v570[4] = HIDWORD(v87);
  LODWORD(v87) = v118 | ((unsigned int)v575 >> 31);
  v123 = v569 + __CFADD__(HIDWORD(v40), HIDWORD(v87)) + (_DWORD)v41;
  LODWORD(v41) = HIDWORD(v586);
  LODWORD(v51) = (2 * v575) | (HIDWORD(v41) >> 31);
  HIDWORD(v586) = HIDWORD(v40) + HIDWORD(v87);
  LODWORD(v575) = (HIDWORD(v40) + HIDWORD(v87)) ^ v40;
  v608 = v123;
  v124 = m[11] + __PAIR64__(v615, v41) + __PAIR64__(v51, v87);
  v580 = v123 ^ v121;
  LODWORD(v87) = v87 ^ (v602 + (HIDWORD(v124) ^ v572));
  HIDWORD(v87) = (__PAIR64__(v550, v602) + __PAIR64__((unsigned int)v124 ^ v620, HIDWORD(v124) ^ (unsigned int)v572)) >> 32;
  LODWORD(v40) = v602 + (HIDWORD(v124) ^ v572);
  LODWORD(v51) = HIDWORD(v87) ^ v51;
  HIDWORD(v40) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v40) |= (_DWORD)v87 << 8;
  v125 = m[7] + v124 + __PAIR64__(HIDWORD(v40), v51);
  v616 = HIDWORD(v125);
  v603 = v125;
  HIDWORD(v51) = (HIDWORD(v40) + __CFADD__(LODWORD(m[7]) + v124, (_DWORD)v51) + ((m[7] + v124) >> 32)) ^ v124 ^ v620;
  HIDWORD(v41) = v583;
  HIDWORD(v118) = (((LODWORD(m[7]) + (_DWORD)v124 + (_DWORD)v51) ^ HIDWORD(v124) ^ (unsigned int)v572) >> 16)
                | (HIDWORD(v51) << 16);
  LODWORD(v118) = HIWORD(HIDWORD(v51)) | (((LODWORD(m[7]) + (_DWORD)v124 + (_DWORD)v51) ^ HIDWORD(v124) ^ v572) << 16);
  v96 = __CFADD__((_DWORD)v40, HIDWORD(v118));
  LODWORD(v40) = v40 + HIDWORD(v118);
  HIDWORD(v87) += v96 + (_DWORD)v118;
  HIDWORD(v51) = 2 * v583;
  v584 = v118;
  v126 = (2 * *(_DWORD *)&v576[8]) | (HIDWORD(v41) >> 31);
  HIDWORD(v51) |= *(_DWORD *)&v576[8] >> 31;
  v573 = HIDWORD(v118);
  *(_DWORD *)&v576[4] = v40 ^ v51;
  *(_DWORD *)&v576[8] = HIDWORD(v87) ^ HIDWORD(v40);
  HIDWORD(v18) = (LODWORD(m[5]) + v105 + v126) ^ v626;
  v127 = m[5] + v105 + __PAIR64__(HIDWORD(v51), v126);
  LODWORD(v18) = HIDWORD(v127) ^ v633;
  v128 = (v586 + (HIDWORD(v127) ^ v633)) ^ v126;
  LODWORD(v87) = (__PAIR64__(v568, v586) + v18) >> 32;
  HIDWORD(v40) = v586 + (HIDWORD(v127) ^ v633);
  HIDWORD(v51) ^= v87;
  v129 = HIBYTE(v128) | (HIDWORD(v51) << 8);
  v130 = HIBYTE(HIDWORD(v51)) | (v128 << 8);
  v131 = m[3] + v127 + __PAIR64__(v130, v129);
  v621 = HIDWORD(v131);
  LODWORD(v118) = v131;
  LODWORD(v18) = v118 ^ HIDWORD(v127) ^ v633;
  HIDWORD(v18) ^= v130 + __CFADD__(LODWORD(m[3]) + v127, v129) + ((m[3] + v127) >> 32);
  LODWORD(v586) = LODWORD(m[3]) + v127 + v129;
  LODWORD(v118) = HIWORD(HIDWORD(v18));
  HIDWORD(v18) = v18 >> 16;
  LODWORD(v18) = v118 | ((_DWORD)v18 << 16);
  v132 = (HIDWORD(v40) + HIDWORD(v18)) ^ v129;
  v133 = __PAIR64__(v87, HIDWORD(v40)) + __PAIR64__(v18, HIDWORD(v18));
  LODWORD(v87) = (__PAIR64__(v87, HIDWORD(v40)) + __PAIR64__(v18, HIDWORD(v18))) >> 32;
  v134 = v87 ^ v130;
  HIDWORD(v51) = 2 * v134;
  v135 = (2 * v132) | (v134 >> 31);
  v136 = HIDWORD(v51) | (v132 >> 31);
  v137 = m[11] + v590 + __PAIR64__(v136, v135);
  v96 = __CFADD__((_DWORD)v40, v569 ^ HIDWORD(v137));
  LODWORD(v40) = v40 + (v569 ^ HIDWORD(v137));
  v138 = v40 ^ v135;
  v551 = v40;
  HIDWORD(v87) += v96 + (*(_DWORD *)&v570[4] ^ v137);
  v139 = HIDWORD(v87) ^ v136;
  HIDWORD(v51) = HIBYTE(v139);
  v140 = HIBYTE(v138) | (v139 << 8);
  v141 = HIDWORD(v51) | (v138 << 8);
  HIDWORD(v118) = v569 ^ HIDWORD(v137) ^ (LODWORD(m[8]) + v137 + v140);
  HIDWORD(v41) = *(_DWORD *)&v570[4] ^ v137 ^ ((m[8] + v137 + __PAIR64__(v141, v140)) >> 32);
  v592 = m[8] + v137 + __PAIR64__(v141, v140);
  *(_DWORD *)&v570[4] = HIWORD(HIDWORD(v41)) | (HIDWORD(v118) << 16);
  v627 = HIWORD(HIDWORD(v118)) | (HIDWORD(v41) << 16);
  LODWORD(v41) = (2 * HIDWORD(v575)) | (HIDWORD(v569) >> 31);
  HIDWORD(v118) = (2 * HIDWORD(v569)) | (HIDWORD(v575) >> 31);
  HIDWORD(v41) = v40 + v627;
  LODWORD(v40) = *(_DWORD *)&v591[12];
  v552 = *(_DWORD *)&v570[4] + __CFADD__(v551, v627) + HIDWORD(v87);
  *(_DWORD *)&v591[12] = HIDWORD(v41);
  *(_DWORD *)&v576[12] = HIDWORD(v41) ^ v140;
  LODWORD(v118) = LODWORD(m[12]) + v40;
  HIDWORD(v87) = (v118 + __PAIR64__((m[12] + __PAIR64__(*(unsigned int *)&v591[16], v40)) >> 32, v41)) >> 32;
  LODWORD(v118) = LODWORD(m[12]) + v40 + v41;
  HIDWORD(v51) = HIDWORD(v87) ^ v584;
  HIDWORD(v40) = v133 + (HIDWORD(v87) ^ v584);
  LODWORD(v87) = v87 + __CFADD__((_DWORD)v133, HIDWORD(v87) ^ v584) + (v118 ^ v573);
  LODWORD(v41) = v41 ^ HIDWORD(v40);
  HIDWORD(v118) ^= v87;
  LODWORD(v51) = HIBYTE(HIDWORD(v118));
  *(_DWORD *)&v576[16] = v552 ^ v141;
  v142 = m[0] + __PAIR64__(HIDWORD(v87), v118);
  HIDWORD(v87) = (m[0] + __PAIR64__(HIDWORD(v87), v118)) >> 32;
  HIDWORD(v118) = BYTE3(v41) | (HIDWORD(v118) << 8);
  LODWORD(v41) = v51 | ((_DWORD)v41 << 8);
  HIDWORD(v41) = v118 ^ v573 ^ (v41 + __CFADD__((_DWORD)v142, HIDWORD(v118)) + HIDWORD(v87));
  LODWORD(v568) = v41 + __CFADD__((_DWORD)v142, HIDWORD(v118)) + HIDWORD(v87);
  *(_DWORD *)&v591[16] = v142 + HIDWORD(v118);
  v574 = ((HIDWORD(v51) ^ (unsigned int)(v142 + HIDWORD(v118))) >> 16) | (HIDWORD(v41) << 16);
  v634 = HIWORD(HIDWORD(v41)) | ((HIDWORD(v51) ^ ((_DWORD)v142 + HIDWORD(v118))) << 16);
  v143 = (2 * v575) | (v580 >> 31);
  HIDWORD(v87) = (2 * v580) | ((unsigned int)v575 >> 31);
  LODWORD(v40) = v603;
  LODWORD(v569) = HIDWORD(v40) + v574;
  v604 = v634 + __CFADD__(HIDWORD(v40), v574) + (_DWORD)v87;
  HIDWORD(v569) = (HIDWORD(v40) + v574) ^ HIDWORD(v118);
  v144 = v604 ^ v41;
  LODWORD(v118) = (m[5] + __PAIR64__(v616, v40) + __PAIR64__(HIDWORD(v87), v143)) >> 32;
  HIDWORD(v40) = LODWORD(m[5]) + v40 + v143;
  HIDWORD(v18) ^= HIDWORD(v40);
  LODWORD(v18) = v118 ^ v18;
  v145 = (v112 + v643 + v18) ^ v143;
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v568), (int)v112 + (int)v643) + v18) >> 32;
  LODWORD(v40) = v112 + v643 + v18;
  HIDWORD(v87) ^= HIDWORD(v41);
  HIDWORD(v118) = HIBYTE(HIDWORD(v87));
  HIDWORD(v87) = HIBYTE(v145) | (HIDWORD(v87) << 8);
  v146 = HIDWORD(v118) | (v145 << 8);
  v147 = (m[2] + __PAIR64__(v118, HIDWORD(v40)) + __PAIR64__(v146, HIDWORD(v87))) ^ v18;
  v617 = (m[2] + __PAIR64__(v118, HIDWORD(v40)) + __PAIR64__(v146, HIDWORD(v87))) >> 32;
  *(_DWORD *)&v591[8] = LODWORD(m[2]) + HIDWORD(v40) + HIDWORD(v87);
  LODWORD(v118) = v147 >> 16;
  v96 = __CFADD__((_DWORD)v40, (_DWORD)v118);
  LODWORD(v40) = v40 + v118;
  LODWORD(v575) = HIWORD(HIDWORD(v147)) | ((_DWORD)v147 << 16);
  HIDWORD(v41) += v96 + (_DWORD)v575;
  HIDWORD(v643) = v118;
  v148 = HIDWORD(v41) ^ v146;
  HIDWORD(v575) = v40 ^ HIDWORD(v87);
  LODWORD(v118) = (m[15] + __PAIR64__(v621, v586) + ((2LL * *(_QWORD *)&v576[4]) | (*(_DWORD *)&v576[8] >> 31))) >> 32;
  HIDWORD(v40) = LODWORD(m[15]) + v586 + ((2 * *(_DWORD *)&v576[4]) | (*(_DWORD *)&v576[8] >> 31));
  HIDWORD(v568) = HIDWORD(v586) + (v118 ^ *(_DWORD *)v570);
  LODWORD(v87) = ((2 * *(_DWORD *)&v576[4]) | (*(_DWORD *)&v576[8] >> 31)) ^ HIDWORD(v568);
  LODWORD(v41) = (HIDWORD(v40) ^ v643) + __CFADD__(HIDWORD(v586), v118 ^ *(_DWORD *)v570) + v608;
  LODWORD(v51) = v41 ^ (*(__int64 *)&v576[4] >> 31);
  HIDWORD(v87) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  LODWORD(v87) = HIDWORD(v87) | ((_DWORD)v87 << 8);
  HIDWORD(v51) = (LODWORD(m[13]) + HIDWORD(v40) + v51) ^ v118 ^ *(_DWORD *)v570;
  HIDWORD(v147) = ((m[13]
                  + m[15]
                  + __PAIR64__(v621, v586)
                  + ((2LL * *(_QWORD *)&v576[4]) | (*(_DWORD *)&v576[8] >> 31))
                  + __PAIR64__(v87, v51)) >> 32)
                ^ HIDWORD(v40)
                ^ v643;
  HIDWORD(v586) = LODWORD(m[13]) + HIDWORD(v40) + v51;
  v609 = (m[13]
        + m[15]
        + __PAIR64__(v621, v586)
        + ((2LL * *(_QWORD *)&v576[4]) | (*(_DWORD *)&v576[8] >> 31))
        + __PAIR64__(v87, v51)) >> 32;
  LODWORD(v118) = HIWORD(HIDWORD(v147));
  HIDWORD(v147) = HIWORD(HIDWORD(v51)) | (HIDWORD(v147) << 16);
  HIDWORD(v51) = v118 | (HIDWORD(v51) << 16);
  LODWORD(v147) = (2 * v144) | (HIDWORD(v569) >> 31);
  v149 = __PAIR64__(v41, HIDWORD(v568)) + __PAIR64__(HIDWORD(v51), HIDWORD(v147));
  v150 = (2 * HIDWORD(v569)) | (v144 >> 31);
  *(_DWORD *)&v576[8] = HIDWORD(v568) + HIDWORD(v147);
  LODWORD(v87) = v87 ^ ((__PAIR64__(v41, HIDWORD(v568)) + __PAIR64__(HIDWORD(v51), HIDWORD(v147))) >> 32);
  *(_DWORD *)v570 = (HIDWORD(v568) + HIDWORD(v147)) ^ v51;
  HIDWORD(v568) = LODWORD(m[10]) + v592 + v150;
  LODWORD(v118) = (m[10] + v592 + __PAIR64__(v147, v150)) >> 32;
  HIDWORD(v51) ^= v118;
  HIDWORD(v147) ^= HIDWORD(v568);
  v151 = (v40 + HIDWORD(v51)) ^ v150;
  v152 = __PAIR64__(HIDWORD(v41), v40) + __PAIR64__(HIDWORD(v147), HIDWORD(v51));
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), v40) + __PAIR64__(HIDWORD(v147), HIDWORD(v51))) >> 32;
  LODWORD(v147) = HIDWORD(v41) ^ v147;
  LODWORD(v40) = BYTE3(v147);
  LODWORD(v147) = HIBYTE(v151) | ((_DWORD)v147 << 8);
  v153 = v40 | (v151 << 8);
  v154 = m[14] + __PAIR64__(v118, HIDWORD(v568)) + __PAIR64__(v153, v147);
  HIDWORD(v51) ^= v154;
  HIDWORD(v147) ^= HIDWORD(v154);
  v593 = v154;
  HIDWORD(v154) = HIDWORD(v575);
  LODWORD(v643) = HIWORD(HIDWORD(v51)) | (HIDWORD(v147) << 16);
  HIDWORD(v575) = HIWORD(HIDWORD(v147)) | (HIDWORD(v51) << 16);
  LODWORD(v154) = (2 * v148) | (HIDWORD(v154) >> 31);
  v155 = (2 * HIDWORD(v154)) | (v148 >> 31);
  HIDWORD(v569) = HIDWORD(v575) + __CFADD__((_DWORD)v152, (_DWORD)v643) + HIDWORD(v41);
  *(_DWORD *)v576 = (v152 + v643) ^ v147;
  HIDWORD(v87) = (m[3] + __PAIR64__(v568, *(unsigned int *)&v591[16]) + __PAIR64__(v154, v155)) >> 32;
  LODWORD(v118) = LODWORD(m[3]) + *(_DWORD *)&v591[16] + v155;
  *(_DWORD *)&v576[4] = HIDWORD(v569) ^ v153;
  v156 = __PAIR64__(HIDWORD(v149), *(unsigned int *)&v576[8])
       + __PAIR64__((unsigned int)v118 ^ v627, HIDWORD(v87) ^ *(_DWORD *)&v570[4]);
  LODWORD(v41) = HIDWORD(v156);
  HIDWORD(v154) = v156;
  v157 = (*(_DWORD *)&v576[8] + (HIDWORD(v87) ^ *(_DWORD *)&v570[4])) ^ v155;
  LODWORD(v154) = v154
                ^ ((__PAIR64__(HIDWORD(v149), *(unsigned int *)&v576[8])
                  + __PAIR64__((unsigned int)v118 ^ v627, HIDWORD(v87) ^ *(_DWORD *)&v570[4])) >> 32);
  v158 = BYTE3(v154);
  LODWORD(v154) = HIBYTE(v157) | ((_DWORD)v154 << 8);
  v159 = v158 | (v157 << 8);
  v160 = m[6] + __PAIR64__(HIDWORD(v87), v118) + __PAIR64__(v159, v154);
  LODWORD(v51) = v160 ^ HIDWORD(v87) ^ *(_DWORD *)&v570[4];
  HIDWORD(v41) = v118 ^ v627 ^ HIDWORD(v160);
  HIDWORD(v118) = HIWORD(HIDWORD(v41));
  HIDWORD(v41) = WORD1(v51) | (HIDWORD(v41) << 16);
  LODWORD(v118) = *(_DWORD *)v570;
  HIDWORD(v118) |= (_DWORD)v51 << 16;
  LODWORD(v51) = 2 * v87;
  LODWORD(v568) = HIDWORD(v154) + HIDWORD(v41);
  LODWORD(v87) = (2 * *(_DWORD *)v570) | ((unsigned int)v87 >> 31);
  *(_DWORD *)v570 = HIDWORD(v118) + __CFADD__(HIDWORD(v154), HIDWORD(v41)) + (_DWORD)v41;
  LODWORD(v51) = v51 | ((unsigned int)v118 >> 31);
  *(_DWORD *)&v576[8] = (HIDWORD(v154) + HIDWORD(v41)) ^ v154;
  v161 = m[7] + __PAIR64__(v617, *(unsigned int *)&v591[8]) + __PAIR64__(v51, v87);
  LODWORD(v586) = *(_DWORD *)v570 ^ v159;
  HIDWORD(v87) = (__PAIR64__(v552, *(unsigned int *)&v591[12])
                + __PAIR64__((unsigned int)v161 ^ v574, HIDWORD(v161) ^ (unsigned int)v634)) >> 32;
  LODWORD(v154) = *(_DWORD *)&v591[12] + (HIDWORD(v161) ^ v634);
  LODWORD(v87) = v87 ^ v154;
  LODWORD(v51) = HIDWORD(v87) ^ v51;
  HIDWORD(v147) = BYTE3(v51);
  HIDWORD(v51) = (m[1] + v161) >> 32;
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v154) = HIDWORD(v147) | ((_DWORD)v87 << 8);
  LODWORD(v118) = HIDWORD(v161) ^ v634 ^ (LODWORD(m[1]) + v161 + v51);
  v162 = ((__PAIR64__(HIDWORD(v154), LODWORD(m[1]) + (int)v161) + v51) >> 32) ^ v161 ^ v574;
  *(_DWORD *)&v570[4] = WORD1(v118) | (v162 << 16);
  *(_DWORD *)&v570[8] = HIWORD(v162) | ((_DWORD)v118 << 16);
  *(_QWORD *)&v591[8] = __PAIR64__(HIDWORD(v154), LODWORD(m[1]) + (int)v161) + v51;
  HIDWORD(v51) = *(__int64 *)&v576[12] >> 31;
  v163 = (2 * *(_DWORD *)&v576[12]) | (*(_DWORD *)&v576[16] >> 31);
  v164 = __PAIR64__(HIDWORD(v87), v154) + *(_QWORD *)&v570[4];
  HIDWORD(v87) = (__PAIR64__(HIDWORD(v87), v154) + *(_QWORD *)&v570[4]) >> 32;
  *(_DWORD *)&v576[12] = v164 ^ v51;
  LODWORD(v87) = (m[9] + __PAIR64__(v609, HIDWORD(v586)) + __PAIR64__(HIDWORD(v51), v163)) >> 32;
  LODWORD(v118) = LODWORD(m[9]) + HIDWORD(v586) + v163;
  HIDWORD(v147) = v118 ^ HIDWORD(v643);
  LODWORD(v147) = v87 ^ v575;
  *(_DWORD *)&v576[16] = HIDWORD(v87) ^ HIDWORD(v154);
  v165 = (v569 + (v87 ^ v575)) ^ v163;
  HIDWORD(v154) = v569 + (v87 ^ v575);
  HIDWORD(v51) ^= (__PAIR64__(v604, v569) + v147) >> 32;
  v553 = (__PAIR64__(v604, v569) + v147) >> 32;
  v166 = HIBYTE(v165) | (HIDWORD(v51) << 8);
  v167 = HIBYTE(HIDWORD(v51)) | (v165 << 8);
  LODWORD(v147) = (LODWORD(m[4]) + v118 + v166) ^ v87 ^ v575;
  HIDWORD(v147) = v87 ^ v118 ^ HIDWORD(v643);
  v168 = m[4] + __PAIR64__(v87, v118) + __PAIR64__(v167, v166);
  LODWORD(v87) = HIDWORD(v168);
  HIDWORD(v586) = v168;
  LODWORD(v118) = HIWORD(HIDWORD(v147));
  v605 = v87;
  HIDWORD(v147) = v147 >> 16;
  LODWORD(v147) = v118 | ((_DWORD)v147 << 16);
  v169 = (HIDWORD(v154) + HIDWORD(v147)) ^ v166;
  LODWORD(v87) = (__PAIR64__(v553, HIDWORD(v154)) + __PAIR64__(v147, HIDWORD(v147))) >> 32;
  HIDWORD(v154) += HIDWORD(v147);
  v170 = v87 ^ v167;
  HIDWORD(v51) = 2 * v170;
  v171 = (2 * v169) | (v170 >> 31);
  v172 = HIDWORD(v51) | (v169 >> 31);
  v173 = m[7] + v593 + __PAIR64__(v172, v171);
  HIDWORD(v41) ^= v173;
  HIDWORD(v118) ^= HIDWORD(v173);
  LODWORD(v154) = v164 + HIDWORD(v118);
  v174 = (v164 + HIDWORD(v118)) ^ v171;
  LODWORD(v569) = HIDWORD(v87) + __CFADD__((_DWORD)v164, HIDWORD(v118)) + HIDWORD(v41);
  v175 = v569 ^ v172;
  HIDWORD(v51) = HIBYTE(v175);
  v176 = HIBYTE(v174) | (v175 << 8);
  v177 = HIDWORD(v51) | (v174 << 8);
  HIDWORD(v118) ^= LODWORD(m[9]) + v173 + v176;
  HIDWORD(v41) ^= (m[9] + v173 + __PAIR64__(v177, v176)) >> 32;
  v594 = m[9] + v173 + __PAIR64__(v177, v176);
  HIDWORD(v87) = HIWORD(HIDWORD(v118)) | (HIDWORD(v41) << 16);
  LODWORD(v575) = HIWORD(HIDWORD(v41)) | (HIDWORD(v118) << 16);
  v554 = v154 + HIDWORD(v87);
  v618 = HIDWORD(v87);
  LODWORD(v41) = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[4] >> 31);
  HIDWORD(v118) = *(__int64 *)v576 >> 31;
  LODWORD(v569) = v575 + __CFADD__((_DWORD)v154, HIDWORD(v87)) + (_DWORD)v569;
  *(_DWORD *)v576 = (v154 + HIDWORD(v87)) ^ v176;
  LODWORD(v118) = LODWORD(m[3]) + v160;
  v178 = v118 + __PAIR64__((m[3] + v160) >> 32, v41);
  v96 = __CFADD__(HIDWORD(v154), ((v118 + __PAIR64__((m[3] + v160) >> 32, v41)) >> 32) ^ *(_DWORD *)&v570[8]);
  HIDWORD(v154) += ((v118 + __PAIR64__((m[3] + v160) >> 32, v41)) >> 32) ^ *(_DWORD *)&v570[8];
  LODWORD(v87) = v87 + v96 + ((LODWORD(m[3]) + v160 + v41) ^ *(_DWORD *)&v570[4]);
  LODWORD(v41) = v41 ^ HIDWORD(v154);
  HIDWORD(v118) ^= v87;
  LODWORD(v51) = HIBYTE(HIDWORD(v118));
  *(_DWORD *)&v576[4] = v569 ^ v177;
  HIDWORD(v118) = BYTE3(v41) | (HIDWORD(v118) << 8);
  LODWORD(v41) = v51 | ((_DWORD)v41 << 8);
  v179 = m[1] + v178 + __PAIR64__(v41, HIDWORD(v118));
  v610 = HIDWORD(v179);
  LODWORD(v118) = v179;
  LODWORD(v154) = HIDWORD(v178) ^ *(_DWORD *)&v570[8] ^ v118;
  HIDWORD(v41) = v178
               ^ *(_DWORD *)&v570[4]
               ^ (v41 + __CFADD__(LODWORD(m[1]) + v178, HIDWORD(v118)) + ((m[1] + v178) >> 32));
  *(_DWORD *)&v591[16] = LODWORD(m[1]) + v178 + HIDWORD(v118);
  *(_DWORD *)&v570[8] = WORD1(v154) | (HIDWORD(v41) << 16);
  v622 = HIWORD(HIDWORD(v41)) | ((_DWORD)v154 << 16);
  v180 = (2 * *(_DWORD *)&v576[8]) | ((unsigned int)v586 >> 31);
  LODWORD(v118) = (2 * v586) | (*(_DWORD *)&v576[8] >> 31);
  HIDWORD(v87) = (HIDWORD(v154) + *(_DWORD *)&v570[8]) ^ HIDWORD(v118);
  *(_DWORD *)&v570[4] = v622 + __CFADD__(HIDWORD(v154), *(_DWORD *)&v570[8]) + (_DWORD)v87;
  LODWORD(v586) = HIDWORD(v154) + *(_DWORD *)&v570[8];
  HIDWORD(v51) = (m[13] + *(_QWORD *)&v591[8] + __PAIR64__(v118, v180)) >> 32;
  HIDWORD(v154) = LODWORD(m[13]) + *(_DWORD *)&v591[8] + v180;
  HIDWORD(v147) ^= HIDWORD(v154);
  LODWORD(v147) = HIDWORD(v51) ^ v147;
  v181 = (v152 + v643 + v147) ^ v180;
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v569), (int)v152 + (int)v643) + v147) >> 32;
  LODWORD(v154) = v152 + v643 + v147;
  LODWORD(v118) = v118 ^ HIDWORD(v41);
  HIDWORD(v118) = BYTE3(v118);
  LODWORD(v118) = HIBYTE(v181) | ((_DWORD)v118 << 8);
  v182 = HIDWORD(v118) | (v181 << 8);
  v183 = m[12] + __PAIR64__(HIDWORD(v51), HIDWORD(v154)) + __PAIR64__(v182, v118);
  v184 = v183 ^ v147;
  HIDWORD(v568) = v184 >> 16;
  HIDWORD(v569) = HIWORD(HIDWORD(v184)) | ((_DWORD)v184 << 16);
  v96 = __CFADD__((_DWORD)v154, HIDWORD(v568));
  LODWORD(v154) = v154 + HIDWORD(v568);
  HIDWORD(v41) += v96 + HIDWORD(v569);
  v185 = HIDWORD(v41) ^ v182;
  *(_DWORD *)&v576[8] = v154 ^ v118;
  v186 = m[11] + __PAIR64__(v605, HIDWORD(v586)) + ((2LL * *(_QWORD *)&v576[12]) | (*(_DWORD *)&v576[16] >> 31));
  LODWORD(v87) = ((2 * *(_DWORD *)&v576[12]) | (*(_DWORD *)&v576[16] >> 31)) ^ (v568 + (HIDWORD(v186) ^ HIDWORD(v575)));
  LODWORD(v51) = ((__PAIR64__(*(unsigned int *)v570, v568)
                 + __PAIR64__((unsigned int)v186 ^ (unsigned int)v643, HIDWORD(v186) ^ HIDWORD(v575))) >> 32)
               ^ (*(__int64 *)&v576[12] >> 31);
  LODWORD(v118) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  LODWORD(v87) = v118 | ((_DWORD)v87 << 8);
  HIDWORD(v51) = (LODWORD(m[14])
                + LODWORD(m[11])
                + HIDWORD(v586)
                + ((2 * *(_DWORD *)&v576[12]) | (*(_DWORD *)&v576[16] >> 31))
                + v51)
               ^ HIDWORD(v186)
               ^ HIDWORD(v575);
  *(_DWORD *)&v576[16] = LODWORD(m[14])
                       + LODWORD(m[11])
                       + HIDWORD(v586)
                       + ((2 * *(_DWORD *)&v576[12]) | (*(_DWORD *)&v576[16] >> 31))
                       + v51;
  HIDWORD(v184) = ((m[14] + v186 + __PAIR64__(v87, v51)) >> 32) ^ v186 ^ v643;
  HIDWORD(v586) = (m[14] + v186 + __PAIR64__(v87, v51)) >> 32;
  LODWORD(v118) = HIWORD(HIDWORD(v184));
  HIDWORD(v184) = HIWORD(HIDWORD(v51)) | (HIDWORD(v184) << 16);
  HIDWORD(v51) = v118 | (HIDWORD(v51) << 16);
  v187 = (2 * HIDWORD(v87)) | ((*(_DWORD *)&v570[4] ^ (unsigned int)v41) >> 31);
  LODWORD(v184) = (2 * (*(_DWORD *)&v570[4] ^ v41)) | (HIDWORD(v87) >> 31);
  LODWORD(v41) = (__PAIR64__(*(unsigned int *)v570, v568)
                + __PAIR64__((unsigned int)v186 ^ (unsigned int)v643, HIDWORD(v186) ^ HIDWORD(v575))
                + __PAIR64__(HIDWORD(v51), HIDWORD(v184))) >> 32;
  LODWORD(v568) = v568 + (HIDWORD(v186) ^ HIDWORD(v575)) + HIDWORD(v184);
  LODWORD(v87) = v87 ^ v41;
  HIDWORD(v575) = v568 ^ v51;
  LODWORD(v118) = (m[2] + v594 + __PAIR64__(v184, v187)) >> 32;
  HIDWORD(v184) ^= LODWORD(m[2]) + v594 + v187;
  HIDWORD(v51) ^= v118;
  HIDWORD(v154) = LODWORD(m[2]) + v594 + v187;
  v188 = __PAIR64__(HIDWORD(v41), v154) + __PAIR64__(HIDWORD(v184), HIDWORD(v51));
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), v154) + __PAIR64__(HIDWORD(v184), HIDWORD(v51))) >> 32;
  v189 = v188 ^ v187;
  LODWORD(v184) = HIDWORD(v41) ^ v184;
  LODWORD(v154) = BYTE3(v184);
  LODWORD(v184) = HIBYTE(v189) | ((_DWORD)v184 << 8);
  v190 = v154 | (v189 << 8);
  HIDWORD(v51) ^= LODWORD(m[6]) + HIDWORD(v154) + v184;
  HIDWORD(v184) ^= (m[6] + __PAIR64__(v118, HIDWORD(v154)) + __PAIR64__(v190, v184)) >> 32;
  v595 = m[6] + __PAIR64__(v118, HIDWORD(v154)) + __PAIR64__(v190, v184);
  *(_DWORD *)v570 = HIWORD(HIDWORD(v51)) | (HIDWORD(v184) << 16);
  LODWORD(v154) = 2 * v185;
  v191 = (2 * *(_DWORD *)&v576[8]) | (v185 >> 31);
  LODWORD(v154) = v154 | (*(_DWORD *)&v576[8] >> 31);
  v192 = __PAIR64__(v610, *(unsigned int *)&v591[16]);
  v628 = HIWORD(HIDWORD(v184)) | (HIDWORD(v51) << 16);
  HIDWORD(v154) = v628 + __CFADD__((_DWORD)v188, *(_DWORD *)v570) + HIDWORD(v41);
  *(_QWORD *)&v591[16] = __PAIR64__(HIDWORD(v154), (int)v188 + *(_DWORD *)v570);
  HIDWORD(v87) = (m[5] + v192) >> 32;
  LODWORD(v192) = LODWORD(m[5]) + v192;
  v96 = __CFADD__((_DWORD)v192, v191);
  LODWORD(v192) = v192 + v191;
  *(_DWORD *)&v576[8] = (v188 + *(_DWORD *)v570) ^ v184;
  HIDWORD(v87) += v96 + (_DWORD)v154;
  LODWORD(v184) = v192 ^ v618;
  LODWORD(v51) = HIDWORD(v87) ^ v575;
  LODWORD(v575) = HIDWORD(v154) ^ v190;
  HIDWORD(v154) = v568 + v51;
  v193 = (v568 + v51) ^ v191;
  LODWORD(v41) = v41 + __CFADD__((_DWORD)v568, (_DWORD)v51) + (v192 ^ v618);
  v194 = m[10] + __PAIR64__(HIDWORD(v87), v192);
  LODWORD(v154) = v154 ^ v41;
  v195 = BYTE3(v154);
  LODWORD(v154) = HIBYTE(v193) | ((_DWORD)v154 << 8);
  v196 = v195 | (v193 << 8);
  LODWORD(v51) = (LODWORD(m[10]) + v192 + v154) ^ v51;
  HIDWORD(v87) = v196
               + __CFADD__(LODWORD(m[10]) + v192, (_DWORD)v154)
               + ((m[10] + __PAIR64__(HIDWORD(v87), v192)) >> 32);
  v611 = __PAIR64__(HIDWORD(v87), (int)v194 + (int)v154);
  HIDWORD(v41) = WORD1(v51) | (((unsigned int)v184 ^ HIDWORD(v87)) << 16);
  HIDWORD(v192) = (((unsigned int)v184 ^ HIDWORD(v87)) >> 16) | ((_DWORD)v51 << 16);
  LODWORD(v51) = (2 * v87) | (HIDWORD(v575) >> 31);
  LODWORD(v87) = (2 * HIDWORD(v575)) | ((unsigned int)v87 >> 31);
  LODWORD(v568) = HIDWORD(v192) + __CFADD__(HIDWORD(v154), HIDWORD(v41)) + (_DWORD)v41;
  HIDWORD(v575) = (HIDWORD(v154) + HIDWORD(v41)) ^ v154;
  v197 = m[4] + v183 + __PAIR64__(v51, v87);
  *(_DWORD *)&v591[8] = HIDWORD(v154) + HIDWORD(v41);
  *(_DWORD *)&v576[12] = v568 ^ v196;
  HIDWORD(v87) = (__PAIR64__(v569, v554)
                + __PAIR64__((unsigned int)v197 ^ *(_DWORD *)&v570[8], HIDWORD(v197) ^ (unsigned int)v622)) >> 32;
  LODWORD(v154) = v554 + (HIDWORD(v197) ^ v622);
  LODWORD(v87) = v87 ^ v154;
  LODWORD(v51) = HIDWORD(v87) ^ v51;
  HIDWORD(v184) = BYTE3(v51);
  HIDWORD(v51) = (m[0] + v197) >> 32;
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v154) = HIDWORD(v184) | ((_DWORD)v87 << 8);
  *(_DWORD *)&v591[12] = LODWORD(m[0]) + v197 + v51;
  LODWORD(v184) = HIDWORD(v197) ^ v622 ^ *(_DWORD *)&v591[12];
  v198 = ((__PAIR64__(HIDWORD(v154), LODWORD(m[0]) + (int)v197) + v51) >> 32) ^ v197 ^ *(_DWORD *)&v570[8];
  v623 = (__PAIR64__(HIDWORD(v154), LODWORD(m[0]) + (int)v197) + v51) >> 32;
  LODWORD(v569) = WORD1(v184) | (v198 << 16);
  *(_DWORD *)&v570[8] = HIWORD(v198) | ((_DWORD)v184 << 16);
  HIDWORD(v51) = *(__int64 *)v576 >> 31;
  v199 = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[4] >> 31);
  v96 = __CFADD__((_DWORD)v154, (_DWORD)v569);
  LODWORD(v154) = v154 + v569;
  HIDWORD(v87) += v96 + *(_DWORD *)&v570[8];
  *(_DWORD *)v576 = v154 ^ v51;
  *(_DWORD *)&v576[4] = HIDWORD(v87) ^ HIDWORD(v154);
  v200 = m[15] + __PAIR64__(HIDWORD(v586), *(unsigned int *)&v576[16]) + __PAIR64__(HIDWORD(v51), v199);
  HIDWORD(v184) = v200 ^ HIDWORD(v568);
  LODWORD(v184) = HIDWORD(v200) ^ HIDWORD(v569);
  v201 = (v586 + (HIDWORD(v200) ^ HIDWORD(v569))) ^ v199;
  HIDWORD(v154) = v586 + (HIDWORD(v200) ^ HIDWORD(v569));
  v555 = (__PAIR64__(*(unsigned int *)&v570[4], v586) + v184) >> 32;
  HIDWORD(v51) ^= v555;
  v202 = HIBYTE(v201) | (HIDWORD(v51) << 8);
  v203 = HIBYTE(HIDWORD(v51)) | (v201 << 8);
  v204 = m[8] + v200 + __PAIR64__(v203, v202);
  LODWORD(v184) = v204 ^ HIDWORD(v200) ^ HIDWORD(v569);
  HIDWORD(v184) = HIDWORD(v204) ^ v200 ^ HIDWORD(v568);
  LODWORD(v192) = HIWORD(HIDWORD(v184));
  HIDWORD(v184) = v184 >> 16;
  LODWORD(v184) = v192 | ((_DWORD)v184 << 16);
  v205 = (HIDWORD(v154) + HIDWORD(v184)) ^ v202;
  LODWORD(v192) = (__PAIR64__(v555, HIDWORD(v154)) + __PAIR64__(v184, HIDWORD(v184))) >> 32;
  HIDWORD(v154) += HIDWORD(v184);
  v206 = v192 ^ v203;
  *(_DWORD *)&v570[4] = v192;
  HIDWORD(v51) = 2 * v206;
  v207 = (2 * v205) | (v206 >> 31);
  v208 = HIDWORD(v51) | (v205 >> 31);
  v209 = m[9] + v595 + __PAIR64__(v208, v207);
  HIDWORD(v41) ^= v209;
  HIDWORD(v192) ^= HIDWORD(v209);
  v96 = __CFADD__((_DWORD)v154, HIDWORD(v192));
  LODWORD(v154) = v154 + HIDWORD(v192);
  HIDWORD(v87) += v96 + HIDWORD(v41);
  v210 = v154 ^ v207;
  v211 = HIDWORD(v87) ^ v208;
  HIDWORD(v51) = HIBYTE(v211);
  v212 = HIBYTE(v210) | (v211 << 8);
  v213 = HIDWORD(v51) | (v210 << 8);
  HIDWORD(v192) ^= LODWORD(m[0]) + v209 + v212;
  HIDWORD(v41) ^= (m[0] + v209 + __PAIR64__(v213, v212)) >> 32;
  v596 = m[0] + v209 + __PAIR64__(v213, v212);
  HIDWORD(v569) = HIWORD(HIDWORD(v192)) | (HIDWORD(v41) << 16);
  LODWORD(v51) = HIWORD(HIDWORD(v41)) | (HIDWORD(v192) << 16);
  LODWORD(v41) = (2 * *(_DWORD *)&v576[8]) | ((unsigned int)v575 >> 31);
  HIDWORD(v192) = (2 * v575) | (*(_DWORD *)&v576[8] >> 31);
  v635 = v51;
  v556 = v154 + HIDWORD(v569);
  HIDWORD(v568) = v51 + __CFADD__((_DWORD)v154, HIDWORD(v569)) + HIDWORD(v87);
  *(_DWORD *)&v576[8] = (v154 + HIDWORD(v569)) ^ v212;
  LODWORD(v192) = LODWORD(m[5]) + v611;
  HIDWORD(v87) = (v192 + __PAIR64__((m[5] + v611) >> 32, v41)) >> 32;
  LODWORD(v192) = LODWORD(m[5]) + v611 + v41;
  v96 = __CFADD__(HIDWORD(v154), HIDWORD(v87) ^ *(_DWORD *)&v570[8]);
  HIDWORD(v154) += HIDWORD(v87) ^ *(_DWORD *)&v570[8];
  LODWORD(v87) = *(_DWORD *)&v570[4] + v96 + (v192 ^ v569);
  LODWORD(v41) = v41 ^ HIDWORD(v154);
  HIDWORD(v192) ^= v87;
  LODWORD(v51) = HIBYTE(HIDWORD(v192));
  *(_DWORD *)&v576[16] = HIDWORD(v568) ^ v213;
  HIDWORD(v192) = BYTE3(v41) | (HIDWORD(v192) << 8);
  LODWORD(v41) = v51 | ((_DWORD)v41 << 8);
  *(_QWORD *)v612 = m[7] + __PAIR64__(HIDWORD(v87), v192) + __PAIR64__(v41, HIDWORD(v192));
  LODWORD(v154) = HIDWORD(v87) ^ *(_DWORD *)&v570[8] ^ *(_DWORD *)v612;
  HIDWORD(v41) = v192 ^ v569 ^ *(_DWORD *)&v612[4];
  *(_DWORD *)&v570[4] = WORD1(v154) | (HIDWORD(v41) << 16);
  *(_DWORD *)&v570[8] = HIWORD(HIDWORD(v41)) | ((_DWORD)v154 << 16);
  v96 = __CFADD__(HIDWORD(v154), *(_DWORD *)&v570[4]);
  v214 = HIDWORD(v154) + *(_DWORD *)&v570[4];
  v215 = (2 * HIDWORD(v575)) | (*(_DWORD *)&v576[12] >> 31);
  HIDWORD(v154) = (2 * *(_DWORD *)&v576[12]) | (HIDWORD(v575) >> 31);
  LODWORD(v569) = v214;
  LODWORD(v154) = *(_DWORD *)&v591[12];
  *(_DWORD *)&v591[12] = *(_DWORD *)&v570[8] + v96 + (_DWORD)v87;
  v216 = *(_DWORD *)&v591[12] ^ v41;
  HIDWORD(v87) = v569 ^ HIDWORD(v192);
  v217 = m[2] + __PAIR64__(v623, v154) + __PAIR64__(HIDWORD(v154), v215);
  LODWORD(v184) = HIDWORD(v217) ^ v184;
  HIDWORD(v184) ^= v217;
  HIDWORD(v41) = (unsigned __int64)(*(_QWORD *)&v591[16] + v184) >> 32;
  LODWORD(v154) = *(_DWORD *)&v591[16] + v184;
  v218 = (*(_DWORD *)&v591[16] + v184) ^ v215;
  HIDWORD(v154) ^= HIDWORD(v41);
  LODWORD(v41) = HIBYTE(v218) | (HIDWORD(v154) << 8);
  v219 = HIBYTE(HIDWORD(v154)) | (v218 << 8);
  v220 = m[4] + v217 + __PAIR64__(v219, v41);
  *(_DWORD *)&v591[20] = HIDWORD(v220);
  LODWORD(v192) = v220;
  LODWORD(v184) = v192 ^ v184;
  HIDWORD(v184) ^= v219 + __CFADD__(LODWORD(m[4]) + v217, (_DWORD)v41) + ((m[4] + v217) >> 32);
  *(_DWORD *)&v591[16] = LODWORD(m[4]) + v217 + v41;
  LODWORD(v575) = v184 >> 16;
  HIDWORD(v575) = HIWORD(HIDWORD(v184)) | ((_DWORD)v184 << 16);
  LODWORD(v87) = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[4] >> 31);
  LODWORD(v51) = *(__int64 *)v576 >> 31;
  v221 = __PAIR64__(HIDWORD(v41), v154) + v575;
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), v154) + v575) >> 32;
  *(_DWORD *)v576 = v221 ^ v41;
  v222 = HIDWORD(v41) ^ v219;
  LODWORD(v192) = (m[10] + v204 + __PAIR64__(v51, v87)) >> 32;
  HIDWORD(v192) = LODWORD(m[10]) + v204 + v87;
  HIDWORD(v184) = HIDWORD(v192) ^ *(_DWORD *)v570;
  LODWORD(v87) = v87 ^ (*(_DWORD *)&v591[8] + (v192 ^ v628));
  HIDWORD(v154) = *(_DWORD *)&v591[8] + (v192 ^ v628);
  LODWORD(v51) = ((__PAIR64__(v568, *(unsigned int *)&v591[8])
                 + __PAIR64__(HIDWORD(v192) ^ *(_DWORD *)v570, (unsigned int)v192 ^ v628)) >> 32)
               ^ v51;
  *(_DWORD *)v570 = (__PAIR64__(v568, *(unsigned int *)&v591[8])
                   + __PAIR64__(HIDWORD(v192) ^ *(_DWORD *)v570, (unsigned int)v192 ^ v628)) >> 32;
  LODWORD(v41) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  LODWORD(v87) = v41 | ((_DWORD)v87 << 8);
  HIDWORD(v51) = (LODWORD(m[15]) + HIDWORD(v192) + v51) ^ v192 ^ v628;
  v223 = m[15] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v87, v51);
  HIDWORD(v192) = HIDWORD(v223);
  *(_DWORD *)&v591[8] = v223;
  HIDWORD(v184) ^= HIDWORD(v192);
  v624 = HIDWORD(v192);
  LODWORD(v192) = HIWORD(HIDWORD(v184));
  LODWORD(v184) = (2 * v216) | (HIDWORD(v87) >> 31);
  HIDWORD(v184) = HIWORD(HIDWORD(v51)) | (HIDWORD(v184) << 16);
  HIDWORD(v51) = v192 | (HIDWORD(v51) << 16);
  v224 = (2 * HIDWORD(v87)) | (v216 >> 31);
  LODWORD(v41) = (__PAIR64__(*(unsigned int *)v570, HIDWORD(v154)) + __PAIR64__(HIDWORD(v51), HIDWORD(v184))) >> 32;
  HIDWORD(v154) += HIDWORD(v184);
  LODWORD(v87) = v87 ^ v41;
  *(_DWORD *)&v576[4] = HIDWORD(v154) ^ v51;
  LODWORD(v192) = (m[14] + v596 + __PAIR64__(v184, v224)) >> 32;
  HIDWORD(v192) = LODWORD(m[14]) + v596 + v224;
  HIDWORD(v184) ^= HIDWORD(v192);
  HIDWORD(v51) ^= v192;
  v225 = __PAIR64__(HIDWORD(v41), v221) + __PAIR64__(HIDWORD(v184), HIDWORD(v51));
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), v221) + __PAIR64__(HIDWORD(v184), HIDWORD(v51))) >> 32;
  v226 = v225 ^ v224;
  LODWORD(v184) = HIDWORD(v41) ^ v184;
  LODWORD(v154) = BYTE3(v184);
  LODWORD(v184) = HIBYTE(v226) | ((_DWORD)v184 << 8);
  HIDWORD(v51) ^= LODWORD(m[1]) + HIDWORD(v192) + v184;
  LODWORD(v596) = LODWORD(m[1]) + HIDWORD(v192) + v184;
  v227 = v154 | (v226 << 8);
  LODWORD(v192) = v227
                + __CFADD__(LODWORD(m[1]) + HIDWORD(v192), (_DWORD)v184)
                + ((m[1] + __PAIR64__(v192, HIDWORD(v192))) >> 32);
  HIDWORD(v184) ^= v192;
  HIDWORD(v596) = v192;
  *(_DWORD *)v570 = HIWORD(HIDWORD(v51)) | (HIDWORD(v184) << 16);
  LODWORD(v192) = *(_DWORD *)v576;
  *(_DWORD *)v576 = HIWORD(HIDWORD(v184)) | (HIDWORD(v51) << 16);
  LODWORD(v154) = (2 * v222) | ((unsigned int)v192 >> 31);
  v228 = (2 * v192) | (v222 >> 31);
  LODWORD(v568) = *(_DWORD *)v576 + __CFADD__((_DWORD)v225, *(_DWORD *)v570) + HIDWORD(v41);
  *(_DWORD *)&v576[12] = (v225 + *(_DWORD *)v570) ^ v184;
  HIDWORD(v87) = (m[11] + *(_QWORD *)v612 + __PAIR64__(v154, v228)) >> 32;
  LODWORD(v192) = LODWORD(m[11]) + *(_DWORD *)v612 + v228;
  v229 = (HIDWORD(v154) + (HIDWORD(v87) ^ v635)) ^ v228;
  LODWORD(v184) = (__PAIR64__(v41, HIDWORD(v154)) + __PAIR64__((unsigned int)v192 ^ HIDWORD(v569), HIDWORD(v87) ^ v635)) >> 32;
  HIDWORD(v154) += HIDWORD(v87) ^ v635;
  LODWORD(v154) = v154 ^ v184;
  LODWORD(v586) = v568 ^ v227;
  v230 = BYTE3(v154);
  LODWORD(v154) = HIBYTE(v229) | ((_DWORD)v154 << 8);
  v231 = v230 | (v229 << 8);
  v232 = m[12] + __PAIR64__(HIDWORD(v87), v192) + __PAIR64__(v231, v154);
  LODWORD(v51) = v232 ^ HIDWORD(v87) ^ v635;
  HIDWORD(v41) = v192 ^ HIDWORD(v569) ^ HIDWORD(v232);
  HIDWORD(v192) = HIWORD(HIDWORD(v41));
  HIDWORD(v41) = WORD1(v51) | (HIDWORD(v41) << 16);
  HIDWORD(v192) |= (_DWORD)v51 << 16;
  v96 = __CFADD__(HIDWORD(v154), HIDWORD(v41));
  v233 = HIDWORD(v154) + HIDWORD(v41);
  HIDWORD(v154) = *(_DWORD *)&v591[16];
  LODWORD(v51) = (2 * v87) | (*(_DWORD *)&v576[4] >> 31);
  LODWORD(v87) = (2 * *(_DWORD *)&v576[4]) | ((unsigned int)v87 >> 31);
  *(_DWORD *)&v591[16] = v233;
  HIDWORD(v569) = HIDWORD(v192) + v96 + (_DWORD)v184;
  *(_DWORD *)&v576[4] = v233 ^ v154;
  v234 = (LODWORD(m[6]) + HIDWORD(v154) + v87) ^ *(_DWORD *)&v570[4];
  v235 = m[6] + __PAIR64__(*(unsigned int *)&v591[20], HIDWORD(v154)) + __PAIR64__(v51, v87);
  HIDWORD(v586) = HIDWORD(v569) ^ v231;
  LODWORD(v87) = v87 ^ (v556 + (HIDWORD(v235) ^ *(_DWORD *)&v570[8]));
  HIDWORD(v184) = (__PAIR64__(HIDWORD(v568), v556) + __PAIR64__(v234, HIDWORD(v235) ^ *(_DWORD *)&v570[8])) >> 32;
  LODWORD(v51) = HIDWORD(v184) ^ v51;
  HIDWORD(v87) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v51) = (m[8] + v235) >> 32;
  HIDWORD(v154) = HIDWORD(v87) | ((_DWORD)v87 << 8);
  LODWORD(v41) = HIDWORD(v235) ^ *(_DWORD *)&v570[8] ^ (LODWORD(m[8]) + v235 + v51);
  v236 = __PAIR64__(HIDWORD(v154), LODWORD(m[8]) + (int)v235) + v51;
  v237 = ((__PAIR64__(HIDWORD(v154), LODWORD(m[8]) + (int)v235) + v51) >> 32) ^ v234;
  v636 = (__PAIR64__(HIDWORD(v154), LODWORD(m[8]) + (int)v235) + v51) >> 32;
  *(_DWORD *)&v570[4] = WORD1(v41) | (v237 << 16);
  LODWORD(v643) = HIWORD(v237) | ((_DWORD)v41 << 16);
  v238 = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)&v576[16] >> 31);
  LODWORD(v154) = v556 + (HIDWORD(v235) ^ *(_DWORD *)&v570[8]) + *(_DWORD *)&v570[4];
  v557 = (__PAIR64__(HIDWORD(v184), v556 + (HIDWORD(v235) ^ *(_DWORD *)&v570[8]))
        + __PAIR64__(v643, *(unsigned int *)&v570[4])) >> 32;
  HIDWORD(v51) = (2 * *(_DWORD *)&v576[16]) | (*(_DWORD *)&v576[8] >> 31);
  *(_DWORD *)&v576[8] = v154 ^ v51;
  LODWORD(v41) = (m[3] + __PAIR64__(v624, *(unsigned int *)&v591[8]) + __PAIR64__(HIDWORD(v51), v238)) >> 32;
  HIDWORD(v568) = LODWORD(m[3]) + *(_DWORD *)&v591[8] + v238;
  HIDWORD(v184) = HIDWORD(v568) ^ v575;
  *(_DWORD *)&v576[16] = v557 ^ HIDWORD(v154);
  LODWORD(v184) = v41 ^ HIDWORD(v575);
  v239 = (v569 + (v41 ^ HIDWORD(v575))) ^ v238;
  LODWORD(v87) = (__PAIR64__(*(unsigned int *)&v591[12], v569) + v184) >> 32;
  HIDWORD(v154) = v569 + (v41 ^ HIDWORD(v575));
  HIDWORD(v51) ^= v87;
  v240 = HIBYTE(v239) | (HIDWORD(v51) << 8);
  v241 = HIBYTE(HIDWORD(v51)) | (v239 << 8);
  v242 = m[13] + __PAIR64__(v41, HIDWORD(v568)) + __PAIR64__(v241, v240);
  LODWORD(v184) = v242 ^ v41 ^ HIDWORD(v575);
  HIDWORD(v184) = HIDWORD(v242) ^ HIDWORD(v568) ^ v575;
  LODWORD(v192) = HIWORD(HIDWORD(v184));
  HIDWORD(v184) = v184 >> 16;
  LODWORD(v184) = v192 | ((_DWORD)v184 << 16);
  v243 = (HIDWORD(v154) + HIDWORD(v184)) ^ v240;
  v244 = __PAIR64__(v87, HIDWORD(v154)) + __PAIR64__(v184, HIDWORD(v184));
  LODWORD(v87) = (__PAIR64__(v87, HIDWORD(v154)) + __PAIR64__(v184, HIDWORD(v184))) >> 32;
  v245 = v87 ^ v241;
  HIDWORD(v51) = 2 * v245;
  v246 = (2 * v243) | (v245 >> 31);
  v247 = HIDWORD(v51) | (v243 >> 31);
  HIDWORD(v41) ^= LODWORD(m[2]) + v596 + v246;
  LODWORD(v41) = (m[2] + v596 + __PAIR64__(v247, v246)) >> 32;
  v96 = __CFADD__((_DWORD)v154, HIDWORD(v192) ^ v41);
  LODWORD(v154) = v154 + (HIDWORD(v192) ^ v41);
  LODWORD(v192) = LODWORD(m[2]) + v596 + v246;
  v248 = v154 ^ v246;
  v249 = (v557 + v96 + HIDWORD(v41)) ^ v247;
  HIDWORD(v51) = HIBYTE(v249);
  v250 = HIBYTE(v248) | (v249 << 8);
  v251 = HIDWORD(v51) | (v248 << 8);
  v252 = m[12] + __PAIR64__(v41, v192) + __PAIR64__(v251, v250);
  HIDWORD(v41) ^= HIDWORD(v252);
  HIDWORD(v192) ^= v41 ^ (unsigned int)v252;
  *(_DWORD *)&v570[8] = HIWORD(HIDWORD(v192)) | (HIDWORD(v41) << 16);
  LODWORD(v575) = HIWORD(HIDWORD(v41)) | (HIDWORD(v192) << 16);
  LODWORD(v41) = (2 * *(_DWORD *)&v576[12]) | ((unsigned int)v586 >> 31);
  HIDWORD(v192) = (2 * v586) | (*(_DWORD *)&v576[12] >> 31);
  v558 = v154 + *(_DWORD *)&v570[8];
  HIDWORD(v568) = v154 + *(_DWORD *)&v570[8];
  *(_DWORD *)&v576[12] = (v154 + *(_DWORD *)&v570[8]) ^ v250;
  LODWORD(v192) = LODWORD(m[6]) + v232;
  HIDWORD(v87) = (v192 + __PAIR64__((m[6] + v232) >> 32, v41)) >> 32;
  LODWORD(v192) = LODWORD(m[6]) + v232 + v41;
  LODWORD(v586) = (v154 + *(_DWORD *)&v570[8]) ^ v251;
  HIDWORD(v154) = v244 + (v643 ^ HIDWORD(v87));
  LODWORD(v87) = v87 + __CFADD__((_DWORD)v244, v643 ^ HIDWORD(v87)) + (v192 ^ *(_DWORD *)&v570[4]);
  LODWORD(v41) = v41 ^ HIDWORD(v154);
  HIDWORD(v51) = HIDWORD(v192) ^ v87;
  HIDWORD(v192) = BYTE3(v41) | ((HIDWORD(v192) ^ (unsigned int)v87) << 8);
  LODWORD(v41) = HIBYTE(HIDWORD(v51)) | ((_DWORD)v41 << 8);
  v253 = m[10] + __PAIR64__(HIDWORD(v87), v192) + __PAIR64__(v41, HIDWORD(v192));
  HIDWORD(v41) = v192 ^ *(_DWORD *)&v570[4] ^ HIDWORD(v253);
  *(_DWORD *)&v570[4] = (((unsigned int)v643 ^ HIDWORD(v87) ^ (unsigned int)v253) >> 16) | (HIDWORD(v41) << 16);
  LODWORD(v643) = HIWORD(HIDWORD(v41)) | (((unsigned int)v643 ^ HIDWORD(v87) ^ (unsigned int)v253) << 16);
  v254 = (2 * *(_DWORD *)&v576[4]) | (HIDWORD(v586) >> 31);
  v96 = __CFADD__(HIDWORD(v154), *(_DWORD *)&v570[4]);
  v255 = HIDWORD(v154) + *(_DWORD *)&v570[4];
  HIDWORD(v154) = (2 * HIDWORD(v586)) | (*(_DWORD *)&v576[4] >> 31);
  HIDWORD(v586) = v255;
  v256 = (v643 + v96 + (_DWORD)v87) ^ v41;
  *(_DWORD *)&v591[20] = v643 + v96 + (_DWORD)v87;
  HIDWORD(v87) = HIDWORD(v586) ^ HIDWORD(v192);
  v257 = m[0] + __PAIR64__(v636, v236) + __PAIR64__(HIDWORD(v154), v254);
  HIDWORD(v184) ^= v257;
  LODWORD(v184) = HIDWORD(v257) ^ v184;
  v258 = (v225 + *(_DWORD *)v570 + v184) ^ v254;
  HIDWORD(v41) = (__PAIR64__(v568, (int)v225 + *(_DWORD *)v570) + v184) >> 32;
  LODWORD(v154) = v225 + *(_DWORD *)v570 + v184;
  HIDWORD(v154) ^= HIDWORD(v41);
  LODWORD(v41) = HIBYTE(v258) | (HIDWORD(v154) << 8);
  v259 = HIBYTE(HIDWORD(v154)) | (v258 << 8);
  v260 = (m[11] + v257 + __PAIR64__(v259, v41)) ^ v184;
  v629 = (m[11] + v257 + __PAIR64__(v259, v41)) >> 32;
  *(_DWORD *)v612 = LODWORD(m[11]) + v257 + v41;
  HIDWORD(v575) = v260 >> 16;
  *(_DWORD *)&v576[4] = HIWORD(HIDWORD(v260)) | ((_DWORD)v260 << 16);
  LODWORD(v51) = (2 * *(_DWORD *)&v576[16]) | (*(_DWORD *)&v576[8] >> 31);
  v96 = __CFADD__((_DWORD)v154, HIDWORD(v575));
  LODWORD(v154) = v154 + HIDWORD(v575);
  HIDWORD(v41) += v96 + *(_DWORD *)&v576[4];
  LODWORD(v87) = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)&v576[16] >> 31);
  LODWORD(v569) = v154 ^ v41;
  v261 = HIDWORD(v41) ^ v259;
  LODWORD(v192) = (m[8] + v242 + __PAIR64__(v51, v87)) >> 32;
  HIDWORD(v192) = LODWORD(m[8]) + v242 + v87;
  HIDWORD(v260) = HIDWORD(v192) ^ *(_DWORD *)v570;
  LODWORD(v87) = v87 ^ (*(_DWORD *)&v591[16] + (v192 ^ *(_DWORD *)v576));
  *(_DWORD *)v570 = *(_DWORD *)&v591[16] + (v192 ^ *(_DWORD *)v576);
  LODWORD(v41) = (__PAIR64__(HIDWORD(v569), *(unsigned int *)&v591[16])
                + __PAIR64__(HIDWORD(v260), (unsigned int)v192 ^ *(_DWORD *)v576)) >> 32;
  LODWORD(v51) = v41 ^ v51;
  HIDWORD(v154) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v51) = (LODWORD(m[3]) + HIDWORD(v192) + v51) ^ v192 ^ *(_DWORD *)v576;
  *(_DWORD *)&v576[16] = LODWORD(m[3]) + HIDWORD(v192) + v51;
  LODWORD(v87) = HIDWORD(v154) | ((_DWORD)v87 << 8);
  LODWORD(v192) = v87
                + __CFADD__(LODWORD(m[3]) + HIDWORD(v192), (_DWORD)v51)
                + ((m[3] + __PAIR64__(v192, HIDWORD(v192))) >> 32);
  HIDWORD(v260) ^= v192;
  *(_DWORD *)&v591[8] = v192;
  LODWORD(v192) = HIWORD(HIDWORD(v260));
  HIDWORD(v260) = HIWORD(HIDWORD(v51)) | (HIDWORD(v260) << 16);
  LODWORD(v260) = (2 * v256) | (HIDWORD(v87) >> 31);
  HIDWORD(v51) = v192 | (HIDWORD(v51) << 16);
  v262 = (2 * HIDWORD(v87)) | (v256 >> 31);
  v263 = __PAIR64__(v41, *(unsigned int *)v570) + __PAIR64__(HIDWORD(v51), HIDWORD(v260));
  LODWORD(v41) = (__PAIR64__(v41, *(unsigned int *)v570) + __PAIR64__(HIDWORD(v51), HIDWORD(v260))) >> 32;
  HIDWORD(v569) = v263 ^ v51;
  LODWORD(v87) = v87 ^ v41;
  LODWORD(v192) = (m[4] + v252 + __PAIR64__(v260, v262)) >> 32;
  HIDWORD(v192) = LODWORD(m[4]) + v252 + v262;
  HIDWORD(v260) ^= HIDWORD(v192);
  HIDWORD(v51) ^= v192;
  v264 = __PAIR64__(HIDWORD(v41), v154) + __PAIR64__(HIDWORD(v260), HIDWORD(v51));
  LODWORD(v154) = (__PAIR64__(HIDWORD(v41), v154) + __PAIR64__(HIDWORD(v260), HIDWORD(v51))) >> 32;
  v265 = v264 ^ v262;
  LODWORD(v260) = v154 ^ v260;
  *(_DWORD *)v570 = v154;
  v266 = m[13] + __PAIR64__(v192, HIDWORD(v192));
  LODWORD(v192) = (m[13] + __PAIR64__(v192, HIDWORD(v192))) >> 32;
  LODWORD(v154) = BYTE3(v260);
  LODWORD(v260) = HIBYTE(v265) | ((_DWORD)v260 << 8);
  v267 = v154 | (v265 << 8);
  HIDWORD(v51) ^= v266 + (_DWORD)v260;
  LODWORD(v596) = v266 + v260;
  HIDWORD(v260) ^= v267 + __CFADD__((_DWORD)v266, (_DWORD)v260) + (_DWORD)v192;
  HIDWORD(v596) = v267 + __CFADD__((_DWORD)v266, (_DWORD)v260) + (_DWORD)v192;
  LODWORD(v154) = 2 * v261;
  v637 = HIWORD(HIDWORD(v51)) | (HIDWORD(v260) << 16);
  *(_DWORD *)v576 = HIWORD(HIDWORD(v260)) | (HIDWORD(v51) << 16);
  v268 = (2 * v569) | (v261 >> 31);
  LODWORD(v154) = v154 | ((unsigned int)v569 >> 31);
  LODWORD(v569) = *(_DWORD *)v576 + __CFADD__((_DWORD)v264, v637) + *(_DWORD *)v570;
  *(_DWORD *)v570 = (((m[7] + v253) >> 32) + v637) ^ v260;
  HIDWORD(v87) = (m[7] + v253 + __PAIR64__(v154, v268)) >> 32;
  LODWORD(v192) = LODWORD(m[7]) + v253 + v268;
  LODWORD(v51) = HIDWORD(v87) ^ v575;
  HIDWORD(v154) = v263 + (HIDWORD(v87) ^ v575);
  v269 = HIDWORD(v154) ^ v268;
  LODWORD(v41) = v41 + __CFADD__((_DWORD)v263, HIDWORD(v87) ^ v575) + (v192 ^ *(_DWORD *)&v570[8]);
  LODWORD(v154) = v154 ^ v41;
  LODWORD(v575) = v569 ^ v267;
  v270 = BYTE3(v154);
  v271 = m[5] + __PAIR64__(HIDWORD(v87), v192);
  HIDWORD(v87) = (m[5] + __PAIR64__(HIDWORD(v87), v192)) >> 32;
  LODWORD(v154) = HIBYTE(v269) | ((_DWORD)v154 << 8);
  v272 = v270 | (v269 << 8);
  LODWORD(v51) = (v271 + v154) ^ v51;
  *(_DWORD *)&v591[12] = v271 + v154;
  HIDWORD(v41) = v192 ^ *(_DWORD *)&v570[8] ^ (v272 + __CFADD__((_DWORD)v271, (_DWORD)v154) + HIDWORD(v87));
  *(_DWORD *)&v591[16] = v272 + __CFADD__((_DWORD)v271, (_DWORD)v154) + HIDWORD(v87);
  HIDWORD(v192) = HIWORD(HIDWORD(v41));
  HIDWORD(v41) = WORD1(v51) | (HIDWORD(v41) << 16);
  v96 = __CFADD__(HIDWORD(v154), HIDWORD(v41));
  HIDWORD(v192) |= (_DWORD)v51 << 16;
  *(_DWORD *)&v570[8] = HIDWORD(v41);
  HIDWORD(v41) += HIDWORD(v154);
  HIDWORD(v87) = 2 * HIDWORD(v569);
  LODWORD(v51) = (2 * v87) | (HIDWORD(v569) >> 31);
  HIDWORD(v569) = HIDWORD(v192) + v96 + (_DWORD)v41;
  LODWORD(v87) = HIDWORD(v87) | ((unsigned int)v87 >> 31);
  *(_DWORD *)&v576[8] = HIDWORD(v41) ^ v154;
  v273 = *(_DWORD *)v612;
  *(_DWORD *)v612 = HIDWORD(v41);
  v274 = (LODWORD(m[15]) + v273 + v87) ^ *(_DWORD *)&v570[4];
  v275 = m[15] + __PAIR64__(v629, v273) + __PAIR64__(v51, v87);
  HIDWORD(v260) = v87 ^ (v558 + (HIDWORD(v275) ^ v643));
  *(_DWORD *)&v570[4] = HIDWORD(v569) ^ v272;
  HIDWORD(v87) = (__PAIR64__(HIDWORD(v568), v558) + __PAIR64__(v274, HIDWORD(v275) ^ (unsigned int)v643)) >> 32;
  LODWORD(v154) = v558 + (HIDWORD(v275) ^ v643);
  LODWORD(v51) = HIDWORD(v87) ^ v51;
  HIDWORD(v154) = BYTE3(v51);
  LODWORD(v51) = HIBYTE(HIDWORD(v260)) | ((_DWORD)v51 << 8);
  HIDWORD(v51) = (m[14] + v275) >> 32;
  HIDWORD(v154) |= HIDWORD(v260) << 8;
  LODWORD(v41) = HIDWORD(v275) ^ v643 ^ (LODWORD(m[14]) + v275 + v51);
  v276 = ((__PAIR64__(HIDWORD(v154), LODWORD(m[14]) + (int)v275) + v51) >> 32) ^ v274;
  v559 = WORD1(v41) | (v276 << 16);
  *(_QWORD *)&v612[4] = __PAIR64__(HIDWORD(v154), LODWORD(m[14]) + (int)v275) + v51;
  HIDWORD(v51) = (2 * v586) | (*(_DWORD *)&v576[12] >> 31);
  v630 = HIWORD(v276) | ((_DWORD)v41 << 16);
  v277 = (2 * *(_DWORD *)&v576[12]) | ((unsigned int)v586 >> 31);
  LODWORD(v87) = (__PAIR64__(HIDWORD(v87), v154) + __PAIR64__(v630, v559)) >> 32;
  LODWORD(v154) = v154 + v559;
  *(_DWORD *)&v576[12] = v154 ^ v51;
  HIDWORD(v568) = v87;
  HIDWORD(v260) = (LODWORD(m[1]) + *(_DWORD *)&v576[16] + v277) ^ HIDWORD(v575);
  v278 = m[1] + __PAIR64__(*(unsigned int *)&v591[8], *(unsigned int *)&v576[16]) + __PAIR64__(HIDWORD(v51), v277);
  HIDWORD(v575) = v87 ^ HIDWORD(v154);
  LODWORD(v260) = HIDWORD(v278) ^ *(_DWORD *)&v576[4];
  v279 = (HIDWORD(v586) + (HIDWORD(v278) ^ *(_DWORD *)&v576[4])) ^ v277;
  LODWORD(v87) = (__PAIR64__(*(unsigned int *)&v591[20], HIDWORD(v586)) + v260) >> 32;
  HIDWORD(v51) ^= v87;
  v280 = HIBYTE(v279) | (HIDWORD(v51) << 8);
  v281 = HIBYTE(HIDWORD(v51)) | (v279 << 8);
  v282 = m[9] + v278 + __PAIR64__(v281, v280);
  LODWORD(v260) = v282 ^ HIDWORD(v278) ^ *(_DWORD *)&v576[4];
  HIDWORD(v260) ^= HIDWORD(v282);
  LODWORD(v192) = HIWORD(HIDWORD(v260));
  HIDWORD(v260) = v260 >> 16;
  LODWORD(v260) = v192 | ((_DWORD)v260 << 16);
  v283 = __PAIR64__(v87, HIDWORD(v586) + (HIDWORD(v278) ^ *(_DWORD *)&v576[4])) + __PAIR64__(v260, HIDWORD(v260));
  LODWORD(v87) = (__PAIR64__(v87, HIDWORD(v586) + (HIDWORD(v278) ^ *(_DWORD *)&v576[4]))
                + __PAIR64__(v260, HIDWORD(v260))) >> 32;
  v284 = v283 ^ v280;
  v285 = v87 ^ v281;
  HIDWORD(v51) = 2 * v285;
  v286 = (2 * v284) | (v285 >> 31);
  v287 = HIDWORD(v51) | (v284 >> 31);
  v288 = m[12] + v596 + __PAIR64__(v287, v286);
  HIDWORD(v192) ^= HIDWORD(v288);
  v96 = __CFADD__((_DWORD)v154, HIDWORD(v192));
  LODWORD(v154) = v154 + HIDWORD(v192);
  v289 = v154 ^ v286;
  *(_DWORD *)&v576[4] = HIDWORD(v568) + v96 + (*(_DWORD *)&v570[8] ^ v288);
  v290 = *(_DWORD *)&v576[4] ^ v287;
  HIDWORD(v51) = HIBYTE(v290);
  v291 = HIBYTE(v289) | (v290 << 8);
  v292 = HIDWORD(v51) | (v289 << 8);
  v293 = m[5] + v288 + __PAIR64__(v292, v291);
  HIDWORD(v87) = HIDWORD(v293);
  LODWORD(v192) = v293;
  HIDWORD(v192) ^= v192;
  HIDWORD(v41) = *(_DWORD *)&v570[8] ^ v288 ^ HIDWORD(v87);
  *(_QWORD *)v591 = __PAIR64__(HIDWORD(v87), v192);
  HIDWORD(v87) = HIWORD(HIDWORD(v192)) | (HIDWORD(v41) << 16);
  *(_DWORD *)&v570[8] = HIWORD(HIDWORD(v41)) | (HIDWORD(v192) << 16);
  HIDWORD(v568) = v154 + HIDWORD(v87);
  LODWORD(v643) = HIDWORD(v87);
  LODWORD(v41) = (2 * *(_DWORD *)v570) | ((unsigned int)v575 >> 31);
  HIDWORD(v192) = (2 * v575) | (*(_DWORD *)v570 >> 31);
  *(_DWORD *)v570 = *(_DWORD *)&v570[8] + __CFADD__((_DWORD)v154, HIDWORD(v87)) + *(_DWORD *)&v576[4];
  *(_DWORD *)&v576[4] = (v154 + HIDWORD(v87)) ^ v291;
  LODWORD(v192) = LODWORD(m[1]) + *(_DWORD *)&v591[12];
  HIDWORD(v87) = (v192 + __PAIR64__((m[1] + *(_QWORD *)&v591[12]) >> 32, v41)) >> 32;
  LODWORD(v192) = LODWORD(m[1]) + *(_DWORD *)&v591[12] + v41;
  *(_DWORD *)&v576[16] = *(_DWORD *)v570 ^ v292;
  HIDWORD(v154) = v283 + (v630 ^ HIDWORD(v87));
  LODWORD(v87) = v87 + __CFADD__((_DWORD)v283, v630 ^ HIDWORD(v87)) + (v192 ^ v559);
  HIDWORD(v51) = v41 ^ HIDWORD(v154);
  LODWORD(v41) = HIDWORD(v192) ^ v87;
  HIDWORD(v192) = HIBYTE(HIDWORD(v51)) | ((HIDWORD(v192) ^ (unsigned int)v87) << 8);
  LODWORD(v41) = BYTE3(v41) | (HIDWORD(v51) << 8);
  v294 = m[15] + __PAIR64__(HIDWORD(v87), v192) + __PAIR64__(v41, HIDWORD(v192));
  HIDWORD(v41) = v192 ^ v559 ^ HIDWORD(v294);
  LODWORD(v154) = v630 ^ HIDWORD(v87) ^ v294;
  LODWORD(v575) = WORD1(v154) | (HIDWORD(v41) << 16);
  v631 = HIWORD(HIDWORD(v41)) | ((_DWORD)v154 << 16);
  v295 = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)&v570[4] >> 31);
  v96 = __CFADD__(HIDWORD(v154), (_DWORD)v575);
  v296 = HIDWORD(v154) + v575;
  HIDWORD(v154) = (2 * *(_DWORD *)&v570[4]) | (*(_DWORD *)&v576[8] >> 31);
  *(_DWORD *)&v570[4] = v296;
  *(_DWORD *)&v591[16] = v631 + v96 + (_DWORD)v87;
  HIDWORD(v87) = v296 ^ HIDWORD(v192);
  v297 = m[14] + *(_QWORD *)&v612[4] + __PAIR64__(HIDWORD(v154), v295);
  HIDWORD(v260) ^= v297;
  LODWORD(v260) = HIDWORD(v297) ^ v260;
  v298 = *(_DWORD *)&v591[16] ^ v41;
  v299 = (v264 + v637 + v260) ^ v295;
  HIDWORD(v41) = (__PAIR64__(v569, (int)v264 + v637) + v260) >> 32;
  LODWORD(v154) = v264 + v637 + v260;
  HIDWORD(v154) ^= HIDWORD(v41);
  LODWORD(v41) = HIBYTE(v299) | (HIDWORD(v154) << 8);
  v300 = HIBYTE(HIDWORD(v154)) | (v299 << 8);
  v301 = (m[13] + v297 + __PAIR64__(v300, v41)) ^ v260;
  *(_DWORD *)&v591[20] = LODWORD(m[13]) + v297 + v41;
  *(_DWORD *)&v612[4] = (m[13] + v297 + __PAIR64__(v300, v41)) >> 32;
  LODWORD(v568) = v301 >> 16;
  LODWORD(v569) = HIWORD(HIDWORD(v301)) | ((_DWORD)v301 << 16);
  LODWORD(v87) = (2 * *(_DWORD *)&v576[12]) | (HIDWORD(v575) >> 31);
  LODWORD(v51) = (2 * HIDWORD(v575)) | (*(_DWORD *)&v576[12] >> 31);
  v96 = __CFADD__((_DWORD)v154, (_DWORD)v568);
  LODWORD(v154) = v154 + v568;
  HIDWORD(v41) += v96 + (_DWORD)v569;
  v302 = HIDWORD(v41) ^ v300;
  HIDWORD(v575) = v154 ^ v41;
  LODWORD(v192) = (m[4] + v282 + __PAIR64__(v51, v87)) >> 32;
  HIDWORD(v192) = LODWORD(m[4]) + v282 + v87;
  v560 = v87 ^ (*(_DWORD *)v612 + (v192 ^ *(_DWORD *)v576));
  LODWORD(v41) = (__PAIR64__(HIDWORD(v569), *(unsigned int *)v612)
                + __PAIR64__(HIDWORD(v192) ^ (unsigned int)v637, (unsigned int)v192 ^ *(_DWORD *)v576)) >> 32;
  HIDWORD(v154) = *(_DWORD *)v612 + (v192 ^ *(_DWORD *)v576);
  LODWORD(v51) = v41 ^ v51;
  HIDWORD(v569) = BYTE3(v51);
  LODWORD(v51) = HIBYTE(v560) | ((_DWORD)v51 << 8);
  v303 = m[10] + __PAIR64__(v192, HIDWORD(v192));
  LODWORD(v87) = HIDWORD(v569) | (v560 << 8);
  HIDWORD(v51) = (LODWORD(m[10]) + HIDWORD(v192) + v51) ^ v192 ^ *(_DWORD *)v576;
  LODWORD(v192) = v87
                + __CFADD__(LODWORD(m[10]) + HIDWORD(v192), (_DWORD)v51)
                + ((m[10] + __PAIR64__(v192, HIDWORD(v192))) >> 32);
  v587 = __PAIR64__(v192, (int)v303 + (int)v51);
  HIDWORD(v301) = v192 ^ HIDWORD(v192) ^ v637;
  LODWORD(v192) = HIWORD(HIDWORD(v301));
  HIDWORD(v301) = HIWORD(HIDWORD(v51)) | (HIDWORD(v301) << 16);
  HIDWORD(v51) = v192 | (HIDWORD(v51) << 16);
  LODWORD(v301) = 2 * v298;
  v304 = (2 * HIDWORD(v87)) | (v298 >> 31);
  LODWORD(v301) = v301 | (HIDWORD(v87) >> 31);
  v305 = __PAIR64__(v41, HIDWORD(v154)) + __PAIR64__(HIDWORD(v51), HIDWORD(v301));
  LODWORD(v41) = (__PAIR64__(v41, HIDWORD(v154)) + __PAIR64__(HIDWORD(v51), HIDWORD(v301))) >> 32;
  *(_DWORD *)v576 = v305 ^ v51;
  LODWORD(v192) = (m[0] + *(_QWORD *)v591 + __PAIR64__(v301, v304)) >> 32;
  HIDWORD(v192) = LODWORD(m[0]) + *(_DWORD *)v591 + v304;
  *(_DWORD *)&v576[8] = v87 ^ v41;
  HIDWORD(v51) ^= v192;
  HIDWORD(v301) ^= HIDWORD(v192);
  v306 = (v154 + HIDWORD(v51)) ^ v304;
  v307 = __PAIR64__(HIDWORD(v41), v154) + __PAIR64__(HIDWORD(v301), HIDWORD(v51));
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), v154) + __PAIR64__(HIDWORD(v301), HIDWORD(v51))) >> 32;
  LODWORD(v301) = HIDWORD(v41) ^ v301;
  LODWORD(v154) = BYTE3(v301);
  LODWORD(v301) = HIBYTE(v306) | ((_DWORD)v301 << 8);
  v308 = v154 | (v306 << 8);
  v309 = m[7] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v308, v301);
  HIDWORD(v51) ^= v309;
  HIDWORD(v301) ^= HIDWORD(v309);
  v638 = HIWORD(HIDWORD(v51)) | (HIDWORD(v301) << 16);
  HIDWORD(v569) = HIWORD(HIDWORD(v301)) | (HIDWORD(v51) << 16);
  LODWORD(v154) = (2 * v302) | (HIDWORD(v575) >> 31);
  v310 = (2 * HIDWORD(v575)) | (v302 >> 31);
  v561 = HIDWORD(v569) + __CFADD__((_DWORD)v307, v638) + HIDWORD(v41);
  HIDWORD(v575) = (v307 + v638) ^ v301;
  HIDWORD(v87) = (m[6] + v294 + __PAIR64__(v154, v310)) >> 32;
  LODWORD(v192) = LODWORD(m[6]) + v294 + v310;
  LODWORD(v51) = HIDWORD(v87) ^ *(_DWORD *)&v570[8];
  HIDWORD(v154) = v305 + (HIDWORD(v87) ^ *(_DWORD *)&v570[8]);
  v311 = HIDWORD(v154) ^ v310;
  LODWORD(v41) = v41 + __CFADD__((_DWORD)v305, HIDWORD(v87) ^ *(_DWORD *)&v570[8]) + (v192 ^ v643);
  LODWORD(v154) = v154 ^ v41;
  v312 = m[3] + __PAIR64__(HIDWORD(v87), v192);
  HIDWORD(v87) = (m[3] + __PAIR64__(HIDWORD(v87), v192)) >> 32;
  *(_DWORD *)&v576[12] = v561 ^ v308;
  v313 = BYTE3(v154);
  LODWORD(v154) = HIBYTE(v311) | ((_DWORD)v154 << 8);
  v314 = v313 | (v311 << 8);
  LODWORD(v51) = (v312 + v154) ^ v51;
  HIDWORD(v41) = v192 ^ v643 ^ (v314 + __CFADD__((_DWORD)v312, (_DWORD)v154) + HIDWORD(v87));
  *(_DWORD *)&v591[12] = v312 + v154;
  *(_DWORD *)v612 = v314 + __CFADD__((_DWORD)v312, (_DWORD)v154) + HIDWORD(v87);
  HIDWORD(v192) = HIWORD(HIDWORD(v41));
  HIDWORD(v41) = WORD1(v51) | (HIDWORD(v41) << 16);
  *(_DWORD *)&v570[8] = HIDWORD(v192) | ((_DWORD)v51 << 16);
  LODWORD(v51) = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)v576 >> 31);
  LODWORD(v87) = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[8] >> 31);
  HIDWORD(v87) = HIDWORD(v154) + HIDWORD(v41);
  v315 = *(_DWORD *)&v570[8] + __CFADD__(HIDWORD(v154), HIDWORD(v41)) + (_DWORD)v41;
  HIDWORD(v154) = *(_DWORD *)&v591[20];
  *(_DWORD *)&v591[20] = HIDWORD(v87);
  *(_DWORD *)v576 = HIDWORD(v87) ^ v154;
  LODWORD(v41) = *(_DWORD *)&v612[4];
  *(_DWORD *)&v612[4] = v315;
  v316 = m[9] + __PAIR64__(v41, HIDWORD(v154));
  LODWORD(v41) = v575;
  v317 = v316 + __PAIR64__(v51, v87);
  LODWORD(v575) = v315 ^ v314;
  v318 = (v316 + v87) ^ v41;
  LODWORD(v41) = ((v316 + __PAIR64__(v51, v87)) >> 32) ^ v631;
  HIDWORD(v87) = (__PAIR64__(*(unsigned int *)v570, HIDWORD(v568)) + __PAIR64__(v318, v41)) >> 32;
  HIDWORD(v301) = HIDWORD(v568) + v41;
  LODWORD(v87) = v87 ^ (HIDWORD(v568) + v41);
  LODWORD(v51) = ((__PAIR64__(*(unsigned int *)v570, HIDWORD(v568))
                 + __PAIR64__(v318, HIDWORD(v317) ^ (unsigned int)v631)) >> 32)
               ^ v51;
  LODWORD(v154) = BYTE3(v51);
  HIDWORD(v51) = (m[2] + v317) >> 32;
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v154) = v154 | ((_DWORD)v87 << 8);
  LODWORD(v41) = v41 ^ (LODWORD(m[2]) + v317 + v51);
  v319 = __PAIR64__(HIDWORD(v154), LODWORD(m[2]) + (int)v317) + v51;
  v320 = ((__PAIR64__(HIDWORD(v154), LODWORD(m[2]) + (int)v317) + v51) >> 32) ^ v318;
  HIDWORD(v643) = HIWORD(v320) | ((_DWORD)v41 << 16);
  LODWORD(v643) = WORD1(v41) | (v320 << 16);
  HIDWORD(v51) = (2 * *(_DWORD *)&v576[16]) | (*(_DWORD *)&v576[4] >> 31);
  v321 = (2 * *(_DWORD *)&v576[4]) | (*(_DWORD *)&v576[16] >> 31);
  v322 = __PAIR64__(HIDWORD(v87), HIDWORD(v301)) + v643;
  HIDWORD(v87) = (__PAIR64__(HIDWORD(v87), HIDWORD(v301)) + v643) >> 32;
  *(_DWORD *)&v576[4] = v322 ^ v51;
  *(_DWORD *)&v576[8] = HIDWORD(v87) ^ HIDWORD(v154);
  v323 = m[8] + v587 + __PAIR64__(HIDWORD(v51), v321);
  HIDWORD(v301) = v323 ^ v568;
  LODWORD(v301) = HIDWORD(v323) ^ v569;
  v324 = (*(_DWORD *)&v570[4] + (HIDWORD(v323) ^ v569)) ^ v321;
  LODWORD(v87) = (__PAIR64__(*(unsigned int *)&v591[16], *(unsigned int *)&v570[4]) + v301) >> 32;
  HIDWORD(v154) = *(_DWORD *)&v570[4] + (HIDWORD(v323) ^ v569);
  HIDWORD(v51) ^= v87;
  v325 = HIBYTE(v324) | (HIDWORD(v51) << 8);
  v326 = HIBYTE(HIDWORD(v51)) | (v324 << 8);
  v327 = m[11] + v323 + __PAIR64__(v326, v325);
  LODWORD(v301) = v327 ^ HIDWORD(v323) ^ v569;
  HIDWORD(v301) = HIDWORD(v327) ^ v323 ^ v568;
  LODWORD(v192) = HIWORD(HIDWORD(v301));
  HIDWORD(v301) = v301 >> 16;
  LODWORD(v301) = v192 | ((_DWORD)v301 << 16);
  v328 = (HIDWORD(v154) + HIDWORD(v301)) ^ v325;
  v329 = __PAIR64__(v87, HIDWORD(v154)) + __PAIR64__(v301, HIDWORD(v301));
  LODWORD(v87) = (__PAIR64__(v87, HIDWORD(v154)) + __PAIR64__(v301, HIDWORD(v301))) >> 32;
  v330 = v87 ^ v326;
  HIDWORD(v51) = 2 * v330;
  v331 = (2 * v328) | (v330 >> 31);
  v332 = HIDWORD(v51) | (v328 >> 31);
  v333 = m[13] + v309 + __PAIR64__(v332, v331);
  HIDWORD(v41) ^= v333;
  LODWORD(v568) = v322 + (*(_DWORD *)&v570[8] ^ HIDWORD(v333));
  v334 = v568 ^ v331;
  HIDWORD(v87) += __CFADD__((_DWORD)v322, *(_DWORD *)&v570[8] ^ HIDWORD(v333)) + HIDWORD(v41);
  v335 = HIDWORD(v87) ^ v332;
  HIDWORD(v51) = HIBYTE(v335);
  v336 = HIBYTE(v334) | (v335 << 8);
  v337 = HIDWORD(v51) | (v334 << 8);
  HIDWORD(v192) = *(_DWORD *)&v570[8] ^ HIDWORD(v333) ^ (LODWORD(m[11]) + v333 + v336);
  HIDWORD(v41) ^= (m[11] + v333 + __PAIR64__(v337, v336)) >> 32;
  *(_DWORD *)v591 = (m[11] + v333 + __PAIR64__(v337, v336)) >> 32;
  HIDWORD(v587) = LODWORD(m[11]) + v333 + v336;
  v644 = HIWORD(HIDWORD(v192)) | (HIDWORD(v41) << 16);
  *(_DWORD *)v570 = HIWORD(HIDWORD(v41)) | (HIDWORD(v192) << 16);
  LODWORD(v41) = (2 * HIDWORD(v575)) | (*(_DWORD *)&v576[12] >> 31);
  HIDWORD(v192) = (2 * *(_DWORD *)&v576[12]) | (HIDWORD(v575) >> 31);
  v96 = __CFADD__((_DWORD)v568, v644);
  LODWORD(v568) = v568 + v644;
  HIDWORD(v568) = *(_DWORD *)v570 + v96 + HIDWORD(v87);
  HIDWORD(v575) = v568 ^ v336;
  LODWORD(v192) = LODWORD(m[7]) + *(_DWORD *)&v591[12];
  HIDWORD(v87) = (v192 + __PAIR64__((m[7] + __PAIR64__(*(unsigned int *)v612, *(unsigned int *)&v591[12])) >> 32, v41)) >> 32;
  LODWORD(v192) = LODWORD(m[7]) + *(_DWORD *)&v591[12] + v41;
  *(_DWORD *)&v576[12] = HIDWORD(v568) ^ v337;
  HIDWORD(v154) = v329 + (HIDWORD(v643) ^ HIDWORD(v87));
  LODWORD(v87) = v87 + __CFADD__((_DWORD)v329, HIDWORD(v643) ^ HIDWORD(v87)) + (v192 ^ v643);
  LODWORD(v41) = v41 ^ HIDWORD(v154);
  HIDWORD(v51) = HIDWORD(v192) ^ v87;
  HIDWORD(v192) = BYTE3(v41) | ((HIDWORD(v192) ^ (unsigned int)v87) << 8);
  LODWORD(v41) = HIBYTE(HIDWORD(v51)) | ((_DWORD)v41 << 8);
  LODWORD(v154) = HIDWORD(v643) ^ HIDWORD(v87) ^ (LODWORD(m[14]) + v192 + HIDWORD(v192));
  *(_DWORD *)&v591[4] = LODWORD(m[14]) + v192 + HIDWORD(v192);
  *(_DWORD *)&v591[12] = (m[14] + __PAIR64__(HIDWORD(v87), v192) + __PAIR64__(v41, HIDWORD(v192))) >> 32;
  HIDWORD(v41) = v192 ^ v643 ^ *(_DWORD *)&v591[12];
  *(_DWORD *)&v570[4] = WORD1(v154) | (HIDWORD(v41) << 16);
  LODWORD(v643) = HIWORD(HIDWORD(v41)) | ((_DWORD)v154 << 16);
  v338 = (2 * *(_DWORD *)v576) | ((unsigned int)v575 >> 31);
  v96 = __CFADD__(HIDWORD(v154), *(_DWORD *)&v570[4]);
  v339 = HIDWORD(v154) + *(_DWORD *)&v570[4];
  HIDWORD(v154) = (2 * v575) | (*(_DWORD *)v576 >> 31);
  LODWORD(v569) = v339;
  LODWORD(v154) = v643 + v96 + (_DWORD)v87;
  LODWORD(v87) = v339;
  v340 = v154 ^ v41;
  *(_DWORD *)&v591[16] = v154;
  HIDWORD(v87) = v87 ^ HIDWORD(v192);
  v341 = m[12] + v319 + __PAIR64__(HIDWORD(v154), v338);
  LODWORD(v301) = HIDWORD(v341) ^ v301;
  HIDWORD(v301) ^= v341;
  v342 = (v307 + v638 + v301) ^ v338;
  HIDWORD(v41) = (__PAIR64__(v561, (int)v307 + v638) + v301) >> 32;
  LODWORD(v154) = v307 + v638 + v301;
  HIDWORD(v154) ^= HIDWORD(v41);
  LODWORD(v41) = HIBYTE(v342) | (HIDWORD(v154) << 8);
  v343 = HIBYTE(HIDWORD(v154)) | (v342 << 8);
  v344 = (m[1] + v341 + __PAIR64__(v343, v41)) ^ v301;
  *(_DWORD *)&v591[8] = LODWORD(m[1]) + v341 + v41;
  *(_DWORD *)v612 = (m[1] + v341 + __PAIR64__(v343, v41)) >> 32;
  *(_DWORD *)&v570[8] = v344 >> 16;
  LODWORD(v87) = (2 * (v322 ^ v51)) | (*(_DWORD *)&v576[8] >> 31);
  LODWORD(v575) = HIWORD(HIDWORD(v344)) | ((_DWORD)v344 << 16);
  HIDWORD(v154) = v575;
  v345 = v154 + __PAIR64__(HIDWORD(v41), *(unsigned int *)&v570[8]);
  v346 = HIDWORD(v345) ^ v343;
  *(_DWORD *)v576 = v345 ^ v41;
  HIDWORD(v344) = (LODWORD(m[3]) + v327 + v87) ^ v638;
  HIDWORD(v41) = HIDWORD(v569);
  LODWORD(v192) = (m[3] + v327 + ((2LL * *(_QWORD *)&v576[4]) | (*(_DWORD *)&v576[8] >> 31))) >> 32;
  HIDWORD(v192) = LODWORD(m[3]) + v327 + v87;
  HIDWORD(v569) = HIDWORD(v345);
  HIDWORD(v51) = v192 ^ HIDWORD(v41);
  LODWORD(v87) = v87 ^ (*(_DWORD *)&v591[20] + (v192 ^ HIDWORD(v41)));
  LODWORD(v41) = (__PAIR64__(*(unsigned int *)&v612[4], *(unsigned int *)&v591[20])
                + __PAIR64__(HIDWORD(v344), (unsigned int)v192 ^ HIDWORD(v41))) >> 32;
  HIDWORD(v345) = *(_DWORD *)&v591[20] + (v192 ^ HIDWORD(v41));
  LODWORD(v51) = v41 ^ (*(__int64 *)&v576[4] >> 31);
  HIDWORD(v41) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  LODWORD(v87) = HIDWORD(v41) | ((_DWORD)v87 << 8);
  HIDWORD(v51) ^= LODWORD(m[9]) + HIDWORD(v192) + v51;
  v347 = m[9] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v87, v51);
  HIDWORD(v192) = HIDWORD(v347);
  LODWORD(v587) = v347;
  HIDWORD(v344) ^= HIDWORD(v192);
  *(_DWORD *)&v591[20] = HIDWORD(v192);
  LODWORD(v192) = HIWORD(HIDWORD(v344));
  LODWORD(v344) = (2 * v340) | (HIDWORD(v87) >> 31);
  HIDWORD(v344) = HIWORD(HIDWORD(v51)) | (HIDWORD(v344) << 16);
  HIDWORD(v51) = v192 | (HIDWORD(v51) << 16);
  v348 = __PAIR64__(v41, HIDWORD(v345)) + __PAIR64__(HIDWORD(v51), HIDWORD(v344));
  LODWORD(v41) = (__PAIR64__(v41, HIDWORD(v345)) + __PAIR64__(HIDWORD(v51), HIDWORD(v344))) >> 32;
  v349 = (2 * HIDWORD(v87)) | (v340 >> 31);
  *(_DWORD *)&v576[8] = v87 ^ v41;
  LODWORD(v192) = (m[5] + __PAIR64__(*(unsigned int *)v591, HIDWORD(v587)) + __PAIR64__(v344, v349)) >> 32;
  HIDWORD(v192) = LODWORD(m[5]) + HIDWORD(v587) + v349;
  HIDWORD(v344) ^= HIDWORD(v192);
  HIDWORD(v51) ^= v192;
  *(_DWORD *)&v576[4] = v348 ^ v51;
  v350 = (v345 + HIDWORD(v51)) ^ v349;
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v569), v345) + __PAIR64__(HIDWORD(v344), HIDWORD(v51))) >> 32;
  HIDWORD(v87) = v345 + HIDWORD(v51);
  LODWORD(v344) = HIDWORD(v41) ^ v344;
  LODWORD(v345) = BYTE3(v344);
  LODWORD(v344) = HIBYTE(v350) | ((_DWORD)v344 << 8);
  v351 = v345 | (v350 << 8);
  HIDWORD(v51) ^= LODWORD(m[0]) + HIDWORD(v192) + v344;
  HIDWORD(v344) ^= (m[0] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v351, v344)) >> 32;
  HIDWORD(v587) = LODWORD(m[0]) + HIDWORD(v192) + v344;
  *(_DWORD *)v591 = (m[0] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v351, v344)) >> 32;
  v639 = HIWORD(HIDWORD(v51)) | (HIDWORD(v344) << 16);
  HIDWORD(v569) = HIWORD(HIDWORD(v344)) | (HIDWORD(v51) << 16);
  LODWORD(v87) = HIDWORD(v87) + v639;
  LODWORD(v345) = (2 * v346) | (*(_DWORD *)v576 >> 31);
  v352 = (2 * *(_DWORD *)v576) | (v346 >> 31);
  LODWORD(v51) = HIDWORD(v569) + __CFADD__(HIDWORD(v87), v639) + HIDWORD(v41);
  HIDWORD(v87) = *(_DWORD *)&v591[4];
  v562 = v51;
  *(_DWORD *)&v591[4] = v87;
  *(_DWORD *)v576 = v87 ^ v344;
  v353 = m[15] + __PAIR64__(*(unsigned int *)&v591[12], HIDWORD(v87)) + __PAIR64__(v345, v352);
  HIDWORD(v87) = HIDWORD(v353);
  LODWORD(v192) = v353;
  LODWORD(v51) = HIDWORD(v87) ^ *(_DWORD *)v570;
  HIDWORD(v345) = v348 + (HIDWORD(v87) ^ *(_DWORD *)v570);
  v354 = HIDWORD(v345) ^ v352;
  LODWORD(v41) = v41 + __CFADD__((_DWORD)v348, HIDWORD(v87) ^ *(_DWORD *)v570) + (v192 ^ v644);
  LODWORD(v345) = v345 ^ v41;
  *(_DWORD *)&v576[16] = v562 ^ v351;
  v355 = BYTE3(v345);
  LODWORD(v345) = HIBYTE(v354) | ((_DWORD)v345 << 8);
  v356 = m[4] + __PAIR64__(HIDWORD(v87), v192);
  HIDWORD(v87) = (m[4] + __PAIR64__(HIDWORD(v87), v192)) >> 32;
  v357 = v355 | (v354 << 8);
  LODWORD(v51) = (v356 + v345) ^ v51;
  HIDWORD(v41) = v192 ^ v644 ^ (v357 + __CFADD__((_DWORD)v356, (_DWORD)v345) + HIDWORD(v87));
  *(_DWORD *)&v612[4] = v357 + __CFADD__((_DWORD)v356, (_DWORD)v345) + HIDWORD(v87);
  *(_DWORD *)&v591[12] = v356 + v345;
  HIDWORD(v192) = HIWORD(HIDWORD(v41)) | ((_DWORD)v51 << 16);
  HIDWORD(v41) = WORD1(v51) | (HIDWORD(v41) << 16);
  LODWORD(v51) = *(__int64 *)&v576[4] >> 31;
  LODWORD(v192) = *(_DWORD *)&v591[8];
  LODWORD(v87) = (2 * *(_DWORD *)&v576[4]) | (*(_DWORD *)&v576[8] >> 31);
  *(_DWORD *)&v591[8] = HIDWORD(v345) + HIDWORD(v41);
  *(_DWORD *)&v576[4] = (HIDWORD(v345) + HIDWORD(v41)) ^ v345;
  v358 = m[8] + __PAIR64__(*(unsigned int *)v612, v192) + __PAIR64__(v51, v87);
  v359 = v358 ^ *(_DWORD *)&v570[4];
  *(_DWORD *)v612 = HIDWORD(v192) + __CFADD__(HIDWORD(v345), HIDWORD(v41)) + (_DWORD)v41;
  *(_DWORD *)&v570[4] = *(_DWORD *)v612 ^ v357;
  LODWORD(v87) = v87 ^ (v568 + (HIDWORD(v358) ^ v643));
  HIDWORD(v87) = (v568 + __PAIR64__(v359, HIDWORD(v358) ^ (unsigned int)v643)) >> 32;
  HIDWORD(v344) = v568 + (HIDWORD(v358) ^ v643);
  LODWORD(v51) = HIDWORD(v87) ^ v51;
  HIDWORD(v51) = (m[6] + v358) >> 32;
  HIDWORD(v345) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v345) |= (_DWORD)v87 << 8;
  LODWORD(v41) = HIDWORD(v358) ^ v643 ^ (LODWORD(m[6]) + v358 + v51);
  v360 = ((__PAIR64__(HIDWORD(v345), LODWORD(m[6]) + (int)v358) + v51) >> 32) ^ v359;
  LODWORD(v87) = HIDWORD(v575);
  LODWORD(v345) = HIWORD(v360) | ((_DWORD)v41 << 16);
  *(_DWORD *)&v576[8] = WORD1(v41) | (v360 << 16);
  *(_QWORD *)&v612[8] = __PAIR64__(HIDWORD(v345), LODWORD(m[6]) + (int)v358) + v51;
  v361 = (2 * HIDWORD(v575)) | (*(_DWORD *)&v576[12] >> 31);
  LODWORD(v568) = HIDWORD(v344) + *(_DWORD *)&v576[8];
  LODWORD(v643) = v345;
  HIDWORD(v87) += __CFADD__(HIDWORD(v344), *(_DWORD *)&v576[8]) + (_DWORD)v345;
  HIDWORD(v575) = (HIDWORD(v344) + *(_DWORD *)&v576[8]) ^ v51;
  HIDWORD(v51) = (2 * *(_DWORD *)&v576[12]) | ((unsigned int)v87 >> 31);
  LODWORD(v41) = (m[2] + __PAIR64__(*(unsigned int *)&v591[20], v587) + __PAIR64__(HIDWORD(v51), v361)) >> 32;
  LODWORD(v345) = LODWORD(m[2]) + v587 + v361;
  HIDWORD(v344) = v345 ^ *(_DWORD *)&v570[8];
  LODWORD(v344) = v41 ^ v575;
  LODWORD(v575) = HIDWORD(v87) ^ HIDWORD(v345);
  LODWORD(v87) = (__PAIR64__(*(unsigned int *)&v591[16], v569) + v344) >> 32;
  HIDWORD(v345) = v569 + v344;
  v362 = (v569 + v344) ^ v361;
  HIDWORD(v51) ^= v87;
  v363 = HIBYTE(v362) | (HIDWORD(v51) << 8);
  v364 = HIBYTE(HIDWORD(v51)) | (v362 << 8);
  v365 = m[10] + __PAIR64__(v41, v345) + __PAIR64__(v364, v363);
  v366 = v365 ^ v344;
  LODWORD(v192) = HIWORD(HIDWORD(v366));
  HIDWORD(v366) = v366 >> 16;
  LODWORD(v366) = v192 | ((_DWORD)v366 << 16);
  v367 = HIDWORD(v345);
  HIDWORD(v345) += HIDWORD(v366);
  v368 = HIDWORD(v345) ^ v363;
  HIDWORD(v568) = HIDWORD(v345);
  LODWORD(v87) = (__PAIR64__(v87, v367) + __PAIR64__(v366, HIDWORD(v366))) >> 32;
  v369 = v87 ^ v364;
  HIDWORD(v51) = 2 * v369;
  v370 = (2 * v368) | (v369 >> 31);
  v371 = HIDWORD(v51) | (v368 >> 31);
  v372 = m[6] + __PAIR64__(*(unsigned int *)v591, HIDWORD(v587)) + __PAIR64__(v371, v370);
  HIDWORD(v41) ^= v372;
  LODWORD(v345) = v568 + (HIDWORD(v192) ^ HIDWORD(v372));
  HIDWORD(v87) += __CFADD__((_DWORD)v568, HIDWORD(v192) ^ HIDWORD(v372)) + HIDWORD(v41);
  v373 = v345 ^ v370;
  v374 = HIDWORD(v87) ^ v371;
  HIDWORD(v51) = HIBYTE(v374);
  v375 = HIBYTE(v373) | (v374 << 8);
  v376 = HIDWORD(v51) | (v373 << 8);
  HIDWORD(v192) ^= HIDWORD(v372) ^ (LODWORD(m[15]) + v372 + v375);
  HIDWORD(v41) ^= (m[15] + v372 + __PAIR64__(v376, v375)) >> 32;
  *(_DWORD *)v591 = (m[15] + v372 + __PAIR64__(v376, v375)) >> 32;
  HIDWORD(v587) = LODWORD(m[15]) + v372 + v375;
  LODWORD(v569) = HIWORD(HIDWORD(v41)) | (HIDWORD(v192) << 16);
  HIDWORD(v643) = HIWORD(HIDWORD(v192)) | (HIDWORD(v41) << 16);
  LODWORD(v41) = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[16] >> 31);
  HIDWORD(v192) = (2 * *(_DWORD *)&v576[16]) | (*(_DWORD *)v576 >> 31);
  HIDWORD(v345) = *(_DWORD *)&v591[12];
  LODWORD(v568) = v569 + __CFADD__((_DWORD)v345, HIDWORD(v643)) + HIDWORD(v87);
  *(_DWORD *)&v591[12] = v345 + HIDWORD(v643);
  *(_DWORD *)v576 = (v345 + HIDWORD(v643)) ^ v375;
  LODWORD(v192) = LODWORD(m[14]) + HIDWORD(v345);
  HIDWORD(v87) = (v192 + __PAIR64__((m[14] + __PAIR64__(*(unsigned int *)&v612[4], HIDWORD(v345))) >> 32, v41)) >> 32;
  LODWORD(v192) = LODWORD(m[14]) + HIDWORD(v345) + v41;
  HIDWORD(v41) = v192 ^ *(_DWORD *)&v576[8];
  *(_DWORD *)&v576[8] = v568 ^ v376;
  HIDWORD(v51) = HIDWORD(v568) + (HIDWORD(v87) ^ v643);
  LODWORD(v41) = v41 ^ HIDWORD(v51);
  LODWORD(v87) = v87 + __CFADD__(HIDWORD(v568), HIDWORD(v87) ^ v643) + HIDWORD(v41);
  HIDWORD(v192) ^= v87;
  LODWORD(v51) = HIBYTE(HIDWORD(v192));
  HIDWORD(v192) = BYTE3(v41) | (HIDWORD(v192) << 8);
  LODWORD(v41) = v51 | ((_DWORD)v41 << 8);
  LODWORD(v345) = HIDWORD(v87) ^ v643 ^ (LODWORD(m[9]) + v192 + HIDWORD(v192));
  HIDWORD(v41) ^= (m[9] + __PAIR64__(HIDWORD(v87), v192) + __PAIR64__(v41, HIDWORD(v192))) >> 32;
  *(_DWORD *)&v591[16] = (m[9] + __PAIR64__(HIDWORD(v87), v192) + __PAIR64__(v41, HIDWORD(v192))) >> 32;
  *(_DWORD *)&v576[16] = LODWORD(m[9]) + v192 + HIDWORD(v192);
  HIDWORD(v87) = WORD1(v345) | (HIDWORD(v41) << 16);
  *(_DWORD *)v570 = HIWORD(HIDWORD(v41)) | ((_DWORD)v345 << 16);
  v96 = __CFADD__(HIDWORD(v51), HIDWORD(v87));
  LODWORD(v643) = HIDWORD(v87);
  HIDWORD(v568) = HIDWORD(v51) + HIDWORD(v87);
  v377 = (2 * *(_DWORD *)&v576[4]) | (*(_DWORD *)&v570[4] >> 31);
  HIDWORD(v345) = (2 * *(_DWORD *)&v570[4]) | (*(_DWORD *)&v576[4] >> 31);
  HIDWORD(v87) = (HIDWORD(v51) + HIDWORD(v87)) ^ HIDWORD(v192);
  LODWORD(v87) = *(_DWORD *)v570 + v96 + (_DWORD)v87;
  v378 = v87 ^ v41;
  *(_DWORD *)&v591[20] = v87;
  v379 = m[11] + *(_QWORD *)&v612[8] + __PAIR64__(HIDWORD(v345), v377);
  HIDWORD(v366) ^= v379;
  LODWORD(v366) = HIDWORD(v379) ^ v366;
  v380 = (*(_DWORD *)&v591[4] + v366) ^ v377;
  HIDWORD(v41) = (__PAIR64__(v562, *(unsigned int *)&v591[4]) + v366) >> 32;
  LODWORD(v345) = *(_DWORD *)&v591[4] + v366;
  HIDWORD(v345) ^= HIDWORD(v41);
  LODWORD(v41) = HIBYTE(v380) | (HIDWORD(v345) << 8);
  v381 = HIBYTE(HIDWORD(v345)) | (v380 << 8);
  v382 = (m[3] + v379 + __PAIR64__(v381, v41)) ^ v366;
  *(_DWORD *)&v591[4] = LODWORD(m[3]) + v379 + v41;
  *(_DWORD *)&v612[4] = (m[3] + v379 + __PAIR64__(v381, v41)) >> 32;
  *(_DWORD *)&v570[4] = v382 >> 16;
  *(_DWORD *)&v570[8] = HIWORD(HIDWORD(v382)) | ((_DWORD)v382 << 16);
  LODWORD(v87) = v575 >> 31;
  LODWORD(v51) = (2 * v575) | (HIDWORD(v575) >> 31);
  v383 = __PAIR64__(HIDWORD(v41), v345) + *(_QWORD *)&v570[4];
  v563 = HIDWORD(v383);
  LODWORD(v575) = v383 ^ v41;
  HIDWORD(v382) = (LODWORD(m[0]) + v365 + v87) ^ v639;
  LODWORD(v192) = (m[0] + v365 + __PAIR64__(v51, v87)) >> 32;
  HIDWORD(v192) = LODWORD(m[0]) + v365 + v87;
  v384 = HIDWORD(v383) ^ v381;
  LODWORD(v87) = v87 ^ (*(_DWORD *)&v591[8] + (v192 ^ HIDWORD(v569)));
  LODWORD(v41) = (__PAIR64__(*(unsigned int *)v612, *(unsigned int *)&v591[8])
                + __PAIR64__(HIDWORD(v382), (unsigned int)v192 ^ HIDWORD(v569))) >> 32;
  HIDWORD(v383) = *(_DWORD *)&v591[8] + (v192 ^ HIDWORD(v569));
  LODWORD(v51) = v41 ^ v51;
  HIDWORD(v41) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v51) = (LODWORD(m[8]) + HIDWORD(v192) + v51) ^ v192 ^ HIDWORD(v569);
  LODWORD(v587) = LODWORD(m[8]) + HIDWORD(v192) + v51;
  LODWORD(v87) = HIDWORD(v41) | ((_DWORD)v87 << 8);
  LODWORD(v192) = v87
                + __CFADD__(LODWORD(m[8]) + HIDWORD(v192), (_DWORD)v51)
                + ((m[8] + __PAIR64__(v192, HIDWORD(v192))) >> 32);
  HIDWORD(v382) ^= v192;
  *(_DWORD *)&v591[8] = v192;
  LODWORD(v192) = HIWORD(HIDWORD(v382));
  HIDWORD(v382) = HIWORD(HIDWORD(v51)) | (HIDWORD(v382) << 16);
  LODWORD(v382) = (2 * v378) | (HIDWORD(v87) >> 31);
  HIDWORD(v51) = v192 | (HIDWORD(v51) << 16);
  v385 = (2 * HIDWORD(v87)) | (v378 >> 31);
  v386 = __PAIR64__(v41, HIDWORD(v383)) + __PAIR64__(HIDWORD(v51), HIDWORD(v382));
  LODWORD(v41) = (__PAIR64__(v41, HIDWORD(v383)) + __PAIR64__(HIDWORD(v51), HIDWORD(v382))) >> 32;
  HIDWORD(v575) = v386 ^ v51;
  LODWORD(v87) = v87 ^ v41;
  LODWORD(v192) = (m[12] + __PAIR64__(*(unsigned int *)v591, HIDWORD(v587)) + __PAIR64__(v382, v385)) >> 32;
  HIDWORD(v192) = LODWORD(m[12]) + HIDWORD(v587) + v385;
  HIDWORD(v382) ^= HIDWORD(v192);
  HIDWORD(v51) ^= v192;
  v387 = (v383 + HIDWORD(v51)) ^ v385;
  HIDWORD(v41) = (__PAIR64__(v563, v383) + __PAIR64__(HIDWORD(v382), HIDWORD(v51))) >> 32;
  HIDWORD(v87) = v383 + HIDWORD(v51);
  LODWORD(v382) = HIDWORD(v41) ^ v382;
  LODWORD(v383) = BYTE3(v382);
  LODWORD(v382) = HIBYTE(v387) | ((_DWORD)v382 << 8);
  v388 = v383 | (v387 << 8);
  HIDWORD(v51) ^= LODWORD(m[2]) + HIDWORD(v192) + v382;
  v389 = m[2] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v388, v382);
  HIDWORD(v192) = HIDWORD(v389);
  HIDWORD(v587) = v389;
  HIDWORD(v382) ^= HIDWORD(v192);
  *(_DWORD *)v591 = HIDWORD(v192);
  HIDWORD(v569) = HIWORD(HIDWORD(v51)) | (HIDWORD(v382) << 16);
  LODWORD(v192) = v575;
  LODWORD(v575) = HIWORD(HIDWORD(v382)) | (HIDWORD(v51) << 16);
  LODWORD(v383) = (2 * v384) | ((unsigned int)v192 >> 31);
  v390 = (2 * v192) | (v384 >> 31);
  v96 = __CFADD__(HIDWORD(v87), HIDWORD(v569));
  *(_DWORD *)v612 = HIDWORD(v87) + HIDWORD(v569);
  *(_DWORD *)&v576[4] = (HIDWORD(v87) + HIDWORD(v569)) ^ v382;
  HIDWORD(v87) = (m[13] + __PAIR64__(*(unsigned int *)&v591[16], *(unsigned int *)&v576[16]) + __PAIR64__(v383, v390)) >> 32;
  LODWORD(v192) = LODWORD(m[13]) + *(_DWORD *)&v576[16] + v390;
  v564 = v575 + v96 + HIDWORD(v41);
  HIDWORD(v383) = v386 + (HIDWORD(v87) ^ v569);
  v391 = HIDWORD(v383) ^ v390;
  LODWORD(v41) = v41 + __CFADD__((_DWORD)v386, HIDWORD(v87) ^ v569) + (v192 ^ HIDWORD(v643));
  LODWORD(v383) = v383 ^ v41;
  *(_DWORD *)&v576[12] = v564 ^ v388;
  v392 = BYTE3(v383);
  LODWORD(v383) = HIBYTE(v391) | ((_DWORD)v383 << 8);
  HIDWORD(v192) = HIDWORD(m[7]);
  v393 = v392 | (v391 << 8);
  LODWORD(v51) = (LODWORD(m[7]) + v192 + v383) ^ HIDWORD(v87) ^ v569;
  v394 = __PAIR64__(HIDWORD(v87), m[7]) + v192 + __PAIR64__(v393, v383);
  *(_DWORD *)&v612[8] = HIDWORD(v394);
  *(_DWORD *)&v591[16] = v394;
  HIDWORD(v192) = (((unsigned int)v192 ^ HIDWORD(v643) ^ *(_DWORD *)&v612[8]) >> 16) | ((_DWORD)v51 << 16);
  v640 = WORD1(v51) | (((unsigned int)v192 ^ HIDWORD(v643) ^ *(_DWORD *)&v612[8]) << 16);
  LODWORD(v51) = (2 * v87) | (HIDWORD(v575) >> 31);
  LODWORD(v87) = (2 * HIDWORD(v575)) | ((unsigned int)v87 >> 31);
  LODWORD(v192) = *(_DWORD *)&v591[4];
  *(_DWORD *)&v591[4] = HIDWORD(v383) + v640;
  HIDWORD(v575) = (HIDWORD(v383) + v640) ^ v383;
  v395 = m[1] + __PAIR64__(*(unsigned int *)&v612[4], v192);
  *(_DWORD *)&v612[4] = HIDWORD(v192) + __CFADD__(HIDWORD(v383), v640) + (_DWORD)v41;
  v396 = v395 + __PAIR64__(v51, v87);
  *(_DWORD *)&v576[16] = *(_DWORD *)&v612[4] ^ v393;
  v397 = (v395 + v87) ^ v643;
  LODWORD(v87) = v87 ^ (*(_DWORD *)&v591[12] + (((v395 + __PAIR64__(v51, v87)) >> 32) ^ *(_DWORD *)v570));
  HIDWORD(v87) = (__PAIR64__(v568, *(unsigned int *)&v591[12])
                + __PAIR64__((unsigned int)v396 ^ (unsigned int)v643, HIDWORD(v396) ^ *(_DWORD *)v570)) >> 32;
  LODWORD(v383) = *(_DWORD *)&v591[12] + (HIDWORD(v396) ^ *(_DWORD *)v570);
  LODWORD(v51) = HIDWORD(v87) ^ v51;
  HIDWORD(v51) = (m[4] + v396) >> 32;
  HIDWORD(v383) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v383) |= (_DWORD)v87 << 8;
  LODWORD(v41) = HIDWORD(v396) ^ *(_DWORD *)v570 ^ (LODWORD(m[4]) + v396 + v51);
  v398 = ((__PAIR64__(HIDWORD(v383), LODWORD(m[4]) + (int)v396) + v51) >> 32) ^ v397;
  *(_DWORD *)&v612[12] = (__PAIR64__(HIDWORD(v383), LODWORD(m[4]) + (int)v396) + v51) >> 32;
  LODWORD(v569) = WORD1(v41) | (v398 << 16);
  *(_DWORD *)&v591[12] = LODWORD(m[4]) + v396 + v51;
  LODWORD(v643) = HIWORD(v398) | ((_DWORD)v41 << 16);
  v399 = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[8] >> 31);
  HIDWORD(v51) = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)v576 >> 31);
  v96 = __CFADD__((_DWORD)v383, (_DWORD)v569);
  LODWORD(v383) = v383 + v569;
  HIDWORD(v87) += v96 + (_DWORD)v643;
  *(_DWORD *)v576 = v383 ^ v51;
  HIDWORD(v382) = (LODWORD(m[10]) + v587 + v399) ^ *(_DWORD *)&v570[4];
  v400 = m[10] + __PAIR64__(*(unsigned int *)&v591[8], v587) + __PAIR64__(HIDWORD(v51), v399);
  *(_DWORD *)&v576[8] = HIDWORD(v87) ^ HIDWORD(v383);
  LODWORD(v382) = HIDWORD(v400) ^ *(_DWORD *)&v570[8];
  v401 = (HIDWORD(v568) + (HIDWORD(v400) ^ *(_DWORD *)&v570[8])) ^ v399;
  LODWORD(v87) = (__PAIR64__(*(unsigned int *)&v591[20], HIDWORD(v568)) + v382) >> 32;
  HIDWORD(v51) ^= v87;
  v402 = HIBYTE(v401) | (HIDWORD(v51) << 8);
  v403 = HIBYTE(HIDWORD(v51)) | (v401 << 8);
  v404 = m[5] + v400 + __PAIR64__(v403, v402);
  *(_DWORD *)&v591[8] = HIDWORD(v404);
  LODWORD(v192) = v404;
  LODWORD(v382) = v192 ^ HIDWORD(v400) ^ *(_DWORD *)&v570[8];
  HIDWORD(v382) ^= v403 + __CFADD__(LODWORD(m[5]) + v400, v402) + ((m[5] + v400) >> 32);
  LODWORD(v587) = LODWORD(m[5]) + v400 + v402;
  LODWORD(v192) = HIWORD(HIDWORD(v382));
  HIDWORD(v382) = v382 >> 16;
  LODWORD(v382) = v192 | ((_DWORD)v382 << 16);
  v405 = ((__PAIR64__(v87, HIDWORD(v568) + (HIDWORD(v400) ^ *(_DWORD *)&v570[8])) + __PAIR64__(v382, HIDWORD(v382))) >> 32)
       ^ v403;
  v406 = (HIDWORD(v568) + (HIDWORD(v400) ^ *(_DWORD *)&v570[8]) + HIDWORD(v382)) ^ v402;
  HIDWORD(v51) = 2 * v405;
  v407 = (2 * v406) | (v405 >> 31);
  v408 = HIDWORD(v51) | (v406 >> 31);
  v409 = m[10] + __PAIR64__(*(unsigned int *)v591, HIDWORD(v587)) + __PAIR64__(v408, v407);
  HIDWORD(v192) ^= HIDWORD(v409);
  v96 = __CFADD__((_DWORD)v383, HIDWORD(v192));
  LODWORD(v383) = v383 + HIDWORD(v192);
  v410 = v383 ^ v407;
  HIDWORD(v87) += v96 + (v640 ^ v409);
  v411 = HIDWORD(v87) ^ v408;
  HIDWORD(v51) = HIBYTE(v411);
  v412 = HIBYTE(v410) | (v411 << 8);
  v413 = HIDWORD(v51) | (v410 << 8);
  v414 = m[2] + v409 + __PAIR64__(v413, v412);
  HIDWORD(v192) ^= v414;
  HIDWORD(v41) = v640 ^ v409 ^ HIDWORD(v414);
  HIDWORD(v587) = LODWORD(m[2]) + v409 + v412;
  LODWORD(v192) = HIWORD(HIDWORD(v41));
  HIDWORD(v41) = HIWORD(HIDWORD(v192)) | (HIDWORD(v41) << 16);
  *(_DWORD *)v570 = v192 | (HIDWORD(v192) << 16);
  v96 = __CFADD__((_DWORD)v383, HIDWORD(v41));
  v641 = HIDWORD(v41);
  HIDWORD(v41) += v383;
  LODWORD(v41) = (2 * *(_DWORD *)&v576[4]) | (*(_DWORD *)&v576[12] >> 31);
  HIDWORD(v192) = (2 * *(_DWORD *)&v576[12]) | (*(_DWORD *)&v576[4] >> 31);
  v415 = *(_DWORD *)&v591[16];
  LODWORD(v568) = *(_DWORD *)v570 + v96 + HIDWORD(v87);
  LODWORD(v51) = HIDWORD(v41) ^ v412;
  *(_DWORD *)&v591[16] = HIDWORD(v41);
  HIDWORD(v41) = (LODWORD(m[8]) + v415 + v41) ^ v569;
  v416 = m[8] + __PAIR64__(*(unsigned int *)&v612[8], v415) + __PAIR64__(HIDWORD(v192), v41);
  *(_DWORD *)&v576[4] = v51;
  v417 = __PAIR64__(v87, HIDWORD(v568) + (HIDWORD(v400) ^ *(_DWORD *)&v570[8]))
       + __PAIR64__(v382, HIDWORD(v382))
       + __PAIR64__(HIDWORD(v41), HIDWORD(v416) ^ (unsigned int)v643);
  LODWORD(v87) = HIDWORD(v417);
  HIDWORD(v383) = v417;
  *(_DWORD *)&v576[12] = v568 ^ v413;
  LODWORD(v41) = v41 ^ HIDWORD(v383);
  HIDWORD(v192) ^= v87;
  LODWORD(v51) = HIBYTE(HIDWORD(v192));
  HIDWORD(v192) = BYTE3(v41) | (HIDWORD(v192) << 8);
  LODWORD(v41) = v51 | ((_DWORD)v41 << 8);
  LODWORD(v383) = HIDWORD(v416) ^ v643 ^ (LODWORD(m[4]) + v416 + HIDWORD(v192));
  HIDWORD(v41) ^= (_DWORD)v41 + __CFADD__(LODWORD(m[4]) + v416, HIDWORD(v192)) + ((m[4] + v416) >> 32);
  v418 = m[4] + v416 + __PAIR64__(v41, HIDWORD(v192));
  *(_DWORD *)&v612[8] = HIDWORD(v418);
  *(_DWORD *)&v591[20] = v418;
  *(_DWORD *)&v570[4] = WORD1(v383) | (HIDWORD(v41) << 16);
  LODWORD(v643) = HIWORD(HIDWORD(v41)) | ((_DWORD)v383 << 16);
  v419 = (2 * HIDWORD(v575)) | (*(_DWORD *)&v576[16] >> 31);
  v96 = __CFADD__(HIDWORD(v383), *(_DWORD *)&v570[4]);
  v420 = HIDWORD(v383) + *(_DWORD *)&v570[4];
  HIDWORD(v383) = (2 * *(_DWORD *)&v576[16]) | (HIDWORD(v575) >> 31);
  HIDWORD(v568) = v420;
  v421 = (v643 + v96 + (_DWORD)v87) ^ v41;
  v422 = __PAIR64__(*(unsigned int *)v612, *(unsigned int *)&v591[12]);
  HIDWORD(v87) = HIDWORD(v568) ^ HIDWORD(v192);
  *(_DWORD *)&v591[12] = v643 + v96 + (_DWORD)v87;
  v423 = m[7] + __PAIR64__(*(unsigned int *)&v612[12], v422) + __PAIR64__(HIDWORD(v383), v419);
  HIDWORD(v382) ^= v423;
  LODWORD(v382) = HIDWORD(v423) ^ v382;
  v424 = (*(_DWORD *)v612 + v382) ^ v419;
  HIDWORD(v41) = (__PAIR64__(v564, *(unsigned int *)v612) + v382) >> 32;
  LODWORD(v383) = *(_DWORD *)v612 + v382;
  HIDWORD(v383) ^= HIDWORD(v41);
  LODWORD(v41) = HIBYTE(v424) | (HIDWORD(v383) << 8);
  v425 = HIBYTE(HIDWORD(v383)) | (v424 << 8);
  v426 = (m[6] + v423 + __PAIR64__(v425, v41)) ^ v382;
  *(_DWORD *)v612 = LODWORD(m[6]) + v423 + v41;
  *(_DWORD *)&v570[8] = v426 >> 16;
  *(_DWORD *)&v612[12] = (m[6] + v423 + __PAIR64__(v425, v41)) >> 32;
  HIDWORD(v575) = HIWORD(HIDWORD(v426)) | ((_DWORD)v426 << 16);
  LODWORD(v87) = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[8] >> 31);
  LODWORD(v51) = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)v576 >> 31);
  *(_DWORD *)v576 = v383 + *(_DWORD *)&v570[8];
  HIDWORD(v41) += __CFADD__((_DWORD)v383, *(_DWORD *)&v570[8]) + HIDWORD(v575);
  v427 = HIDWORD(v41) ^ v425;
  LODWORD(v569) = (v383 + *(_DWORD *)&v570[8]) ^ v41;
  HIDWORD(v426) = (LODWORD(m[1]) + v587 + v87) ^ HIDWORD(v569);
  LODWORD(v192) = (m[1] + __PAIR64__(*(unsigned int *)&v591[8], v587) + __PAIR64__(v51, v87)) >> 32;
  HIDWORD(v192) = LODWORD(m[1]) + v587 + v87;
  HIDWORD(v51) = v192 ^ v575;
  LODWORD(v87) = v87 ^ (*(_DWORD *)&v591[4] + (v192 ^ v575));
  LODWORD(v41) = (__PAIR64__(*(unsigned int *)&v612[4], *(unsigned int *)&v591[4])
                + __PAIR64__(HIDWORD(v426), (unsigned int)v192 ^ (unsigned int)v575)) >> 32;
  HIDWORD(v383) = *(_DWORD *)&v591[4] + (v192 ^ v575);
  LODWORD(v51) = v41 ^ v51;
  LODWORD(v383) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  v428 = m[5] + __PAIR64__(v192, HIDWORD(v192));
  LODWORD(v192) = (m[5] + __PAIR64__(v192, HIDWORD(v192))) >> 32;
  HIDWORD(v51) ^= v428 + (_DWORD)v51;
  *(_DWORD *)&v591[4] = v428 + v51;
  LODWORD(v87) = v383 | ((_DWORD)v87 << 8);
  HIDWORD(v426) ^= v87 + __CFADD__((_DWORD)v428, (_DWORD)v51) + (_DWORD)v192;
  *(_DWORD *)&v591[8] = v87 + __CFADD__((_DWORD)v428, (_DWORD)v51) + (_DWORD)v192;
  LODWORD(v192) = HIWORD(HIDWORD(v426));
  HIDWORD(v426) = HIWORD(HIDWORD(v51)) | (HIDWORD(v426) << 16);
  LODWORD(v426) = (2 * v421) | (HIDWORD(v87) >> 31);
  HIDWORD(v51) = v192 | (HIDWORD(v51) << 16);
  v429 = (2 * HIDWORD(v87)) | (v421 >> 31);
  v430 = __PAIR64__(v41, HIDWORD(v383)) + __PAIR64__(HIDWORD(v51), HIDWORD(v426));
  LODWORD(v41) = (__PAIR64__(v41, HIDWORD(v383)) + __PAIR64__(HIDWORD(v51), HIDWORD(v426))) >> 32;
  HIDWORD(v569) = (HIDWORD(v383) + HIDWORD(v426)) ^ v51;
  LODWORD(v87) = v87 ^ v41;
  v431 = m[15] + __PAIR64__(HIDWORD(v414), HIDWORD(v587)) + __PAIR64__(v426, v429);
  HIDWORD(v426) ^= v431;
  HIDWORD(v51) ^= HIDWORD(v431);
  v432 = __PAIR64__(HIDWORD(v41), *(unsigned int *)v576) + __PAIR64__(HIDWORD(v426), HIDWORD(v51));
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), *(unsigned int *)v576) + __PAIR64__(HIDWORD(v426), HIDWORD(v51))) >> 32;
  v433 = v432 ^ v429;
  LODWORD(v426) = HIDWORD(v41) ^ v426;
  HIDWORD(v192) = BYTE3(v426);
  LODWORD(v426) = HIBYTE(v433) | ((_DWORD)v426 << 8);
  LODWORD(v192) = (m[11] + v431) >> 32;
  HIDWORD(v51) ^= LODWORD(m[11]) + v431 + (_DWORD)v426;
  *(_DWORD *)v591 = LODWORD(m[11]) + v431 + v426;
  v434 = HIDWORD(v192) | (v433 << 8);
  HIDWORD(v426) ^= v434 + __CFADD__(LODWORD(m[11]) + v431, (_DWORD)v426) + (_DWORD)v192;
  *(_DWORD *)&v612[4] = v434 + __CFADD__(LODWORD(m[11]) + v431, (_DWORD)v426) + (_DWORD)v192;
  LODWORD(v575) = HIWORD(HIDWORD(v51)) | (HIDWORD(v426) << 16);
  LODWORD(v383) = 2 * v427;
  v435 = (2 * v569) | (v427 >> 31);
  *(_DWORD *)v576 = HIWORD(HIDWORD(v426)) | (HIDWORD(v51) << 16);
  LODWORD(v383) = v383 | ((unsigned int)v569 >> 31);
  LODWORD(v569) = *(_DWORD *)v576 + __CFADD__((_DWORD)v432, (_DWORD)v575) + HIDWORD(v41);
  *(_DWORD *)&v576[8] = (v432 + v575) ^ v426;
  HIDWORD(v87) = (m[9] + __PAIR64__(*(unsigned int *)&v612[8], *(unsigned int *)&v591[20]) + __PAIR64__(v383, v435)) >> 32;
  LODWORD(v426) = LODWORD(m[9]) + *(_DWORD *)&v591[20] + v435;
  HIDWORD(v383) = v430 + (HIDWORD(v87) ^ *(_DWORD *)v570);
  v436 = HIDWORD(v383) ^ v435;
  LODWORD(v41) = v41 + __CFADD__((_DWORD)v430, HIDWORD(v87) ^ *(_DWORD *)v570) + (v426 ^ v641);
  LODWORD(v383) = v383 ^ v41;
  *(_DWORD *)&v576[16] = v569 ^ v434;
  v437 = BYTE3(v383);
  LODWORD(v383) = HIBYTE(v436) | ((_DWORD)v383 << 8);
  v438 = v437 | (v436 << 8);
  LODWORD(v51) = (LODWORD(m[14]) + v426 + v383) ^ HIDWORD(v87) ^ *(_DWORD *)v570;
  HIDWORD(v41) = v426 ^ v641 ^ ((m[14] + __PAIR64__(HIDWORD(v87), v426) + __PAIR64__(v438, v383)) >> 32);
  *(_DWORD *)&v612[8] = (m[14] + __PAIR64__(HIDWORD(v87), v426) + __PAIR64__(v438, v383)) >> 32;
  *(_DWORD *)&v591[20] = LODWORD(m[14]) + v426 + v383;
  HIDWORD(v192) = HIWORD(HIDWORD(v41));
  HIDWORD(v41) = WORD1(v51) | (HIDWORD(v41) << 16);
  HIDWORD(v192) |= (_DWORD)v51 << 16;
  LODWORD(v51) = (2 * v87) | (HIDWORD(v569) >> 31);
  LODWORD(v87) = (2 * HIDWORD(v569)) | ((unsigned int)v87 >> 31);
  HIDWORD(v569) = HIDWORD(v192) + __CFADD__(HIDWORD(v383), HIDWORD(v41)) + (_DWORD)v41;
  LODWORD(v41) = *(_DWORD *)v612;
  *(_DWORD *)v612 = HIDWORD(v383) + HIDWORD(v41);
  LODWORD(v587) = (HIDWORD(v383) + HIDWORD(v41)) ^ v383;
  v439 = m[3] + __PAIR64__(*(unsigned int *)&v612[12], v41) + __PAIR64__(v51, v87);
  HIDWORD(v587) = HIDWORD(v569) ^ v438;
  LODWORD(v87) = v87 ^ (*(_DWORD *)&v591[16] + (HIDWORD(v439) ^ v643));
  HIDWORD(v87) = (__PAIR64__(v568, *(unsigned int *)&v591[16])
                + __PAIR64__((unsigned int)v439 ^ *(_DWORD *)&v570[4], HIDWORD(v439) ^ (unsigned int)v643)) >> 32;
  LODWORD(v383) = *(_DWORD *)&v591[16] + (HIDWORD(v439) ^ v643);
  LODWORD(v51) = HIDWORD(v87) ^ v51;
  HIDWORD(v51) = (m[12] + v439) >> 32;
  HIDWORD(v383) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  *(_DWORD *)&v591[16] = LODWORD(m[12]) + v439 + v51;
  LODWORD(v426) = HIDWORD(v439) ^ v643 ^ *(_DWORD *)&v591[16];
  HIDWORD(v383) |= (_DWORD)v87 << 8;
  v440 = ((__PAIR64__(HIDWORD(v383), LODWORD(m[12]) + (int)v439) + v51) >> 32) ^ v439 ^ *(_DWORD *)&v570[4];
  *(_DWORD *)&v612[12] = (__PAIR64__(HIDWORD(v383), LODWORD(m[12]) + (int)v439) + v51) >> 32;
  *(_DWORD *)v570 = WORD1(v426) | (v440 << 16);
  *(_DWORD *)&v570[4] = HIWORD(v440) | ((_DWORD)v426 << 16);
  HIDWORD(v51) = (2 * *(_DWORD *)&v576[12]) | (*(_DWORD *)&v576[4] >> 31);
  v441 = (2 * *(_DWORD *)&v576[4]) | (*(_DWORD *)&v576[12] >> 31);
  v442 = __PAIR64__(HIDWORD(v87), v383) + *(_QWORD *)v570;
  HIDWORD(v87) = (__PAIR64__(HIDWORD(v87), v383) + *(_QWORD *)v570) >> 32;
  *(_DWORD *)&v576[4] = v442 ^ v51;
  v443 = m[13] + *(_QWORD *)&v591[4] + __PAIR64__(HIDWORD(v51), v441);
  HIDWORD(v426) = v443 ^ *(_DWORD *)&v570[8];
  *(_DWORD *)&v576[12] = HIDWORD(v87) ^ HIDWORD(v383);
  LODWORD(v426) = HIDWORD(v443) ^ HIDWORD(v575);
  v444 = (HIDWORD(v568) + (HIDWORD(v443) ^ HIDWORD(v575))) ^ v441;
  LODWORD(v87) = (__PAIR64__(*(unsigned int *)&v591[12], HIDWORD(v568)) + v426) >> 32;
  HIDWORD(v51) ^= v87;
  v445 = HIBYTE(v444) | (HIDWORD(v51) << 8);
  v446 = HIBYTE(HIDWORD(v51)) | (v444 << 8);
  v447 = m[0] + v443 + __PAIR64__(v446, v445);
  LODWORD(v426) = v447 ^ HIDWORD(v443) ^ HIDWORD(v575);
  HIDWORD(v426) = HIDWORD(v447) ^ v443 ^ *(_DWORD *)&v570[8];
  LODWORD(v192) = HIWORD(HIDWORD(v426));
  HIDWORD(v426) = v426 >> 16;
  LODWORD(v426) = v192 | ((_DWORD)v426 << 16);
  HIDWORD(v383) = HIDWORD(v568) + (HIDWORD(v443) ^ HIDWORD(v575)) + HIDWORD(v426);
  v448 = HIDWORD(v383) ^ v445;
  LODWORD(v87) = (__PAIR64__(v87, HIDWORD(v568) + (HIDWORD(v443) ^ HIDWORD(v575))) + __PAIR64__(v426, HIDWORD(v426))) >> 32;
  v449 = v87 ^ v446;
  HIDWORD(v51) = 2 * v449;
  v450 = (2 * v448) | (v449 >> 31);
  v451 = HIDWORD(v51) | (v448 >> 31);
  v452 = m[0] + __PAIR64__(*(unsigned int *)&v612[4], *(unsigned int *)v591) + __PAIR64__(v451, v450);
  HIDWORD(v41) ^= v452;
  HIDWORD(v192) ^= HIDWORD(v452);
  LODWORD(v383) = v442 + HIDWORD(v192);
  v453 = (v442 + HIDWORD(v192)) ^ v450;
  HIDWORD(v87) += __CFADD__((_DWORD)v442, HIDWORD(v192)) + HIDWORD(v41);
  v454 = HIDWORD(v87) ^ v451;
  HIDWORD(v51) = HIBYTE(v454);
  v455 = HIBYTE(v453) | (v454 << 8);
  v456 = HIDWORD(v51) | (v453 << 8);
  HIDWORD(v192) ^= LODWORD(m[1]) + v452 + v455;
  *(_DWORD *)v591 = LODWORD(m[1]) + v452 + v455;
  HIDWORD(v41) ^= (m[1] + v452 + __PAIR64__(v456, v455)) >> 32;
  *(_DWORD *)&v591[12] = (m[1] + v452 + __PAIR64__(v456, v455)) >> 32;
  *(_DWORD *)&v570[8] = HIWORD(HIDWORD(v192)) | (HIDWORD(v41) << 16);
  LODWORD(v51) = HIWORD(HIDWORD(v41)) | (HIDWORD(v192) << 16);
  LODWORD(v41) = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)&v576[16] >> 31);
  HIDWORD(v192) = (2 * *(_DWORD *)&v576[16]) | (*(_DWORD *)&v576[8] >> 31);
  v642 = v51;
  LODWORD(v568) = v383 + *(_DWORD *)&v570[8];
  v457 = *(_DWORD *)&v591[20];
  *(_DWORD *)&v591[20] = v51 + __CFADD__((_DWORD)v383, *(_DWORD *)&v570[8]) + HIDWORD(v87);
  *(_DWORD *)&v576[16] = *(_DWORD *)&v591[20] ^ v456;
  *(_DWORD *)&v576[8] = (v383 + *(_DWORD *)&v570[8]) ^ v455;
  LODWORD(v192) = LODWORD(m[2]) + v457;
  HIDWORD(v87) = (v192 + __PAIR64__((m[2] + __PAIR64__(*(unsigned int *)&v612[8], v457)) >> 32, v41)) >> 32;
  LODWORD(v192) = LODWORD(m[2]) + v457 + v41;
  LODWORD(v383) = *(_DWORD *)&v570[4] ^ HIDWORD(v87);
  HIDWORD(v383) += *(_DWORD *)&v570[4] ^ HIDWORD(v87);
  LODWORD(v87) = v87
               + __CFADD__(
                   HIDWORD(v568) + (HIDWORD(v443) ^ HIDWORD(v575)) + HIDWORD(v426),
                   *(_DWORD *)&v570[4] ^ HIDWORD(v87))
               + (v192 ^ *(_DWORD *)v570);
  HIDWORD(v192) ^= v87;
  v458 = m[3] + __PAIR64__(HIDWORD(v87), v192);
  HIDWORD(v87) = (m[3] + __PAIR64__(HIDWORD(v87), v192)) >> 32;
  LODWORD(v51) = HIBYTE(HIDWORD(v192));
  HIDWORD(v192) = (((unsigned int)v41 ^ HIDWORD(v383)) >> 24) | (HIDWORD(v192) << 8);
  LODWORD(v41) = v51 | (((unsigned int)v41 ^ HIDWORD(v383)) << 8);
  LODWORD(v383) = v383 ^ (v458 + HIDWORD(v192));
  HIDWORD(v41) = v192 ^ *(_DWORD *)v570 ^ (v41 + __CFADD__((_DWORD)v458, HIDWORD(v192)) + HIDWORD(v87));
  HIDWORD(v568) = v41 + __CFADD__((_DWORD)v458, HIDWORD(v192)) + HIDWORD(v87);
  *(_DWORD *)&v612[4] = v458 + HIDWORD(v192);
  *(_DWORD *)&v570[4] = WORD1(v383) | (HIDWORD(v41) << 16);
  *(_DWORD *)&v612[8] = HIWORD(HIDWORD(v41)) | ((_DWORD)v383 << 16);
  v459 = (2 * v587) | (HIDWORD(v587) >> 31);
  v96 = __CFADD__(HIDWORD(v383), *(_DWORD *)&v570[4]);
  v460 = HIDWORD(v383) + *(_DWORD *)&v570[4];
  HIDWORD(v383) = v587 >> 31;
  *(_DWORD *)v570 = v460;
  v461 = (*(_DWORD *)&v612[8] + v96 + (_DWORD)v87) ^ v41;
  LODWORD(v587) = *(_DWORD *)&v612[8] + v96 + (_DWORD)v87;
  HIDWORD(v87) = *(_DWORD *)v570 ^ HIDWORD(v192);
  v462 = m[4] + __PAIR64__(*(unsigned int *)&v612[12], *(unsigned int *)&v591[16]) + __PAIR64__(HIDWORD(v383), v459);
  HIDWORD(v426) ^= v462;
  LODWORD(v426) = HIDWORD(v462) ^ v426;
  v463 = (v432 + v575 + v426) ^ v459;
  HIDWORD(v41) = (__PAIR64__(v569, (int)v432 + (int)v575) + v426) >> 32;
  LODWORD(v383) = v432 + v575 + v426;
  HIDWORD(v383) ^= HIDWORD(v41);
  LODWORD(v41) = HIBYTE(v463) | (HIDWORD(v383) << 8);
  v464 = HIBYTE(HIDWORD(v383)) | (v463 << 8);
  v465 = (m[5] + v462 + __PAIR64__(v464, v41)) ^ v426;
  *(_DWORD *)&v591[16] = (m[5] + v462 + __PAIR64__(v464, v41)) >> 32;
  HIDWORD(v587) = LODWORD(m[5]) + v462 + v41;
  HIDWORD(v192) = *(_DWORD *)&v576[4];
  HIDWORD(v575) = v465 >> 16;
  *(_DWORD *)&v576[4] = HIWORD(HIDWORD(v465)) | ((_DWORD)v465 << 16);
  LODWORD(v192) = HIDWORD(v575);
  LODWORD(v87) = (2 * HIDWORD(v192)) | (*(_DWORD *)&v576[12] >> 31);
  LODWORD(v51) = (2 * *(_DWORD *)&v576[12]) | (HIDWORD(v192) >> 31);
  HIDWORD(v192) = *(_DWORD *)&v576[4];
  HIDWORD(v51) = (v383 + HIDWORD(v575)) ^ v41;
  v466 = __PAIR64__(HIDWORD(v41), v383) + v192;
  v467 = HIDWORD(v466) ^ v464;
  v565 = HIDWORD(v51);
  LODWORD(v192) = (m[6] + v447 + __PAIR64__(v51, v87)) >> 32;
  HIDWORD(v192) = LODWORD(m[6]) + v447 + v87;
  LODWORD(v87) = v87 ^ (*(_DWORD *)v612 + (v192 ^ *(_DWORD *)v576));
  v468 = __PAIR64__(HIDWORD(v569), *(unsigned int *)v612)
       + __PAIR64__(HIDWORD(v192) ^ (unsigned int)v575, (unsigned int)v192 ^ *(_DWORD *)v576);
  LODWORD(v41) = (__PAIR64__(HIDWORD(v569), *(unsigned int *)v612)
                + __PAIR64__(HIDWORD(v192) ^ (unsigned int)v575, (unsigned int)v192 ^ *(_DWORD *)v576)) >> 32;
  LODWORD(v51) = v41 ^ v51;
  HIDWORD(v41) = BYTE3(v51);
  LODWORD(v51) = BYTE3(v87) | ((_DWORD)v51 << 8);
  HIDWORD(v51) = (LODWORD(m[7]) + HIDWORD(v192) + v51) ^ v192 ^ *(_DWORD *)v576;
  *(_DWORD *)&v591[4] = LODWORD(m[7]) + HIDWORD(v192) + v51;
  LODWORD(v87) = HIDWORD(v41) | ((_DWORD)v87 << 8);
  LODWORD(v192) = v87
                + __CFADD__(LODWORD(m[7]) + HIDWORD(v192), (_DWORD)v51)
                + ((m[7] + __PAIR64__(v192, HIDWORD(v192))) >> 32);
  HIDWORD(v465) = v192 ^ HIDWORD(v192) ^ v575;
  *(_DWORD *)&v591[8] = v192;
  LODWORD(v192) = HIWORD(HIDWORD(v465));
  HIDWORD(v465) = HIWORD(HIDWORD(v51)) | (HIDWORD(v465) << 16);
  LODWORD(v465) = (2 * v461) | (HIDWORD(v87) >> 31);
  HIDWORD(v51) = v192 | (HIDWORD(v51) << 16);
  v469 = (2 * HIDWORD(v87)) | (v461 >> 31);
  v470 = __PAIR64__(v41, v468) + __PAIR64__(HIDWORD(v51), HIDWORD(v465));
  LODWORD(v41) = (__PAIR64__(v41, v468) + __PAIR64__(HIDWORD(v51), HIDWORD(v465))) >> 32;
  *(_DWORD *)v576 = v470 ^ v51;
  LODWORD(v87) = v87 ^ v41;
  LODWORD(v192) = (m[8] + __PAIR64__(*(unsigned int *)&v591[12], *(unsigned int *)v591) + __PAIR64__(v465, v469)) >> 32;
  HIDWORD(v192) = LODWORD(m[8]) + *(_DWORD *)v591 + v469;
  HIDWORD(v465) ^= HIDWORD(v192);
  HIDWORD(v51) ^= v192;
  v471 = (v466 + HIDWORD(v51)) ^ v469;
  HIDWORD(v41) = (v466 + __PAIR64__(HIDWORD(v465), HIDWORD(v51))) >> 32;
  HIDWORD(v87) = v466 + HIDWORD(v51);
  LODWORD(v465) = HIDWORD(v41) ^ v465;
  LODWORD(v466) = BYTE3(v465);
  LODWORD(v465) = HIBYTE(v471) | ((_DWORD)v465 << 8);
  v472 = v466 | (v471 << 8);
  HIDWORD(v51) ^= LODWORD(m[9]) + HIDWORD(v192) + v465;
  *(_DWORD *)v591 = LODWORD(m[9]) + HIDWORD(v192) + v465;
  HIDWORD(v465) ^= (m[9] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v472, v465)) >> 32;
  *(_DWORD *)&v591[12] = (m[9] + __PAIR64__(v192, HIDWORD(v192)) + __PAIR64__(v472, v465)) >> 32;
  HIDWORD(v569) = HIWORD(HIDWORD(v51)) | (HIDWORD(v465) << 16);
  LODWORD(v575) = HIWORD(HIDWORD(v465)) | (HIDWORD(v51) << 16);
  HIDWORD(v192) = 2 * v467;
  LODWORD(v569) = HIDWORD(v87) + HIDWORD(v569);
  v473 = (2 * v565) | (v467 >> 31);
  LODWORD(v466) = v565;
  v566 = v575 + __CFADD__(HIDWORD(v87), HIDWORD(v569)) + HIDWORD(v41);
  HIDWORD(v192) |= (unsigned int)v466 >> 31;
  HIDWORD(v465) = (HIDWORD(v87) + HIDWORD(v569)) ^ v465;
  LODWORD(v192) = LODWORD(m[10]) + *(_DWORD *)&v612[4];
  HIDWORD(v41) = (v192 + __PAIR64__((m[10] + __PAIR64__(HIDWORD(v568), *(unsigned int *)&v612[4])) >> 32, v473)) >> 32;
  LODWORD(v466) = LODWORD(m[10]) + *(_DWORD *)&v612[4] + v473;
  LODWORD(v51) = v466 ^ *(_DWORD *)&v570[8];
  LODWORD(v465) = (__PAIR64__(v41, v470) + __PAIR64__((unsigned int)v466 ^ *(_DWORD *)&v570[8], HIDWORD(v41) ^ v642)) >> 32;
  HIDWORD(v466) = v470 + (HIDWORD(v41) ^ v642);
  v474 = HIDWORD(v466) ^ v473;
  HIDWORD(v192) ^= v465;
  HIDWORD(v87) = HIBYTE(v474) | (HIDWORD(v192) << 8);
  *(_DWORD *)&v570[8] = v566 ^ v472;
  v475 = HIBYTE(HIDWORD(v192));
  HIDWORD(v192) = HIDWORD(v587);
  v476 = v475 | (v474 << 8);
  LODWORD(v192) = HIDWORD(v41) ^ v642 ^ (LODWORD(m[11]) + v466 + HIDWORD(v87));
  *(_QWORD *)v612 = m[11] + __PAIR64__(HIDWORD(v41), v466) + __PAIR64__(v476, HIDWORD(v87));
  LODWORD(v51) = *(_DWORD *)&v612[4] ^ v51;
  HIDWORD(v51) = (2 * v87) | (*(_DWORD *)v576 >> 31);
  *(_DWORD *)&v612[12] = WORD1(v192) | ((_DWORD)v51 << 16);
  *(_DWORD *)&v612[16] = WORD1(v51) | ((_DWORD)v192 << 16);
  LODWORD(v87) = (2 * *(_DWORD *)v576) | ((unsigned int)v87 >> 31);
  HIDWORD(v568) = (__PAIR64__(v465, HIDWORD(v466)) + *(_QWORD *)&v612[12]) >> 32;
  HIDWORD(v587) = HIDWORD(v466) + *(_DWORD *)&v612[12];
  LODWORD(v466) = (m[12] + __PAIR64__(*(unsigned int *)&v591[16], HIDWORD(v192)) + __PAIR64__(HIDWORD(v51), v87)) >> 32;
  LODWORD(v465) = LODWORD(m[12]) + HIDWORD(v192) + v87;
  HIDWORD(v41) = v465 ^ *(_DWORD *)&v570[4];
  *(_DWORD *)v576 = (HIDWORD(v466) + *(_DWORD *)&v612[12]) ^ HIDWORD(v87);
  LODWORD(v41) = *(_DWORD *)&v612[8] ^ v466;
  *(_DWORD *)&v576[12] = HIDWORD(v568) ^ v476;
  LODWORD(v87) = v87 ^ (v568 + (*(_DWORD *)&v612[8] ^ v466));
  HIDWORD(v87) = (__PAIR64__(*(unsigned int *)&v591[20], v568) + v41) >> 32;
  LODWORD(v192) = v568 + (*(_DWORD *)&v612[8] ^ v466);
  HIDWORD(v192) = HIDWORD(v87) ^ HIDWORD(v51);
  HIDWORD(v51) = BYTE3(v87) | ((HIDWORD(v87) ^ HIDWORD(v51)) << 8);
  LODWORD(v51) = HIBYTE(HIDWORD(v192)) | ((_DWORD)v87 << 8);
  v477 = m[13] + __PAIR64__(v466, v465) + __PAIR64__(v51, HIDWORD(v51));
  HIDWORD(v466) = v477 ^ *(_DWORD *)&v612[8] ^ v466;
  HIDWORD(v41) = v465 ^ *(_DWORD *)&v570[4] ^ HIDWORD(v477);
  *(_DWORD *)&v570[4] = HIWORD(HIDWORD(v466)) | (HIDWORD(v41) << 16);
  *(_DWORD *)&v612[8] = HIWORD(HIDWORD(v41)) | (HIDWORD(v466) << 16);
  HIDWORD(v192) = (2 * *(_DWORD *)&v576[16]) | (*(_DWORD *)&v576[8] >> 31);
  HIDWORD(v466) = (__PAIR64__(HIDWORD(v87), v192) + __PAIR64__(*(unsigned int *)&v612[8], *(unsigned int *)&v570[4])) >> 32;
  LODWORD(v192) = v192 + *(_DWORD *)&v570[4];
  HIDWORD(v51) ^= v192;
  LODWORD(v41) = (2 * *(_DWORD *)&v576[8]) | (*(_DWORD *)&v576[16] >> 31);
  LODWORD(v568) = HIDWORD(v466);
  LODWORD(v87) = LODWORD(m[14]) + *(_DWORD *)&v591[4] + v41;
  v478 = (m[14] + *(_QWORD *)&v591[4] + __PAIR64__(HIDWORD(v192), v41)) >> 32;
  LODWORD(v465) = v87 ^ HIDWORD(v575);
  v479 = v478 ^ *(_DWORD *)&v576[4];
  LODWORD(v51) = HIDWORD(v466) ^ v51;
  LODWORD(v41) = v41 ^ (*(_DWORD *)v570 + (v478 ^ *(_DWORD *)&v576[4]));
  HIDWORD(v41) = (__PAIR64__(v587, *(unsigned int *)v570)
                + __PAIR64__((unsigned int)v87 ^ HIDWORD(v575), v478 ^ *(_DWORD *)&v576[4])) >> 32;
  LODWORD(v466) = *(_DWORD *)v570 + (v478 ^ *(_DWORD *)&v576[4]);
  HIDWORD(v192) ^= HIDWORD(v41);
  v481 = m[15] + __PAIR64__(v478, v87);
  v480 = (m[15] + __PAIR64__(v478, v87)) >> 32;
  LODWORD(v87) = v481;
  HIDWORD(v466) = BYTE3(v41) | (HIDWORD(v192) << 8);
  HIDWORD(v87) = HIBYTE(HIDWORD(v192)) | ((_DWORD)v41 << 8);
  v483 = v87 + __PAIR64__(v480, HIDWORD(v466));
  v482 = (v87 + __PAIR64__(v480, HIDWORD(v466))) >> 32;
  v484 = v483 ^ v479;
  *(_QWORD *)&v576[4] = __PAIR64__(v482, v483);
  LODWORD(v465) = v482 ^ v465;
  HIDWORD(v192) = HIWORD(v484) | ((_DWORD)v465 << 16);
  v96 = __CFADD__((_DWORD)v466, HIDWORD(v192));
  LODWORD(v466) = v466 + HIDWORD(v192);
  LODWORD(v587) = HIDWORD(v192);
  HIDWORD(v41) += v96 + (WORD1(v465) | (v484 << 16));
  *(_DWORD *)&v591[4] = WORD1(v465) | (v484 << 16);
  *(_DWORD *)&v576[16] = (2 * HIDWORD(v465)) | (*(_DWORD *)&v570[8] >> 31);
  HIDWORD(v87) ^= HIDWORD(v41);
  LODWORD(v465) = 2 * HIDWORD(v87);
  HIDWORD(v87) = (2 * (HIDWORD(v466) ^ v466)) | (HIDWORD(v87) >> 31);
  LODWORD(v41) = (2 * *(_DWORD *)&v570[8]) | (HIDWORD(v465) >> 31);
  v538 = (2 * *(_DWORD *)&v576[12]) | (*(_DWORD *)v576 >> 31);
  v485 = m[14]
       + __PAIR64__(*(unsigned int *)&v591[12], *(unsigned int *)v591)
       + __PAIR64__((unsigned int)v465 | ((HIDWORD(v466) ^ (unsigned int)v466) >> 31), HIDWORD(v87));
  *(_DWORD *)&v576[12] = (2 * *(_DWORD *)v576) | (*(_DWORD *)&v576[12] >> 31);
  HIDWORD(v465) = 2 * v51;
  LODWORD(v51) = v51 >> 31;
  HIDWORD(v51) = HIDWORD(v465) | (HIDWORD(v51) >> 31);
  HIDWORD(v465) = HIDWORD(v87) ^ (v192 + (HIDWORD(v485) ^ *(_DWORD *)&v612[16]));
  v486 = v51;
  *(_DWORD *)v576 = v192 + (HIDWORD(v485) ^ *(_DWORD *)&v612[16]);
  LODWORD(v87) = (__PAIR64__(v568, v192)
                + __PAIR64__((unsigned int)v485 ^ *(_DWORD *)&v612[12], HIDWORD(v485) ^ *(_DWORD *)&v612[16])) >> 32;
  HIDWORD(v466) = (v465 | ((HIDWORD(v466) ^ (unsigned int)v466) >> 31)) ^ v87;
  HIDWORD(v192) = HIBYTE(HIDWORD(v465)) | (HIDWORD(v466) << 8);
  HIDWORD(v87) = HIBYTE(HIDWORD(v466)) | (HIDWORD(v465) << 8);
  v487 = m[10] + v485 + __PAIR64__(HIDWORD(v87), HIDWORD(v192));
  LODWORD(v568) = HIDWORD(v487);
  LODWORD(v192) = v487;
  v488 = v192 ^ HIDWORD(v485) ^ *(_DWORD *)&v612[16];
  LODWORD(v51) = (HIDWORD(v87) + __CFADD__(LODWORD(m[10]) + v485, HIDWORD(v192)) + ((m[10] + v485) >> 32))
               ^ v485
               ^ *(_DWORD *)&v612[12];
  v546 = LODWORD(m[10]) + v485 + HIDWORD(v192);
  HIDWORD(v575) = HIWORD(v488) | ((_DWORD)v51 << 16);
  HIDWORD(v466) = WORD1(v51) | (v488 << 16);
  v96 = __CFADD__(*(_DWORD *)v576, HIDWORD(v575));
  v489 = *(_DWORD *)v576 + HIDWORD(v575);
  *(_DWORD *)v576 = HIDWORD(v466);
  v531 = v489;
  v536 = HIDWORD(v466) + v96 + (_DWORD)v87;
  LODWORD(v51) = (LODWORD(m[4]) + *(_DWORD *)v612 + *(_DWORD *)&v576[16]) ^ *(_DWORD *)&v570[4];
  v490 = (m[4] + *(_QWORD *)v612 + __PAIR64__(v41, *(unsigned int *)&v576[16])) >> 32;
  HIDWORD(v465) = v490 ^ *(_DWORD *)&v612[8];
  v491 = (v466 + (v490 ^ *(_DWORD *)&v612[8])) ^ *(_DWORD *)&v576[16];
  v492 = __PAIR64__(HIDWORD(v41), v466) + __PAIR64__(v51, v490 ^ *(_DWORD *)&v612[8]);
  HIDWORD(v41) = (__PAIR64__(HIDWORD(v41), v466) + __PAIR64__(v51, v490 ^ *(_DWORD *)&v612[8])) >> 32;
  LODWORD(v41) = v41 ^ HIDWORD(v41);
  LODWORD(v87) = BYTE3(v41);
  LODWORD(v41) = HIBYTE(v491) | ((_DWORD)v41 << 8);
  LODWORD(v87) = v87 | (v491 << 8);
  HIDWORD(v87) ^= v536;
  v494 = m[8] + __PAIR64__(v490, LODWORD(m[4]) + *(_DWORD *)v612 + *(_DWORD *)&v576[16]);
  v493 = (m[8] + __PAIR64__(v490, LODWORD(m[4]) + *(_DWORD *)v612 + *(_DWORD *)&v576[16])) >> 32;
  HIDWORD(v465) ^= v494 + (_DWORD)v41;
  *(_DWORD *)&v576[16] = (2 * (v531 ^ HIDWORD(v192))) | (HIDWORD(v87) >> 31);
  LODWORD(v51) = ((__PAIR64__(v493, v494) + __PAIR64__(v87, v41)) >> 32) ^ v51;
  *(_DWORD *)&v570[4] = (__PAIR64__(v493, v494) + __PAIR64__(v87, v41)) >> 32;
  v545 = v494 + v41;
  *(_DWORD *)v591 = (2 * HIDWORD(v87)) | (((unsigned int)v531 ^ HIDWORD(v192)) >> 31);
  *(_DWORD *)&v591[8] = HIWORD(HIDWORD(v465)) | ((_DWORD)v51 << 16);
  v528 = __PAIR64__(HIDWORD(v41), v492) + __PAIR64__(WORD1(v51) | (HIDWORD(v465) << 16), *(unsigned int *)&v591[8]);
  *(_DWORD *)&v591[12] = WORD1(v51) | (HIDWORD(v465) << 16);
  LODWORD(v41) = v41 ^ (v492 + *(_DWORD *)&v591[8]);
  v495 = m[9] + v477 + __PAIR64__(v538, *(unsigned int *)&v576[12]);
  HIDWORD(v465) = (v569 + (HIDWORD(v495) ^ *(_DWORD *)&v591[4])) ^ *(_DWORD *)&v576[12];
  HIDWORD(v51) = HIBYTE(HIDWORD(v465))
               | ((((__PAIR64__(v566, v569)
                   + __PAIR64__((unsigned int)v495 ^ (unsigned int)v587, HIDWORD(v495) ^ *(_DWORD *)&v591[4])) >> 32)
                 ^ (unsigned int)v538) << 8);
  HIDWORD(v87) = ((((__PAIR64__(v566, v569)
                   + __PAIR64__((unsigned int)v495 ^ (unsigned int)v587, HIDWORD(v495) ^ *(_DWORD *)&v591[4])) >> 32)
                 ^ (unsigned int)v538) >> 24)
               | (HIDWORD(v465) << 8);
  v496 = LODWORD(m[15]) + LODWORD(m[9]) + v477 + *(_DWORD *)&v576[12];
  v497 = (v496 + HIDWORD(v51)) ^ HIDWORD(v495) ^ *(_DWORD *)&v591[4];
  v542 = (2 * v41) | ((HIDWORD(v528) ^ (unsigned int)v87) >> 31);
  LODWORD(v465) = ((m[15] + v495 + __PAIR64__(HIDWORD(v87), HIDWORD(v51))) >> 32) ^ v495 ^ v587;
  v539 = (m[15] + v495 + __PAIR64__(HIDWORD(v87), HIDWORD(v51))) >> 32;
  LODWORD(v529) = (2 * (HIDWORD(v528) ^ v87)) | ((unsigned int)v41 >> 31);
  HIDWORD(v529) = v496 + HIDWORD(v51);
  v544 = HIWORD(v497) | ((_DWORD)v465 << 16);
  HIDWORD(v41) = (__PAIR64__(v566, v569)
                + __PAIR64__((unsigned int)v495 ^ (unsigned int)v587, HIDWORD(v495) ^ *(_DWORD *)&v591[4])
                + __PAIR64__(WORD1(v465) | (v497 << 16), v544)) >> 32;
  HIDWORD(v192) = v569 + (HIDWORD(v495) ^ *(_DWORD *)&v591[4]) + v544;
  v567 = WORD1(v465) | (v497 << 16);
  HIDWORD(v87) ^= HIDWORD(v41);
  v498 = m[13] + *(_QWORD *)&v576[4] + v486;
  v525 = HIDWORD(v192) ^ HIDWORD(v51);
  v499 = (__PAIR64__(HIDWORD(v568), HIDWORD(v587))
        + __PAIR64__((unsigned int)v498 ^ HIDWORD(v569), HIDWORD(v498) ^ (unsigned int)v575))
       ^ v486;
  HIDWORD(v465) = v499 >> 24;
  LODWORD(v465) = HIBYTE(HIDWORD(v499)) | ((_DWORD)v499 << 8);
  v500 = (LODWORD(m[6]) + LODWORD(m[13]) + *(_DWORD *)&v576[4] + v486 + HIDWORD(v465)) ^ HIDWORD(v498) ^ v575;
  *(_QWORD *)&v533[4] = m[6] + v498 + __PAIR64__(v465, HIDWORD(v465));
  v527 = (2 * v525) | (HIDWORD(v87) >> 31);
  v501 = *(_DWORD *)&v533[8] ^ v498 ^ HIDWORD(v569);
  LODWORD(v87) = HIWORD(v500) | (v501 << 16);
  v502 = __PAIR64__(HIDWORD(v568), HIDWORD(v587))
       + __PAIR64__((unsigned int)v498 ^ HIDWORD(v569), HIDWORD(v498) ^ (unsigned int)v575)
       + __PAIR64__(HIWORD(v501) | (v500 << 16), v87);
  HIDWORD(v499) = HIWORD(v501) | (v500 << 16);
  HIDWORD(v465) ^= v502;
  v526 = (2 * HIDWORD(v87)) | (v525 >> 31);
  LODWORD(v465) = HIDWORD(v502) ^ v465;
  v503 = m[1] + __PAIR64__(v568, v546) + __PAIR64__(v529, v542);
  v96 = __CFADD__(HIDWORD(v192), HIDWORD(v503) ^ HIDWORD(v499));
  HIDWORD(v192) += HIDWORD(v503) ^ HIDWORD(v499);
  HIDWORD(v41) += v96 + (v87 ^ (LODWORD(m[1]) + v546 + v542));
  HIDWORD(v87) = ((HIDWORD(v192) ^ v542) >> 24) | ((HIDWORD(v41) ^ (unsigned int)v529) << 8);
  v504 = ((HIDWORD(v41) ^ (unsigned int)v529) >> 24) | ((HIDWORD(v192) ^ v542) << 8);
  LODWORD(v529) = (2 * v465) | (HIDWORD(v465) >> 31);
  v[0] = m[12] + v503 + __PAIR64__(v504, HIDWORD(v87));
  LODWORD(v466) = HIDWORD(v503) ^ HIDWORD(v499) ^ LODWORD(v[0]);
  HIDWORD(v466) = v87 ^ (LODWORD(m[1]) + v546 + v542) ^ HIDWORD(v[0]);
  LODWORD(v87) = v466 >> 16;
  v96 = __CFADD__(HIDWORD(v192), (_DWORD)v87);
  HIDWORD(v192) += v87;
  LODWORD(v[15]) = v87;
  HIDWORD(v[15]) = HIWORD(HIDWORD(v466)) | ((_DWORD)v466 << 16);
  HIDWORD(v41) += v96 + HIDWORD(v[15]);
  HIDWORD(v87) ^= HIDWORD(v192);
  v505 = HIDWORD(v41) ^ v504;
  v[10] = __PAIR64__(HIDWORD(v41), HIDWORD(v192));
  v506 = m[0] + __PAIR64__(*(unsigned int *)&v570[4], v545) + __PAIR64__(v526, v527);
  HIDWORD(v499) = v506 ^ HIDWORD(v575);
  LODWORD(v499) = HIDWORD(v506) ^ *(_DWORD *)v576;
  LODWORD(v41) = (v502 + v499) >> 32;
  v524 = v502 + (HIDWORD(v506) ^ *(_DWORD *)v576);
  LODWORD(v87) = ((v524 ^ v527) >> 24) | (((unsigned int)v41 ^ v526) << 8);
  v507 = (((unsigned int)v41 ^ v526) >> 24) | ((v524 ^ v527) << 8);
  LODWORD(v[5]) = (2 * HIDWORD(v87)) | (v505 >> 31);
  LODWORD(v499) = (LODWORD(m[2]) + LODWORD(m[0]) + v545 + v527 + v87) ^ HIDWORD(v506) ^ *(_DWORD *)v576;
  v[1] = m[2] + v506 + __PAIR64__(v507, v87);
  HIDWORD(v499) = HIDWORD(v[1]) ^ v506 ^ HIDWORD(v575);
  LODWORD(v[12]) = v499 >> 16;
  HIDWORD(v[12]) = HIWORD(HIDWORD(v499)) | ((_DWORD)v499 << 16);
  HIDWORD(v[5]) = (2 * v505) | (HIDWORD(v87) >> 31);
  LODWORD(v87) = v87 ^ (v524 + LODWORD(v[12]));
  v508 = v41 ^ v507;
  v509 = m[11] + __PAIR64__(v539, HIDWORD(v529)) + __PAIR64__(v529, v465 >> 31);
  HIDWORD(v499) = v509 ^ *(_DWORD *)&v591[8];
  LODWORD(v499) = HIDWORD(v509) ^ *(_DWORD *)&v591[12];
  v510 = __PAIR64__(v536, v531) + v499;
  LODWORD(v465) = (v531 + (HIDWORD(v509) ^ *(_DWORD *)&v591[12])) ^ (v465 >> 31);
  HIDWORD(v465) = ((__PAIR64__(v536, v531) + v499) >> 32) ^ v529;
  HIDWORD(v87) = v465 >> 24;
  v511 = HIBYTE(HIDWORD(v465)) | ((_DWORD)v465 << 8);
  LODWORD(v499) = (LODWORD(m[7]) + v509 + HIDWORD(v87)) ^ HIDWORD(v509) ^ *(_DWORD *)&v591[12];
  HIDWORD(v499) = ((m[7] + v509 + __PAIR64__(v511, HIDWORD(v87))) >> 32) ^ v509 ^ *(_DWORD *)&v591[8];
  LODWORD(v[13]) = v499 >> 16;
  v[11] = __PAIR64__(v41, v524) + v[12];
  HIDWORD(v[13]) = HIWORD(HIDWORD(v499)) | ((_DWORD)v499 << 16);
  v512 = v510 + v[13];
  HIDWORD(v[6]) = (2 * v508) | ((unsigned int)v87 >> 31);
  LODWORD(v[6]) = (2 * v87) | (v508 >> 31);
  HIDWORD(v[2]) = (m[7] + v509 + __PAIR64__(v511, HIDWORD(v87))) >> 32;
  v513 = ((v510 + v[13]) >> 32) ^ v511;
  v514 = m[5] + *(_QWORD *)&v533[4] + __PAIR64__(*(unsigned int *)v591, *(unsigned int *)&v576[16]);
  v[8] = v510 + v[13];
  LODWORD(v465) = (v528 + (HIDWORD(v514) ^ v567)) ^ *(_DWORD *)&v576[16];
  LODWORD(v87) = ((((v528 + __PAIR64__((unsigned int)v514 ^ v544, HIDWORD(v514) ^ v567)) >> 32) ^ *(_DWORD *)v591) >> 24)
               | ((_DWORD)v465 << 8);
  LODWORD(v41) = BYTE3(v465)
               | ((((v528 + __PAIR64__((unsigned int)v514 ^ v544, HIDWORD(v514) ^ v567)) >> 32) ^ *(_DWORD *)v591) << 8);
  v515 = m[3] + v514 + __PAIR64__(v87, v41);
  v516 = v515 ^ HIDWORD(v514) ^ v567;
  HIDWORD(v499) = HIDWORD(v515) ^ v514 ^ v544;
  LODWORD(v[2]) = LODWORD(m[7]) + v509 + HIDWORD(v87);
  v[3] = v515;
  LODWORD(v[7]) = (2 * (HIDWORD(v87) ^ (v510 + LODWORD(v[13])))) | (v513 >> 31);
  v517 = p_buflen;
  HIDWORD(v[7]) = (2 * v513) | ((HIDWORD(v87) ^ (unsigned int)(v510 + LODWORD(v[13]))) >> 31);
  HIDWORD(v[14]) = HIWORD(HIDWORD(v499)) | (v516 << 16);
  LODWORD(v[14]) = HIWORD(v516) | (HIDWORD(v499) << 16);
  LODWORD(v41) = v41 ^ (v528 + (HIDWORD(v514) ^ v567) + LODWORD(v[14]));
  LODWORD(v87) = ((v528 + __PAIR64__((unsigned int)v514 ^ v544, HIDWORD(v514) ^ v567) + v[14]) >> 32) ^ v87;
  v[9] = v528 + __PAIR64__((unsigned int)v514 ^ v544, HIDWORD(v514) ^ v567) + v[14];
  v518 = &v[1];
  LODWORD(v[4]) = (2 * v41) | ((unsigned int)v87 >> 31);
  HIDWORD(v[4]) = (2 * v87) | ((unsigned int)v41 >> 31);
  v519 = v[0];
  while ( 1 )
  {
    v521 = v517[2];
    v517 += 2;
    v522 = v517[1];
    *v517 = v512 ^ v519 ^ v521;
    v517[1] = v522 ^ HIDWORD(v512) ^ HIDWORD(v519);
    if ( v588 == (blake2b_state *)v517 )
      break;
    v520 = *v518++;
    v519 = v520;
    v512 = v518[7];
  }
  return 0;
}
