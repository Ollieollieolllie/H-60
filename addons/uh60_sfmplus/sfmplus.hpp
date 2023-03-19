class vtx_SfmPlus {
    emptyMass  = 5896;//kg

    stabPos[]  = {0.0, -7.041, -0.084};
    stabWidth  = 4.18;  //m
    stabLength = 1.18; //m

    forcePos[] = {0.0, 0.0, 2.0};

    maxTank1FuelMass = 547; //1206lbs in kg
    maxTank2FuelMass = 547; //1206lbs in kg
    maxTank3FuelMass = 607;  //1340lbs in kg, center robbie
    //maxExtFuelMass = 690; //1541lbs in kg, not yet implemented, 230gal external tank

    //Engine Data
    engSimTime  = 8.0;

    engIdleTQ   = 0.07;
    engFlyTQ    = 0.20;

    engStartNG  = 0.23;
    engIdleNG   = 0.679;
    engFlyNG    = 0.834;
    engMaxNG    = 1.04;

    engStartNP  = 0.10;
    engIdleNP   = 0.52;
    engFlyNP    = 1.00;

    //----------------0-NG-----1-TGT----2-TQ----3-NP----4-Oil
    engBaseTable[] =  {{0.000,    0,  0.00,  0.00,  0.00},    //Off
                         {0.262,      3,  0.01,  0.00,  0.01},  
                         {0.318,    244,  0.015,  0.00,  0.11},
                         {0.355,    339,  0.02,  0.00,  0.19},
                         {0.407,    435,  0.025,  0.00,  0.25},
                         {0.455,    513,  0.03,  0.00,  0.29},
                         {0.548,    622,  0.035,  0.01,  0.38},
                         {0.643,    678,  0.04,  0.02,  0.41},
                         {0.670,    582,  0.045,  0.03,  0.48},
                         {0.672,    565,  0.05,  0.12,  0.51},
                         {0.675,    530,  0.055,  0.20,  0.58},
                         {0.677,    505,  0.06,  0.37,  0.62},
                         {0.679,    500,  0.07,  0.52,  0.70},    //Idle
                         {0.698,    525,  0.10,  0.55,  0.71},
                         {0.718,    550,  0.12,  0.63,  0.73},
                         {0.737,    566,  0.14,  0.67,  0.77},
                         {0.757,    564,  0.16,  0.71,  0.81},
                         {0.776,    571,  0.17,  0.78,  0.82},
                         {0.795,    552,  0.18,  0.82,  0.84},
                         {0.815,    546,  0.19,  0.95,  0.86},
                         {0.834,    541,  0.20,  1.00,  0.88}};      //Fly

    //--------------------GWT---IGE---OGE--
    hvrTqTable[] =      {{5443,  0.43, 0.51},  //12000lbs
                         {5897,  0.45, 0.55},  //13000lbs
                         {6350,  0.48, 0.59},  //14000lbs
                         {6804,  0.52, 0.64},  //15000lbs
                         {7257,  0.56, 0.69},  //16000lbs
                         {7711,  0.60, 0.74},   //17000lbs
                         {8165,  0.64, 0.80},  //18000lbs
                         {8618,  0.68, 0.85},  //19000lbs
                         {9072,  0.72, 0.92},  //20000lbs
                         {9525,  0.78, 0.98},   //21000lbs
                         {9979,  0.82, 1.05},   //22000lbs
                         {10433, 0.86, 1.13},  //23000lbs
                         {14000, 1.66, 2.06}};  //31000lbs

    //--------------------GWT----24kt--40kt--60kt--70kt--90kt--100kt-120kt-130kt-150kt
    cruiseTable[] =      {{5897,  0.40, 0.34, 0.32, 0.32, 0.36, 0.39, 0.50, 0.57, 0.82},  //13000lbs
                         {7257,  0.50, 0.42, 0.38, 0.38, 0.41, 0.44, 0.54, 0.62, 0.86},  //16000lbs
                         {7711,  0.58, 0.49, 0.44, 0.42, 0.44, 0.48, 0.58, 0.65, 0.90},  //18000lbs
                         {8618,  0.66, 0.56, 0.48, 0.47, 0.48, 0.51, 0.61, 0.69, 0.94},  //20000lbs
                         {9525,  0.76, 0.63, 0.54, 0.52, 0.54, 0.56, 0.66, 0.74, 1.00},  //22000lbs
                         {10433, 0.81, 0.67, 0.58, 0.56, 0.56, 0.59, 0.69, 0.77, 1.05}, //23000lbs
                         {14000, 1.73, 1.33, 1.12, 1.08, 1.11, 1.20, 1.63, 1.97, 2.83}}; //31000lbs

    //--------------------TQ----FF (kg/s)
    engFFTable[]  =     {{0.00, 0.0000},
                         {0.07, 0.0216},
                         {0.15, 0.0350},
                         {0.30, 0.0454},
                         {0.40, 0.0517},
                         {0.50, 0.0576},
                         {0.60, 0.0636},
                         {0.70, 0.0699},
                         {0.80, 0.0762},
                         {0.90, 0.0832},
                         {1.00, 0.0898},
                         {1.10, 0.0970},
                         {1.20, 0.1052},
                         {1.30, 0.1134},
                         {1.40, 0.1222}};

    //Stabilator Data
    stabKeyTheta = -8.0;

    //--------------------Coll----30kts--70kts--130kts-150kts
    stabTable[] =       {{0.00,  -42.00,  0.0,    0.0,   0.0},  
                         {0.67,  -42.00, -1.2,   -1.2,  -1.2},  
                         {0.87,  -42.00, -8.6,   -8.6,  -8.6},
                         {0.93,  -42.00, -10.2, -10.2, -10.2}};

    stabAirfoilTable[] =    //NACA 0012 Airfoil
    {
    //------AoA-{0}----------CL-{1}--------CD-{2}-------------
        {   -180.0,        0.0,           0.0        },  //0  - DO NOT CHANGE!!
        {   -135.0,        0.5,           0.5        },  //1  - DO NOT CHANGE!!
        {   -90.0,         0.0,           0.0        },  //2  - DO NOT CHANGE!!
        {   -18.5,         -1.22580,      0.10236    },  //3  -
        {   -17.5,         -1.30310,      0.07429    },  //4  -
        {   -15.75,        -1.38680,      0.03865    },  //5  -
        {   -10.0,         -1.08070,      0.01499    },  //6  -
        {   -5.0,          -0.55710,      0.00847    },  //7  -
        {   0.0,           0.00000,       0.00540    },  //8  -
        {   5.0,           0.55720,       0.00847    },  //9  -
        {   10.0,          1.08080,       0.01499    },  //10 -
        {   15.75,         1.38810,       0.03863    },  //11 -
        {   17.5,          1.30590,       0.07416    },  //12 -
        {   18.5,          1.22840,       0.10229    },  //13 -
        {   90.0,          0.0,           0.0        },  //14 - DO NOT CHANGE!!
        {   135.0,         -0.5,          -0.5       },  //15 - DO NOT CHANGE!!
        {   180.0,         0.0,           0.0        }   //16 - DO NOT CHANGE!!
    };
};