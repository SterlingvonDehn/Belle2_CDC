# Setup a minimal environment to build and run the examples

setenv GARFIELD_INSTALL /Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/install
setenv CMAKE_PREFIX_PATH /Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/install:${CMAKE_PREFIX_PATH}
setenv HEED_DATABASE ${GARFIELD_INSTALL}/share/Heed/database
setenv LD_LIBRARY_PATH ${GARFIELD_INSTALL}/lib:${LD_LIBRARY_PATH}
setenv PYTHONPATH ${GARFIELD_INSTALL}/lib/python3.12/site-packages/:${PYTHONPATH}
