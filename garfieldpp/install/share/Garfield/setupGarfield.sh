# Setup a minimal environment to build and run the examples

export GARFIELD_INSTALL=/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/install
export CMAKE_PREFIX_PATH=/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/install:$CMAKE_PREFIX_PATH
export HEED_DATABASE=$GARFIELD_INSTALL/share/Heed/database
export LD_LIBRARY_PATH=$GARFIELD_INSTALL/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$GARFIELD_INSTALL/lib/python3.12/site-packages/:$PYTHONPATH
