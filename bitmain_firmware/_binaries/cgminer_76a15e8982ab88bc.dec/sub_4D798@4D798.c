int __fastcall sub_4D798(int a1, unsigned __int8 *a2)
{
  __int64 *v2; // r12
  unsigned __int8 *v3; // r6
  unsigned int v4; // r2
  unsigned int v5; // d16.s[0]
  __int64 v6; // d19
  int v7; // r12
  __int64 *v8; // r1
  __int64 v9; // t1
  __int64 v10; // r2
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // d18
  unsigned int v13; // r12
  unsigned int v14; // r1
  __int64 v15; // r2
  __int64 v16; // r4
  __int64 v17; // r8
  __int64 v18; // r2
  signed __int64 v19; // r2
  unsigned __int64 v20; // r10
  __int64 v21; // r2
  unsigned __int64 v22; // r4
  __int64 v23; // r4
  __int64 v24; // r2
  __int64 v25; // r6
  unsigned __int64 v26; // r8
  __int64 v27; // r4
  signed __int64 v28; // r2
  unsigned __int64 v29; // r6
  __int64 v30; // r0
  __int64 v31; // r10
  __int64 v32; // r2
  __int64 v33; // r4
  __int64 v34; // r0
  __int64 v35; // r4
  __int64 v36; // r6
  unsigned __int64 v37; // r4
  __int64 v38; // r2
  __int64 v39; // r4
  unsigned __int64 v40; // r6
  signed __int64 v41; // r0
  __int64 v42; // r4
  unsigned __int64 v43; // r0
  unsigned __int64 v44; // r6
  __int64 v45; // r4
  __int64 v46; // r0
  __int64 v47; // r8
  __int64 v48; // r4
  unsigned __int64 v49; // r10
  __int64 v50; // r2
  __int64 v51; // r10
  __int64 v52; // r2
  __int64 v53; // r6
  signed __int64 v54; // r4
  signed __int64 v55; // r0
  signed __int64 v56; // r6
  __int64 v57; // r2
  signed __int64 v58; // r0
  __int64 v59; // r0
  unsigned __int64 v60; // r10
  __int64 v61; // r8
  unsigned __int64 v62; // r4
  int v63; // r12
  unsigned __int64 v64; // r6
  signed __int64 v65; // r0
  __int64 v66; // r2
  __int64 v67; // r8
  __int64 v68; // r4
  __int64 v69; // r0
  __int64 v70; // r2
  unsigned __int64 v71; // r6
  __int64 v72; // r6
  signed __int64 v73; // r2
  __int64 v74; // r4
  __int64 v75; // r0
  unsigned __int64 v76; // r4
  __int64 v77; // r0
  unsigned __int64 v78; // r6
  unsigned __int64 v79; // r4
  __int64 v80; // r4
  __int64 v81; // r0
  unsigned __int64 v82; // r6
  unsigned __int64 v83; // r4
  int v84; // r12
  unsigned __int64 v85; // r10
  __int64 v86; // r0
  __int64 v87; // r10
  signed __int64 v88; // r2
  __int64 v89; // r2
  signed __int64 v90; // r0
  unsigned __int64 v91; // r0
  __int64 v92; // r4
  unsigned __int64 v93; // r6
  signed __int64 v94; // r0
  unsigned __int64 v95; // r2
  unsigned int v96; // r12
  __int64 v97; // r4
  __int64 v98; // r6
  __int64 v99; // r2
  unsigned __int64 v100; // r4
  __int64 v101; // r6
  __int64 v102; // r8
  __int64 v103; // r4
  __int64 v104; // r8
  __int64 v105; // r6
  signed __int64 v106; // r2
  unsigned __int64 v107; // r8
  unsigned __int64 v108; // r4
  __int64 v109; // r2
  __int64 v110; // r2
  unsigned __int64 v111; // r8
  signed __int64 v112; // r4
  __int64 v113; // r6
  __int64 v114; // r2
  __int64 v115; // r6
  __int64 v116; // r4
  unsigned __int64 v117; // r8
  __int64 v118; // r0
  __int64 v119; // r6
  unsigned __int64 v120; // r8
  __int64 v121; // r4
  __int64 v122; // r4
  unsigned __int64 v123; // r4
  __int64 v124; // r2
  __int64 v125; // r4
  __int64 v126; // r2
  unsigned __int64 v127; // r4
  __int64 v128; // r0
  __int64 v129; // r2
  unsigned __int64 v130; // r4
  unsigned __int64 v131; // r10
  __int64 v132; // r4
  int v133; // r12
  __int64 v134; // r4
  __int64 v135; // r2
  __int64 v136; // r2
  __int64 v137; // r2
  __int64 v138; // r4
  __int64 v139; // r6
  __int64 v140; // r0
  unsigned __int64 v141; // r4
  signed __int64 v142; // r4
  unsigned __int64 v143; // r6
  __int64 v144; // r0
  unsigned __int64 v145; // r2
  __int64 v146; // r0
  __int64 v147; // r2
  unsigned __int64 v148; // r2
  __int64 v149; // r0
  __int64 v150; // r8
  __int64 v151; // r4
  __int64 v152; // r2
  signed __int64 v153; // r4
  __int64 v154; // r8
  signed __int64 v155; // r2
  __int64 v156; // r0
  __int64 v157; // r4
  __int64 v158; // r10
  signed __int64 v159; // r0
  unsigned __int64 v160; // r4
  __int64 v161; // r0
  __int64 v162; // r2
  __int64 v163; // r4
  __int64 v164; // r0
  __int64 v165; // r2
  __int64 v166; // r6
  __int64 v167; // r6
  __int64 v168; // r6
  __int64 v169; // r4
  __int64 v170; // r2
  unsigned __int64 v171; // r8
  unsigned __int64 v172; // r10
  signed __int64 v173; // r0
  __int64 v174; // r10
  __int64 v175; // r2
  __int64 v176; // r0
  unsigned __int64 v177; // r4
  __int64 v178; // r2
  unsigned __int64 v179; // r6
  unsigned __int64 v180; // r10
  __int64 v181; // r4
  unsigned __int64 v182; // r0
  __int64 v183; // r8
  __int64 v184; // r2
  __int64 v185; // r2
  __int64 v186; // r6
  unsigned __int64 v187; // r0
  __int64 v188; // r4
  __int64 v189; // r0
  __int64 v190; // r6
  unsigned __int64 v191; // r4
  __int64 v192; // r6
  __int64 v193; // r2
  __int64 v194; // r6
  __int64 v195; // r2
  __int64 v196; // r4
  unsigned __int64 v197; // r0
  __int64 v198; // r2
  unsigned __int64 v199; // r8
  __int64 v200; // r10
  __int64 v201; // r4
  __int64 v202; // r0
  __int64 v203; // r2
  __int64 v204; // r4
  __int64 v205; // r0
  __int64 v206; // r6
  unsigned __int64 v207; // r2
  unsigned __int64 v208; // r10
  signed __int64 v209; // r8
  signed __int64 v210; // r2
  unsigned __int64 v211; // r4
  unsigned __int64 v212; // r8
  __int64 v213; // r2
  int v214; // r12
  unsigned __int64 v215; // r6
  __int64 v216; // r10
  unsigned __int64 v217; // r8
  __int64 v218; // r6
  __int64 v219; // r2
  __int64 v220; // r4
  unsigned __int64 v221; // r2
  unsigned __int64 v222; // r4
  unsigned __int64 v223; // r0
  unsigned __int64 v224; // r10
  __int64 v225; // r2
  unsigned __int64 v226; // r4
  unsigned __int64 v227; // r4
  __int64 v228; // r0
  __int64 v229; // r4
  __int64 v230; // r0
  unsigned __int64 v231; // r6
  unsigned __int64 v232; // r10
  unsigned int v233; // kr54_4
  __int64 v234; // r2
  __int64 v235; // r0
  unsigned __int64 v236; // r10
  __int64 v237; // r6
  __int64 v238; // r2
  __int64 v239; // r10
  unsigned __int64 v240; // r0
  __int64 v241; // r4
  unsigned __int64 v242; // r10
  __int64 v243; // r0
  __int64 v244; // r4
  __int64 v245; // r2
  __int64 v246; // r2
  signed __int64 v247; // r4
  __int64 v248; // r0
  __int64 v249; // r2
  __int64 v250; // r4
  unsigned __int64 v251; // r10
  __int64 v252; // r0
  int v253; // r12
  unsigned __int64 v254; // r2
  unsigned __int64 v255; // r6
  unsigned __int64 v256; // r4
  __int64 v257; // r4
  __int64 v258; // r0
  __int64 v259; // r6
  __int64 v260; // r0
  __int64 v261; // r4
  unsigned __int64 v262; // r0
  __int64 v263; // r2
  unsigned __int64 v264; // r8
  __int64 v265; // r2
  __int64 v266; // r6
  __int64 v267; // r4
  __int64 v268; // r0
  __int64 v269; // r4
  unsigned __int64 v270; // r6
  unsigned __int64 v271; // r4
  signed __int64 v272; // r0
  __int64 v273; // r2
  __int64 v274; // r6
  signed __int64 v275; // r0
  __int64 v276; // r0
  unsigned __int64 v277; // r6
  __int64 v278; // r10
  unsigned int v279; // kr74_4
  unsigned int v280; // kr78_4
  signed __int64 v281; // r2
  unsigned __int64 v282; // r10
  signed __int64 v283; // r0
  unsigned __int64 v284; // r4
  unsigned __int64 v285; // r2
  unsigned __int64 v286; // r4
  __int64 v287; // r0
  unsigned __int64 v288; // r4
  unsigned __int64 v289; // r6
  int v290; // r12
  __int64 v291; // r4
  __int64 v292; // r0
  __int64 v293; // r4
  unsigned __int64 v294; // r8
  unsigned __int64 v295; // r2
  unsigned __int64 v296; // r4
  __int64 v297; // r4
  __int64 v298; // r2
  __int64 v299; // r0
  __int64 v300; // r6
  __int64 v301; // r2
  __int64 v302; // r4
  __int64 v303; // r4
  unsigned __int64 v304; // r10
  __int64 v305; // r2
  unsigned __int64 v306; // r4
  unsigned __int64 v307; // r2
  unsigned __int64 v308; // r0
  signed __int64 v309; // r0
  __int64 v310; // r4
  signed __int64 v311; // r2
  signed __int64 v312; // r6
  unsigned __int64 v313; // r8
  __int64 v314; // r6
  __int64 v315; // r8
  signed __int64 v316; // r4
  __int64 v317; // r6
  unsigned __int64 v318; // r8
  signed __int64 v319; // r6
  unsigned __int64 v320; // r10
  __int64 v321; // r8
  signed __int64 v322; // r0
  __int64 v323; // r2
  int v324; // r12
  unsigned __int64 v325; // r10
  int result; // r0
  __int64 v327; // r8
  unsigned __int64 v328; // r6
  __int64 v329; // r4
  unsigned __int64 v330; // r2
  __int64 v331; // r2
  unsigned __int64 v332; // r2
  __int64 v333; // r6
  unsigned __int64 v334; // r10
  __int64 v335; // r4
  __int64 v336; // r2
  _QWORD *v337; // r12
  __int64 v338; // r8
  __int64 *v339; // r6
  _QWORD *i; // r1
  __int64 v341; // t1
  unsigned __int64 v342; // t1
  unsigned __int64 v343; // [sp+0h] [bp-220h]
  unsigned __int64 v344; // [sp+0h] [bp-220h]
  unsigned __int64 v345; // [sp+0h] [bp-220h]
  __int64 v346; // [sp+0h] [bp-220h]
  unsigned __int64 v347; // [sp+0h] [bp-220h]
  unsigned __int64 v348; // [sp+0h] [bp-220h]
  unsigned __int64 v349; // [sp+0h] [bp-220h]
  __int64 v350; // [sp+0h] [bp-220h]
  unsigned __int64 v351; // [sp+0h] [bp-220h]
  unsigned __int64 v352; // [sp+0h] [bp-220h]
  unsigned __int64 v353; // [sp+0h] [bp-220h]
  unsigned __int64 v354; // [sp+0h] [bp-220h]
  unsigned __int64 v355; // [sp+0h] [bp-220h]
  unsigned __int64 v356; // [sp+0h] [bp-220h]
  unsigned __int64 v357; // [sp+0h] [bp-220h]
  unsigned __int64 v358; // [sp+0h] [bp-220h]
  unsigned __int64 v359; // [sp+0h] [bp-220h]
  unsigned __int64 v360; // [sp+0h] [bp-220h]
  unsigned __int64 v361; // [sp+8h] [bp-218h]
  unsigned __int64 v362; // [sp+8h] [bp-218h]
  unsigned __int64 v363; // [sp+8h] [bp-218h]
  unsigned __int64 v364; // [sp+8h] [bp-218h]
  __int64 v365; // [sp+8h] [bp-218h]
  unsigned __int64 v366; // [sp+8h] [bp-218h]
  unsigned __int64 v367; // [sp+8h] [bp-218h]
  unsigned __int64 v368; // [sp+8h] [bp-218h]
  unsigned __int64 v369; // [sp+8h] [bp-218h]
  unsigned __int64 v370; // [sp+8h] [bp-218h]
  __int64 v371; // [sp+8h] [bp-218h]
  unsigned __int64 v372; // [sp+8h] [bp-218h]
  unsigned __int64 v373; // [sp+8h] [bp-218h]
  __int64 v374; // [sp+8h] [bp-218h]
  __int64 v375; // [sp+10h] [bp-210h]
  __int64 v376; // [sp+10h] [bp-210h]
  __int64 v377; // [sp+10h] [bp-210h]
  __int64 v378; // [sp+10h] [bp-210h]
  unsigned __int64 v379; // [sp+10h] [bp-210h]
  unsigned __int64 v380; // [sp+10h] [bp-210h]
  unsigned __int64 v381; // [sp+10h] [bp-210h]
  unsigned __int64 v382; // [sp+10h] [bp-210h]
  __int64 v383; // [sp+10h] [bp-210h]
  __int64 v384; // [sp+10h] [bp-210h]
  unsigned __int64 v385; // [sp+10h] [bp-210h]
  __int64 v386; // [sp+10h] [bp-210h]
  __int64 v387; // [sp+10h] [bp-210h]
  __int64 v388; // [sp+10h] [bp-210h]
  __int64 v389; // [sp+18h] [bp-208h]
  unsigned __int64 v390; // [sp+18h] [bp-208h]
  unsigned __int64 v391; // [sp+18h] [bp-208h]
  unsigned __int64 v392; // [sp+18h] [bp-208h]
  unsigned __int64 v393; // [sp+18h] [bp-208h]
  __int64 v394; // [sp+18h] [bp-208h]
  __int64 v395; // [sp+18h] [bp-208h]
  unsigned __int64 v396; // [sp+18h] [bp-208h]
  unsigned __int64 v397; // [sp+18h] [bp-208h]
  __int64 v398; // [sp+18h] [bp-208h]
  __int64 v399; // [sp+18h] [bp-208h]
  __int64 v400; // [sp+18h] [bp-208h]
  unsigned __int64 v401; // [sp+18h] [bp-208h]
  __int64 v402; // [sp+18h] [bp-208h]
  __int64 v403; // [sp+18h] [bp-208h]
  __int64 v404; // [sp+18h] [bp-208h]
  __int64 v405; // [sp+18h] [bp-208h]
  unsigned __int64 v406; // [sp+20h] [bp-200h]
  unsigned __int64 v407; // [sp+20h] [bp-200h]
  unsigned __int64 v408; // [sp+20h] [bp-200h]
  __int64 v409; // [sp+20h] [bp-200h]
  unsigned __int64 v410; // [sp+20h] [bp-200h]
  unsigned __int64 v411; // [sp+20h] [bp-200h]
  unsigned __int64 v412; // [sp+20h] [bp-200h]
  unsigned __int64 v413; // [sp+20h] [bp-200h]
  unsigned __int64 v414; // [sp+20h] [bp-200h]
  unsigned __int64 v415; // [sp+20h] [bp-200h]
  unsigned __int64 v416; // [sp+20h] [bp-200h]
  unsigned __int64 v417; // [sp+20h] [bp-200h]
  unsigned __int64 v418; // [sp+20h] [bp-200h]
  unsigned __int64 v419; // [sp+20h] [bp-200h]
  __int64 v420; // [sp+28h] [bp-1F8h]
  unsigned __int64 v421; // [sp+28h] [bp-1F8h]
  unsigned __int64 v422; // [sp+28h] [bp-1F8h]
  unsigned __int64 v423; // [sp+28h] [bp-1F8h]
  unsigned __int64 v424; // [sp+28h] [bp-1F8h]
  unsigned __int64 v425; // [sp+28h] [bp-1F8h]
  unsigned __int64 v426; // [sp+28h] [bp-1F8h]
  __int64 v427; // [sp+28h] [bp-1F8h]
  unsigned __int64 v428; // [sp+28h] [bp-1F8h]
  unsigned __int64 v429; // [sp+28h] [bp-1F8h]
  unsigned __int64 v430; // [sp+28h] [bp-1F8h]
  unsigned __int64 v431; // [sp+28h] [bp-1F8h]
  unsigned __int64 v432; // [sp+28h] [bp-1F8h]
  unsigned __int64 v433; // [sp+28h] [bp-1F8h]
  unsigned __int64 v434; // [sp+30h] [bp-1F0h]
  unsigned __int64 v435; // [sp+30h] [bp-1F0h]
  __int64 v436; // [sp+30h] [bp-1F0h]
  __int64 v437; // [sp+30h] [bp-1F0h]
  unsigned __int64 v438; // [sp+30h] [bp-1F0h]
  __int64 v439; // [sp+30h] [bp-1F0h]
  unsigned __int64 v440; // [sp+30h] [bp-1F0h]
  unsigned __int64 v441; // [sp+30h] [bp-1F0h]
  __int64 v442; // [sp+30h] [bp-1F0h]
  unsigned __int64 v443; // [sp+30h] [bp-1F0h]
  unsigned __int64 v444; // [sp+30h] [bp-1F0h]
  __int64 v445; // [sp+30h] [bp-1F0h]
  __int64 v446; // [sp+30h] [bp-1F0h]
  unsigned __int64 v447; // [sp+30h] [bp-1F0h]
  __int64 v448; // [sp+30h] [bp-1F0h]
  __int64 v449; // [sp+30h] [bp-1F0h]
  __int64 v450; // [sp+30h] [bp-1F0h]
  __int64 v451; // [sp+30h] [bp-1F0h]
  __int64 v452; // [sp+30h] [bp-1F0h]
  unsigned __int64 v453; // [sp+30h] [bp-1F0h]
  __int64 v454; // [sp+30h] [bp-1F0h]
  __int64 v455; // [sp+30h] [bp-1F0h]
  unsigned __int64 v456; // [sp+30h] [bp-1F0h]
  unsigned __int64 v457; // [sp+30h] [bp-1F0h]
  unsigned __int64 v458; // [sp+30h] [bp-1F0h]
  unsigned __int64 v459; // [sp+30h] [bp-1F0h]
  __int64 v460; // [sp+30h] [bp-1F0h]
  unsigned __int64 v461; // [sp+38h] [bp-1E8h]
  unsigned __int64 v462; // [sp+38h] [bp-1E8h]
  unsigned __int64 v463; // [sp+38h] [bp-1E8h]
  unsigned __int64 v464; // [sp+38h] [bp-1E8h]
  __int64 v465; // [sp+38h] [bp-1E8h]
  unsigned __int64 v466; // [sp+38h] [bp-1E8h]
  __int64 v467; // [sp+38h] [bp-1E8h]
  unsigned __int64 v468; // [sp+38h] [bp-1E8h]
  unsigned __int64 v469; // [sp+38h] [bp-1E8h]
  __int64 v470; // [sp+38h] [bp-1E8h]
  unsigned __int64 v471; // [sp+38h] [bp-1E8h]
  unsigned __int64 v472; // [sp+38h] [bp-1E8h]
  unsigned __int64 v473; // [sp+38h] [bp-1E8h]
  unsigned __int64 v474; // [sp+38h] [bp-1E8h]
  unsigned __int64 v475; // [sp+38h] [bp-1E8h]
  unsigned __int64 v476; // [sp+38h] [bp-1E8h]
  __int64 v477; // [sp+38h] [bp-1E8h]
  __int64 v478; // [sp+40h] [bp-1E0h]
  unsigned __int64 v479; // [sp+40h] [bp-1E0h]
  unsigned __int64 v480; // [sp+40h] [bp-1E0h]
  unsigned __int64 v481; // [sp+40h] [bp-1E0h]
  unsigned __int64 v482; // [sp+40h] [bp-1E0h]
  unsigned __int64 v483; // [sp+40h] [bp-1E0h]
  unsigned __int64 v484; // [sp+40h] [bp-1E0h]
  __int64 v485; // [sp+40h] [bp-1E0h]
  unsigned __int64 v486; // [sp+40h] [bp-1E0h]
  __int64 v487; // [sp+40h] [bp-1E0h]
  unsigned __int64 v488; // [sp+40h] [bp-1E0h]
  __int64 v489; // [sp+40h] [bp-1E0h]
  __int64 v490; // [sp+40h] [bp-1E0h]
  __int64 v491; // [sp+40h] [bp-1E0h]
  __int64 v492; // [sp+40h] [bp-1E0h]
  __int64 v493; // [sp+40h] [bp-1E0h]
  __int64 v494; // [sp+40h] [bp-1E0h]
  __int64 v495; // [sp+40h] [bp-1E0h]
  unsigned __int64 v496; // [sp+40h] [bp-1E0h]
  __int64 v497; // [sp+40h] [bp-1E0h]
  unsigned __int64 v498; // [sp+40h] [bp-1E0h]
  __int64 v499; // [sp+40h] [bp-1E0h]
  __int64 v500; // [sp+40h] [bp-1E0h]
  unsigned __int64 v501; // [sp+40h] [bp-1E0h]
  unsigned __int64 v502; // [sp+40h] [bp-1E0h]
  __int64 v503; // [sp+40h] [bp-1E0h]
  unsigned __int64 v504; // [sp+40h] [bp-1E0h]
  unsigned __int64 v505; // [sp+40h] [bp-1E0h]
  unsigned __int64 v506; // [sp+40h] [bp-1E0h]
  unsigned __int64 v507; // [sp+40h] [bp-1E0h]
  __int64 v508; // [sp+40h] [bp-1E0h]
  __int64 v509; // [sp+40h] [bp-1E0h]
  __int64 v510; // [sp+48h] [bp-1D8h]
  unsigned __int64 v511; // [sp+48h] [bp-1D8h]
  unsigned __int64 v512; // [sp+48h] [bp-1D8h]
  __int64 v513; // [sp+48h] [bp-1D8h]
  unsigned __int64 v514; // [sp+48h] [bp-1D8h]
  __int64 v515; // [sp+48h] [bp-1D8h]
  unsigned __int64 v516; // [sp+48h] [bp-1D8h]
  __int64 v517; // [sp+48h] [bp-1D8h]
  unsigned __int64 v518; // [sp+48h] [bp-1D8h]
  __int64 v519; // [sp+48h] [bp-1D8h]
  __int64 v520; // [sp+48h] [bp-1D8h]
  unsigned __int64 v521; // [sp+48h] [bp-1D8h]
  __int64 v522; // [sp+48h] [bp-1D8h]
  __int64 v523; // [sp+48h] [bp-1D8h]
  unsigned __int64 v524; // [sp+48h] [bp-1D8h]
  unsigned __int64 v525; // [sp+48h] [bp-1D8h]
  unsigned __int64 v526; // [sp+48h] [bp-1D8h]
  unsigned __int64 v527; // [sp+48h] [bp-1D8h]
  unsigned __int64 v528; // [sp+48h] [bp-1D8h]
  unsigned __int64 v529; // [sp+48h] [bp-1D8h]
  unsigned __int64 v530; // [sp+48h] [bp-1D8h]
  unsigned __int64 v531; // [sp+48h] [bp-1D8h]
  __int64 v532; // [sp+48h] [bp-1D8h]
  __int64 v533; // [sp+48h] [bp-1D8h]
  unsigned __int64 v534; // [sp+48h] [bp-1D8h]
  unsigned __int64 v535; // [sp+48h] [bp-1D8h]
  unsigned __int64 v536; // [sp+48h] [bp-1D8h]
  unsigned __int64 v537; // [sp+48h] [bp-1D8h]
  unsigned __int64 v538; // [sp+48h] [bp-1D8h]
  unsigned __int64 v539; // [sp+50h] [bp-1D0h]
  unsigned __int64 v540; // [sp+50h] [bp-1D0h]
  __int64 v541; // [sp+50h] [bp-1D0h]
  unsigned __int64 v542; // [sp+50h] [bp-1D0h]
  unsigned __int64 v543; // [sp+50h] [bp-1D0h]
  __int64 v544; // [sp+50h] [bp-1D0h]
  __int64 v545; // [sp+50h] [bp-1D0h]
  unsigned __int64 v546; // [sp+50h] [bp-1D0h]
  unsigned __int64 v547; // [sp+50h] [bp-1D0h]
  unsigned __int64 v548; // [sp+50h] [bp-1D0h]
  __int64 v549; // [sp+50h] [bp-1D0h]
  unsigned __int64 v550; // [sp+50h] [bp-1D0h]
  unsigned __int64 v551; // [sp+50h] [bp-1D0h]
  unsigned __int64 v552; // [sp+50h] [bp-1D0h]
  unsigned __int64 v553; // [sp+50h] [bp-1D0h]
  __int64 v554; // [sp+50h] [bp-1D0h]
  __int64 v555; // [sp+50h] [bp-1D0h]
  unsigned __int64 v556; // [sp+50h] [bp-1D0h]
  unsigned __int64 v557; // [sp+50h] [bp-1D0h]
  __int64 v558; // [sp+50h] [bp-1D0h]
  unsigned __int64 v559; // [sp+50h] [bp-1D0h]
  __int64 v560; // [sp+50h] [bp-1D0h]
  __int64 v561; // [sp+50h] [bp-1D0h]
  __int64 v562; // [sp+50h] [bp-1D0h]
  __int64 v563; // [sp+50h] [bp-1D0h]
  unsigned __int64 v564; // [sp+50h] [bp-1D0h]
  unsigned __int64 v565; // [sp+50h] [bp-1D0h]
  __int64 v566; // [sp+50h] [bp-1D0h]
  __int64 v567; // [sp+50h] [bp-1D0h]
  unsigned __int64 v568; // [sp+50h] [bp-1D0h]
  unsigned __int64 v569; // [sp+50h] [bp-1D0h]
  unsigned __int64 v570; // [sp+50h] [bp-1D0h]
  unsigned __int64 v571; // [sp+50h] [bp-1D0h]
  __int64 v572; // [sp+58h] [bp-1C8h]
  unsigned __int64 v573; // [sp+58h] [bp-1C8h]
  unsigned __int64 v574; // [sp+58h] [bp-1C8h]
  __int64 v575; // [sp+58h] [bp-1C8h]
  unsigned __int64 v576; // [sp+58h] [bp-1C8h]
  __int64 v577; // [sp+58h] [bp-1C8h]
  __int64 v578; // [sp+58h] [bp-1C8h]
  __int64 v579; // [sp+58h] [bp-1C8h]
  unsigned __int64 v580; // [sp+58h] [bp-1C8h]
  unsigned __int64 v581; // [sp+58h] [bp-1C8h]
  unsigned __int64 v582; // [sp+58h] [bp-1C8h]
  unsigned __int64 v583; // [sp+58h] [bp-1C8h]
  __int64 v584; // [sp+58h] [bp-1C8h]
  unsigned __int64 v585; // [sp+58h] [bp-1C8h]
  unsigned __int64 v586; // [sp+58h] [bp-1C8h]
  unsigned __int64 v587; // [sp+58h] [bp-1C8h]
  __int64 v588; // [sp+58h] [bp-1C8h]
  __int64 v589; // [sp+58h] [bp-1C8h]
  __int64 v590; // [sp+58h] [bp-1C8h]
  unsigned __int64 v591; // [sp+58h] [bp-1C8h]
  unsigned __int64 v592; // [sp+58h] [bp-1C8h]
  __int64 v593; // [sp+58h] [bp-1C8h]
  __int64 v594; // [sp+58h] [bp-1C8h]
  __int64 v595; // [sp+58h] [bp-1C8h]
  __int64 v596; // [sp+58h] [bp-1C8h]
  unsigned __int64 v597; // [sp+58h] [bp-1C8h]
  unsigned __int64 v598; // [sp+58h] [bp-1C8h]
  unsigned __int64 v599; // [sp+58h] [bp-1C8h]
  unsigned __int64 v600; // [sp+58h] [bp-1C8h]
  unsigned __int64 v601; // [sp+58h] [bp-1C8h]
  unsigned __int64 v602; // [sp+58h] [bp-1C8h]
  __int64 v603; // [sp+60h] [bp-1C0h]
  unsigned __int64 v604; // [sp+60h] [bp-1C0h]
  unsigned __int64 v605; // [sp+60h] [bp-1C0h]
  unsigned __int64 v606; // [sp+60h] [bp-1C0h]
  __int64 v607; // [sp+60h] [bp-1C0h]
  __int64 v608; // [sp+60h] [bp-1C0h]
  __int64 v609; // [sp+60h] [bp-1C0h]
  __int64 v610; // [sp+60h] [bp-1C0h]
  __int64 v611; // [sp+60h] [bp-1C0h]
  __int64 v612; // [sp+60h] [bp-1C0h]
  __int64 v613; // [sp+60h] [bp-1C0h]
  __int64 v614; // [sp+60h] [bp-1C0h]
  unsigned __int64 v615; // [sp+60h] [bp-1C0h]
  unsigned __int64 v616; // [sp+60h] [bp-1C0h]
  unsigned __int64 v617; // [sp+60h] [bp-1C0h]
  unsigned __int64 v618; // [sp+60h] [bp-1C0h]
  unsigned __int64 v619; // [sp+60h] [bp-1C0h]
  unsigned __int64 v620; // [sp+60h] [bp-1C0h]
  unsigned __int64 v621; // [sp+60h] [bp-1C0h]
  unsigned __int64 v622; // [sp+60h] [bp-1C0h]
  unsigned __int64 v623; // [sp+60h] [bp-1C0h]
  __int64 v624; // [sp+60h] [bp-1C0h]
  __int64 v625; // [sp+60h] [bp-1C0h]
  __int64 v626; // [sp+60h] [bp-1C0h]
  __int64 v627; // [sp+60h] [bp-1C0h]
  __int64 v628; // [sp+60h] [bp-1C0h]
  unsigned __int64 v629; // [sp+60h] [bp-1C0h]
  unsigned __int64 v630; // [sp+60h] [bp-1C0h]
  unsigned __int64 v631; // [sp+60h] [bp-1C0h]
  __int64 v632; // [sp+60h] [bp-1C0h]
  __int64 v633; // [sp+60h] [bp-1C0h]
  unsigned __int64 v634; // [sp+68h] [bp-1B8h]
  __int64 v635; // [sp+68h] [bp-1B8h]
  unsigned __int64 v636; // [sp+68h] [bp-1B8h]
  unsigned __int64 v637; // [sp+68h] [bp-1B8h]
  __int64 v638; // [sp+68h] [bp-1B8h]
  unsigned __int64 v639; // [sp+68h] [bp-1B8h]
  unsigned __int64 v640; // [sp+68h] [bp-1B8h]
  __int64 v641; // [sp+68h] [bp-1B8h]
  __int64 v642; // [sp+68h] [bp-1B8h]
  unsigned __int64 v643; // [sp+68h] [bp-1B8h]
  __int64 v644; // [sp+68h] [bp-1B8h]
  __int64 v645; // [sp+68h] [bp-1B8h]
  __int64 v646; // [sp+68h] [bp-1B8h]
  __int64 v647; // [sp+68h] [bp-1B8h]
  __int64 v648; // [sp+68h] [bp-1B8h]
  __int64 v649; // [sp+68h] [bp-1B8h]
  __int64 v650; // [sp+68h] [bp-1B8h]
  __int64 v651; // [sp+68h] [bp-1B8h]
  __int64 v652; // [sp+68h] [bp-1B8h]
  __int64 v653; // [sp+68h] [bp-1B8h]
  __int64 v654; // [sp+68h] [bp-1B8h]
  unsigned __int64 v655; // [sp+68h] [bp-1B8h]
  unsigned __int64 v656; // [sp+68h] [bp-1B8h]
  unsigned __int64 v657; // [sp+68h] [bp-1B8h]
  unsigned __int64 v658; // [sp+68h] [bp-1B8h]
  unsigned __int64 v659; // [sp+68h] [bp-1B8h]
  __int64 v660; // [sp+68h] [bp-1B8h]
  __int64 v661; // [sp+68h] [bp-1B8h]
  __int64 v662; // [sp+68h] [bp-1B8h]
  __int64 v663; // [sp+68h] [bp-1B8h]
  unsigned __int64 v664; // [sp+70h] [bp-1B0h]
  __int64 v665; // [sp+70h] [bp-1B0h]
  unsigned __int64 v666; // [sp+70h] [bp-1B0h]
  __int64 v667; // [sp+70h] [bp-1B0h]
  __int64 v668; // [sp+70h] [bp-1B0h]
  __int64 v669; // [sp+70h] [bp-1B0h]
  __int64 v670; // [sp+70h] [bp-1B0h]
  __int64 v671; // [sp+70h] [bp-1B0h]
  __int64 v672; // [sp+70h] [bp-1B0h]
  __int64 v673; // [sp+70h] [bp-1B0h]
  __int64 v674; // [sp+70h] [bp-1B0h]
  __int64 v675; // [sp+70h] [bp-1B0h]
  __int64 v676; // [sp+70h] [bp-1B0h]
  __int64 v677; // [sp+70h] [bp-1B0h]
  __int64 v678; // [sp+70h] [bp-1B0h]
  __int64 v679; // [sp+70h] [bp-1B0h]
  unsigned __int64 v680; // [sp+70h] [bp-1B0h]
  unsigned __int64 v681; // [sp+70h] [bp-1B0h]
  __int64 v682; // [sp+70h] [bp-1B0h]
  __int64 v683; // [sp+70h] [bp-1B0h]
  __int64 v684; // [sp+70h] [bp-1B0h]
  __int64 v685; // [sp+70h] [bp-1B0h]
  unsigned __int64 v686; // [sp+70h] [bp-1B0h]
  unsigned __int64 v687; // [sp+70h] [bp-1B0h]
  unsigned __int64 v688; // [sp+70h] [bp-1B0h]
  unsigned __int64 v689; // [sp+70h] [bp-1B0h]
  unsigned __int64 v690; // [sp+70h] [bp-1B0h]
  unsigned __int64 v691; // [sp+78h] [bp-1A8h]
  unsigned __int64 v692; // [sp+78h] [bp-1A8h]
  __int64 v693; // [sp+78h] [bp-1A8h]
  __int64 v694; // [sp+78h] [bp-1A8h]
  __int64 v695; // [sp+78h] [bp-1A8h]
  __int64 v696; // [sp+78h] [bp-1A8h]
  __int64 v697; // [sp+78h] [bp-1A8h]
  __int64 v698; // [sp+78h] [bp-1A8h]
  __int64 v699; // [sp+78h] [bp-1A8h]
  __int64 v700; // [sp+78h] [bp-1A8h]
  __int64 v701; // [sp+78h] [bp-1A8h]
  __int64 v702; // [sp+78h] [bp-1A8h]
  __int64 v703; // [sp+78h] [bp-1A8h]
  unsigned __int64 v704; // [sp+78h] [bp-1A8h]
  __int64 v705; // [sp+78h] [bp-1A8h]
  unsigned __int64 v706; // [sp+78h] [bp-1A8h]
  __int64 v707; // [sp+78h] [bp-1A8h]
  __int64 v708; // [sp+78h] [bp-1A8h]
  __int64 v709; // [sp+78h] [bp-1A8h]
  __int64 v710; // [sp+78h] [bp-1A8h]
  __int64 v711; // [sp+78h] [bp-1A8h]
  __int64 v712; // [sp+78h] [bp-1A8h]
  __int64 v713; // [sp+78h] [bp-1A8h]
  __int64 v714; // [sp+78h] [bp-1A8h]
  __int64 v715; // [sp+78h] [bp-1A8h]
  __int64 v716; // [sp+78h] [bp-1A8h]
  unsigned __int64 v717; // [sp+78h] [bp-1A8h]
  __int64 v718; // [sp+78h] [bp-1A8h]
  unsigned __int64 v719; // [sp+80h] [bp-1A0h]
  unsigned __int64 v720; // [sp+80h] [bp-1A0h]
  __int64 v721; // [sp+80h] [bp-1A0h]
  unsigned __int64 v722; // [sp+80h] [bp-1A0h]
  unsigned __int64 v723; // [sp+80h] [bp-1A0h]
  __int64 v724; // [sp+80h] [bp-1A0h]
  __int64 v725; // [sp+80h] [bp-1A0h]
  __int64 v726; // [sp+80h] [bp-1A0h]
  unsigned __int64 v727; // [sp+80h] [bp-1A0h]
  __int64 v728; // [sp+80h] [bp-1A0h]
  __int64 v729; // [sp+80h] [bp-1A0h]
  __int64 v730; // [sp+80h] [bp-1A0h]
  __int64 v731; // [sp+80h] [bp-1A0h]
  unsigned __int64 v732; // [sp+80h] [bp-1A0h]
  unsigned __int64 v733; // [sp+80h] [bp-1A0h]
  __int64 v734; // [sp+80h] [bp-1A0h]
  unsigned __int64 v735; // [sp+80h] [bp-1A0h]
  __int64 v736; // [sp+80h] [bp-1A0h]
  __int64 v737; // [sp+80h] [bp-1A0h]
  __int64 v738; // [sp+80h] [bp-1A0h]
  unsigned __int64 v739; // [sp+88h] [bp-198h]
  unsigned __int64 v740; // [sp+88h] [bp-198h]
  unsigned __int64 v741; // [sp+88h] [bp-198h]
  unsigned __int64 v742; // [sp+88h] [bp-198h]
  unsigned __int64 v743; // [sp+88h] [bp-198h]
  unsigned __int64 v744; // [sp+88h] [bp-198h]
  unsigned __int64 v745; // [sp+90h] [bp-190h]
  unsigned __int64 v746; // [sp+90h] [bp-190h]
  __int64 v747; // [sp+98h] [bp-188h]
  unsigned __int64 v748; // [sp+98h] [bp-188h]
  __int64 v749; // [sp+A0h] [bp-180h]
  __int64 v750; // [sp+A0h] [bp-180h]
  __int64 v751; // [sp+A0h] [bp-180h]
  unsigned __int64 v752; // [sp+A0h] [bp-180h]
  __int64 v753; // [sp+A0h] [bp-180h]
  __int64 v754; // [sp+A0h] [bp-180h]
  __int64 v755; // [sp+A0h] [bp-180h]
  __int64 v756; // [sp+A0h] [bp-180h]
  __int64 v757; // [sp+A0h] [bp-180h]
  __int64 v758; // [sp+A0h] [bp-180h]
  unsigned __int64 v759; // [sp+A0h] [bp-180h]
  __int64 v760; // [sp+A0h] [bp-180h]
  __int64 v761; // [sp+A0h] [bp-180h]
  __int64 v762; // [sp+A8h] [bp-178h]
  unsigned __int64 v763; // [sp+B0h] [bp-170h]
  unsigned __int64 v764; // [sp+B0h] [bp-170h]
  unsigned __int64 v765; // [sp+B8h] [bp-168h]
  unsigned __int64 v766; // [sp+B8h] [bp-168h]
  unsigned __int64 v767; // [sp+C0h] [bp-160h]
  __int64 v768; // [sp+C8h] [bp-158h]
  __int64 v769; // [sp+D0h] [bp-150h]
  unsigned __int64 v770; // [sp+D0h] [bp-150h]
  unsigned __int64 v771; // [sp+D0h] [bp-150h]
  unsigned __int64 v772; // [sp+D8h] [bp-148h]
  unsigned __int64 v773; // [sp+E0h] [bp-140h]
  unsigned __int64 v774; // [sp+E0h] [bp-140h]
  __int64 v775; // [sp+E8h] [bp-138h]
  unsigned __int64 v776; // [sp+F0h] [bp-130h]
  __int64 v777; // [sp+F8h] [bp-128h]
  __int64 v778; // [sp+F8h] [bp-128h]
  __int64 v779; // [sp+F8h] [bp-128h]
  __int64 v780; // [sp+F8h] [bp-128h]
  __int64 v781; // [sp+F8h] [bp-128h]
  __int64 v782; // [sp+F8h] [bp-128h]
  unsigned __int64 v783; // [sp+F8h] [bp-128h]
  unsigned __int64 v784; // [sp+F8h] [bp-128h]
  __int64 v785; // [sp+F8h] [bp-128h]
  __int64 v786; // [sp+F8h] [bp-128h]
  __int64 v787; // [sp+108h] [bp-118h]
  __int64 v789; // [sp+118h] [bp-108h] BYREF
  __int64 v790; // [sp+120h] [bp-100h]
  __int64 v791; // [sp+128h] [bp-F8h]
  __int64 v792; // [sp+130h] [bp-F0h]
  __int64 v793; // [sp+138h] [bp-E8h]
  __int64 v794; // [sp+140h] [bp-E0h]
  __int64 v795; // [sp+148h] [bp-D8h]
  __int64 v796; // [sp+150h] [bp-D0h]
  __int64 v797; // [sp+158h] [bp-C8h]
  __int64 v798; // [sp+160h] [bp-C0h]
  __int64 v799; // [sp+168h] [bp-B8h]
  __int64 v800; // [sp+170h] [bp-B0h]
  __int64 v801; // [sp+178h] [bp-A8h]
  __int64 v802; // [sp+180h] [bp-A0h]
  __int64 v803; // [sp+188h] [bp-98h]
  __int64 v804; // [sp+190h] [bp-90h]
  __int64 v805; // [sp+198h] [bp-88h] BYREF
  __int64 v806; // [sp+1A0h] [bp-80h] BYREF
  unsigned __int64 v807; // [sp+1A8h] [bp-78h]
  unsigned __int64 v808; // [sp+1B0h] [bp-70h]
  __int64 v809; // [sp+1B8h] [bp-68h]
  __int64 v810; // [sp+1C0h] [bp-60h]
  __int64 v811; // [sp+1C8h] [bp-58h]
  __int64 v812; // [sp+1D0h] [bp-50h]
  __int64 v813; // [sp+1D8h] [bp-48h] BYREF
  _QWORD v814[8]; // [sp+1E0h] [bp-40h] BYREF

  v2 = &v789;
  v3 = a2 + 128;
  do
  {
    v4 = a2[7];
    v5 = a2[6];
    v6 = vshld_n_s64(a2[5], 0x28u)
       | vshld_n_s64(a2[4], 0x20u)
       | vshld_n_s64(a2[3], 0x18u)
       | *a2
       | vshld_n_s64(a2[2], 0x10u)
       | vshld_n_s64(a2[1], 8u);
    a2 += 8;
    v2[1] = vshld_n_s64(v4, 0x38u) | vshld_n_s64(v5, 0x30u) | v6;
    ++v2;
  }
  while ( a2 != v3 );
  v7 = a1 - 8;
  v8 = &v805;
  do
  {
    v9 = *(_QWORD *)(v7 + 8);
    v7 += 8;
    v8[1] = v9;
    ++v8;
  }
  while ( v8 != &v813 );
  v10 = v807 + v811 + v792;
  v11 = __PAIR64__(
          *(_DWORD *)(a1 + 72) ^ 0x2B3E6C1F ^ (unsigned int)v10,
          (*(_QWORD *)(a1 + 72) ^ 0x9B05688C2B3E6C1FLL ^ v10) >> 32);
  v12 = __PAIR64__(
          *(_DWORD *)(a1 + 72) ^ 0x2B3E6C1F ^ (unsigned int)v10,
          (*(_QWORD *)(a1 + 72) ^ 0x9B05688C2B3E6C1FLL ^ v10) >> 32)
      - 0x4498517A7B3558C5LL;
  v13 = (__int64)((__PAIR64__(
                     *(_DWORD *)(a1 + 72) ^ 0x2B3E6C1F ^ (unsigned int)v10,
                     (*(_QWORD *)(a1 + 72) ^ 0x9B05688C2B3E6C1FLL ^ v10) >> 32)
                 - 0x4498517A7B3558C5LL)
                ^ v811) >> 24;
  v14 = ((unsigned int)((v12 ^ v811) >> 32) >> 24) | (((unsigned int)v12 ^ (unsigned int)v811) << 8);
  v461 = v10 + v793 + __PAIR64__(v14, v13);
  v15 = *(_QWORD *)(a1 + 80) ^ 0x1F83D9ABFB41BD6BLL;
  v16 = *(_QWORD *)(a1 + 64) ^ 0x510E527FADE682D1LL ^ (v806 + v810 + v790);
  HIDWORD(v739) = *(_DWORD *)(a1 + 88) ^ 0x137E2179 ^ (v809 + v813 + v796);
  LODWORD(v739) = (*(_QWORD *)(a1 + 88) ^ 0x5BE0CD19137E2179LL ^ (unsigned __int64)(v809 + v813 + v796)) >> 32;
  v719 = __PAIR64__(v15 ^ (v812 + v808 + v794), (v15 ^ (v812 + v808 + v794)) >> 32);
  v17 = v11 ^ v461;
  LODWORD(v375) = v17 >> 16;
  v361 = __PAIR64__(v15 ^ (v812 + v808 + v794), (v15 ^ (v812 + v808 + v794)) >> 32) + 0x3C6EF372FE94F82BLL;
  HIDWORD(v375) = HIWORD(HIDWORD(v17)) | ((_DWORD)v17 << 16);
  v18 = (v739 - 0x5AB00AC5A0E2C90FLL) ^ v813;
  LODWORD(v389) = ((((_DWORD)v739 + 1595750129) ^ (unsigned int)v813) >> 24) | (HIDWORD(v18) << 8);
  HIDWORD(v389) = HIBYTE(HIDWORD(v18)) | ((((_DWORD)v739 + 1595750129) ^ (unsigned int)v813) << 8);
  LODWORD(v762) = (__int64)(v361 ^ v812) >> 24;
  LODWORD(v769) = (__int64)((__PAIR64__(v16, HIDWORD(v16)) + 0x6A09E667F3BCC908LL) ^ v810) >> 24;
  HIDWORD(v769) = ((unsigned int)(((__PAIR64__(v16, HIDWORD(v16)) + 0x6A09E667F3BCC908LL) ^ v810) >> 32) >> 24)
                | (((HIDWORD(v16) - 205731576) ^ (unsigned int)v810) << 8);
  v572 = v375 + v12;
  v19 = (v375 + v12) ^ __PAIR64__(v14, v13);
  HIDWORD(v762) = ((unsigned int)((v361 ^ v812) >> 32) >> 24) | (((unsigned int)v361 ^ (unsigned int)v812) << 8);
  HIDWORD(v773) = v19 >> 31;
  v603 = v809 + v813 + v796 + v797 + v389;
  LODWORD(v773) = (2 * v19) | (HIDWORD(v19) >> 31);
  v478 = v806 + v810 + v790 + v791 + v769;
  v510 = v812 + v808 + v794 + v795 + v762;
  LODWORD(v691) = (__int64)(v603 ^ v739) >> 16;
  HIDWORD(v691) = ((unsigned int)((v603 ^ v739) >> 32) >> 16) | (((unsigned int)v603 ^ (unsigned int)v739) << 16);
  LODWORD(v406) = (__int64)(v510 ^ v719) >> 16;
  HIDWORD(v406) = ((unsigned int)((v510 ^ v719) >> 32) >> 16) | (((unsigned int)v510 ^ (unsigned int)v719) << 16);
  HIDWORD(v20) = (v478 + v798 + v773) ^ v691;
  LODWORD(v20) = ((v478 + v798 + v773) ^ v691) >> 32;
  v21 = (v406 + v361) ^ v762;
  v539 = v20 + v406 + v361;
  LODWORD(v17) = (__int64)(v478 ^ __PAIR64__(v16, HIDWORD(v16))) >> 16;
  HIDWORD(v17) = ((HIDWORD(v478) ^ (unsigned int)v16) >> 16) | (((unsigned int)v478 ^ HIDWORD(v16)) << 16);
  LODWORD(v343) = (__int64)(v539 ^ v773) >> 24;
  HIDWORD(v343) = ((unsigned int)((v539 ^ v773) >> 32) >> 24) | (((unsigned int)v539 ^ (unsigned int)v773) << 8);
  HIDWORD(v361) = v21 >> 31;
  LODWORD(v361) = (2 * v21) | (HIDWORD(v21) >> 31);
  v634 = v478 + v798 + v773 + v799 + v343;
  v479 = v17 + __PAIR64__(v16, HIDWORD(v16)) + 0x6A09E667F3BCC908LL;
  v664 = v461 + v800 + v361;
  LODWORD(v461) = (__int64)(v634 ^ v20) >> 16;
  v22 = v691 + v739 - 0x5AB00AC5A0E2C90FLL;
  v434 = __PAIR64__((unsigned int)v17 ^ (unsigned int)v664, (v17 ^ v664) >> 32);
  v692 = __PAIR64__((unsigned int)v17 ^ (unsigned int)v664, (v17 ^ v664) >> 32) + v22;
  v23 = v22 ^ v389;
  HIDWORD(v461) = ((unsigned int)((v634 ^ v20) >> 32) >> 16) | (((unsigned int)v634 ^ (unsigned int)v20) << 16);
  LODWORD(v389) = (2 * (v479 ^ v769)) | ((unsigned int)((v479 ^ v769) >> 32) >> 31);
  v540 = v461 + v539;
  LODWORD(v420) = (2 * v23) | (HIDWORD(v23) >> 31);
  HIDWORD(v420) = v23 >> 31;
  v665 = v664 + v801;
  HIDWORD(v389) = (__int64)(v479 ^ v769) >> 31;
  v24 = v692 ^ v361;
  v25 = v603 + v804 + v389;
  v362 = __PAIR64__((unsigned int)v25 ^ (unsigned int)v406, (v25 ^ v406) >> 32);
  v407 = v25 + v805;
  v749 = v510 + v802 + v420 + v803;
  v26 = (v510 + v802 + v420) ^ v375;
  v635 = v634 + v804;
  v376 = (2 * (v540 ^ v343)) | ((unsigned int)((v540 ^ v343) >> 32) >> 31);
  v27 = (v362 + v572) ^ v389;
  v390 = __PAIR64__(HIBYTE(HIDWORD(v24)) | ((_DWORD)v24 << 8), v24 >> 24);
  LODWORD(v343) = v27 >> 24;
  HIDWORD(v343) = HIBYTE(HIDWORD(v27)) | ((_DWORD)v27 << 8);
  v604 = v25 + v805 + v343;
  v28 = (v665 + __PAIR64__(HIBYTE(HIDWORD(v24)) | ((_DWORD)v24 << 8), v24 >> 24)) ^ v434;
  v29 = __PAIR64__(v26, HIDWORD(v26));
  v30 = (v407 + v343) ^ v362;
  LODWORD(v407) = v28 >> 16;
  v480 = __PAIR64__(v26, HIDWORD(v26)) + v479;
  HIDWORD(v407) = HIWORD(HIDWORD(v28)) | ((_DWORD)v28 << 16);
  LODWORD(v434) = v30 >> 16;
  v720 = v665 + v390 + v794 + v376;
  HIDWORD(v434) = HIWORD(HIDWORD(v30)) | ((_DWORD)v30 << 16);
  v31 = v362 + v572;
  v573 = v407 + v692;
  LODWORD(v26) = (__int64)(v480 ^ v420) >> 24;
  HIDWORD(v26) = ((unsigned int)((v480 ^ v420) >> 32) >> 24) | (((unsigned int)v480 ^ (unsigned int)v420) << 8);
  v32 = (v407 + v692) ^ v390;
  v33 = (v434 + v31) ^ v343;
  LODWORD(v362) = (2 * v32) | (HIDWORD(v32) >> 31);
  HIDWORD(v362) = v32 >> 31;
  LODWORD(v420) = (2 * v33) | (HIDWORD(v33) >> 31);
  v34 = (v749 + v26) ^ v29;
  HIDWORD(v420) = v33 >> 31;
  LODWORD(v32) = v34 >> 16;
  HIDWORD(v32) = HIWORD(HIDWORD(v34)) | ((_DWORD)v34 << 16);
  v391 = v635 + v420;
  v740 = (v749 + v26 + v799 + v362) ^ v434;
  v344 = __PAIR64__((unsigned int)v720 ^ (unsigned int)v32, (v720 ^ v32) >> 32);
  v408 = __PAIR64__((v635 + v420) ^ v407, ((v635 + v420) ^ v407) >> 32);
  v481 = v32 + v480;
  v636 = __PAIR64__((unsigned int)v720 ^ (unsigned int)v32, (v720 ^ v32) >> 32) + v434 + v31;
  HIDWORD(v29) = (v749 + v26 + v799 + v362) ^ v434;
  v750 = v749 + v26 + v799 + v362 + v805;
  v693 = v391 + v800;
  v435 = __PAIR64__(HIDWORD(v29), HIDWORD(v740));
  v666 = __PAIR64__(HIDWORD(v29), HIDWORD(v740)) + v540;
  v35 = v481 ^ v26;
  v511 = v408 + v481;
  v36 = (v408 + v481) ^ v420;
  LODWORD(v31) = (__int64)(v636 ^ v376) >> 24;
  HIDWORD(v31) = ((unsigned int)((v636 ^ v376) >> 32) >> 24) | (((unsigned int)v636 ^ (unsigned int)v376) << 8);
  LODWORD(v391) = (2 * (v481 ^ v26)) | ((unsigned int)((v481 ^ v26) >> 32) >> 31);
  LODWORD(v26) = v36 >> 24;
  v721 = v720 + v798 + v31;
  HIDWORD(v391) = v35 >> 31;
  v482 = __PAIR64__(
           ((unsigned int)(((v435 + v540) ^ v362) >> 32) >> 24)
         | (((HIDWORD(v740) + (_DWORD)v540) ^ (unsigned int)v362) << 8),
           (__int64)((v435 + v540) ^ v362) >> 24);
  HIDWORD(v26) = HIBYTE(HIDWORD(v36)) | ((_DWORD)v36 << 8);
  v37 = __PAIR64__(
          ((unsigned int)(((v435 + v540) ^ v362) >> 32) >> 24)
        | (((HIDWORD(v740) + (_DWORD)v540) ^ (unsigned int)v362) << 8),
          (__int64)((v435 + v540) ^ v362) >> 24);
  v541 = v693 + v26;
  v694 = v750 + v37;
  LODWORD(v420) = (__int64)(v721 ^ v344) >> 16;
  HIDWORD(v420) = ((unsigned int)((v721 ^ v344) >> 32) >> 16) | (((unsigned int)v721 ^ (unsigned int)v344) << 16);
  v38 = (v750 + v37) ^ v435;
  LODWORD(v376) = (__int64)(v541 ^ v408) >> 16;
  HIDWORD(v376) = ((unsigned int)((v541 ^ v408) >> 32) >> 16) | (((unsigned int)v541 ^ (unsigned int)v408) << 16);
  v436 = v420 + v636;
  v39 = (v420 + v636) ^ v31;
  v345 = __PAIR64__(HIWORD(HIDWORD(v38)) | ((_DWORD)v38 << 16), v38 >> 16);
  v512 = v376 + v511;
  v637 = __PAIR64__(HIWORD(HIDWORD(v38)) | ((_DWORD)v38 << 16), v38 >> 16) + v666;
  LODWORD(v362) = (2 * v39) | (HIDWORD(v39) >> 31);
  v40 = v604 + v803 + v391;
  v41 = (__PAIR64__(HIWORD(HIDWORD(v38)) | ((_DWORD)v38 << 16), v38 >> 16) + v666) ^ v482;
  HIDWORD(v362) = v39 >> 31;
  LODWORD(v408) = (2 * (v512 ^ v26)) | ((unsigned int)((v512 ^ v26) >> 32) >> 31);
  HIDWORD(v38) = (__int64)(v512 ^ v26) >> 31;
  LODWORD(v26) = (v40 ^ v461) >> 32;
  HIDWORD(v26) = v40 ^ v461;
  v483 = v26 + v573;
  HIDWORD(v408) = HIDWORD(v38);
  v42 = (v26 + v573) ^ v391;
  LODWORD(v391) = v42 >> 24;
  HIDWORD(v391) = HIBYTE(HIDWORD(v42)) | ((_DWORD)v42 << 8);
  HIDWORD(v461) = v41 >> 31;
  LODWORD(v461) = (2 * v41) | (HIDWORD(v41) >> 31);
  v542 = v541 + v791 + v362;
  v43 = v40 + v796 + v391;
  v44 = v721 + v790 + v461;
  v45 = v43 + v795;
  v46 = v43 ^ v26;
  v47 = v44 ^ v376;
  v48 = v45 + v408;
  v777 = v44 + v792;
  LODWORD(v38) = v46 >> 16;
  HIDWORD(v38) = HIWORD(HIDWORD(v46)) | ((_DWORD)v46 << 16);
  v49 = v345;
  v346 = v542 ^ v38;
  LODWORD(v46) = (v48 ^ v49) >> 32;
  v484 = v38 + v483;
  HIDWORD(v46) = v48 ^ v49;
  v667 = v46 + v436;
  v751 = v542 + v802;
  v377 = (2 * (v484 ^ v391)) | ((unsigned int)((v484 ^ v391) >> 32) >> 31);
  v50 = (v46 + v436) ^ v408;
  v51 = v694 + v801 + v377;
  LODWORD(v436) = v50 >> 24;
  HIDWORD(v436) = HIBYTE(HIDWORD(v50)) | ((_DWORD)v50 << 8);
  v695 = v48 + v793 + v436;
  v52 = v51 ^ v420;
  v574 = __PAIR64__(v346, HIDWORD(v346)) + v637;
  v53 = v695 ^ v46;
  v605 = __PAIR64__(v47, HIDWORD(v47)) + v484;
  v54 = (__PAIR64__(v346, HIDWORD(v346)) + v637) ^ v362;
  v421 = __PAIR64__(HIWORD(HIDWORD(v53)) | ((_DWORD)v53 << 16), v53 >> 16);
  v55 = (__PAIR64__(v47, HIDWORD(v47)) + v484) ^ v461;
  v485 = v51 + v797;
  v363 = __PAIR64__(v52, HIDWORD(v52));
  v543 = __PAIR64__(v52, HIDWORD(v52)) + v512;
  LODWORD(v408) = v54 >> 24;
  v668 = __PAIR64__(HIWORD(HIDWORD(v53)) | ((_DWORD)v53 << 16), v53 >> 16) + v667;
  v56 = (__PAIR64__(v52, HIDWORD(v52)) + v512) ^ v377;
  v722 = __PAIR64__(HIBYTE(HIDWORD(v55)) | ((_DWORD)v55 << 8), v55 >> 24);
  v57 = v668 ^ v436;
  HIDWORD(v408) = HIBYTE(HIDWORD(v54)) | ((_DWORD)v54 << 8);
  LODWORD(v461) = (2 * v57) | (HIDWORD(v57) >> 31);
  v437 = v777 + __PAIR64__(HIBYTE(HIDWORD(v55)) | ((_DWORD)v55 << 8), v55 >> 24);
  v58 = (v751 + v408) ^ __PAIR64__(v346, HIDWORD(v346));
  HIDWORD(v461) = v57 >> 31;
  LODWORD(v51) = v56 >> 24;
  HIDWORD(v51) = HIBYTE(HIDWORD(v56)) | ((_DWORD)v56 << 8);
  LODWORD(v391) = v58 >> 16;
  v638 = v485 + v51;
  HIDWORD(v391) = HIWORD(HIDWORD(v58)) | ((_DWORD)v58 << 16);
  LODWORD(v56) = (__int64)(v437 ^ __PAIR64__(v47, HIDWORD(v47))) >> 16;
  v752 = v751 + v408 + v801 + v461;
  HIDWORD(v56) = ((unsigned int)((v437 ^ __PAIR64__(v47, HIDWORD(v47))) >> 32) >> 16)
               | (((unsigned int)v437 ^ HIDWORD(v47)) << 16);
  v486 = v391 + v574;
  v59 = (v391 + v574) ^ v408;
  v513 = v56 + v605;
  v364 = __PAIR64__(
           ((unsigned int)((v638 ^ v363) >> 32) >> 16) | (((unsigned int)v638 ^ (unsigned int)v363) << 16),
           (__int64)(v638 ^ v363) >> 16);
  LODWORD(v377) = (2 * v59) | (HIDWORD(v59) >> 31);
  HIDWORD(v377) = v59 >> 31;
  v347 = __PAIR64__((unsigned int)v56 ^ (unsigned int)v752, (v56 ^ v752) >> 32);
  LODWORD(v408) = (2 * (v513 ^ v722)) | ((unsigned int)((v513 ^ v722) >> 32) >> 31);
  v60 = v51 ^ (v364 + v543);
  HIDWORD(v408) = (__int64)((v56 + v605) ^ v722) >> 31;
  v606 = __PAIR64__((unsigned int)v56 ^ (unsigned int)v752, (v56 ^ v752) >> 32) + v364 + v543;
  v575 = v752 + v798;
  v61 = v437 + v802 + v377;
  v62 = v606 ^ v461;
  v63 = (__int64)(v606 ^ v461) >> 24;
  v778 = v695 + v805;
  v462 = __PAIR64__((unsigned int)v61 ^ (unsigned int)v364, (v61 ^ v364) >> 32);
  v696 = v61 + v790;
  v438 = __PAIR64__((v638 + v795 + v408) ^ v421, ((v638 + v795 + v408) ^ v421) >> 32);
  v753 = v638 + v795 + v408 + v792;
  v64 = __PAIR64__((v638 + v795 + v408) ^ v421, ((v638 + v795 + v408) ^ v421) >> 32);
  LODWORD(v421) = v63;
  v639 = v64 + v486;
  HIDWORD(v421) = HIBYTE(HIDWORD(v62)) | ((_DWORD)v62 << 8);
  v544 = __PAIR64__((unsigned int)v61 ^ (unsigned int)v364, (v61 ^ v364) >> 32) + v668;
  v65 = (__PAIR64__((unsigned int)v61 ^ (unsigned int)v364, (v61 ^ v364) >> 32) + v668) ^ v377;
  v365 = (2 * v60) | (HIDWORD(v60) >> 31);
  v66 = (v64 + v486) ^ v408;
  v67 = v778 + v365;
  v779 = v778 + v365 + v803;
  LODWORD(v60) = v65 >> 24;
  v68 = (v575 + v421) ^ v347;
  HIDWORD(v60) = HIBYTE(HIDWORD(v65)) | ((_DWORD)v65 << 8);
  v409 = v67 ^ v391;
  HIDWORD(v486) = HIBYTE(HIDWORD(v66)) | ((_DWORD)v66 << 8);
  LODWORD(v486) = v66 >> 24;
  v789 = v575 + v421 + v800;
  v669 = v753 + v486;
  v69 = (v696 + v60) ^ v462;
  v70 = (v753 + v486) ^ v438;
  HIDWORD(v391) = HIWORD(HIDWORD(v68)) | ((_DWORD)v68 << 16);
  v697 = v696 + v60 + v793;
  LODWORD(v391) = v68 >> 16;
  v576 = __PAIR64__(v409, HIDWORD(v409));
  v71 = __PAIR64__(v409, HIDWORD(v409));
  v410 = __PAIR64__(HIWORD(HIDWORD(v69)) | ((_DWORD)v69 << 16), v69 >> 16);
  v439 = v71 + v513;
  v72 = (v71 + v513) ^ v365;
  HIDWORD(v347) = HIWORD(HIDWORD(v70)) | ((_DWORD)v70 << 16);
  LODWORD(v347) = v70 >> 16;
  v514 = v391 + v606;
  v607 = __PAIR64__(HIWORD(HIDWORD(v69)) | ((_DWORD)v69 << 16), v69 >> 16) + v544;
  LODWORD(v462) = v72 >> 24;
  LODWORD(v377) = (2 * (v514 ^ v63)) | ((unsigned int)((v514 ^ v421) >> 32) >> 31);
  v73 = (__PAIR64__(HIWORD(HIDWORD(v69)) | ((_DWORD)v69 << 16), v69 >> 16) + v544) ^ v60;
  HIDWORD(v462) = HIBYTE(HIDWORD(v72)) | ((_DWORD)v72 << 8);
  v74 = (v347 + v639) ^ v486;
  LODWORD(v365) = (2 * (((v69 >> 16) + v544) ^ v60)) | (HIDWORD(v73) >> 31);
  HIDWORD(v365) = v73 >> 31;
  v75 = (v779 + v462) ^ v576;
  HIDWORD(v377) = (__int64)(v514 ^ v421) >> 31;
  LODWORD(v60) = (2 * v74) | (HIDWORD(v74) >> 31);
  HIDWORD(v60) = v74 >> 31;
  LODWORD(v73) = v75 >> 16;
  HIDWORD(v73) = HIWORD(HIDWORD(v75)) | ((_DWORD)v75 << 16);
  v577 = v73 + v439;
  v76 = (v697 + v60) ^ v391;
  v422 = __PAIR64__((v789 + v365) ^ v73, ((v789 + v365) ^ (unsigned __int64)v73) >> 32);
  v698 = v697 + v60 + v796;
  v77 = (v73 + v439) ^ v462;
  v440 = __PAIR64__(v76, HIDWORD(v76));
  v78 = __PAIR64__((v789 + v365) ^ v73, ((v789 + v365) ^ (unsigned __int64)v73) >> 32) + v347 + v639;
  LODWORD(v391) = (2 * v77) | (HIDWORD(v77) >> 31);
  v578 = __PAIR64__(v76, HIDWORD(v76)) + v577;
  HIDWORD(v77) = v77 >> 31;
  v79 = v578 ^ v60;
  LODWORD(v77) = (__int64)(v78 ^ v365) >> 24;
  HIDWORD(v391) = HIDWORD(v77);
  HIDWORD(v77) = ((unsigned int)((v78 ^ v365) >> 32) >> 24) | (((unsigned int)v78 ^ (unsigned int)v365) << 8);
  LODWORD(v60) = (__int64)(v578 ^ v60) >> 24;
  HIDWORD(v60) = HIBYTE(HIDWORD(v79)) | ((_DWORD)v79 << 8);
  v545 = v789 + v365 + v804 + v77;
  v723 = v698 + v60;
  v80 = (v698 + v60) ^ v440;
  HIDWORD(v365) = ((unsigned int)(HIDWORD(v545) ^ HIDWORD(v422)) >> 16)
                | (((unsigned int)v545 ^ (unsigned int)v422) << 16);
  LODWORD(v365) = (__int64)(v545 ^ v422) >> 16;
  LODWORD(v486) = v80 >> 16;
  HIDWORD(v486) = HIWORD(HIDWORD(v80)) | ((_DWORD)v80 << 16);
  v441 = v365 + v78;
  v579 = v486 + v578;
  v81 = v77 ^ (v365 + v78);
  v82 = v669 + v797 + v391;
  v83 = v779 + v462 + v799 + v377;
  LODWORD(v422) = (2 * v81) | (HIDWORD(v81) >> 31);
  HIDWORD(v422) = v81 >> 31;
  v640 = v82 ^ v410;
  v84 = (2 * (v579 ^ v60)) | ((unsigned int)((v579 ^ v60) >> 32) >> 31);
  HIDWORD(v410) = (__int64)(v579 ^ v60) >> 31;
  v463 = __PAIR64__((unsigned int)v83 ^ (unsigned int)v347, (v83 ^ v347) >> 32);
  v670 = v82 + v791;
  v608 = __PAIR64__((unsigned int)v83 ^ (unsigned int)v347, (v83 ^ v347) >> 32) + v607;
  v754 = v545 + v797;
  LODWORD(v82) = (v608 ^ v377) >> 24;
  v780 = v698 + v60 + v793 + v422 + v791;
  HIDWORD(v82) = ((unsigned int)((v608 ^ (unsigned __int64)v377) >> 32) >> 24)
               | (((unsigned int)v608 ^ (unsigned int)v377) << 8);
  v85 = v83 + v794 + v82;
  v348 = __PAIR64__(v640, HIDWORD(v640)) + v514;
  LODWORD(v410) = v84;
  v86 = v85 + v801;
  v87 = v85 ^ v463;
  v699 = v86;
  LODWORD(v83) = v87 >> 16;
  HIDWORD(v83) = HIWORD(HIDWORD(v87)) | ((_DWORD)v87 << 16);
  v88 = (__PAIR64__(v640, HIDWORD(v640)) + v514) ^ v391;
  v515 = v83 + v608;
  LODWORD(v87) = v88 >> 24;
  HIDWORD(v87) = HIBYTE(HIDWORD(v88)) | ((_DWORD)v88 << 8);
  v89 = (v83 + v608) ^ v82;
  LODWORD(v391) = (2 * v89) | (HIDWORD(v89) >> 31);
  HIDWORD(v391) = v89 >> 31;
  v90 = (v670 + v87) ^ __PAIR64__(v640, HIDWORD(v640));
  LODWORD(v89) = v90 >> 16;
  HIDWORD(v89) = HIWORD(HIDWORD(v90)) | ((_DWORD)v90 << 16);
  LODWORD(v377) = ((v545 + v797 + v391) ^ v486) >> 32;
  v91 = (v670 + v87 + v803 + v410) ^ v83;
  HIDWORD(v377) = (v545 + v797 + v391) ^ v486;
  v487 = v377 + v89 + v348;
  v92 = (v89 + v348) ^ v87;
  v464 = __PAIR64__(v89 ^ (v723 + v793 + v422), (v89 ^ (v723 + v793 + v422)) >> 32);
  v641 = v670 + v87 + v803 + v410 + v802;
  v609 = __PAIR64__(v89 ^ (v723 + v793 + v422), (v89 ^ (v723 + v793 + v422)) >> 32) + v515;
  v741 = __PAIR64__(v91, HIDWORD(v91));
  LODWORD(v348) = (__int64)(v487 ^ v391) >> 24;
  v93 = __PAIR64__(v91, HIDWORD(v91)) + v441;
  HIDWORD(v348) = ((unsigned int)((v487 ^ v391) >> 32) >> 24) | (((unsigned int)v487 ^ (unsigned int)v391) << 8);
  v94 = (__PAIR64__(v89 ^ (v723 + v793 + v422), (v89 ^ (v723 + v793 + v422)) >> 32) + v515) ^ v422;
  v546 = v93;
  LODWORD(v87) = (2 * v92) | (HIDWORD(v92) >> 31);
  HIDWORD(v87) = v92 >> 31;
  v95 = v93 ^ v410;
  LODWORD(v723) = v94 >> 24;
  v671 = v699 + v87;
  v96 = (__int64)(v93 ^ v410) >> 24;
  v516 = v754 + v391 + v799 + v348;
  HIDWORD(v723) = HIBYTE(HIDWORD(v94)) | ((_DWORD)v94 << 8);
  v423 = __PAIR64__(HIBYTE(HIDWORD(v95)) | ((_DWORD)v95 << 8), v96);
  v392 = __PAIR64__(
           ((unsigned int)((v516 ^ v377) >> 32) >> 16)
         | ((((_DWORD)v754 + (_DWORD)v391 + (_DWORD)v799 + (_DWORD)v348) ^ (unsigned int)v377) << 16),
           (__int64)(v516 ^ v377) >> 16);
  v642 = v641 + __PAIR64__(HIBYTE(HIDWORD(v95)) | ((_DWORD)v95 << 8), v96);
  v366 = __PAIR64__((v699 + v87) ^ v365, ((v699 + v87) ^ (unsigned __int64)v365) >> 32);
  v97 = (v780 + v723) ^ v464;
  v700 = v366 + v579;
  v580 = v392 + v487;
  v98 = (v392 + v487) ^ v348;
  LODWORD(v410) = v97 >> 16;
  v99 = v700 ^ v87;
  LODWORD(v87) = (__int64)(v642 ^ v741) >> 16;
  LODWORD(v377) = (2 * v98) | (HIDWORD(v98) >> 31);
  HIDWORD(v377) = v98 >> 31;
  HIDWORD(v87) = ((unsigned int)((v642 ^ v741) >> 32) >> 16) | (((unsigned int)v642 ^ (unsigned int)v741) << 16);
  HIDWORD(v410) = HIWORD(HIDWORD(v97)) | ((_DWORD)v97 << 16);
  LODWORD(v464) = v99 >> 24;
  HIDWORD(v464) = HIBYTE(HIDWORD(v99)) | ((_DWORD)v99 << 8);
  v610 = v410 + v609;
  v547 = v87 + v546;
  v100 = v671 + v804 + v464;
  v101 = v547 ^ v423;
  v755 = v780 + v723 + v795;
  LODWORD(v348) = (2 * (v547 ^ v423)) | ((unsigned int)((v547 ^ v423) >> 32) >> 31);
  v102 = v100 + v805;
  v103 = v100 ^ v366;
  v104 = v102 + v377;
  LODWORD(v423) = v103 >> 16;
  HIDWORD(v423) = HIWORD(HIDWORD(v103)) | ((_DWORD)v103 << 16);
  LODWORD(v366) = (2 * (v610 ^ v723)) | ((unsigned int)((v610 ^ v723) >> 32) >> 31);
  HIDWORD(v348) = v101 >> 31;
  v488 = __PAIR64__((unsigned int)v104 ^ (unsigned int)v87, HIDWORD(v104) ^ HIDWORD(v87));
  HIDWORD(v366) = (__int64)(v610 ^ v723) >> 31;
  v672 = v423 + v700;
  v724 = v516 + v792;
  v105 = v423 + v700;
  v701 = __PAIR64__((unsigned int)v104 ^ (unsigned int)v87, HIDWORD(v104) ^ HIDWORD(v87)) + v610;
  v517 = v755 + v348;
  v442 = (2 * (v105 ^ v464)) | ((unsigned int)((v105 ^ v464) >> 32) >> 31);
  v106 = (__PAIR64__((unsigned int)v104 ^ (unsigned int)v87, HIDWORD(v104) ^ HIDWORD(v87)) + v610) ^ v377;
  v378 = v104 + v798;
  v611 = v642 + v794 + v442;
  LODWORD(v105) = v106 >> 24;
  v107 = (v755 + v348) ^ v392;
  HIDWORD(v105) = HIBYTE(HIDWORD(v106)) | ((_DWORD)v106 << 8);
  v756 = v378 + v105;
  v393 = (v724 + v366) ^ v423;
  v108 = v611 ^ v410;
  v109 = v378 + v105;
  v379 = v517 + v800;
  v110 = v109 ^ v488;
  v411 = __PAIR64__(v107, HIDWORD(v107));
  v725 = v724 + v366 + v796;
  v781 = v611 + v790;
  v612 = __PAIR64__(v107, HIDWORD(v107)) + v672;
  LODWORD(v464) = v110 >> 16;
  HIDWORD(v464) = HIWORD(HIDWORD(v110)) | ((_DWORD)v110 << 16);
  v111 = __PAIR64__(v393, HIDWORD(v393));
  v518 = __PAIR64__(v393, HIDWORD(v393)) + v547;
  v424 = __PAIR64__(v108, HIDWORD(v108));
  v702 = v464 + v701;
  v112 = (__PAIR64__(v393, HIDWORD(v393)) + v547) ^ v366;
  v643 = v424 + v580;
  v113 = v105 ^ v702;
  LODWORD(v488) = (2 * v113) | (HIDWORD(v113) >> 31);
  v114 = (v424 + v580) ^ v442;
  HIDWORD(v488) = v113 >> 31;
  LODWORD(v393) = v112 >> 24;
  HIDWORD(v393) = HIBYTE(HIDWORD(v112)) | ((_DWORD)v112 << 8);
  HIDWORD(v366) = ((unsigned int)((v612 ^ v348) >> 32) >> 24) | (((unsigned int)v612 ^ (unsigned int)v348) << 8);
  LODWORD(v366) = (__int64)(v612 ^ v348) >> 24;
  LODWORD(v348) = v114 >> 24;
  HIDWORD(v348) = HIBYTE(HIDWORD(v114)) | ((_DWORD)v114 << 8);
  v548 = v379 + v366;
  v115 = (v725 + v393) ^ v111;
  v673 = v781 + v348;
  v116 = (v379 + v366) ^ v411;
  v117 = v725 + v393 + v799 + v488;
  LODWORD(v379) = v115 >> 16;
  v118 = (v781 + v348) ^ v424;
  v782 = v117 + v790;
  LODWORD(v114) = v116 >> 16;
  HIDWORD(v114) = HIWORD(HIDWORD(v116)) | ((_DWORD)v116 << 16);
  HIDWORD(v379) = HIWORD(HIDWORD(v115)) | ((_DWORD)v115 << 16);
  LODWORD(v424) = v118 >> 16;
  HIDWORD(v424) = HIWORD(HIDWORD(v118)) | ((_DWORD)v118 << 16);
  v581 = v379 + v518;
  v443 = __PAIR64__((unsigned int)v114 ^ (unsigned int)v117, (v114 ^ v117) >> 32);
  v119 = (v379 + v518) ^ v393;
  v519 = v114 + v612;
  v120 = __PAIR64__((unsigned int)v114 ^ (unsigned int)v117, (v114 ^ v117) >> 32) + v424 + v643;
  v121 = (v114 + v612) ^ v366;
  LODWORD(v411) = (2 * v119) | (HIDWORD(v119) >> 31);
  HIDWORD(v411) = v119 >> 31;
  LODWORD(v87) = (2 * (v519 ^ v366)) | ((unsigned int)((v519 ^ v366) >> 32) >> 31);
  HIDWORD(v114) = ((unsigned int)((v120 ^ v488) >> 32) >> 24) | (((unsigned int)v120 ^ (unsigned int)v488) << 8);
  HIDWORD(v87) = v121 >> 31;
  LODWORD(v114) = (__int64)(v120 ^ v488) >> 24;
  v489 = v782 + v114;
  v122 = (v782 + v114) ^ v443;
  LODWORD(v366) = v122 >> 16;
  HIDWORD(v366) = HIWORD(HIDWORD(v122)) | ((_DWORD)v122 << 16);
  v444 = v366 + v120;
  v394 = (2 * ((v424 + v643) ^ v348)) | ((unsigned int)(((v424 + v643) ^ v348) >> 32) >> 31);
  v123 = v548 + v795 + v411;
  v124 = v114 ^ (v366 + v120);
  v425 = __PAIR64__((unsigned int)v123 ^ (unsigned int)v424, (v123 ^ v424) >> 32);
  v549 = v123 + v797;
  v349 = __PAIR64__((v673 + v792 + v87) ^ v464, ((v673 + v792 + v87) ^ v464) >> 32);
  v644 = v673 + v792 + v87 + v794;
  v613 = v425 + v702;
  v582 = __PAIR64__((v673 + v792 + v87) ^ v464, ((v673 + v792 + v87) ^ v464) >> 32) + v581;
  v465 = (v756 + v800 + v394) ^ v379;
  HIDWORD(v379) = v124 >> 31;
  v125 = (v425 + v702) ^ v411;
  v674 = v756 + v800 + v394 + v805;
  LODWORD(v411) = v125 >> 24;
  v703 = v489 + v804;
  LODWORD(v119) = (__int64)(v582 ^ v87) >> 24;
  HIDWORD(v411) = HIBYTE(HIDWORD(v125)) | ((_DWORD)v125 << 8);
  HIDWORD(v119) = ((unsigned int)((v582 ^ v87) >> 32) >> 24) | (((unsigned int)v582 ^ (unsigned int)v87) << 8);
  LODWORD(v118) = (v549 + v411) ^ v425;
  LODWORD(v379) = (2 * v124) | (HIDWORD(v124) >> 31);
  v126 = (v644 + v119) ^ v349;
  HIDWORD(v118) = (unsigned int)(((v549 + v411) ^ v425) >> 32) >> 16;
  LODWORD(v425) = (__int64)((v549 + v411) ^ v425) >> 16;
  v127 = __PAIR64__(v465, HIDWORD(v465));
  v726 = v549 + v411 + v801;
  HIDWORD(v425) = HIDWORD(v118) | ((_DWORD)v118 << 16);
  v520 = __PAIR64__(v465, HIDWORD(v465)) + v519;
  LODWORD(v118) = v520 ^ v394;
  LODWORD(v465) = v126 >> 16;
  v490 = v425 + v613;
  HIDWORD(v465) = HIWORD(HIDWORD(v126)) | ((_DWORD)v126 << 16);
  HIDWORD(v118) = (unsigned int)((v520 ^ (unsigned __int64)v394) >> 32) >> 24;
  LODWORD(v394) = (v520 ^ v394) >> 24;
  HIDWORD(v394) = HIDWORD(v118) | ((_DWORD)v118 << 8);
  v645 = v644 + v119 + v796;
  v350 = (2 * ((v425 + v613) ^ v411)) | ((unsigned int)(((v425 + v613) ^ v411) >> 32) >> 31);
  v128 = (v465 + v582) ^ v119;
  LODWORD(v119) = (2 * v128) | (HIDWORD(v128) >> 31);
  v129 = (v674 + v394) ^ v127;
  v614 = v674 + v394;
  HIDWORD(v119) = v128 >> 31;
  LODWORD(v120) = v129 >> 16;
  HIDWORD(v120) = HIWORD(HIDWORD(v129)) | ((_DWORD)v129 << 16);
  v130 = (v703 + v350) ^ v120;
  v131 = __PAIR64__(v130, HIDWORD(v130));
  v583 = __PAIR64__(v130, HIDWORD(v130)) + v465 + v582;
  v132 = (v120 + v520) ^ v394;
  v133 = (2 * ((v120 + v520) ^ v394)) | (HIDWORD(v132) >> 31);
  v395 = v726 + v119 + v802;
  v367 = __PAIR64__((v726 + v119) ^ v366, ((v726 + v119) ^ v366) >> 32);
  LODWORD(v411) = v133;
  v550 = v367 + v120 + v520;
  HIDWORD(v411) = v132 >> 31;
  v134 = v550 ^ v119;
  LODWORD(v120) = (__int64)(v583 ^ v350) >> 24;
  HIDWORD(v120) = ((unsigned int)((v583 ^ v350) >> 32) >> 24) | (((unsigned int)v583 ^ (unsigned int)v350) << 8);
  LODWORD(v119) = (__int64)(v550 ^ v119) >> 24;
  HIDWORD(v119) = HIBYTE(HIDWORD(v134)) | ((_DWORD)v134 << 8);
  v521 = v703 + v350 + v791 + v120;
  v675 = v645 + v411;
  v646 = v395 + v119;
  v135 = v395 + v119;
  LODWORD(v395) = (__int64)(v521 ^ v131) >> 16;
  HIDWORD(v395) = ((unsigned int)(HIDWORD(v521) ^ HIDWORD(v131)) >> 16)
                | (((unsigned int)v521 ^ (unsigned int)v131) << 16);
  v136 = v135 ^ v367;
  v351 = __PAIR64__((unsigned int)v675 ^ (unsigned int)v425, (v675 ^ v425) >> 32);
  v584 = v395 + v583;
  LODWORD(v425) = v136 >> 16;
  HIDWORD(v425) = HIWORD(HIDWORD(v136)) | ((_DWORD)v136 << 16);
  v704 = v351 + v444;
  v551 = v425 + v550;
  v137 = (v351 + v444) ^ v411;
  HIDWORD(v367) = (__int64)(v584 ^ v120) >> 31;
  v676 = v675 + v798;
  LODWORD(v367) = (2 * (v584 ^ v120)) | ((unsigned int)((v584 ^ v120) >> 32) >> 31);
  v138 = v551 ^ v119;
  LODWORD(v411) = (2 * (v551 ^ v119)) | ((unsigned int)((v551 ^ v119) >> 32) >> 31);
  v139 = (v614 + v793 + v379) ^ v465;
  HIDWORD(v411) = v138 >> 31;
  v491 = __PAIR64__(v139, HIDWORD(v139)) + v490;
  LODWORD(v465) = v137 >> 24;
  HIDWORD(v465) = HIBYTE(HIDWORD(v137)) | ((_DWORD)v137 << 8);
  LODWORD(v131) = (__int64)(v491 ^ v379) >> 24;
  HIDWORD(v131) = ((unsigned int)((v491 ^ v379) >> 32) >> 24) | (((unsigned int)v491 ^ (unsigned int)v379) << 8);
  v140 = (v676 + v465) ^ v351;
  v141 = v614 + v793 + v379 + v803 + v131;
  v757 = v141 + v798;
  v142 = v141 ^ __PAIR64__(v139, HIDWORD(v139));
  LODWORD(v120) = v140 >> 16;
  v143 = v676 + v465 + v790 + v411;
  LODWORD(v137) = v142 >> 16;
  HIDWORD(v137) = HIWORD(HIDWORD(v142)) | ((_DWORD)v142 << 16);
  HIDWORD(v120) = HIWORD(HIDWORD(v140)) | ((_DWORD)v140 << 16);
  v445 = v137 + v491;
  v144 = v143 ^ v137;
  v145 = v646 + v796 + v367;
  v492 = v144;
  v727 = v120 ^ v145;
  v146 = v445 ^ v131;
  v647 = v145 + v800;
  v147 = (v120 + v704) ^ v465;
  LODWORD(v131) = (2 * (v445 ^ v131)) | ((unsigned int)((v445 ^ v131) >> 32) >> 31);
  HIDWORD(v131) = v146 >> 31;
  LODWORD(v379) = (2 * v147) | (HIDWORD(v147) >> 31);
  HIDWORD(v379) = v147 >> 31;
  v148 = (v521 + v792 + v131) ^ v425;
  v149 = (v757 + v379) ^ v395;
  v466 = __PAIR64__(v148, HIDWORD(v148)) + v120 + v704;
  HIDWORD(v395) = ((unsigned int)((v466 ^ v131) >> 32) >> 24) | (((unsigned int)v466 ^ (unsigned int)v131) << 8);
  v352 = __PAIR64__(v492, HIDWORD(v492));
  LODWORD(v395) = (__int64)(v466 ^ v131) >> 24;
  v150 = __PAIR64__(v492, HIDWORD(v492)) + v584;
  v493 = __PAIR64__(v727, HIDWORD(v727)) + v445;
  v446 = v521 + v792 + v131 + v802 + v395;
  v522 = v150;
  v552 = __PAIR64__(v149, HIDWORD(v149)) + v551;
  v151 = v150 ^ v411;
  LODWORD(v411) = (__int64)(__PAIR64__(v148, HIDWORD(v148)) ^ v446) >> 16;
  HIDWORD(v411) = (((unsigned int)v148 ^ HIDWORD(v446)) >> 16) | ((HIDWORD(v148) ^ (unsigned int)v446) << 16);
  v368 = __PAIR64__(
           ((unsigned int)((v493 ^ v367) >> 32) >> 24) | (((unsigned int)v493 ^ (unsigned int)v367) << 8),
           (__int64)(v493 ^ v367) >> 24);
  v585 = v411 + v466;
  v152 = (v411 + v466) ^ v395;
  LODWORD(v131) = v151 >> 24;
  LODWORD(v741) = (__int64)(v552 ^ v379) >> 24;
  v467 = v647 + v368;
  HIDWORD(v131) = HIBYTE(HIDWORD(v151)) | ((_DWORD)v151 << 8);
  HIDWORD(v741) = ((unsigned int)((v552 ^ v379) >> 32) >> 24) | (((unsigned int)v552 ^ (unsigned int)v379) << 8);
  v153 = (v647 + v368) ^ __PAIR64__(v727, HIDWORD(v727));
  v615 = v143 + v801 + v131;
  v154 = v757 + v379 + v793;
  LODWORD(v379) = (2 * v152) | (HIDWORD(v152) >> 31);
  v648 = v154 + v741;
  HIDWORD(v379) = v152 >> 31;
  LODWORD(v395) = v153 >> 16;
  v155 = (v154 + v741) ^ __PAIR64__(v149, HIDWORD(v149));
  HIDWORD(v395) = HIWORD(HIDWORD(v153)) | ((_DWORD)v153 << 16);
  LODWORD(v154) = (__int64)(v615 ^ v352) >> 16;
  HIDWORD(v154) = ((unsigned int)((v615 ^ v352) >> 32) >> 16) | (((unsigned int)v615 ^ (unsigned int)v352) << 16);
  HIDWORD(v352) = HIWORD(HIDWORD(v155)) | ((_DWORD)v155 << 16);
  LODWORD(v352) = v155 >> 16;
  v523 = v154 + v522;
  v494 = v395 + v493;
  v156 = v494 ^ v368;
  v553 = v352 + v552;
  v677 = v446 + v794;
  LODWORD(v425) = (2 * (v523 ^ v131)) | ((unsigned int)((v523 ^ v131) >> 32) >> 31);
  HIDWORD(v425) = (__int64)(v523 ^ v131) >> 31;
  v157 = (v648 + v791 + v379) ^ v154;
  v447 = __PAIR64__(v157, HIDWORD(v157));
  v728 = v615 + v805;
  LODWORD(v368) = (2 * v156) | (HIDWORD(v156) >> 31);
  HIDWORD(v368) = v156 >> 31;
  v616 = v467 + v797 + v425;
  v158 = v648 + v791 + v379 + v799;
  LODWORD(v467) = (2 * (v553 ^ v741)) | ((unsigned int)((v553 ^ v741) >> 32) >> 31);
  v649 = __PAIR64__(v157, HIDWORD(v157)) + v494;
  HIDWORD(v467) = (__int64)(v553 ^ v741) >> 31;
  v159 = (__PAIR64__(v157, HIDWORD(v157)) + v494) ^ v379;
  v380 = v677 + v368;
  v729 = v728 + v467;
  v160 = (v677 + v368) ^ v352;
  LODWORD(v143) = v159 >> 24;
  HIDWORD(v143) = HIBYTE(HIDWORD(v159)) | ((_DWORD)v159 << 8);
  v161 = v729 ^ v395;
  v678 = v158 + v143;
  v412 = __PAIR64__((unsigned int)v616 ^ (unsigned int)v411, (v616 ^ v411) >> 32);
  v705 = v616 + v795;
  v162 = (v158 + v143) ^ v447;
  v396 = __PAIR64__(v160, HIDWORD(v160));
  v617 = v412 + v553;
  v448 = __PAIR64__(v160, HIDWORD(v160)) + v523;
  v353 = __PAIR64__(v161, HIDWORD(v161));
  v163 = (v412 + v553) ^ v425;
  HIDWORD(v494) = HIWORD(HIDWORD(v162)) | ((_DWORD)v162 << 16);
  LODWORD(v494) = v162 >> 16;
  v586 = __PAIR64__(v161, HIDWORD(v161)) + v585;
  v164 = v448 ^ v368;
  LODWORD(v368) = v163 >> 24;
  v554 = v494 + v649;
  v165 = v586 ^ v467;
  v166 = v143 ^ (v494 + v649);
  LODWORD(v467) = (2 * v166) | (HIDWORD(v166) >> 31);
  HIDWORD(v467) = v166 >> 31;
  v167 = v380 + v803;
  HIDWORD(v380) = HIBYTE(HIDWORD(v164)) | ((_DWORD)v164 << 8);
  LODWORD(v380) = v164 >> 24;
  HIDWORD(v368) = HIBYTE(HIDWORD(v163)) | ((_DWORD)v163 << 8);
  LODWORD(v425) = v165 >> 24;
  HIDWORD(v425) = HIBYTE(HIDWORD(v165)) | ((_DWORD)v165 << 8);
  v168 = v167 + v380;
  v524 = v729 + v804 + v425;
  v169 = v168 + v802 + v467;
  v170 = (v705 + v368) ^ v412;
  v397 = __PAIR64__(
           ((unsigned int)((v168 ^ v396) >> 32) >> 16) | (((unsigned int)v168 ^ (unsigned int)v396) << 16),
           (__int64)(v168 ^ v396) >> 16);
  v171 = v524 ^ v353;
  LODWORD(v164) = v170 >> 16;
  HIDWORD(v164) = HIWORD(HIDWORD(v170)) | ((_DWORD)v170 << 16);
  LODWORD(v353) = (__int64)(v524 ^ v353) >> 16;
  v449 = v397 + v448;
  HIDWORD(v353) = HIWORD(HIDWORD(v171)) | ((_DWORD)v171 << 16);
  v650 = v169 + v795;
  v172 = v353 + v586;
  LODWORD(v168) = HIDWORD(v169) ^ HIDWORD(v164);
  v587 = v164 + v617;
  HIDWORD(v168) = v169 ^ v164;
  LODWORD(v412) = (2 * (v449 ^ v380)) | ((unsigned int)((v449 ^ v380) >> 32) >> 31);
  HIDWORD(v412) = (__int64)(v449 ^ v380) >> 31;
  v618 = __PAIR64__((unsigned int)v169 ^ (unsigned int)v164, HIDWORD(v169) ^ HIDWORD(v164)) + v172;
  v173 = (__PAIR64__((unsigned int)v169 ^ (unsigned int)v164, HIDWORD(v169) ^ HIDWORD(v164)) + v172) ^ v467;
  v468 = v705 + v368 + v791 + v412;
  LODWORD(v169) = v173 >> 24;
  v174 = v172 ^ v425;
  HIDWORD(v169) = HIBYTE(HIDWORD(v173)) | ((_DWORD)v173 << 8);
  v706 = v468 ^ v353;
  LODWORD(v171) = (2 * (v587 ^ v368)) | ((unsigned int)((v587 ^ v368) >> 32) >> 31);
  HIDWORD(v171) = (__int64)(v587 ^ v368) >> 31;
  v175 = (v650 + v169) ^ v168;
  v354 = v650 + v169;
  LODWORD(v368) = v175 >> 16;
  HIDWORD(v368) = HIWORD(HIDWORD(v175)) | ((_DWORD)v175 << 16);
  v426 = __PAIR64__(v706, HIDWORD(v706));
  v619 = v368 + v618;
  HIDWORD(v380) = v174 >> 31;
  v555 = __PAIR64__(v706, HIDWORD(v706)) + v554;
  v176 = v619 ^ v169;
  v651 = v468 + v805;
  LODWORD(v380) = (2 * v174) | (HIDWORD(v174) >> 31);
  v177 = v524 + v804 + v171;
  v178 = v555 ^ v412;
  v413 = v678 + v794 + v380;
  v679 = v177 + v803;
  v179 = v177 ^ v494;
  v469 = v177 ^ v494;
  v495 = v413 + v800;
  v707 = v354 + v790;
  v414 = __PAIR64__((unsigned int)v413 ^ (unsigned int)v397, (v413 ^ v397) >> 32);
  v180 = __PAIR64__(v469, HIDWORD(v469));
  v398 = (2 * v176) | (HIDWORD(v176) >> 31);
  v450 = __PAIR64__(v179, HIDWORD(v179)) + v449;
  v181 = (v414 + v587) ^ v380;
  v182 = v450 ^ v171;
  LODWORD(v179) = v178 >> 24;
  HIDWORD(v179) = HIBYTE(HIDWORD(v178)) | ((_DWORD)v178 << 8);
  LODWORD(v469) = v181 >> 24;
  LODWORD(v354) = (__int64)(v450 ^ v171) >> 24;
  HIDWORD(v469) = HIBYTE(HIDWORD(v181)) | ((_DWORD)v181 << 8);
  v183 = v651 + v179;
  v184 = (v651 + v179) ^ v426;
  HIDWORD(v354) = HIBYTE(HIDWORD(v182)) | ((_DWORD)v182 << 8);
  v652 = v495 + v469;
  LODWORD(v380) = v184 >> 16;
  HIDWORD(v380) = HIWORD(HIDWORD(v184)) | ((_DWORD)v184 << 16);
  v185 = (v679 + v354) ^ v180;
  LODWORD(v180) = (__int64)((v495 + v469) ^ v414) >> 16;
  HIDWORD(v426) = HIWORD(HIDWORD(v185)) | ((_DWORD)v185 << 16);
  HIDWORD(v180) = ((unsigned int)((v652 ^ v414) >> 32) >> 16) | (((unsigned int)v652 ^ (unsigned int)v414) << 16);
  v186 = v179 ^ (v380 + v555);
  v187 = v180 + v414 + v587;
  v588 = v380 + v555;
  LODWORD(v426) = v185 >> 16;
  v556 = v187;
  LODWORD(v414) = (2 * v186) | (HIDWORD(v186) >> 31);
  v188 = v187 ^ v469;
  HIDWORD(v414) = v186 >> 31;
  v189 = (v426 + v450) ^ v354;
  HIDWORD(v469) = v188 >> 31;
  v190 = v679 + v354 + v799;
  LODWORD(v469) = (2 * v188) | (HIDWORD(v188) >> 31);
  LODWORD(v354) = (2 * v189) | (HIDWORD(v189) >> 31);
  v191 = (v707 + v414) ^ v180;
  v192 = v190 + v469;
  HIDWORD(v354) = v189 >> 31;
  v730 = v707 + v414 + v797;
  v193 = v183 + v796 + v354;
  v525 = __PAIR64__(v191, HIDWORD(v191)) + v426 + v450;
  v708 = v192 + v792;
  v496 = __PAIR64__((unsigned int)v193 ^ (unsigned int)v368, (v193 ^ v368) >> 32);
  v369 = __PAIR64__((unsigned int)v192 ^ (unsigned int)v380, (v192 ^ v380) >> 32);
  v557 = v496 + v556;
  v680 = __PAIR64__((unsigned int)v192 ^ (unsigned int)v380, (v192 ^ v380) >> 32) + v619;
  v194 = v193 + v793;
  LODWORD(v380) = (__int64)(v525 ^ v414) >> 24;
  HIDWORD(v380) = ((unsigned int)((v525 ^ v414) >> 32) >> 24) | (((unsigned int)v525 ^ (unsigned int)v414) << 8);
  LODWORD(v180) = (__int64)(v557 ^ v354) >> 24;
  HIDWORD(v180) = ((unsigned int)((v557 ^ v354) >> 32) >> 24) | (((unsigned int)v557 ^ (unsigned int)v354) << 8);
  LODWORD(v354) = (__int64)(v680 ^ v469) >> 24;
  HIDWORD(v193) = ((unsigned int)((v680 ^ v469) >> 32) >> 24) | (((unsigned int)v680 ^ (unsigned int)v469) << 8);
  v470 = v730 + v380;
  LODWORD(v193) = (v730 + v380) ^ HIDWORD(v191);
  HIDWORD(v354) = HIDWORD(v193);
  HIDWORD(v193) = ((v730 + v380) >> 32) ^ v191;
  v731 = v194 + v180;
  LODWORD(v414) = v193 >> 16;
  v451 = v708 + v354;
  HIDWORD(v414) = HIWORD(HIDWORD(v193)) | ((_DWORD)v193 << 16);
  v195 = (v708 + v354) ^ v369;
  v526 = v414 + v525;
  v370 = __PAIR64__(
           ((unsigned int)(((v194 + v180) ^ v496) >> 32) >> 16)
         | ((((_DWORD)v194 + (_DWORD)v180) ^ (unsigned int)v496) << 16),
           (__int64)((v194 + v180) ^ v496) >> 16);
  LODWORD(v194) = v195 >> 16;
  HIDWORD(v194) = HIWORD(HIDWORD(v195)) | ((_DWORD)v195 << 16);
  v620 = v370 + v557;
  v196 = v526 ^ v380;
  v497 = v194 + v680;
  v197 = (v370 + v557) ^ v180;
  LODWORD(v380) = (2 * (v526 ^ v380)) | ((unsigned int)((v526 ^ v380) >> 32) >> 31);
  v653 = v652 + v798 + v398;
  v198 = (v194 + v680) ^ v354;
  HIDWORD(v380) = v196 >> 31;
  v558 = v653 + v801;
  v355 = __PAIR64__((unsigned int)v653 ^ (unsigned int)v426, (v653 ^ v426) >> 32);
  v654 = v470 + v803;
  v199 = v731 + v797 + v380;
  v200 = v355 + v588;
  v589 = v199 ^ v194;
  v427 = (2 * v197) | (HIDWORD(v197) >> 31);
  LODWORD(v470) = (v200 ^ v398) >> 24;
  HIDWORD(v470) = ((unsigned int)((v200 ^ (unsigned __int64)v398) >> 32) >> 24)
                | (((unsigned int)v200 ^ (unsigned int)v398) << 8);
  v399 = (2 * v198) | (HIDWORD(v198) >> 31);
  v201 = (v558 + v470) ^ v355;
  LODWORD(v194) = v201 >> 16;
  HIDWORD(v194) = HIWORD(HIDWORD(v201)) | ((_DWORD)v201 << 16);
  v202 = v558 + v470 + v793 + v399;
  v203 = (v194 + v200) ^ v470;
  v559 = __PAIR64__(v589, HIDWORD(v589)) + v194 + v200;
  LODWORD(v355) = (2 * v203) | (HIDWORD(v203) >> 31);
  v415 = v202 ^ v414;
  HIDWORD(v355) = v203 >> 31;
  v204 = v202 + v799;
  v205 = (v451 + v802 + v427) ^ v194;
  v709 = v204;
  v758 = v451 + v802 + v427 + v791;
  v206 = v654 + v355;
  v207 = (v654 + v355) ^ v370;
  v655 = v199
       + v804
       + __PAIR64__(
           ((unsigned int)((v559 ^ v380) >> 32) >> 24) | (((unsigned int)v559 ^ (unsigned int)v380) << 8),
           (__int64)(v559 ^ v380) >> 24);
  v208 = __PAIR64__(v207, HIDWORD(v207));
  v209 = __PAIR64__(v589, HIDWORD(v589)) ^ v655;
  v590 = __PAIR64__(v207, HIDWORD(v207)) + v497;
  v471 = __PAIR64__(HIWORD(HIDWORD(v209)) | ((_DWORD)v209 << 16), v209 >> 16);
  v210 = (__PAIR64__(v207, HIDWORD(v207)) + v497) ^ v355;
  v498 = __PAIR64__(v415, HIDWORD(v415));
  v211 = __PAIR64__(v415, HIDWORD(v415));
  v416 = __PAIR64__(v205, HIDWORD(v205));
  v681 = v211 + v620;
  v621 = __PAIR64__(HIWORD(HIDWORD(v209)) | ((_DWORD)v209 << 16), v209 >> 16) + v559;
  v527 = __PAIR64__(v205, HIDWORD(v205)) + v526;
  v212 = __PAIR64__(
           ((unsigned int)((v559 ^ v380) >> 32) >> 24) | (((unsigned int)v559 ^ (unsigned int)v380) << 8),
           (__int64)(v559 ^ v380) >> 24);
  v381 = __PAIR64__(HIBYTE(HIDWORD(v210)) | ((_DWORD)v210 << 8), v210 >> 24);
  LODWORD(v370) = (2 * (v621 ^ v212)) | ((unsigned int)((v621 ^ v212) >> 32) >> 31);
  v213 = v527 ^ v427;
  v214 = (__int64)(v621 ^ v212) >> 31;
  v215 = v206 + v801 + v381;
  v216 = v208 ^ v215;
  HIDWORD(v355) = ((unsigned int)((v681 ^ v399) >> 32) >> 24) | (((unsigned int)v681 ^ (unsigned int)v399) << 8);
  LODWORD(v355) = (__int64)(v681 ^ v399) >> 24;
  LODWORD(v427) = (__int64)(v527 ^ v427) >> 24;
  LODWORD(v399) = v216 >> 16;
  HIDWORD(v427) = HIBYTE(HIDWORD(v213)) | ((_DWORD)v213 << 8);
  HIDWORD(v399) = HIWORD(HIDWORD(v216)) | ((_DWORD)v216 << 16);
  v217 = v215 + v795;
  v218 = (v709 + v355) ^ v498;
  HIDWORD(v370) = v214;
  v710 = v709 + v355;
  v732 = v217 + v370;
  v499 = v399 + v590;
  v219 = (v399 + v590) ^ v381;
  LODWORD(v205) = v218 >> 16;
  v220 = (v758 + v427) ^ v416;
  HIDWORD(v205) = HIWORD(HIDWORD(v218)) | ((_DWORD)v218 << 16);
  LODWORD(v416) = (2 * v219) | (HIDWORD(v219) >> 31);
  v382 = __PAIR64__(HIWORD(HIDWORD(v220)) | ((_DWORD)v220 << 16), v220 >> 16);
  HIDWORD(v416) = v219 >> 31;
  v221 = __PAIR64__(HIWORD(HIDWORD(v220)) | ((_DWORD)v220 << 16), v220 >> 16) + v527;
  v222 = (v217 + v370) ^ v205;
  v591 = v205 + v681;
  v223 = __PAIR64__(v222, HIDWORD(v222)) + v221;
  v224 = __PAIR64__(v222, HIDWORD(v222));
  v225 = v221 ^ v427;
  v528 = v223;
  LODWORD(v223) = v223 ^ v370;
  LODWORD(v451) = (2 * (v591 ^ v355)) | ((unsigned int)((v591 ^ v355) >> 32) >> 31);
  HIDWORD(v451) = (__int64)(v591 ^ v355) >> 31;
  v356 = __PAIR64__((v710 + v792 + v416) ^ v382, ((v710 + v792 + v416) ^ v382) >> 32);
  v226 = v710 + v792 + v416;
  HIDWORD(v223) = (unsigned int)((v528 ^ v370) >> 32) >> 24;
  LODWORD(v370) = (__int64)(v528 ^ v370) >> 24;
  v711 = v758 + v427 + v798 + v451;
  v560 = v226 + v800;
  v622 = v356 + v621;
  HIDWORD(v370) = HIDWORD(v223) | ((_DWORD)v223 << 8);
  HIDWORD(v382) = v225 >> 31;
  v227 = v711 ^ v471;
  LODWORD(v382) = (2 * v225) | (HIDWORD(v225) >> 31);
  v472 = v732 + v790 + v370;
  v733 = __PAIR64__(v227, HIDWORD(v227));
  LODWORD(v217) = (__int64)(v622 ^ v416) >> 24;
  HIDWORD(v217) = ((unsigned int)((v622 ^ v416) >> 32) >> 24) | (((unsigned int)v622 ^ (unsigned int)v416) << 8);
  v656 = v655 + v805 + v382;
  HIDWORD(v427) = ((unsigned int)((v472 ^ v224) >> 32) >> 16) | (((unsigned int)v472 ^ (unsigned int)v224) << 16);
  v561 = v560 + v217;
  LODWORD(v427) = (__int64)(v472 ^ v224) >> 16;
  LODWORD(v225) = v561 ^ v356;
  v417 = __PAIR64__((unsigned int)v656 ^ (unsigned int)v399, (v656 ^ v399) >> 32);
  v529 = v427 + v528;
  v682 = v656 + v794;
  v592 = __PAIR64__((unsigned int)v656 ^ (unsigned int)v399, (v656 ^ v399) >> 32) + v591;
  v500 = __PAIR64__(v227, HIDWORD(v227)) + v499;
  LODWORD(v218) = v592 ^ v382;
  LODWORD(v399) = (2 * (v529 ^ v370)) | ((unsigned int)((v529 ^ v370) >> 32) >> 31);
  v228 = v500 ^ v451;
  HIDWORD(v225) = (unsigned int)((v561 ^ v356) >> 32) >> 16;
  LODWORD(v356) = (__int64)(v561 ^ v356) >> 16;
  HIDWORD(v356) = HIDWORD(v225) | ((_DWORD)v225 << 16);
  HIDWORD(v399) = (__int64)(v529 ^ v370) >> 31;
  v657 = v356 + v622;
  LODWORD(v382) = (__int64)(v592 ^ v382) >> 24;
  v452 = v472 + v796;
  v229 = (v356 + v622) ^ v217;
  HIDWORD(v382) = ((unsigned int)(HIDWORD(v592) ^ HIDWORD(v382)) >> 24) | ((_DWORD)v218 << 8);
  LODWORD(v370) = v228 >> 24;
  HIDWORD(v370) = HIBYTE(HIDWORD(v228)) | ((_DWORD)v228 << 8);
  v623 = v711 + v796 + v370;
  v230 = (v682 + v382) ^ v417;
  v231 = v682 + v382 + v804 + v399;
  LODWORD(v217) = v230 >> 16;
  HIDWORD(v472) = v229 >> 31;
  LODWORD(v472) = (2 * v229) | (HIDWORD(v229) >> 31);
  v683 = v231 + v799;
  HIDWORD(v217) = HIWORD(HIDWORD(v230)) | ((_DWORD)v230 << 16);
  v232 = v452 + ((2 * v229) | (HIDWORD(v229) >> 31));
  HIDWORD(v229) = ((unsigned int)(HIDWORD(v623) ^ HIDWORD(v733)) >> 16)
                | (((unsigned int)v623 ^ (unsigned int)v733) << 16);
  v712 = v452 + v472 + v805;
  v233 = (__int64)(v623 ^ v733) >> 16;
  v234 = __PAIR64__(HIDWORD(v229), v233) + v500;
  v453 = __PAIR64__(v233 ^ (unsigned int)v231, HIDWORD(v229) ^ HIDWORD(v231));
  v501 = v217 + v592;
  v658 = __PAIR64__(v233 ^ (unsigned int)v231, HIDWORD(v229) ^ HIDWORD(v231)) + v657;
  v235 = v234 ^ v370;
  v236 = __PAIR64__((unsigned int)v217 ^ (unsigned int)v232, (v217 ^ v232) >> 32);
  LODWORD(v417) = (2 * (v501 ^ v382)) | ((unsigned int)((v501 ^ v382) >> 32) >> 31);
  v237 = v658 ^ v399;
  v593 = v236 + v234;
  HIDWORD(v417) = (__int64)(v501 ^ v382) >> 31;
  LODWORD(v399) = (2 * (v234 ^ v370)) | ((unsigned int)((v234 ^ v370) >> 32) >> 31);
  v238 = (v236 + v234) ^ v472;
  LODWORD(v217) = v237 >> 24;
  HIDWORD(v382) = HIBYTE(HIDWORD(v238)) | ((_DWORD)v238 << 8);
  LODWORD(v382) = v238 >> 24;
  HIDWORD(v217) = HIBYTE(HIDWORD(v237)) | ((_DWORD)v237 << 8);
  v684 = v683 + v217;
  HIDWORD(v399) = v235 >> 31;
  v239 = v236 ^ (v712 + v382);
  HIDWORD(v472) = ((unsigned int)((v684 ^ v453) >> 32) >> 16) | (((unsigned int)v684 ^ (unsigned int)v453) << 16);
  LODWORD(v472) = (__int64)(v684 ^ v453) >> 16;
  LODWORD(v370) = v239 >> 16;
  HIDWORD(v370) = HIWORD(HIDWORD(v239)) | ((_DWORD)v239 << 16);
  v659 = v472 + v658;
  v594 = v370 + v593;
  HIDWORD(v453) = (__int64)(v659 ^ v217) >> 31;
  v240 = v623 + v801 + v417;
  v241 = v561 + v790 + v399;
  LODWORD(v453) = (2 * (v659 ^ v217)) | ((unsigned int)((v659 ^ v217) >> 32) >> 31);
  v624 = v240 + v793;
  v562 = v241 + v798;
  v428 = __PAIR64__((unsigned int)v241 ^ (unsigned int)v427, (v241 ^ (unsigned __int64)v427) >> 32);
  v242 = __PAIR64__((unsigned int)v240 ^ (unsigned int)v356, (v240 ^ v356) >> 32);
  v502 = v428 + v501;
  v357 = __PAIR64__((unsigned int)v240 ^ (unsigned int)v356, (v240 ^ v356) >> 32) + v529;
  v243 = v399;
  v400 = (2 * (v594 ^ v382)) | ((unsigned int)((v594 ^ v382) >> 32) >> 31);
  v530 = v712 + v382 + v802 + v453;
  LODWORD(v382) = (v502 ^ v243) >> 24;
  LODWORD(v237) = (__int64)(v357 ^ v417) >> 24;
  HIDWORD(v382) = ((unsigned int)((v502 ^ (unsigned __int64)v243) >> 32) >> 24)
                | (((unsigned int)v502 ^ (unsigned int)v243) << 8);
  HIDWORD(v237) = ((unsigned int)((v357 ^ v417) >> 32) >> 24) | (((unsigned int)v357 ^ (unsigned int)v417) << 8);
  v244 = (v241 + v798 + v382) ^ v428;
  v245 = (v624 + v237) ^ v242;
  v625 = v624 + v237 + v791;
  LODWORD(v243) = v244 >> 16;
  HIDWORD(v243) = HIWORD(HIDWORD(v244)) | ((_DWORD)v244 << 16);
  LODWORD(v242) = v245 >> 16;
  HIDWORD(v242) = HIWORD(HIDWORD(v245)) | ((_DWORD)v245 << 16);
  v503 = v243 + v502;
  v358 = v242 + v357;
  v759 = v562 + v382 + v800 + v400;
  LODWORD(v417) = (2 * (v503 ^ v382)) | ((unsigned int)((v503 ^ v382) >> 32) >> 31);
  HIDWORD(v417) = (__int64)(v503 ^ v382) >> 31;
  v783 = v759 ^ v242;
  v429 = __PAIR64__((unsigned int)v243 ^ (unsigned int)v530, (v243 ^ v530) >> 32);
  v563 = v530 + v792;
  v383 = (2 * (v358 ^ v237)) | ((unsigned int)((v358 ^ v237) >> 32) >> 31);
  v531 = __PAIR64__((unsigned int)v243 ^ (unsigned int)v530, (v243 ^ v530) >> 32) + v358;
  v734 = v684 + v803 + v383;
  v246 = (v429 + v358) ^ v453;
  v359 = __PAIR64__((unsigned int)v734 ^ (unsigned int)v370, (v734 ^ v370) >> 32);
  LODWORD(v242) = v246 >> 24;
  v473 = __PAIR64__((v625 + v417) ^ v472, ((v625 + v417) ^ v472) >> 32);
  HIDWORD(v242) = HIBYTE(HIDWORD(v246)) | ((_DWORD)v246 << 8);
  v713 = v625 + v417 + v794;
  v626 = __PAIR64__((unsigned int)v734 ^ (unsigned int)v370, (v734 ^ v370) >> 32) + v503;
  v685 = v473 + v594;
  v247 = (__PAIR64__((unsigned int)v734 ^ (unsigned int)v370, (v734 ^ v370) >> 32) + v503) ^ v383;
  v248 = (v473 + v594) ^ v417;
  v595 = v563 + v242;
  LODWORD(v453) = v248 >> 24;
  LODWORD(v370) = v247 >> 24;
  HIDWORD(v453) = HIBYTE(HIDWORD(v248)) | ((_DWORD)v248 << 8);
  v249 = (v563 + v242) ^ v429;
  LODWORD(v383) = v249 >> 16;
  HIDWORD(v370) = HIBYTE(HIDWORD(v247)) | ((_DWORD)v247 << 8);
  HIDWORD(v383) = HIWORD(HIDWORD(v249)) | ((_DWORD)v249 << 16);
  v564 = v734 + v797 + v370;
  v504 = __PAIR64__(v783, HIDWORD(v783));
  v714 = v713 + v453;
  v784 = __PAIR64__(v783, HIDWORD(v783)) + v659;
  v532 = v383 + v531;
  LODWORD(v429) = (__int64)(v564 ^ v359) >> 16;
  LODWORD(v217) = (__int64)(v714 ^ v473) >> 16;
  LODWORD(v417) = (2 * (v532 ^ v242)) | ((unsigned int)((v532 ^ v242) >> 32) >> 31);
  HIDWORD(v417) = (__int64)(v532 ^ v242) >> 31;
  HIDWORD(v429) = ((unsigned int)(HIDWORD(v564) ^ HIDWORD(v359)) >> 16)
                | (((unsigned int)v564 ^ (unsigned int)v359) << 16);
  HIDWORD(v217) = ((unsigned int)((v714 ^ v473) >> 32) >> 16) | (((unsigned int)v714 ^ (unsigned int)v473) << 16);
  v627 = v429 + v626;
  LODWORD(v473) = (__int64)(v784 ^ v400) >> 24;
  HIDWORD(v473) = ((unsigned int)((v784 ^ v400) >> 32) >> 24) | (((unsigned int)v784 ^ (unsigned int)v400) << 8);
  v660 = v217 + v685;
  v250 = (v217 + v685) ^ v453;
  v251 = v759 + v795 + v473;
  v252 = v627 ^ v370;
  HIDWORD(v359) = v250 >> 31;
  v253 = (2 * (v627 ^ v370)) | ((unsigned int)((v627 ^ v370) >> 32) >> 31);
  v254 = v251 ^ v504;
  LODWORD(v359) = (2 * v250) | (HIDWORD(v250) >> 31);
  v255 = (v564 + v798 + v417) ^ v217;
  LODWORD(v370) = (__int64)(v251 ^ v504) >> 16;
  v505 = __PAIR64__(v255, HIDWORD(v255));
  HIDWORD(v370) = HIWORD(HIDWORD(v254)) | ((_DWORD)v254 << 16);
  HIDWORD(v400) = v252 >> 31;
  LODWORD(v400) = v253;
  v686 = __PAIR64__(v255, HIDWORD(v255)) + v370 + v784;
  v454 = (2 * ((v370 + v784) ^ v473)) | ((unsigned int)(((v370 + v784) ^ v473) >> 32) >> 31);
  v735 = v251 + v791 + v359;
  v715 = v714 + v797 + v400;
  v596 = v595 + v800 + v454;
  LODWORD(v255) = (__int64)(v686 ^ v417) >> 24;
  v384 = v735 ^ v383;
  HIDWORD(v255) = ((unsigned int)((v686 ^ v417) >> 32) >> 24) | (((unsigned int)v686 ^ (unsigned int)v417) << 8);
  v256 = v596 ^ v429;
  v565 = v564 + v798 + v417 + v794 + v255;
  v785 = v735 + v795;
  v430 = __PAIR64__((unsigned int)v715 ^ (unsigned int)v370, (v715 ^ v370) >> 32);
  v760 = v715 + v796;
  HIDWORD(v473) = v384;
  LODWORD(v384) = HIDWORD(v256);
  HIDWORD(v417) = ((unsigned int)((v565 ^ v505) >> 32) >> 16) | (((unsigned int)v565 ^ (unsigned int)v505) << 16);
  HIDWORD(v251) = HIDWORD(v384);
  v736 = v596 + v792;
  HIDWORD(v384) = v256;
  LODWORD(v473) = HIDWORD(v251);
  LODWORD(v417) = (__int64)(v565 ^ v505) >> 16;
  v597 = v417 + v686;
  v257 = (v473 + v627) ^ v359;
  v533 = __PAIR64__((unsigned int)v715 ^ (unsigned int)v370, (v715 ^ v370) >> 32) + v532;
  v258 = (v384 + v660) ^ v454;
  LODWORD(v454) = v257 >> 24;
  v259 = v255 ^ (v417 + v686);
  LODWORD(v370) = (2 * v259) | (HIDWORD(v259) >> 31);
  HIDWORD(v370) = v259 >> 31;
  LODWORD(v251) = v258 >> 24;
  HIDWORD(v251) = HIBYTE(HIDWORD(v258)) | ((_DWORD)v258 << 8);
  HIDWORD(v454) = HIBYTE(HIDWORD(v257)) | ((_DWORD)v257 << 8);
  LODWORD(v359) = (v533 ^ v400) >> 24;
  HIDWORD(v359) = ((unsigned int)((v533 ^ (unsigned __int64)v400) >> 32) >> 24) | (((unsigned int)v533 ^ v253) << 8);
  v260 = (v785 + v454) ^ v473;
  v401 = __PAIR64__(
           ((unsigned int)(((v736 + v251) ^ v384) >> 32) >> 16)
         | ((((_DWORD)v736 + (_DWORD)v251) ^ (unsigned int)v384) << 16),
           (__int64)((v736 + v251) ^ v384) >> 16);
  v261 = (v715 + v796 + v359) ^ v430;
  LODWORD(v254) = v260 >> 16;
  HIDWORD(v254) = HIWORD(HIDWORD(v260)) | ((_DWORD)v260 << 16);
  LODWORD(v430) = v261 >> 16;
  HIDWORD(v430) = HIWORD(HIDWORD(v261)) | ((_DWORD)v261 << 16);
  v506 = __PAIR64__(
           ((unsigned int)(((v736 + v251) ^ v384) >> 32) >> 16)
         | ((((_DWORD)v736 + (_DWORD)v251) ^ (unsigned int)v384) << 16),
           (__int64)((v736 + v251) ^ v384) >> 16)
       + v384
       + v660;
  v687 = v254 + v473 + v627;
  v262 = (v736 + v251 + v805 + v370) ^ v254;
  LODWORD(v384) = (2 * (v506 ^ v251)) | ((unsigned int)((v506 ^ v251) >> 32) >> 31);
  v263 = v430 + v533;
  v534 = __PAIR64__(v262, HIDWORD(v262)) + v430 + v533;
  v264 = __PAIR64__(v262, HIDWORD(v262));
  HIDWORD(v384) = (__int64)(v506 ^ v251) >> 31;
  v265 = v263 ^ v359;
  LODWORD(v262) = (__int64)(v534 ^ v370) >> 24;
  HIDWORD(v262) = ((unsigned int)((v534 ^ v370) >> 32) >> 24) | (((unsigned int)v534 ^ (unsigned int)v370) << 8);
  v266 = v736 + v251 + v805 + v370 + v801;
  LODWORD(v370) = (2 * (v687 ^ v454)) | ((unsigned int)((v687 ^ v454) >> 32) >> 31);
  v716 = v266 + v262;
  LODWORD(v473) = (__int64)((v266 + v262) ^ v264) >> 16;
  HIDWORD(v473) = ((unsigned int)((v716 ^ v264) >> 32) >> 16) | (((unsigned int)v716 ^ (unsigned int)v264) << 16);
  HIDWORD(v370) = (__int64)(v687 ^ v454) >> 31;
  v535 = v473 + v534;
  v267 = v785 + v454;
  v455 = v565 + v799;
  v268 = v262 ^ v535;
  v269 = v267 + v803 + v384;
  v270 = v760 + v359 + v793 + v370;
  v628 = v269 + v790;
  LODWORD(v359) = (2 * v268) | (HIDWORD(v268) >> 31);
  v271 = v269 ^ v430;
  v418 = v270 ^ v417;
  v566 = v270 + v802;
  v431 = __PAIR64__(v271, HIDWORD(v271));
  HIDWORD(v359) = v268 >> 31;
  v272 = (__PAIR64__(v271, HIDWORD(v271)) + v597) ^ v384;
  LODWORD(v270) = (2 * v265) | (HIDWORD(v265) >> 31);
  v598 = __PAIR64__(v271, HIDWORD(v271)) + v597;
  LODWORD(v264) = v272 >> 24;
  HIDWORD(v270) = v265 >> 31;
  HIDWORD(v264) = HIBYTE(HIDWORD(v272)) | ((_DWORD)v272 << 8);
  v737 = v455 + v270 + v804;
  v661 = v628 + v264;
  LODWORD(v271) = ((v455 + v270) ^ v401) >> 32;
  HIDWORD(v271) = (v455 + v270) ^ v401;
  v456 = v271 + v687;
  v273 = (v628 + v264) ^ v431;
  v385 = __PAIR64__(v418, HIDWORD(v418));
  v274 = v270 ^ (v271 + v687);
  v629 = __PAIR64__(v418, HIDWORD(v418)) + v506;
  LODWORD(v401) = v274 >> 24;
  HIDWORD(v401) = HIBYTE(HIDWORD(v274)) | ((_DWORD)v274 << 8);
  v275 = (__PAIR64__(v418, HIDWORD(v418)) + v506) ^ v370;
  HIDWORD(v431) = HIWORD(HIDWORD(v273)) | ((_DWORD)v273 << 16);
  LODWORD(v431) = v273 >> 16;
  LODWORD(v418) = v275 >> 24;
  HIDWORD(v273) = HIBYTE(HIDWORD(v275)) | ((_DWORD)v275 << 8);
  v276 = (v737 + v401) ^ v271;
  v688 = v431 + v598;
  HIDWORD(v418) = HIDWORD(v273);
  v567 = v566 + v418;
  v371 = (2 * ((v431 + v598) ^ v264)) | ((unsigned int)(((v431 + v598) ^ v264) >> 32) >> 31);
  v277 = v737 + v401 + v792 + v359;
  HIDWORD(v264) = HIWORD(HIDWORD(v276)) | ((_DWORD)v276 << 16);
  v278 = v716 + v790 + v371;
  HIDWORD(v271) = ((unsigned int)(HIDWORD(v567) ^ HIDWORD(v385)) >> 16)
                | (((unsigned int)v567 ^ (unsigned int)v385) << 16);
  v279 = v276 >> 16;
  v599 = __PAIR64__(HIDWORD(v264), v279) + v456;
  v280 = (__int64)(v567 ^ v385) >> 16;
  v689 = __PAIR64__(v280 ^ (unsigned int)v277, HIDWORD(v271) ^ HIDWORD(v277)) + v688;
  v457 = __PAIR64__(v279 ^ (unsigned int)v278, HIDWORD(v264) ^ HIDWORD(v278));
  HIDWORD(v385) = (__int64)(v599 ^ v401) >> 31;
  v281 = (__PAIR64__(HIDWORD(v271), v280) + v629) ^ v418;
  v630 = __PAIR64__(v279 ^ (unsigned int)v278, HIDWORD(v264) ^ HIDWORD(v278)) + __PAIR64__(HIDWORD(v271), v280) + v629;
  LODWORD(v385) = (2 * (v599 ^ v401)) | ((unsigned int)((v599 ^ v401) >> 32) >> 31);
  LODWORD(v418) = (__int64)(v630 ^ v371) >> 24;
  v717 = v567 + v794 + v385;
  LODWORD(v264) = (__int64)(v689 ^ v359) >> 24;
  HIDWORD(v264) = ((unsigned int)((v689 ^ v359) >> 32) >> 24) | (((unsigned int)v689 ^ (unsigned int)v359) << 8);
  HIDWORD(v418) = ((unsigned int)((v630 ^ v371) >> 32) >> 24) | (((unsigned int)v630 ^ (unsigned int)v371) << 8);
  v568 = v277 + v793 + v264;
  LODWORD(v401) = (2 * v281) | (HIDWORD(v281) >> 31);
  HIDWORD(v401) = v281 >> 31;
  v282 = v278 + v791 + v418;
  v283 = v568 ^ __PAIR64__(v280 ^ (unsigned int)v277, HIDWORD(v271) ^ HIDWORD(v277));
  v284 = v717 ^ v431;
  LODWORD(v431) = v283 >> 16;
  HIDWORD(v431) = HIWORD(HIDWORD(v283)) | ((_DWORD)v283 << 16);
  v285 = v282 ^ v457;
  v690 = v431 + v689;
  HIDWORD(v283) = ((unsigned int)v282 ^ (unsigned int)v457) >> 16;
  v458 = __PAIR64__(v284, HIDWORD(v284));
  LODWORD(v371) = HIDWORD(v283) | (HIDWORD(v285) << 16);
  HIDWORD(v371) = HIWORD(HIDWORD(v285)) | ((_DWORD)v285 << 16);
  v536 = __PAIR64__(v284, HIDWORD(v284)) + v535;
  v507 = v371 + v630;
  HIDWORD(v359) = (__int64)(v690 ^ v264) >> 31;
  v738 = v717 + v795;
  LODWORD(v359) = (2 * (v690 ^ v264)) | ((unsigned int)((v690 ^ v264) >> 32) >> 31);
  v286 = v661 + v796 + v401;
  v287 = (v371 + v630) ^ v418;
  v662 = v286 + v797;
  v288 = v286 ^ v473;
  v289 = __PAIR64__(v288, HIDWORD(v288));
  v631 = v282 + v798 + v359;
  v761 = v568 + v800;
  v718 = v631 + v799;
  v600 = __PAIR64__(v288, HIDWORD(v288)) + v599;
  LODWORD(v282) = (2 * v287) | (HIDWORD(v287) >> 31);
  HIDWORD(v282) = v287 >> 31;
  v290 = (__int64)(v536 ^ v385) >> 24;
  HIDWORD(v385) = ((unsigned int)((v536 ^ v385) >> 32) >> 24) | (((unsigned int)v536 ^ (unsigned int)v385) << 8);
  LODWORD(v385) = v290;
  LODWORD(v418) = (__int64)(v600 ^ v401) >> 24;
  HIDWORD(v418) = ((unsigned int)((v600 ^ v401) >> 32) >> 24) | (((unsigned int)v600 ^ (unsigned int)v401) << 8);
  v291 = (v738 + v385) ^ v458;
  v292 = (v662 + v418) ^ v289;
  v402 = v662 + v418 + v804;
  LODWORD(v264) = v291 >> 16;
  HIDWORD(v264) = HIWORD(HIDWORD(v291)) | ((_DWORD)v291 << 16);
  LODWORD(v285) = v292 >> 16;
  HIDWORD(v285) = HIWORD(HIDWORD(v292)) | ((_DWORD)v292 << 16);
  v474 = v264 + v536;
  v569 = (v402 + v282) ^ v264;
  v459 = v285 + v600;
  v786 = v402 + v282 + v805;
  v403 = (2 * ((v264 + v536) ^ v385)) | ((unsigned int)(((v264 + v536) ^ v385) >> 32) >> 31);
  LODWORD(v289) = (2 * (v459 ^ v418)) | ((unsigned int)((v459 ^ v418) >> 32) >> 31);
  HIDWORD(v289) = (__int64)((v285 + v600) ^ v418) >> 31;
  v293 = v738 + v385 + v802;
  v294 = __PAIR64__((unsigned int)v285 ^ (unsigned int)v631, (v285 ^ v631) >> 32);
  v632 = v761 + v403 + v801;
  v475 = v294 + v474;
  v295 = (v293 + v289) ^ v431;
  v432 = __PAIR64__(v295, HIDWORD(v295));
  v663 = v293 + v289 + v803;
  v372 = __PAIR64__((v761 + v403) ^ v371, ((v761 + v403) ^ (unsigned __int64)v371) >> 32);
  HIDWORD(v385) = ((unsigned int)((v475 ^ v359) >> 32) >> 24) | (((unsigned int)v475 ^ (unsigned int)v359) << 8);
  LODWORD(v385) = (__int64)(v475 ^ v359) >> 24;
  v601 = v372 + v459;
  v537 = __PAIR64__(v295, HIDWORD(v295)) + v507;
  v360 = __PAIR64__(v569, HIDWORD(v569));
  v296 = v372 + v459;
  v460 = v718 + v385;
  v297 = v296 ^ v403;
  v570 = __PAIR64__(v569, HIDWORD(v569)) + v690;
  v298 = v570 ^ v282;
  v299 = v537 ^ v289;
  v300 = (v718 + v385) ^ v294;
  LODWORD(v403) = v300 >> 16;
  HIDWORD(v403) = HIWORD(HIDWORD(v300)) | ((_DWORD)v300 << 16);
  LODWORD(v294) = v297 >> 24;
  LODWORD(v282) = v299 >> 24;
  LODWORD(v718) = v298 >> 24;
  v476 = v403 + v475;
  HIDWORD(v294) = HIBYTE(HIDWORD(v297)) | ((_DWORD)v297 << 8);
  HIDWORD(v282) = HIBYTE(HIDWORD(v299)) | ((_DWORD)v299 << 8);
  HIDWORD(v718) = HIBYTE(HIDWORD(v298)) | ((_DWORD)v298 << 8);
  v508 = v632 + v294;
  v633 = v663 + v282;
  LODWORD(v418) = (2 * (v476 ^ v385)) | ((unsigned int)((v476 ^ v385) >> 32) >> 31);
  HIDWORD(v418) = (__int64)(v476 ^ v385) >> 31;
  v301 = (v663 + v282) ^ v432;
  LODWORD(v385) = (__int64)(v508 ^ v372) >> 16;
  v302 = (v786 + v718) ^ v360;
  HIDWORD(v385) = ((unsigned int)((v508 ^ v372) >> 32) >> 16) | (((unsigned int)v508 ^ (unsigned int)v372) << 16);
  LODWORD(v372) = v301 >> 16;
  HIDWORD(v372) = HIWORD(HIDWORD(v301)) | ((_DWORD)v301 << 16);
  LODWORD(v360) = v302 >> 16;
  v602 = v385 + v601;
  HIDWORD(v360) = HIWORD(HIDWORD(v302)) | ((_DWORD)v302 << 16);
  v538 = v372 + v537;
  v303 = v538 ^ v282;
  v304 = v508 + v794 + v418;
  LODWORD(v432) = (2 * v303) | (HIDWORD(v303) >> 31);
  HIDWORD(v432) = v303 >> 31;
  v742 = __PAIR64__((unsigned int)v304 ^ (unsigned int)v372, (v304 ^ v372) >> 32);
  HIDWORD(v768) = (__int64)(v602 ^ v294) >> 31;
  LODWORD(v768) = (2 * (v602 ^ v294)) | ((unsigned int)((v602 ^ v294) >> 32) >> 31);
  LODWORD(v738) = (2 * ((v360 + v570) ^ v718)) | ((unsigned int)(((v360 + v570) ^ v718) >> 32) >> 31);
  v373 = __PAIR64__((unsigned int)v304 ^ (unsigned int)v372, (v304 ^ v372) >> 32) + v360 + v570;
  HIDWORD(v738) = (__int64)((v360 + v570) ^ v718) >> 31;
  v305 = v403;
  v404 = v460 + v804 + v738;
  v306 = (v786 + v718 + v803 + v432) ^ v305;
  v307 = (v633 + v799 + v768) ^ v360;
  LODWORD(v300) = (__int64)(v373 ^ v418) >> 24;
  HIDWORD(v300) = ((unsigned int)((v373 ^ v418) >> 32) >> 24) | (((unsigned int)v373 ^ (unsigned int)v418) << 8);
  v308 = v404 ^ v385;
  v386 = v304 + v798 + v300;
  v770 = __PAIR64__(v306, HIDWORD(v306));
  v509 = v786 + v718 + v803 + v432 + v796;
  v772 = __PAIR64__(v308, HIDWORD(v308));
  v765 = __PAIR64__(
           ((unsigned int)((v386 ^ v742) >> 32) >> 16) | (((unsigned int)v386 ^ (unsigned int)v742) << 16),
           (__int64)(v386 ^ v742) >> 16);
  v571 = __PAIR64__(v307, HIDWORD(v307));
  v309 = (__PAIR64__(v306, HIDWORD(v306)) + v602) ^ v432;
  v310 = (v772 + v538) ^ v738;
  v433 = __PAIR64__(v307, HIDWORD(v307)) + v476;
  v419 = __PAIR64__(
           ((unsigned int)((v386 ^ v742) >> 32) >> 16) | (((unsigned int)v386 ^ (unsigned int)v742) << 16),
           (__int64)(v386 ^ v742) >> 16)
       + v373;
  v311 = (__PAIR64__(v307, HIDWORD(v307)) + v476) ^ v768;
  v312 = v300
       ^ (__PAIR64__(
            ((unsigned int)((v386 ^ v742) >> 32) >> 16) | (((unsigned int)v386 ^ (unsigned int)v742) << 16),
            (__int64)(v386 ^ v742) >> 16)
        + v373);
  LODWORD(v738) = (2 * v312) | (HIDWORD(v312) >> 31);
  v477 = v386 + v790;
  HIDWORD(v738) = v312 >> 31;
  LODWORD(v745) = v310 >> 24;
  HIDWORD(v745) = HIBYTE(HIDWORD(v310)) | ((_DWORD)v310 << 8);
  LODWORD(v747) = v311 >> 24;
  v313 = v404 + v800 + v745;
  HIDWORD(v747) = HIBYTE(HIDWORD(v311)) | ((_DWORD)v311 << 8);
  v314 = v313 + v791;
  v315 = v313 ^ v772;
  v387 = v509 + __PAIR64__(HIBYTE(HIDWORD(v309)) | ((_DWORD)v309 << 8), v309 >> 24);
  v405 = v633 + v799 + v768 + v805 + v747;
  v316 = (v509 + __PAIR64__(HIBYTE(HIDWORD(v309)) | ((_DWORD)v309 << 8), v309 >> 24)) ^ v770;
  v317 = v314 + v738;
  LODWORD(v763) = v315 >> 16;
  HIDWORD(v763) = HIWORD(HIDWORD(v315)) | ((_DWORD)v315 << 16);
  v374 = v317 + v802;
  LODWORD(v311) = v316 >> 16;
  v318 = v772 + v538;
  HIDWORD(v311) = HIWORD(HIDWORD(v316)) | ((_DWORD)v316 << 16);
  LODWORD(v772) = (__int64)(v405 ^ v571) >> 16;
  HIDWORD(v772) = ((unsigned int)((v405 ^ v571) >> 32) >> 16) | (((unsigned int)v405 ^ (unsigned int)v571) << 16);
  v319 = v317 ^ v311;
  v320 = v311 + v770 + v602;
  v771 = v763 + v318;
  v767 = v320;
  v321 = (v763 + v318) ^ v745;
  v322 = v320 ^ __PAIR64__(HIBYTE(HIDWORD(v309)) | ((_DWORD)v309 << 8), v309 >> 24);
  v743 = __PAIR64__(v319, HIDWORD(v319)) + v772 + v433;
  LODWORD(v768) = (2 * v321) | (HIDWORD(v321) >> 31);
  v323 = (v772 + v433) ^ v747;
  HIDWORD(v768) = v321 >> 31;
  v324 = (2 * v322) | (HIDWORD(v322) >> 31);
  LODWORD(v745) = (2 * v323) | (HIDWORD(v323) >> 31);
  LODWORD(v762) = (__int64)(v743 ^ v738) >> 24;
  HIDWORD(v762) = ((unsigned int)((v743 ^ v738) >> 32) >> 24) | (((unsigned int)v743 ^ (unsigned int)v738) << 8);
  HIDWORD(v322) = v322 >> 31;
  HIDWORD(v745) = v323 >> 31;
  LODWORD(v322) = (v374 + v762) ^ HIDWORD(v319);
  HIDWORD(v738) = HIDWORD(v322);
  HIDWORD(v322) = ((unsigned __int64)(v374 + v762) >> 32) ^ v319;
  LODWORD(v738) = v324;
  v806 = v374 + v762;
  LODWORD(v323) = v322 >> 16;
  HIDWORD(v323) = HIWORD(HIDWORD(v322)) | ((_DWORD)v322 << 16);
  v748 = __PAIR64__((v477 + v745) ^ v763, ((v477 + v745) ^ v763) >> 32);
  v325 = v323 + v743;
  v814[7] = v323;
  v744 = __PAIR64__((v477 + v745) ^ v763, ((v477 + v745) ^ v763) >> 32) + v767;
  v388 = v387 + v795;
  v775 = v325 ^ v762;
  result = 8;
  v814[2] = v325;
  v327 = v405 + v801 + v738;
  v776 = (v388 + v768) ^ v772;
  LODWORD(v325) = (__int64)((__PAIR64__((v477 + v745) ^ v763, ((v477 + v745) ^ v763) >> 32) + v767) ^ v745) >> 24;
  HIDWORD(v325) = ((unsigned int)((v744 ^ v745) >> 32) >> 24) | (((unsigned int)v744 ^ (unsigned int)v745) << 8);
  HIDWORD(v763) = v327 ^ v765;
  v328 = __PAIR64__(v776, HIDWORD(v776));
  LODWORD(v763) = (v327 ^ v765) >> 32;
  v766 = v763 + v771;
  v774 = __PAIR64__(v776, HIDWORD(v776)) + v419;
  v807 = v477 + v745 + v792 + v325;
  v329 = (v763 + v771) ^ v738;
  v330 = __PAIR64__(v776, HIDWORD(v776)) + v419;
  LODWORD(v776) = v329 >> 24;
  v331 = v330 ^ v768;
  LODWORD(v787) = v331 >> 24;
  HIDWORD(v787) = HIBYTE(HIDWORD(v331)) | ((_DWORD)v331 << 8);
  HIDWORD(v776) = HIBYTE(HIDWORD(v329)) | ((_DWORD)v329 << 8);
  v808 = v327 + v797 + v776;
  v809 = v388 + v768 + v793 + v787;
  v746 = __PAIR64__(
           ((unsigned int)((v807 ^ v748) >> 32) >> 16)
         | ((((_DWORD)v477 + (_DWORD)v745 + (_DWORD)v792 + (_DWORD)v325) ^ (unsigned int)v748) << 16),
           (__int64)(v807 ^ v748) >> 16);
  v332 = v809 ^ v328;
  v814[3] = v746 + v744;
  LODWORD(v768) = (__int64)(v809 ^ v328) >> 16;
  v764 = __PAIR64__(
           ((unsigned int)((v808 ^ v763) >> 32) >> 16) | (((unsigned int)v808 ^ (unsigned int)v763) << 16),
           (__int64)(v808 ^ v763) >> 16);
  v333 = (v746 + v744) ^ v325;
  HIDWORD(v768) = HIWORD(HIDWORD(v332)) | ((_DWORD)v332 << 16);
  v334 = v764 + v766;
  LODWORD(v811) = (2 * v775) | (HIDWORD(v775) >> 31);
  v814[1] = v768 + v774;
  v335 = (v764 + v766) ^ v776;
  HIDWORD(v811) = v775 >> 31;
  v336 = (v768 + v774) ^ v787;
  LODWORD(v812) = (2 * v333) | (HIDWORD(v333) >> 31);
  v814[4] = v746;
  LODWORD(v813) = (2 * v335) | (HIDWORD(v335) >> 31);
  HIDWORD(v812) = v333 >> 31;
  HIDWORD(v813) = v335 >> 31;
  LODWORD(v810) = (2 * v336) | (HIDWORD(v336) >> 31);
  v814[5] = v764;
  v814[0] = v764 + v766;
  v814[6] = v768;
  HIDWORD(v810) = v336 >> 31;
  v337 = (_QWORD *)a1;
  v338 = v374 + v762;
  v339 = &v806;
  for ( i = v814; ; ++i )
  {
    --result;
    *v337++ ^= v338 ^ v334;
    if ( !result )
      break;
    v341 = v339[1];
    ++v339;
    v338 = v341;
    v342 = i[1];
    v334 = v342;
  }
  return result;
}
