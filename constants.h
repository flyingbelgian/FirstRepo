#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

namespace convert   //Definition of conversion constants
{
    //all conversion factors sourced from ICAO Annex 5 (Units of Measurements), Attachment C
    double yards{9.144000e-01};     //conversion to meters
    double feet{3.048000e-01};      //conversion to meters
    double degrees{1.745329e-02};   //conversion to radians
}

struct Ellipsoid
{
    double mSemiMajorAxis;
    double ratioInverseFlattening;
};

struct TM //TM stands for Transverse Mercator
{
    double mFalseEasting;
    double mFalseNorthing;
    double factorCentralScale;
    int degreesZoneWidth;
    int degreesMeridianLongitude; //positive for West, negative for East
};

//Ellipsoid and TM data from Redfaerns-Formulae_Convert-LAT+LONG_dl170710.xls file as received from JMC @ StratAir
Ellipsoid GRS80{6378137.0,298.257222101};
Ellipsoid WGS84{6378137.0,298.257223563};
Ellipsoid ANS{6378160.0,298.25};
Ellipsoid CLARKE{6975449.335*convert::yards,294.26};

TM ISG{300000.0,5000000.0,0.99994,2,141};
TM ANG{400000.0*convert::yards,4915813.467*convert::yards,1.0,5,116};

#endif // CONSTANTS_H_INCLUDED
