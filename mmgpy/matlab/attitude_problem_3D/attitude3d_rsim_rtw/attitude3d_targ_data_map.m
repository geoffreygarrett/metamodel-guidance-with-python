  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
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
      section.nData     = 76;
      section.data(76)  = dumData; %prealloc
      
	  ;% rtP.P
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.antenna_vb
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.init_xBI
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtP.init_yBI
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtP.init_zBI
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% rtP.solar_array_vb
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% rtP.star_sensor_1_vb
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% rtP.star_sensor_2_vb
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% rtP.thrust_no_shadow_weight
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 22;
	
	  ;% rtP.thrust_shadow_weight
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 23;
	
	  ;% rtP.thruster_vb
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 24;
	
	  ;% rtP.x_test
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 27;
	
	  ;% rtP.NormalizeVector_maxzero
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 39;
	
	  ;% rtP.NormalizeVector1_maxzero
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 40;
	
	  ;% rtP.NormalizeVector_maxzero_m
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 41;
	
	  ;% rtP.NormalizeVector1_maxzero_i
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 42;
	
	  ;% rtP.NormalizeVector_maxzero_o
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 43;
	
	  ;% rtP.NormalizeVector1_maxzero_c
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 44;
	
	  ;% rtP.NormalizeVector_maxzero_f
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 45;
	
	  ;% rtP.NormalizeVector1_maxzero_c1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 46;
	
	  ;% rtP.NormalizeVector_maxzero_p
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 47;
	
	  ;% rtP.NormalizeVector1_maxzero_d
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 48;
	
	  ;% rtP.NormalizeVector_maxzero_j
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 49;
	
	  ;% rtP.NormalizeVector1_maxzero_g
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 50;
	
	  ;% rtP.Constant_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 51;
	
	  ;% rtP.Constant_Value_e
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 52;
	
	  ;% rtP.Constant_Value_c
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 53;
	
	  ;% rtP.Constant_Value_b
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 54;
	
	  ;% rtP.Constant_Value_k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 55;
	
	  ;% rtP.Constant_Value_b5
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 56;
	
	  ;% rtP.Integrator1_IC
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 57;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 58;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 59;
	
	  ;% rtP.Constant_Value_o
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 63;
	
	  ;% rtP.Integrator1_IC_k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 64;
	
	  ;% rtP.DiscreteFIRFilter_InitialStat_l
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 65;
	
	  ;% rtP.DiscreteFIRFilter_Coefficient_l
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 66;
	
	  ;% rtP.Gain1_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 72;
	
	  ;% rtP.Gain1_Gain_m
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 76;
	
	  ;% rtP.Constant_Value_l
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 80;
	
	  ;% rtP.Gain1_Gain_p
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 81;
	
	  ;% rtP.Constant_Value_d
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 85;
	
	  ;% rtP.Gain1_Gain_i
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 86;
	
	  ;% rtP.Constant_Value_g
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 90;
	
	  ;% rtP.Gain1_Gain_h
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 91;
	
	  ;% rtP.Constant_Value_i
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 95;
	
	  ;% rtP.Gain1_Gain_a
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 96;
	
	  ;% rtP.Constant_Value_bg
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 100;
	
	  ;% rtP.Constant_Value_p
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 101;
	
	  ;% rtP.Constant_Value_pb
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 102;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 103;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 104;
	
	  ;% rtP.Constant_Value_oj
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 105;
	
	  ;% rtP.Constant_Value_pw
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 106;
	
	  ;% rtP.Saturation_UpperSat_o
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 107;
	
	  ;% rtP.Saturation_LowerSat_p
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 108;
	
	  ;% rtP.Constant_Value_kd
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 109;
	
	  ;% rtP.Constant_Value_gs
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 110;
	
	  ;% rtP.Saturation_UpperSat_j
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 111;
	
	  ;% rtP.Saturation_LowerSat_p4
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 112;
	
	  ;% rtP.Constant9_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 113;
	
	  ;% rtP.Integrator2_IC
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 114;
	
	  ;% rtP.Integrator1_IC_b
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 115;
	
	  ;% rtP.Constant_Value_i2
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 116;
	
	  ;% rtP.Constant_Value_bf
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 117;
	
	  ;% rtP.Constant11_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 118;
	
	  ;% rtP.Constant_Value_os
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 119;
	
	  ;% rtP.Constant_Value_n
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 120;
	
	  ;% rtP.Saturation_UpperSat_e
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 121;
	
	  ;% rtP.Saturation_LowerSat_n
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 122;
	
	  ;% rtP.Constant11_Value_h
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 123;
	
	  ;% rtP.Constant_Value_ku
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 124;
	
	  ;% rtP.Constant_Value_lf
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 125;
	
	  ;% rtP.Saturation_UpperSat_l
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 126;
	
	  ;% rtP.Saturation_LowerSat_pj
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 127;
	
	  ;% rtP.Constant11_Value_c
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 128;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ManualSwitch1_CurrentSetting_k
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.ManualSwitch1_CurrentSetting_g
	  section.data(3).logicalSrcIdx = 78;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 44;
      section.data(44)  = dumData; %prealloc
      
	  ;% rtB.r_target
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.r_satellite
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.r_comms
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtB.v_target
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% rtB.v_satellite
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 12;
	
	  ;% rtB.v_comms
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 15;
	
	  ;% rtB.solar_v
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% rtB.integral_solar
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 21;
	
	  ;% rtB.sight_solar
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 22;
	
	  ;% rtB.comms_v
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 23;
	
	  ;% rtB.integral_comms
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 26;
	
	  ;% rtB.sight_comms
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 27;
	
	  ;% rtB.thrust_v_ref
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 28;
	
	  ;% rtB.Divide
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 31;
	
	  ;% rtB.Divide_i
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 32;
	
	  ;% rtB.Product
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 33;
	
	  ;% rtB.Product_f
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 36;
	
	  ;% rtB.Product_b
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 39;
	
	  ;% rtB.Product_k
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 42;
	
	  ;% rtB.Product_p
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 45;
	
	  ;% rtB.Saturation
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 48;
	
	  ;% rtB.min_exclusion
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 49;
	
	  ;% rtB.Acos
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 50;
	
	  ;% rtB.Saturation_i
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 51;
	
	  ;% rtB.min_exclusion_m
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 52;
	
	  ;% rtB.Acos_i
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 53;
	
	  ;% rtB.Saturation_k
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 54;
	
	  ;% rtB.min_exclusion_g
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 55;
	
	  ;% rtB.Acos_i1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 56;
	
	  ;% rtB.Switch
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 57;
	
	  ;% rtB.integral_pointing
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 58;
	
	  ;% rtB.Divide_b
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 59;
	
	  ;% rtB.DotProduct1
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 60;
	
	  ;% rtB.ManualSwitch1
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 61;
	
	  ;% rtB.Switch1
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 62;
	
	  ;% rtB.current_solar_e
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 63;
	
	  ;% rtB.ManualSwitch1_c
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 64;
	
	  ;% rtB.current_solar_e_p
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 65;
	
	  ;% rtB.ManualSwitch1_m
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 66;
	
	  ;% rtB.current_solar_e_pn
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 67;
	
	  ;% rtB.Clock1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 68;
	
	  ;% rtB.qA2B
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 69;
	
	  ;% rtB.y
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 73;
	
	  ;% rtB.q_dot
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.Compare
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.MovingMinimum_pn.MovingMinimum
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.MovingMinimum_p.MovingMinimum
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.MovingMinimum.MovingMinimum
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    nTotSects     = 12;
    sectIdxOffset = 5;
    
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
      
	  ;% rtDW.DiscreteFIRFilter_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.DiscreteFIRFilter_states_d
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% rtDW.FromFile_PWORK.PrevTimePtr
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.FromFile1_PWORK.PrevTimePtr
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.FromFile6_PWORK.PrevTimePtr
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.FromFile7_PWORK.PrevTimePtr
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.FromFile2_PWORK.PrevTimePtr
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.FromFile3_PWORK.PrevTimePtr
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.FromFile4_PWORK.PrevTimePtr
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.FromFile9_PWORK.PrevTimePtr
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.FromFile10_PWORK.PrevTimePtr
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.FromFile11_PWORK.PrevTimePtr
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.FromFile5_PWORK.PrevTimePtr
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.FromFile12_PWORK.PrevTimePtr
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.FromFile8_PWORK.PrevTimePtr
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.Scope_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.Scope1_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 26;
	
	  ;% rtDW.Scope2_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 28;
	
	  ;% rtDW.Scope5_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 30;
	
	  ;% rtDW.Scope_PWORK_g.LoggedData
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 35;
	
	  ;% rtDW.Scope1_PWORK_o.LoggedData
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 37;
	
	  ;% rtDW.Scope2_PWORK_o.LoggedData
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 38;
	
	  ;% rtDW.Scope3_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 39;
	
	  ;% rtDW.Scope6_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 40;
	
	  ;% rtDW.Scope1_PWORK_k.LoggedData
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 41;
	
	  ;% rtDW.Scope2_PWORK_i.LoggedData
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 42;
	
	  ;% rtDW.Scope3_PWORK_e.LoggedData
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 43;
	
	  ;% rtDW.Scope6_PWORK_l.LoggedData
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 44;
	
	  ;% rtDW.Scope1_PWORK_p.LoggedData
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 45;
	
	  ;% rtDW.Scope2_PWORK_a.LoggedData
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 46;
	
	  ;% rtDW.Scope3_PWORK_f.LoggedData
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 47;
	
	  ;% rtDW.Scope6_PWORK_c.LoggedData
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 48;
	
	  ;% rtDW.Scope4_PWORK.LoggedData
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 49;
	
	  ;% rtDW.Scope6_PWORK_cq.LoggedData
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 50;
	
	  ;% rtDW.Scope7_PWORK.LoggedData
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 51;
	
	  ;% rtDW.Scope8_PWORK.LoggedData
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 52;
	
	  ;% rtDW.Scope9_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 53;
	
	  ;% rtDW.Scope6_PWORK_e.LoggedData
	  section.data(36).logicalSrcIdx = 37;
	  section.data(36).dtTransOffset = 54;
	
	  ;% rtDW.Scope6_PWORK_a.LoggedData
	  section.data(37).logicalSrcIdx = 38;
	  section.data(37).dtTransOffset = 55;
	
	  ;% rtDW.Scope_PWORK_b.LoggedData
	  section.data(38).logicalSrcIdx = 39;
	  section.data(38).dtTransOffset = 56;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_pn.obj
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_pn.gobj_0
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.MovingMinimum_pn.gobj_1
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_pn.objisempty
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_p.obj
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_p.gobj_0
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.MovingMinimum_p.gobj_1
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_p.objisempty
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum.obj
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum.gobj_0
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.MovingMinimum.gobj_1
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum.objisempty
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
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


  targMap.checksum0 = 3150072023;
  targMap.checksum1 = 3767935592;
  targMap.checksum2 = 1838606884;
  targMap.checksum3 = 4003405232;

