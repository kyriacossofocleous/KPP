#!/bin/sh

for model in cbm4_ref chapman_ref saprc_ref small_ref smog_ref strato_ref tropo_ref

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
