#=======================================================================================
#	FileName    : 
#	Description : Make ALL
#       Date:         2012/02/03
#=======================================================================================

cd shell
source ./env_entry.sh
./build.sh $BOARD_VERSION $BUILD_VERSION && ./all_make.sh
./copy_out_release.sh

