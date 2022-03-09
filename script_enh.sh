#!/bin/sh

for model in cbm4_single chapman_single saprc_single small_single smog_single strato_single tropo_single
	     
do
   rm -r $model_enh
   mkdir $model_enh
   cp input/$model.kpp $model/
   cd $model_enh
   ../bin/kpp $model.kpp
   make -f Makefile_$model
   ./$model.exe
   cd ../ 
done
