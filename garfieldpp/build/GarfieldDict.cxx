// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME GarfieldDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "Garfield/AvalancheGrid.hh"
#include "Garfield/AvalancheMC.hh"
#include "Garfield/AvalancheMicroscopic.hh"
#include "Garfield/Component.hh"
#include "Garfield/ComponentAnalyticField.hh"
#include "Garfield/ComponentAnsys121.hh"
#include "Garfield/ComponentAnsys123.hh"
#include "Garfield/ComponentCST.hh"
#include "Garfield/ComponentComsol.hh"
#include "Garfield/ComponentConstant.hh"
#include "Garfield/ComponentElmer.hh"
#include "Garfield/ComponentElmer2d.hh"
#include "Garfield/ComponentFieldMap.hh"
#include "Garfield/ComponentGrid.hh"
#include "Garfield/ComponentNeBem2d.hh"
#include "Garfield/ComponentNeBem3d.hh"
#include "Garfield/ComponentNeBem3dMap.hh"
#include "Garfield/ComponentParallelPlate.hh"
#include "Garfield/ComponentTcad2d.hh"
#include "Garfield/ComponentTcad3d.hh"
#include "Garfield/ComponentTcadBase.hh"
#include "Garfield/ComponentUser.hh"
#include "Garfield/ComponentVoxel.hh"
#include "Garfield/DegradeInterface.hh"
#include "Garfield/DriftLineRKF.hh"
#include "Garfield/FundamentalConstants.hh"
#include "Garfield/GarfieldConstants.hh"
#include "Garfield/Geometry.hh"
#include "Garfield/GeometryRoot.hh"
#include "Garfield/GeometrySimple.hh"
#include "Garfield/KDTree.hh"
#include "Garfield/MagboltzInterface.hh"
#include "Garfield/Medium.hh"
#include "Garfield/MediumCdTe.hh"
#include "Garfield/MediumConductor.hh"
#include "Garfield/MediumDiamond.hh"
#include "Garfield/MediumGaAs.hh"
#include "Garfield/MediumGaN.hh"
#include "Garfield/MediumGas.hh"
#include "Garfield/MediumMagboltz.hh"
#include "Garfield/MediumPlastic.hh"
#include "Garfield/MediumSilicon.hh"
#include "Garfield/Numerics.hh"
#include "Garfield/OpticalData.hh"
#include "Garfield/Plotting.hh"
#include "Garfield/PlottingEngine.hh"
#include "Garfield/Polygon.hh"
#include "Garfield/QuadTree.hh"
#include "Garfield/Random.hh"
#include "Garfield/RandomEngine.hh"
#include "Garfield/RandomEngineRoot.hh"
#include "Garfield/Sensor.hh"
#include "Garfield/Shaper.hh"
#include "Garfield/Solid.hh"
#include "Garfield/SolidBox.hh"
#include "Garfield/SolidExtrusion.hh"
#include "Garfield/SolidHole.hh"
#include "Garfield/SolidRidge.hh"
#include "Garfield/SolidSphere.hh"
#include "Garfield/SolidTube.hh"
#include "Garfield/SolidWire.hh"
#include "Garfield/TGeoTet.hh"
#include "Garfield/TetrahedralTree.hh"
#include "Garfield/Track.hh"
#include "Garfield/TrackBichsel.hh"
#include "Garfield/TrackDegrade.hh"
#include "Garfield/TrackElectron.hh"
#include "Garfield/TrackHeed.hh"
#include "Garfield/TrackPAI.hh"
#include "Garfield/TrackSimple.hh"
#include "Garfield/TrackSrim.hh"
#include "Garfield/TrackTrim.hh"
#include "Garfield/Utilities.hh"
#include "Garfield/ViewBase.hh"
#include "Garfield/ViewCell.hh"
#include "Garfield/ViewDrift.hh"
#include "Garfield/ViewFEMesh.hh"
#include "Garfield/ViewField.hh"
#include "Garfield/ViewGeometry.hh"
#include "Garfield/ViewIsochrons.hh"
#include "Garfield/ViewMedium.hh"
#include "Garfield/ViewSignal.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace Garfield {
   namespace ROOTDict {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *Garfield_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("Garfield", 0 /*version*/, "Garfield/GarfieldConstants.hh", 5,
                     ::ROOT::Internal::DefineBehavior((void*)nullptr,(void*)nullptr),
                     &Garfield_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *Garfield_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *GarfieldcLcLMedium_Dictionary();
   static void GarfieldcLcLMedium_TClassManip(TClass*);
   static void *new_GarfieldcLcLMedium(void *p = nullptr);
   static void *newArray_GarfieldcLcLMedium(Long_t size, void *p);
   static void delete_GarfieldcLcLMedium(void *p);
   static void deleteArray_GarfieldcLcLMedium(void *p);
   static void destruct_GarfieldcLcLMedium(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::Medium*)
   {
      ::Garfield::Medium *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::Medium));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::Medium", "Garfield/Medium.hh", 16,
                  typeid(::Garfield::Medium), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMedium_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::Medium), alignof(::Garfield::Medium) );
      instance.SetNew(&new_GarfieldcLcLMedium);
      instance.SetNewArray(&newArray_GarfieldcLcLMedium);
      instance.SetDelete(&delete_GarfieldcLcLMedium);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMedium);
      instance.SetDestructor(&destruct_GarfieldcLcLMedium);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::Medium*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::Medium*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::Medium*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMedium_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::Medium*>(nullptr))->GetClass();
      GarfieldcLcLMedium_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMedium_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolid_Dictionary();
   static void GarfieldcLcLSolid_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolid(void *p);
   static void deleteArray_GarfieldcLcLSolid(void *p);
   static void destruct_GarfieldcLcLSolid(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::Solid*)
   {
      ::Garfield::Solid *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::Solid));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::Solid", "Garfield/Solid.hh", 28,
                  typeid(::Garfield::Solid), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolid_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::Solid), alignof(::Garfield::Solid) );
      instance.SetDelete(&delete_GarfieldcLcLSolid);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolid);
      instance.SetDestructor(&destruct_GarfieldcLcLSolid);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::Solid*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::Solid*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::Solid*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolid_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::Solid*>(nullptr))->GetClass();
      GarfieldcLcLSolid_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolid_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLGeometry_Dictionary();
   static void GarfieldcLcLGeometry_TClassManip(TClass*);
   static void delete_GarfieldcLcLGeometry(void *p);
   static void deleteArray_GarfieldcLcLGeometry(void *p);
   static void destruct_GarfieldcLcLGeometry(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::Geometry*)
   {
      ::Garfield::Geometry *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::Geometry));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::Geometry", "Garfield/Geometry.hh", 13,
                  typeid(::Garfield::Geometry), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLGeometry_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::Geometry), alignof(::Garfield::Geometry) );
      instance.SetDelete(&delete_GarfieldcLcLGeometry);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLGeometry);
      instance.SetDestructor(&destruct_GarfieldcLcLGeometry);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::Geometry*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::Geometry*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::Geometry*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLGeometry_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::Geometry*>(nullptr))->GetClass();
      GarfieldcLcLGeometry_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLGeometry_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponent_Dictionary();
   static void GarfieldcLcLComponent_TClassManip(TClass*);
   static void delete_GarfieldcLcLComponent(void *p);
   static void deleteArray_GarfieldcLcLComponent(void *p);
   static void destruct_GarfieldcLcLComponent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::Component*)
   {
      ::Garfield::Component *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::Component));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::Component", "Garfield/Component.hh", 13,
                  typeid(::Garfield::Component), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponent_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::Component), alignof(::Garfield::Component) );
      instance.SetDelete(&delete_GarfieldcLcLComponent);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponent);
      instance.SetDestructor(&destruct_GarfieldcLcLComponent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::Component*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::Component*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::Component*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponent_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::Component*>(nullptr))->GetClass();
      GarfieldcLcLComponent_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponent_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSensor_Dictionary();
   static void GarfieldcLcLSensor_TClassManip(TClass*);
   static void *new_GarfieldcLcLSensor(void *p = nullptr);
   static void *newArray_GarfieldcLcLSensor(Long_t size, void *p);
   static void delete_GarfieldcLcLSensor(void *p);
   static void deleteArray_GarfieldcLcLSensor(void *p);
   static void destruct_GarfieldcLcLSensor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::Sensor*)
   {
      ::Garfield::Sensor *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::Sensor));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::Sensor", "Garfield/Sensor.hh", 20,
                  typeid(::Garfield::Sensor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSensor_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::Sensor), alignof(::Garfield::Sensor) );
      instance.SetNew(&new_GarfieldcLcLSensor);
      instance.SetNewArray(&newArray_GarfieldcLcLSensor);
      instance.SetDelete(&delete_GarfieldcLcLSensor);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSensor);
      instance.SetDestructor(&destruct_GarfieldcLcLSensor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::Sensor*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::Sensor*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::Sensor*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSensor_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::Sensor*>(nullptr))->GetClass();
      GarfieldcLcLSensor_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSensor_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewDrift_Dictionary();
   static void GarfieldcLcLViewDrift_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewDrift(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewDrift(Long_t size, void *p);
   static void delete_GarfieldcLcLViewDrift(void *p);
   static void deleteArray_GarfieldcLcLViewDrift(void *p);
   static void destruct_GarfieldcLcLViewDrift(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewDrift*)
   {
      ::Garfield::ViewDrift *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewDrift));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewDrift", "Garfield/ViewDrift.hh", 19,
                  typeid(::Garfield::ViewDrift), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewDrift_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewDrift), alignof(::Garfield::ViewDrift) );
      instance.SetNew(&new_GarfieldcLcLViewDrift);
      instance.SetNewArray(&newArray_GarfieldcLcLViewDrift);
      instance.SetDelete(&delete_GarfieldcLcLViewDrift);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewDrift);
      instance.SetDestructor(&destruct_GarfieldcLcLViewDrift);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewDrift*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewDrift*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewDrift*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewDrift_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewDrift*>(nullptr))->GetClass();
      GarfieldcLcLViewDrift_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewDrift_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLAvalancheMicroscopic_Dictionary();
   static void GarfieldcLcLAvalancheMicroscopic_TClassManip(TClass*);
   static void *new_GarfieldcLcLAvalancheMicroscopic(void *p = nullptr);
   static void *newArray_GarfieldcLcLAvalancheMicroscopic(Long_t size, void *p);
   static void delete_GarfieldcLcLAvalancheMicroscopic(void *p);
   static void deleteArray_GarfieldcLcLAvalancheMicroscopic(void *p);
   static void destruct_GarfieldcLcLAvalancheMicroscopic(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::AvalancheMicroscopic*)
   {
      ::Garfield::AvalancheMicroscopic *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::AvalancheMicroscopic));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::AvalancheMicroscopic", "Garfield/AvalancheMicroscopic.hh", 17,
                  typeid(::Garfield::AvalancheMicroscopic), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLAvalancheMicroscopic_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::AvalancheMicroscopic), alignof(::Garfield::AvalancheMicroscopic) );
      instance.SetNew(&new_GarfieldcLcLAvalancheMicroscopic);
      instance.SetNewArray(&newArray_GarfieldcLcLAvalancheMicroscopic);
      instance.SetDelete(&delete_GarfieldcLcLAvalancheMicroscopic);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLAvalancheMicroscopic);
      instance.SetDestructor(&destruct_GarfieldcLcLAvalancheMicroscopic);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::AvalancheMicroscopic*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::AvalancheMicroscopic*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::AvalancheMicroscopic*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLAvalancheMicroscopic_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::AvalancheMicroscopic*>(nullptr))->GetClass();
      GarfieldcLcLAvalancheMicroscopic_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLAvalancheMicroscopic_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentGrid_Dictionary();
   static void GarfieldcLcLComponentGrid_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentGrid(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentGrid(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentGrid(void *p);
   static void deleteArray_GarfieldcLcLComponentGrid(void *p);
   static void destruct_GarfieldcLcLComponentGrid(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentGrid*)
   {
      ::Garfield::ComponentGrid *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentGrid));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentGrid", "Garfield/ComponentGrid.hh", 12,
                  typeid(::Garfield::ComponentGrid), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentGrid_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentGrid), alignof(::Garfield::ComponentGrid) );
      instance.SetNew(&new_GarfieldcLcLComponentGrid);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentGrid);
      instance.SetDelete(&delete_GarfieldcLcLComponentGrid);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentGrid);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentGrid);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentGrid*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentGrid*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentGrid*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentGrid_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentGrid*>(nullptr))->GetClass();
      GarfieldcLcLComponentGrid_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentGrid_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentParallelPlate_Dictionary();
   static void GarfieldcLcLComponentParallelPlate_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentParallelPlate(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentParallelPlate(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentParallelPlate(void *p);
   static void deleteArray_GarfieldcLcLComponentParallelPlate(void *p);
   static void destruct_GarfieldcLcLComponentParallelPlate(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentParallelPlate*)
   {
      ::Garfield::ComponentParallelPlate *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentParallelPlate));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentParallelPlate", "Garfield/ComponentParallelPlate.hh", 17,
                  typeid(::Garfield::ComponentParallelPlate), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentParallelPlate_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentParallelPlate), alignof(::Garfield::ComponentParallelPlate) );
      instance.SetNew(&new_GarfieldcLcLComponentParallelPlate);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentParallelPlate);
      instance.SetDelete(&delete_GarfieldcLcLComponentParallelPlate);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentParallelPlate);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentParallelPlate);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentParallelPlate*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentParallelPlate*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentParallelPlate*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentParallelPlate_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentParallelPlate*>(nullptr))->GetClass();
      GarfieldcLcLComponentParallelPlate_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentParallelPlate_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLAvalancheMC_Dictionary();
   static void GarfieldcLcLAvalancheMC_TClassManip(TClass*);
   static void *new_GarfieldcLcLAvalancheMC(void *p = nullptr);
   static void *newArray_GarfieldcLcLAvalancheMC(Long_t size, void *p);
   static void delete_GarfieldcLcLAvalancheMC(void *p);
   static void deleteArray_GarfieldcLcLAvalancheMC(void *p);
   static void destruct_GarfieldcLcLAvalancheMC(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::AvalancheMC*)
   {
      ::Garfield::AvalancheMC *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::AvalancheMC));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::AvalancheMC", "Garfield/AvalancheMC.hh", 18,
                  typeid(::Garfield::AvalancheMC), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLAvalancheMC_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::AvalancheMC), alignof(::Garfield::AvalancheMC) );
      instance.SetNew(&new_GarfieldcLcLAvalancheMC);
      instance.SetNewArray(&newArray_GarfieldcLcLAvalancheMC);
      instance.SetDelete(&delete_GarfieldcLcLAvalancheMC);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLAvalancheMC);
      instance.SetDestructor(&destruct_GarfieldcLcLAvalancheMC);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::AvalancheMC*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::AvalancheMC*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::AvalancheMC*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLAvalancheMC_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::AvalancheMC*>(nullptr))->GetClass();
      GarfieldcLcLAvalancheMC_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLAvalancheMC_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentAnalyticField_Dictionary();
   static void GarfieldcLcLComponentAnalyticField_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentAnalyticField(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentAnalyticField(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentAnalyticField(void *p);
   static void deleteArray_GarfieldcLcLComponentAnalyticField(void *p);
   static void destruct_GarfieldcLcLComponentAnalyticField(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentAnalyticField*)
   {
      ::Garfield::ComponentAnalyticField *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentAnalyticField));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentAnalyticField", "Garfield/ComponentAnalyticField.hh", 18,
                  typeid(::Garfield::ComponentAnalyticField), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentAnalyticField_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentAnalyticField), alignof(::Garfield::ComponentAnalyticField) );
      instance.SetNew(&new_GarfieldcLcLComponentAnalyticField);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentAnalyticField);
      instance.SetDelete(&delete_GarfieldcLcLComponentAnalyticField);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentAnalyticField);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentAnalyticField);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentAnalyticField*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentAnalyticField*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentAnalyticField*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentAnalyticField_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentAnalyticField*>(nullptr))->GetClass();
      GarfieldcLcLComponentAnalyticField_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentAnalyticField_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentFieldMap_Dictionary();
   static void GarfieldcLcLComponentFieldMap_TClassManip(TClass*);
   static void delete_GarfieldcLcLComponentFieldMap(void *p);
   static void deleteArray_GarfieldcLcLComponentFieldMap(void *p);
   static void destruct_GarfieldcLcLComponentFieldMap(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentFieldMap*)
   {
      ::Garfield::ComponentFieldMap *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentFieldMap));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentFieldMap", "Garfield/ComponentFieldMap.hh", 19,
                  typeid(::Garfield::ComponentFieldMap), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentFieldMap_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentFieldMap), alignof(::Garfield::ComponentFieldMap) );
      instance.SetDelete(&delete_GarfieldcLcLComponentFieldMap);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentFieldMap);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentFieldMap);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentFieldMap*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentFieldMap*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentFieldMap*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentFieldMap_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentFieldMap*>(nullptr))->GetClass();
      GarfieldcLcLComponentFieldMap_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentFieldMap_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentAnsys121_Dictionary();
   static void GarfieldcLcLComponentAnsys121_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentAnsys121(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentAnsys121(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentAnsys121(void *p);
   static void deleteArray_GarfieldcLcLComponentAnsys121(void *p);
   static void destruct_GarfieldcLcLComponentAnsys121(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentAnsys121*)
   {
      ::Garfield::ComponentAnsys121 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentAnsys121));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentAnsys121", "Garfield/ComponentAnsys121.hh", 10,
                  typeid(::Garfield::ComponentAnsys121), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentAnsys121_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentAnsys121), alignof(::Garfield::ComponentAnsys121) );
      instance.SetNew(&new_GarfieldcLcLComponentAnsys121);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentAnsys121);
      instance.SetDelete(&delete_GarfieldcLcLComponentAnsys121);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentAnsys121);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentAnsys121);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentAnsys121*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentAnsys121*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentAnsys121*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentAnsys121_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentAnsys121*>(nullptr))->GetClass();
      GarfieldcLcLComponentAnsys121_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentAnsys121_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentAnsys123_Dictionary();
   static void GarfieldcLcLComponentAnsys123_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentAnsys123(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentAnsys123(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentAnsys123(void *p);
   static void deleteArray_GarfieldcLcLComponentAnsys123(void *p);
   static void destruct_GarfieldcLcLComponentAnsys123(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentAnsys123*)
   {
      ::Garfield::ComponentAnsys123 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentAnsys123));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentAnsys123", "Garfield/ComponentAnsys123.hh", 10,
                  typeid(::Garfield::ComponentAnsys123), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentAnsys123_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentAnsys123), alignof(::Garfield::ComponentAnsys123) );
      instance.SetNew(&new_GarfieldcLcLComponentAnsys123);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentAnsys123);
      instance.SetDelete(&delete_GarfieldcLcLComponentAnsys123);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentAnsys123);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentAnsys123);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentAnsys123*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentAnsys123*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentAnsys123*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentAnsys123_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentAnsys123*>(nullptr))->GetClass();
      GarfieldcLcLComponentAnsys123_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentAnsys123_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentCST_Dictionary();
   static void GarfieldcLcLComponentCST_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentCST(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentCST(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentCST(void *p);
   static void deleteArray_GarfieldcLcLComponentCST(void *p);
   static void destruct_GarfieldcLcLComponentCST(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentCST*)
   {
      ::Garfield::ComponentCST *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentCST));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentCST", "Garfield/ComponentCST.hh", 15,
                  typeid(::Garfield::ComponentCST), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentCST_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentCST), alignof(::Garfield::ComponentCST) );
      instance.SetNew(&new_GarfieldcLcLComponentCST);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentCST);
      instance.SetDelete(&delete_GarfieldcLcLComponentCST);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentCST);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentCST);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentCST*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentCST*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentCST*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentCST_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentCST*>(nullptr))->GetClass();
      GarfieldcLcLComponentCST_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentCST_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentComsol_Dictionary();
   static void GarfieldcLcLComponentComsol_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentComsol(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentComsol(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentComsol(void *p);
   static void deleteArray_GarfieldcLcLComponentComsol(void *p);
   static void destruct_GarfieldcLcLComponentComsol(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentComsol*)
   {
      ::Garfield::ComponentComsol *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentComsol));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentComsol", "Garfield/ComponentComsol.hh", 9,
                  typeid(::Garfield::ComponentComsol), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentComsol_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentComsol), alignof(::Garfield::ComponentComsol) );
      instance.SetNew(&new_GarfieldcLcLComponentComsol);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentComsol);
      instance.SetDelete(&delete_GarfieldcLcLComponentComsol);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentComsol);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentComsol);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentComsol*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentComsol*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentComsol*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentComsol_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentComsol*>(nullptr))->GetClass();
      GarfieldcLcLComponentComsol_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentComsol_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentConstant_Dictionary();
   static void GarfieldcLcLComponentConstant_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentConstant(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentConstant(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentConstant(void *p);
   static void deleteArray_GarfieldcLcLComponentConstant(void *p);
   static void destruct_GarfieldcLcLComponentConstant(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentConstant*)
   {
      ::Garfield::ComponentConstant *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentConstant));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentConstant", "Garfield/ComponentConstant.hh", 14,
                  typeid(::Garfield::ComponentConstant), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentConstant_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentConstant), alignof(::Garfield::ComponentConstant) );
      instance.SetNew(&new_GarfieldcLcLComponentConstant);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentConstant);
      instance.SetDelete(&delete_GarfieldcLcLComponentConstant);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentConstant);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentConstant);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentConstant*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentConstant*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentConstant*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentConstant_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentConstant*>(nullptr))->GetClass();
      GarfieldcLcLComponentConstant_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentConstant_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentElmer_Dictionary();
   static void GarfieldcLcLComponentElmer_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentElmer(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentElmer(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentElmer(void *p);
   static void deleteArray_GarfieldcLcLComponentElmer(void *p);
   static void destruct_GarfieldcLcLComponentElmer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentElmer*)
   {
      ::Garfield::ComponentElmer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentElmer));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentElmer", "Garfield/ComponentElmer.hh", 10,
                  typeid(::Garfield::ComponentElmer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentElmer_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentElmer), alignof(::Garfield::ComponentElmer) );
      instance.SetNew(&new_GarfieldcLcLComponentElmer);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentElmer);
      instance.SetDelete(&delete_GarfieldcLcLComponentElmer);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentElmer);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentElmer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentElmer*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentElmer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentElmer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentElmer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentElmer*>(nullptr))->GetClass();
      GarfieldcLcLComponentElmer_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentElmer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentElmer2d_Dictionary();
   static void GarfieldcLcLComponentElmer2d_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentElmer2d(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentElmer2d(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentElmer2d(void *p);
   static void deleteArray_GarfieldcLcLComponentElmer2d(void *p);
   static void destruct_GarfieldcLcLComponentElmer2d(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentElmer2d*)
   {
      ::Garfield::ComponentElmer2d *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentElmer2d));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentElmer2d", "Garfield/ComponentElmer2d.hh", 10,
                  typeid(::Garfield::ComponentElmer2d), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentElmer2d_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentElmer2d), alignof(::Garfield::ComponentElmer2d) );
      instance.SetNew(&new_GarfieldcLcLComponentElmer2d);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentElmer2d);
      instance.SetDelete(&delete_GarfieldcLcLComponentElmer2d);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentElmer2d);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentElmer2d);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentElmer2d*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentElmer2d*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentElmer2d*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentElmer2d_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentElmer2d*>(nullptr))->GetClass();
      GarfieldcLcLComponentElmer2d_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentElmer2d_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentNeBem2d_Dictionary();
   static void GarfieldcLcLComponentNeBem2d_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentNeBem2d(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentNeBem2d(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentNeBem2d(void *p);
   static void deleteArray_GarfieldcLcLComponentNeBem2d(void *p);
   static void destruct_GarfieldcLcLComponentNeBem2d(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentNeBem2d*)
   {
      ::Garfield::ComponentNeBem2d *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentNeBem2d));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentNeBem2d", "Garfield/ComponentNeBem2d.hh", 10,
                  typeid(::Garfield::ComponentNeBem2d), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentNeBem2d_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentNeBem2d), alignof(::Garfield::ComponentNeBem2d) );
      instance.SetNew(&new_GarfieldcLcLComponentNeBem2d);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentNeBem2d);
      instance.SetDelete(&delete_GarfieldcLcLComponentNeBem2d);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentNeBem2d);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentNeBem2d);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentNeBem2d*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentNeBem2d*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentNeBem2d*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentNeBem2d_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentNeBem2d*>(nullptr))->GetClass();
      GarfieldcLcLComponentNeBem2d_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentNeBem2d_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentNeBem3d_Dictionary();
   static void GarfieldcLcLComponentNeBem3d_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentNeBem3d(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentNeBem3d(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentNeBem3d(void *p);
   static void deleteArray_GarfieldcLcLComponentNeBem3d(void *p);
   static void destruct_GarfieldcLcLComponentNeBem3d(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentNeBem3d*)
   {
      ::Garfield::ComponentNeBem3d *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentNeBem3d));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentNeBem3d", "Garfield/ComponentNeBem3d.hh", 12,
                  typeid(::Garfield::ComponentNeBem3d), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentNeBem3d_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentNeBem3d), alignof(::Garfield::ComponentNeBem3d) );
      instance.SetNew(&new_GarfieldcLcLComponentNeBem3d);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentNeBem3d);
      instance.SetDelete(&delete_GarfieldcLcLComponentNeBem3d);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentNeBem3d);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentNeBem3d);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentNeBem3d*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentNeBem3d*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentNeBem3d*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentNeBem3d_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentNeBem3d*>(nullptr))->GetClass();
      GarfieldcLcLComponentNeBem3d_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentNeBem3d_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentTcad2d_Dictionary();
   static void GarfieldcLcLComponentTcad2d_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentTcad2d(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentTcad2d(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentTcad2d(void *p);
   static void deleteArray_GarfieldcLcLComponentTcad2d(void *p);
   static void destruct_GarfieldcLcLComponentTcad2d(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentTcad2d*)
   {
      ::Garfield::ComponentTcad2d *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentTcad2d));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentTcad2d", "Garfield/ComponentTcad2d.hh", 13,
                  typeid(::Garfield::ComponentTcad2d), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentTcad2d_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentTcad2d), alignof(::Garfield::ComponentTcad2d) );
      instance.SetNew(&new_GarfieldcLcLComponentTcad2d);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentTcad2d);
      instance.SetDelete(&delete_GarfieldcLcLComponentTcad2d);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentTcad2d);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentTcad2d);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentTcad2d*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentTcad2d*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentTcad2d*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentTcad2d_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentTcad2d*>(nullptr))->GetClass();
      GarfieldcLcLComponentTcad2d_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentTcad2d_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentTcad3d_Dictionary();
   static void GarfieldcLcLComponentTcad3d_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentTcad3d(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentTcad3d(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentTcad3d(void *p);
   static void deleteArray_GarfieldcLcLComponentTcad3d(void *p);
   static void destruct_GarfieldcLcLComponentTcad3d(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentTcad3d*)
   {
      ::Garfield::ComponentTcad3d *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentTcad3d));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentTcad3d", "Garfield/ComponentTcad3d.hh", 13,
                  typeid(::Garfield::ComponentTcad3d), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentTcad3d_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentTcad3d), alignof(::Garfield::ComponentTcad3d) );
      instance.SetNew(&new_GarfieldcLcLComponentTcad3d);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentTcad3d);
      instance.SetDelete(&delete_GarfieldcLcLComponentTcad3d);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentTcad3d);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentTcad3d);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentTcad3d*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentTcad3d*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentTcad3d*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentTcad3d_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentTcad3d*>(nullptr))->GetClass();
      GarfieldcLcLComponentTcad3d_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentTcad3d_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLComponentUser_Dictionary();
   static void GarfieldcLcLComponentUser_TClassManip(TClass*);
   static void *new_GarfieldcLcLComponentUser(void *p = nullptr);
   static void *newArray_GarfieldcLcLComponentUser(Long_t size, void *p);
   static void delete_GarfieldcLcLComponentUser(void *p);
   static void deleteArray_GarfieldcLcLComponentUser(void *p);
   static void destruct_GarfieldcLcLComponentUser(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ComponentUser*)
   {
      ::Garfield::ComponentUser *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ComponentUser));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ComponentUser", "Garfield/ComponentUser.hh", 13,
                  typeid(::Garfield::ComponentUser), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLComponentUser_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ComponentUser), alignof(::Garfield::ComponentUser) );
      instance.SetNew(&new_GarfieldcLcLComponentUser);
      instance.SetNewArray(&newArray_GarfieldcLcLComponentUser);
      instance.SetDelete(&delete_GarfieldcLcLComponentUser);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLComponentUser);
      instance.SetDestructor(&destruct_GarfieldcLcLComponentUser);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ComponentUser*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ComponentUser*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentUser*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLComponentUser_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ComponentUser*>(nullptr))->GetClass();
      GarfieldcLcLComponentUser_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLComponentUser_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLDriftLineRKF_Dictionary();
   static void GarfieldcLcLDriftLineRKF_TClassManip(TClass*);
   static void *new_GarfieldcLcLDriftLineRKF(void *p = nullptr);
   static void *newArray_GarfieldcLcLDriftLineRKF(Long_t size, void *p);
   static void delete_GarfieldcLcLDriftLineRKF(void *p);
   static void deleteArray_GarfieldcLcLDriftLineRKF(void *p);
   static void destruct_GarfieldcLcLDriftLineRKF(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::DriftLineRKF*)
   {
      ::Garfield::DriftLineRKF *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::DriftLineRKF));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::DriftLineRKF", "Garfield/DriftLineRKF.hh", 18,
                  typeid(::Garfield::DriftLineRKF), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLDriftLineRKF_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::DriftLineRKF), alignof(::Garfield::DriftLineRKF) );
      instance.SetNew(&new_GarfieldcLcLDriftLineRKF);
      instance.SetNewArray(&newArray_GarfieldcLcLDriftLineRKF);
      instance.SetDelete(&delete_GarfieldcLcLDriftLineRKF);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLDriftLineRKF);
      instance.SetDestructor(&destruct_GarfieldcLcLDriftLineRKF);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::DriftLineRKF*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::DriftLineRKF*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::DriftLineRKF*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLDriftLineRKF_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::DriftLineRKF*>(nullptr))->GetClass();
      GarfieldcLcLDriftLineRKF_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLDriftLineRKF_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLGeometryRoot_Dictionary();
   static void GarfieldcLcLGeometryRoot_TClassManip(TClass*);
   static void *new_GarfieldcLcLGeometryRoot(void *p = nullptr);
   static void *newArray_GarfieldcLcLGeometryRoot(Long_t size, void *p);
   static void delete_GarfieldcLcLGeometryRoot(void *p);
   static void deleteArray_GarfieldcLcLGeometryRoot(void *p);
   static void destruct_GarfieldcLcLGeometryRoot(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::GeometryRoot*)
   {
      ::Garfield::GeometryRoot *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::GeometryRoot));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::GeometryRoot", "Garfield/GeometryRoot.hh", 15,
                  typeid(::Garfield::GeometryRoot), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLGeometryRoot_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::GeometryRoot), alignof(::Garfield::GeometryRoot) );
      instance.SetNew(&new_GarfieldcLcLGeometryRoot);
      instance.SetNewArray(&newArray_GarfieldcLcLGeometryRoot);
      instance.SetDelete(&delete_GarfieldcLcLGeometryRoot);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLGeometryRoot);
      instance.SetDestructor(&destruct_GarfieldcLcLGeometryRoot);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::GeometryRoot*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::GeometryRoot*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::GeometryRoot*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLGeometryRoot_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::GeometryRoot*>(nullptr))->GetClass();
      GarfieldcLcLGeometryRoot_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLGeometryRoot_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLGeometrySimple_Dictionary();
   static void GarfieldcLcLGeometrySimple_TClassManip(TClass*);
   static void *new_GarfieldcLcLGeometrySimple(void *p = nullptr);
   static void *newArray_GarfieldcLcLGeometrySimple(Long_t size, void *p);
   static void delete_GarfieldcLcLGeometrySimple(void *p);
   static void deleteArray_GarfieldcLcLGeometrySimple(void *p);
   static void destruct_GarfieldcLcLGeometrySimple(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::GeometrySimple*)
   {
      ::Garfield::GeometrySimple *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::GeometrySimple));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::GeometrySimple", "Garfield/GeometrySimple.hh", 13,
                  typeid(::Garfield::GeometrySimple), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLGeometrySimple_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::GeometrySimple), alignof(::Garfield::GeometrySimple) );
      instance.SetNew(&new_GarfieldcLcLGeometrySimple);
      instance.SetNewArray(&newArray_GarfieldcLcLGeometrySimple);
      instance.SetDelete(&delete_GarfieldcLcLGeometrySimple);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLGeometrySimple);
      instance.SetDestructor(&destruct_GarfieldcLcLGeometrySimple);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::GeometrySimple*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::GeometrySimple*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::GeometrySimple*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLGeometrySimple_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::GeometrySimple*>(nullptr))->GetClass();
      GarfieldcLcLGeometrySimple_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLGeometrySimple_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLMediumCdTe_Dictionary();
   static void GarfieldcLcLMediumCdTe_TClassManip(TClass*);
   static void *new_GarfieldcLcLMediumCdTe(void *p = nullptr);
   static void *newArray_GarfieldcLcLMediumCdTe(Long_t size, void *p);
   static void delete_GarfieldcLcLMediumCdTe(void *p);
   static void deleteArray_GarfieldcLcLMediumCdTe(void *p);
   static void destruct_GarfieldcLcLMediumCdTe(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::MediumCdTe*)
   {
      ::Garfield::MediumCdTe *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::MediumCdTe));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::MediumCdTe", "Garfield/MediumCdTe.hh", 10,
                  typeid(::Garfield::MediumCdTe), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMediumCdTe_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::MediumCdTe), alignof(::Garfield::MediumCdTe) );
      instance.SetNew(&new_GarfieldcLcLMediumCdTe);
      instance.SetNewArray(&newArray_GarfieldcLcLMediumCdTe);
      instance.SetDelete(&delete_GarfieldcLcLMediumCdTe);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMediumCdTe);
      instance.SetDestructor(&destruct_GarfieldcLcLMediumCdTe);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::MediumCdTe*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::MediumCdTe*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumCdTe*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMediumCdTe_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumCdTe*>(nullptr))->GetClass();
      GarfieldcLcLMediumCdTe_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMediumCdTe_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLMediumDiamond_Dictionary();
   static void GarfieldcLcLMediumDiamond_TClassManip(TClass*);
   static void *new_GarfieldcLcLMediumDiamond(void *p = nullptr);
   static void *newArray_GarfieldcLcLMediumDiamond(Long_t size, void *p);
   static void delete_GarfieldcLcLMediumDiamond(void *p);
   static void deleteArray_GarfieldcLcLMediumDiamond(void *p);
   static void destruct_GarfieldcLcLMediumDiamond(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::MediumDiamond*)
   {
      ::Garfield::MediumDiamond *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::MediumDiamond));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::MediumDiamond", "Garfield/MediumDiamond.hh", 12,
                  typeid(::Garfield::MediumDiamond), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMediumDiamond_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::MediumDiamond), alignof(::Garfield::MediumDiamond) );
      instance.SetNew(&new_GarfieldcLcLMediumDiamond);
      instance.SetNewArray(&newArray_GarfieldcLcLMediumDiamond);
      instance.SetDelete(&delete_GarfieldcLcLMediumDiamond);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMediumDiamond);
      instance.SetDestructor(&destruct_GarfieldcLcLMediumDiamond);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::MediumDiamond*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::MediumDiamond*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumDiamond*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMediumDiamond_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumDiamond*>(nullptr))->GetClass();
      GarfieldcLcLMediumDiamond_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMediumDiamond_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLMediumGaAs_Dictionary();
   static void GarfieldcLcLMediumGaAs_TClassManip(TClass*);
   static void *new_GarfieldcLcLMediumGaAs(void *p = nullptr);
   static void *newArray_GarfieldcLcLMediumGaAs(Long_t size, void *p);
   static void delete_GarfieldcLcLMediumGaAs(void *p);
   static void deleteArray_GarfieldcLcLMediumGaAs(void *p);
   static void destruct_GarfieldcLcLMediumGaAs(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::MediumGaAs*)
   {
      ::Garfield::MediumGaAs *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::MediumGaAs));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::MediumGaAs", "Garfield/MediumGaAs.hh", 10,
                  typeid(::Garfield::MediumGaAs), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMediumGaAs_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::MediumGaAs), alignof(::Garfield::MediumGaAs) );
      instance.SetNew(&new_GarfieldcLcLMediumGaAs);
      instance.SetNewArray(&newArray_GarfieldcLcLMediumGaAs);
      instance.SetDelete(&delete_GarfieldcLcLMediumGaAs);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMediumGaAs);
      instance.SetDestructor(&destruct_GarfieldcLcLMediumGaAs);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::MediumGaAs*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::MediumGaAs*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumGaAs*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMediumGaAs_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumGaAs*>(nullptr))->GetClass();
      GarfieldcLcLMediumGaAs_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMediumGaAs_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLMediumGaN_Dictionary();
   static void GarfieldcLcLMediumGaN_TClassManip(TClass*);
   static void *new_GarfieldcLcLMediumGaN(void *p = nullptr);
   static void *newArray_GarfieldcLcLMediumGaN(Long_t size, void *p);
   static void delete_GarfieldcLcLMediumGaN(void *p);
   static void deleteArray_GarfieldcLcLMediumGaN(void *p);
   static void destruct_GarfieldcLcLMediumGaN(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::MediumGaN*)
   {
      ::Garfield::MediumGaN *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::MediumGaN));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::MediumGaN", "Garfield/MediumGaN.hh", 10,
                  typeid(::Garfield::MediumGaN), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMediumGaN_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::MediumGaN), alignof(::Garfield::MediumGaN) );
      instance.SetNew(&new_GarfieldcLcLMediumGaN);
      instance.SetNewArray(&newArray_GarfieldcLcLMediumGaN);
      instance.SetDelete(&delete_GarfieldcLcLMediumGaN);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMediumGaN);
      instance.SetDestructor(&destruct_GarfieldcLcLMediumGaN);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::MediumGaN*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::MediumGaN*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumGaN*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMediumGaN_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumGaN*>(nullptr))->GetClass();
      GarfieldcLcLMediumGaN_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMediumGaN_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLMediumGas_Dictionary();
   static void GarfieldcLcLMediumGas_TClassManip(TClass*);
   static void *new_GarfieldcLcLMediumGas(void *p = nullptr);
   static void *newArray_GarfieldcLcLMediumGas(Long_t size, void *p);
   static void delete_GarfieldcLcLMediumGas(void *p);
   static void deleteArray_GarfieldcLcLMediumGas(void *p);
   static void destruct_GarfieldcLcLMediumGas(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::MediumGas*)
   {
      ::Garfield::MediumGas *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::MediumGas));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::MediumGas", "Garfield/MediumGas.hh", 15,
                  typeid(::Garfield::MediumGas), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMediumGas_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::MediumGas), alignof(::Garfield::MediumGas) );
      instance.SetNew(&new_GarfieldcLcLMediumGas);
      instance.SetNewArray(&newArray_GarfieldcLcLMediumGas);
      instance.SetDelete(&delete_GarfieldcLcLMediumGas);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMediumGas);
      instance.SetDestructor(&destruct_GarfieldcLcLMediumGas);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::MediumGas*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::MediumGas*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumGas*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMediumGas_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumGas*>(nullptr))->GetClass();
      GarfieldcLcLMediumGas_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMediumGas_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLMediumMagboltz_Dictionary();
   static void GarfieldcLcLMediumMagboltz_TClassManip(TClass*);
   static void *new_GarfieldcLcLMediumMagboltz(void *p = nullptr);
   static void *newArray_GarfieldcLcLMediumMagboltz(Long_t size, void *p);
   static void delete_GarfieldcLcLMediumMagboltz(void *p);
   static void deleteArray_GarfieldcLcLMediumMagboltz(void *p);
   static void destruct_GarfieldcLcLMediumMagboltz(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::MediumMagboltz*)
   {
      ::Garfield::MediumMagboltz *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::MediumMagboltz));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::MediumMagboltz", "Garfield/MediumMagboltz.hh", 15,
                  typeid(::Garfield::MediumMagboltz), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMediumMagboltz_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::MediumMagboltz), alignof(::Garfield::MediumMagboltz) );
      instance.SetNew(&new_GarfieldcLcLMediumMagboltz);
      instance.SetNewArray(&newArray_GarfieldcLcLMediumMagboltz);
      instance.SetDelete(&delete_GarfieldcLcLMediumMagboltz);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMediumMagboltz);
      instance.SetDestructor(&destruct_GarfieldcLcLMediumMagboltz);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::MediumMagboltz*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::MediumMagboltz*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumMagboltz*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMediumMagboltz_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumMagboltz*>(nullptr))->GetClass();
      GarfieldcLcLMediumMagboltz_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMediumMagboltz_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLMediumSilicon_Dictionary();
   static void GarfieldcLcLMediumSilicon_TClassManip(TClass*);
   static void *new_GarfieldcLcLMediumSilicon(void *p = nullptr);
   static void *newArray_GarfieldcLcLMediumSilicon(Long_t size, void *p);
   static void delete_GarfieldcLcLMediumSilicon(void *p);
   static void deleteArray_GarfieldcLcLMediumSilicon(void *p);
   static void destruct_GarfieldcLcLMediumSilicon(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::MediumSilicon*)
   {
      ::Garfield::MediumSilicon *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::MediumSilicon));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::MediumSilicon", "Garfield/MediumSilicon.hh", 13,
                  typeid(::Garfield::MediumSilicon), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLMediumSilicon_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::MediumSilicon), alignof(::Garfield::MediumSilicon) );
      instance.SetNew(&new_GarfieldcLcLMediumSilicon);
      instance.SetNewArray(&newArray_GarfieldcLcLMediumSilicon);
      instance.SetDelete(&delete_GarfieldcLcLMediumSilicon);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLMediumSilicon);
      instance.SetDestructor(&destruct_GarfieldcLcLMediumSilicon);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::MediumSilicon*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::MediumSilicon*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumSilicon*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLMediumSilicon_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::MediumSilicon*>(nullptr))->GetClass();
      GarfieldcLcLMediumSilicon_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLMediumSilicon_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLOpticalData_Dictionary();
   static void GarfieldcLcLOpticalData_TClassManip(TClass*);
   static void *new_GarfieldcLcLOpticalData(void *p = nullptr);
   static void *newArray_GarfieldcLcLOpticalData(Long_t size, void *p);
   static void delete_GarfieldcLcLOpticalData(void *p);
   static void deleteArray_GarfieldcLcLOpticalData(void *p);
   static void destruct_GarfieldcLcLOpticalData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::OpticalData*)
   {
      ::Garfield::OpticalData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::OpticalData));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::OpticalData", "Garfield/OpticalData.hh", 11,
                  typeid(::Garfield::OpticalData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLOpticalData_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::OpticalData), alignof(::Garfield::OpticalData) );
      instance.SetNew(&new_GarfieldcLcLOpticalData);
      instance.SetNewArray(&newArray_GarfieldcLcLOpticalData);
      instance.SetDelete(&delete_GarfieldcLcLOpticalData);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLOpticalData);
      instance.SetDestructor(&destruct_GarfieldcLcLOpticalData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::OpticalData*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::OpticalData*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::OpticalData*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLOpticalData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::OpticalData*>(nullptr))->GetClass();
      GarfieldcLcLOpticalData_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLOpticalData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolidBox_Dictionary();
   static void GarfieldcLcLSolidBox_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolidBox(void *p);
   static void deleteArray_GarfieldcLcLSolidBox(void *p);
   static void destruct_GarfieldcLcLSolidBox(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::SolidBox*)
   {
      ::Garfield::SolidBox *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::SolidBox));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::SolidBox", "Garfield/SolidBox.hh", 10,
                  typeid(::Garfield::SolidBox), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolidBox_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::SolidBox), alignof(::Garfield::SolidBox) );
      instance.SetDelete(&delete_GarfieldcLcLSolidBox);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolidBox);
      instance.SetDestructor(&destruct_GarfieldcLcLSolidBox);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::SolidBox*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::SolidBox*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidBox*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolidBox_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidBox*>(nullptr))->GetClass();
      GarfieldcLcLSolidBox_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolidBox_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolidExtrusion_Dictionary();
   static void GarfieldcLcLSolidExtrusion_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolidExtrusion(void *p);
   static void deleteArray_GarfieldcLcLSolidExtrusion(void *p);
   static void destruct_GarfieldcLcLSolidExtrusion(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::SolidExtrusion*)
   {
      ::Garfield::SolidExtrusion *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::SolidExtrusion));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::SolidExtrusion", "Garfield/SolidExtrusion.hh", 10,
                  typeid(::Garfield::SolidExtrusion), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolidExtrusion_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::SolidExtrusion), alignof(::Garfield::SolidExtrusion) );
      instance.SetDelete(&delete_GarfieldcLcLSolidExtrusion);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolidExtrusion);
      instance.SetDestructor(&destruct_GarfieldcLcLSolidExtrusion);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::SolidExtrusion*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::SolidExtrusion*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidExtrusion*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolidExtrusion_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidExtrusion*>(nullptr))->GetClass();
      GarfieldcLcLSolidExtrusion_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolidExtrusion_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolidHole_Dictionary();
   static void GarfieldcLcLSolidHole_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolidHole(void *p);
   static void deleteArray_GarfieldcLcLSolidHole(void *p);
   static void destruct_GarfieldcLcLSolidHole(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::SolidHole*)
   {
      ::Garfield::SolidHole *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::SolidHole));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::SolidHole", "Garfield/SolidHole.hh", 12,
                  typeid(::Garfield::SolidHole), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolidHole_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::SolidHole), alignof(::Garfield::SolidHole) );
      instance.SetDelete(&delete_GarfieldcLcLSolidHole);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolidHole);
      instance.SetDestructor(&destruct_GarfieldcLcLSolidHole);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::SolidHole*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::SolidHole*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidHole*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolidHole_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidHole*>(nullptr))->GetClass();
      GarfieldcLcLSolidHole_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolidHole_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolidRidge_Dictionary();
   static void GarfieldcLcLSolidRidge_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolidRidge(void *p);
   static void deleteArray_GarfieldcLcLSolidRidge(void *p);
   static void destruct_GarfieldcLcLSolidRidge(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::SolidRidge*)
   {
      ::Garfield::SolidRidge *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::SolidRidge));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::SolidRidge", "Garfield/SolidRidge.hh", 10,
                  typeid(::Garfield::SolidRidge), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolidRidge_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::SolidRidge), alignof(::Garfield::SolidRidge) );
      instance.SetDelete(&delete_GarfieldcLcLSolidRidge);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolidRidge);
      instance.SetDestructor(&destruct_GarfieldcLcLSolidRidge);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::SolidRidge*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::SolidRidge*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidRidge*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolidRidge_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidRidge*>(nullptr))->GetClass();
      GarfieldcLcLSolidRidge_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolidRidge_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolidSphere_Dictionary();
   static void GarfieldcLcLSolidSphere_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolidSphere(void *p);
   static void deleteArray_GarfieldcLcLSolidSphere(void *p);
   static void destruct_GarfieldcLcLSolidSphere(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::SolidSphere*)
   {
      ::Garfield::SolidSphere *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::SolidSphere));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::SolidSphere", "Garfield/SolidSphere.hh", 12,
                  typeid(::Garfield::SolidSphere), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolidSphere_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::SolidSphere), alignof(::Garfield::SolidSphere) );
      instance.SetDelete(&delete_GarfieldcLcLSolidSphere);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolidSphere);
      instance.SetDestructor(&destruct_GarfieldcLcLSolidSphere);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::SolidSphere*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::SolidSphere*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidSphere*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolidSphere_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidSphere*>(nullptr))->GetClass();
      GarfieldcLcLSolidSphere_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolidSphere_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolidTube_Dictionary();
   static void GarfieldcLcLSolidTube_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolidTube(void *p);
   static void deleteArray_GarfieldcLcLSolidTube(void *p);
   static void destruct_GarfieldcLcLSolidTube(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::SolidTube*)
   {
      ::Garfield::SolidTube *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::SolidTube));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::SolidTube", "Garfield/SolidTube.hh", 12,
                  typeid(::Garfield::SolidTube), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolidTube_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::SolidTube), alignof(::Garfield::SolidTube) );
      instance.SetDelete(&delete_GarfieldcLcLSolidTube);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolidTube);
      instance.SetDestructor(&destruct_GarfieldcLcLSolidTube);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::SolidTube*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::SolidTube*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidTube*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolidTube_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidTube*>(nullptr))->GetClass();
      GarfieldcLcLSolidTube_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolidTube_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLSolidWire_Dictionary();
   static void GarfieldcLcLSolidWire_TClassManip(TClass*);
   static void delete_GarfieldcLcLSolidWire(void *p);
   static void deleteArray_GarfieldcLcLSolidWire(void *p);
   static void destruct_GarfieldcLcLSolidWire(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::SolidWire*)
   {
      ::Garfield::SolidWire *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::SolidWire));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::SolidWire", "Garfield/SolidWire.hh", 10,
                  typeid(::Garfield::SolidWire), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLSolidWire_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::SolidWire), alignof(::Garfield::SolidWire) );
      instance.SetDelete(&delete_GarfieldcLcLSolidWire);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLSolidWire);
      instance.SetDestructor(&destruct_GarfieldcLcLSolidWire);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::SolidWire*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::SolidWire*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidWire*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLSolidWire_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::SolidWire*>(nullptr))->GetClass();
      GarfieldcLcLSolidWire_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLSolidWire_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLTrack_Dictionary();
   static void GarfieldcLcLTrack_TClassManip(TClass*);
   static void delete_GarfieldcLcLTrack(void *p);
   static void deleteArray_GarfieldcLcLTrack(void *p);
   static void destruct_GarfieldcLcLTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::Track*)
   {
      ::Garfield::Track *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::Track));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::Track", "Garfield/Track.hh", 14,
                  typeid(::Garfield::Track), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLTrack_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::Track), alignof(::Garfield::Track) );
      instance.SetDelete(&delete_GarfieldcLcLTrack);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLTrack);
      instance.SetDestructor(&destruct_GarfieldcLcLTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::Track*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::Track*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::Track*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLTrack_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::Track*>(nullptr))->GetClass();
      GarfieldcLcLTrack_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLTrack_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLTrackBichsel_Dictionary();
   static void GarfieldcLcLTrackBichsel_TClassManip(TClass*);
   static void *new_GarfieldcLcLTrackBichsel(void *p = nullptr);
   static void *newArray_GarfieldcLcLTrackBichsel(Long_t size, void *p);
   static void delete_GarfieldcLcLTrackBichsel(void *p);
   static void deleteArray_GarfieldcLcLTrackBichsel(void *p);
   static void destruct_GarfieldcLcLTrackBichsel(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::TrackBichsel*)
   {
      ::Garfield::TrackBichsel *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::TrackBichsel));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::TrackBichsel", "Garfield/TrackBichsel.hh", 17,
                  typeid(::Garfield::TrackBichsel), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLTrackBichsel_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::TrackBichsel), alignof(::Garfield::TrackBichsel) );
      instance.SetNew(&new_GarfieldcLcLTrackBichsel);
      instance.SetNewArray(&newArray_GarfieldcLcLTrackBichsel);
      instance.SetDelete(&delete_GarfieldcLcLTrackBichsel);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLTrackBichsel);
      instance.SetDestructor(&destruct_GarfieldcLcLTrackBichsel);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::TrackBichsel*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::TrackBichsel*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::TrackBichsel*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLTrackBichsel_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::TrackBichsel*>(nullptr))->GetClass();
      GarfieldcLcLTrackBichsel_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLTrackBichsel_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLTrackHeed_Dictionary();
   static void GarfieldcLcLTrackHeed_TClassManip(TClass*);
   static void *new_GarfieldcLcLTrackHeed(void *p = nullptr);
   static void *newArray_GarfieldcLcLTrackHeed(Long_t size, void *p);
   static void delete_GarfieldcLcLTrackHeed(void *p);
   static void deleteArray_GarfieldcLcLTrackHeed(void *p);
   static void destruct_GarfieldcLcLTrackHeed(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::TrackHeed*)
   {
      ::Garfield::TrackHeed *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::TrackHeed));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::TrackHeed", "Garfield/TrackHeed.hh", 35,
                  typeid(::Garfield::TrackHeed), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLTrackHeed_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::TrackHeed), alignof(::Garfield::TrackHeed) );
      instance.SetNew(&new_GarfieldcLcLTrackHeed);
      instance.SetNewArray(&newArray_GarfieldcLcLTrackHeed);
      instance.SetDelete(&delete_GarfieldcLcLTrackHeed);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLTrackHeed);
      instance.SetDestructor(&destruct_GarfieldcLcLTrackHeed);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::TrackHeed*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::TrackHeed*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::TrackHeed*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLTrackHeed_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::TrackHeed*>(nullptr))->GetClass();
      GarfieldcLcLTrackHeed_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLTrackHeed_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLTrackSrim_Dictionary();
   static void GarfieldcLcLTrackSrim_TClassManip(TClass*);
   static void *new_GarfieldcLcLTrackSrim(void *p = nullptr);
   static void *newArray_GarfieldcLcLTrackSrim(Long_t size, void *p);
   static void delete_GarfieldcLcLTrackSrim(void *p);
   static void deleteArray_GarfieldcLcLTrackSrim(void *p);
   static void destruct_GarfieldcLcLTrackSrim(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::TrackSrim*)
   {
      ::Garfield::TrackSrim *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::TrackSrim));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::TrackSrim", "Garfield/TrackSrim.hh", 11,
                  typeid(::Garfield::TrackSrim), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLTrackSrim_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::TrackSrim), alignof(::Garfield::TrackSrim) );
      instance.SetNew(&new_GarfieldcLcLTrackSrim);
      instance.SetNewArray(&newArray_GarfieldcLcLTrackSrim);
      instance.SetDelete(&delete_GarfieldcLcLTrackSrim);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLTrackSrim);
      instance.SetDestructor(&destruct_GarfieldcLcLTrackSrim);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::TrackSrim*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::TrackSrim*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::TrackSrim*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLTrackSrim_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::TrackSrim*>(nullptr))->GetClass();
      GarfieldcLcLTrackSrim_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLTrackSrim_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewCell_Dictionary();
   static void GarfieldcLcLViewCell_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewCell(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewCell(Long_t size, void *p);
   static void delete_GarfieldcLcLViewCell(void *p);
   static void deleteArray_GarfieldcLcLViewCell(void *p);
   static void destruct_GarfieldcLcLViewCell(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewCell*)
   {
      ::Garfield::ViewCell *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewCell));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewCell", "Garfield/ViewCell.hh", 18,
                  typeid(::Garfield::ViewCell), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewCell_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewCell), alignof(::Garfield::ViewCell) );
      instance.SetNew(&new_GarfieldcLcLViewCell);
      instance.SetNewArray(&newArray_GarfieldcLcLViewCell);
      instance.SetDelete(&delete_GarfieldcLcLViewCell);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewCell);
      instance.SetDestructor(&destruct_GarfieldcLcLViewCell);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewCell*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewCell*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewCell*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewCell_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewCell*>(nullptr))->GetClass();
      GarfieldcLcLViewCell_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewCell_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewFEMesh_Dictionary();
   static void GarfieldcLcLViewFEMesh_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewFEMesh(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewFEMesh(Long_t size, void *p);
   static void delete_GarfieldcLcLViewFEMesh(void *p);
   static void deleteArray_GarfieldcLcLViewFEMesh(void *p);
   static void destruct_GarfieldcLcLViewFEMesh(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewFEMesh*)
   {
      ::Garfield::ViewFEMesh *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewFEMesh));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewFEMesh", "Garfield/ViewFEMesh.hh", 22,
                  typeid(::Garfield::ViewFEMesh), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewFEMesh_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewFEMesh), alignof(::Garfield::ViewFEMesh) );
      instance.SetNew(&new_GarfieldcLcLViewFEMesh);
      instance.SetNewArray(&newArray_GarfieldcLcLViewFEMesh);
      instance.SetDelete(&delete_GarfieldcLcLViewFEMesh);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewFEMesh);
      instance.SetDestructor(&destruct_GarfieldcLcLViewFEMesh);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewFEMesh*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewFEMesh*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewFEMesh*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewFEMesh_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewFEMesh*>(nullptr))->GetClass();
      GarfieldcLcLViewFEMesh_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewFEMesh_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewField_Dictionary();
   static void GarfieldcLcLViewField_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewField(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewField(Long_t size, void *p);
   static void delete_GarfieldcLcLViewField(void *p);
   static void deleteArray_GarfieldcLcLViewField(void *p);
   static void destruct_GarfieldcLcLViewField(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewField*)
   {
      ::Garfield::ViewField *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewField));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewField", "Garfield/ViewField.hh", 15,
                  typeid(::Garfield::ViewField), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewField_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewField), alignof(::Garfield::ViewField) );
      instance.SetNew(&new_GarfieldcLcLViewField);
      instance.SetNewArray(&newArray_GarfieldcLcLViewField);
      instance.SetDelete(&delete_GarfieldcLcLViewField);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewField);
      instance.SetDestructor(&destruct_GarfieldcLcLViewField);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewField*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewField*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewField*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewField_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewField*>(nullptr))->GetClass();
      GarfieldcLcLViewField_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewField_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewGeometry_Dictionary();
   static void GarfieldcLcLViewGeometry_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewGeometry(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewGeometry(Long_t size, void *p);
   static void delete_GarfieldcLcLViewGeometry(void *p);
   static void deleteArray_GarfieldcLcLViewGeometry(void *p);
   static void destruct_GarfieldcLcLViewGeometry(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewGeometry*)
   {
      ::Garfield::ViewGeometry *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewGeometry));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewGeometry", "Garfield/ViewGeometry.hh", 18,
                  typeid(::Garfield::ViewGeometry), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewGeometry_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewGeometry), alignof(::Garfield::ViewGeometry) );
      instance.SetNew(&new_GarfieldcLcLViewGeometry);
      instance.SetNewArray(&newArray_GarfieldcLcLViewGeometry);
      instance.SetDelete(&delete_GarfieldcLcLViewGeometry);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewGeometry);
      instance.SetDestructor(&destruct_GarfieldcLcLViewGeometry);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewGeometry*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewGeometry*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewGeometry*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewGeometry_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewGeometry*>(nullptr))->GetClass();
      GarfieldcLcLViewGeometry_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewGeometry_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewIsochrons_Dictionary();
   static void GarfieldcLcLViewIsochrons_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewIsochrons(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewIsochrons(Long_t size, void *p);
   static void delete_GarfieldcLcLViewIsochrons(void *p);
   static void deleteArray_GarfieldcLcLViewIsochrons(void *p);
   static void destruct_GarfieldcLcLViewIsochrons(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewIsochrons*)
   {
      ::Garfield::ViewIsochrons *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewIsochrons));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewIsochrons", "Garfield/ViewIsochrons.hh", 14,
                  typeid(::Garfield::ViewIsochrons), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewIsochrons_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewIsochrons), alignof(::Garfield::ViewIsochrons) );
      instance.SetNew(&new_GarfieldcLcLViewIsochrons);
      instance.SetNewArray(&newArray_GarfieldcLcLViewIsochrons);
      instance.SetDelete(&delete_GarfieldcLcLViewIsochrons);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewIsochrons);
      instance.SetDestructor(&destruct_GarfieldcLcLViewIsochrons);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewIsochrons*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewIsochrons*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewIsochrons*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewIsochrons_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewIsochrons*>(nullptr))->GetClass();
      GarfieldcLcLViewIsochrons_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewIsochrons_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewMedium_Dictionary();
   static void GarfieldcLcLViewMedium_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewMedium(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewMedium(Long_t size, void *p);
   static void delete_GarfieldcLcLViewMedium(void *p);
   static void deleteArray_GarfieldcLcLViewMedium(void *p);
   static void destruct_GarfieldcLcLViewMedium(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewMedium*)
   {
      ::Garfield::ViewMedium *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewMedium));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewMedium", "Garfield/ViewMedium.hh", 17,
                  typeid(::Garfield::ViewMedium), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewMedium_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewMedium), alignof(::Garfield::ViewMedium) );
      instance.SetNew(&new_GarfieldcLcLViewMedium);
      instance.SetNewArray(&newArray_GarfieldcLcLViewMedium);
      instance.SetDelete(&delete_GarfieldcLcLViewMedium);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewMedium);
      instance.SetDestructor(&destruct_GarfieldcLcLViewMedium);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewMedium*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewMedium*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewMedium*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewMedium_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewMedium*>(nullptr))->GetClass();
      GarfieldcLcLViewMedium_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewMedium_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GarfieldcLcLViewSignal_Dictionary();
   static void GarfieldcLcLViewSignal_TClassManip(TClass*);
   static void *new_GarfieldcLcLViewSignal(void *p = nullptr);
   static void *newArray_GarfieldcLcLViewSignal(Long_t size, void *p);
   static void delete_GarfieldcLcLViewSignal(void *p);
   static void deleteArray_GarfieldcLcLViewSignal(void *p);
   static void destruct_GarfieldcLcLViewSignal(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Garfield::ViewSignal*)
   {
      ::Garfield::ViewSignal *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Garfield::ViewSignal));
      static ::ROOT::TGenericClassInfo 
         instance("Garfield::ViewSignal", "Garfield/ViewSignal.hh", 19,
                  typeid(::Garfield::ViewSignal), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GarfieldcLcLViewSignal_Dictionary, isa_proxy, 0,
                  sizeof(::Garfield::ViewSignal), alignof(::Garfield::ViewSignal) );
      instance.SetNew(&new_GarfieldcLcLViewSignal);
      instance.SetNewArray(&newArray_GarfieldcLcLViewSignal);
      instance.SetDelete(&delete_GarfieldcLcLViewSignal);
      instance.SetDeleteArray(&deleteArray_GarfieldcLcLViewSignal);
      instance.SetDestructor(&destruct_GarfieldcLcLViewSignal);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Garfield::ViewSignal*)
   {
      return GenerateInitInstanceLocal(static_cast<::Garfield::ViewSignal*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewSignal*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GarfieldcLcLViewSignal_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::Garfield::ViewSignal*>(nullptr))->GetClass();
      GarfieldcLcLViewSignal_TClassManip(theClass);
   return theClass;
   }

   static void GarfieldcLcLViewSignal_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMedium(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::Medium : new ::Garfield::Medium;
   }
   static void *newArray_GarfieldcLcLMedium(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::Medium[nElements] : new ::Garfield::Medium[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMedium(void *p) {
      delete (static_cast<::Garfield::Medium*>(p));
   }
   static void deleteArray_GarfieldcLcLMedium(void *p) {
      delete [] (static_cast<::Garfield::Medium*>(p));
   }
   static void destruct_GarfieldcLcLMedium(void *p) {
      typedef ::Garfield::Medium current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::Medium

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolid(void *p) {
      delete (static_cast<::Garfield::Solid*>(p));
   }
   static void deleteArray_GarfieldcLcLSolid(void *p) {
      delete [] (static_cast<::Garfield::Solid*>(p));
   }
   static void destruct_GarfieldcLcLSolid(void *p) {
      typedef ::Garfield::Solid current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::Solid

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLGeometry(void *p) {
      delete (static_cast<::Garfield::Geometry*>(p));
   }
   static void deleteArray_GarfieldcLcLGeometry(void *p) {
      delete [] (static_cast<::Garfield::Geometry*>(p));
   }
   static void destruct_GarfieldcLcLGeometry(void *p) {
      typedef ::Garfield::Geometry current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::Geometry

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponent(void *p) {
      delete (static_cast<::Garfield::Component*>(p));
   }
   static void deleteArray_GarfieldcLcLComponent(void *p) {
      delete [] (static_cast<::Garfield::Component*>(p));
   }
   static void destruct_GarfieldcLcLComponent(void *p) {
      typedef ::Garfield::Component current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::Component

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLSensor(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::Sensor : new ::Garfield::Sensor;
   }
   static void *newArray_GarfieldcLcLSensor(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::Sensor[nElements] : new ::Garfield::Sensor[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSensor(void *p) {
      delete (static_cast<::Garfield::Sensor*>(p));
   }
   static void deleteArray_GarfieldcLcLSensor(void *p) {
      delete [] (static_cast<::Garfield::Sensor*>(p));
   }
   static void destruct_GarfieldcLcLSensor(void *p) {
      typedef ::Garfield::Sensor current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::Sensor

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewDrift(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewDrift : new ::Garfield::ViewDrift;
   }
   static void *newArray_GarfieldcLcLViewDrift(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewDrift[nElements] : new ::Garfield::ViewDrift[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewDrift(void *p) {
      delete (static_cast<::Garfield::ViewDrift*>(p));
   }
   static void deleteArray_GarfieldcLcLViewDrift(void *p) {
      delete [] (static_cast<::Garfield::ViewDrift*>(p));
   }
   static void destruct_GarfieldcLcLViewDrift(void *p) {
      typedef ::Garfield::ViewDrift current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewDrift

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLAvalancheMicroscopic(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::AvalancheMicroscopic : new ::Garfield::AvalancheMicroscopic;
   }
   static void *newArray_GarfieldcLcLAvalancheMicroscopic(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::AvalancheMicroscopic[nElements] : new ::Garfield::AvalancheMicroscopic[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLAvalancheMicroscopic(void *p) {
      delete (static_cast<::Garfield::AvalancheMicroscopic*>(p));
   }
   static void deleteArray_GarfieldcLcLAvalancheMicroscopic(void *p) {
      delete [] (static_cast<::Garfield::AvalancheMicroscopic*>(p));
   }
   static void destruct_GarfieldcLcLAvalancheMicroscopic(void *p) {
      typedef ::Garfield::AvalancheMicroscopic current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::AvalancheMicroscopic

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentGrid(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentGrid : new ::Garfield::ComponentGrid;
   }
   static void *newArray_GarfieldcLcLComponentGrid(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentGrid[nElements] : new ::Garfield::ComponentGrid[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentGrid(void *p) {
      delete (static_cast<::Garfield::ComponentGrid*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentGrid(void *p) {
      delete [] (static_cast<::Garfield::ComponentGrid*>(p));
   }
   static void destruct_GarfieldcLcLComponentGrid(void *p) {
      typedef ::Garfield::ComponentGrid current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentGrid

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentParallelPlate(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentParallelPlate : new ::Garfield::ComponentParallelPlate;
   }
   static void *newArray_GarfieldcLcLComponentParallelPlate(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentParallelPlate[nElements] : new ::Garfield::ComponentParallelPlate[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentParallelPlate(void *p) {
      delete (static_cast<::Garfield::ComponentParallelPlate*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentParallelPlate(void *p) {
      delete [] (static_cast<::Garfield::ComponentParallelPlate*>(p));
   }
   static void destruct_GarfieldcLcLComponentParallelPlate(void *p) {
      typedef ::Garfield::ComponentParallelPlate current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentParallelPlate

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLAvalancheMC(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::AvalancheMC : new ::Garfield::AvalancheMC;
   }
   static void *newArray_GarfieldcLcLAvalancheMC(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::AvalancheMC[nElements] : new ::Garfield::AvalancheMC[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLAvalancheMC(void *p) {
      delete (static_cast<::Garfield::AvalancheMC*>(p));
   }
   static void deleteArray_GarfieldcLcLAvalancheMC(void *p) {
      delete [] (static_cast<::Garfield::AvalancheMC*>(p));
   }
   static void destruct_GarfieldcLcLAvalancheMC(void *p) {
      typedef ::Garfield::AvalancheMC current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::AvalancheMC

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentAnalyticField(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentAnalyticField : new ::Garfield::ComponentAnalyticField;
   }
   static void *newArray_GarfieldcLcLComponentAnalyticField(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentAnalyticField[nElements] : new ::Garfield::ComponentAnalyticField[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentAnalyticField(void *p) {
      delete (static_cast<::Garfield::ComponentAnalyticField*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentAnalyticField(void *p) {
      delete [] (static_cast<::Garfield::ComponentAnalyticField*>(p));
   }
   static void destruct_GarfieldcLcLComponentAnalyticField(void *p) {
      typedef ::Garfield::ComponentAnalyticField current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentAnalyticField

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentFieldMap(void *p) {
      delete (static_cast<::Garfield::ComponentFieldMap*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentFieldMap(void *p) {
      delete [] (static_cast<::Garfield::ComponentFieldMap*>(p));
   }
   static void destruct_GarfieldcLcLComponentFieldMap(void *p) {
      typedef ::Garfield::ComponentFieldMap current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentFieldMap

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentAnsys121(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentAnsys121 : new ::Garfield::ComponentAnsys121;
   }
   static void *newArray_GarfieldcLcLComponentAnsys121(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentAnsys121[nElements] : new ::Garfield::ComponentAnsys121[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentAnsys121(void *p) {
      delete (static_cast<::Garfield::ComponentAnsys121*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentAnsys121(void *p) {
      delete [] (static_cast<::Garfield::ComponentAnsys121*>(p));
   }
   static void destruct_GarfieldcLcLComponentAnsys121(void *p) {
      typedef ::Garfield::ComponentAnsys121 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentAnsys121

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentAnsys123(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentAnsys123 : new ::Garfield::ComponentAnsys123;
   }
   static void *newArray_GarfieldcLcLComponentAnsys123(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentAnsys123[nElements] : new ::Garfield::ComponentAnsys123[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentAnsys123(void *p) {
      delete (static_cast<::Garfield::ComponentAnsys123*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentAnsys123(void *p) {
      delete [] (static_cast<::Garfield::ComponentAnsys123*>(p));
   }
   static void destruct_GarfieldcLcLComponentAnsys123(void *p) {
      typedef ::Garfield::ComponentAnsys123 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentAnsys123

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentCST(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentCST : new ::Garfield::ComponentCST;
   }
   static void *newArray_GarfieldcLcLComponentCST(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentCST[nElements] : new ::Garfield::ComponentCST[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentCST(void *p) {
      delete (static_cast<::Garfield::ComponentCST*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentCST(void *p) {
      delete [] (static_cast<::Garfield::ComponentCST*>(p));
   }
   static void destruct_GarfieldcLcLComponentCST(void *p) {
      typedef ::Garfield::ComponentCST current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentCST

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentComsol(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentComsol : new ::Garfield::ComponentComsol;
   }
   static void *newArray_GarfieldcLcLComponentComsol(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentComsol[nElements] : new ::Garfield::ComponentComsol[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentComsol(void *p) {
      delete (static_cast<::Garfield::ComponentComsol*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentComsol(void *p) {
      delete [] (static_cast<::Garfield::ComponentComsol*>(p));
   }
   static void destruct_GarfieldcLcLComponentComsol(void *p) {
      typedef ::Garfield::ComponentComsol current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentComsol

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentConstant(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentConstant : new ::Garfield::ComponentConstant;
   }
   static void *newArray_GarfieldcLcLComponentConstant(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentConstant[nElements] : new ::Garfield::ComponentConstant[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentConstant(void *p) {
      delete (static_cast<::Garfield::ComponentConstant*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentConstant(void *p) {
      delete [] (static_cast<::Garfield::ComponentConstant*>(p));
   }
   static void destruct_GarfieldcLcLComponentConstant(void *p) {
      typedef ::Garfield::ComponentConstant current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentConstant

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentElmer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentElmer : new ::Garfield::ComponentElmer;
   }
   static void *newArray_GarfieldcLcLComponentElmer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentElmer[nElements] : new ::Garfield::ComponentElmer[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentElmer(void *p) {
      delete (static_cast<::Garfield::ComponentElmer*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentElmer(void *p) {
      delete [] (static_cast<::Garfield::ComponentElmer*>(p));
   }
   static void destruct_GarfieldcLcLComponentElmer(void *p) {
      typedef ::Garfield::ComponentElmer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentElmer

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentElmer2d(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentElmer2d : new ::Garfield::ComponentElmer2d;
   }
   static void *newArray_GarfieldcLcLComponentElmer2d(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentElmer2d[nElements] : new ::Garfield::ComponentElmer2d[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentElmer2d(void *p) {
      delete (static_cast<::Garfield::ComponentElmer2d*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentElmer2d(void *p) {
      delete [] (static_cast<::Garfield::ComponentElmer2d*>(p));
   }
   static void destruct_GarfieldcLcLComponentElmer2d(void *p) {
      typedef ::Garfield::ComponentElmer2d current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentElmer2d

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentNeBem2d(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentNeBem2d : new ::Garfield::ComponentNeBem2d;
   }
   static void *newArray_GarfieldcLcLComponentNeBem2d(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentNeBem2d[nElements] : new ::Garfield::ComponentNeBem2d[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentNeBem2d(void *p) {
      delete (static_cast<::Garfield::ComponentNeBem2d*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentNeBem2d(void *p) {
      delete [] (static_cast<::Garfield::ComponentNeBem2d*>(p));
   }
   static void destruct_GarfieldcLcLComponentNeBem2d(void *p) {
      typedef ::Garfield::ComponentNeBem2d current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentNeBem2d

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentNeBem3d(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentNeBem3d : new ::Garfield::ComponentNeBem3d;
   }
   static void *newArray_GarfieldcLcLComponentNeBem3d(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentNeBem3d[nElements] : new ::Garfield::ComponentNeBem3d[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentNeBem3d(void *p) {
      delete (static_cast<::Garfield::ComponentNeBem3d*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentNeBem3d(void *p) {
      delete [] (static_cast<::Garfield::ComponentNeBem3d*>(p));
   }
   static void destruct_GarfieldcLcLComponentNeBem3d(void *p) {
      typedef ::Garfield::ComponentNeBem3d current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentNeBem3d

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentTcad2d(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentTcad2d : new ::Garfield::ComponentTcad2d;
   }
   static void *newArray_GarfieldcLcLComponentTcad2d(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentTcad2d[nElements] : new ::Garfield::ComponentTcad2d[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentTcad2d(void *p) {
      delete (static_cast<::Garfield::ComponentTcad2d*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentTcad2d(void *p) {
      delete [] (static_cast<::Garfield::ComponentTcad2d*>(p));
   }
   static void destruct_GarfieldcLcLComponentTcad2d(void *p) {
      typedef ::Garfield::ComponentTcad2d current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentTcad2d

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentTcad3d(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentTcad3d : new ::Garfield::ComponentTcad3d;
   }
   static void *newArray_GarfieldcLcLComponentTcad3d(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentTcad3d[nElements] : new ::Garfield::ComponentTcad3d[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentTcad3d(void *p) {
      delete (static_cast<::Garfield::ComponentTcad3d*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentTcad3d(void *p) {
      delete [] (static_cast<::Garfield::ComponentTcad3d*>(p));
   }
   static void destruct_GarfieldcLcLComponentTcad3d(void *p) {
      typedef ::Garfield::ComponentTcad3d current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentTcad3d

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLComponentUser(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentUser : new ::Garfield::ComponentUser;
   }
   static void *newArray_GarfieldcLcLComponentUser(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ComponentUser[nElements] : new ::Garfield::ComponentUser[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLComponentUser(void *p) {
      delete (static_cast<::Garfield::ComponentUser*>(p));
   }
   static void deleteArray_GarfieldcLcLComponentUser(void *p) {
      delete [] (static_cast<::Garfield::ComponentUser*>(p));
   }
   static void destruct_GarfieldcLcLComponentUser(void *p) {
      typedef ::Garfield::ComponentUser current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ComponentUser

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLDriftLineRKF(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::DriftLineRKF : new ::Garfield::DriftLineRKF;
   }
   static void *newArray_GarfieldcLcLDriftLineRKF(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::DriftLineRKF[nElements] : new ::Garfield::DriftLineRKF[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLDriftLineRKF(void *p) {
      delete (static_cast<::Garfield::DriftLineRKF*>(p));
   }
   static void deleteArray_GarfieldcLcLDriftLineRKF(void *p) {
      delete [] (static_cast<::Garfield::DriftLineRKF*>(p));
   }
   static void destruct_GarfieldcLcLDriftLineRKF(void *p) {
      typedef ::Garfield::DriftLineRKF current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::DriftLineRKF

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLGeometryRoot(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::GeometryRoot : new ::Garfield::GeometryRoot;
   }
   static void *newArray_GarfieldcLcLGeometryRoot(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::GeometryRoot[nElements] : new ::Garfield::GeometryRoot[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLGeometryRoot(void *p) {
      delete (static_cast<::Garfield::GeometryRoot*>(p));
   }
   static void deleteArray_GarfieldcLcLGeometryRoot(void *p) {
      delete [] (static_cast<::Garfield::GeometryRoot*>(p));
   }
   static void destruct_GarfieldcLcLGeometryRoot(void *p) {
      typedef ::Garfield::GeometryRoot current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::GeometryRoot

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLGeometrySimple(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::GeometrySimple : new ::Garfield::GeometrySimple;
   }
   static void *newArray_GarfieldcLcLGeometrySimple(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::GeometrySimple[nElements] : new ::Garfield::GeometrySimple[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLGeometrySimple(void *p) {
      delete (static_cast<::Garfield::GeometrySimple*>(p));
   }
   static void deleteArray_GarfieldcLcLGeometrySimple(void *p) {
      delete [] (static_cast<::Garfield::GeometrySimple*>(p));
   }
   static void destruct_GarfieldcLcLGeometrySimple(void *p) {
      typedef ::Garfield::GeometrySimple current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::GeometrySimple

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMediumCdTe(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumCdTe : new ::Garfield::MediumCdTe;
   }
   static void *newArray_GarfieldcLcLMediumCdTe(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumCdTe[nElements] : new ::Garfield::MediumCdTe[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMediumCdTe(void *p) {
      delete (static_cast<::Garfield::MediumCdTe*>(p));
   }
   static void deleteArray_GarfieldcLcLMediumCdTe(void *p) {
      delete [] (static_cast<::Garfield::MediumCdTe*>(p));
   }
   static void destruct_GarfieldcLcLMediumCdTe(void *p) {
      typedef ::Garfield::MediumCdTe current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::MediumCdTe

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMediumDiamond(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumDiamond : new ::Garfield::MediumDiamond;
   }
   static void *newArray_GarfieldcLcLMediumDiamond(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumDiamond[nElements] : new ::Garfield::MediumDiamond[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMediumDiamond(void *p) {
      delete (static_cast<::Garfield::MediumDiamond*>(p));
   }
   static void deleteArray_GarfieldcLcLMediumDiamond(void *p) {
      delete [] (static_cast<::Garfield::MediumDiamond*>(p));
   }
   static void destruct_GarfieldcLcLMediumDiamond(void *p) {
      typedef ::Garfield::MediumDiamond current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::MediumDiamond

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMediumGaAs(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumGaAs : new ::Garfield::MediumGaAs;
   }
   static void *newArray_GarfieldcLcLMediumGaAs(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumGaAs[nElements] : new ::Garfield::MediumGaAs[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMediumGaAs(void *p) {
      delete (static_cast<::Garfield::MediumGaAs*>(p));
   }
   static void deleteArray_GarfieldcLcLMediumGaAs(void *p) {
      delete [] (static_cast<::Garfield::MediumGaAs*>(p));
   }
   static void destruct_GarfieldcLcLMediumGaAs(void *p) {
      typedef ::Garfield::MediumGaAs current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::MediumGaAs

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMediumGaN(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumGaN : new ::Garfield::MediumGaN;
   }
   static void *newArray_GarfieldcLcLMediumGaN(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumGaN[nElements] : new ::Garfield::MediumGaN[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMediumGaN(void *p) {
      delete (static_cast<::Garfield::MediumGaN*>(p));
   }
   static void deleteArray_GarfieldcLcLMediumGaN(void *p) {
      delete [] (static_cast<::Garfield::MediumGaN*>(p));
   }
   static void destruct_GarfieldcLcLMediumGaN(void *p) {
      typedef ::Garfield::MediumGaN current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::MediumGaN

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMediumGas(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumGas : new ::Garfield::MediumGas;
   }
   static void *newArray_GarfieldcLcLMediumGas(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumGas[nElements] : new ::Garfield::MediumGas[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMediumGas(void *p) {
      delete (static_cast<::Garfield::MediumGas*>(p));
   }
   static void deleteArray_GarfieldcLcLMediumGas(void *p) {
      delete [] (static_cast<::Garfield::MediumGas*>(p));
   }
   static void destruct_GarfieldcLcLMediumGas(void *p) {
      typedef ::Garfield::MediumGas current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::MediumGas

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMediumMagboltz(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumMagboltz : new ::Garfield::MediumMagboltz;
   }
   static void *newArray_GarfieldcLcLMediumMagboltz(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumMagboltz[nElements] : new ::Garfield::MediumMagboltz[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMediumMagboltz(void *p) {
      delete (static_cast<::Garfield::MediumMagboltz*>(p));
   }
   static void deleteArray_GarfieldcLcLMediumMagboltz(void *p) {
      delete [] (static_cast<::Garfield::MediumMagboltz*>(p));
   }
   static void destruct_GarfieldcLcLMediumMagboltz(void *p) {
      typedef ::Garfield::MediumMagboltz current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::MediumMagboltz

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLMediumSilicon(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumSilicon : new ::Garfield::MediumSilicon;
   }
   static void *newArray_GarfieldcLcLMediumSilicon(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::MediumSilicon[nElements] : new ::Garfield::MediumSilicon[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLMediumSilicon(void *p) {
      delete (static_cast<::Garfield::MediumSilicon*>(p));
   }
   static void deleteArray_GarfieldcLcLMediumSilicon(void *p) {
      delete [] (static_cast<::Garfield::MediumSilicon*>(p));
   }
   static void destruct_GarfieldcLcLMediumSilicon(void *p) {
      typedef ::Garfield::MediumSilicon current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::MediumSilicon

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLOpticalData(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::OpticalData : new ::Garfield::OpticalData;
   }
   static void *newArray_GarfieldcLcLOpticalData(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::OpticalData[nElements] : new ::Garfield::OpticalData[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLOpticalData(void *p) {
      delete (static_cast<::Garfield::OpticalData*>(p));
   }
   static void deleteArray_GarfieldcLcLOpticalData(void *p) {
      delete [] (static_cast<::Garfield::OpticalData*>(p));
   }
   static void destruct_GarfieldcLcLOpticalData(void *p) {
      typedef ::Garfield::OpticalData current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::OpticalData

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolidBox(void *p) {
      delete (static_cast<::Garfield::SolidBox*>(p));
   }
   static void deleteArray_GarfieldcLcLSolidBox(void *p) {
      delete [] (static_cast<::Garfield::SolidBox*>(p));
   }
   static void destruct_GarfieldcLcLSolidBox(void *p) {
      typedef ::Garfield::SolidBox current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::SolidBox

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolidExtrusion(void *p) {
      delete (static_cast<::Garfield::SolidExtrusion*>(p));
   }
   static void deleteArray_GarfieldcLcLSolidExtrusion(void *p) {
      delete [] (static_cast<::Garfield::SolidExtrusion*>(p));
   }
   static void destruct_GarfieldcLcLSolidExtrusion(void *p) {
      typedef ::Garfield::SolidExtrusion current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::SolidExtrusion

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolidHole(void *p) {
      delete (static_cast<::Garfield::SolidHole*>(p));
   }
   static void deleteArray_GarfieldcLcLSolidHole(void *p) {
      delete [] (static_cast<::Garfield::SolidHole*>(p));
   }
   static void destruct_GarfieldcLcLSolidHole(void *p) {
      typedef ::Garfield::SolidHole current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::SolidHole

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolidRidge(void *p) {
      delete (static_cast<::Garfield::SolidRidge*>(p));
   }
   static void deleteArray_GarfieldcLcLSolidRidge(void *p) {
      delete [] (static_cast<::Garfield::SolidRidge*>(p));
   }
   static void destruct_GarfieldcLcLSolidRidge(void *p) {
      typedef ::Garfield::SolidRidge current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::SolidRidge

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolidSphere(void *p) {
      delete (static_cast<::Garfield::SolidSphere*>(p));
   }
   static void deleteArray_GarfieldcLcLSolidSphere(void *p) {
      delete [] (static_cast<::Garfield::SolidSphere*>(p));
   }
   static void destruct_GarfieldcLcLSolidSphere(void *p) {
      typedef ::Garfield::SolidSphere current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::SolidSphere

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolidTube(void *p) {
      delete (static_cast<::Garfield::SolidTube*>(p));
   }
   static void deleteArray_GarfieldcLcLSolidTube(void *p) {
      delete [] (static_cast<::Garfield::SolidTube*>(p));
   }
   static void destruct_GarfieldcLcLSolidTube(void *p) {
      typedef ::Garfield::SolidTube current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::SolidTube

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLSolidWire(void *p) {
      delete (static_cast<::Garfield::SolidWire*>(p));
   }
   static void deleteArray_GarfieldcLcLSolidWire(void *p) {
      delete [] (static_cast<::Garfield::SolidWire*>(p));
   }
   static void destruct_GarfieldcLcLSolidWire(void *p) {
      typedef ::Garfield::SolidWire current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::SolidWire

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GarfieldcLcLTrack(void *p) {
      delete (static_cast<::Garfield::Track*>(p));
   }
   static void deleteArray_GarfieldcLcLTrack(void *p) {
      delete [] (static_cast<::Garfield::Track*>(p));
   }
   static void destruct_GarfieldcLcLTrack(void *p) {
      typedef ::Garfield::Track current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::Track

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLTrackBichsel(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::TrackBichsel : new ::Garfield::TrackBichsel;
   }
   static void *newArray_GarfieldcLcLTrackBichsel(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::TrackBichsel[nElements] : new ::Garfield::TrackBichsel[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLTrackBichsel(void *p) {
      delete (static_cast<::Garfield::TrackBichsel*>(p));
   }
   static void deleteArray_GarfieldcLcLTrackBichsel(void *p) {
      delete [] (static_cast<::Garfield::TrackBichsel*>(p));
   }
   static void destruct_GarfieldcLcLTrackBichsel(void *p) {
      typedef ::Garfield::TrackBichsel current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::TrackBichsel

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLTrackHeed(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::TrackHeed : new ::Garfield::TrackHeed;
   }
   static void *newArray_GarfieldcLcLTrackHeed(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::TrackHeed[nElements] : new ::Garfield::TrackHeed[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLTrackHeed(void *p) {
      delete (static_cast<::Garfield::TrackHeed*>(p));
   }
   static void deleteArray_GarfieldcLcLTrackHeed(void *p) {
      delete [] (static_cast<::Garfield::TrackHeed*>(p));
   }
   static void destruct_GarfieldcLcLTrackHeed(void *p) {
      typedef ::Garfield::TrackHeed current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::TrackHeed

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLTrackSrim(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::TrackSrim : new ::Garfield::TrackSrim;
   }
   static void *newArray_GarfieldcLcLTrackSrim(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::TrackSrim[nElements] : new ::Garfield::TrackSrim[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLTrackSrim(void *p) {
      delete (static_cast<::Garfield::TrackSrim*>(p));
   }
   static void deleteArray_GarfieldcLcLTrackSrim(void *p) {
      delete [] (static_cast<::Garfield::TrackSrim*>(p));
   }
   static void destruct_GarfieldcLcLTrackSrim(void *p) {
      typedef ::Garfield::TrackSrim current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::TrackSrim

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewCell(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewCell : new ::Garfield::ViewCell;
   }
   static void *newArray_GarfieldcLcLViewCell(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewCell[nElements] : new ::Garfield::ViewCell[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewCell(void *p) {
      delete (static_cast<::Garfield::ViewCell*>(p));
   }
   static void deleteArray_GarfieldcLcLViewCell(void *p) {
      delete [] (static_cast<::Garfield::ViewCell*>(p));
   }
   static void destruct_GarfieldcLcLViewCell(void *p) {
      typedef ::Garfield::ViewCell current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewCell

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewFEMesh(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewFEMesh : new ::Garfield::ViewFEMesh;
   }
   static void *newArray_GarfieldcLcLViewFEMesh(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewFEMesh[nElements] : new ::Garfield::ViewFEMesh[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewFEMesh(void *p) {
      delete (static_cast<::Garfield::ViewFEMesh*>(p));
   }
   static void deleteArray_GarfieldcLcLViewFEMesh(void *p) {
      delete [] (static_cast<::Garfield::ViewFEMesh*>(p));
   }
   static void destruct_GarfieldcLcLViewFEMesh(void *p) {
      typedef ::Garfield::ViewFEMesh current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewFEMesh

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewField(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewField : new ::Garfield::ViewField;
   }
   static void *newArray_GarfieldcLcLViewField(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewField[nElements] : new ::Garfield::ViewField[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewField(void *p) {
      delete (static_cast<::Garfield::ViewField*>(p));
   }
   static void deleteArray_GarfieldcLcLViewField(void *p) {
      delete [] (static_cast<::Garfield::ViewField*>(p));
   }
   static void destruct_GarfieldcLcLViewField(void *p) {
      typedef ::Garfield::ViewField current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewField

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewGeometry(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewGeometry : new ::Garfield::ViewGeometry;
   }
   static void *newArray_GarfieldcLcLViewGeometry(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewGeometry[nElements] : new ::Garfield::ViewGeometry[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewGeometry(void *p) {
      delete (static_cast<::Garfield::ViewGeometry*>(p));
   }
   static void deleteArray_GarfieldcLcLViewGeometry(void *p) {
      delete [] (static_cast<::Garfield::ViewGeometry*>(p));
   }
   static void destruct_GarfieldcLcLViewGeometry(void *p) {
      typedef ::Garfield::ViewGeometry current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewGeometry

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewIsochrons(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewIsochrons : new ::Garfield::ViewIsochrons;
   }
   static void *newArray_GarfieldcLcLViewIsochrons(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewIsochrons[nElements] : new ::Garfield::ViewIsochrons[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewIsochrons(void *p) {
      delete (static_cast<::Garfield::ViewIsochrons*>(p));
   }
   static void deleteArray_GarfieldcLcLViewIsochrons(void *p) {
      delete [] (static_cast<::Garfield::ViewIsochrons*>(p));
   }
   static void destruct_GarfieldcLcLViewIsochrons(void *p) {
      typedef ::Garfield::ViewIsochrons current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewIsochrons

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewMedium(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewMedium : new ::Garfield::ViewMedium;
   }
   static void *newArray_GarfieldcLcLViewMedium(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewMedium[nElements] : new ::Garfield::ViewMedium[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewMedium(void *p) {
      delete (static_cast<::Garfield::ViewMedium*>(p));
   }
   static void deleteArray_GarfieldcLcLViewMedium(void *p) {
      delete [] (static_cast<::Garfield::ViewMedium*>(p));
   }
   static void destruct_GarfieldcLcLViewMedium(void *p) {
      typedef ::Garfield::ViewMedium current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewMedium

namespace ROOT {
   // Wrappers around operator new
   static void *new_GarfieldcLcLViewSignal(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewSignal : new ::Garfield::ViewSignal;
   }
   static void *newArray_GarfieldcLcLViewSignal(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::Garfield::ViewSignal[nElements] : new ::Garfield::ViewSignal[nElements];
   }
   // Wrapper around operator delete
   static void delete_GarfieldcLcLViewSignal(void *p) {
      delete (static_cast<::Garfield::ViewSignal*>(p));
   }
   static void deleteArray_GarfieldcLcLViewSignal(void *p) {
      delete [] (static_cast<::Garfield::ViewSignal*>(p));
   }
   static void destruct_GarfieldcLcLViewSignal(void *p) {
      typedef ::Garfield::ViewSignal current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Garfield::ViewSignal

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_libGarfieldDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_libGarfieldDict) = RecordReadRules_libGarfieldDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_libGarfieldDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_libGarfieldDict_Impl() {
    static const char* headers[] = {
"Garfield/AvalancheGrid.hh",
"Garfield/AvalancheMC.hh",
"Garfield/AvalancheMicroscopic.hh",
"Garfield/Component.hh",
"Garfield/ComponentAnalyticField.hh",
"Garfield/ComponentAnsys121.hh",
"Garfield/ComponentAnsys123.hh",
"Garfield/ComponentCST.hh",
"Garfield/ComponentComsol.hh",
"Garfield/ComponentConstant.hh",
"Garfield/ComponentElmer.hh",
"Garfield/ComponentElmer2d.hh",
"Garfield/ComponentFieldMap.hh",
"Garfield/ComponentGrid.hh",
"Garfield/ComponentNeBem2d.hh",
"Garfield/ComponentNeBem3d.hh",
"Garfield/ComponentNeBem3dMap.hh",
"Garfield/ComponentParallelPlate.hh",
"Garfield/ComponentTcad2d.hh",
"Garfield/ComponentTcad3d.hh",
"Garfield/ComponentTcadBase.hh",
"Garfield/ComponentUser.hh",
"Garfield/ComponentVoxel.hh",
"Garfield/DegradeInterface.hh",
"Garfield/DriftLineRKF.hh",
"Garfield/FundamentalConstants.hh",
"Garfield/GarfieldConstants.hh",
"Garfield/Geometry.hh",
"Garfield/GeometryRoot.hh",
"Garfield/GeometrySimple.hh",
"Garfield/KDTree.hh",
"Garfield/MagboltzInterface.hh",
"Garfield/Medium.hh",
"Garfield/MediumCdTe.hh",
"Garfield/MediumConductor.hh",
"Garfield/MediumDiamond.hh",
"Garfield/MediumGaAs.hh",
"Garfield/MediumGaN.hh",
"Garfield/MediumGas.hh",
"Garfield/MediumMagboltz.hh",
"Garfield/MediumPlastic.hh",
"Garfield/MediumSilicon.hh",
"Garfield/Numerics.hh",
"Garfield/OpticalData.hh",
"Garfield/Plotting.hh",
"Garfield/PlottingEngine.hh",
"Garfield/Polygon.hh",
"Garfield/QuadTree.hh",
"Garfield/Random.hh",
"Garfield/RandomEngine.hh",
"Garfield/RandomEngineRoot.hh",
"Garfield/Sensor.hh",
"Garfield/Shaper.hh",
"Garfield/Solid.hh",
"Garfield/SolidBox.hh",
"Garfield/SolidExtrusion.hh",
"Garfield/SolidHole.hh",
"Garfield/SolidRidge.hh",
"Garfield/SolidSphere.hh",
"Garfield/SolidTube.hh",
"Garfield/SolidWire.hh",
"Garfield/TGeoTet.hh",
"Garfield/TetrahedralTree.hh",
"Garfield/Track.hh",
"Garfield/TrackBichsel.hh",
"Garfield/TrackDegrade.hh",
"Garfield/TrackElectron.hh",
"Garfield/TrackHeed.hh",
"Garfield/TrackPAI.hh",
"Garfield/TrackSimple.hh",
"Garfield/TrackSrim.hh",
"Garfield/TrackTrim.hh",
"Garfield/Utilities.hh",
"Garfield/ViewBase.hh",
"Garfield/ViewCell.hh",
"Garfield/ViewDrift.hh",
"Garfield/ViewFEMesh.hh",
"Garfield/ViewField.hh",
"Garfield/ViewGeometry.hh",
"Garfield/ViewIsochrons.hh",
"Garfield/ViewMedium.hh",
"Garfield/ViewSignal.hh",
nullptr
    };
    static const char* includePaths[] = {
"/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/Include",
"/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/Heed",
"/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp",
"/opt/homebrew/Cellar/root/6.40.04/include/root",
"/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGarfieldDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  Medium;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  Solid;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  Geometry;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  Component;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  Sensor;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  ViewDrift;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  AvalancheMicroscopic;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentParallelPlate.hh")))  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  ComponentGrid;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentParallelPlate.hh")))  __attribute__((annotate("$clingAutoload$Garfield/AvalancheGrid.hh")))  ComponentParallelPlate;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/AvalancheMC.hh")))  AvalancheMC;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentAnalyticField.hh")))  ComponentAnalyticField;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentAnsys121.hh")))  ComponentFieldMap;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentAnsys121.hh")))  ComponentAnsys121;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentAnsys123.hh")))  ComponentAnsys123;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentCST.hh")))  ComponentCST;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentComsol.hh")))  ComponentComsol;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentConstant.hh")))  ComponentConstant;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentElmer.hh")))  ComponentElmer;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentElmer2d.hh")))  ComponentElmer2d;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentNeBem2d.hh")))  ComponentNeBem2d;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentNeBem3d.hh")))  ComponentNeBem3d;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentTcad2d.hh")))  ComponentTcad2d;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentTcad3d.hh")))  ComponentTcad3d;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ComponentUser.hh")))  ComponentUser;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/DriftLineRKF.hh")))  DriftLineRKF;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/GeometryRoot.hh")))  GeometryRoot;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/GeometrySimple.hh")))  GeometrySimple;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/MediumCdTe.hh")))  MediumCdTe;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/MediumDiamond.hh")))  MediumDiamond;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/MediumGaAs.hh")))  MediumGaAs;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/MediumGaN.hh")))  MediumGaN;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/MediumGas.hh")))  MediumGas;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/MediumMagboltz.hh")))  MediumMagboltz;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/MediumSilicon.hh")))  MediumSilicon;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/OpticalData.hh")))  OpticalData;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/SolidBox.hh")))  SolidBox;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/SolidExtrusion.hh")))  SolidExtrusion;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/SolidHole.hh")))  SolidHole;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/SolidRidge.hh")))  SolidRidge;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/SolidSphere.hh")))  SolidSphere;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/SolidTube.hh")))  SolidTube;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/SolidWire.hh")))  SolidWire;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/Track.hh")))  Track;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/TrackBichsel.hh")))  TrackBichsel;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/TrackHeed.hh")))  TrackHeed;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/TrackSrim.hh")))  TrackSrim;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ViewCell.hh")))  ViewCell;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ViewFEMesh.hh")))  ViewFEMesh;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ViewField.hh")))  ViewField;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ViewGeometry.hh")))  ViewGeometry;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ViewIsochrons.hh")))  ViewIsochrons;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ViewMedium.hh")))  ViewMedium;}
namespace Garfield{class  __attribute__((annotate("$clingAutoload$Garfield/ViewSignal.hh")))  ViewSignal;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGarfieldDict dictionary payload"

#ifndef R__DUMMY_CXX_STANDARD_
  #define R__DUMMY_CXX_STANDARD_ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Garfield/AvalancheGrid.hh"
#include "Garfield/AvalancheMC.hh"
#include "Garfield/AvalancheMicroscopic.hh"
#include "Garfield/Component.hh"
#include "Garfield/ComponentAnalyticField.hh"
#include "Garfield/ComponentAnsys121.hh"
#include "Garfield/ComponentAnsys123.hh"
#include "Garfield/ComponentCST.hh"
#include "Garfield/ComponentComsol.hh"
#include "Garfield/ComponentConstant.hh"
#include "Garfield/ComponentElmer.hh"
#include "Garfield/ComponentElmer2d.hh"
#include "Garfield/ComponentFieldMap.hh"
#include "Garfield/ComponentGrid.hh"
#include "Garfield/ComponentNeBem2d.hh"
#include "Garfield/ComponentNeBem3d.hh"
#include "Garfield/ComponentNeBem3dMap.hh"
#include "Garfield/ComponentParallelPlate.hh"
#include "Garfield/ComponentTcad2d.hh"
#include "Garfield/ComponentTcad3d.hh"
#include "Garfield/ComponentTcadBase.hh"
#include "Garfield/ComponentUser.hh"
#include "Garfield/ComponentVoxel.hh"
#include "Garfield/DegradeInterface.hh"
#include "Garfield/DriftLineRKF.hh"
#include "Garfield/FundamentalConstants.hh"
#include "Garfield/GarfieldConstants.hh"
#include "Garfield/Geometry.hh"
#include "Garfield/GeometryRoot.hh"
#include "Garfield/GeometrySimple.hh"
#include "Garfield/KDTree.hh"
#include "Garfield/MagboltzInterface.hh"
#include "Garfield/Medium.hh"
#include "Garfield/MediumCdTe.hh"
#include "Garfield/MediumConductor.hh"
#include "Garfield/MediumDiamond.hh"
#include "Garfield/MediumGaAs.hh"
#include "Garfield/MediumGaN.hh"
#include "Garfield/MediumGas.hh"
#include "Garfield/MediumMagboltz.hh"
#include "Garfield/MediumPlastic.hh"
#include "Garfield/MediumSilicon.hh"
#include "Garfield/Numerics.hh"
#include "Garfield/OpticalData.hh"
#include "Garfield/Plotting.hh"
#include "Garfield/PlottingEngine.hh"
#include "Garfield/Polygon.hh"
#include "Garfield/QuadTree.hh"
#include "Garfield/Random.hh"
#include "Garfield/RandomEngine.hh"
#include "Garfield/RandomEngineRoot.hh"
#include "Garfield/Sensor.hh"
#include "Garfield/Shaper.hh"
#include "Garfield/Solid.hh"
#include "Garfield/SolidBox.hh"
#include "Garfield/SolidExtrusion.hh"
#include "Garfield/SolidHole.hh"
#include "Garfield/SolidRidge.hh"
#include "Garfield/SolidSphere.hh"
#include "Garfield/SolidTube.hh"
#include "Garfield/SolidWire.hh"
#include "Garfield/TGeoTet.hh"
#include "Garfield/TetrahedralTree.hh"
#include "Garfield/Track.hh"
#include "Garfield/TrackBichsel.hh"
#include "Garfield/TrackDegrade.hh"
#include "Garfield/TrackElectron.hh"
#include "Garfield/TrackHeed.hh"
#include "Garfield/TrackPAI.hh"
#include "Garfield/TrackSimple.hh"
#include "Garfield/TrackSrim.hh"
#include "Garfield/TrackTrim.hh"
#include "Garfield/Utilities.hh"
#include "Garfield/ViewBase.hh"
#include "Garfield/ViewCell.hh"
#include "Garfield/ViewDrift.hh"
#include "Garfield/ViewFEMesh.hh"
#include "Garfield/ViewField.hh"
#include "Garfield/ViewGeometry.hh"
#include "Garfield/ViewIsochrons.hh"
#include "Garfield/ViewMedium.hh"
#include "Garfield/ViewSignal.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Garfield::AvalancheMC", payloadCode, "@",
"Garfield::AvalancheMicroscopic", payloadCode, "@",
"Garfield::Component", payloadCode, "@",
"Garfield::ComponentAnalyticField", payloadCode, "@",
"Garfield::ComponentAnsys121", payloadCode, "@",
"Garfield::ComponentAnsys123", payloadCode, "@",
"Garfield::ComponentCST", payloadCode, "@",
"Garfield::ComponentComsol", payloadCode, "@",
"Garfield::ComponentConstant", payloadCode, "@",
"Garfield::ComponentElmer", payloadCode, "@",
"Garfield::ComponentElmer2d", payloadCode, "@",
"Garfield::ComponentFieldMap", payloadCode, "@",
"Garfield::ComponentGrid", payloadCode, "@",
"Garfield::ComponentNeBem2d", payloadCode, "@",
"Garfield::ComponentNeBem3d", payloadCode, "@",
"Garfield::ComponentParallelPlate", payloadCode, "@",
"Garfield::ComponentTcad2d", payloadCode, "@",
"Garfield::ComponentTcad3d", payloadCode, "@",
"Garfield::ComponentUser", payloadCode, "@",
"Garfield::DriftLineRKF", payloadCode, "@",
"Garfield::Geometry", payloadCode, "@",
"Garfield::GeometryRoot", payloadCode, "@",
"Garfield::GeometrySimple", payloadCode, "@",
"Garfield::Medium", payloadCode, "@",
"Garfield::MediumCdTe", payloadCode, "@",
"Garfield::MediumDiamond", payloadCode, "@",
"Garfield::MediumGaAs", payloadCode, "@",
"Garfield::MediumGaN", payloadCode, "@",
"Garfield::MediumGas", payloadCode, "@",
"Garfield::MediumMagboltz", payloadCode, "@",
"Garfield::MediumSilicon", payloadCode, "@",
"Garfield::OpticalData", payloadCode, "@",
"Garfield::RndmUniform", payloadCode, "@",
"Garfield::Sensor", payloadCode, "@",
"Garfield::SetDefaultStyle", payloadCode, "@",
"Garfield::SetSansSerif", payloadCode, "@",
"Garfield::SetSerif", payloadCode, "@",
"Garfield::Solid", payloadCode, "@",
"Garfield::SolidBox", payloadCode, "@",
"Garfield::SolidExtrusion", payloadCode, "@",
"Garfield::SolidHole", payloadCode, "@",
"Garfield::SolidRidge", payloadCode, "@",
"Garfield::SolidSphere", payloadCode, "@",
"Garfield::SolidTube", payloadCode, "@",
"Garfield::SolidWire", payloadCode, "@",
"Garfield::Track", payloadCode, "@",
"Garfield::TrackBichsel", payloadCode, "@",
"Garfield::TrackHeed", payloadCode, "@",
"Garfield::TrackSrim", payloadCode, "@",
"Garfield::ViewCell", payloadCode, "@",
"Garfield::ViewDrift", payloadCode, "@",
"Garfield::ViewFEMesh", payloadCode, "@",
"Garfield::ViewField", payloadCode, "@",
"Garfield::ViewGeometry", payloadCode, "@",
"Garfield::ViewIsochrons", payloadCode, "@",
"Garfield::ViewMedium", payloadCode, "@",
"Garfield::ViewSignal", payloadCode, "@",
"Garfield::plottingEngine", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGarfieldDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGarfieldDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGarfieldDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGarfieldDict() {
  TriggerDictionaryInitialization_libGarfieldDict_Impl();
}
