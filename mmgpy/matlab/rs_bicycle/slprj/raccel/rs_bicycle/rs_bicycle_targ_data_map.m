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
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
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
	
	  ;% rtP.Difference_ICPrevInput
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtP.Integrator_IC
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtP.Switch_Threshold
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtP.Switch2_Threshold
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtP.Switch_Threshold_hglhrydy3y
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtP.Gain_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtP.Integrator1_IC
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtP.Integrator2_IC
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtP.Switch1_Threshold
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtP.no_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rtP.yes_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rtP.Constant_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% rtP.no1_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% rtP.Constant_Value_ehkhiuseje
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% rtP.Constant_Value_oxokqz1erg
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% rtP.no_Value_eq3lkpaxhu
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% rtP.reaction_time_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% rtP.Constant_Value_kyz3xktxbl
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% rtP.Constant1_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 33;
	
	  ;% rtP.Constant2_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 34;
	
	  ;% rtP.Constant3_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% rtP.Constant4_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 36;
	
	  ;% rtP.Constant_Value_jqzxbewhqx
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 37;
	
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
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
	  ;% rtB.kkii1l5vii
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.pwf3pin41a
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.nmalw2wdvv
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.phpmeo4o31
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.arnwhbdsjr
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.letet25bjg
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.cuq4s4xyta
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtB.fkudo4yvzg
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtB.lfuqpkbv4w
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% rtB.gjgjxuamsb
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtB.owlwvra5lv
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtB.koludsbdn4
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtB.nd3novo4e2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtB.crugzyhjzg
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtB.pnpnetosep
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtB.kky4swrkln
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtB.pwzgbqhmlu
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtB.nfix4prp31
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtB.mjipwiwsab
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtB.mg4tkrdzya
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtB.dny1ckhqrw
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rtB.gwzzjj2332
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rtB.agcm0t1jl3
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% rtB.bmrbqdn4ib
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% rtB.mgtwfogikl
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% rtB.na1xsgoign
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% rtB.kliqr4bqad
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% rtB.lqzb33ramg
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% rtB.j2ranx3eff
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% rtB.eb5o55xhxk
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 33;
	
	  ;% rtB.lmtgic4fhp
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 34;
	
	  ;% rtB.mg4fdmac5p
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 36;
	
	  ;% rtB.lhn2pokn3p
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 38;
	
	  ;% rtB.bba5tmuhaa
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 40;
	
	  ;% rtB.nvdetxb5tx
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 41;
	
	  ;% rtB.ddyto5b4zd
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 42;
	
	  ;% rtB.gddvi424wr
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 43;
	
	  ;% rtB.k3z3m3ldej
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 44;
	
	  ;% rtB.ipe2ymqves
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 45;
	
	  ;% rtB.pusu00yrcw
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 46;
	
	  ;% rtB.e5n35j2niw
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 48;
	
	  ;% rtB.lb31uoepla
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 49;
	
	  ;% rtB.dxa2fe4h5d
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 50;
	
	  ;% rtB.cfti4gkgoy
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 52;
	
	  ;% rtB.nmxegffgia
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 54;
	
	  ;% rtB.eph0u45qky
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 56;
	
	  ;% rtB.nngc4xyghd
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 57;
	
	  ;% rtB.fvmipg4lrj
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 58;
	
	  ;% rtB.ouatgm5wlm
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 59;
	
	  ;% rtB.itak35c1xz
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 61;
	
	  ;% rtB.omdnrdnywn
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 62;
	
	  ;% rtB.erbk25hexb
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 64;
	
	  ;% rtB.gjhcrpjjk2
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 66;
	
	  ;% rtB.g14mvqcdge
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 67;
	
	  ;% rtB.pviusfxiyr
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 68;
	
	  ;% rtB.e3mvbvmzx4
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 69;
	
	  ;% rtB.ic2bkjstr3
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 70;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% rtB.di5jcafytx
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.odelljfi5g
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtB.lmdphncnhd
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtB.lavjegxa0s
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtB.k5yjkklppp
	  section.data(5).logicalSrcIdx = 61;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtB.gqyvdicpar
	  section.data(6).logicalSrcIdx = 62;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtB.n30pv2m1ci
	  section.data(7).logicalSrcIdx = 63;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtB.mssb2m5uof
	  section.data(8).logicalSrcIdx = 64;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtB.ei3l4cdp3l
	  section.data(9).logicalSrcIdx = 65;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtB.jkqihkxsof
	  section.data(10).logicalSrcIdx = 66;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtB.pn4bqsppqd
	  section.data(11).logicalSrcIdx = 67;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtB.lwwvvar4jx
	  section.data(12).logicalSrcIdx = 68;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtB.nivlobgrcv
	  section.data(13).logicalSrcIdx = 69;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtB.gllg0oiz3l
	  section.data(14).logicalSrcIdx = 70;
	  section.data(14).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.cq1wd4pu5m.ipdergl1q3
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.it0b4crh0a.ipdergl1q3
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.jfaynsbq1z.ipdergl1q3
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.c351hegycsd.ipdergl1q3
	  section.data(1).logicalSrcIdx = 74;
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
      
	  ;% rtDW.gqwdiipwrj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bcimcwmolr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.azlvoaxn1v
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gdlg4sgpor
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.ifjz2d2ffr
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.o5o3u4ixzs
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.odnmi54ao0
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.g3n5clq5yl.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.nennjmvryo.LoggedData
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtDW.a1vj5lhw2w.LoggedData
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 16;
	
	  ;% rtDW.gsgtf5x3u2.LoggedData
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.eufiybe1pc
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.pchqaf4hz2
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.l4xuf0ayh1
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.cq1wd4pu5m.aviewp3bz1
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.cq1wd4pu5m.ita2zzwqtk
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cq1wd4pu5m.bu2jbgsv15
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cq1wd4pu5m.pumqcfxdvo
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.it0b4crh0a.aviewp3bz1
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.it0b4crh0a.ita2zzwqtk
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.it0b4crh0a.bu2jbgsv15
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.it0b4crh0a.pumqcfxdvo
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.jfaynsbq1z.aviewp3bz1
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jfaynsbq1z.ita2zzwqtk
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jfaynsbq1z.bu2jbgsv15
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jfaynsbq1z.pumqcfxdvo
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.c351hegycsd.aviewp3bz1
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.c351hegycsd.ita2zzwqtk
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.c351hegycsd.bu2jbgsv15
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.c351hegycsd.pumqcfxdvo
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


  targMap.checksum0 = 551039131;
  targMap.checksum1 = 168430918;
  targMap.checksum2 = 238321069;
  targMap.checksum3 = 1733840132;

