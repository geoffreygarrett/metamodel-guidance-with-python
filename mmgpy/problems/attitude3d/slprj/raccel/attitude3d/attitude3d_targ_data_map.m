  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.P_E
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.P_F
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.P_X
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 73;
      section.data(73)  = dumData; %prealloc
      
	  ;% rtP.NormalizeVector_maxzero
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.NormalizeVector1_maxzero
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.NormalizeVector_maxzero_mt13upuc30
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.NormalizeVector1_maxzero_it3sz44pnw
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.NormalizeVector_maxzero_oczsk3pynm
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.NormalizeVector1_maxzero_curh4i254k
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.NormalizeVector_maxzero_ektzry0otc
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.NormalizeVector1_maxzero_esmeewv013
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.NormalizeVector_maxzero_frofudci2i
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.NormalizeVector1_maxzero_c1jmgth0uc
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.NormalizeVector_maxzero_p3wnqley4p
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.NormalizeVector1_maxzero_d0tqs3zyle
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.NormalizeVector_maxzero_jv521hznkv
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.NormalizeVector1_maxzero_gagywgljsc
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.Constant_Value
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.Constant_Value_c4d4ozwwzr
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.Constant_Value_bpciai0igk
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.Constant_Value_kw5w4qkv5v
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.Gain1_Gain
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.Gain1_Gain_i0dny2tgg4
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 22;
	
	  ;% rtP.Gain1_Gain_f3zo2a45h3
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 26;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 30;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 31;
	
	  ;% rtP.Gain1_Gain_mglm2i5i2e
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 32;
	
	  ;% rtP.Saturation_UpperSat_o0tu1knjb5
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 36;
	
	  ;% rtP.Saturation_LowerSat_pjt1p3frof
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 37;
	
	  ;% rtP.Gain1_Gain_jasbtnac0r
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 38;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 39;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 40;
	
	  ;% rtP.Gain1_Gain_luip00ayzb
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 100;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates_igm30wm5ib
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 101;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients_n1yfwntl03
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 102;
	
	  ;% rtP.Integrator1_IC
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 162;
	
	  ;% rtP.Integrator1_IC_khgln1fz0y
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 163;
	
	  ;% rtP.Integrator2_IC
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 164;
	
	  ;% rtP.Integrator1_IC_bdymfb0f54
	  section.data(36).logicalSrcIdx = 38;
	  section.data(36).dtTransOffset = 165;
	
	  ;% rtP.Gain1_Gain_fe1rn1jbbk
	  section.data(37).logicalSrcIdx = 39;
	  section.data(37).dtTransOffset = 166;
	
	  ;% rtP.Gain1_Gain_m4frltiumm
	  section.data(38).logicalSrcIdx = 40;
	  section.data(38).dtTransOffset = 170;
	
	  ;% rtP.Gain1_Gain_nu325gvdxx
	  section.data(39).logicalSrcIdx = 41;
	  section.data(39).dtTransOffset = 174;
	
	  ;% rtP.Gain_Gain
	  section.data(40).logicalSrcIdx = 42;
	  section.data(40).dtTransOffset = 178;
	
	  ;% rtP.Saturation_UpperSat_ex5fckh1e5
	  section.data(41).logicalSrcIdx = 43;
	  section.data(41).dtTransOffset = 179;
	
	  ;% rtP.Saturation_LowerSat_nqfyaemvcp
	  section.data(42).logicalSrcIdx = 44;
	  section.data(42).dtTransOffset = 180;
	
	  ;% rtP.Saturation_UpperSat_laawyukirp
	  section.data(43).logicalSrcIdx = 45;
	  section.data(43).dtTransOffset = 181;
	
	  ;% rtP.Saturation_LowerSat_pjistqqcmw
	  section.data(44).logicalSrcIdx = 46;
	  section.data(44).dtTransOffset = 182;
	
	  ;% rtP.Constant_Value_bpuwj1x24m
	  section.data(45).logicalSrcIdx = 47;
	  section.data(45).dtTransOffset = 183;
	
	  ;% rtP.Constant_Value_p5yqgecpys
	  section.data(46).logicalSrcIdx = 48;
	  section.data(46).dtTransOffset = 184;
	
	  ;% rtP.Constant_Value_pblczk22x1
	  section.data(47).logicalSrcIdx = 49;
	  section.data(47).dtTransOffset = 185;
	
	  ;% rtP.Constant_Value_ojxmxt5mmf
	  section.data(48).logicalSrcIdx = 50;
	  section.data(48).dtTransOffset = 186;
	
	  ;% rtP.Constant_Value_pwofnawzxn
	  section.data(49).logicalSrcIdx = 51;
	  section.data(49).dtTransOffset = 187;
	
	  ;% rtP.Constant10_Value
	  section.data(50).logicalSrcIdx = 52;
	  section.data(50).dtTransOffset = 188;
	
	  ;% rtP.Constant11_Value
	  section.data(51).logicalSrcIdx = 53;
	  section.data(51).dtTransOffset = 189;
	
	  ;% rtP.Constant_Value_kd4xr3zjvz
	  section.data(52).logicalSrcIdx = 54;
	  section.data(52).dtTransOffset = 190;
	
	  ;% rtP.Constant_Value_gspoitvpf3
	  section.data(53).logicalSrcIdx = 55;
	  section.data(53).dtTransOffset = 191;
	
	  ;% rtP.Constant10_Value_pnntlgrkfl
	  section.data(54).logicalSrcIdx = 56;
	  section.data(54).dtTransOffset = 192;
	
	  ;% rtP.Constant11_Value_fak2wrhghj
	  section.data(55).logicalSrcIdx = 57;
	  section.data(55).dtTransOffset = 193;
	
	  ;% rtP.Constant_Value_bu2n4z0wwl
	  section.data(56).logicalSrcIdx = 58;
	  section.data(56).dtTransOffset = 194;
	
	  ;% rtP.Constant_Value_ovccxkrnjy
	  section.data(57).logicalSrcIdx = 59;
	  section.data(57).dtTransOffset = 195;
	
	  ;% rtP.Constant_Value_o2fro3xhzj
	  section.data(58).logicalSrcIdx = 60;
	  section.data(58).dtTransOffset = 196;
	
	  ;% rtP.Constant_Value_i2bviibqa1
	  section.data(59).logicalSrcIdx = 61;
	  section.data(59).dtTransOffset = 197;
	
	  ;% rtP.Constant_Value_mgesvrfwfg
	  section.data(60).logicalSrcIdx = 62;
	  section.data(60).dtTransOffset = 198;
	
	  ;% rtP.Constant_Value_gdyff4hfxx
	  section.data(61).logicalSrcIdx = 63;
	  section.data(61).dtTransOffset = 199;
	
	  ;% rtP.Constant_Value_fcyoyjujtb
	  section.data(62).logicalSrcIdx = 64;
	  section.data(62).dtTransOffset = 200;
	
	  ;% rtP.Constant11_Value_howgtgmefa
	  section.data(63).logicalSrcIdx = 65;
	  section.data(63).dtTransOffset = 201;
	
	  ;% rtP.Constant9_Value
	  section.data(64).logicalSrcIdx = 66;
	  section.data(64).dtTransOffset = 202;
	
	  ;% rtP.Constant_Value_i2ujud0fea
	  section.data(65).logicalSrcIdx = 67;
	  section.data(65).dtTransOffset = 203;
	
	  ;% rtP.Constant_Value_bfz3r5ve34
	  section.data(66).logicalSrcIdx = 68;
	  section.data(66).dtTransOffset = 204;
	
	  ;% rtP.Constant_Value_ok5wcdghto
	  section.data(67).logicalSrcIdx = 69;
	  section.data(67).dtTransOffset = 205;
	
	  ;% rtP.Constant11_Value_hvpxwvfqmk
	  section.data(68).logicalSrcIdx = 70;
	  section.data(68).dtTransOffset = 206;
	
	  ;% rtP.Constant_Value_osq1m5ngw5
	  section.data(69).logicalSrcIdx = 71;
	  section.data(69).dtTransOffset = 207;
	
	  ;% rtP.Constant_Value_n5p1mlb1zj
	  section.data(70).logicalSrcIdx = 72;
	  section.data(70).dtTransOffset = 208;
	
	  ;% rtP.Constant_Value_b54p1uwprt
	  section.data(71).logicalSrcIdx = 73;
	  section.data(71).dtTransOffset = 209;
	
	  ;% rtP.Constant_Value_kubckzbqj3
	  section.data(72).logicalSrcIdx = 74;
	  section.data(72).dtTransOffset = 210;
	
	  ;% rtP.Constant_Value_lfkufjj3ic
	  section.data(73).logicalSrcIdx = 75;
	  section.data(73).dtTransOffset = 211;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ManualSwitch1_CurrentSetting_kps3rcsvpl
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    nTotSects     = 7;
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
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ggl2c42ej4
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% rtB.j3dtcamj3h
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.gwuhy1m1pb
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtB.ksb54aeynf
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 7;
	
	  ;% rtB.lbvs2uyceq
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 8;
	
	  ;% rtB.bv1kuls22a
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 9;
	
	  ;% rtB.i1cpfgl4ur
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtB.b13j3pqall
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 13;
	
	  ;% rtB.p2owgzs2iz
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 14;
	
	  ;% rtB.adp4h11fxy
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 15;
	
	  ;% rtB.kla2ie4xqo
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 16;
	
	  ;% rtB.fvvukgofqm
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 17;
	
	  ;% rtB.ocjizknfbp
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 18;
	
	  ;% rtB.hcfehsmczi
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 19;
	
	  ;% rtB.jcjpclbjp2
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 20;
	
	  ;% rtB.aui5mhj44r
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 21;
	
	  ;% rtB.objaac1udz
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 22;
	
	  ;% rtB.njrvjekzfm
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 23;
	
	  ;% rtB.pctj4gwip4
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 26;
	
	  ;% rtB.fpa0aiyozw
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 27;
	
	  ;% rtB.bi23bgkdar
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 28;
	
	  ;% rtB.ozqsycmu2s
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 29;
	
	  ;% rtB.lm0mtopp3u
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 30;
	
	  ;% rtB.ndieoaonxd
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 31;
	
	  ;% rtB.ewt1hyh1w1
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 34;
	
	  ;% rtB.hmkhnfnj2o
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 37;
	
	  ;% rtB.lbe030o5eg
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 40;
	
	  ;% rtB.pu5umgngnw
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 43;
	
	  ;% rtB.nkfoxrkhb4
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 46;
	
	  ;% rtB.kg4dzhebco
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 49;
	
	  ;% rtB.fx1eniibgn
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 52;
	
	  ;% rtB.dbvg0t1pgh
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 55;
	
	  ;% rtB.jwzvety1de
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 58;
	
	  ;% rtB.mgffwko2vy
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 62;
	
	  ;% rtB.p4mnuhzffc
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 63;
	
	  ;% rtB.n5lv0if3fe
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 64;
	
	  ;% rtB.fmpx14rdcd
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 65;
	
	  ;% rtB.haese0mx0t
	  section.data(37).logicalSrcIdx = 37;
	  section.data(37).dtTransOffset = 66;
	
	  ;% rtB.jtzgz1uiwi
	  section.data(38).logicalSrcIdx = 38;
	  section.data(38).dtTransOffset = 67;
	
	  ;% rtB.gdkatceig2
	  section.data(39).logicalSrcIdx = 39;
	  section.data(39).dtTransOffset = 68;
	
	  ;% rtB.hcaghgg2d4
	  section.data(40).logicalSrcIdx = 40;
	  section.data(40).dtTransOffset = 69;
	
	  ;% rtB.id3syu3xda
	  section.data(41).logicalSrcIdx = 41;
	  section.data(41).dtTransOffset = 70;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.bqvggehzz5
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.juzdrgfwywbn.ezrshmdyuk
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.juzdrgfwywb.ezrshmdyuk
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.fbz1lrgadk1o.olimizud5z
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.fbz1lrgadk1.olimizud5z
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
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
    nTotSects     = 15;
    sectIdxOffset = 7;
    
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
      
	  ;% rtDW.nrt1u3ug04
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.nn3mukf4ls
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 59;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtDW.ahlf4oinxv.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.p5wpguxq2t.PrevTimePtr
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ddanh5gylu.LoggedData
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.objy321rh1.LoggedData
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 9;
	
	  ;% rtDW.g4kmj1bu2w.LoggedData
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 21;
	
	  ;% rtDW.fdwjlnvn2h.LoggedData
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 22;
	
	  ;% rtDW.b2rvqw04iy.LoggedData
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 27;
	
	  ;% rtDW.hk1giknb0y.LoggedData
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 28;
	
	  ;% rtDW.ljsijxpkth.LoggedData
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 29;
	
	  ;% rtDW.mkouu2vbc0.LoggedData
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 30;
	
	  ;% rtDW.mn51ahvl50.LoggedData
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 31;
	
	  ;% rtDW.miwmuef3dm.LoggedData
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 32;
	
	  ;% rtDW.lvmw50sr0x.LoggedData
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 33;
	
	  ;% rtDW.c1sznid5dz.LoggedData
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 34;
	
	  ;% rtDW.bs2m1afbbu.LoggedData
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 35;
	
	  ;% rtDW.dikyhxirdn.LoggedData
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 36;
	
	  ;% rtDW.g545csv13p.LoggedData
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 37;
	
	  ;% rtDW.kaytbfj0hw.LoggedData
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 38;
	
	  ;% rtDW.arutvhkvxm.LoggedData
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 39;
	
	  ;% rtDW.i2wgvpy5uh.LoggedData
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 40;
	
	  ;% rtDW.by5wrfdoin.LoggedData
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.ag2rcaep41
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.juzdrgfwywbn.jsyeqj31fa
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.juzdrgfwywbn.aivxxmxdyh
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.juzdrgfwywbn.oethoov3ae
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.juzdrgfwywbn.d1vg1xnbad
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.juzdrgfwywb.jsyeqj31fa
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.juzdrgfwywb.aivxxmxdyh
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.juzdrgfwywb.oethoov3ae
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.juzdrgfwywb.d1vg1xnbad
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fbz1lrgadk1o.bdmeifvj0g
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.fbz1lrgadk1o.kfvrm3e5fw
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fbz1lrgadk1o.ege0j1fhnq
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fbz1lrgadk1o.phxfrbtrrv
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fbz1lrgadk1.bdmeifvj0g
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.fbz1lrgadk1.kfvrm3e5fw
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fbz1lrgadk1.ege0j1fhnq
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fbz1lrgadk1.phxfrbtrrv
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
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


  targMap.checksum0 = 3803236602;
  targMap.checksum1 = 2346542714;
  targMap.checksum2 = 3261620555;
  targMap.checksum3 = 2040919633;

