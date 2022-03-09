#!/bin/sh

for model in cbm4_ref chapman_ref saprc_ref small_ref strato_ref tropo_ref cbm4 chapman saprc small smog strato tropo chapman_single saprc_single small_single smog_single strato_single tropo_single

do
   rm -r $model
   mkdir $model
   cp input/$model.kpp $model/
   cd $model
   ../bin/kpp $model.kpp
   make -f Makefile_$model
   ./$model.exe
   cd ../ 
done
