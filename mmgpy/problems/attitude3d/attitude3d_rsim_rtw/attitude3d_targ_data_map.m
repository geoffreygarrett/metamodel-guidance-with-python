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
	
	  ;% rtP.NormalizeVector_maxzero_m
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.NormalizeVector1_maxzero_i
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.NormalizeVector_maxzero_o
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.NormalizeVector1_maxzero_c
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.NormalizeVector_maxzero_e
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.NormalizeVector1_maxzero_e
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.NormalizeVector_maxzero_f
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.NormalizeVector1_maxzero_c1
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.NormalizeVector_maxzero_p
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.NormalizeVector1_maxzero_d
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.NormalizeVector_maxzero_j
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.NormalizeVector1_maxzero_g
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.Constant_Value
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.Constant_Value_c
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.Constant_Value_b
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.Constant_Value_k
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.Constant_Value_p
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.Gain1_Gain
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.Gain1_Gain_i
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 23;
	
	  ;% rtP.Gain1_Gain_f
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 27;
	
	  ;% rtP.Constant_Value_o
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 31;
	
	  ;% rtP.Constant_Value_pb
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 32;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 33;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 34;
	
	  ;% rtP.Constant_Value_oj
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 35;
	
	  ;% rtP.Gain1_Gain_m
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 36;
	
	  ;% rtP.Constant_Value_i
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 40;
	
	  ;% rtP.Constant_Value_pw
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 41;
	
	  ;% rtP.Saturation_UpperSat_o
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 42;
	
	  ;% rtP.Saturation_LowerSat_p
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 43;
	
	  ;% rtP.Constant10_Value
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 44;
	
	  ;% rtP.Gain1_Gain_j
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 45;
	
	  ;% rtP.Constant_Value_kd
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 46;
	
	  ;% rtP.Constant_Value_g
	  section.data(36).logicalSrcIdx = 38;
	  section.data(36).dtTransOffset = 47;
	
	  ;% rtP.Constant11_Value
	  section.data(37).logicalSrcIdx = 39;
	  section.data(37).dtTransOffset = 48;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates
	  section.data(38).logicalSrcIdx = 40;
	  section.data(38).dtTransOffset = 49;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients
	  section.data(39).logicalSrcIdx = 41;
	  section.data(39).dtTransOffset = 50;
	
	  ;% rtP.Constant10_Value_p
	  section.data(40).logicalSrcIdx = 42;
	  section.data(40).dtTransOffset = 110;
	
	  ;% rtP.Gain1_Gain_l
	  section.data(41).logicalSrcIdx = 43;
	  section.data(41).dtTransOffset = 111;
	
	  ;% rtP.Constant_Value_bu
	  section.data(42).logicalSrcIdx = 44;
	  section.data(42).dtTransOffset = 112;
	
	  ;% rtP.Constant_Value_ov
	  section.data(43).logicalSrcIdx = 45;
	  section.data(43).dtTransOffset = 113;
	
	  ;% rtP.Constant11_Value_f
	  section.data(44).logicalSrcIdx = 46;
	  section.data(44).dtTransOffset = 114;
	
	  ;% rtP.DiscreteFIRFilter_InitialStat_i
	  section.data(45).logicalSrcIdx = 47;
	  section.data(45).dtTransOffset = 115;
	
	  ;% rtP.DiscreteFIRFilter_Coefficient_n
	  section.data(46).logicalSrcIdx = 48;
	  section.data(46).dtTransOffset = 116;
	
	  ;% rtP.Constant_Value_b5
	  section.data(47).logicalSrcIdx = 49;
	  section.data(47).dtTransOffset = 176;
	
	  ;% rtP.Integrator1_IC
	  section.data(48).logicalSrcIdx = 50;
	  section.data(48).dtTransOffset = 177;
	
	  ;% rtP.Constant_Value_ok
	  section.data(49).logicalSrcIdx = 51;
	  section.data(49).dtTransOffset = 178;
	
	  ;% rtP.Integrator1_IC_k
	  section.data(50).logicalSrcIdx = 52;
	  section.data(50).dtTransOffset = 179;
	
	  ;% rtP.Constant9_Value
	  section.data(51).logicalSrcIdx = 53;
	  section.data(51).dtTransOffset = 180;
	
	  ;% rtP.Integrator2_IC
	  section.data(52).logicalSrcIdx = 54;
	  section.data(52).dtTransOffset = 181;
	
	  ;% rtP.Integrator1_IC_b
	  section.data(53).logicalSrcIdx = 55;
	  section.data(53).dtTransOffset = 182;
	
	  ;% rtP.Gain1_Gain_fe
	  section.data(54).logicalSrcIdx = 56;
	  section.data(54).dtTransOffset = 183;
	
	  ;% rtP.Constant_Value_f
	  section.data(55).logicalSrcIdx = 57;
	  section.data(55).dtTransOffset = 187;
	
	  ;% rtP.Gain1_Gain_m4
	  section.data(56).logicalSrcIdx = 58;
	  section.data(56).dtTransOffset = 188;
	
	  ;% rtP.Constant_Value_gd
	  section.data(57).logicalSrcIdx = 59;
	  section.data(57).dtTransOffset = 192;
	
	  ;% rtP.Gain1_Gain_n
	  section.data(58).logicalSrcIdx = 60;
	  section.data(58).dtTransOffset = 193;
	
	  ;% rtP.Constant_Value_m
	  section.data(59).logicalSrcIdx = 61;
	  section.data(59).dtTransOffset = 197;
	
	  ;% rtP.Constant_Value_bp
	  section.data(60).logicalSrcIdx = 62;
	  section.data(60).dtTransOffset = 198;
	
	  ;% rtP.Gain_Gain
	  section.data(61).logicalSrcIdx = 63;
	  section.data(61).dtTransOffset = 199;
	
	  ;% rtP.Constant_Value_i2
	  section.data(62).logicalSrcIdx = 64;
	  section.data(62).dtTransOffset = 200;
	
	  ;% rtP.Constant_Value_bf
	  section.data(63).logicalSrcIdx = 65;
	  section.data(63).dtTransOffset = 201;
	
	  ;% rtP.Constant11_Value_h
	  section.data(64).logicalSrcIdx = 66;
	  section.data(64).dtTransOffset = 202;
	
	  ;% rtP.Constant_Value_os
	  section.data(65).logicalSrcIdx = 67;
	  section.data(65).dtTransOffset = 203;
	
	  ;% rtP.Constant_Value_n
	  section.data(66).logicalSrcIdx = 68;
	  section.data(66).dtTransOffset = 204;
	
	  ;% rtP.Saturation_UpperSat_e
	  section.data(67).logicalSrcIdx = 69;
	  section.data(67).dtTransOffset = 205;
	
	  ;% rtP.Saturation_LowerSat_n
	  section.data(68).logicalSrcIdx = 70;
	  section.data(68).dtTransOffset = 206;
	
	  ;% rtP.Constant11_Value_hv
	  section.data(69).logicalSrcIdx = 71;
	  section.data(69).dtTransOffset = 207;
	
	  ;% rtP.Constant_Value_ku
	  section.data(70).logicalSrcIdx = 72;
	  section.data(70).dtTransOffset = 208;
	
	  ;% rtP.Constant_Value_l
	  section.data(71).logicalSrcIdx = 73;
	  section.data(71).dtTransOffset = 209;
	
	  ;% rtP.Saturation_UpperSat_l
	  section.data(72).logicalSrcIdx = 74;
	  section.data(72).dtTransOffset = 210;
	
	  ;% rtP.Saturation_LowerSat_pj
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
	
	  ;% rtP.ManualSwitch1_CurrentSetting_k
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
      
	  ;% rtB.E
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% rtB.Gain1
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.Product
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtB.Saturation
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 7;
	
	  ;% rtB.min_exclusion
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 8;
	
	  ;% rtB.Acos
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 9;
	
	  ;% rtB.Product_i
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtB.Saturation_i
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 13;
	
	  ;% rtB.min_exclusion_m
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 14;
	
	  ;% rtB.Acos_i
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 15;
	
	  ;% rtB.Switch
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 16;
	
	  ;% rtB.Switch_a
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 17;
	
	  ;% rtB.Divide
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 18;
	
	  ;% rtB.Divide_i
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 19;
	
	  ;% rtB.Switch_c
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 20;
	
	  ;% rtB.integral_pointing
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 21;
	
	  ;% rtB.Divide_b
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 22;
	
	  ;% rtB.thrust_vector
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 23;
	
	  ;% rtB.thrust_weight
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 26;
	
	  ;% rtB.solar_occulted_integral
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 27;
	
	  ;% rtB.solar_occulted_boolean
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 28;
	
	  ;% rtB.comms_occulted_integral
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 29;
	
	  ;% rtB.comms_occulted_boolean
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 30;
	
	  ;% rtB.r_s
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 31;
	
	  ;% rtB.v_s
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 34;
	
	  ;% rtB.r_c
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 37;
	
	  ;% rtB.v_c
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 40;
	
	  ;% rtB.r_t
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 43;
	
	  ;% rtB.v_t
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 46;
	
	  ;% rtB.Product_o
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 49;
	
	  ;% rtB.Product_a
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 52;
	
	  ;% rtB.Product_d
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 55;
	
	  ;% rtB.q_dot
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 58;
	
	  ;% rtB.DotProduct1
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 62;
	
	  ;% rtB.ManualSwitch1
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 63;
	
	  ;% rtB.current_solar_e
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 64;
	
	  ;% rtB.ManualSwitch1_c
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 65;
	
	  ;% rtB.current_solar_e_p
	  section.data(37).logicalSrcIdx = 37;
	  section.data(37).dtTransOffset = 66;
	
	  ;% rtB.current_solar_e_pn
	  section.data(38).logicalSrcIdx = 38;
	  section.data(38).dtTransOffset = 67;
	
	  ;% rtB.Clock1
	  section.data(39).logicalSrcIdx = 39;
	  section.data(39).dtTransOffset = 68;
	
	  ;% rtB.y
	  section.data(40).logicalSrcIdx = 40;
	  section.data(40).dtTransOffset = 69;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.Compare
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.MovingMaximum_p.MovingMaximum
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.MovingMaximum.MovingMaximum
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.MovingMinimum_p.MovingMinimum
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.MovingMinimum.MovingMinimum
	  section.data(1).logicalSrcIdx = 45;
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
      
	  ;% rtDW.DiscreteFIRFilter_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.DiscreteFIRFilter_states_k
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 59;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtDW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.FromFile13_PWORK.PrevTimePtr
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 9;
	
	  ;% rtDW.Scope3_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 21;
	
	  ;% rtDW.Scope5_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 22;
	
	  ;% rtDW.Scope1_PWORK_o.LoggedData
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 27;
	
	  ;% rtDW.Scope2_PWORK_o.LoggedData
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 28;
	
	  ;% rtDW.Scope3_PWORK_n.LoggedData
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 29;
	
	  ;% rtDW.Scope6_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 30;
	
	  ;% rtDW.Scope1_PWORK_k.LoggedData
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 31;
	
	  ;% rtDW.Scope2_PWORK_i.LoggedData
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 32;
	
	  ;% rtDW.Scope3_PWORK_e.LoggedData
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 33;
	
	  ;% rtDW.Scope6_PWORK_l.LoggedData
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 34;
	
	  ;% rtDW.Scope4_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 35;
	
	  ;% rtDW.Scope6_PWORK_c.LoggedData
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 36;
	
	  ;% rtDW.Scope7_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 37;
	
	  ;% rtDW.Scope8_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 38;
	
	  ;% rtDW.Scope9_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 39;
	
	  ;% rtDW.Scope6_PWORK_e.LoggedData
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 40;
	
	  ;% rtDW.Scope_PWORK_b.LoggedData
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMaximum_p.obj
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.MovingMaximum_p.gobj_0
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.MovingMaximum_p.gobj_1
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMaximum_p.objisempty
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMaximum.obj
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.MovingMaximum.gobj_0
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.MovingMaximum.gobj_1
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMaximum.objisempty
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_p.obj
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_p.gobj_0
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.MovingMinimum_p.gobj_1
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum_p.objisempty
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum.obj
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum.gobj_0
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.MovingMinimum.gobj_1
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.MovingMinimum.objisempty
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


  targMap.checksum0 = 846969622;
  targMap.checksum1 = 3598695172;
  targMap.checksum2 = 2962041261;
  targMap.checksum3 = 1529343573;

