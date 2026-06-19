# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/vbox/MPLABXProjects/ProgramIntegration.X/out/ProgramIntegration.X/default.cmf"
  "/home/vbox/MPLABXProjects/ProgramIntegration.X/out/ProgramIntegration.X/default.hex"
  "/home/vbox/MPLABXProjects/ProgramIntegration.X/out/ProgramIntegration.X/default.hxl"
  "/home/vbox/MPLABXProjects/ProgramIntegration.X/out/ProgramIntegration.X/default.mum"
  "/home/vbox/MPLABXProjects/ProgramIntegration.X/out/ProgramIntegration.X/default.o"
  "/home/vbox/MPLABXProjects/ProgramIntegration.X/out/ProgramIntegration.X/default.sdb"
  "/home/vbox/MPLABXProjects/ProgramIntegration.X/out/ProgramIntegration.X/default.sym"
  )
endif()
