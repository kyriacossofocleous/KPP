#!/bin/sh

mkdir bin
make -f Makefile -B

export KPP_HOME=$(pwd)
export PATH=$PATH:$HOME/bin

for model in cbm4_ref chapman_ref saprc_ref small_ref smog_ref strato_ref tropo_ref  cbm4_dp chapman_dp saprc_dp small_dp smog_dp strato_dp tropo_dp cbm4_sp chapman_sp saprc_sp small_sp smog_sp strato_sp tropo_sp 

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

make -f Makefile CFLAGS="-D__MIXEDPREC" -B

for model in cbm4_mp chapman_mp saprc_mp small_mp smog_mp strato_mp tropo_mp

do
   rm -r $model
   mkdir $model
   cp input/$model.kpp $model/
   cd $model
   ../bin/kpp $model.kpp
   make -f Makefile_$model COPT="-O3 -D__MIXEDPREC" -B
   ./$model.exe
   cd ../ 
done