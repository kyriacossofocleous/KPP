#!/bin/sh

mkdir bin
make -f Makefile -B

export KPP_HOME=$(pwd)
export PATH=$PATH:$HOME/bin

for model in cbm4 chapman saprc small smog strato tropo
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
