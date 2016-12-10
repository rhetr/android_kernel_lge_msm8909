#
 # Copyright � 2016,  Sultan Qasim Khan <sultanqasim@gmail.com> 		      
 # Copyright � 2016,  Varun Chitre  <varun.chitre15@gmail.com>	
 #
 # Custom build script
 #
#
 # Copyright � 2016,  Sultan Qasim Khan <sultanqasim@gmail.com> 		      
 # Copyright � 2016,  Varun Chitre  <varun.chitre15@gmail.com>	
 #
 # Custom build script
 #
 # This software is licensed under the terms of the GNU General Public
 # License version 2, as published by the Free Software Foundation, and
 # may be copied, distributed, and modified under those terms.
 #
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 #
 # Please maintain this if you use this script or any part of it
 #

#!/bin/bash
BUILD_START=$(date +"%s")
blue='\033[0;34m'
cyan='\033[0;36m'
yellow='\033[0;33m'
red='\033[0;31m'
nocol='\033[0m'
export ARCH=arm
export SUBARCH=arm
export CROSS_COMPILE=/home/taco/android/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi- 
export KBUILD_BUILD_USER="taco"
export KBUILD_BUILD_HOST="mau"
echo -e "$cyan***********************************************"
echo "          Compiling kernel                          "   
echo -e "**********************************************$nocol"
rm -f /home/taco/android/kernel/lge/msm8909/arch/arm/boot/dts/*.dtb
rm -f /home/taco/android/kernel/lge/msm8909/arch/arm/boot/dt.img
rm -f /home/taco/android/kernel/lge/msm8909/flash_zip/boot.img
make clean && make mrproper
echo -e " Initializing defconfig"
make m1_mpcs_us_defconfig
echo -e " Building kernel"
make -j8 zImage
make -j8 dtbs

/home/taco/android/kernel/lge/msm8909/tools/dtbToolCM -2 -o /home/taco/android/kernel/lge/msm8909/arch/arm/boot/dt.img -s 2048 -p /home/taco/android/kernel/lge/msm8909/scripts/dtc/ /home/taco/android/kernel/lge/msm8909/arch/arm/boot/dts/

make -j8 modules
echo -e " Make flashable zip"
rm -rf taco_install
mkdir -p taco_install
make -j8 modules_install INSTALL_MOD_PATH=taco_install INSTALL_MOD_STRIP=1
mkdir -p /home/taco/android/kernel/lge/msm8909/flash_zip/system/lib/modules/pronto
find taco_install/ -name '*.ko' -type f -exec cp '{}' /home/taco/android/kernel/lge/msm8909/flash_zip/system/lib/modules/ \;
mv /home/taco/android/kernel/lge/msm8909/flash_zip/system/lib/modules/wlan.ko /home/taco/android/kernel/lge/msm8909/flash_zip/system/lib/modules/pronto/pronto_wlan.ko
cp home/taco/android/kernel/lge/msm8909/arch/arm/boot/zImage home/taco/android/kernel/lge/msm8909/flash_zip/tools/
cp home/taco/android/kernel/lge/msm8909/arch/arm/boot/dt.img home/taco/android/kernel/lge/msm8909/flash_zip/tools/
rm -f /home/taco/m1_taco_kernel_rx.zip
cd /home/taco/android/kernel/lge/msm8909/flash_zip
zip -r /home/taco/android/kernel/lge/msm8909/arch/arm/boot/m1_kernel.zip ./
mv /home/taco/android/kernel/lge/msm8909/arch/arm/boot/m1_kernel.zip /home/taco/m1_kernel_rx.zip
BUILD_END=$(date +"%s")
DIFF=$(($BUILD_END - $BUILD_START))
echo -e "$yellow Build completed in $(($DIFF / 60)) minute(s) and $(($DIFF % 60)) seconds.$nocol"

