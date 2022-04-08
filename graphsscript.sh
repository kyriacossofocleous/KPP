mkdir bin
make -f Makefile -B

export KPP_HOME=$(pwd)
export PATH=$PATH:$HOME/bin

for model in small_dp small_sp cbm4_dp cbm4_sp cbm4_ref strato_dp

do
   rm -r $model
   mkdir $model
   cp input/$model.kpp $model/
   cd $model
   ../bin/kpp $model.kpp
   if [ "$model" = "cbm4_dp" ] || [ "$model" = "cbm4_sp" ];
   then
    perl -i -pe 's/5.0;/200.0;/g;' $model"_Initialize.c"
   fi 
   if [ "$model" = "cbm4_ref" ];
   then
    sed -i 's/05.00/200.0/g' $model"_Initialize.f"
   fi 
   if [ "$model" = "strato_dp" ];
   then
    sed -i 's/RTOLS = 1e-2;/RTOLS = 1e-3;/1' $model"_Main.c"
   fi 

   make -f Makefile_$model
   ./$model.exe
   cd ../ 
done

make -f Makefile CFLAGS="-D__MIXEDPREC" -B

for model in small_mp cbm4_mp strato_mp

do
   rm -r $model
   mkdir $model
   cp input/$model.kpp $model/
   cd $model
   ../bin/kpp $model.kpp
   if [ "$model" = "cbm4_mp" ];
   then
    perl -i -pe 's/5.0;/200.0;/g;' $model"_Initialize.c"
   fi 
   if [ "$model" = "strato_mp" ];
   then
    sed -i 's/RTOLS = 1e-2;/RTOLS = 1e-3;/1' $model"_Main.c"
   fi 
   make -f Makefile_$model COPT="-O3 -D__MIXEDPREC" -B
   ./$model.exe
   cd ../ 
done