import ROOT
import os, sys

path = '/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/install/lib'
if sys.platform == 'darwin':
  ROOT.gSystem.Load(path + '/libmagboltz.dylib')
  ROOT.gSystem.Load(path + '/libdegrade.dylib')
  ROOT.gSystem.Load(path + '/libGarfield.dylib')
else:
  ROOT.gSystem.Load(path + '/libmagboltz.so')
  ROOT.gSystem.Load(path + '/libdegrade.so')
  ROOT.gSystem.Load(path + '/libGarfield.so')
