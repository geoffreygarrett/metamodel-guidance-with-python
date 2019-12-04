  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% rtP.duration
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.env_forest
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.env_mu_s_dry
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtP.env_mu_s_wet
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtP.env_route_length
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtP.env_t_rain_start
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.env_traffic_durations
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.env_traffic_pos
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtP.env_traffic_times
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtP.g
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% rtP.init_position
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtP.vel
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtP.Difference_ICPrevInput
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 23;
	
	  ;% rtP.Integrator_IC
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
	  ;% rtP.Switch_Threshold
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 25;
	
	  ;% rtP.Switch2_Threshold
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 26;
	
	  ;% rtP.Switch_Threshold_hglhrydy3y
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 27;
	
	  ;% rtP.Gain_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 28;
	
	  ;% rtP.Integrator1_IC
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 29;
	
	  ;% rtP.Integrator2_IC
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 30;
	
	  ;% rtP.Switch1_Threshold
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 31;
	
	  ;% rtP.no_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 32;
	
	  ;% rtP.yes_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% rtP.Constant_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% rtP.no1_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% rtP.Constant_Value_ehkhiuseje
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% rtP.Constant_Value_oxokqz1erg
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37;
	
	  ;% rtP.no_Value_eq3lkpaxhu
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 38;
	
	  ;% rtP.reaction_time_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 39;
	
	  ;% rtP.Constant_Value_kyz3xktxbl
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 40;
	
	  ;% rtP.Constant1_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 41;
	
	  ;% rtP.Constant2_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 42;
	
	  ;% rtP.Constant3_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 43;
	
	  ;% rtP.Constant4_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 44;
	
	  ;% rtP.Constant_Value_jqzxbewhqx
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 59;
      section.data(59)  = dumData; %prealloc
      
	  ;% rtB.kcyp21kc2a
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.dj31gbg42s
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.pr5iwe4db4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.jgw3cnihqn
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.bvtrmm42qq
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.a0vhvlfvrp
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.klvou0jp43
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtB.ft1lwiplkf
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtB.nuq4ebgzji
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% rtB.foohqlhzxj
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtB.jyapjnygey
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtB.hbw1yihztg
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtB.cwg0hry4ws
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtB.prpccjcehp
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtB.oj4ir132kn
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtB.dhkufhyeyq
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtB.eodzgtkr5j
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtB.dvlei2dmhh
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtB.e5a31ttfny
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtB.olssxob2yv
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtB.bk43fv2n4y
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rtB.nge5jnvtgx
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rtB.irfhmm4oof
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% rtB.f5lt2gautr
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% rtB.ixalepcbyn
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% rtB.lz2vzowa3c
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% rtB.h3xadqth0r
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% rtB.a5ewqn2mxx
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% rtB.lvxqtzvles
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% rtB.hlq1tatw2c
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 33;
	
	  ;% rtB.ojsxt052dx
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 34;
	
	  ;% rtB.hydn0gjndu
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% rtB.j5mv5pspvc
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 37;
	
	  ;% rtB.egn3zic0pm
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 39;
	
	  ;% rtB.jbd0xdvrsq
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 41;
	
	  ;% rtB.j4s3bqbxd4
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 42;
	
	  ;% rtB.dage4kxeup
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 43;
	
	  ;% rtB.na4hrtuuyw
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 44;
	
	  ;% rtB.d1jelb2eui
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 45;
	
	  ;% rtB.ovxbrcsfmz
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 46;
	
	  ;% rtB.biki50erxe
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 47;
	
	  ;% rtB.odv2qhzlqg
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 49;
	
	  ;% rtB.f4spskjtp4
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 50;
	
	  ;% rtB.c5fwmfh314
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 51;
	
	  ;% rtB.jmn33aahhq
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 53;
	
	  ;% rtB.czhyu2bg0k
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 55;
	
	  ;% rtB.o2zt0cwv3s
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 57;
	
	  ;% rtB.craf4qjftk
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 58;
	
	  ;% rtB.ifpg5v2co4
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 59;
	
	  ;% rtB.hqjcuxu5y0
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 60;
	
	  ;% rtB.jtpferclbe
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 62;
	
	  ;% rtB.dm0n54sbqj
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 63;
	
	  ;% rtB.l3gkhpvljt
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 65;
	
	  ;% rtB.ixl2ngyssb
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 67;
	
	  ;% rtB.brmok2vfn0
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 68;
	
	  ;% rtB.jpfgqre33f
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 69;
	
	  ;% rtB.iazliuf4fr
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 70;
	
	  ;% rtB.m2q0pua4hf
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 71;
	
	  ;% rtB.edohkr2wul
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 72;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% rtB.dhdvnfqewh
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.erbdt202km
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtB.ntvdgb201d
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtB.o2croyjuf1
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtB.ntwseknv4g
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtB.jwq1epnjmp
	  section.data(6).logicalSrcIdx = 64;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtB.hxqshrzbjb
	  section.data(7).logicalSrcIdx = 65;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtB.erl53vzxd3
	  section.data(8).logicalSrcIdx = 66;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtB.fisvgzk5zv
	  section.data(9).logicalSrcIdx = 67;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtB.nlloggg0bk
	  section.data(10).logicalSrcIdx = 68;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtB.comw5ylrlx
	  section.data(11).logicalSrcIdx = 69;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtB.ece5hhfx4x
	  section.data(12).logicalSrcIdx = 70;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtB.dpka2uzame
	  section.data(13).logicalSrcIdx = 71;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtB.jhgjsl1qel
	  section.data(14).logicalSrcIdx = 72;
	  section.data(14).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pzjd3kuy5m.gm53zhdnh5
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.jdbr35ed4p.gm53zhdnh5
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.fpf3fqle5c.gm53zhdnh5
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.nrszotctkrz.gm53zhdnh5
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 20;
    sectIdxOffset = 6;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.anxd5wnwwf
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jzedrgivtk
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.l4wnyi14fe
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.dukunxirwj
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.pjhwxlxh5o
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.dhfsjbleur
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.o0ozn4wrlb
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.axozqa2z0x.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.p4ifn0i4ms.LoggedData
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtDW.l3axxfz1gt.LoggedData
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 16;
	
	  ;% rtDW.dwr4oeemew.LoggedData
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.bptbpmlejv
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.gvs4eonwop
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.h53kbocvrf
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.pzjd3kuy5m.ohlmpp21yt
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.pzjd3kuy5m.iq234qewu4
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.pzjd3kuy5m.bgtbyci3g4
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.pzjd3kuy5m.oo5zsud5tm
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.jdbr35ed4p.ohlmpp21yt
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jdbr35ed4p.iq234qewu4
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jdbr35ed4p.bgtbyci3g4
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jdbr35ed4p.oo5zsud5tm
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.fpf3fqle5c.ohlmpp21yt
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fpf3fqle5c.iq234qewu4
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fpf3fqle5c.bgtbyci3g4
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fpf3fqle5c.oo5zsud5tm
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.nrszotctkrz.ohlmpp21yt
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.nrszotctkrz.iq234qewu4
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.nrszotctkrz.bgtbyci3g4
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.nrszotctkrz.oo5zsud5tm
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2815083295;
  targMap.checksum1 = 69055812;
  targMap.checksum2 = 3976536213;
  targMap.checksum3 = 588105720;

