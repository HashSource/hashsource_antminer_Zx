int __fastcall sub_12220(int *a1, int a2, int *a3)
{
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r10
  _DWORD *v7; // r3
  int *v8; // r2
  unsigned int v9; // lr
  unsigned int v10; // r12
  unsigned int v11; // r1
  unsigned int v12; // t1
  int v13; // r3
  int *v14; // r5
  int v15; // r7
  int i; // r3
  int v17; // r4
  int v18; // r3
  int v19; // r9
  int v20; // r7
  int v21; // r11
  int v22; // r0
  int v23; // r8
  int v24; // r2
  int v25; // r10
  int v26; // r1
  int v27; // r5
  bool v28; // zf
  int v29; // r11
  int v30; // r7
  int v31; // r9
  int v32; // r6
  int v33; // r3
  int v34; // r0
  int v35; // r1
  int v36; // r2
  int v37; // r5
  int v38; // r4
  int v39; // r12
  int v40; // lr
  int v41; // r7
  int v42; // lr
  int v43; // r6
  int v44; // r9
  int v45; // r11
  int v46; // r4
  int v47; // r12
  int v48; // r2
  int v49; // r1
  int v50; // r5
  int v51; // r8
  int v52; // r10
  int v53; // r2
  int v54; // r11
  int v55; // r9
  int v56; // lr
  int v57; // r5
  int v58; // r7
  int v59; // r6
  int v60; // r1
  int v61; // r3
  int v62; // r0
  int v63; // r3
  int v64; // r9
  int v65; // r7
  int v66; // r11
  int v67; // r0
  int v68; // r8
  int v69; // r2
  int v70; // r10
  int v71; // r1
  int v72; // r5
  int v73; // r4
  int v74; // r11
  int v75; // r7
  int v76; // r9
  int v77; // r6
  int v78; // r3
  int v79; // r0
  int v80; // r1
  int v81; // r2
  int v82; // r5
  int v83; // r4
  int v84; // r12
  int v85; // lr
  int v86; // lr
  int v87; // r9
  int v88; // r7
  int v89; // r11
  int v90; // r10
  int v91; // r4
  int v92; // r6
  int v93; // r1
  int v94; // r5
  int v95; // r8
  int v96; // r10
  int v97; // r11
  int v98; // r9
  int v99; // r7
  int v100; // lr
  int v101; // r6
  int v102; // r5
  int v103; // r12
  int v104; // r1
  int v105; // r0
  int v106; // r3
  int v107; // r2
  __int16 v108; // r2
  int *v109; // r1
  int v110; // r0
  __int64 v111; // t1
  int v112; // lr
  int v113; // r10
  int v114; // r2
  int v115; // r9
  int v116; // r11
  int v117; // r3
  int v118; // r6
  int v119; // r4
  int v120; // r5
  int v121; // r8
  int v122; // r10
  int v123; // r11
  int v124; // r9
  int v125; // r6
  int v126; // lr
  int v127; // r7
  int v128; // r5
  int v129; // r2
  int v130; // r3
  int v131; // r12
  int v132; // r1
  int v133; // r0
  int v134; // r7
  int v135; // r0
  int v136; // r2
  int v137; // r4
  int v138; // r9
  int v139; // r7
  int v140; // r11
  int v141; // r10
  int v142; // r6
  int v143; // r1
  int v144; // r5
  int v145; // lr
  int v146; // r8
  int v147; // r10
  int v148; // r1
  int v149; // r11
  int v150; // r7
  int v151; // r9
  int v152; // r5
  int v153; // r6
  int v154; // r12
  int v155; // lr
  int v156; // r0
  int v157; // r3
  int v158; // r2
  int *v159; // r12
  int v160; // lr
  __int64 v161; // t1
  int v162; // r10
  int v163; // r2
  int v164; // r9
  int v165; // r11
  int v166; // lr
  int v167; // r6
  int v168; // r3
  int v169; // r4
  int v170; // r5
  int v171; // r8
  int v172; // r10
  int v173; // r11
  int v174; // r9
  int v175; // r3
  int v176; // r6
  int v177; // r7
  int v178; // lr
  int v179; // r5
  int v180; // r2
  int v181; // r12
  int v182; // r1
  int v183; // r0
  int v184; // r7
  int v185; // r0
  int v186; // r12
  int v187; // r2
  int v188; // r5
  int v189; // r12
  int v190; // r9
  int v191; // r7
  int v192; // r11
  int v193; // r10
  int v194; // r4
  int v195; // r6
  int v196; // r1
  int v197; // r8
  int v198; // lr
  int v199; // r10
  int v200; // r9
  int v201; // r11
  int v202; // r7
  int v203; // r1
  int v204; // r5
  int v205; // r6
  int v206; // lr
  int v207; // r12
  int v208; // r0
  int v209; // r3
  int v210; // r2
  int v211; // r6
  int v212; // r1
  int v213; // r2
  int v214; // r3
  int v215; // r0
  int v216; // r1
  int v217; // r2
  int v218; // r3
  int v219; // r0
  int v220; // r1
  int v221; // r2
  int v222; // r3
  int v223; // r12
  int v224; // r3
  int v226; // [sp+4h] [bp-2C8h]
  int v227; // [sp+4h] [bp-2C8h]
  int v228; // [sp+4h] [bp-2C8h]
  int v229; // [sp+4h] [bp-2C8h]
  int v230; // [sp+4h] [bp-2C8h]
  int v231; // [sp+4h] [bp-2C8h]
  int v232; // [sp+4h] [bp-2C8h]
  int v233; // [sp+4h] [bp-2C8h]
  int v234; // [sp+4h] [bp-2C8h]
  int v235; // [sp+4h] [bp-2C8h]
  int v236; // [sp+4h] [bp-2C8h]
  int v237; // [sp+8h] [bp-2C4h]
  int v238; // [sp+8h] [bp-2C4h]
  int v239; // [sp+8h] [bp-2C4h]
  int v240; // [sp+8h] [bp-2C4h]
  int v241; // [sp+8h] [bp-2C4h]
  int v242; // [sp+8h] [bp-2C4h]
  int v243; // [sp+8h] [bp-2C4h]
  int v244; // [sp+8h] [bp-2C4h]
  int v245; // [sp+8h] [bp-2C4h]
  int v246; // [sp+8h] [bp-2C4h]
  int v247; // [sp+Ch] [bp-2C0h]
  int v248; // [sp+Ch] [bp-2C0h]
  int v249; // [sp+Ch] [bp-2C0h]
  int v250; // [sp+Ch] [bp-2C0h]
  int v251; // [sp+Ch] [bp-2C0h]
  int v252; // [sp+Ch] [bp-2C0h]
  int v253; // [sp+Ch] [bp-2C0h]
  int v254; // [sp+Ch] [bp-2C0h]
  int v255; // [sp+10h] [bp-2BCh]
  int v256; // [sp+10h] [bp-2BCh]
  int v257; // [sp+10h] [bp-2BCh]
  int v258; // [sp+10h] [bp-2BCh]
  int v259; // [sp+10h] [bp-2BCh]
  int v260; // [sp+10h] [bp-2BCh]
  int v261; // [sp+10h] [bp-2BCh]
  int v262; // [sp+10h] [bp-2BCh]
  int v263; // [sp+14h] [bp-2B8h]
  int v264; // [sp+14h] [bp-2B8h]
  int v265; // [sp+14h] [bp-2B8h]
  int v266; // [sp+14h] [bp-2B8h]
  int v267; // [sp+14h] [bp-2B8h]
  int v268; // [sp+14h] [bp-2B8h]
  int v269; // [sp+14h] [bp-2B8h]
  int v270; // [sp+14h] [bp-2B8h]
  int v271; // [sp+18h] [bp-2B4h]
  int v272; // [sp+18h] [bp-2B4h]
  int v273; // [sp+18h] [bp-2B4h]
  int v274; // [sp+18h] [bp-2B4h]
  int v275; // [sp+18h] [bp-2B4h]
  int v276; // [sp+18h] [bp-2B4h]
  int v277; // [sp+18h] [bp-2B4h]
  int v278; // [sp+18h] [bp-2B4h]
  int v279; // [sp+1Ch] [bp-2B0h]
  int v280; // [sp+1Ch] [bp-2B0h]
  int v281; // [sp+1Ch] [bp-2B0h]
  int v282; // [sp+1Ch] [bp-2B0h]
  int v283; // [sp+1Ch] [bp-2B0h]
  int v284; // [sp+1Ch] [bp-2B0h]
  int v285; // [sp+1Ch] [bp-2B0h]
  int v286; // [sp+1Ch] [bp-2B0h]
  int v287; // [sp+20h] [bp-2ACh]
  int v288; // [sp+20h] [bp-2ACh]
  int v289; // [sp+20h] [bp-2ACh]
  int v290; // [sp+20h] [bp-2ACh]
  int v291; // [sp+20h] [bp-2ACh]
  int v292; // [sp+20h] [bp-2ACh]
  int v293; // [sp+20h] [bp-2ACh]
  int v294; // [sp+20h] [bp-2ACh]
  int v295; // [sp+24h] [bp-2A8h]
  int v296; // [sp+24h] [bp-2A8h]
  int v297; // [sp+24h] [bp-2A8h]
  int v298; // [sp+24h] [bp-2A8h]
  int v299; // [sp+24h] [bp-2A8h]
  int v300; // [sp+24h] [bp-2A8h]
  int v301; // [sp+24h] [bp-2A8h]
  int v302; // [sp+24h] [bp-2A8h]
  int v303; // [sp+28h] [bp-2A4h]
  int v304; // [sp+28h] [bp-2A4h]
  int v305; // [sp+28h] [bp-2A4h]
  int v306; // [sp+28h] [bp-2A4h]
  int v307; // [sp+28h] [bp-2A4h]
  int v308; // [sp+28h] [bp-2A4h]
  int v309; // [sp+28h] [bp-2A4h]
  int v310; // [sp+28h] [bp-2A4h]
  int v311; // [sp+2Ch] [bp-2A0h]
  int v312; // [sp+2Ch] [bp-2A0h]
  int v313; // [sp+2Ch] [bp-2A0h]
  int v314; // [sp+2Ch] [bp-2A0h]
  int v315; // [sp+2Ch] [bp-2A0h]
  int v316; // [sp+2Ch] [bp-2A0h]
  int v317; // [sp+30h] [bp-29Ch]
  int v318; // [sp+30h] [bp-29Ch]
  int v319; // [sp+30h] [bp-29Ch]
  int v320; // [sp+30h] [bp-29Ch]
  int v321; // [sp+30h] [bp-29Ch]
  int v322; // [sp+30h] [bp-29Ch]
  int v323; // [sp+34h] [bp-298h]
  int v324; // [sp+34h] [bp-298h]
  int v325; // [sp+34h] [bp-298h]
  int v326; // [sp+34h] [bp-298h]
  int v327; // [sp+34h] [bp-298h]
  int v328; // [sp+34h] [bp-298h]
  int v329; // [sp+38h] [bp-294h]
  int v330; // [sp+38h] [bp-294h]
  int v331; // [sp+38h] [bp-294h]
  int v332; // [sp+38h] [bp-294h]
  int v333; // [sp+38h] [bp-294h]
  int v334; // [sp+38h] [bp-294h]
  int v335; // [sp+3Ch] [bp-290h]
  int v336; // [sp+3Ch] [bp-290h]
  int v337; // [sp+3Ch] [bp-290h]
  int v338; // [sp+3Ch] [bp-290h]
  int v339; // [sp+3Ch] [bp-290h]
  int v340; // [sp+3Ch] [bp-290h]
  int v341; // [sp+40h] [bp-28Ch]
  int v342; // [sp+40h] [bp-28Ch]
  int v343; // [sp+40h] [bp-28Ch]
  int v344; // [sp+40h] [bp-28Ch]
  int v345; // [sp+40h] [bp-28Ch]
  int v346; // [sp+40h] [bp-28Ch]
  int v347; // [sp+44h] [bp-288h]
  int v348; // [sp+44h] [bp-288h]
  int v349; // [sp+44h] [bp-288h]
  int v350; // [sp+44h] [bp-288h]
  int v351; // [sp+44h] [bp-288h]
  int v352; // [sp+44h] [bp-288h]
  int v353; // [sp+48h] [bp-284h]
  int v354; // [sp+48h] [bp-284h]
  int v355; // [sp+48h] [bp-284h]
  int v356; // [sp+48h] [bp-284h]
  int v357; // [sp+48h] [bp-284h]
  int v358; // [sp+48h] [bp-284h]
  int v359; // [sp+4Ch] [bp-280h]
  int v360; // [sp+4Ch] [bp-280h]
  int v361; // [sp+4Ch] [bp-280h]
  int v362; // [sp+4Ch] [bp-280h]
  int v363; // [sp+4Ch] [bp-280h]
  int v364; // [sp+4Ch] [bp-280h]
  int v365; // [sp+50h] [bp-27Ch]
  int v366; // [sp+50h] [bp-27Ch]
  int v367; // [sp+50h] [bp-27Ch]
  int v368; // [sp+50h] [bp-27Ch]
  int v369; // [sp+50h] [bp-27Ch]
  int v370; // [sp+50h] [bp-27Ch]
  int v371; // [sp+54h] [bp-278h]
  int v372; // [sp+54h] [bp-278h]
  int v373; // [sp+54h] [bp-278h]
  int v374; // [sp+54h] [bp-278h]
  int v375; // [sp+54h] [bp-278h]
  int v376; // [sp+54h] [bp-278h]
  int v377; // [sp+58h] [bp-274h]
  int v378; // [sp+58h] [bp-274h]
  int v379; // [sp+58h] [bp-274h]
  int v380; // [sp+58h] [bp-274h]
  int v381; // [sp+58h] [bp-274h]
  int v382; // [sp+58h] [bp-274h]
  int v383; // [sp+5Ch] [bp-270h]
  int v384; // [sp+5Ch] [bp-270h]
  int v385; // [sp+5Ch] [bp-270h]
  int v386; // [sp+5Ch] [bp-270h]
  int v387; // [sp+5Ch] [bp-270h]
  int v388; // [sp+5Ch] [bp-270h]
  int v389; // [sp+60h] [bp-26Ch]
  int v390; // [sp+60h] [bp-26Ch]
  int v391; // [sp+60h] [bp-26Ch]
  int v392; // [sp+60h] [bp-26Ch]
  int v393; // [sp+60h] [bp-26Ch]
  int v394; // [sp+60h] [bp-26Ch]
  int v395; // [sp+64h] [bp-268h]
  int v396; // [sp+64h] [bp-268h]
  int v397; // [sp+64h] [bp-268h]
  int v398; // [sp+64h] [bp-268h]
  int v399; // [sp+64h] [bp-268h]
  int v400; // [sp+64h] [bp-268h]
  int v401; // [sp+68h] [bp-264h]
  int v402; // [sp+68h] [bp-264h]
  int v403; // [sp+68h] [bp-264h]
  int v404; // [sp+68h] [bp-264h]
  int v405; // [sp+68h] [bp-264h]
  int v406; // [sp+68h] [bp-264h]
  int v407; // [sp+6Ch] [bp-260h]
  int v408; // [sp+6Ch] [bp-260h]
  int v409; // [sp+6Ch] [bp-260h]
  int v410; // [sp+6Ch] [bp-260h]
  int v411; // [sp+6Ch] [bp-260h]
  int v412; // [sp+6Ch] [bp-260h]
  int v413; // [sp+70h] [bp-25Ch]
  int v414; // [sp+70h] [bp-25Ch]
  int v415; // [sp+70h] [bp-25Ch]
  int v416; // [sp+70h] [bp-25Ch]
  int v417; // [sp+70h] [bp-25Ch]
  int v418; // [sp+70h] [bp-25Ch]
  int v419; // [sp+74h] [bp-258h]
  int v420; // [sp+74h] [bp-258h]
  int v421; // [sp+74h] [bp-258h]
  int v422; // [sp+74h] [bp-258h]
  int v423; // [sp+74h] [bp-258h]
  int v424; // [sp+74h] [bp-258h]
  int v425; // [sp+78h] [bp-254h]
  int v426; // [sp+78h] [bp-254h]
  int v427; // [sp+78h] [bp-254h]
  int v428; // [sp+78h] [bp-254h]
  int v429; // [sp+78h] [bp-254h]
  int v430; // [sp+78h] [bp-254h]
  int v431; // [sp+7Ch] [bp-250h]
  int v432; // [sp+7Ch] [bp-250h]
  int v433; // [sp+7Ch] [bp-250h]
  int v434; // [sp+7Ch] [bp-250h]
  int v435; // [sp+7Ch] [bp-250h]
  int v436; // [sp+7Ch] [bp-250h]
  int v437; // [sp+80h] [bp-24Ch]
  int v438; // [sp+80h] [bp-24Ch]
  int v439; // [sp+80h] [bp-24Ch]
  int v440; // [sp+80h] [bp-24Ch]
  int v441; // [sp+80h] [bp-24Ch]
  int v442; // [sp+80h] [bp-24Ch]
  int v443; // [sp+80h] [bp-24Ch]
  int v444; // [sp+80h] [bp-24Ch]
  int v445; // [sp+84h] [bp-248h]
  int v446; // [sp+84h] [bp-248h]
  int v447; // [sp+84h] [bp-248h]
  int v448; // [sp+84h] [bp-248h]
  int v449; // [sp+84h] [bp-248h]
  int v450; // [sp+84h] [bp-248h]
  int v451; // [sp+88h] [bp-244h]
  int v452; // [sp+88h] [bp-244h]
  int v453; // [sp+88h] [bp-244h]
  int v454; // [sp+88h] [bp-244h]
  int v455; // [sp+88h] [bp-244h]
  int v456; // [sp+88h] [bp-244h]
  int v457; // [sp+88h] [bp-244h]
  int v458; // [sp+88h] [bp-244h]
  int v459; // [sp+8Ch] [bp-240h]
  int v460; // [sp+8Ch] [bp-240h]
  int v461; // [sp+8Ch] [bp-240h]
  int v462; // [sp+8Ch] [bp-240h]
  int v463; // [sp+8Ch] [bp-240h]
  int v464; // [sp+8Ch] [bp-240h]
  int v465; // [sp+90h] [bp-23Ch]
  int v466; // [sp+90h] [bp-23Ch]
  int v467; // [sp+90h] [bp-23Ch]
  int v468; // [sp+90h] [bp-23Ch]
  int v469; // [sp+90h] [bp-23Ch]
  int v470; // [sp+90h] [bp-23Ch]
  int v471; // [sp+94h] [bp-238h]
  int v472; // [sp+94h] [bp-238h]
  int v473; // [sp+94h] [bp-238h]
  int v474; // [sp+94h] [bp-238h]
  int v475; // [sp+98h] [bp-234h]
  int v476; // [sp+98h] [bp-234h]
  int v477; // [sp+98h] [bp-234h]
  int v478; // [sp+98h] [bp-234h]
  int v479; // [sp+98h] [bp-234h]
  int v480; // [sp+98h] [bp-234h]
  int v481; // [sp+9Ch] [bp-230h]
  int v482; // [sp+9Ch] [bp-230h]
  int v483; // [sp+9Ch] [bp-230h]
  int v484; // [sp+9Ch] [bp-230h]
  int v485; // [sp+A0h] [bp-22Ch]
  int v486; // [sp+A0h] [bp-22Ch]
  int v487; // [sp+A0h] [bp-22Ch]
  int v488; // [sp+A0h] [bp-22Ch]
  int v489; // [sp+A0h] [bp-22Ch]
  int v490; // [sp+A0h] [bp-22Ch]
  int v491; // [sp+A4h] [bp-228h]
  int v492; // [sp+A4h] [bp-228h]
  int v493; // [sp+A4h] [bp-228h]
  int v494; // [sp+A4h] [bp-228h]
  int v495; // [sp+A8h] [bp-224h]
  int v496; // [sp+A8h] [bp-224h]
  int v497; // [sp+A8h] [bp-224h]
  int v498; // [sp+A8h] [bp-224h]
  int v499; // [sp+A8h] [bp-224h]
  int v500; // [sp+A8h] [bp-224h]
  char *dest; // [sp+ACh] [bp-220h]
  int desta; // [sp+ACh] [bp-220h]
  int v503; // [sp+B0h] [bp-21Ch]
  char *v504; // [sp+B4h] [bp-218h]
  char *v505; // [sp+B8h] [bp-214h]
  int v508; // [sp+C8h] [bp-204h] BYREF
  int v509; // [sp+CCh] [bp-200h]
  int v510; // [sp+D0h] [bp-1FCh]
  int v511; // [sp+D4h] [bp-1F8h]
  int v512; // [sp+D8h] [bp-1F4h]
  int v513; // [sp+DCh] [bp-1F0h]
  int v514; // [sp+E0h] [bp-1ECh]
  int v515; // [sp+E4h] [bp-1E8h]
  _DWORD v516[8]; // [sp+E8h] [bp-1E4h]
  int v517; // [sp+108h] [bp-1C4h] BYREF
  int v518; // [sp+10Ch] [bp-1C0h]
  int v519; // [sp+110h] [bp-1BCh]
  int v520; // [sp+114h] [bp-1B8h]
  int v521; // [sp+118h] [bp-1B4h]
  int v522; // [sp+11Ch] [bp-1B0h]
  int v523; // [sp+120h] [bp-1ACh]
  int v524; // [sp+124h] [bp-1A8h]
  int v525[8]; // [sp+128h] [bp-1A4h] BYREF
  int v526; // [sp+148h] [bp-184h] BYREF
  int v527; // [sp+14Ch] [bp-180h]
  int v528; // [sp+150h] [bp-17Ch]
  int v529; // [sp+154h] [bp-178h]
  int v530; // [sp+158h] [bp-174h]
  int v531; // [sp+15Ch] [bp-170h]
  int v532; // [sp+160h] [bp-16Ch]
  int v533; // [sp+164h] [bp-168h]
  _DWORD v534[8]; // [sp+168h] [bp-164h] BYREF
  int v535; // [sp+188h] [bp-144h] BYREF
  int v536; // [sp+18Ch] [bp-140h]
  int v537; // [sp+190h] [bp-13Ch]
  int v538; // [sp+194h] [bp-138h]
  int v539; // [sp+198h] [bp-134h]
  int v540; // [sp+19Ch] [bp-130h]
  int v541; // [sp+1A0h] [bp-12Ch]
  int v542; // [sp+1A4h] [bp-128h]
  int v543[4]; // [sp+1A8h] [bp-124h] BYREF
  int v544; // [sp+1B8h] [bp-114h] BYREF
  int v545; // [sp+1E8h] [bp-E4h] BYREF
  int v546; // [sp+1ECh] [bp-E0h]
  int v547; // [sp+1F0h] [bp-DCh]
  int v548; // [sp+1F4h] [bp-D8h]
  int v549; // [sp+1F8h] [bp-D4h]
  int v550; // [sp+1FCh] [bp-D0h]
  int v551; // [sp+200h] [bp-CCh]
  int v552; // [sp+204h] [bp-C8h]
  int v553[16]; // [sp+208h] [bp-C4h] BYREF
  int src[32]; // [sp+248h] [bp-84h] BYREF
  char v555; // [sp+2C8h] [bp-4h] BYREF

  dest = (char *)((a2 + 63) & 0xFFFFFFC0);
  v508 = 1779033703;
  v509 = -1150833019;
  v510 = 1013904242;
  v511 = -1521486534;
  v512 = 1359893119;
  v513 = -1694144372;
  v514 = 528734635;
  v515 = 1541459225;
  sub_FBC8(&v508, a1, 1);
  v3 = a1[17];
  v4 = a1[18];
  v5 = a1[19];
  v526 = a1[16];
  v527 = v3;
  v528 = v4;
  v529 = v5;
  v530 = 128;
  v531 = 0;
  v532 = 0;
  v533 = 0;
  v504 = dest;
  memset(v534, 0, 28);
  v534[7] = -2147352576;
  sub_FBC8(&v508, &v526, 1);
  v538 = -1521486534;
  v539 = 1359893119;
  v516[0] = v508;
  v516[1] = v509;
  v516[2] = v510;
  v516[3] = v511;
  v535 = 1779033703;
  v6 = 0;
  v536 = -1150833019;
  v537 = 1013904242;
  v540 = -1694144372;
  v541 = 528734635;
  v542 = 1541459225;
  v516[4] = v512;
  v516[5] = v513;
  v516[6] = v514;
  v516[7] = v515;
  do
  {
    *(int *)((char *)&v526 + v6 * 4) = v516[v6] ^ 0x36363636;
    ++v6;
  }
  while ( v6 != 8 );
  memset(v534, 54, sizeof(v534));
  sub_FBC8(&v535, &v526, 0);
  sub_FBC8(&v535, a1, 1);
  v7 = &unk_5A9B4;
  v8 = &v544;
  v9 = a1[17];
  v10 = a1[18];
  v543[0] = bswap32(a1[16]);
  v11 = a1[19];
  v543[1] = bswap32(v9);
  v543[2] = bswap32(v10);
  v543[3] = bswap32(v11);
  do
  {
    v12 = v7[1];
    ++v7;
    v8[1] = bswap32(v12);
    ++v8;
  }
  while ( v7 != (_DWORD *)&unk_5A9E0 );
  v13 = 0;
  v545 = 1779033703;
  v546 = -1150833019;
  v547 = 1013904242;
  v548 = -1521486534;
  v549 = 1359893119;
  v550 = -1694144372;
  v551 = 528734635;
  v552 = 1541459225;
  do
  {
    *(int *)((char *)&v526 + v13 * 4) = v516[v13] ^ 0x5C5C5C5C;
    ++v13;
  }
  while ( v13 != 8 );
  memset(v534, 92, sizeof(v534));
  sub_FBC8(&v545, &v526, 0);
  v14 = src;
  v15 = 0;
  v553[8] = 0x80000000;
  memset(&v553[9], 0, 24);
  v553[15] = 768;
  do
  {
    ++v15;
    v517 = v535;
    v518 = v536;
    v519 = v537;
    v520 = v538;
    v544 = v15;
    v521 = v539;
    v522 = v540;
    v523 = v541;
    v524 = v542;
    sub_FBC8(&v517, v543, 0);
    v553[0] = v517;
    v553[1] = v518;
    v553[2] = v519;
    v553[3] = v520;
    v553[4] = v521;
    v553[5] = v522;
    v553[6] = v523;
    v553[7] = v524;
    v525[0] = v545;
    v525[1] = v546;
    v525[2] = v547;
    v525[3] = v548;
    v525[4] = v549;
    v525[5] = v550;
    v525[6] = v551;
    v525[7] = v552;
    sub_FBC8(v525, v553, 0);
    for ( i = 0; i != 8; ++i )
      v14[i] = bswap32(v525[i]);
    v14 += 8;
  }
  while ( v15 != 4 );
  v317 = src[0];
  v505 = dest + 0x20000;
  v311 = src[16];
  v323 = src[1];
  v413 = src[17];
  v329 = src[2];
  v419 = src[18];
  v335 = src[3];
  v425 = src[19];
  v341 = src[4];
  v431 = src[20];
  v347 = src[5];
  v437 = src[21];
  v353 = src[6];
  v445 = src[22];
  v359 = src[7];
  v451 = src[23];
  v365 = src[8];
  v459 = src[24];
  v371 = src[9];
  v465 = src[25];
  v377 = src[10];
  v471 = src[26];
  v383 = src[11];
  v475 = src[27];
  v389 = src[12];
  v481 = src[28];
  v395 = src[13];
  v485 = src[29];
  v401 = src[14];
  v491 = src[30];
  v407 = src[15];
  v495 = src[31];
  do
  {
    memcpy(dest, src, 0x80u);
    v318 = v311 ^ v317;
    v324 = v413 ^ v323;
    v330 = v419 ^ v329;
    v336 = v425 ^ v335;
    v342 = v431 ^ v341;
    v348 = v437 ^ v347;
    v354 = v445 ^ v353;
    v360 = v451 ^ v359;
    v366 = v459 ^ v365;
    v372 = v465 ^ v371;
    v378 = v471 ^ v377;
    v384 = v475 ^ v383;
    v263 = v384;
    v396 = v485 ^ v395;
    v408 = v495 ^ v407;
    v287 = v396;
    v17 = v408;
    v255 = v354;
    v18 = v491 ^ v401;
    v19 = v360;
    v20 = v330;
    v21 = v366;
    v22 = v336;
    v23 = v378;
    v24 = v372;
    v25 = v324;
    v26 = v342;
    v27 = v318;
    v390 = v481 ^ v389;
    v247 = v390;
    v402 = v491 ^ v401;
    v295 = v348;
    v303 = 4;
    do
    {
      v226 = v26 ^ __ROR4__(v247 + v27, 25);
      v271 = v18 ^ __ROR4__(v255 + v23, 25);
      v28 = v303-- == 1;
      v237 = v24 ^ __ROR4__(v25 + v295, 25);
      v279 = v22 ^ __ROR4__(v263 + v17, 25);
      v29 = v21 ^ __ROR4__(v226 + v27, 23);
      v30 = v20 ^ __ROR4__(v271 + v23, 23);
      v31 = v19 ^ __ROR4__(v279 + v17, 23);
      v32 = v247 ^ __ROR4__(v29 + v226, 19);
      v33 = v287 ^ __ROR4__(v237 + v295, 23);
      v34 = v263 ^ __ROR4__(v31 + v279, 19);
      v35 = v255 ^ __ROR4__(v30 + v271, 19);
      v36 = v25 ^ __ROR4__(v33 + v237, 19);
      v37 = v27 ^ __ROR4__(v32 + v29, 14);
      v38 = v17 ^ __ROR4__(v34 + v31, 14);
      v39 = v23 ^ __ROR4__(v35 + v30, 14);
      v40 = v295 ^ __ROR4__(v36 + v33, 14);
      v247 = v32 ^ __ROR4__(v38 + v271, 25);
      v263 = v34 ^ __ROR4__(v39 + v237, 25);
      v255 = v35 ^ __ROR4__(v40 + v226, 25);
      v25 = v36 ^ __ROR4__(v37 + v279, 25);
      v21 = v29 ^ __ROR4__(v263 + v39, 23);
      v19 = v31 ^ __ROR4__(v255 + v40, 23);
      v20 = v30 ^ __ROR4__(v25 + v37, 23);
      v287 = v33 ^ __ROR4__(v247 + v38, 23);
      v22 = v279 ^ __ROR4__(v20 + v25, 19);
      v26 = v226 ^ __ROR4__(v19 + v255, 19);
      v24 = v237 ^ __ROR4__(v21 + v263, 19);
      v18 = v271 ^ __ROR4__(v287 + v247, 19);
      v27 = v37 ^ __ROR4__(v22 + v20, 14);
      v295 = v40 ^ __ROR4__(v26 + v19, 14);
      v23 = v39 ^ __ROR4__(v24 + v21, 14);
      v17 = v38 ^ __ROR4__(v18 + v287, 14);
    }
    while ( !v28 );
    v319 = v27 + v318;
    v325 = v25 + v324;
    v331 = v20 + v330;
    v337 = v22 + v336;
    v343 = v26 + v342;
    v349 = v295 + v348;
    v355 = v255 + v354;
    v361 = v19 + v360;
    v379 = v23 + v378;
    v367 = v21 + v366;
    v373 = v24 + v372;
    v385 = v263 + v384;
    v391 = v247 + v390;
    v397 = v287 + v396;
    v403 = v18 + v402;
    v409 = v17 + v408;
    v414 = v325 ^ v413;
    v420 = v331 ^ v419;
    v426 = v337 ^ v425;
    v432 = v343 ^ v431;
    v503 = v319 ^ v311;
    v438 = v349 ^ v437;
    v446 = v355 ^ v445;
    v452 = v361 ^ v451;
    v460 = v367 ^ v459;
    v466 = v373 ^ v465;
    v472 = v379 ^ v471;
    v492 = v403 ^ v491;
    v41 = v492;
    v256 = v414;
    v312 = 4;
    v482 = v391 ^ v481;
    v496 = v409 ^ v495;
    v42 = v397 ^ v485;
    v476 = v385 ^ v475;
    v486 = v397 ^ v485;
    v264 = v476;
    v280 = v472;
    v43 = v452;
    v44 = v420;
    v45 = v460;
    v46 = v496;
    v47 = v446;
    v48 = v466;
    v272 = v438;
    v49 = v432;
    v50 = v482;
    src[0] = v319;
    v304 = v426;
    v51 = v503;
    src[1] = v325;
    src[2] = v331;
    src[3] = v337;
    src[4] = v343;
    src[5] = v349;
    src[6] = v355;
    src[7] = v361;
    src[8] = v367;
    src[9] = v373;
    src[10] = v379;
    src[11] = v385;
    src[12] = v391;
    src[13] = v397;
    src[14] = v403;
    src[15] = v409;
    do
    {
      v248 = v49 ^ __ROR4__(v50 + v51, 25);
      v238 = v41 ^ __ROR4__(v47 + v280, 25);
      v28 = v312-- == 1;
      v52 = v304 ^ __ROR4__(v264 + v46, 25);
      v227 = v48 ^ __ROR4__(v256 + v272, 25);
      v53 = v43 ^ __ROR4__(v52 + v46, 23);
      v54 = v45 ^ __ROR4__(v248 + v51, 23);
      v55 = v44 ^ __ROR4__(v238 + v280, 23);
      v56 = v42 ^ __ROR4__(v227 + v272, 23);
      v57 = v50 ^ __ROR4__(v54 + v248, 19);
      v58 = v264 ^ __ROR4__(v53 + v52, 19);
      v59 = v47 ^ __ROR4__(v55 + v238, 19);
      v60 = v256 ^ __ROR4__(v56 + v227, 19);
      v296 = v46 ^ __ROR4__(v58 + v53, 14);
      v61 = v280 ^ __ROR4__(v59 + v55, 14);
      v288 = v51 ^ __ROR4__(v57 + v54, 14);
      v62 = v272 ^ __ROR4__(v60 + v56, 14);
      v50 = v57 ^ __ROR4__(v296 + v238, 25);
      v264 = v58 ^ __ROR4__(v61 + v227, 25);
      v47 = v59 ^ __ROR4__(v62 + v248, 25);
      v256 = v60 ^ __ROR4__(v288 + v52, 25);
      v45 = v54 ^ __ROR4__(v264 + v61, 23);
      v43 = v53 ^ __ROR4__(v47 + v62, 23);
      v44 = v55 ^ __ROR4__(v256 + v288, 23);
      v42 = v56 ^ __ROR4__(v50 + v296, 23);
      v304 = v52 ^ __ROR4__(v44 + v256, 19);
      v41 = v238 ^ __ROR4__(v42 + v50, 19);
      v49 = v248 ^ __ROR4__(v43 + v47, 19);
      v48 = v227 ^ __ROR4__(v45 + v264, 19);
      v51 = v288 ^ __ROR4__(v304 + v44, 14);
      v272 = v62 ^ __ROR4__(v49 + v43, 14);
      v280 = v61 ^ __ROR4__(v48 + v45, 14);
      v46 = v296 ^ __ROR4__(v41 + v42, 14);
    }
    while ( !v28 );
    v313 = v51 + v503;
    v415 = v256 + v414;
    v427 = v304 + v426;
    v433 = v49 + v432;
    v421 = v44 + v420;
    v453 = v43 + v452;
    v439 = v272 + v438;
    v447 = v47 + v446;
    v467 = v48 + v466;
    v487 = v42 + v486;
    v461 = v45 + v460;
    v473 = v280 + v472;
    v477 = v264 + v476;
    v483 = v50 + v482;
    v493 = v41 + v492;
    v497 = v46 + v496;
    src[16] = v51 + v503;
    src[17] = v415;
    src[18] = v421;
    src[19] = v427;
    src[20] = v433;
    src[21] = v439;
    src[22] = v447;
    src[23] = v453;
    src[24] = v461;
    src[25] = v467;
    src[26] = v473;
    src[27] = v477;
    src[28] = v483;
    src[29] = v487;
    src[30] = v493;
    src[31] = v497;
    memcpy(dest + 128, src, 0x80u);
    v320 = (v51 + v503) ^ v319;
    v326 = v415 ^ v325;
    v332 = v421 ^ v331;
    v338 = v427 ^ v337;
    v344 = v433 ^ v343;
    v350 = v439 ^ v349;
    v356 = v447 ^ v355;
    v362 = v453 ^ v361;
    v368 = v461 ^ v367;
    v374 = v467 ^ v373;
    v380 = v473 ^ v379;
    v386 = v477 ^ v385;
    v392 = v483 ^ v391;
    v398 = v487 ^ v397;
    v404 = v493 ^ v403;
    v63 = v404;
    v289 = v398;
    v257 = v356;
    v64 = v362;
    v65 = v332;
    v66 = v368;
    v67 = v338;
    v68 = v380;
    v69 = v374;
    v70 = v326;
    v71 = v344;
    v72 = v320;
    v410 = v497 ^ v409;
    v265 = v386;
    v73 = v410;
    v297 = v350;
    v249 = v392;
    v305 = 4;
    do
    {
      v228 = v71 ^ __ROR4__(v249 + v72, 25);
      v273 = v63 ^ __ROR4__(v257 + v68, 25);
      v28 = v305-- == 1;
      v239 = v69 ^ __ROR4__(v70 + v297, 25);
      v281 = v67 ^ __ROR4__(v265 + v73, 25);
      v74 = v66 ^ __ROR4__(v228 + v72, 23);
      v75 = v65 ^ __ROR4__(v273 + v68, 23);
      v76 = v64 ^ __ROR4__(v281 + v73, 23);
      v77 = v249 ^ __ROR4__(v74 + v228, 19);
      v78 = v289 ^ __ROR4__(v239 + v297, 23);
      v79 = v265 ^ __ROR4__(v76 + v281, 19);
      v80 = v257 ^ __ROR4__(v75 + v273, 19);
      v81 = v70 ^ __ROR4__(v78 + v239, 19);
      v82 = v72 ^ __ROR4__(v77 + v74, 14);
      v83 = v73 ^ __ROR4__(v79 + v76, 14);
      v84 = v68 ^ __ROR4__(v80 + v75, 14);
      v85 = v297 ^ __ROR4__(v81 + v78, 14);
      v249 = v77 ^ __ROR4__(v83 + v273, 25);
      v265 = v79 ^ __ROR4__(v84 + v239, 25);
      v257 = v80 ^ __ROR4__(v85 + v228, 25);
      v70 = v81 ^ __ROR4__(v82 + v281, 25);
      v66 = v74 ^ __ROR4__(v265 + v84, 23);
      v64 = v76 ^ __ROR4__(v257 + v85, 23);
      v65 = v75 ^ __ROR4__(v70 + v82, 23);
      v289 = v78 ^ __ROR4__(v249 + v83, 23);
      v67 = v281 ^ __ROR4__(v65 + v70, 19);
      v71 = v228 ^ __ROR4__(v64 + v257, 19);
      v69 = v239 ^ __ROR4__(v66 + v265, 19);
      v63 = v273 ^ __ROR4__(v289 + v249, 19);
      v72 = v82 ^ __ROR4__(v67 + v65, 14);
      v297 = v85 ^ __ROR4__(v71 + v64, 14);
      v68 = v84 ^ __ROR4__(v69 + v66, 14);
      v73 = v83 ^ __ROR4__(v63 + v289, 14);
    }
    while ( !v28 );
    v317 = v72 + v320;
    v323 = v70 + v326;
    v329 = v65 + v332;
    v335 = v67 + v338;
    v341 = v71 + v344;
    v347 = v297 + v350;
    v353 = v257 + v356;
    v359 = v64 + v362;
    v377 = v68 + v380;
    v365 = v66 + v368;
    v371 = v69 + v374;
    v383 = v265 + v386;
    v389 = v249 + v392;
    v395 = v289 + v398;
    v401 = v63 + v404;
    v407 = v73 + v410;
    v416 = v323 ^ v415;
    v422 = v329 ^ v421;
    v428 = v335 ^ v427;
    v434 = v341 ^ v433;
    v314 = v317 ^ v313;
    v440 = v347 ^ v439;
    v448 = v353 ^ v447;
    v454 = v359 ^ v453;
    v462 = v365 ^ v461;
    v468 = v371 ^ v467;
    v474 = v377 ^ v473;
    v484 = v389 ^ v483;
    v494 = v401 ^ v493;
    v498 = v407 ^ v497;
    v86 = v395 ^ v487;
    v478 = v383 ^ v477;
    v488 = v395 ^ v487;
    v266 = v448;
    v290 = v474;
    v258 = v416;
    v87 = v454;
    v88 = v422;
    v89 = v462;
    v90 = v428;
    v91 = v498;
    v92 = v468;
    v282 = v440;
    v93 = v434;
    v306 = 4;
    v250 = v484;
    v94 = v478;
    src[0] = v317;
    src[1] = v323;
    src[2] = v329;
    src[3] = v335;
    src[4] = v341;
    src[5] = v347;
    src[6] = v353;
    src[7] = v359;
    src[8] = v365;
    src[9] = v371;
    src[10] = v377;
    src[11] = v383;
    src[12] = v389;
    src[13] = v395;
    src[14] = v401;
    src[15] = v407;
    v240 = v494;
    v95 = v314;
    do
    {
      v229 = v93 ^ __ROR4__(v250 + v95, 25);
      v28 = v306-- == 1;
      v96 = v90 ^ __ROR4__(v94 + v91, 25);
      v274 = v240 ^ __ROR4__(v266 + v290, 25);
      v241 = v92 ^ __ROR4__(v258 + v282, 25);
      v97 = v89 ^ __ROR4__(v229 + v95, 23);
      v98 = v87 ^ __ROR4__(v96 + v91, 23);
      v99 = v88 ^ __ROR4__(v274 + v290, 23);
      v100 = v86 ^ __ROR4__(v241 + v282, 23);
      v101 = v250 ^ __ROR4__(v97 + v229, 19);
      v102 = v94 ^ __ROR4__(v98 + v96, 19);
      v103 = v266 ^ __ROR4__(v99 + v274, 19);
      v104 = v258 ^ __ROR4__(v100 + v241, 19);
      v105 = v95 ^ __ROR4__(v101 + v97, 14);
      v298 = v91 ^ __ROR4__(v102 + v98, 14);
      v106 = v290 ^ __ROR4__(v103 + v99, 14);
      v107 = v282 ^ __ROR4__(v104 + v100, 14);
      v94 = v102 ^ __ROR4__(v106 + v241, 25);
      v250 = v101 ^ __ROR4__(v298 + v274, 25);
      v266 = v103 ^ __ROR4__(v107 + v229, 25);
      v258 = v104 ^ __ROR4__(v105 + v96, 25);
      v89 = v97 ^ __ROR4__(v94 + v106, 23);
      v87 = v98 ^ __ROR4__(v266 + v107, 23);
      v88 = v99 ^ __ROR4__(v258 + v105, 23);
      v86 = v100 ^ __ROR4__(v250 + v298, 23);
      v90 = v96 ^ __ROR4__(v88 + v258, 19);
      v93 = v229 ^ __ROR4__(v87 + v266, 19);
      v92 = v241 ^ __ROR4__(v89 + v94, 19);
      v240 = v274 ^ __ROR4__(v86 + v250, 19);
      v95 = v105 ^ __ROR4__(v90 + v88, 14);
      v290 = v106 ^ __ROR4__(v92 + v89, 14);
      v282 = v107 ^ __ROR4__(v93 + v87, 14);
      v91 = v298 ^ __ROR4__(v240 + v86, 14);
    }
    while ( !v28 );
    v311 = v95 + v314;
    dest += 256;
    src[16] = v311;
    v419 = v88 + v422;
    v413 = v258 + v416;
    src[17] = v413;
    src[18] = v419;
    v425 = v90 + v428;
    src[19] = v425;
    v437 = v282 + v440;
    src[21] = v437;
    v431 = v93 + v434;
    src[20] = v431;
    v451 = v87 + v454;
    v445 = v266 + v448;
    src[22] = v445;
    v459 = v89 + v462;
    v465 = v92 + v468;
    src[23] = v451;
    v475 = v94 + v478;
    src[27] = v475;
    src[24] = v459;
    v471 = v290 + v474;
    src[25] = v465;
    src[26] = v471;
    v481 = v250 + v484;
    v485 = v86 + v488;
    src[28] = v481;
    v491 = v240 + v494;
    src[29] = v485;
    v495 = v91 + v498;
    src[30] = v491;
    src[31] = v495;
  }
  while ( dest != v505 );
  v108 = v311;
  desta = 512;
  do
  {
    v109 = src;
    v110 = (int)&v504[128 * (v108 & 0x3FF) - 8];
    do
    {
      v111 = *(_QWORD *)(v110 + 8);
      v110 += 8;
      *(_QWORD *)v109 ^= v111;
      v109 += 2;
    }
    while ( v109 != (int *)&v555 );
    v345 = src[18] ^ src[2];
    v333 = src[17] ^ src[1];
    v321 = src[16] ^ src[0];
    v369 = src[20] ^ src[4];
    v357 = src[19] ^ src[3];
    v307 = 4;
    v259 = src[17] ^ src[1];
    v381 = src[21] ^ src[5];
    v112 = src[18] ^ src[2];
    v113 = src[19] ^ src[3];
    v393 = src[22] ^ src[6];
    v405 = src[23] ^ src[7];
    v417 = src[24] ^ src[8];
    v441 = src[26] ^ src[10];
    v267 = src[22] ^ src[6];
    v455 = src[27] ^ src[11];
    v283 = src[21] ^ src[5];
    v114 = src[25] ^ src[9];
    v115 = src[23] ^ src[7];
    v116 = src[24] ^ src[8];
    v291 = src[26] ^ src[10];
    v469 = src[28] ^ src[12];
    v479 = src[29] ^ src[13];
    v117 = src[30] ^ src[14];
    v118 = src[29] ^ src[13];
    v119 = src[31] ^ src[15];
    v251 = src[28] ^ src[12];
    v120 = src[27] ^ src[11];
    v230 = src[20] ^ src[4];
    v121 = src[16] ^ src[0];
    v489 = src[30] ^ src[14];
    v499 = src[31] ^ src[15];
    do
    {
      v28 = v307-- == 1;
      v122 = v113 ^ __ROR4__(v120 + v119, 25);
      v231 = v230 ^ __ROR4__(v251 + v121, 25);
      v275 = v117 ^ __ROR4__(v267 + v291, 25);
      v242 = v114 ^ __ROR4__(v259 + v283, 25);
      v123 = v116 ^ __ROR4__(v231 + v121, 23);
      v124 = v115 ^ __ROR4__(v122 + v119, 23);
      v125 = v118 ^ __ROR4__(v242 + v283, 23);
      v126 = v112 ^ __ROR4__(v275 + v291, 23);
      v127 = v251 ^ __ROR4__(v123 + v231, 19);
      v128 = v120 ^ __ROR4__(v124 + v122, 19);
      v129 = v267 ^ __ROR4__(v126 + v275, 19);
      v130 = v259 ^ __ROR4__(v125 + v242, 19);
      v299 = v119 ^ __ROR4__(v128 + v124, 14);
      v131 = v121 ^ __ROR4__(v127 + v123, 14);
      v132 = v291 ^ __ROR4__(v129 + v126, 14);
      v133 = v283 ^ __ROR4__(v130 + v125, 14);
      v120 = v128 ^ __ROR4__(v132 + v242, 25);
      v251 = v127 ^ __ROR4__(v299 + v275, 25);
      v267 = v129 ^ __ROR4__(v133 + v231, 25);
      v259 = v130 ^ __ROR4__(v131 + v122, 25);
      v116 = v123 ^ __ROR4__(v120 + v132, 23);
      v115 = v124 ^ __ROR4__(v267 + v133, 23);
      v112 = v126 ^ __ROR4__(v259 + v131, 23);
      v118 = v125 ^ __ROR4__(v251 + v299, 23);
      v113 = v122 ^ __ROR4__(v112 + v259, 19);
      v230 = v231 ^ __ROR4__(v115 + v267, 19);
      v114 = v242 ^ __ROR4__(v116 + v120, 19);
      v117 = v275 ^ __ROR4__(v118 + v251, 19);
      v121 = v131 ^ __ROR4__(v113 + v112, 14);
      v134 = v133 ^ __ROR4__(v230 + v115, 14);
      v283 = v134;
      v119 = v299 ^ __ROR4__(v117 + v118, 14);
      v291 = v132 ^ __ROR4__(v114 + v116, 14);
    }
    while ( !v28 );
    src[0] = v121 + v321;
    v135 = v259 + v333;
    src[4] = v230 + v369;
    src[5] = v134 + v381;
    src[6] = v267 + v393;
    src[7] = v115 + v405;
    v136 = v114 + (src[25] ^ src[9]);
    src[10] = v291 + v441;
    src[12] = v251 + v469;
    src[13] = v118 + v479;
    src[8] = v116 + v417;
    src[11] = v120 + v455;
    src[14] = v117 + v489;
    src[15] = v119 + v499;
    v315 = (v121 + v321) ^ src[16];
    v327 = (v259 + v333) ^ src[17];
    v339 = (v112 + v345) ^ src[18];
    v351 = (v113 + v357) ^ src[19];
    v363 = (v230 + v369) ^ src[20];
    v375 = (v134 + v381) ^ src[21];
    v387 = (v267 + v393) ^ src[22];
    v399 = (v115 + v405) ^ src[23];
    v411 = (v116 + v417) ^ src[24];
    v423 = v136 ^ src[25];
    v429 = (v291 + v441) ^ src[26];
    v435 = (v120 + v455) ^ src[27];
    v442 = (v251 + v469) ^ src[28];
    v456 = (v117 + v489) ^ src[30];
    v252 = v435;
    v137 = (v119 + v499) ^ src[31];
    v138 = (v118 + v479) ^ src[29];
    v463 = v137;
    v268 = v387;
    v292 = v429;
    v449 = v138;
    v260 = v327;
    v284 = v375;
    src[3] = v113 + v357;
    v139 = v339;
    v140 = v411;
    v141 = v351;
    v142 = v136 ^ src[25];
    v143 = v363;
    v144 = v442;
    v308 = 4;
    src[1] = v135;
    src[2] = v112 + v345;
    src[9] = v136;
    v243 = v456;
    v145 = v399;
    v146 = v315;
    do
    {
      v232 = v143 ^ __ROR4__(v144 + v146, 25);
      v28 = v308-- == 1;
      v147 = v141 ^ __ROR4__(v252 + v137, 25);
      v276 = v243 ^ __ROR4__(v268 + v292, 25);
      v148 = v145 ^ __ROR4__(v147 + v137, 23);
      v244 = v142 ^ __ROR4__(v260 + v284, 25);
      v149 = v140 ^ __ROR4__(v232 + v146, 23);
      v150 = v139 ^ __ROR4__(v276 + v292, 23);
      v151 = v138 ^ __ROR4__(v244 + v284, 23);
      v152 = v144 ^ __ROR4__(v149 + v232, 19);
      v153 = v252 ^ __ROR4__(v148 + v147, 19);
      v154 = v260 ^ __ROR4__(v151 + v244, 19);
      v155 = v268 ^ __ROR4__(v150 + v276, 19);
      v300 = v137 ^ __ROR4__(v153 + v148, 14);
      v156 = v146 ^ __ROR4__(v152 + v149, 14);
      v157 = v292 ^ __ROR4__(v155 + v150, 14);
      v158 = v284 ^ __ROR4__(v154 + v151, 14);
      v144 = v152 ^ __ROR4__(v300 + v276, 25);
      v252 = v153 ^ __ROR4__(v157 + v244, 25);
      v260 = v154 ^ __ROR4__(v156 + v147, 25);
      v268 = v155 ^ __ROR4__(v158 + v232, 25);
      v140 = v149 ^ __ROR4__(v252 + v157, 23);
      v145 = v148 ^ __ROR4__(v268 + v158, 23);
      v139 = v150 ^ __ROR4__(v260 + v156, 23);
      v138 = v151 ^ __ROR4__(v144 + v300, 23);
      v141 = v147 ^ __ROR4__(v139 + v260, 19);
      v143 = v232 ^ __ROR4__(v145 + v268, 19);
      v142 = v244 ^ __ROR4__(v140 + v252, 19);
      v243 = v276 ^ __ROR4__(v138 + v144, 19);
      v146 = v156 ^ __ROR4__(v141 + v139, 14);
      v292 = v157 ^ __ROR4__(v142 + v140, 14);
      v284 = v158 ^ __ROR4__(v143 + v145, 14);
      v137 = v300 ^ __ROR4__(v243 + v138, 14);
    }
    while ( !v28 );
    v233 = v145;
    src[16] = v146 + v315;
    src[17] = v260 + v327;
    v159 = src;
    src[18] = v139 + v339;
    src[19] = v141 + v351;
    v160 = (int)&v504[128 * ((v146 + v315) & 0x3FF) - 8];
    src[20] = v143 + v363;
    src[21] = v284 + v375;
    src[22] = v268 + v387;
    src[23] = v233 + v399;
    src[24] = v140 + v411;
    src[25] = v142 + v423;
    src[26] = v292 + v429;
    src[27] = v252 + v435;
    src[28] = v144 + v442;
    src[29] = v138 + v449;
    src[30] = v243 + v456;
    src[31] = v137 + v463;
    do
    {
      v161 = *(_QWORD *)(v160 + 8);
      v160 += 8;
      *(_QWORD *)v159 ^= v161;
      v159 += 2;
    }
    while ( v159 != (int *)&v555 );
    v334 = src[17] ^ src[1];
    v322 = src[16] ^ src[0];
    v370 = src[20] ^ src[4];
    v309 = 4;
    v261 = src[17] ^ src[1];
    v162 = src[19] ^ src[3];
    v358 = src[19] ^ src[3];
    v382 = src[21] ^ src[5];
    v346 = src[18] ^ src[2];
    v394 = src[22] ^ src[6];
    v406 = src[23] ^ src[7];
    v418 = src[24] ^ src[8];
    v443 = src[26] ^ src[10];
    v285 = src[21] ^ src[5];
    v269 = src[22] ^ src[6];
    v457 = src[27] ^ src[11];
    v163 = src[25] ^ src[9];
    v293 = src[26] ^ src[10];
    v164 = src[23] ^ src[7];
    v165 = src[24] ^ src[8];
    v470 = src[28] ^ src[12];
    v480 = src[29] ^ src[13];
    v166 = src[28] ^ src[12];
    v167 = src[29] ^ src[13];
    v168 = src[30] ^ src[14];
    v253 = src[27] ^ src[11];
    v169 = src[31] ^ src[15];
    v234 = src[20] ^ src[4];
    v170 = src[18] ^ src[2];
    v171 = src[16] ^ src[0];
    v490 = src[30] ^ src[14];
    v500 = src[31] ^ src[15];
    do
    {
      v277 = v168 ^ __ROR4__(v293 + v269, 25);
      v28 = v309-- == 1;
      v172 = v162 ^ __ROR4__(v169 + v253, 25);
      v235 = v234 ^ __ROR4__(v171 + v166, 25);
      v245 = v163 ^ __ROR4__(v285 + v261, 25);
      v173 = v165 ^ __ROR4__(v235 + v171, 23);
      v174 = v164 ^ __ROR4__(v172 + v169, 23);
      v175 = v170 ^ __ROR4__(v277 + v293, 23);
      v176 = v167 ^ __ROR4__(v245 + v285, 23);
      v177 = v253 ^ __ROR4__(v174 + v172, 19);
      v178 = v166 ^ __ROR4__(v173 + v235, 19);
      v179 = v269 ^ __ROR4__(v175 + v277, 19);
      v180 = v261 ^ __ROR4__(v176 + v245, 19);
      v301 = v169 ^ __ROR4__(v177 + v174, 14);
      v181 = v171 ^ __ROR4__(v178 + v173, 14);
      v182 = v293 ^ __ROR4__(v179 + v175, 14);
      v183 = v285 ^ __ROR4__(v180 + v176, 14);
      v166 = v178 ^ __ROR4__(v301 + v277, 25);
      v253 = v177 ^ __ROR4__(v182 + v245, 25);
      v261 = v180 ^ __ROR4__(v181 + v172, 25);
      v269 = v179 ^ __ROR4__(v183 + v235, 25);
      v164 = v174 ^ __ROR4__(v269 + v183, 23);
      v165 = v173 ^ __ROR4__(v253 + v182, 23);
      v170 = v175 ^ __ROR4__(v261 + v181, 23);
      v167 = v176 ^ __ROR4__(v166 + v301, 23);
      v162 = v172 ^ __ROR4__(v170 + v261, 19);
      v234 = v235 ^ __ROR4__(v164 + v269, 19);
      v163 = v245 ^ __ROR4__(v165 + v253, 19);
      v168 = v277 ^ __ROR4__(v167 + v166, 19);
      v171 = v181 ^ __ROR4__(v162 + v170, 14);
      v184 = v183 ^ __ROR4__(v234 + v164, 14);
      v285 = v184;
      v169 = v301 ^ __ROR4__(v168 + v167, 14);
      v293 = v182 ^ __ROR4__(v163 + v165, 14);
    }
    while ( !v28 );
    src[0] = v171 + v322;
    v185 = v261 + v334;
    v186 = v170 + v346;
    src[3] = v162 + v358;
    src[4] = v234 + v370;
    src[5] = v184 + v382;
    src[7] = v164 + v406;
    v187 = v163 + (src[25] ^ src[9]);
    src[6] = v269 + v394;
    src[10] = v293 + v443;
    src[12] = v166 + v470;
    src[8] = v165 + v418;
    src[11] = v253 + v457;
    src[13] = v167 + v480;
    src[14] = v168 + v490;
    src[15] = v169 + v500;
    v316 = (v171 + v322) ^ src[16];
    v328 = (v261 + v334) ^ src[17];
    v340 = (v170 + v346) ^ src[18];
    v352 = (v162 + v358) ^ src[19];
    v364 = (v234 + v370) ^ src[20];
    v376 = (v184 + v382) ^ src[21];
    v388 = (v269 + v394) ^ src[22];
    v400 = (v164 + v406) ^ src[23];
    v412 = (v165 + v418) ^ src[24];
    v424 = v187 ^ src[25];
    v430 = (v293 + v443) ^ src[26];
    v436 = (v253 + v457) ^ src[27];
    v444 = (v166 + v470) ^ src[28];
    v450 = (v167 + v480) ^ src[29];
    v188 = v436;
    v262 = v388;
    v458 = (v168 + v490) ^ src[30];
    v270 = v328;
    v286 = v376;
    v464 = (v169 + v500) ^ src[31];
    v294 = v316;
    src[2] = v186;
    v189 = v458;
    v190 = v400;
    v191 = v340;
    v192 = v412;
    v193 = v352;
    v194 = v464;
    v195 = v187 ^ src[25];
    v196 = v364;
    v310 = 4;
    src[1] = v185;
    src[9] = v187;
    v254 = v444;
    v197 = v430;
    v198 = v450;
    do
    {
      v236 = v196 ^ __ROR4__(v294 + v254, 25);
      v278 = v189 ^ __ROR4__(v197 + v262, 25);
      v199 = v193 ^ __ROR4__(v194 + v188, 25);
      v28 = v310-- == 1;
      v200 = v190 ^ __ROR4__(v199 + v194, 23);
      v201 = v192 ^ __ROR4__(v236 + v294, 23);
      v246 = v195 ^ __ROR4__(v286 + v270, 25);
      v202 = v191 ^ __ROR4__(v278 + v197, 23);
      v203 = v198 ^ __ROR4__(v246 + v286, 23);
      v204 = v188 ^ __ROR4__(v200 + v199, 19);
      v205 = v254 ^ __ROR4__(v201 + v236, 19);
      v206 = v262 ^ __ROR4__(v202 + v278, 19);
      v207 = v270 ^ __ROR4__(v203 + v246, 19);
      v208 = v294 ^ __ROR4__(v205 + v201, 14);
      v302 = v194 ^ __ROR4__(v204 + v200, 14);
      v209 = v197 ^ __ROR4__(v206 + v202, 14);
      v210 = v286 ^ __ROR4__(v207 + v203, 14);
      v188 = v204 ^ __ROR4__(v209 + v246, 25);
      v254 = v205 ^ __ROR4__(v302 + v278, 25);
      v211 = v207 ^ __ROR4__(v208 + v199, 25);
      v262 = v206 ^ __ROR4__(v210 + v236, 25);
      v190 = v200 ^ __ROR4__(v262 + v210, 23);
      v191 = v202 ^ __ROR4__(v211 + v208, 23);
      v192 = v201 ^ __ROR4__(v188 + v209, 23);
      v270 = v211;
      v198 = v203 ^ __ROR4__(v254 + v302, 23);
      v193 = v199 ^ __ROR4__(v191 + v211, 19);
      v195 = v246 ^ __ROR4__(v192 + v188, 19);
      v196 = v236 ^ __ROR4__(v190 + v262, 19);
      v189 = v278 ^ __ROR4__(v198 + v254, 19);
      v294 = v208 ^ __ROR4__(v193 + v191, 14);
      v286 = v210 ^ __ROR4__(v196 + v190, 14);
      v197 = v209 ^ __ROR4__(v195 + v192, 14);
      v194 = v302 ^ __ROR4__(v189 + v198, 14);
    }
    while ( !v28 );
    v28 = desta-- == 1;
    v108 = v294 + v316;
    src[17] = v270 + v328;
    src[18] = v191 + v340;
    src[19] = v193 + v352;
    src[20] = v196 + v364;
    src[21] = v286 + v376;
    src[23] = v190 + v400;
    src[22] = v262 + v388;
    src[24] = v192 + v412;
    src[25] = v195 + v424;
    src[26] = v197 + v430;
    src[16] = v294 + v316;
    src[27] = v188 + v436;
    src[29] = v198 + v450;
    src[28] = v254 + v444;
    src[30] = v189 + v458;
    src[31] = v194 + v464;
  }
  while ( !v28 );
  v526 = 1779033703;
  v527 = -1150833019;
  v528 = 1013904242;
  v529 = -1521486534;
  v530 = 1359893119;
  v531 = -1694144372;
  v532 = 528734635;
  v533 = 1541459225;
  sub_FBC8(&v526, a1, 1);
  v212 = a1[17];
  v213 = a1[18];
  v214 = a1[19];
  v545 = a1[16];
  v546 = v212;
  v547 = v213;
  v548 = v214;
  v549 = 128;
  v550 = 0;
  v551 = 0;
  v552 = 0;
  memset(v553, 0, 28);
  v553[7] = -2147352576;
  sub_FBC8(&v526, &v545, 1);
  v215 = v526;
  v216 = v527;
  v217 = v528;
  v218 = v529;
  a3[6] = 528734635;
  v535 = v215;
  v536 = v216;
  v537 = v217;
  v538 = v218;
  v219 = v530;
  v220 = v531;
  v221 = v532;
  v222 = v533;
  *a3 = 1779033703;
  a3[1] = -1150833019;
  a3[2] = 1013904242;
  a3[3] = -1521486534;
  a3[4] = 1359893119;
  a3[5] = -1694144372;
  a3[7] = 1541459225;
  v223 = desta;
  v539 = v219;
  v540 = v220;
  v541 = v221;
  v542 = v222;
  do
  {
    *(int *)((char *)&v545 + v223) = *(int *)((char *)&v535 + v223) ^ 0x5C5C5C5C;
    v223 += 4;
  }
  while ( v223 != 32 );
  memset(v553, 92, 32);
  sub_FBC8(a3, &v545, 0);
  v224 = 0;
  v526 = 1779033703;
  v527 = -1150833019;
  v528 = 1013904242;
  v529 = -1521486534;
  v530 = 1359893119;
  v531 = -1694144372;
  v532 = 528734635;
  v533 = 1541459225;
  do
  {
    *(int *)((char *)&v545 + v224) = *(int *)((char *)&v535 + v224) ^ 0x36363636;
    v224 += 4;
  }
  while ( v224 != 32 );
  memset(v553, 54, 32);
  sub_FBC8(&v526, &v545, 0);
  sub_FBC8(&v526, src, 1);
  sub_FBC8(&v526, &src[16], 1);
  sub_FBC8(&v526, dword_5AA04, 0);
  v545 = v526;
  v546 = v527;
  v547 = v528;
  v548 = v529;
  v549 = v530;
  v550 = v531;
  v551 = v532;
  v552 = v533;
  v553[0] = 0x80000000;
  memset(&v553[1], 0, 24);
  v553[7] = 768;
  return sub_FBC8(a3, &v545, 0);
}
