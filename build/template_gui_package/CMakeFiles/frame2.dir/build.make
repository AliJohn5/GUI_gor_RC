# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alijohn/Desktop/temp_for_gui/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alijohn/Desktop/temp_for_gui/build

# Include any dependencies generated for this target.
include template_gui_package/CMakeFiles/frame2.dir/depend.make

# Include the progress variables for this target.
include template_gui_package/CMakeFiles/frame2.dir/progress.make

# Include the compile flags for this target's objects.
include template_gui_package/CMakeFiles/frame2.dir/flags.make

template_gui_package/ui_hello_gui.h: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/include/template_gui_package/hello_gui.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/alijohn/Desktop/temp_for_gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_hello_gui.h"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/lib/qt5/bin/uic -o /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/ui_hello_gui.h /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/include/template_gui_package/hello_gui.ui

template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/res.qrc
template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp: template_gui_package/CMakeFiles/frame2_autogen.dir/AutoRcc_res_UVLADIE3JM_Info.json
template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/cameraicon.jpg
template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/back.jpg
template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/arm.jpeg
template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/bac.jpg
template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/alijohn/Desktop/temp_for_gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic RCC for src/res.qrc"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/cmake -E cmake_autorcc /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/CMakeFiles/frame2_autogen.dir/AutoRcc_res_UVLADIE3JM_Info.json Debug

template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.o: template_gui_package/CMakeFiles/frame2.dir/flags.make
template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.o: template_gui_package/frame2_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alijohn/Desktop/temp_for_gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.o"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.o -c /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/frame2_autogen/mocs_compilation.cpp

template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.i"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/frame2_autogen/mocs_compilation.cpp > CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.i

template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.s"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/frame2_autogen/mocs_compilation.cpp -o CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.s

template_gui_package/CMakeFiles/frame2.dir/nodes/frame2.cpp.o: template_gui_package/CMakeFiles/frame2.dir/flags.make
template_gui_package/CMakeFiles/frame2.dir/nodes/frame2.cpp.o: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/nodes/frame2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alijohn/Desktop/temp_for_gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object template_gui_package/CMakeFiles/frame2.dir/nodes/frame2.cpp.o"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame2.dir/nodes/frame2.cpp.o -c /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/nodes/frame2.cpp

template_gui_package/CMakeFiles/frame2.dir/nodes/frame2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame2.dir/nodes/frame2.cpp.i"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/nodes/frame2.cpp > CMakeFiles/frame2.dir/nodes/frame2.cpp.i

template_gui_package/CMakeFiles/frame2.dir/nodes/frame2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame2.dir/nodes/frame2.cpp.s"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/nodes/frame2.cpp -o CMakeFiles/frame2.dir/nodes/frame2.cpp.s

template_gui_package/CMakeFiles/frame2.dir/src/hello_gui.cpp.o: template_gui_package/CMakeFiles/frame2.dir/flags.make
template_gui_package/CMakeFiles/frame2.dir/src/hello_gui.cpp.o: /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/hello_gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alijohn/Desktop/temp_for_gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object template_gui_package/CMakeFiles/frame2.dir/src/hello_gui.cpp.o"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame2.dir/src/hello_gui.cpp.o -c /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/hello_gui.cpp

template_gui_package/CMakeFiles/frame2.dir/src/hello_gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame2.dir/src/hello_gui.cpp.i"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/hello_gui.cpp > CMakeFiles/frame2.dir/src/hello_gui.cpp.i

template_gui_package/CMakeFiles/frame2.dir/src/hello_gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame2.dir/src/hello_gui.cpp.s"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alijohn/Desktop/temp_for_gui/src/template_gui_package/src/hello_gui.cpp -o CMakeFiles/frame2.dir/src/hello_gui.cpp.s

template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.o: template_gui_package/CMakeFiles/frame2.dir/flags.make
template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.o: template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alijohn/Desktop/temp_for_gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.o"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.o -c /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp

template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.i"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp > CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.i

template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.s"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp -o CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.s

# Object files for target frame2
frame2_OBJECTS = \
"CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/frame2.dir/nodes/frame2.cpp.o" \
"CMakeFiles/frame2.dir/src/hello_gui.cpp.o" \
"CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.o"

# External object files for target frame2
frame2_EXTERNAL_OBJECTS =

/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/mocs_compilation.cpp.o
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: template_gui_package/CMakeFiles/frame2.dir/nodes/frame2.cpp.o
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: template_gui_package/CMakeFiles/frame2.dir/src/hello_gui.cpp.o
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: template_gui_package/CMakeFiles/frame2.dir/frame2_autogen/UVLADIE3JM/qrc_res.cpp.o
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: template_gui_package/CMakeFiles/frame2.dir/build.make
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/libroscpp.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/libcv_bridge.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.2.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/librosconsole.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/librostime.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /opt/ros/noetic/lib/libcpp_common.so
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.12.8
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_gapi.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_highgui.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_ml.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_objdetect.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_photo.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_stitching.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_video.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_videoio.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_dnn.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_calib3d.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_features2d.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_flann.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_imgproc.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/local/lib/libopencv_core.so.4.7.0
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
/home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2: template_gui_package/CMakeFiles/frame2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alijohn/Desktop/temp_for_gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable /home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2"
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/frame2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
template_gui_package/CMakeFiles/frame2.dir/build: /home/alijohn/Desktop/temp_for_gui/devel/lib/template_gui_package/frame2

.PHONY : template_gui_package/CMakeFiles/frame2.dir/build

template_gui_package/CMakeFiles/frame2.dir/clean:
	cd /home/alijohn/Desktop/temp_for_gui/build/template_gui_package && $(CMAKE_COMMAND) -P CMakeFiles/frame2.dir/cmake_clean.cmake
.PHONY : template_gui_package/CMakeFiles/frame2.dir/clean

template_gui_package/CMakeFiles/frame2.dir/depend: template_gui_package/ui_hello_gui.h
template_gui_package/CMakeFiles/frame2.dir/depend: template_gui_package/frame2_autogen/UVLADIE3JM/qrc_res.cpp
	cd /home/alijohn/Desktop/temp_for_gui/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alijohn/Desktop/temp_for_gui/src /home/alijohn/Desktop/temp_for_gui/src/template_gui_package /home/alijohn/Desktop/temp_for_gui/build /home/alijohn/Desktop/temp_for_gui/build/template_gui_package /home/alijohn/Desktop/temp_for_gui/build/template_gui_package/CMakeFiles/frame2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : template_gui_package/CMakeFiles/frame2.dir/depend

